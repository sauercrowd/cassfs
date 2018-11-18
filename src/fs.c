#include "fs.h"
#include <fuse.h>
#include <stdio.h>
#include <errno.h>

static void *cassfs_init(struct fuse_conn_info *conn,
		struct fuse_config *cfg)
{
	printf("%p\n", conn);
	return NULL;
}

static int cassfs_getattr(const char *path, 
		struct stat *stbuf,
		struct fuse_file_info *fi)
{
//	(void) fi;
//	int res = 0;
	return -ENOENT;
//	memset(stbuf, 0, sizeof(struct stat));
}

static int cassfs_readdir(const char *path,
		void *buf, fuse_fill_dir_t filler,
		off_t offset, struct fuse_file_info *fi,
		enum fuse_readdir_flags flags)
{
	return -ENOENT;
}

static int cassfs_open(const char *path, struct fuse_file_info *fi)
{
	return 0;
}

static int cassfs_read(const char *path, char *buf, size_t size,
		off_t offset, struct fuse_file_info *fi)
{
	return 0;
}



