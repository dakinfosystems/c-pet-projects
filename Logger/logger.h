/*****************************************************************************\
 * @file: logger.h
 * @description: This is header file of Logger. Use this file to use Logger
 * 		 in your project. It has different level of logging.
 * @created on: 02/06/2017
 * @author: Pramod Jain
\*****************************************************************************/

/* Include only once */
#ifndef __LOGGER_H__
#define __LOGGER_H__

/* Include */
#include <stdarg.h>

/****************************************************************\
 * Common section 
\****************************************************************/
/* Defines and ENUMS */
typedef enum LogLevel_e {
	CRITICAL_LOG = 0X01,
	ERROR_LOG,		/* 0x02 */
	INFO_LOG,		/* 0x03 */
	DEBUG_LOG,		/* 0x04 */
}LogLevel_et;

#define LOG( level, file, line, format, ... ) log( (level), (file), (line), format, ##__VA_ARGS__ )

#define CRITICAL(format, ...) LOG( CRITICAL_LOG, __FILE__, __LINE__, format, ##__VA_ARGS__) 
#define ERROR(format, ...) LOG( ERROR_LOG, __FILE__,__LINE__, format, ##__VA_ARGS__ )
#define INFO(format, ...) LOG( INFO_LOG, __FILE__,__LINE__, format, ##__VA_ARGS__ )
#define DEBUG(format, ...) LOG( DEBUG_LOG, __FILE__,__LINE__, format, ##__VA_ARGS__ )


/* User Dara Types */


/* Globals and constants */

/* function prototype */
void log( unsigned char, unsigned char *, long int, unsigned char *, ... ); 
void initLog( LogLevel_et );

#endif
