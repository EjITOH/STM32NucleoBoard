/*
 * rcvGnssRcverMsgThread.h
 *
 *  Created on: Apr 17, 2023
 *      Author: EijiITOH
 */

#ifndef THREAD_INC_RCVGNSSMSGTHREAD_H_
#define THREAD_INC_RCVGNSSMSGTHREAD_H_

#include "cmsis_os.h"


/*
 * prototype
 */
int32_t newQueue_GnssMsg(void);
int32_t newThread_rcvGnssMsg(void);
void Thread_rcvGnssMsg(void *argument);



#endif /* THREAD_INC_RCVGNSSMSGTHREAD_H_ */
