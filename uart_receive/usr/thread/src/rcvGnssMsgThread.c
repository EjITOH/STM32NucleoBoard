/**
  ******************************************************************************
  * @file           : rcvGnssRcverMsgThread.c
  * @brief          :
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */

/*
 * include files
 */
#include "main.h"
#include "cmsis_os.h"

#include "App.h"


static void forever(void);


/**
  * @brief  Function implementing the receive Gnss-Receiver-Message thread.
  * @param  argument: Not used
  * @retval None
  */
void Thread_rcvGnssMsg(void *argument)
{
	static uint8_t buf;
	static uint8_t msg[128];
	static uint8_t index_msg = 0;

	while (1) {
		if ( osOK != osMessageQueueGet(QueueId_GnssMsg, &buf, 0, osWaitForever) ) {
			forever();
		}
		else {
			msg[ index_msg++ ] = buf;

			if ( index_msg >= 128 ) {
				HAL_UART_Transmit_IT(p_UartPort_App, &(msg[0]), 128);
				index_msg = 0;
			}
			else {
				// no process
			}
		}
	}
}


/**
 *
 */
static void forever(void)
{
	uint32_t loop = 0;

	while (1) {
		loop++;
	}

	return;
}
