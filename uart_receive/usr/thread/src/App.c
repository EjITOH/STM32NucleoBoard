/*
 * App.c
 *
 *  Created on: Apr 17, 2023
 *      Author: EijiITOH
 */

/*
 * include files
 */
#include "main.h"
#include "cmsis_os.h"

#include "App.h"
#include "rcvGnssMsgThread.h"


/*
 *
 */
/* Definitions for Gnss-UartPort */
UART_HandleTypeDef *p_UartPort_Gnss;

/*　Definitions for App-UartPort */
UART_HandleTypeDef *p_UartPort_App;

/* Definitions for QueueGnssMsg */
osMessageQueueId_t QueueId_GnssMsg;
static uint8_t QueueBuf_GnssMsg[ 16 * sizeof( uint8_t ) ];
static StaticQueue_t QueueControlBlock_GnssMsg;
static const osMessageQueueAttr_t AttributesQueue_GnssMsg = {
  .name = "Queue_GnssMsg",
  .cb_mem = &QueueControlBlock_GnssMsg,
  .cb_size = sizeof(QueueControlBlock_GnssMsg),
  .mq_mem = &QueueBuf_GnssMsg,
  .mq_size = sizeof(QueueBuf_GnssMsg)
};

/* Definitions for rcvGnssMsg-Thread */
static osThreadId_t ThreadId_rcvGnssMsg;
static const osThreadAttr_t AttributesThread_rcvGnssMsg = {
  .name = "rcvGnssMsg-Thread",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};


/**
 *
 */
int32_t newQueue_GnssMsg(void)
{
	QueueId_GnssMsg = osMessageQueueNew (
							16,
							sizeof(uint8_t),
							&AttributesQueue_GnssMsg
						);

	if ( NULL == QueueId_GnssMsg ) {
		return APP_FALSE;
	}
	else {
		return APP_TRUE;
	}
}


/**
 *
 */
int32_t newThread_rcvGnssMsg(void)
{
	/* creation of rcvGnssMsg-Thread */
	ThreadId_rcvGnssMsg = osThreadNew(
								Thread_rcvGnssMsg,
								NULL,
								&AttributesThread_rcvGnssMsg
							);

	if ( NULL == ThreadId_rcvGnssMsg ) {
		return APP_FALSE;
	}
	else {
		return APP_TRUE;
	}
}


