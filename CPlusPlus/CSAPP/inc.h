#ifndef _INC_H_
#define _INC_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <setjmp.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h>
#include <math.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <limits.h>

#define BEGIN_TEST printf("\n------------[%s][%d]----------------------\n", __FUNCTION__, __LINE__);
#define END_TEST printf("--------------------------end-------------------------------\n");

// 2.55, 2.56, 2.57
typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start, int len);
void show_int(int x);
void show_float(float x);
void show_pointer(void *x);
void show_short(short x);
void show_long(long x);
void show_double(double x);
void show_bytes_test();

// 2.58
int is_little_endian();
void is_little_endian_test();

// 2.59
int f259(int x, int y);
void f259_test();

// 2.60
unsigned put_byte(unsigned x, unsigned char b, int i);
void put_byte_test();

// 2.61
int f261(int x);
void f261_test();

// 2.62
int int_shifts_are_logical();
void int_shifts_are_logical_test();

#endif
