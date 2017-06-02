/*****************************************************************************\
 * @file: logger.c
 * @description: This file contains implementation of logger.
 * @created on: 02/06/2017
 * @author: Pramod Jain
\*****************************************************************************/

/* Include */
#include <stdio.h>
#include <stdarg.h>
/* Defines */
#define MAX_BUFFER_LEN 512

/* User data types */

/* Globals */

/* Function prototype */


/* Function definition */ 
void log( unsigned int level, unsigned char *file, long int line, unsigned char *format, ...)
{
	va_list args;
	unsigned char buffer[MAX_BUFFER_LEN] = { 0 };	
	
	va_start(args, format);
	vsprintf(buffer, format, args);
	va_end(args);

	buffer[MAX_BUFFER_LEN - 1] = '\n';
	printf(buffer);
	printf("\n");
}
