#include "args.h"
#include <fuse.h>
#include <fcntl.h>
#include <stdio.h>
#include <stddef.h>

//static options opts;

//#define OPTION(t, p) \
//	{ t, offsetof(options, p), 1 }
//static const struct fuse_opt option_spec[] = {
//	OPTION("--name=%s", filename),
//	OPTION("--contents=%s", contents),
//	OPTION("-h", show_help),
//	OPTION("--help", show_help),
//	FUSE_OPT_END
//};

static void show_help(const char *progname)
{
	printf("Help!\n");
}


