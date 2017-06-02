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
#define CRITICAL_LOG 0X01
#define ERROR_LOG 0x03
#define INFO_LOG 0x07
#define DEBUG_LOG 0x0F

#define LOG( level, file, line, format, ... ) log( (level), (file), (line), format, ##__VA_ARGS__ )

#define CRITICAL(format, ...) LOG( CRITICAL_LOG, __FILE__, __LINE__, format, ##__VA_ARGS__) 
#define ERROR(format, ...) LOG( ERROR_LOG, __FILE__,__LINE__, format, ##__VA_ARGS__ )
#define INFO(format, ...) LOG( INFO_LOG, __FILE__,__LINE__, format, ##__VA_ARGS__ )
#define DEBUG(format, ...) LOG( DEBUG_LOG, __FILE__,__LINE__, format, ##__VA_ARGS__ )


/* User Dara Types */


/* Globals and constants */

/* function prototype */
void log( unsigned char, unsigned char *, long int, unsigned char *, ... ); 

#endif
