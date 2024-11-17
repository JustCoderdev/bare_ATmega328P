/* ---------------------------------------- *\
 * LOve Builder                             *
 *    by JustCode <justcode.rdev@gmail.com> *
 *   src                                    *
\* ---------------------------------------- */

#ifndef LOB_H_
#define LOB_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/* Types
 * ------------------------------------------------------------ */

typedef enum {
	true = (1 == 1),
	false = (1 != 1)
} bool;

typedef enum {
	success = false,
	failure = true
} error;

/* Program
 * ------------------------------------------------------------ */

extern char* shift(int* argc, char*** argv);
extern bool str_match(char* strA, char* strB);

/* extern int exec(char* path, ...); */

/* extern error dir_new(char* path); */
/* extern error dir_del(char* path); */

/* extern error file_del(char* path); */
/* extern error file_mov(char* path); */


/* - String operations
 * - Path operations
 * */

#ifdef LOB_IMPLEMENTATION

char* shift(int* argc, char*** argv)
{
	char* t;

	if(*argc < 1) {
		fprintf(stderr, "Error shifting args!\n");
		exit(failure);
	}

	(*argc)--;
	t = (*argv)[0];
	(*argv)++;

	return t;
}

bool str_match(char* strA, char* strB)
{
	int alen = strlen(strA);
	int blen = strlen(strB);
	int i;

	if(alen != blen) return false;

	for(i = 0; i < alen; ++i) {
		if(strA[i] != strB[i]) return false;
	}

	return true;
}

#endif /* LOB_IMPLEMENTATION */

#endif /* LOB_H_ */
