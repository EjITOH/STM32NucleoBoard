/*
 * App.h
 *
 *  Created on: Apr 17, 2023
 *      Author: EijiITOH
 */

#ifndef THREAD_INC_APP_H_
#define THREAD_INC_APP_H_


/*
 * defines
 */
#define	APP_TRUE	(0)
#define APP_FALSE	(-1)


/*
 *
 */
extern UART_HandleTypeDef *p_UartPort_Gnss;
extern UART_HandleTypeDef *p_UartPort_App;
extern osMessageQueueId_t QueueId_GnssMsg;


/*
 * prototype
 */



#endif /* THREAD_INC_APP_H_ */
