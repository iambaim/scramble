/*
Copyright (c) 2016 Ibrahim Umar

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#ifndef LIMIT
#define LIMIT 5000000
#endif

/* Hashing functions (using 64-bit bucket size and the golden ratio discussed by Knuth in TAOCP vol.3) */
#if defined(_FMOD)

#define HASH(X)  	(uint64_t)floor(9223372036854775808ULL * MOD(X))
#define MOD(X)		fmod((double)X * 0.61803398875, 1)

#define METHOD		"fmod"

#elif defined(_MULT)

#define _HASH_CONSTANT  11400714819323198485ULL
#define HASH(X)         (X * _HASH_CONSTANT)

#define METHOD		"mult"

#else

#define HASH(X)         (X)

#define METHOD		"none"

#endif

int main(void)
{

	FILE *fp;

	char out[256];

#if defined(_RAND)
	char *KEYS = "rand"; 
#elif defined(_SEQ)
	char *KEYS = "seq"; 		
#else
	#error You must define either -D_RAND or -D_SEQ!
#endif

	uint64_t key, j;
	
	srand(time(NULL));

	snprintf(out, 256, "%s.%s.%d.out", KEYS, METHOD, LIMIT);
	
	fp = fopen(out, "w");

	fprintf(fp, "key,HASH(key)\n");

	for (j = 1; j <= LIMIT; j++){

#if defined(_RAND)
		key = rand()%(LIMIT);
#elif defined(_SEQ)
		key = j;
#endif

		fprintf(fp, "%llu,%llu\n", j, (uint64_t) HASH(key));
	}

	fclose(fp);
	return 0;

}
