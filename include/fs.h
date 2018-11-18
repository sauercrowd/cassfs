#define FUSE_USE_VERSION 31

#include <fuse.h>
#include <stdio.h>

static void *cassfs_init(struct fuse_conn_info *conn,
		struct fuse_config *cfg);

static int cassfs_getattr(const char *path, 
		struct stat *stbuf,
		struct fuse_file_info *fi);

static int cassfs_readdir(const char *path,
		void *buf, fuse_fill_dir_t filler,
		off_t offset, struct fuse_file_info *fi,
		enum fuse_readdir_flags flags);

static int cassfs_open(const char *path, struct fuse_file_info *fi);

static int cassfs_read(const char *path, char *buf, size_t size,
		off_t offset, struct fuse_file_info *fi);

