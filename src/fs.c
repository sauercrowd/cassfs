#include "fs.h"

#include <string.h>
#include <fuse.h>
#include <stdio.h>
#include <errno.h>

void *cassfs_init(struct fuse_conn_info *conn,
		struct fuse_config *cfg)
{
	(void) conn;
	cfg->kernel_cache = 1;
	return NULL;
}

int cassfs_getattr(const char *path, 
		struct stat *stbuf,
		struct fuse_file_info *fi)
{
	(void) fi;
	int res = 0;

	memset(stbuf, 0, sizeof(struct stat));
	stbuf->st_mode = S_IFDIR | 0755;
	stbuf->st_nlink = 2;
	return res;
}

int cassfs_readdir(const char *path,
		void *buf, fuse_fill_dir_t filler,
		off_t offset, struct fuse_file_info *fi,
		enum fuse_readdir_flags flags)
{
	(void) offset;
	(void) fi;
	(void) flags;

	filler(buf, ".", NULL, 0, 0);
	filler(buf, "..", NULL, 0, 0);
	filler(buf, "hello_test", NULL, 0, 0);

	return 0;
}

int cassfs_open(const char *path, struct fuse_file_info *fi)
{
	return 0;
}

int cassfs_read(const char *path, char *buf, size_t size,
		off_t offset, struct fuse_file_info *fi)
{
	return 0;
}



