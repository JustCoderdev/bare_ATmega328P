#define LOB_IMPLEMENTATION
#include "lob.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>


const char* PROGRAM_NAME = "blink";

const char* SRC_FILES[] = { "main" };
const char* SI_FILES[] = { "si_io", "si_clock" };
#define SI_PATH "lib/silicon"

const char* CC_FLAGS[] = {
    "-xc", "-std=c89", "-ansi", "-pedantic-errors", "-pedantic",
    "-Wall", "-Wextra", "-Werror", "-Wshadow", "-Wpointer-arith",
    "-Wcast-qual", "-Wcast-align", "-Wstrict-prototypes",
    "-Wmissing-prototypes", "-Wno-conversion", "-g"
};

const char* MEGA_FLAGS[] = {
    "-nostdlib", "-mmcu=atmega328p", "--param=min-pagesize=0"
};

const char* IFLAGS[] = { "-I./", "-I./lib/include" };
const char* LFLAGS[] = { "-L./" };
const char* DFLAGS[] = { "-DF_CPU=16000000UL" };



static void usage(void)
{
    printf(
    "Available commands:\n"
      "\tclean - clean build artifacts\n"
      "\tbuild - compile, link and load into a .hex file\n"
      "\tflash - flash .hex to chip\n"
    );
}

static bool flag_set(char* arg, char* name, bool* flag)
{
    if(!str_match(arg, name)) return false;

    if(*flag) {
	fprintf(stderr,
        "Flag '%s' already setted, ignoring...\n", name);
    }

    *flag = true;
    return true;
}

int main(int argc, char** argv)
{
	/* GO_REBUILD_YOURSELF */
	{
		#include <sys/stat.h>
		#include <fcntl.h>

		struct stat bin_stat = {0};
		struct stat src_stat = {0};
		if(stat("./lob.c", &src_stat) == -1) {
			printf("Error getting stats of './lob.c': %s\n", strerror(errno));
			exit(failure);
		}

		if(stat("./lob", &bin_stat) == -1) {
			printf("Error getting stats of './lob': %s\n", strerror(errno));
			exit(failure);
		}

		if(src_stat.st_mtime > bin_stat.st_mtime) {
			printf("Rebuild needed!\n");
            printf("Src: %s", ctime(&src_stat.st_mtime));
            printf("Bin: %s", ctime(&bin_stat.st_mtime));
			exit(failure);

		} else {
			printf("No rebuild needed\n");
            printf("Src: %s", ctime(&src_stat.st_mtime));
            printf("Bin: %s", ctime(&bin_stat.st_mtime));
		}
	}
	/* GO_REBUILD_YOURSELF */

    char* program = shift(&argc, &argv);

    struct {
	bool clean;
	bool build;
	bool flash;
    } flags = {0};

    /* Parse args */
    while(argc > 0)
    {
		char* arg = shift(&argc, &argv);

		if(flag_set(arg, "clean", &flags.clean)) continue;
		if(flag_set(arg, "build", &flags.build)) continue;
		if(flag_set(arg, "flash", &flags.flash)) continue;
    }

    /* Print flags */
    printf(
    "-----------\n"
    " clean - %d\n"
    " build - %d\n"
    " flash - %d\n"
    "-----------\n",
    flags.clean, flags.build, flags.flash
    );

    if(flags.clean)
    {
		printf("Cleaning...\n");
    }

    if(flags.build)
    {
		printf("Building...\n");
    }

    if(flags.flash)
    {
		printf("Flashing...\n");
    }

    return success;
}
