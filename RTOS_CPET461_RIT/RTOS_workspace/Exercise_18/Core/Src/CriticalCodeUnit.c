/*
 * CriticalCodeUnit.c
 *
 *  Created on: Mar 3, 2023
 *      Author: tonyb
 */
#include "CriticalCodeUnit.h"
#include "FreeRTOS.h"
#include "semphr.h"

typedef struct SharedPool
{
	int RedFlashingRate; //Shared Resource 1 ~ Red Task Flashing Rate
	int GreenFlashingRate; //Shared Resource 1 ~ Green Task Flashing Rate
};

SemaphoreHandle_t PoolSemaphore;

struct SharedPool SharedPoolData = {1, 10}; // Default Values for Flashing Rate of Leds in Hz

void InitSemaphore(void)
{
	PoolSemaphore = xSemaphoreCreateBinary();
	xSemaphoreGive(PoolSemaphore);
}

void SetShared(char RedOrGreen, int x)
{
	xSemaphoreTake(PoolSemaphore, portMAX_DELAY);
	if(RedOrGreen == 'R')
	{
		SharedPoolData.RedFlashingRate = x;
	}
	else
	{
		SharedPoolData.GreenFlashingRate = x;
	}
	xSemaphoreGive(PoolSemaphore);
}

int GetShared(char RedOrGreen)
{
	if(RedOrGreen == 'R')
	{
		return SharedPoolData.RedFlashingRate;
	}
	else
	{
		return SharedPoolData.GreenFlashingRate;
	}
}

