#pragma once

#define u32 unsigned int
#define u16 unsigned short
#define u8  unsigned char
#define _BYTE unsigned char
#define _DWORD unsigned int
#define __PAIR__
#define __uint64_t	unsigned __int64
#define __int64_t	__int64

void print(u32* a);

void print(u32* a, char *info);
void testReversal();

void testEncyption(void);

__uint64_t mul_32(u32 R0, u32 R1, u32 R2, u32 R3); // r0 * r2

void mul_256_add(u32 R0, u32 *R1, u32 *R2, u32 *R3);

void reversal_byte(u8 *a1, u8 *a2);

void Encryption(u32* R0, u32* R1, u32* R2);

void test_reversal_byte(u8 *a1, u8 *a2);

void test_mul_32(u32 R0, u32 R1, u32 R2, u32 R3);
void test_mul_256_add();

void test_mul_256_add(u32 R0, u32 *R1, u32 *R2, u32 *R3);
void test_mul_256_add();

void test_encryption(u32* R0, u32* R1, u32* R2);
void test_mul_32();
void qiufan(u32 *a);
