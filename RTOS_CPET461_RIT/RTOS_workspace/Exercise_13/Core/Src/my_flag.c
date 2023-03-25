/*
 * my_flag.c
 *
 *  Created on: Feb 28, 2023
 *      Author: tonyb
 */

#include "my_flags.h"

Flag Flag1 = Reset;
Flag Flag2 = Reset;

void Set_Flag(int flag_num)
{
	switch(flag_num)
	{
	case 1:
		Flag1 = Set;
		break;
	case 2:
		Flag2 = Set;
		break;
	}
	return;
}

void Reset_Flag(int flag_num)
{
	switch(flag_num)
	{
	case 1:
		Flag1 = Reset;
		break;
	case 2:
		Flag2 = Reset;
		break;
	}
	return;
}

Flag Check_Flag(int flag_num)
{
	Flag temp;
	switch(flag_num)
	{
	case 1:
		temp = Flag1;
		break;
	case 2:
		temp = Flag2;
		break;
	}
	return temp;
}
