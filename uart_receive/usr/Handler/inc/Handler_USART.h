/*
 * Handler_USART.h
 *
 *  Created on: Apr 17, 2023
 *      Author: EijiITOH
 */

#ifndef HANDLER_INC_HANDLER_USART_H_
#define HANDLER_INC_HANDLER_USART_H_

/*
 * functions
 */
int32_t newUartPort_Gnss(UART_HandleTypeDef *p_UartHandle);
int32_t newUartPort_App(UART_HandleTypeDef *p_UartHandle);
int32_t enableUartPort_RcvIT(UART_HandleTypeDef *p_UartHandle);
int32_t enableUartPort_SndIT(UART_HandleTypeDef *p_UartHandle);

void App_enableRcvUsartIT(UART_HandleTypeDef *p_huart);


#endif /* HANDLER_INC_HANDLER_USART_H_ */
