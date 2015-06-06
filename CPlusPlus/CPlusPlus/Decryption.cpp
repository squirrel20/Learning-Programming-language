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

#define TEST_REVERSAL 0
#define TEST_MUL_32 0
#define TEST_MUL_256_ADD 0 
#define TEST_ENCRYPTION 0



 u32 dword_1[] = {0x77311F33, 0xD393A14C, 0xBADB54DE, 0x8088CD0E};
								
 u32 dword_2[] = {0xBB1B71EA, 0x5DC4E44D, 0x9344E72A, 0x8A98747E};
								
 u32 dword_3[] = {0xD9066581, 0xEE397C94, 0x39B6BD11, 0x9D18FAA0};
								
//	dword_1,dword_2,dword_3,为常数不会改变							
								

// return r0 * r2
__uint64_t mul_32( u32 R0, u32 R1, u32 R2, u32 R3 ) // r0 * r2
{
#if TEST_MUL_32
	printf("before mul 32 :\tR0=0x%04X\tR1=0x%04X\tR2=0x%04X\tR3=0x%04X\n", R0, R1, R2, R3);
#endif
	u32 R4,R5,R6,R7,R12;
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

	if( (u32)R7 > (u32)R0 )
	{
		R5 += 0x10000;
	}

	R1 = (R12 * R4 + R1 * R2) + (R5 + (R0 >> 16));
	R0 = (R0 << 16) + (R6 & 0xFFFF);


	R1R0 = ((__uint64_t)R1 << 32) + R0;

#if TEST_MUL_32
	printf("after mul 32 :\tR0=0x%04X\tR1=0x%04X\tR2=0x%04X\tR3=0x%04X\n", R0, R1, R2, R3);
#endif
	return R1R0;
}

// 精简函数mul_32，去掉无用的参数
// return r0 * r2
__uint64_t mul_32( u32 R0, u32 R2 ) // r0 * r2
{
#if TEST_MUL_32
	printf("before mul 32 :\tR0=0x%04X\tR1=0x%04X\tR2=0x%04X\tR3=0x%04X\n", R0, R1, R2, R3);
#endif
	u32 R1 = 0;
	u32 R3 = 0;
	u32 R4,R5,R6,R7,R12;
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

	if( (u32)R7 > (u32)R0 )
	{
		R5 += 0x10000;
	}

	R1 = (R12 * R4 + R1 * R2) + (R5 + (R0 >> 16));
	R0 = (R0 << 16) + (R6 & 0xFFFF);


	R1R0 = ((__uint64_t)R1 << 32) + R0;

#if TEST_MUL_32
	printf("after mul 32 :\tR0=0x%04X\tR1=0x%04X\tR2=0x%04X\tR3=0x%04X\n", R0, R1, R2, R3);
#endif
	return R1R0;
}

// 计算后R1会变，R2，R3不变
// RO = 0xD28257F
// R1 在计算时会被初始化为 {0, 0, 0, 0}, 就是说该计算的返回值放在R1中，传入时R1为任何值都不会影响到计算
// R2
// R3
// R1 = f(R0, R2, R3), R2 != 0, R3 != 0
void mul_256_add( u32 R0, u32 *R1, u32 *R2, u32 *R3 )
/*
Encryption函数调用mul_256_add有三种样式:
1.r2 == r3
2.r3 为常数
3.r3 为需加密的原始数(即179行的Y)

1 2两种情况可以得到为一的v29,从而算出R2(R2,R3为16字节数,从最高4字节可算出V29的大致范围,用穷尽法可得V29)
3这情况就不知道怎么办了

设 R2 * R3 = a31a30a29a28a27a26a25a24a23a22a21a20a19a18a17a16a15a14a13a12a11a10a09a08a07a06a05a04a03a02a01a00
则v29i0 = (u32)a03a02a01a00 *0xD28257F;

设 R2 * R3 + v29i0 * dword_3= b31b30b29b28b27b26b25b24b23b22b21b20b19b18b17b16b15b14b13b12b11b10b09b08b07b06b05b04b03b02b01b00
则 b03b02b01b00 = 0
v29i1 = (u32)(b07b06b05b04*0xD28257F;
 
设 R2 * R3 + (v29i1 *dword_3) <<32 + v29i0 * dword_3= c31c30c29c28c27c26c25c24c23c22c21c20c19c18c17c16c15c14c13c12c11c10c09c08c07c06c05c04c03c02c01c00
则 c03c02c01c00 = 0,c07c06c05c04=0
v29i2 = (u32)(c11c10c09c08*0xD28257F;

设 R2 * R3 + (v29i2 *dword_3) <<64 + (v29i1 *dword_3) <<32 + v29i0 * dword_3= d31d30d29d28d27d26d25d24d23d22d21d20d19d18d17d16d15d14d13d12d11d10d09d08d07d06d05d04d03d02d01d00
则 d03d02d01d00 = 0,d07d06d05d04=0,d11d10d09d08=0,
v29i3 = (u32)(d15d14d13d12*0xD28257F;

设 R2 * R3 + (v29i3 *dword_3) <<96 + (v29i2 *dword_3) <<64 + (v29i1 *dword_3) <<32 + v29i0 * dword_3= e31e30e29e28e27e26e25e24e23e22e21e20e19e18e17e16e15e14e13e12e11e10e09e08e07e06e05e04e03e02e01e00
则 e03e02e01e00 = 0,e07e06e05e04=0,e11e10e09e08=0,e15e14e13e12=0,
e31e30e29e28e27e26e25e24e23e22e21e20e19e18e17e16 = R1  为输出结果


*/
{
	static int num = 1;
#if TEST_MUL_256_ADD
	printf("before mul 256 add : %d\n", num++);
	printf("R0=\t0x%04X\n", R0);
	print(R1, "R1=");
	print(R2, "R2=");
	print(R3, "R3=");
#endif
	u32 *R5,*R6,*R7;
	u32 R12;
	u32 i,j,k;

	u32 *a3 = (u32 *)R3;
	u32 *a2 = (u32 *)R2;
	u32 *a1 = (u32 *)R1;
	u32 a0 = R0;

	u32 v0;
	u32 v29;

	__uint64_t v5v1;
	__uint64_t v3v1;

	__uint64_t R1R0;
	__uint64_t v35;

	u32 *v19 = (u32*)(dword_3);
	u32 *v1 = a1;
	__uint64_t v21;
	u32 v22;
	__uint64_t result = 0;

	// ? 那这个和传入 {0, 0, 0, 0}有什么区别
	// 没区别
	*(R1+0) = 0;
	*(R1+1) = 0;
	*(R1+2) = 0;
	*(R1+3) = 0;

	// TODO v29
	for( i = 0; i < 4; i++ )// a1 = a3 * a2 + dword_3 * (v29i3<<96 + v29i2<<64 + v29i1<<32 + v29i0)
	{
		//------------------------------------------------------------------------------------------------
		v0 = a2[i];
		//v0 = *a2++;
		R6 = a3;	// dword_2
		R5 = (u32*)(dword_3); 

		//R1R0 = mul_32(v0, *R6++);
		//v5v1 = *a1 + R1R0;	// v5v1 = R1[i] + R2[i] * R3[i];
		v5v1 = *a1 + mul_32(v0, *R6++);

		v29 = (u32)(R0 * v5v1);	// v29 = R0 * v5v1 = R0 * (R1[i] + R2[i] * R3[i]);
		R1R0 = mul_32( v29, *R5++);	// R1R0 = R0 * (R1[i] + R2[i] * R3[i]) * (*dword_3++);

		v3v1 = R1R0 + (u32)v5v1;	// v3v1 = R0 * (R1[i] + R2[i] * R3[i]) * (*dword_3++) + R1[i] + R2[i] * R3[i]

		R7 = a1;

		//------------------------------------------------------------------------------------------------
		for( j = 0; j < 3; j++ ) // a1 = a3 * v0 + dword_3 * v29
		{
			R12 = *R6++;
			v5v1 = *(R7+1) + (v5v1>>32) + mul_32( R12, v0);
			v3v1 = mul_32( *R5++, v29) + (u32)(v3v1>>32) + (u32)(v5v1);
			*R7++ = (u32)v3v1;	// TODO 将计算结果v3v1赋给 *R7
		}

		//------------------------------------------------------------------------------------------------
		v35 = (v3v1>>32) + (v5v1>>32);
		a1[3] = (u32)v35;
		if( (v35>>32) == 0 ) continue;
		//Carry
		v1 = a1;
		v19 = (u32*)(dword_3);
		result = 0;
		for( k = 0; k < 4; k++ ) //a1 - dword_3
		{
			v21 = *v1 + result;
			v22 = *v19++;
			*v1++ = (u32)v21 - v22;
			result = (v21 >> 32) - ((u32)v21 < v22);
		}
	}

#if TEST_MUL_256_ADD
	printf("after mul 256 add :\n");
	printf("R0=\t0x%04X\n", R0);
	print(R1, "R1=");
	print(R2, "R2=");
	print(R3, "R3=");
	printf("\n");
#endif
}


// 将a2按字节反转后赋给a1
void reversal_byte(u8 *a1, u8 *a2)
{
#if TEST_REVERSAL
	printf("before reversal byte :\t");
	print((u32*)a1);
#endif
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
  }
  while ( v3 != 7 );
#if TEST_REVERSAL
	printf("after reversal byte  :\t");
	print((u32*)a1);
#endif
}

// 加密R0。R1和R2是局部变量
void Encryption( u32* R0, u32* R1, u32* R2 )
{
#if TEST_ENCRYPTION
	printf("before encryption :\n");
	print(R0, "R0=");
	print(R1, "R1=");
	print(R2, "R2=");
#endif
	u32 *in0 = (u32*)R0;
	u32 *in1 = (u32*)R1;
	u32 *in2 = (u32*)R2;

	u32 *pBuf1;
	u32 *pBuf2;
	int  i;

	reversal_byte( (u8 *)in1, (u8 *)in0 );

	mul_256_add( 0xD28257F, (u32*)in0, (u32*)in1, (u32*)(dword_2));//mul_256_add : r3为常数
	//设此处计算得的in0为要加密的数为 Y

	pBuf2 = in2;
	pBuf1 = in0;
	i = 1;

	//printf("----------------------------------------------------------------------------------\n");
	do {
		mul_256_add( 0xD28257F, (u32*)pBuf2, (u32*)pBuf1, (u32*)pBuf1 );//mul_256_add : r2 == r3

		if( pBuf2 == in2 )
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

		if( ((buf8[0xF] >> ((~i) & 7)) & 0x1) != 0 )
		{
			//printf("【if】");
			mul_256_add(0xD28257F, (u32*)pBuf2, (u32*)pBuf1, (u32*)in0);//mul_256_add : r3为Y 此处为难点

			if( pBuf2 == in2 )
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
	} while( i != 128 );
	//printf("----------------------------------------------------------------------------------\n");

	pBuf2[0] = 1;
	pBuf2[1] = 0;
	pBuf2[2] = 0;
	pBuf2[3] = 0;

	mul_256_add( 0xD28257F, (u32*)in0, (u32*)pBuf1, (u32*)pBuf2 );//mul_256_add : r3为常数
	reversal_byte( (u8 *)in0, (u8 *)in0 );
#if TEST_ENCRYPTION
	printf("after encryption :\n");
	print(R0, "R0=");
	print(R1, "R1=");
	print(R2, "R2=");
#endif
}	

void Encryption2( u32* R0, u32* R1, u32* R2 )
{
#if TEST_ENCRYPTION
	printf("before encryption :\n");
	print(R0, "R0=");
	print(R1, "R1=");
	print(R2, "R2=");
#endif
	u32 *in0 = (u32*)R0;
	u32 *in1 = (u32*)R1;
	u32 *in2 = (u32*)R2;

	u32 *pBuf1;
	u32 *pBuf2;
	int  i;

	reversal_byte( (u8 *)in1, (u8 *)in0 );

	mul_256_add( 0xD28257F, (u32*)in0, (u32*)in1, (u32*)(dword_2));//mul_256_add : r3为常数
	//设此处计算得的in0为要加密的数为 Y

	pBuf2 = in2;
	pBuf1 = in0;
	i = 1;

	printf("----------------------------------------------------------------------------------\n");
	print(R0, "R0=");
	print(R1, "R1=");
	print(R2, "R2=");
	do {
		mul_256_add( 0xD28257F, (u32*)pBuf2, (u32*)pBuf1, (u32*)pBuf1 );//mul_256_add : r2 == r3

		if( pBuf2 == in2 )
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

		if( ((buf8[0xF] >> ((~i) & 7)) & 0x1) != 0 )
		{
			//printf("【if】");
			mul_256_add(0xD28257F, (u32*)pBuf2, (u32*)pBuf1, (u32*)in0);//mul_256_add : r3为Y 此处为难点

			if( pBuf2 == in2 )
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
	} while (i != 128);

	print(R0, "R0=");
	print(R1, "R1=");
	print(R2, "R2=");

	qiufan(dword_1);
	i = 1;
	do {
		mul_256_add(0xD28257F, (u32*)pBuf2, (u32*)pBuf1, (u32*)pBuf1);//mul_256_add : r2 == r3

		if( pBuf2 == in2 )
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

		if( ((buf8[0xF] >> ((~i) & 7)) & 0x1) != 0 )
		{
			//printf("【if】");
			mul_256_add(0xD28257F, (u32*)pBuf2, (u32*)pBuf1, (u32*)in0);//mul_256_add : r3为Y 此处为难点

			if( pBuf2 == in2 )
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
	} while( i != 128 );
	print(R0, "R0=");
	print(R1, "R1=");
	print(R2, "R2=");
	printf("----------------------------------------------------------------------------------\n");

	pBuf2[0] = 1;
	pBuf2[1] = 0;
	pBuf2[2] = 0;
	pBuf2[3] = 0;

	mul_256_add( 0xD28257F, (u32*)in0, (u32*)pBuf1, (u32*)pBuf2 );//mul_256_add : r3为常数
	reversal_byte( (u8 *)in0, (u8 *)in0 );
#if TEST_ENCRYPTION
	printf("after encryption :\n");
	print(R0, "R0=");
	print(R1, "R1=");
	print(R2, "R2=");
#endif
}
void testEncyption( void )
{
	int i;
	int checkedFlag = 1;

	u32 result[16/4] = { 0xBE232979, 0xD66CE184, 0x499052AE, 0xE9BBF1F1 };

	u32 buf1[16/4] = { 0x283A2E50, 0x74EE8505, 0x4A49FEC4, 0xC8A853B8 };
	u32 buf2[16/4] = { 0, 0, 0, 0 };
	u32 buf3[16/4] = { 0, 0, 0, 0 };

	//qiufan((u32*)dword_1);
	//qiufan((u32*)dword_2);

	Encryption(buf1,buf2,buf3);
	//Encryption(result,buf2,buf3);

	for (i=0;i<4; i+= 2){
		printf( "0x%04X 0x%04X\n", buf1[i], buf1[i+1] );
		//printf( "0x%04X 0x%04X\n", result[i], result[i+1] );
		if( buf1[i] != result[i] || buf1[i+1] != result[i+1] ) checkedFlag = 0;
	}

	if( checkedFlag )
	{
		printf( "\nChecked OK!\n\n" );
	}

}


/*
以上代码为加密算法，例： 由数据{ 0x283A2E50, 0x74EE8505, 0x4A49FEC4, 0xC8A853B8 } 得到 { 0xBE232979, 0xD66CE184, 0x499052AE, 0xE9BBF1F1 }
现求解密算法 例： 由数据{ 0xBE232979, 0xD66CE184, 0x499052AE, 0xE9BBF1F1 } 得到 { 0x283A2E50, 0x74EE8505, 0x4A49FEC4, 0xC8A853B8 }

效验IC过程:
a,b,c为16字节数

a -> FPGA -> IC -> b,看过IC入口数据与a相同

b 经Encryption运算 -> c
如果c 等于 a 的话就说明正常


多给几组数据:
b:0x6f,0x78,0xaf,0x16,0xdd,0xe1,0x9a,0x56,0x21,0x45,0x66,0x25,0x41,0x9b,0x18,0xec,
a:0x79,0x3b,0xd7,0x1e,0xe1,0x33,0x56,0xb7,0x87,0xf8,0xcb,0xc5,0x53,0xe5,0x66,0x40,

b:0x6d,0x6e,0x85,0x45,0x72,0xb7,0xdb,0x26,0x4e,0x0e,0xaf,0xbe,0xff,0x32,0x80,0xab,
a:0x79,0xf5,0xa9,0xfc,0x8a,0x30,0xc4,0xd1,0xcd,0xb2,0x1a,0xd4,0xa2,0xad,0xe2,0x31,

b:0x1b,0x39,0xa8,0xc6,0xec,0x99,0xf2,0x14,0x0f,0x73,0x61,0x31,0xdc,0xd8,0x2e,0xd6,
a:0x79,0xb2,0x31,0x94,0x34,0x38,0x1c,0x93,0xdc,0xe5,0x38,0xeb,0x74,0xf7,0x96,0xef,

b:0x50,0x2e,0x3a,0x28,0x05,0x85,0xee,0x74,0xc4,0xfe,0x49,0x4a,0xb8,0x53,0xa8,0xc8,
a:0x79,0x29,0x23,0xbe,0x84,0xe1,0x6c,0xd6,0xae,0x52,0x90,0x49,0xf1,0xf1,0xbb,0xe9,

*/

void test_reversal_byte(u8 *a1, u8 *a2)
{
#ifdef TEST_REVERSAL
	printf("before reversal byte :\n");
	print((u32*)a1, "a1=");
	print((u32*)a2, "a2=");
	reversal_byte((u8 *)a1, (u8 *)a2);
	printf("after reversal byte  :\n");
	print((u32*)a1, "a1=");
	print((u32*)a2, "a2=");
#endif
}

void test_mul_32()
{
	test_mul_32(1, 0, 2, 0);
	test_mul_32(6, 0, 7, 0);
	test_mul_32(1111, 0x0AAAAAAA, 2222, 0x0AAAAAAA);
}

void test_mul_32(u32 R0, u32 R1, u32 R2, u32 R3)
{
#ifdef TEST_MUL_32
	printf("before mul 32 :\tR0=0x%04X\tR1=0x%04X\tR2=0x%04X\tR3=0x%04X\n", R0, R1, R2, R3);
	__uint64_t result = mul_32(R0, R1, R2, R3); // r0 * r2
	printf("%ld\n", result);
	printf("after mul 32  :\tR0=0x%04X\tR1=0x%04X\tR2=0x%04X\tR3=0x%04X\n", R0, R1, R2, R3);
#endif
}

// f( f(r2,r2), f(r3,r3) ) == f( f(r2,r3), f(r2,r3) )
void test_mul_256_add()
{
	//u32 R2[][4] = {
	//	{0,0,0,1},
	//	{0,0,0,2},
	//	{1,1,1,1},
	//	{ 0x283A2E50, 0x74EE8505, 0x4A49FEC4, 0xC8A853B8 }
	//};
	//int len = sizeof(R2) / (sizeof(u32) * 4);

	//for (int i = 0; i < len; i++)
	//{
	//	//u32 R0 = 0;
	//	u32 R0 = 0xD28257F;
	//	u32 R1[4] = { 0, 0, 0, 0 };
	//	printf("【%d】 -----------------------------------------------------\n", i);
	//	printf("R0=\t%d\n", R0);
	//	// 若R3={0,0,0,0},则R1[i]={0,0,0,0}
	//	//u32 R3[4] = { 0,0,0,0 };
	//	u32 *R3 = (u32*)dword_2;

	//	//reversal_byte((u8*)R2, (u8*)R1[i]);
	//	test_mul_256_add(R0, R1, R2[i], R3);	// 传入参数R1用来保存计算结果
	//	//test_mul_256_add(R0, R1[i], R3, R2);
	//}

	u32 R0 = 0xD28257F;
	u32 R10[4] = { 0, 0, 0, 0 };
	u32 R11[4] = { 0, 0, 0, 0 };
	u32 R12[4] = { 0, 0, 0, 0 };
	u32 R20[4] = { 0x53AE1F00, 0xE2B8C077, 0xAE45E44B, 0xB817A9B3 };
	u32 R21[4] = { 0x53AE1F00, 0xE2B8C077, 0xAE45E44B, 0xB817A9B3 };
	u32 R30[4] = { 0x334E29F0, 0xE1BF6F2D, 0x71AF9C59, 0xC37D7852 };
	u32 R31[4] = { 0x334E29F0, 0xE1BF6F2D, 0x71AF9C59, 0xC37D7852 };
	u32 R40[4] = { 0xCECFDF17, 0xF4C9FA0A, 0x5FC2BB2A, 0x684CC478 };
	u32 R41[4] = { 0xCECFDF17, 0xF4C9FA0A, 0x5FC2BB2A, 0x684CC478 };

	u32 R1[4] = { 0, 0, 0, 0 };

	// (a * b) c == a * (b * c)

	//test_mul_256_add(R0, R10, R20, R30);
	//test_mul_256_add(R0, R11, R21, R31);

	//test_mul_256_add(R0, R10, R20, R21);
	//test_mul_256_add(R0, R11, R30, R31);

	//test_mul_256_add(R0, R1, R10, R11);

	// (a * b) * c
	//test_mul_256_add(R0, R10, R20, R30); // a * b
	//test_mul_256_add(R0, R11, R10, R40); // (a * b) * c

	// a * (b * c)
	//test_mul_256_add(R0, R10, R30, R40);	// b * c
	//test_mul_256_add(R0, R11, R20, R10);	// (b * c) * a

	u32 R2[4] = { 0x53AE1F00, 0xE2B8C077, 0xAE45E44B, 0xB817A9B3 };
	u32 R3[4] = { 0x10000000, 0, 0, 0 };
	print(R2);
	for (int i = 0; i < 127; i++)
	{
		mul_256_add(R0, R1, R2, R2);
		R2[0] = R1[0];
		R2[1] = R1[1];
		R2[2] = R1[2];
		R2[3] = R1[3];
	}
	print(R2);

}

void test_mul_256_add(u32 R0, u32 *R1, u32 *R2, u32 *R3)
{
#ifdef TEST_MUL_256_ADD
	//printf("before mul 256 add :\t");
	//printf("R0=\t0x%04X\n", R0);
	//print(R1, "R1=");
	//print(R2, "R2=");
	//print(R3, "R3=");
	mul_256_add(R0, R1, R2, R3);
	//printf("after mul 256 add  :\t");
	//printf("R0=\t0x%04X\n", R0);
	print(R1, "R1=");
	print(R2, "R2=");
	print(R3, "R3=");
#endif
}

void test_encryption(u32* R0, u32* R1, u32* R2)
{
#ifdef TEST_ENCRYPTION
	printf("before encryption :\n");
	print(R0, "R0=");
	print(R1, "R1=");
	print(R2, "R2=");

	Encryption(R0, R1, R2);

	printf("after encryption :\n");
	print(R0, "R0=");
	print(R1, "R1=");
	print(R2, "R2=");
#endif
}

void print(u32 *a)
{
	printf("0x%04X 0x%04X 0x%04X 0x%04X\n", a[0], a[1], a[2], a[3]);
}

void print(u32 *a, char *info)
{
	printf("%s\t0x%04X 0x%04X 0x%04X 0x%04X\n", info, a[0], a[1], a[2], a[3]);
}

void qiufan(u32 *a)
{
	a[0] = ~a[0];
	a[1] = ~a[1];
	a[2] = ~a[2];
	a[3] = ~a[3];
}