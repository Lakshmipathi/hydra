#include <sys/types.h>
#include <sys/mount.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/xattr.h>
#include <sys/syscall.h>

#include <dirent.h>
#include <errno.h>
#include <error.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	unsigned char v0[8192];
	unsigned char v1[8192];
	char v2[] = ".";
	char v3[] = "foo";
	char v4[] = "foo/bar";
	char v5[] = "foo/bar/baz";
	char v6[] = "foo/bar/xattr";
	char v7[] = "foo/bar/acl";
	char v8[] = "foo/bar/æøå";
	char v9[] = "foo/bar/fifo";
	char v10[] = "foo/bar/hln";
	char v11[] = "foo/bar/sln";
	char v12[] = "./A";
	char v13[] = "./B";
	char v14[] = "./C";
	char v15[] = "./A/foo";
	char v16[] = "./B/foo2";
	char v17[] = "./B/bar";
	char v18[] = "./C/bar";
	long v19;
	long v20;
	syscall(SYS_mkdir, (long)v12);
	syscall(SYS_mkdir, (long)v13);
	syscall(SYS_mkdir, (long)v14);
	v19 = syscall(SYS_open, (long)v15, 2, 0);
	syscall(SYS_link, (long)v15, (long)v16);
	v20 = syscall(SYS_open, (long)v17, 2, 0);
	syscall(SYS_sync);
	syscall(SYS_unlink, (long)v16);
	syscall(SYS_rename, (long)v17, (long)v18);
	syscall(SYS_fsync, (long)v19);

	close(v19);
	close(v20);
	return 0;
}

