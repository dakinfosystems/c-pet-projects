#include "logger.h"

void main( int argc, char **argv)
{
	if( argc < 2 )
		return;

	printf("Step 1\n");
	initLog( (LogLevel_et)(atoi(argv[1])) );

	printf("Printing log\n");
	CRITICAL("This is critical");
	ERROR("This is error");
	INFO("This is info");
	DEBUG("This is debug");
}
