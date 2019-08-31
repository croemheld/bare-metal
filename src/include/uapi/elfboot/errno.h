#ifndef __UAPI_ELFBOOT_ERRNO_H__
#define __UAPI_ELFBOOT_ERRNO_H__

/*
 * POSIX Error codes
 */

#define EPERM		 1	/* Not owner */
#define ENOENT		 2	/* No such file or directory */
#define ESRCH		 3	/* No such context */
#define EINTR		 4	/* Interrupted system call */
#define EIO		 5	/* I/O error */
#define ENXIO		 6	/* No such device or address */
#define E2BIG		 7	/* Arg list too long */
#define ENOEXEC		 8	/* Exec format error */
#define EBADF		 9	/* Bad file number */
#define ECHILD		10	/* No children */
#define EAGAIN		11	/* No more contexts */
#define ENOMEM		12	/* Not enough core */
#define EACCES		13	/* Permission denied */
#define EFAULT		14	/* Bad address */
#define ENOTEMPTY	15	/* Directory not empty */
#define EBUSY		16	/* Mount device busy */
#define EEXIST		17	/* File exists */
#define EXDEV		18	/* Cross-device link */
#define ENODEV		19	/* No such device */
#define ENOTDIR		20	/* Not a directory */
#define EISDIR		21	/* Is a directory */
#define EINVAL		22	/* Invalid argument */
#define ENFILE		23	/* File table overflow */
#define EMFILE		24	/* Too many open files */
#define ENOTTY		25	/* Not a typewriter */
#define ENAMETOOLONG	26	/* File name too long */
#define EFBIG		27	/* File too large */
#define ENOSPC		28	/* No space left on device */
#define ESPIPE		29	/* Illegal seek */
#define EROFS		30	/* Read-only file system */
#define EMLINK		31	/* Too many links */
#define EPIPE		32	/* Broken pipe */
#define EDEADLK		33	/* Resource deadlock avoided */
#define ENOLCK		34	/* No locks available */
#define ENOTSUP		35	/* Unsupported value */
#define EMSGSIZE	36	/* Message size */

#endif /* __UAPI_ELFBOOT_ERRNO_H__ */