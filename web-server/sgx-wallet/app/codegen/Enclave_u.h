#ifndef ENCLAVE_U_H__
#define ENCLAVE_U_H__

#include <stdint.h>
#include <wchar.h>
#include <stddef.h>
#include <string.h>
#include "sgx_edger8r.h" /* for sgx_status_t etc. */

#include "sgx_report.h"
#include "time.h"
#include "inc/stat.h"
#include "sys/uio.h"
#include "inc/stat.h"
#include "inc/dirent.h"
#include "pwd.h"

#include <stdlib.h> /* for size_t */

#define SGX_CAST(type, item) ((type)(item))

#ifdef __cplusplus
extern "C" {
#endif

#ifndef SGX_OC_CPUIDEX_DEFINED__
#define SGX_OC_CPUIDEX_DEFINED__
void SGX_UBRIDGE(SGX_CDECL, sgx_oc_cpuidex, (int cpuinfo[4], int leaf, int subleaf));
#endif
#ifndef SGX_THREAD_WAIT_UNTRUSTED_EVENT_OCALL_DEFINED__
#define SGX_THREAD_WAIT_UNTRUSTED_EVENT_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_CDECL, sgx_thread_wait_untrusted_event_ocall, (const void* self));
#endif
#ifndef SGX_THREAD_SET_UNTRUSTED_EVENT_OCALL_DEFINED__
#define SGX_THREAD_SET_UNTRUSTED_EVENT_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_CDECL, sgx_thread_set_untrusted_event_ocall, (const void* waiter));
#endif
#ifndef SGX_THREAD_SETWAIT_UNTRUSTED_EVENTS_OCALL_DEFINED__
#define SGX_THREAD_SETWAIT_UNTRUSTED_EVENTS_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_CDECL, sgx_thread_setwait_untrusted_events_ocall, (const void* waiter, const void* self));
#endif
#ifndef SGX_THREAD_SET_MULTIPLE_UNTRUSTED_EVENTS_OCALL_DEFINED__
#define SGX_THREAD_SET_MULTIPLE_UNTRUSTED_EVENTS_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_CDECL, sgx_thread_set_multiple_untrusted_events_ocall, (const void** waiters, size_t total));
#endif
#ifndef U_THREAD_SET_EVENT_OCALL_DEFINED__
#define U_THREAD_SET_EVENT_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_thread_set_event_ocall, (int* error, const void* tcs));
#endif
#ifndef U_THREAD_WAIT_EVENT_OCALL_DEFINED__
#define U_THREAD_WAIT_EVENT_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_thread_wait_event_ocall, (int* error, const void* tcs, const struct timespec* timeout));
#endif
#ifndef U_THREAD_SET_MULTIPLE_EVENTS_OCALL_DEFINED__
#define U_THREAD_SET_MULTIPLE_EVENTS_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_thread_set_multiple_events_ocall, (int* error, const void** tcss, int total));
#endif
#ifndef U_THREAD_SETWAIT_EVENTS_OCALL_DEFINED__
#define U_THREAD_SETWAIT_EVENTS_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_thread_setwait_events_ocall, (int* error, const void* waiter_tcs, const void* self_tcs, const struct timespec* timeout));
#endif
#ifndef U_CLOCK_GETTIME_OCALL_DEFINED__
#define U_CLOCK_GETTIME_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_clock_gettime_ocall, (int* error, int clk_id, struct timespec* tp));
#endif
#ifndef U_READ_OCALL_DEFINED__
#define U_READ_OCALL_DEFINED__
size_t SGX_UBRIDGE(SGX_NOCONVENTION, u_read_ocall, (int* error, int fd, void* buf, size_t count));
#endif
#ifndef U_PREAD64_OCALL_DEFINED__
#define U_PREAD64_OCALL_DEFINED__
size_t SGX_UBRIDGE(SGX_NOCONVENTION, u_pread64_ocall, (int* error, int fd, void* buf, size_t count, int64_t offset));
#endif
#ifndef U_READV_OCALL_DEFINED__
#define U_READV_OCALL_DEFINED__
size_t SGX_UBRIDGE(SGX_NOCONVENTION, u_readv_ocall, (int* error, int fd, const struct iovec* iov, int iovcnt));
#endif
#ifndef U_PREADV64_OCALL_DEFINED__
#define U_PREADV64_OCALL_DEFINED__
size_t SGX_UBRIDGE(SGX_NOCONVENTION, u_preadv64_ocall, (int* error, int fd, const struct iovec* iov, int iovcnt, int64_t offset));
#endif
#ifndef U_WRITE_OCALL_DEFINED__
#define U_WRITE_OCALL_DEFINED__
size_t SGX_UBRIDGE(SGX_NOCONVENTION, u_write_ocall, (int* error, int fd, const void* buf, size_t count));
#endif
#ifndef U_PWRITE64_OCALL_DEFINED__
#define U_PWRITE64_OCALL_DEFINED__
size_t SGX_UBRIDGE(SGX_NOCONVENTION, u_pwrite64_ocall, (int* error, int fd, const void* buf, size_t count, int64_t offset));
#endif
#ifndef U_WRITEV_OCALL_DEFINED__
#define U_WRITEV_OCALL_DEFINED__
size_t SGX_UBRIDGE(SGX_NOCONVENTION, u_writev_ocall, (int* error, int fd, const struct iovec* iov, int iovcnt));
#endif
#ifndef U_PWRITEV64_OCALL_DEFINED__
#define U_PWRITEV64_OCALL_DEFINED__
size_t SGX_UBRIDGE(SGX_NOCONVENTION, u_pwritev64_ocall, (int* error, int fd, const struct iovec* iov, int iovcnt, int64_t offset));
#endif
#ifndef U_FCNTL_ARG0_OCALL_DEFINED__
#define U_FCNTL_ARG0_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_fcntl_arg0_ocall, (int* error, int fd, int cmd));
#endif
#ifndef U_FCNTL_ARG1_OCALL_DEFINED__
#define U_FCNTL_ARG1_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_fcntl_arg1_ocall, (int* error, int fd, int cmd, int arg));
#endif
#ifndef U_IOCTL_ARG0_OCALL_DEFINED__
#define U_IOCTL_ARG0_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_ioctl_arg0_ocall, (int* error, int fd, int request));
#endif
#ifndef U_IOCTL_ARG1_OCALL_DEFINED__
#define U_IOCTL_ARG1_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_ioctl_arg1_ocall, (int* error, int fd, int request, int* arg));
#endif
#ifndef U_CLOSE_OCALL_DEFINED__
#define U_CLOSE_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_close_ocall, (int* error, int fd));
#endif
#ifndef U_MALLOC_OCALL_DEFINED__
#define U_MALLOC_OCALL_DEFINED__
void* SGX_UBRIDGE(SGX_NOCONVENTION, u_malloc_ocall, (int* error, size_t size));
#endif
#ifndef U_FREE_OCALL_DEFINED__
#define U_FREE_OCALL_DEFINED__
void SGX_UBRIDGE(SGX_NOCONVENTION, u_free_ocall, (void* p));
#endif
#ifndef U_MMAP_OCALL_DEFINED__
#define U_MMAP_OCALL_DEFINED__
void* SGX_UBRIDGE(SGX_NOCONVENTION, u_mmap_ocall, (int* error, void* start, size_t length, int prot, int flags, int fd, int64_t offset));
#endif
#ifndef U_MUNMAP_OCALL_DEFINED__
#define U_MUNMAP_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_munmap_ocall, (int* error, void* start, size_t length));
#endif
#ifndef U_MSYNC_OCALL_DEFINED__
#define U_MSYNC_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_msync_ocall, (int* error, void* addr, size_t length, int flags));
#endif
#ifndef U_MPROTECT_OCALL_DEFINED__
#define U_MPROTECT_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_mprotect_ocall, (int* error, void* addr, size_t length, int prot));
#endif
#ifndef U_OPEN_OCALL_DEFINED__
#define U_OPEN_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_open_ocall, (int* error, const char* pathname, int flags));
#endif
#ifndef U_OPEN64_OCALL_DEFINED__
#define U_OPEN64_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_open64_ocall, (int* error, const char* path, int oflag, int mode));
#endif
#ifndef U_FSTAT_OCALL_DEFINED__
#define U_FSTAT_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_fstat_ocall, (int* error, int fd, struct stat_t* buf));
#endif
#ifndef U_FSTAT64_OCALL_DEFINED__
#define U_FSTAT64_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_fstat64_ocall, (int* error, int fd, struct stat64_t* buf));
#endif
#ifndef U_STAT_OCALL_DEFINED__
#define U_STAT_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_stat_ocall, (int* error, const char* path, struct stat_t* buf));
#endif
#ifndef U_STAT64_OCALL_DEFINED__
#define U_STAT64_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_stat64_ocall, (int* error, const char* path, struct stat64_t* buf));
#endif
#ifndef U_LSTAT_OCALL_DEFINED__
#define U_LSTAT_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_lstat_ocall, (int* error, const char* path, struct stat_t* buf));
#endif
#ifndef U_LSTAT64_OCALL_DEFINED__
#define U_LSTAT64_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_lstat64_ocall, (int* error, const char* path, struct stat64_t* buf));
#endif
#ifndef U_LSEEK_OCALL_DEFINED__
#define U_LSEEK_OCALL_DEFINED__
uint64_t SGX_UBRIDGE(SGX_NOCONVENTION, u_lseek_ocall, (int* error, int fd, int64_t offset, int whence));
#endif
#ifndef U_LSEEK64_OCALL_DEFINED__
#define U_LSEEK64_OCALL_DEFINED__
int64_t SGX_UBRIDGE(SGX_NOCONVENTION, u_lseek64_ocall, (int* error, int fd, int64_t offset, int whence));
#endif
#ifndef U_FTRUNCATE_OCALL_DEFINED__
#define U_FTRUNCATE_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_ftruncate_ocall, (int* error, int fd, int64_t length));
#endif
#ifndef U_FTRUNCATE64_OCALL_DEFINED__
#define U_FTRUNCATE64_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_ftruncate64_ocall, (int* error, int fd, int64_t length));
#endif
#ifndef U_TRUNCATE_OCALL_DEFINED__
#define U_TRUNCATE_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_truncate_ocall, (int* error, const char* path, int64_t length));
#endif
#ifndef U_TRUNCATE64_OCALL_DEFINED__
#define U_TRUNCATE64_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_truncate64_ocall, (int* error, const char* path, int64_t length));
#endif
#ifndef U_FSYNC_OCALL_DEFINED__
#define U_FSYNC_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_fsync_ocall, (int* error, int fd));
#endif
#ifndef U_FDATASYNC_OCALL_DEFINED__
#define U_FDATASYNC_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_fdatasync_ocall, (int* error, int fd));
#endif
#ifndef U_FCHMOD_OCALL_DEFINED__
#define U_FCHMOD_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_fchmod_ocall, (int* error, int fd, uint32_t mode));
#endif
#ifndef U_UNLINK_OCALL_DEFINED__
#define U_UNLINK_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_unlink_ocall, (int* error, const char* pathname));
#endif
#ifndef U_LINK_OCALL_DEFINED__
#define U_LINK_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_link_ocall, (int* error, const char* oldpath, const char* newpath));
#endif
#ifndef U_RENAME_OCALL_DEFINED__
#define U_RENAME_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_rename_ocall, (int* error, const char* oldpath, const char* newpath));
#endif
#ifndef U_CHMOD_OCALL_DEFINED__
#define U_CHMOD_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_chmod_ocall, (int* error, const char* path, uint32_t mode));
#endif
#ifndef U_READLINK_OCALL_DEFINED__
#define U_READLINK_OCALL_DEFINED__
size_t SGX_UBRIDGE(SGX_NOCONVENTION, u_readlink_ocall, (int* error, const char* path, char* buf, size_t bufsz));
#endif
#ifndef U_SYMLINK_OCALL_DEFINED__
#define U_SYMLINK_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_symlink_ocall, (int* error, const char* path1, const char* path2));
#endif
#ifndef U_REALPATH_OCALL_DEFINED__
#define U_REALPATH_OCALL_DEFINED__
char* SGX_UBRIDGE(SGX_NOCONVENTION, u_realpath_ocall, (int* error, const char* pathname));
#endif
#ifndef U_MKDIR_OCALL_DEFINED__
#define U_MKDIR_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_mkdir_ocall, (int* error, const char* pathname, uint32_t mode));
#endif
#ifndef U_RMDIR_OCALL_DEFINED__
#define U_RMDIR_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_rmdir_ocall, (int* error, const char* pathname));
#endif
#ifndef U_OPENDIR_OCALL_DEFINED__
#define U_OPENDIR_OCALL_DEFINED__
void* SGX_UBRIDGE(SGX_NOCONVENTION, u_opendir_ocall, (int* error, const char* pathname));
#endif
#ifndef U_READDIR64_R_OCALL_DEFINED__
#define U_READDIR64_R_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_readdir64_r_ocall, (void* dirp, struct dirent64_t* entry, struct dirent64_t** result));
#endif
#ifndef U_CLOSEDIR_OCALL_DEFINED__
#define U_CLOSEDIR_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_closedir_ocall, (int* error, void* dirp));
#endif
#ifndef U_DIRFD_OCALL_DEFINED__
#define U_DIRFD_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_dirfd_ocall, (int* error, void* dirp));
#endif
#ifndef U_FSTATAT64_OCALL_DEFINED__
#define U_FSTATAT64_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_fstatat64_ocall, (int* error, int dirfd, const char* pathname, struct stat64_t* buf, int flags));
#endif
#ifndef U_ENVIRON_OCALL_DEFINED__
#define U_ENVIRON_OCALL_DEFINED__
char** SGX_UBRIDGE(SGX_NOCONVENTION, u_environ_ocall, (void));
#endif
#ifndef U_GETENV_OCALL_DEFINED__
#define U_GETENV_OCALL_DEFINED__
char* SGX_UBRIDGE(SGX_NOCONVENTION, u_getenv_ocall, (const char* name));
#endif
#ifndef U_SETENV_OCALL_DEFINED__
#define U_SETENV_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_setenv_ocall, (int* error, const char* name, const char* value, int overwrite));
#endif
#ifndef U_UNSETENV_OCALL_DEFINED__
#define U_UNSETENV_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_unsetenv_ocall, (int* error, const char* name));
#endif
#ifndef U_CHDIR_OCALL_DEFINED__
#define U_CHDIR_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_chdir_ocall, (int* error, const char* dir));
#endif
#ifndef U_GETCWD_OCALL_DEFINED__
#define U_GETCWD_OCALL_DEFINED__
char* SGX_UBRIDGE(SGX_NOCONVENTION, u_getcwd_ocall, (int* error, char* buf, size_t buflen));
#endif
#ifndef U_GETPWUID_R_OCALL_DEFINED__
#define U_GETPWUID_R_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, u_getpwuid_r_ocall, (unsigned int uid, struct passwd* pwd, char* buf, size_t buflen, struct passwd** passwd_result));
#endif
#ifndef U_GETUID_OCALL_DEFINED__
#define U_GETUID_OCALL_DEFINED__
unsigned int SGX_UBRIDGE(SGX_NOCONVENTION, u_getuid_ocall, (void));
#endif
#ifndef U_SGXPROTECTEDFS_EXCLUSIVE_FILE_OPEN_DEFINED__
#define U_SGXPROTECTEDFS_EXCLUSIVE_FILE_OPEN_DEFINED__
void* SGX_UBRIDGE(SGX_NOCONVENTION, u_sgxprotectedfs_exclusive_file_open, (const char* filename, uint8_t read_only, int64_t* file_size, int32_t* error_code));
#endif
#ifndef U_SGXPROTECTEDFS_CHECK_IF_FILE_EXISTS_DEFINED__
#define U_SGXPROTECTEDFS_CHECK_IF_FILE_EXISTS_DEFINED__
uint8_t SGX_UBRIDGE(SGX_NOCONVENTION, u_sgxprotectedfs_check_if_file_exists, (const char* filename));
#endif
#ifndef U_SGXPROTECTEDFS_FREAD_NODE_DEFINED__
#define U_SGXPROTECTEDFS_FREAD_NODE_DEFINED__
int32_t SGX_UBRIDGE(SGX_NOCONVENTION, u_sgxprotectedfs_fread_node, (void* f, uint64_t node_number, uint8_t* buffer, uint32_t node_size));
#endif
#ifndef U_SGXPROTECTEDFS_FWRITE_NODE_DEFINED__
#define U_SGXPROTECTEDFS_FWRITE_NODE_DEFINED__
int32_t SGX_UBRIDGE(SGX_NOCONVENTION, u_sgxprotectedfs_fwrite_node, (void* f, uint64_t node_number, uint8_t* buffer, uint32_t node_size));
#endif
#ifndef U_SGXPROTECTEDFS_FCLOSE_DEFINED__
#define U_SGXPROTECTEDFS_FCLOSE_DEFINED__
int32_t SGX_UBRIDGE(SGX_NOCONVENTION, u_sgxprotectedfs_fclose, (void* f));
#endif
#ifndef U_SGXPROTECTEDFS_FFLUSH_DEFINED__
#define U_SGXPROTECTEDFS_FFLUSH_DEFINED__
uint8_t SGX_UBRIDGE(SGX_NOCONVENTION, u_sgxprotectedfs_fflush, (void* f));
#endif
#ifndef U_SGXPROTECTEDFS_REMOVE_DEFINED__
#define U_SGXPROTECTEDFS_REMOVE_DEFINED__
int32_t SGX_UBRIDGE(SGX_NOCONVENTION, u_sgxprotectedfs_remove, (const char* filename));
#endif
#ifndef U_SGXPROTECTEDFS_RECOVERY_FILE_OPEN_DEFINED__
#define U_SGXPROTECTEDFS_RECOVERY_FILE_OPEN_DEFINED__
void* SGX_UBRIDGE(SGX_NOCONVENTION, u_sgxprotectedfs_recovery_file_open, (const char* filename));
#endif
#ifndef U_SGXPROTECTEDFS_FWRITE_RECOVERY_NODE_DEFINED__
#define U_SGXPROTECTEDFS_FWRITE_RECOVERY_NODE_DEFINED__
uint8_t SGX_UBRIDGE(SGX_NOCONVENTION, u_sgxprotectedfs_fwrite_recovery_node, (void* f, uint8_t* data, uint32_t data_length));
#endif
#ifndef U_SGXPROTECTEDFS_DO_FILE_RECOVERY_DEFINED__
#define U_SGXPROTECTEDFS_DO_FILE_RECOVERY_DEFINED__
int32_t SGX_UBRIDGE(SGX_NOCONVENTION, u_sgxprotectedfs_do_file_recovery, (const char* filename, const char* recovery_filename, uint32_t node_size));
#endif

sgx_status_t enclave_create_report(sgx_enclave_id_t eid, sgx_status_t* retval, const sgx_target_info_t* p_qe3_target, sgx_report_t* p_report, uint8_t enclave_data[32]);
sgx_status_t wallet_operation(sgx_enclave_id_t eid, sgx_status_t* retval, const uint8_t* sealed_request_buffer, size_t sealed_request_size, uint8_t* sealed_response_buffer, size_t sealed_response_capacity, size_t* sealed_response_used);
sgx_status_t t_global_init_ecall(sgx_enclave_id_t eid, uint64_t id, const uint8_t* path, size_t len);
sgx_status_t t_global_exit_ecall(sgx_enclave_id_t eid);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
