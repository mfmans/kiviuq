/*
	$ [KiPHP] /r0/io.cpp  (1406)    (C) 2005-2014  MF
*/


#define KI_RING			0

#include "../kiviuq.h"




/* Á÷ÎÄ¼ş */
FILE *	r0_io::stream_in		= NULL;						// ÊäÈëÁ÷
FILE *	r0_io::stream_out		= NULL;						// Êä³öÁ÷
FILE *	r0_io::stream_error		= NULL;						// ´íÎóÁ÷




KI_LOADER_BOOT (r0_io) {
	r0_io::stream_in		= stdin;
	r0_io::stream_out		= stdout;
	r0_io::stream_error		= stderr;
}


KI_LOADER_SHUTDOWN (r0_io) {
	fclose (r0_io::stream_in);
	fclose (r0_io::stream_out);
	fclose (r0_io::stream_error);
}




/* ÏòÊä³öÁ÷Êä³ö×Ö·û */
void r0_io::putchar (const int data) {
	if((data >= 0x20) && (data <= 0x7E)) {
		fputc (data, r0_io::stream_out);
	} else {
		switch(data) {
			case '\a':		fprintf (r0_io::stream_out,		"%s",		"\\a");			break;
			case '\f':		fprintf (r0_io::stream_out,		"%s",		"\\f");			break;
			case '\n':		fprintf (r0_io::stream_out,		"%s",		"\\n");			break;
			case '\r':		fprintf (r0_io::stream_out,		"%s",		"\\r");			break;
			case '\t':		fprintf (r0_io::stream_out,		"%s",		"\\t");			break;

			default:		fprintf (r0_io::stream_out,		"\\x%02X",	(unsigned int) data);
		}
	}
}




/* ÏòÊä³öÁ÷Êä³ö×Ö·û´® */

void r0_io::print (const char *data) {
	fprintf (r0_io::stream_out, "%s", data);
}


void r0_io::printf (const char *format, ...) {
	KI_VARG_BEGIN (format);

	vfprintf (r0_io::stream_out, format, ap);

	KI_VARG_END ( );
}




/* Ïò´íÎóÁ÷Êä³öÓï·¨¾¯¸æ/´íÎó */
void r0_io::syntax (const char *message, unsigned int line, bool fatal) {
	if(fatal == true) {
		// Êä³ö´íÎó
		if(line == 0) {
			fprintf (r0_io::stream_error,	"@E.ST@"    "%s\n",			message);
		} else {
			fprintf (r0_io::stream_error,	"@E.ST:%u@" "%s\n",	line,	message);
		}

		// ÖÕÖ¹³ÌĞò
		LDR0::die ( );
	} else {
		// Êä³ö¾¯¸æ
		if(line == 0) {
			fprintf (r0_io::stream_error,	"@W.ST@"    "%s\n",			message);
		} else {
			fprintf (r0_io::stream_error,	"@W.ST:%u@" "%s\n",	line,	message);
		}
	}
}


/* Ïò´íÎóÁ÷Êä³öÔËĞĞÊ±´íÎó²¢ÖÕÖ¹³ÌĞò */
void r0_io::runtime (const char *message) {
	// Êä³ö´íÎó
	fprintf (r0_io::stream_error,	"@E.RT@" "%s\n",	message);

	// ÖÕÖ¹³ÌĞò
	LDR0::die ( );
}


/* Ïò´íÎóÁ÷Êä³ö²ÎÊı´íÎó²¢ÖÕÖ¹³ÌĞò */
void r0_io::argument (const char *format, ...) {
	KI_VARG_BEGIN (format);

	fprintf  (r0_io::stream_error,	"@E.AR@");

	vfprintf (r0_io::stream_error,	format,		ap);

	fprintf  (r0_io::stream_error,	"\n");

	KI_VARG_END ( );

	// ÖÕÖ¹³ÌĞò
	LDR0::die ( );
}




/* Ïò´íÎóÁ÷Êä³ö¼ÇÂ¼ĞÅÏ¢ */
void r0_io::log (const char *entry, const char *format, ...) {
	KI_VARG_BEGIN (format);

	fprintf  (r0_io::stream_error,	"@L@" "%s=",	entry);

	vfprintf (r0_io::stream_error,	format,			ap);

	fprintf  (r0_io::stream_error,	"\n");

	KI_VARG_END ( );
}


