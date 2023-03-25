const int TOTAL_SAMPLES = 600; // simulated samples
int numSamples = 1;

// Declare the variables that are computed in the calculateStats function
float sample, runningMean = 0.0, runningSumVar = 0.0, runningStdev = 0.0, runningVariance = runningStdev * runningStdev;
//**********************************************************************
void setup()
{
  Serial.begin(9600);
// This line tells MATLAB that the Arduino is ready to accept data
  Serial.println("%Arduino Ready"); 
// Wait until MATLAB sends a 'g' to start sending data
  while (Serial.read() != 'g'); // spin until 'g' entry
}
//**********************************************************************
void loop()
{ 
  sample = simSample();
  // Call the statistics calculation function
  calculateStats(sample);
  // Display the statistics
  displayStatsData(); 
  // Run TOTAL_SAMPLES iterations then halt
  if (++numSamples > TOTAL_SAMPLES) while (true);  
} 
//**********************************************************************
float simSample(void)
{
  // Simulate sensor for stats calculation development
  float simSmpl, simAmp = 1.0, simT = 60; 
  
  //simAmp = ((numSamples > 180) && (numSamples < 300)) ? 0.125 : 1.0; // burst amplitude
  simT = ((numSamples > 180) && (numSamples < 300)) ? 30.0 : 60.0; // burst frequency
  simSmpl = 180.0 + simAmp*sin((numSamples/simT)*TWO_PI); // fixed amplitude, frequency 
  return simSmpl; 
}
//**********************************************************************
void calculateStats(float x)
{
  // Calculate running statistics per Cook pseudo code.
  static int i = 1;
  static float oldMean, oldVar;
  if (i == 1)
  {
    runningMean = x;
    runningSumVar = 0;
    runningVariance = 0;
    oldMean = runningMean;
    oldVar = runningSumVar;
  }
  else
  {
    runningMean = oldMean + (x - oldMean)/i;
    runningSumVar = oldVar + (x - oldMean)*(x - runningMean);
  }
  i++;
}
//**********************************************************************
void displayStatsData(void)
{
  // Display results to console
  if (numSamples == 1)
  {
    Serial.print("\nn\tsmpl\trunningMean\trunningStdev\n");
  }
  Serial.print(numSamples);  Serial.print('\t');
  Serial.print(sample); Serial.print('\t');
  Serial.print(runningMean);   Serial.print('\t');
  Serial.print(runningStdev);  Serial.print('\n');  
}
