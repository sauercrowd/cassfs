#ifndef __ARGS_H__
#define __ARGS_H__
#define FUSE_USE_VERSION 31

#include <fuse.h>


typedef struct options{
        const char *filename;
        const char* contents;
        int show_help; 
} options;

#endif
