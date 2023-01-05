/*
 * (c) Copyright 2022 Peter Simon Terentschenko
 * Author: Peter Simon Terentschenko <petersimon.teretnschenko@googlemail.come>
 * SPDX-License-Identifier: MIT
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void usage(void)
{
	fputs("Usage: unixhexdump HEX_STRING\n\n", stderr);
	fputs("Converts HEX_STRING in format deadbeef to old school unix hex format \\xde\\xad\\xbe\\xef\n", stderr);
}

int main(int argc, char *argv[])
{
	int len, i;
	char *hex;

	if(argc == 1)
	{
		fprintf(stderr, "Pass at least one string as argument\n");
		goto error;
	}

	len = strlen(argv[1]);

	if((len % 2) != 0)
	{
		fprintf(stderr, "Input is not a valid HEX string\n");
		goto error;
	}

	hex = malloc(sizeof(char) * len);
	if(!hex)
	{
		fprintf(stderr,"Could not allocate memory for input hex string\n");
		goto error;
	}

	memcpy(hex, argv[1], len);

	for(i=0; i<len; i++)
	{
		if(!i)
			printf("\\x");

		printf("%c", hex[i]);
		
		if(!i)
			continue;

		if(i == len-1)
			printf("\n");
		else if((i%2))
			printf("\\x");
	}

	free(hex);
	return EXIT_SUCCESS;

error:
	usage();
	return EXIT_FAILURE;
}