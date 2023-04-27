/*
 * Handler_USART.c
 *
 *  Created on: Apr 14, 2023
 *      Author: EijiITOH
 */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"

#include "App.h"


/*
 *
 */
static void forever(void);


/*
 *
 */
static uint8_t bufRxUsart1[1];
static uint8_t bufTxUsart1[1];
static uint8_t bufRxUsart2[1];
static uint8_t bufTxUsart2[1];


/**
 *
 */
int32_t newUartPort_Gnss(UART_HandleTypeDef *p_UartHandle)
{
	if ( NULL == p_UartHandle ) {
		return APP_FALSE;
	}

	p_UartPort_Gnss = p_UartHandle;
	return APP_TRUE;
}


/**
 *
 */
int32_t newUartPort_App(UART_HandleTypeDef *p_UartHandle)
{
	if ( NULL == p_UartHandle ) {
		return APP_FALSE;
	}

	p_UartPort_App = p_UartHandle;
	return APP_TRUE;
}


/**
 *
 */
int32_t enableUartPort_RcvIT(UART_HandleTypeDef *p_UartHandle)
{
	uint8_t *p_buf;

	if ( NULL == p_UartHandle ) {
		return APP_FALSE;
	}

	if ( USART1 == p_UartHandle->Instance ) {
		p_buf = &(bufRxUsart1[0]);
	}
	else if ( USART2 == p_UartHandle->Instance ) {
		p_buf = &(bufRxUsart2[0]);
	}
	else {
		return APP_FALSE;
	}
	HAL_UART_Receive_IT(p_UartHandle, p_buf, 1);

	return APP_TRUE;
}


/**
 *
 */
int32_t enableUartPort_SndIT(UART_HandleTypeDef *p_UartHandle)
{
	uint8_t *p_buf;

	if ( NULL == p_UartHandle ) {
		return APP_FALSE;
	}

	if ( USART1 == p_UartHandle->Instance ) {
		p_buf = &(bufTxUsart1[0]);
	}
	else if ( USART2 == p_UartHandle->Instance ) {
		p_buf = &(bufTxUsart2[0]);
	}
	else {
		return APP_FALSE;
	}
	HAL_UART_Transmit_IT(p_UartHandle, p_buf, 1);

	return APP_TRUE;
}



/**
 *
 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	/*
	 * When rcv-interrupt is happened USART2, send rcv-data(1 byte) to Queue.
	 */
	if ( USART1 == (huart->Instance) ) {
		// rcv-data is sending to Queue.
		// When result is not osOK, go to forever loop.
		// result is osOK, enable interrupt to USART1.
		if ( osOK != osMessageQueuePut(QueueId_GnssMsg, &bufRxUsart1[0], 0, 0) ) {
//			forever();
		}
		else {
			// no process
		}
		HAL_UART_Receive_IT(huart, &bufRxUsart1[0], 1);
	}

	return;
}


static void forever(void)
{
	uint32_t src=0, dst;

	while (1) {
		dst = src;
	}
}
