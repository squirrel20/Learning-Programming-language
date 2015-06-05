#include "stdafx.h"

#define u32 unsigned int
#define u16 unsigned short
#define u8  unsigned char
#define _BYTE unsigned char
#define _DWORD unsigned int
#define __PAIR__

/*
#define __int64		__int64_t
#define __uint64 	__uint64_t
*/

#define __uint64_t	unsigned __int64
#define __int64_t	__int64


const u32 dword_1[] = { 0x77311F33, 0xD393A14C, 0xBADB54DE, 0x8088CD0E };

const u32 dword_2[] = { 0xBB1B71EA, 0x5DC4E44D, 0x9344E72A, 0x8A98747E };

const u32 dword_3[] = { 0xD9066581, 0xEE397C94, 0x39B6BD11, 0x9D18FAA0 };




__uint64_t mul_32(u32 R0, u32 R1, u32 R2, u32 R3) // r0 * r2
{
	u32 R4, R5, R6, R7, R12;
	__uint64_t R1R0;

	R12 = R3;
	R3 = R0 & 0xFFFF;
	R7 = R2 & 0xFFFF;
	R5 = R2 >> 16;
	R4 = R0;
	R0 = R0 >> 16;
	R6 = R3;
	R6 = R6 * R7;
	R3 = R3 * R5;
	R7 = R7 * R0;
	R5 = R5 * R0;
	R0 = (R7 + R3) + (R6 >> 16);

	if ((u32)R7 > (u32)R0)
	{
		R5 += 0x10000;
	}

	R1 = (R12 * R4 + R1 * R2) + (R5 + (R0 >> 16));
	R0 = (R0 << 16) + (R6 & 0xFFFF);


	R1R0 = ((__uint64_t)R1 << 32) + R0;

	return R1R0;
}

void mul_256_add(u32 R0, u32 *R1, u32 *R2, u32 *R3)
{
	u32 *R5, *R6, *R7;
	u32 R12;
	u32 i, j, k;

	u32 *a4 = (u32 *)R3;
	u32 *a3 = (u32 *)R2;
	u32 *a2 = (u32 *)R1;
	u32 a1 = R0;

	u32 v0;
	u32 v29;

	__uint64_t v5v1;
	__uint64_t v3v1;

	__uint64_t R1R0;
	__uint64_t v35;

	u32 *v19 = (u32*)(dword_3);
	u32 *v20 = a2;
	__uint64_t v21;
	u32 v22;
	__uint64_t result = 0;

	*(R1 + 0) = 0;
	*(R1 + 1) = 0;
	*(R1 + 2) = 0;
	*(R1 + 3) = 0;

	for (i = 0; i < 4; i++)// a2 = a4 * a3 + dword_3 * (v29i3<<96 + v29i2<<64 + v29i1<<32 + v29i0)
	{
		//------------------------------------------------------------------------------------------------
		v0 = *a3++;
		R6 = a4;

		R1R0 = mul_32(v0, 0, *R6++, 0);
		v5v1 = *a2 + R1R0;
		R5 = (u32*)(dword_3);

		v29 = (u32)(a1 * v5v1);
		R1R0 = mul_32(v29, 0, *R5++, 0);

		v3v1 = R1R0 + (u32)v5v1;

		R7 = a2;

		//------------------------------------------------------------------------------------------------
		for (j = 0; j < 3; j++) // a2 = a4 * v0 + dword_3 * v29
		{
			R12 = *R6++;
			v5v1 = *(R7 + 1) + (v5v1 >> 32) + mul_32(R12, 0, v0, 0);
			v3v1 = mul_32(*R5++, 0, v29, 0) + (u32)(v3v1 >> 32) + (u32)(v5v1);
			*R7++ = (u32)v3v1;
		}

		//------------------------------------------------------------------------------------------------
		v35 = (v3v1 >> 32) + (v5v1 >> 32);
		a2[3] = (u32)v35;
		if ((v35 >> 32) == 0) continue;
		//Carry
		v20 = a2;
		v19 = (u32*)(dword_3);
		result = 0;
		for (k = 0; k < 4; k++) //a2 - dword_3
		{
			v21 = *v20 + result;
			v22 = *v19++;
			*v20++ = (u32)v21 - v22;
			result = (v21 >> 32) - ((u32)v21 < v22);
		}
	}
}

// 按字节反转a2，反转的值赋给a1。共16字节,unsigned int [4]
void reversal_byte(u8 *a1, u8 *a2)
{
	u32 v2;
	u32 v3;
	u8 v4;

	v2 = 0;
	v3 = 15;
	do
	{
		v4 = a2[v3];
		a1[v3--] = a2[v2];
		a1[v2++] = v4;
	} while (v3 != 7);
}

void Encryption(u32* R0, u32* R1, u32* R2)
{
	u32 *in0 = (u32*)R0;
	u32 *in1 = (u32*)R1;
	u32 *in2 = (u32*)R2;

	u32 *pBuf1;
	u32 *pBuf2;
	int  i;

	printf("before reversal 0x%04X 0x%04X\n", *in1, *in0);
	reversal_byte((u8 *)in1, (u8 *)in0);	// 将反转的in0赋给in1
	printf("after reversal  0x%04X 0x%04X\n", *in1, *in0);

	mul_256_add(0xD28257F, (u32*)in0, (u32*)in1, (u32*)(dword_2));

	pBuf2 = in2;
	pBuf1 = in0;
	i = 1;

	do {
		mul_256_add(0xD28257F, (u32*)pBuf2, (u32*)pBuf1, (u32*)pBuf1);

		if (pBuf2 == in2)
		{
			pBuf1 = in2;
			pBuf2 = in1;
		}
		else
		{
			pBuf1 = in1;
			pBuf2 = in2;
		}

		u8 *buf8 = (u8*)((u32)dword_1 - (i >> 3));

		if (((buf8[0xF] >> ((~i) & 7)) & 0x1) != 0)
		{
			mul_256_add(0xD28257F, (u32*)pBuf2, (u32*)pBuf1, (u32*)in0);

			if (pBuf2 == in2)
			{
				pBuf1 = in2;
				pBuf2 = in1;
			}
			else
			{
				pBuf1 = in1;
				pBuf2 = in2;
			}
		}

		i++;
	} while (i != 0x80);

	pBuf2[0] = 1;
	pBuf2[1] = 0;
	pBuf2[2] = 0;
	pBuf2[3] = 0;

	mul_256_add(0xD28257F, (u32*)in0, (u32*)pBuf1, (u32*)pBuf2);
	reversal_byte((u8 *)in0, (u8 *)in0);
}

void testEncyption(void)
{
	int i;
	int checkedFlag = 1;

	u32 result[16 / 4] = { 0xBE232979, 0xD66CE184, 0x499052AE, 0xE9BBF1F1 };

	u32 buf1[16 / 4] = { 0x283A2E50, 0x74EE8505, 0x4A49FEC4, 0xC8A853B8 };
	u32 buf2[16 / 4] = { 0, 0, 0, 0 };
	u32 buf3[16 / 4] = { 0, 0, 0, 0 };

	Encryption(buf1, buf2, buf3);

	for (i = 0; i < 4; i += 2) {
		printf("0x%04X 0x%04X\n", buf1[i], buf1[i + 1]);
		if (buf1[i] != result[i] || buf1[i + 1] != result[i + 1]) checkedFlag = 0;
	}

	if (checkedFlag)
	{
		printf("\nChecked OK!\n\n");
	}

}

void testReversal()
{
	u32 a1[4] = { 0x01020304, 0x05060708, 0x090A0B0C, 0x0D0E0F00 };
	u32 a2[4] = { 0, 0, 0, 0 };

	u32 *a = a2;

	printf("before: 0x%04X 0x%04X 0x%04X 0x%04X\n", a[0], a[1], a[2], a[3]);
	reversal_byte((u8 *)a2, (u8 *)a1);
	printf("after : 0x%04X 0x%04X 0x%04X 0x%04X\n", a[0], a[1], a[2], a[3]);
}

/*
以上代码为加密算法，例： 由数据{ 0x283A2E50, 0x74EE8505, 0x4A49FEC4, 0xC8A853B8 } 得到 { 0xBE232979, 0xD66CE184, 0x499052AE, 0xE9BBF1F1 }
现求解密算法 例： 由数据{ 0xBE232979, 0xD66CE184, 0x499052AE, 0xE9BBF1F1 } 得到 { 0x283A2E50, 0x74EE8505, 0x4A49FEC4, 0xC8A853B8 }
*/

