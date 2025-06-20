#include <sys/stat.h>
#include <stdint.h>
#include <errno.h>

void *_sbrk(ptrdiff_t incr) { return (void *)-1; }
int _close(int fd) { return -1; }
int _fstat(int fd, struct stat *st) { return 0; }
int _isatty(int fd) { return 1; }
int _lseek(int fd, int ptr, int dir) { return 0; }
int _open(const char *path, int flags, ...) { return -1; }
int _read(int fd, void *ptr, size_t len) { return 0; }
int _write(int fd, const void *ptr, size_t len) { return len; }
void _exit(int status) { while (1) {} }
int _kill(int pid, int sig) { return -1; }
int _getpid(void) { return 1; }