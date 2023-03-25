/*
 * SyncSema.c
 *
 *  Created on: Mar 25, 2023
 *      Author: tonyb
 */

#include "FreeRTOS.h"
#include "semphr.h"
#include "SyncSema.h"

SemaphoreHandle_t EFSema;

void InitSema(void)
{
	/*
	 * Must be called in the main before osKerenelStart()
	 * change the state of the semaphore from wait to release
	 */

	EFSema = xSemaphoreCreateBinary();
}

void SetEFSema(void)
{
	xSemaphoreGiveFromISR(EFSema, NULL);
}

void WaitEFSema(void)
{
	xSemaphoreTake(EFSema, portMAX_DELAY);
}
