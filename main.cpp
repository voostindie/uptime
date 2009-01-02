/****
 * Uptime
 *
 * Uptime is a very simple Win32 console program that prints the
 * time Windows has been running to the standard output.
 *
 * There are a couple of commandline arguments to affect the way
 * the running time is printed. See class Uptime for details.
 *
 * Compiles under Cygwin
 *
 * (c) Copyright 2000 by Vincent Oostindie
 ****/

#include "Uptime.h"
#include <iostream>

const char * VERSION = "2.0";

void printHelp() {
	std::cout << "uptime version " << VERSION << "\n\n"
	    << "Explanation:\n"
	    << "  Prints the time the system is running in various formats\n\n"
		<< "Usage:\n"
		<< "  uptime [option]\n\n"
		<< "Where option is one of:\n"
		<< "  -?: this help\n"
		<< "  -h: this help\n"
		<< "  -s: short format\n"
		<< "  -n: normal format (default, may be omitted)\n"
		<< "  -l: long format\n\n"
		<< "(c) Copyright 2000 by Vincent Oostindie\n";
}

int main(int argc, char* argv[])
{
	// Instantiate an Uptime object
	Uptime uptime;
	
	// Check commandline arguments
	for (int i = 1; i < argc; i++) {
		if (argv[i][0] == '-') {
			switch (argv[i][1]) {
	    	case 's': // short mode
	    		uptime.SetViewType(Uptime::VIEW_SHORT);
	    		break;
	    	case 'n': // normal mode (default, so unnecessary)
	    		uptime.SetViewType(Uptime::VIEW_NORMAL);
	    		break;
			case 'l': // long mode
				uptime.SetViewType(Uptime::VIEW_LONG);
				break;
			case 'h': // help
				printHelp();
				exit(1);
			case '?': // help
				printHelp();
				exit(1);
			}	
		}	
	}

	// print the time the system is running and exit
	std::cout << uptime << std::endl;
	return 0;
}
