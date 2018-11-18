#include "fs.h"
#include "args.h"

#include <fuse.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>

static struct fuse_operations cassfs_oper = {
        .init           = cassfs_init,
        .getattr        = cassfs_getattr,
        .readdir        = cassfs_readdir,
        .open           = cassfs_open,
        .read           = cassfs_read,
};

#define OPTION(t, p) \
        { t, offsetof(options, p), 1 }
static const struct fuse_opt option_spec[] = {
        OPTION("--name=%s", filename),
        OPTION("--contents=%s", contents),
        OPTION("-h", show_help),
        OPTION("--help", show_help),
        FUSE_OPT_END
};

static options opts;

int main(int argc, char** argv){
	int ret;
        struct fuse_args args = FUSE_ARGS_INIT(argc, argv);

        /* Set defaults -- we have to use strdup so that
           fuse_opt_parse can free the defaults if other
           values are specified */
        opts.filename = strdup("hello");
        opts.contents = strdup("Hello World!\n");

        /* Parse options */
        if (fuse_opt_parse(&args, &opts, option_spec, NULL) == -1)
                return 1;

        /* When --help is specified, first print our own file-system
           specific help text, then signal fuse_main to show
           additional help (by adding `--help` to the options again)
           without usage: line (by setting argv[0] to the empty
           string) */
        if (opts.show_help) {
                show_help(argv[0]);
                assert(fuse_opt_add_arg(&args, "--help") == 0);
                args.argv[0] = (char*) "";
        }

        ret = fuse_main(args.argc, args.argv, &cassfs_oper, NULL);
        fuse_opt_free_args(&args);
        return ret;
	return 0;
}
