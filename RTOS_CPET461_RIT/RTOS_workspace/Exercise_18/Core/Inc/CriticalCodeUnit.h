/*
 * CriticalCodeUnit.h
 *
 *  Created on: Mar 3, 2023
 *      Author: tonyb
 */
#ifndef INC_CRITICALCODEUNIT_H_
#define INC_CRITICALCODEUNIT_H_

void InitSemaphore(void);
void SetShared(char RedOrGreen, int x);
int GetShared(char RedOrGreen);

#endif /* INC_CRITICALCODEUNIT_H_ */
