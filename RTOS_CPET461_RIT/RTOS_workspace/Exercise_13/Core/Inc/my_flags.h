/*
 * my_flags.h
 *
 *  Created on: Feb 28, 2023
 *      Author: tonyb
 */

#ifndef INC_MY_FLAGS_H_
#define INC_MY_FLAGS_H_

typedef enum {Set, Reset} Flag;

void Set_Flag(int);

void Reset_Flag(int);

Flag Check_Flag(int);



#endif /* INC_MY_FLAGS_H_ */
