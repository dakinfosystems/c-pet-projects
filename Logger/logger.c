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
typedef enum LogLevel_e {
	CRITICAL_LOG = 0x01,
}LogLevel_et;

/* Globals */
static LogLevel_et gs_level = 0;

/* Function prototype */


/* Function definition */ 
void log( unsigned int level, unsigned char *file, long int line, unsigned char *format, ...)
{
	va_list args;
	unsigned char buffer[MAX_BUFFER_LEN] = { 0 };	
		
	//printf("log Level 0x%X and g log 0x%X\n", level, gs_level);
	if( gs_level < level )
		return;
	
	//printf("Getting log args\n");
	va_start(args, format);
	vsprintf(buffer, format, args);
	va_end(args);

	//printf("Printing Log >> ");
	printf(buffer);
	printf("\n");
}

void initLog( LogLevel_et logLevel )
{
	//printf("Set log level 0x%X\n", logLevel);
	gs_level = logLevel;
}
