/*
	$ [KiPHP] /kiviuq.cpp  (1406)    (C) 2005-2014  MF
*/


#define KI_RING			255

#include "kiviuq.h"




int main (int argc, char *argv[]) {
	rx_mount ( );

	LDR0::boot (argc, argv);

	STX5::execute ( );
	OUT5::execute ( );

	LDR0::shutdown ( );

	assert (M0::size_current == 0);

	return 0;
}


