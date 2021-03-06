/*
 * Copyright 2013, Broadcom Corporation
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Broadcom Corporation;
 * the contents of this file may not be disclosed to third parties, copied
 * or duplicated in any form, in whole or in part, without the prior
 * written permission of Broadcom Corporation.
 */

/**
 * Modifications by Tyler Freeman, Copyright 2011-2015 DrumPants, Inc.
 * 
 * http://developers.drumpants.com
 * 
 * Modifications licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/***
 * Handles UART communication through the PUART.
 */

#ifndef UART_ONE_WIRE_H
#define UART_ONE_WIRE_H

// needed to remove some code from SDK 1.2 (BCM20732) that doesn't work on the BCM20736.
// use 1 for BCM20732, 2 for BCM20736
#define SDK_VERSION 2

// Use P33 for peripheral uart RX. (default GPIO_PIN_UART_RX)
#define PUART_RX_PIN 25
// Use P32 for peripheral uart TX. (default GPIO_PIN_UART_TX)
#define PUART_TX_PIN 32

#define PUART_BAUD_RATE 115200


// if 1, the UART will call the callback every time it receives bytes
// if 0, this app will poll the UART to read bytes.
#define ENABLE_PUART_INTERRUPT_CALLBACK 1


// the callback function when a packet is read.
// - char* buffer : the buffer (no bigger than 16 bytes)
// - int bufferLength : length of buffer (min: 1, max: 16)
typedef void (*FUNC_ON_UART_RECEIVE)(char*, int);


typedef enum  {
	PUART_SUCCESS,
	PUART_ERROR_LPM,
	PUART_ERROR_PIN_INVALID,
	PUART_ERROR_PIN_ASSIGNMENT_FAILED
} PUART_ERROR;

/***
 * Inits the PUART with the given RX callback.
 */
PUART_ERROR peripheral_uart_init(FUNC_ON_UART_RECEIVE callback, void (*ble_trace0) (const char *p_str) );

// Sends out a stream of bytes to the peer device on the peripheral uart interface.
// buffer - The buffer to send to the peer device.
// length - The number of bytes from buffer to send.
// Returns The number of bytes that were sent.
UINT32 application_send_bytes(UINT8* buffer, UINT32 length);

// Sends out a stream of bytes to the peer device on the peripheral uart interface.
// buffer - The buffer to send to the peer device.
// length - The number of bytes from buffer to send.
// Returns The number of bytes that were sent.
UINT32 application_send_bytes(UINT8* buffer, UINT32 length);

#endif
