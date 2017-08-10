
bomb:     file format elf64-x86-64


Disassembly of section .init:

0000000000400a98 <_init>:
  400a98:	48 83 ec 08          	sub    $0x8,%rsp
  400a9c:	48 8b 05 55 25 20 00 	mov    0x202555(%rip),%rax        # 602ff8 <_DYNAMIC+0x1d0>
  400aa3:	48 85 c0             	test   %rax,%rax
  400aa6:	74 05                	je     400aad <_init+0x15>
  400aa8:	e8 23 01 00 00       	callq  400bd0 <__gmon_start__@plt>
  400aad:	48 83 c4 08          	add    $0x8,%rsp
  400ab1:	c3                   	retq   

Disassembly of section .plt:

0000000000400ac0 <getenv@plt-0x10>:
  400ac0:	ff 35 42 25 20 00    	pushq  0x202542(%rip)        # 603008 <_GLOBAL_OFFSET_TABLE_+0x8>
  400ac6:	ff 25 44 25 20 00    	jmpq   *0x202544(%rip)        # 603010 <_GLOBAL_OFFSET_TABLE_+0x10>
  400acc:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400ad0 <getenv@plt>:
  400ad0:	ff 25 42 25 20 00    	jmpq   *0x202542(%rip)        # 603018 <_GLOBAL_OFFSET_TABLE_+0x18>
  400ad6:	68 00 00 00 00       	pushq  $0x0
  400adb:	e9 e0 ff ff ff       	jmpq   400ac0 <_init+0x28>

0000000000400ae0 <strcpy@plt>:
  400ae0:	ff 25 3a 25 20 00    	jmpq   *0x20253a(%rip)        # 603020 <_GLOBAL_OFFSET_TABLE_+0x20>
  400ae6:	68 01 00 00 00       	pushq  $0x1
  400aeb:	e9 d0 ff ff ff       	jmpq   400ac0 <_init+0x28>

0000000000400af0 <puts@plt>:
  400af0:	ff 25 32 25 20 00    	jmpq   *0x202532(%rip)        # 603028 <_GLOBAL_OFFSET_TABLE_+0x28>
  400af6:	68 02 00 00 00       	pushq  $0x2
  400afb:	e9 c0 ff ff ff       	jmpq   400ac0 <_init+0x28>

0000000000400b00 <fclose@plt>:
  400b00:	ff 25 2a 25 20 00    	jmpq   *0x20252a(%rip)        # 603030 <_GLOBAL_OFFSET_TABLE_+0x30>
  400b06:	68 03 00 00 00       	pushq  $0x3
  400b0b:	e9 b0 ff ff ff       	jmpq   400ac0 <_init+0x28>

0000000000400b10 <system@plt>:
  400b10:	ff 25 22 25 20 00    	jmpq   *0x202522(%rip)        # 603038 <_GLOBAL_OFFSET_TABLE_+0x38>
  400b16:	68 04 00 00 00       	pushq  $0x4
  400b1b:	e9 a0 ff ff ff       	jmpq   400ac0 <_init+0x28>

0000000000400b20 <printf@plt>:
  400b20:	ff 25 1a 25 20 00    	jmpq   *0x20251a(%rip)        # 603040 <_GLOBAL_OFFSET_TABLE_+0x40>
  400b26:	68 05 00 00 00       	pushq  $0x5
  400b2b:	e9 90 ff ff ff       	jmpq   400ac0 <_init+0x28>

0000000000400b30 <rewind@plt>:
  400b30:	ff 25 12 25 20 00    	jmpq   *0x202512(%rip)        # 603048 <_GLOBAL_OFFSET_TABLE_+0x48>
  400b36:	68 06 00 00 00       	pushq  $0x6
  400b3b:	e9 80 ff ff ff       	jmpq   400ac0 <_init+0x28>

0000000000400b40 <dup@plt>:
  400b40:	ff 25 0a 25 20 00    	jmpq   *0x20250a(%rip)        # 603050 <_GLOBAL_OFFSET_TABLE_+0x50>
  400b46:	68 07 00 00 00       	pushq  $0x7
  400b4b:	e9 70 ff ff ff       	jmpq   400ac0 <_init+0x28>

0000000000400b50 <close@plt>:
  400b50:	ff 25 02 25 20 00    	jmpq   *0x202502(%rip)        # 603058 <_GLOBAL_OFFSET_TABLE_+0x58>
  400b56:	68 08 00 00 00       	pushq  $0x8
  400b5b:	e9 60 ff ff ff       	jmpq   400ac0 <_init+0x28>

0000000000400b60 <fputc@plt>:
  400b60:	ff 25 fa 24 20 00    	jmpq   *0x2024fa(%rip)        # 603060 <_GLOBAL_OFFSET_TABLE_+0x60>
  400b66:	68 09 00 00 00       	pushq  $0x9
  400b6b:	e9 50 ff ff ff       	jmpq   400ac0 <_init+0x28>

0000000000400b70 <__libc_start_main@plt>:
  400b70:	ff 25 f2 24 20 00    	jmpq   *0x2024f2(%rip)        # 603068 <_GLOBAL_OFFSET_TABLE_+0x68>
  400b76:	68 0a 00 00 00       	pushq  $0xa
  400b7b:	e9 40 ff ff ff       	jmpq   400ac0 <_init+0x28>

0000000000400b80 <fgets@plt>:
  400b80:	ff 25 ea 24 20 00    	jmpq   *0x2024ea(%rip)        # 603070 <_GLOBAL_OFFSET_TABLE_+0x70>
  400b86:	68 0b 00 00 00       	pushq  $0xb
  400b8b:	e9 30 ff ff ff       	jmpq   400ac0 <_init+0x28>

0000000000400b90 <tmpfile@plt>:
  400b90:	ff 25 e2 24 20 00    	jmpq   *0x2024e2(%rip)        # 603078 <_GLOBAL_OFFSET_TABLE_+0x78>
  400b96:	68 0c 00 00 00       	pushq  $0xc
  400b9b:	e9 20 ff ff ff       	jmpq   400ac0 <_init+0x28>

0000000000400ba0 <signal@plt>:
  400ba0:	ff 25 da 24 20 00    	jmpq   *0x2024da(%rip)        # 603080 <_GLOBAL_OFFSET_TABLE_+0x80>
  400ba6:	68 0d 00 00 00       	pushq  $0xd
  400bab:	e9 10 ff ff ff       	jmpq   400ac0 <_init+0x28>

0000000000400bb0 <gethostbyname@plt>:
  400bb0:	ff 25 d2 24 20 00    	jmpq   *0x2024d2(%rip)        # 603088 <_GLOBAL_OFFSET_TABLE_+0x88>
  400bb6:	68 0e 00 00 00       	pushq  $0xe
  400bbb:	e9 00 ff ff ff       	jmpq   400ac0 <_init+0x28>

0000000000400bc0 <fprintf@plt>:
  400bc0:	ff 25 ca 24 20 00    	jmpq   *0x2024ca(%rip)        # 603090 <_GLOBAL_OFFSET_TABLE_+0x90>
  400bc6:	68 0f 00 00 00       	pushq  $0xf
  400bcb:	e9 f0 fe ff ff       	jmpq   400ac0 <_init+0x28>

0000000000400bd0 <__gmon_start__@plt>:
  400bd0:	ff 25 c2 24 20 00    	jmpq   *0x2024c2(%rip)        # 603098 <_GLOBAL_OFFSET_TABLE_+0x98>
  400bd6:	68 10 00 00 00       	pushq  $0x10
  400bdb:	e9 e0 fe ff ff       	jmpq   400ac0 <_init+0x28>

0000000000400be0 <strtol@plt>:
  400be0:	ff 25 ba 24 20 00    	jmpq   *0x2024ba(%rip)        # 6030a0 <_GLOBAL_OFFSET_TABLE_+0xa0>
  400be6:	68 11 00 00 00       	pushq  $0x11
  400beb:	e9 d0 fe ff ff       	jmpq   400ac0 <_init+0x28>

0000000000400bf0 <fflush@plt>:
  400bf0:	ff 25 b2 24 20 00    	jmpq   *0x2024b2(%rip)        # 6030a8 <_GLOBAL_OFFSET_TABLE_+0xa8>
  400bf6:	68 12 00 00 00       	pushq  $0x12
  400bfb:	e9 c0 fe ff ff       	jmpq   400ac0 <_init+0x28>

0000000000400c00 <__isoc99_sscanf@plt>:
  400c00:	ff 25 aa 24 20 00    	jmpq   *0x2024aa(%rip)        # 6030b0 <_GLOBAL_OFFSET_TABLE_+0xb0>
  400c06:	68 13 00 00 00       	pushq  $0x13
  400c0b:	e9 b0 fe ff ff       	jmpq   400ac0 <_init+0x28>

0000000000400c10 <bcopy@plt>:
  400c10:	ff 25 a2 24 20 00    	jmpq   *0x2024a2(%rip)        # 6030b8 <_GLOBAL_OFFSET_TABLE_+0xb8>
  400c16:	68 14 00 00 00       	pushq  $0x14
  400c1b:	e9 a0 fe ff ff       	jmpq   400ac0 <_init+0x28>

0000000000400c20 <cuserid@plt>:
  400c20:	ff 25 9a 24 20 00    	jmpq   *0x20249a(%rip)        # 6030c0 <_GLOBAL_OFFSET_TABLE_+0xc0>
  400c26:	68 15 00 00 00       	pushq  $0x15
  400c2b:	e9 90 fe ff ff       	jmpq   400ac0 <_init+0x28>

0000000000400c30 <fopen@plt>:
  400c30:	ff 25 92 24 20 00    	jmpq   *0x202492(%rip)        # 6030c8 <_GLOBAL_OFFSET_TABLE_+0xc8>
  400c36:	68 16 00 00 00       	pushq  $0x16
  400c3b:	e9 80 fe ff ff       	jmpq   400ac0 <_init+0x28>

0000000000400c40 <sprintf@plt>:
  400c40:	ff 25 8a 24 20 00    	jmpq   *0x20248a(%rip)        # 6030d0 <_GLOBAL_OFFSET_TABLE_+0xd0>
  400c46:	68 17 00 00 00       	pushq  $0x17
  400c4b:	e9 70 fe ff ff       	jmpq   400ac0 <_init+0x28>

0000000000400c50 <exit@plt>:
  400c50:	ff 25 82 24 20 00    	jmpq   *0x202482(%rip)        # 6030d8 <_GLOBAL_OFFSET_TABLE_+0xd8>
  400c56:	68 18 00 00 00       	pushq  $0x18
  400c5b:	e9 60 fe ff ff       	jmpq   400ac0 <_init+0x28>

0000000000400c60 <connect@plt>:
  400c60:	ff 25 7a 24 20 00    	jmpq   *0x20247a(%rip)        # 6030e0 <_GLOBAL_OFFSET_TABLE_+0xe0>
  400c66:	68 19 00 00 00       	pushq  $0x19
  400c6b:	e9 50 fe ff ff       	jmpq   400ac0 <_init+0x28>

0000000000400c70 <fwrite@plt>:
  400c70:	ff 25 72 24 20 00    	jmpq   *0x202472(%rip)        # 6030e8 <_GLOBAL_OFFSET_TABLE_+0xe8>
  400c76:	68 1a 00 00 00       	pushq  $0x1a
  400c7b:	e9 40 fe ff ff       	jmpq   400ac0 <_init+0x28>

0000000000400c80 <sleep@plt>:
  400c80:	ff 25 6a 24 20 00    	jmpq   *0x20246a(%rip)        # 6030f0 <_GLOBAL_OFFSET_TABLE_+0xf0>
  400c86:	68 1b 00 00 00       	pushq  $0x1b
  400c8b:	e9 30 fe ff ff       	jmpq   400ac0 <_init+0x28>

0000000000400c90 <__ctype_b_loc@plt>:
  400c90:	ff 25 62 24 20 00    	jmpq   *0x202462(%rip)        # 6030f8 <_GLOBAL_OFFSET_TABLE_+0xf8>
  400c96:	68 1c 00 00 00       	pushq  $0x1c
  400c9b:	e9 20 fe ff ff       	jmpq   400ac0 <_init+0x28>

0000000000400ca0 <socket@plt>:
  400ca0:	ff 25 5a 24 20 00    	jmpq   *0x20245a(%rip)        # 603100 <_GLOBAL_OFFSET_TABLE_+0x100>
  400ca6:	68 1d 00 00 00       	pushq  $0x1d
  400cab:	e9 10 fe ff ff       	jmpq   400ac0 <_init+0x28>

Disassembly of section .text:

0000000000400cb0 <_start>:
  400cb0:	31 ed                	xor    %ebp,%ebp
  400cb2:	49 89 d1             	mov    %rdx,%r9
  400cb5:	5e                   	pop    %rsi
  400cb6:	48 89 e2             	mov    %rsp,%rdx
  400cb9:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  400cbd:	50                   	push   %rax
  400cbe:	54                   	push   %rsp
  400cbf:	49 c7 c0 10 19 40 00 	mov    $0x401910,%r8
  400cc6:	48 c7 c1 a0 18 40 00 	mov    $0x4018a0,%rcx
  400ccd:	48 c7 c7 a6 0d 40 00 	mov    $0x400da6,%rdi
  400cd4:	e8 97 fe ff ff       	callq  400b70 <__libc_start_main@plt>
  400cd9:	f4                   	hlt    
  400cda:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000400ce0 <deregister_tm_clones>:
  400ce0:	b8 67 3a 60 00       	mov    $0x603a67,%eax
  400ce5:	55                   	push   %rbp
  400ce6:	48 2d 60 3a 60 00    	sub    $0x603a60,%rax
  400cec:	48 83 f8 0e          	cmp    $0xe,%rax
  400cf0:	48 89 e5             	mov    %rsp,%rbp
  400cf3:	76 1b                	jbe    400d10 <deregister_tm_clones+0x30>
  400cf5:	b8 00 00 00 00       	mov    $0x0,%eax
  400cfa:	48 85 c0             	test   %rax,%rax
  400cfd:	74 11                	je     400d10 <deregister_tm_clones+0x30>
  400cff:	5d                   	pop    %rbp
  400d00:	bf 60 3a 60 00       	mov    $0x603a60,%edi
  400d05:	ff e0                	jmpq   *%rax
  400d07:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  400d0e:	00 00 
  400d10:	5d                   	pop    %rbp
  400d11:	c3                   	retq   
  400d12:	66 66 66 66 66 2e 0f 	data16 data16 data16 data16 nopw %cs:0x0(%rax,%rax,1)
  400d19:	1f 84 00 00 00 00 00 

0000000000400d20 <register_tm_clones>:
  400d20:	be 60 3a 60 00       	mov    $0x603a60,%esi
  400d25:	55                   	push   %rbp
  400d26:	48 81 ee 60 3a 60 00 	sub    $0x603a60,%rsi
  400d2d:	48 c1 fe 03          	sar    $0x3,%rsi
  400d31:	48 89 e5             	mov    %rsp,%rbp
  400d34:	48 89 f0             	mov    %rsi,%rax
  400d37:	48 c1 e8 3f          	shr    $0x3f,%rax
  400d3b:	48 01 c6             	add    %rax,%rsi
  400d3e:	48 d1 fe             	sar    %rsi
  400d41:	74 15                	je     400d58 <register_tm_clones+0x38>
  400d43:	b8 00 00 00 00       	mov    $0x0,%eax
  400d48:	48 85 c0             	test   %rax,%rax
  400d4b:	74 0b                	je     400d58 <register_tm_clones+0x38>
  400d4d:	5d                   	pop    %rbp
  400d4e:	bf 60 3a 60 00       	mov    $0x603a60,%edi
  400d53:	ff e0                	jmpq   *%rax
  400d55:	0f 1f 00             	nopl   (%rax)
  400d58:	5d                   	pop    %rbp
  400d59:	c3                   	retq   
  400d5a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000400d60 <__do_global_dtors_aux>:
  400d60:	80 3d 09 2d 20 00 00 	cmpb   $0x0,0x202d09(%rip)        # 603a70 <completed.6904>
  400d67:	75 11                	jne    400d7a <__do_global_dtors_aux+0x1a>
  400d69:	55                   	push   %rbp
  400d6a:	48 89 e5             	mov    %rsp,%rbp
  400d6d:	e8 6e ff ff ff       	callq  400ce0 <deregister_tm_clones>
  400d72:	5d                   	pop    %rbp
  400d73:	c6 05 f6 2c 20 00 01 	movb   $0x1,0x202cf6(%rip)        # 603a70 <completed.6904>
  400d7a:	f3 c3                	repz retq 
  400d7c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400d80 <frame_dummy>:
  400d80:	bf 20 2e 60 00       	mov    $0x602e20,%edi
  400d85:	48 83 3f 00          	cmpq   $0x0,(%rdi)
  400d89:	75 05                	jne    400d90 <frame_dummy+0x10>
  400d8b:	eb 93                	jmp    400d20 <register_tm_clones>
  400d8d:	0f 1f 00             	nopl   (%rax)
  400d90:	b8 00 00 00 00       	mov    $0x0,%eax
  400d95:	48 85 c0             	test   %rax,%rax
  400d98:	74 f1                	je     400d8b <frame_dummy+0xb>
  400d9a:	55                   	push   %rbp
  400d9b:	48 89 e5             	mov    %rsp,%rbp
  400d9e:	ff d0                	callq  *%rax
  400da0:	5d                   	pop    %rbp
  400da1:	e9 7a ff ff ff       	jmpq   400d20 <register_tm_clones>

0000000000400da6 <main>:
  400da6:	53                   	push   %rbx
  400da7:	83 ff 01             	cmp    $0x1,%edi
  400daa:	75 10                	jne    400dbc <main+0x16>
  400dac:	48 8b 05 b5 2c 20 00 	mov    0x202cb5(%rip),%rax        # 603a68 <stdin@@GLIBC_2.2.5>
  400db3:	48 89 05 be 2c 20 00 	mov    %rax,0x202cbe(%rip)        # 603a78 <infile>
  400dba:	eb 59                	jmp    400e15 <main+0x6f>
  400dbc:	48 89 f3             	mov    %rsi,%rbx
  400dbf:	83 ff 02             	cmp    $0x2,%edi
  400dc2:	75 35                	jne    400df9 <main+0x53>
  400dc4:	48 8b 7e 08          	mov    0x8(%rsi),%rdi
  400dc8:	be 86 1d 40 00       	mov    $0x401d86,%esi
  400dcd:	e8 5e fe ff ff       	callq  400c30 <fopen@plt>
  400dd2:	48 89 05 9f 2c 20 00 	mov    %rax,0x202c9f(%rip)        # 603a78 <infile>
  400dd9:	48 85 c0             	test   %rax,%rax
  400ddc:	75 37                	jne    400e15 <main+0x6f>
  400dde:	48 8b 53 08          	mov    0x8(%rbx),%rdx
  400de2:	48 8b 33             	mov    (%rbx),%rsi
  400de5:	bf 30 19 40 00       	mov    $0x401930,%edi
  400dea:	e8 31 fd ff ff       	callq  400b20 <printf@plt>
  400def:	bf 08 00 00 00       	mov    $0x8,%edi
  400df4:	e8 57 fe ff ff       	callq  400c50 <exit@plt>
  400df9:	48 8b 36             	mov    (%rsi),%rsi
  400dfc:	bf 4d 19 40 00       	mov    $0x40194d,%edi
  400e01:	b8 00 00 00 00       	mov    $0x0,%eax
  400e06:	e8 15 fd ff ff       	callq  400b20 <printf@plt>
  400e0b:	bf 08 00 00 00       	mov    $0x8,%edi
  400e10:	e8 3b fe ff ff       	callq  400c50 <exit@plt>
  400e15:	e8 15 06 00 00       	callq  40142f <initialize_bomb>
  400e1a:	bf 98 19 40 00       	mov    $0x401998,%edi
  400e1f:	e8 cc fc ff ff       	callq  400af0 <puts@plt>
  400e24:	bf d8 19 40 00       	mov    $0x4019d8,%edi
  400e29:	e8 c2 fc ff ff       	callq  400af0 <puts@plt>
  400e2e:	e8 0b 09 00 00       	callq  40173e <read_line>
  400e33:	48 89 c7             	mov    %rax,%rdi
  400e36:	e8 ac 00 00 00       	callq  400ee7 <phase_1>
  400e3b:	e8 e3 09 00 00       	callq  401823 <phase_defused>
  400e40:	bf 08 1a 40 00       	mov    $0x401a08,%edi
  400e45:	e8 a6 fc ff ff       	callq  400af0 <puts@plt>
  400e4a:	e8 ef 08 00 00       	callq  40173e <read_line>
  400e4f:	48 89 c7             	mov    %rax,%rdi
  400e52:	e8 ac 00 00 00       	callq  400f03 <phase_2>
  400e57:	e8 c7 09 00 00       	callq  401823 <phase_defused>
  400e5c:	bf 67 19 40 00       	mov    $0x401967,%edi
  400e61:	e8 8a fc ff ff       	callq  400af0 <puts@plt>
  400e66:	e8 d3 08 00 00       	callq  40173e <read_line>
  400e6b:	48 89 c7             	mov    %rax,%rdi
  400e6e:	e8 d4 00 00 00       	callq  400f47 <phase_3>
  400e73:	e8 ab 09 00 00       	callq  401823 <phase_defused>
  400e78:	bf 85 19 40 00       	mov    $0x401985,%edi
  400e7d:	e8 6e fc ff ff       	callq  400af0 <puts@plt>
  400e82:	e8 b7 08 00 00       	callq  40173e <read_line>
  400e87:	48 89 c7             	mov    %rax,%rdi
  400e8a:	e8 25 02 00 00       	callq  4010b4 <phase_4>
  400e8f:	e8 8f 09 00 00       	callq  401823 <phase_defused>
  400e94:	bf 38 1a 40 00       	mov    $0x401a38,%edi
  400e99:	e8 52 fc ff ff       	callq  400af0 <puts@plt>
  400e9e:	e8 9b 08 00 00       	callq  40173e <read_line>
  400ea3:	48 89 c7             	mov    %rax,%rdi
  400ea6:	e8 4c 02 00 00       	callq  4010f7 <phase_5>
  400eab:	e8 73 09 00 00       	callq  401823 <phase_defused>
  400eb0:	bf 60 1a 40 00       	mov    $0x401a60,%edi
  400eb5:	e8 36 fc ff ff       	callq  400af0 <puts@plt>
  400eba:	bf 98 1a 40 00       	mov    $0x401a98,%edi
  400ebf:	e8 2c fc ff ff       	callq  400af0 <puts@plt>
  400ec4:	bf d8 1a 40 00       	mov    $0x401ad8,%edi
  400ec9:	e8 22 fc ff ff       	callq  400af0 <puts@plt>
  400ece:	e8 6b 08 00 00       	callq  40173e <read_line>
  400ed3:	48 89 c7             	mov    %rax,%rdi
  400ed6:	e8 c5 02 00 00       	callq  4011a0 <phase_6>
  400edb:	e8 43 09 00 00       	callq  401823 <phase_defused>
  400ee0:	b8 00 00 00 00       	mov    $0x0,%eax
  400ee5:	5b                   	pop    %rbx
  400ee6:	c3                   	retq   

0000000000400ee7 <phase_1>:
  400ee7:	48 83 ec 08          	sub    $0x8,%rsp
  400eeb:	be 18 1b 40 00       	mov    $0x401b18,%esi
  400ef0:	e8 0e 04 00 00       	callq  401303 <strings_not_equal>
  400ef5:	85 c0                	test   %eax,%eax
  400ef7:	74 05                	je     400efe <phase_1+0x17>
  400ef9:	e8 df 07 00 00       	callq  4016dd <explode_bomb>
  400efe:	48 83 c4 08          	add    $0x8,%rsp
  400f02:	c3                   	retq   

0000000000400f03 <phase_2>:
  400f03:	55                   	push   %rbp
  400f04:	53                   	push   %rbx
  400f05:	48 83 ec 28          	sub    $0x28,%rsp
  400f09:	48 89 e6             	mov    %rsp,%rsi
  400f0c:	e8 ee 07 00 00       	callq  4016ff <read_six_numbers>
  400f11:	83 3c 24 01          	cmpl   $0x1,(%rsp)
  400f15:	74 05                	je     400f1c <phase_2+0x19>
  400f17:	e8 c1 07 00 00       	callq  4016dd <explode_bomb>
  400f1c:	48 89 e5             	mov    %rsp,%rbp
  400f1f:	bb 01 00 00 00       	mov    $0x1,%ebx
  400f24:	83 c3 01             	add    $0x1,%ebx
  400f27:	89 d8                	mov    %ebx,%eax
  400f29:	0f af 45 00          	imul   0x0(%rbp),%eax
  400f2d:	39 45 04             	cmp    %eax,0x4(%rbp)
  400f30:	74 05                	je     400f37 <phase_2+0x34>
  400f32:	e8 a6 07 00 00       	callq  4016dd <explode_bomb>
  400f37:	48 83 c5 04          	add    $0x4,%rbp
  400f3b:	83 fb 06             	cmp    $0x6,%ebx
  400f3e:	75 e4                	jne    400f24 <phase_2+0x21>
  400f40:	48 83 c4 28          	add    $0x28,%rsp
  400f44:	5b                   	pop    %rbx
  400f45:	5d                   	pop    %rbp
  400f46:	c3                   	retq   

0000000000400f47 <phase_3>:
  400f47:	48 83 ec 18          	sub    $0x18,%rsp
  400f4b:	4c 8d 44 24 08       	lea    0x8(%rsp),%r8
  400f50:	48 8d 4c 24 07       	lea    0x7(%rsp),%rcx
  400f55:	48 8d 54 24 0c       	lea    0xc(%rsp),%rdx
  400f5a:	be 86 1b 40 00       	mov    $0x401b86,%esi
  400f5f:	b8 00 00 00 00       	mov    $0x0,%eax
  400f64:	e8 97 fc ff ff       	callq  400c00 <__isoc99_sscanf@plt>
  400f69:	83 f8 02             	cmp    $0x2,%eax
  400f6c:	7f 05                	jg     400f73 <phase_3+0x2c>
  400f6e:	e8 6a 07 00 00       	callq  4016dd <explode_bomb>
  400f73:	83 7c 24 0c 07       	cmpl   $0x7,0xc(%rsp)
  400f78:	0f 87 f6 00 00 00    	ja     401074 <phase_3+0x12d>
  400f7e:	8b 44 24 0c          	mov    0xc(%rsp),%eax
  400f82:	ff 24 c5 a0 1b 40 00 	jmpq   *0x401ba0(,%rax,8)
  400f89:	b8 61 00 00 00       	mov    $0x61,%eax
  400f8e:	81 7c 24 08 55 01 00 	cmpl   $0x155,0x8(%rsp)
  400f95:	00 
  400f96:	0f 84 e2 00 00 00    	je     40107e <phase_3+0x137>
  400f9c:	e8 3c 07 00 00       	callq  4016dd <explode_bomb>
  400fa1:	b8 61 00 00 00       	mov    $0x61,%eax
  400fa6:	e9 d3 00 00 00       	jmpq   40107e <phase_3+0x137>
  400fab:	b8 66 00 00 00       	mov    $0x66,%eax
  400fb0:	83 7c 24 08 63       	cmpl   $0x63,0x8(%rsp)
  400fb5:	0f 84 c3 00 00 00    	je     40107e <phase_3+0x137>
  400fbb:	e8 1d 07 00 00       	callq  4016dd <explode_bomb>
  400fc0:	b8 66 00 00 00       	mov    $0x66,%eax
  400fc5:	e9 b4 00 00 00       	jmpq   40107e <phase_3+0x137>
  400fca:	b8 76 00 00 00       	mov    $0x76,%eax
  400fcf:	81 7c 24 08 12 02 00 	cmpl   $0x212,0x8(%rsp)
  400fd6:	00 
  400fd7:	0f 84 a1 00 00 00    	je     40107e <phase_3+0x137>
  400fdd:	e8 fb 06 00 00       	callq  4016dd <explode_bomb>
  400fe2:	b8 76 00 00 00       	mov    $0x76,%eax
  400fe7:	e9 92 00 00 00       	jmpq   40107e <phase_3+0x137>
  400fec:	b8 76 00 00 00       	mov    $0x76,%eax
  400ff1:	83 7c 24 08 37       	cmpl   $0x37,0x8(%rsp)
  400ff6:	0f 84 82 00 00 00    	je     40107e <phase_3+0x137>
  400ffc:	e8 dc 06 00 00       	callq  4016dd <explode_bomb>
  401001:	b8 76 00 00 00       	mov    $0x76,%eax
  401006:	eb 76                	jmp    40107e <phase_3+0x137>
  401008:	b8 7a 00 00 00       	mov    $0x7a,%eax
  40100d:	81 7c 24 08 19 03 00 	cmpl   $0x319,0x8(%rsp)
  401014:	00 
  401015:	74 67                	je     40107e <phase_3+0x137>
  401017:	e8 c1 06 00 00       	callq  4016dd <explode_bomb>
  40101c:	b8 7a 00 00 00       	mov    $0x7a,%eax
  401021:	eb 5b                	jmp    40107e <phase_3+0x137>
  401023:	b8 77 00 00 00       	mov    $0x77,%eax
  401028:	81 7c 24 08 94 03 00 	cmpl   $0x394,0x8(%rsp)
  40102f:	00 
  401030:	74 4c                	je     40107e <phase_3+0x137>
  401032:	e8 a6 06 00 00       	callq  4016dd <explode_bomb>
  401037:	b8 77 00 00 00       	mov    $0x77,%eax
  40103c:	eb 40                	jmp    40107e <phase_3+0x137>
  40103e:	b8 74 00 00 00       	mov    $0x74,%eax
  401043:	81 7c 24 08 43 01 00 	cmpl   $0x143,0x8(%rsp)
  40104a:	00 
  40104b:	74 31                	je     40107e <phase_3+0x137>
  40104d:	e8 8b 06 00 00       	callq  4016dd <explode_bomb>
  401052:	b8 74 00 00 00       	mov    $0x74,%eax
  401057:	eb 25                	jmp    40107e <phase_3+0x137>
  401059:	b8 63 00 00 00       	mov    $0x63,%eax
  40105e:	81 7c 24 08 23 02 00 	cmpl   $0x223,0x8(%rsp)
  401065:	00 
  401066:	74 16                	je     40107e <phase_3+0x137>
  401068:	e8 70 06 00 00       	callq  4016dd <explode_bomb>
  40106d:	b8 63 00 00 00       	mov    $0x63,%eax
  401072:	eb 0a                	jmp    40107e <phase_3+0x137>
  401074:	e8 64 06 00 00       	callq  4016dd <explode_bomb>
  401079:	b8 66 00 00 00       	mov    $0x66,%eax
  40107e:	3a 44 24 07          	cmp    0x7(%rsp),%al
  401082:	74 05                	je     401089 <phase_3+0x142>
  401084:	e8 54 06 00 00       	callq  4016dd <explode_bomb>
  401089:	48 83 c4 18          	add    $0x18,%rsp
  40108d:	c3                   	retq   

000000000040108e <func4>:
  40108e:	b8 01 00 00 00       	mov    $0x1,%eax
  401093:	85 ff                	test   %edi,%edi
  401095:	7e 1b                	jle    4010b2 <func4+0x24>
  401097:	48 83 ec 08          	sub    $0x8,%rsp
  40109b:	83 ef 01             	sub    $0x1,%edi
  40109e:	e8 eb ff ff ff       	callq  40108e <func4>
  4010a3:	8d 14 c5 00 00 00 00 	lea    0x0(,%rax,8),%edx
  4010aa:	29 c2                	sub    %eax,%edx
  4010ac:	89 d0                	mov    %edx,%eax
  4010ae:	48 83 c4 08          	add    $0x8,%rsp
  4010b2:	f3 c3                	repz retq 

00000000004010b4 <phase_4>:
  4010b4:	48 83 ec 18          	sub    $0x18,%rsp
  4010b8:	48 8d 54 24 0c       	lea    0xc(%rsp),%rdx
  4010bd:	be 8c 1b 40 00       	mov    $0x401b8c,%esi
  4010c2:	b8 00 00 00 00       	mov    $0x0,%eax
  4010c7:	e8 34 fb ff ff       	callq  400c00 <__isoc99_sscanf@plt>
  4010cc:	83 f8 01             	cmp    $0x1,%eax
  4010cf:	75 07                	jne    4010d8 <phase_4+0x24>
  4010d1:	83 7c 24 0c 00       	cmpl   $0x0,0xc(%rsp)
  4010d6:	7f 05                	jg     4010dd <phase_4+0x29>
  4010d8:	e8 00 06 00 00       	callq  4016dd <explode_bomb>
  4010dd:	8b 7c 24 0c          	mov    0xc(%rsp),%edi
  4010e1:	e8 a8 ff ff ff       	callq  40108e <func4>
  4010e6:	3d a7 41 00 00       	cmp    $0x41a7,%eax
  4010eb:	74 05                	je     4010f2 <phase_4+0x3e>
  4010ed:	e8 eb 05 00 00       	callq  4016dd <explode_bomb>
  4010f2:	48 83 c4 18          	add    $0x18,%rsp
  4010f6:	c3                   	retq   

00000000004010f7 <phase_5>:
  4010f7:	53                   	push   %rbx
  4010f8:	48 89 fb             	mov    %rdi,%rbx
  4010fb:	e8 e5 01 00 00       	callq  4012e5 <string_length>
  401100:	83 f8 06             	cmp    $0x6,%eax
  401103:	74 05                	je     40110a <phase_5+0x13>
  401105:	e8 d3 05 00 00       	callq  4016dd <explode_bomb>
  40110a:	48 89 d8             	mov    %rbx,%rax
  40110d:	48 8d 7b 06          	lea    0x6(%rbx),%rdi
  401111:	b9 00 00 00 00       	mov    $0x0,%ecx
  401116:	0f b6 10             	movzbl (%rax),%edx
  401119:	83 e2 0f             	and    $0xf,%edx
  40111c:	03 0c 95 e0 1b 40 00 	add    0x401be0(,%rdx,4),%ecx
  401123:	48 83 c0 01          	add    $0x1,%rax
  401127:	48 39 f8             	cmp    %rdi,%rax
  40112a:	75 ea                	jne    401116 <phase_5+0x1f>
  40112c:	83 f9 29             	cmp    $0x29,%ecx
  40112f:	74 05                	je     401136 <phase_5+0x3f>
  401131:	e8 a7 05 00 00       	callq  4016dd <explode_bomb>
  401136:	5b                   	pop    %rbx
  401137:	c3                   	retq   

0000000000401138 <fun6>:
  401138:	48 89 f8             	mov    %rdi,%rax
  40113b:	4c 8b 47 08          	mov    0x8(%rdi),%r8
  40113f:	48 c7 47 08 00 00 00 	movq   $0x0,0x8(%rdi)
  401146:	00 
  401147:	48 89 fa             	mov    %rdi,%rdx
  40114a:	4d 85 c0             	test   %r8,%r8
  40114d:	75 38                	jne    401187 <fun6+0x4f>
  40114f:	f3 c3                	repz retq 
  401151:	48 89 d1             	mov    %rdx,%rcx
  401154:	48 8b 51 08          	mov    0x8(%rcx),%rdx
  401158:	48 85 d2             	test   %rdx,%rdx
  40115b:	74 09                	je     401166 <fun6+0x2e>
  40115d:	39 32                	cmp    %esi,(%rdx)
  40115f:	7f f0                	jg     401151 <fun6+0x19>
  401161:	eb 03                	jmp    401166 <fun6+0x2e>
  401163:	48 89 c1             	mov    %rax,%rcx
  401166:	48 39 d1             	cmp    %rdx,%rcx
  401169:	74 06                	je     401171 <fun6+0x39>
  40116b:	4c 89 41 08          	mov    %r8,0x8(%rcx)
  40116f:	eb 03                	jmp    401174 <fun6+0x3c>
  401171:	4c 89 c0             	mov    %r8,%rax
  401174:	49 8b 48 08          	mov    0x8(%r8),%rcx
  401178:	49 89 50 08          	mov    %rdx,0x8(%r8)
  40117c:	48 85 c9             	test   %rcx,%rcx
  40117f:	74 1d                	je     40119e <fun6+0x66>
  401181:	49 89 c8             	mov    %rcx,%r8
  401184:	48 89 c2             	mov    %rax,%rdx
  401187:	48 85 d2             	test   %rdx,%rdx
  40118a:	74 d7                	je     401163 <fun6+0x2b>
  40118c:	41 8b 30             	mov    (%r8),%esi
  40118f:	48 89 c1             	mov    %rax,%rcx
  401192:	39 32                	cmp    %esi,(%rdx)
  401194:	7f be                	jg     401154 <fun6+0x1c>
  401196:	48 89 c2             	mov    %rax,%rdx
  401199:	4c 89 c0             	mov    %r8,%rax
  40119c:	eb d6                	jmp    401174 <fun6+0x3c>
  40119e:	f3 c3                	repz retq 

00000000004011a0 <phase_6>:
  4011a0:	48 83 ec 08          	sub    $0x8,%rsp
  4011a4:	ba 0a 00 00 00       	mov    $0xa,%edx
  4011a9:	be 00 00 00 00       	mov    $0x0,%esi
  4011ae:	e8 2d fa ff ff       	callq  400be0 <strtol@plt>
  4011b3:	89 05 67 21 20 00    	mov    %eax,0x202167(%rip)        # 603320 <node0>
  4011b9:	bf 20 33 60 00       	mov    $0x603320,%edi
  4011be:	e8 75 ff ff ff       	callq  401138 <fun6>
  4011c3:	ba 08 00 00 00       	mov    $0x8,%edx
  4011c8:	48 8b 40 08          	mov    0x8(%rax),%rax
  4011cc:	83 ea 01             	sub    $0x1,%edx
  4011cf:	75 f7                	jne    4011c8 <phase_6+0x28>
  4011d1:	8b 0d 49 21 20 00    	mov    0x202149(%rip),%ecx        # 603320 <node0>
  4011d7:	39 08                	cmp    %ecx,(%rax)
  4011d9:	74 05                	je     4011e0 <phase_6+0x40>
  4011db:	e8 fd 04 00 00       	callq  4016dd <explode_bomb>
  4011e0:	48 83 c4 08          	add    $0x8,%rsp
  4011e4:	c3                   	retq   

00000000004011e5 <fun7>:
  4011e5:	48 83 ec 08          	sub    $0x8,%rsp
  4011e9:	48 85 ff             	test   %rdi,%rdi
  4011ec:	74 2b                	je     401219 <fun7+0x34>
  4011ee:	8b 17                	mov    (%rdi),%edx
  4011f0:	39 f2                	cmp    %esi,%edx
  4011f2:	7e 0d                	jle    401201 <fun7+0x1c>
  4011f4:	48 8b 7f 08          	mov    0x8(%rdi),%rdi
  4011f8:	e8 e8 ff ff ff       	callq  4011e5 <fun7>
  4011fd:	01 c0                	add    %eax,%eax
  4011ff:	eb 1d                	jmp    40121e <fun7+0x39>
  401201:	b8 00 00 00 00       	mov    $0x0,%eax
  401206:	39 f2                	cmp    %esi,%edx
  401208:	74 14                	je     40121e <fun7+0x39>
  40120a:	48 8b 7f 10          	mov    0x10(%rdi),%rdi
  40120e:	e8 d2 ff ff ff       	callq  4011e5 <fun7>
  401213:	8d 44 00 01          	lea    0x1(%rax,%rax,1),%eax
  401217:	eb 05                	jmp    40121e <fun7+0x39>
  401219:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  40121e:	48 83 c4 08          	add    $0x8,%rsp
  401222:	c3                   	retq   

0000000000401223 <secret_phase>:
  401223:	53                   	push   %rbx
  401224:	e8 15 05 00 00       	callq  40173e <read_line>
  401229:	ba 0a 00 00 00       	mov    $0xa,%edx
  40122e:	be 00 00 00 00       	mov    $0x0,%esi
  401233:	48 89 c7             	mov    %rax,%rdi
  401236:	e8 a5 f9 ff ff       	callq  400be0 <strtol@plt>
  40123b:	48 89 c3             	mov    %rax,%rbx
  40123e:	8d 40 ff             	lea    -0x1(%rax),%eax
  401241:	3d e8 03 00 00       	cmp    $0x3e8,%eax
  401246:	76 05                	jbe    40124d <secret_phase+0x2a>
  401248:	e8 90 04 00 00       	callq  4016dd <explode_bomb>
  40124d:	89 de                	mov    %ebx,%esi
  40124f:	bf 40 31 60 00       	mov    $0x603140,%edi
  401254:	e8 8c ff ff ff       	callq  4011e5 <fun7>
  401259:	83 f8 03             	cmp    $0x3,%eax
  40125c:	74 05                	je     401263 <secret_phase+0x40>
  40125e:	e8 7a 04 00 00       	callq  4016dd <explode_bomb>
  401263:	bf 60 1b 40 00       	mov    $0x401b60,%edi
  401268:	e8 83 f8 ff ff       	callq  400af0 <puts@plt>
  40126d:	e8 b1 05 00 00       	callq  401823 <phase_defused>
  401272:	5b                   	pop    %rbx
  401273:	c3                   	retq   

0000000000401274 <sig_handler>:
  401274:	48 83 ec 08          	sub    $0x8,%rsp
  401278:	bf 20 1c 40 00       	mov    $0x401c20,%edi
  40127d:	e8 6e f8 ff ff       	callq  400af0 <puts@plt>
  401282:	bf 03 00 00 00       	mov    $0x3,%edi
  401287:	e8 f4 f9 ff ff       	callq  400c80 <sleep@plt>
  40128c:	bf 18 1d 40 00       	mov    $0x401d18,%edi
  401291:	b8 00 00 00 00       	mov    $0x0,%eax
  401296:	e8 85 f8 ff ff       	callq  400b20 <printf@plt>
  40129b:	48 8b 3d be 27 20 00 	mov    0x2027be(%rip),%rdi        # 603a60 <__TMC_END__>
  4012a2:	e8 49 f9 ff ff       	callq  400bf0 <fflush@plt>
  4012a7:	bf 01 00 00 00       	mov    $0x1,%edi
  4012ac:	e8 cf f9 ff ff       	callq  400c80 <sleep@plt>
  4012b1:	bf 20 1d 40 00       	mov    $0x401d20,%edi
  4012b6:	e8 35 f8 ff ff       	callq  400af0 <puts@plt>
  4012bb:	bf 10 00 00 00       	mov    $0x10,%edi
  4012c0:	e8 8b f9 ff ff       	callq  400c50 <exit@plt>

00000000004012c5 <invalid_phase>:
  4012c5:	48 83 ec 08          	sub    $0x8,%rsp
  4012c9:	48 89 fe             	mov    %rdi,%rsi
  4012cc:	bf 28 1d 40 00       	mov    $0x401d28,%edi
  4012d1:	b8 00 00 00 00       	mov    $0x0,%eax
  4012d6:	e8 45 f8 ff ff       	callq  400b20 <printf@plt>
  4012db:	bf 08 00 00 00       	mov    $0x8,%edi
  4012e0:	e8 6b f9 ff ff       	callq  400c50 <exit@plt>

00000000004012e5 <string_length>:
  4012e5:	80 3f 00             	cmpb   $0x0,(%rdi)
  4012e8:	74 13                	je     4012fd <string_length+0x18>
  4012ea:	b8 00 00 00 00       	mov    $0x0,%eax
  4012ef:	48 83 c7 01          	add    $0x1,%rdi
  4012f3:	83 c0 01             	add    $0x1,%eax
  4012f6:	80 3f 00             	cmpb   $0x0,(%rdi)
  4012f9:	75 f4                	jne    4012ef <string_length+0xa>
  4012fb:	f3 c3                	repz retq 
  4012fd:	b8 00 00 00 00       	mov    $0x0,%eax
  401302:	c3                   	retq   

0000000000401303 <strings_not_equal>:
  401303:	41 54                	push   %r12
  401305:	55                   	push   %rbp
  401306:	53                   	push   %rbx
  401307:	48 89 fb             	mov    %rdi,%rbx
  40130a:	48 89 f5             	mov    %rsi,%rbp
  40130d:	e8 d3 ff ff ff       	callq  4012e5 <string_length>
  401312:	41 89 c4             	mov    %eax,%r12d
  401315:	48 89 ef             	mov    %rbp,%rdi
  401318:	e8 c8 ff ff ff       	callq  4012e5 <string_length>
  40131d:	ba 01 00 00 00       	mov    $0x1,%edx
  401322:	41 39 c4             	cmp    %eax,%r12d
  401325:	75 3c                	jne    401363 <strings_not_equal+0x60>
  401327:	0f b6 03             	movzbl (%rbx),%eax
  40132a:	84 c0                	test   %al,%al
  40132c:	74 22                	je     401350 <strings_not_equal+0x4d>
  40132e:	3a 45 00             	cmp    0x0(%rbp),%al
  401331:	74 07                	je     40133a <strings_not_equal+0x37>
  401333:	eb 22                	jmp    401357 <strings_not_equal+0x54>
  401335:	3a 45 00             	cmp    0x0(%rbp),%al
  401338:	75 24                	jne    40135e <strings_not_equal+0x5b>
  40133a:	48 83 c3 01          	add    $0x1,%rbx
  40133e:	48 83 c5 01          	add    $0x1,%rbp
  401342:	0f b6 03             	movzbl (%rbx),%eax
  401345:	84 c0                	test   %al,%al
  401347:	75 ec                	jne    401335 <strings_not_equal+0x32>
  401349:	ba 00 00 00 00       	mov    $0x0,%edx
  40134e:	eb 13                	jmp    401363 <strings_not_equal+0x60>
  401350:	ba 00 00 00 00       	mov    $0x0,%edx
  401355:	eb 0c                	jmp    401363 <strings_not_equal+0x60>
  401357:	ba 01 00 00 00       	mov    $0x1,%edx
  40135c:	eb 05                	jmp    401363 <strings_not_equal+0x60>
  40135e:	ba 01 00 00 00       	mov    $0x1,%edx
  401363:	89 d0                	mov    %edx,%eax
  401365:	5b                   	pop    %rbx
  401366:	5d                   	pop    %rbp
  401367:	41 5c                	pop    %r12
  401369:	c3                   	retq   

000000000040136a <open_clientfd>:
  40136a:	41 54                	push   %r12
  40136c:	55                   	push   %rbp
  40136d:	53                   	push   %rbx
  40136e:	48 83 ec 10          	sub    $0x10,%rsp
  401372:	49 89 fc             	mov    %rdi,%r12
  401375:	89 f3                	mov    %esi,%ebx
  401377:	ba 00 00 00 00       	mov    $0x0,%edx
  40137c:	be 01 00 00 00       	mov    $0x1,%esi
  401381:	bf 02 00 00 00       	mov    $0x2,%edi
  401386:	e8 15 f9 ff ff       	callq  400ca0 <socket@plt>
  40138b:	85 c0                	test   %eax,%eax
  40138d:	79 14                	jns    4013a3 <open_clientfd+0x39>
  40138f:	bf 39 1d 40 00       	mov    $0x401d39,%edi
  401394:	e8 57 f7 ff ff       	callq  400af0 <puts@plt>
  401399:	bf 08 00 00 00       	mov    $0x8,%edi
  40139e:	e8 ad f8 ff ff       	callq  400c50 <exit@plt>
  4013a3:	89 c5                	mov    %eax,%ebp
  4013a5:	4c 89 e7             	mov    %r12,%rdi
  4013a8:	e8 03 f8 ff ff       	callq  400bb0 <gethostbyname@plt>
  4013ad:	48 85 c0             	test   %rax,%rax
  4013b0:	75 14                	jne    4013c6 <open_clientfd+0x5c>
  4013b2:	bf 47 1d 40 00       	mov    $0x401d47,%edi
  4013b7:	e8 34 f7 ff ff       	callq  400af0 <puts@plt>
  4013bc:	bf 08 00 00 00       	mov    $0x8,%edi
  4013c1:	e8 8a f8 ff ff       	callq  400c50 <exit@plt>
  4013c6:	48 c7 04 24 00 00 00 	movq   $0x0,(%rsp)
  4013cd:	00 
  4013ce:	48 c7 44 24 08 00 00 	movq   $0x0,0x8(%rsp)
  4013d5:	00 00 
  4013d7:	66 c7 04 24 02 00    	movw   $0x2,(%rsp)
  4013dd:	48 63 50 14          	movslq 0x14(%rax),%rdx
  4013e1:	48 8d 74 24 04       	lea    0x4(%rsp),%rsi
  4013e6:	48 8b 40 18          	mov    0x18(%rax),%rax
  4013ea:	48 8b 38             	mov    (%rax),%rdi
  4013ed:	e8 1e f8 ff ff       	callq  400c10 <bcopy@plt>
  4013f2:	89 de                	mov    %ebx,%esi
  4013f4:	66 c1 ce 08          	ror    $0x8,%si
  4013f8:	66 89 74 24 02       	mov    %si,0x2(%rsp)
  4013fd:	ba 10 00 00 00       	mov    $0x10,%edx
  401402:	48 89 e6             	mov    %rsp,%rsi
  401405:	89 ef                	mov    %ebp,%edi
  401407:	e8 54 f8 ff ff       	callq  400c60 <connect@plt>
  40140c:	85 c0                	test   %eax,%eax
  40140e:	79 14                	jns    401424 <open_clientfd+0xba>
  401410:	bf 55 1d 40 00       	mov    $0x401d55,%edi
  401415:	e8 d6 f6 ff ff       	callq  400af0 <puts@plt>
  40141a:	bf 08 00 00 00       	mov    $0x8,%edi
  40141f:	e8 2c f8 ff ff       	callq  400c50 <exit@plt>
  401424:	89 e8                	mov    %ebp,%eax
  401426:	48 83 c4 10          	add    $0x10,%rsp
  40142a:	5b                   	pop    %rbx
  40142b:	5d                   	pop    %rbp
  40142c:	41 5c                	pop    %r12
  40142e:	c3                   	retq   

000000000040142f <initialize_bomb>:
  40142f:	48 83 ec 08          	sub    $0x8,%rsp
  401433:	be 74 12 40 00       	mov    $0x401274,%esi
  401438:	bf 02 00 00 00       	mov    $0x2,%edi
  40143d:	e8 5e f7 ff ff       	callq  400ba0 <signal@plt>
  401442:	48 83 c4 08          	add    $0x8,%rsp
  401446:	c3                   	retq   

0000000000401447 <blank_line>:
  401447:	55                   	push   %rbp
  401448:	53                   	push   %rbx
  401449:	48 83 ec 08          	sub    $0x8,%rsp
  40144d:	48 89 fd             	mov    %rdi,%rbp
  401450:	eb 17                	jmp    401469 <blank_line+0x22>
  401452:	e8 39 f8 ff ff       	callq  400c90 <__ctype_b_loc@plt>
  401457:	48 83 c5 01          	add    $0x1,%rbp
  40145b:	48 0f be db          	movsbq %bl,%rbx
  40145f:	48 8b 00             	mov    (%rax),%rax
  401462:	f6 44 58 01 20       	testb  $0x20,0x1(%rax,%rbx,2)
  401467:	74 0f                	je     401478 <blank_line+0x31>
  401469:	0f b6 5d 00          	movzbl 0x0(%rbp),%ebx
  40146d:	84 db                	test   %bl,%bl
  40146f:	75 e1                	jne    401452 <blank_line+0xb>
  401471:	b8 01 00 00 00       	mov    $0x1,%eax
  401476:	eb 05                	jmp    40147d <blank_line+0x36>
  401478:	b8 00 00 00 00       	mov    $0x0,%eax
  40147d:	48 83 c4 08          	add    $0x8,%rsp
  401481:	5b                   	pop    %rbx
  401482:	5d                   	pop    %rbp
  401483:	c3                   	retq   

0000000000401484 <skip>:
  401484:	53                   	push   %rbx
  401485:	48 63 05 e8 25 20 00 	movslq 0x2025e8(%rip),%rax        # 603a74 <num_input_strings>
  40148c:	48 8d 3c 80          	lea    (%rax,%rax,4),%rdi
  401490:	48 c1 e7 04          	shl    $0x4,%rdi
  401494:	48 81 c7 80 3a 60 00 	add    $0x603a80,%rdi
  40149b:	48 8b 15 d6 25 20 00 	mov    0x2025d6(%rip),%rdx        # 603a78 <infile>
  4014a2:	be 50 00 00 00       	mov    $0x50,%esi
  4014a7:	e8 d4 f6 ff ff       	callq  400b80 <fgets@plt>
  4014ac:	48 89 c3             	mov    %rax,%rbx
  4014af:	48 85 c0             	test   %rax,%rax
  4014b2:	74 0c                	je     4014c0 <skip+0x3c>
  4014b4:	48 89 c7             	mov    %rax,%rdi
  4014b7:	e8 8b ff ff ff       	callq  401447 <blank_line>
  4014bc:	85 c0                	test   %eax,%eax
  4014be:	75 c5                	jne    401485 <skip+0x1>
  4014c0:	48 89 d8             	mov    %rbx,%rax
  4014c3:	5b                   	pop    %rbx
  4014c4:	c3                   	retq   

00000000004014c5 <send_msg>:
  4014c5:	41 54                	push   %r12
  4014c7:	55                   	push   %rbp
  4014c8:	53                   	push   %rbx
  4014c9:	48 83 ec 50          	sub    $0x50,%rsp
  4014cd:	89 fb                	mov    %edi,%ebx
  4014cf:	bf 00 00 00 00       	mov    $0x0,%edi
  4014d4:	e8 67 f6 ff ff       	callq  400b40 <dup@plt>
  4014d9:	83 f8 ff             	cmp    $0xffffffff,%eax
  4014dc:	75 14                	jne    4014f2 <send_msg+0x2d>
  4014de:	bf 74 1d 40 00       	mov    $0x401d74,%edi
  4014e3:	e8 08 f6 ff ff       	callq  400af0 <puts@plt>
  4014e8:	bf 08 00 00 00       	mov    $0x8,%edi
  4014ed:	e8 5e f7 ff ff       	callq  400c50 <exit@plt>
  4014f2:	41 89 c4             	mov    %eax,%r12d
  4014f5:	bf 00 00 00 00       	mov    $0x0,%edi
  4014fa:	e8 51 f6 ff ff       	callq  400b50 <close@plt>
  4014ff:	83 f8 ff             	cmp    $0xffffffff,%eax
  401502:	75 14                	jne    401518 <send_msg+0x53>
  401504:	bf 88 1d 40 00       	mov    $0x401d88,%edi
  401509:	e8 e2 f5 ff ff       	callq  400af0 <puts@plt>
  40150e:	bf 08 00 00 00       	mov    $0x8,%edi
  401513:	e8 38 f7 ff ff       	callq  400c50 <exit@plt>
  401518:	e8 73 f6 ff ff       	callq  400b90 <tmpfile@plt>
  40151d:	48 89 c5             	mov    %rax,%rbp
  401520:	48 85 c0             	test   %rax,%rax
  401523:	75 14                	jne    401539 <send_msg+0x74>
  401525:	bf 9b 1d 40 00       	mov    $0x401d9b,%edi
  40152a:	e8 c1 f5 ff ff       	callq  400af0 <puts@plt>
  40152f:	bf 08 00 00 00       	mov    $0x8,%edi
  401534:	e8 17 f7 ff ff       	callq  400c50 <exit@plt>
  401539:	48 89 c1             	mov    %rax,%rcx
  40153c:	ba 1b 00 00 00       	mov    $0x1b,%edx
  401541:	be 01 00 00 00       	mov    $0x1,%esi
  401546:	bf b0 1d 40 00       	mov    $0x401db0,%edi
  40154b:	e8 20 f7 ff ff       	callq  400c70 <fwrite@plt>
  401550:	48 89 ee             	mov    %rbp,%rsi
  401553:	bf 0a 00 00 00       	mov    $0xa,%edi
  401558:	e8 03 f6 ff ff       	callq  400b60 <fputc@plt>
  40155d:	bf 00 00 00 00       	mov    $0x0,%edi
  401562:	e8 b9 f6 ff ff       	callq  400c20 <cuserid@plt>
  401567:	48 85 c0             	test   %rax,%rax
  40156a:	75 15                	jne    401581 <send_msg+0xbc>
  40156c:	c7 04 24 6e 6f 62 6f 	movl   $0x6f626f6e,(%rsp)
  401573:	66 c7 44 24 04 64 79 	movw   $0x7964,0x4(%rsp)
  40157a:	c6 44 24 06 00       	movb   $0x0,0x6(%rsp)
  40157f:	eb 0b                	jmp    40158c <send_msg+0xc7>
  401581:	48 89 c6             	mov    %rax,%rsi
  401584:	48 89 e7             	mov    %rsp,%rdi
  401587:	e8 54 f5 ff ff       	callq  400ae0 <strcpy@plt>
  40158c:	85 db                	test   %ebx,%ebx
  40158e:	41 b9 6b 1d 40 00    	mov    $0x401d6b,%r9d
  401594:	b8 63 1d 40 00       	mov    $0x401d63,%eax
  401599:	4c 0f 45 c8          	cmovne %rax,%r9
  40159d:	48 83 ec 08          	sub    $0x8,%rsp
  4015a1:	8b 05 cd 24 20 00    	mov    0x2024cd(%rip),%eax        # 603a74 <num_input_strings>
  4015a7:	50                   	push   %rax
  4015a8:	4c 8d 44 24 10       	lea    0x10(%rsp),%r8
  4015ad:	8b 0d 0d 22 20 00    	mov    0x20220d(%rip),%ecx        # 6037c0 <bomb_id>
  4015b3:	ba c0 33 60 00       	mov    $0x6033c0,%edx
  4015b8:	be cc 1d 40 00       	mov    $0x401dcc,%esi
  4015bd:	48 89 ef             	mov    %rbp,%rdi
  4015c0:	b8 00 00 00 00       	mov    $0x0,%eax
  4015c5:	e8 f6 f5 ff ff       	callq  400bc0 <fprintf@plt>
  4015ca:	48 83 c4 10          	add    $0x10,%rsp
  4015ce:	83 3d 9f 24 20 00 00 	cmpl   $0x0,0x20249f(%rip)        # 603a74 <num_input_strings>
  4015d5:	7e 4f                	jle    401626 <send_msg+0x161>
  4015d7:	bb 00 00 00 00       	mov    $0x0,%ebx
  4015dc:	48 63 c3             	movslq %ebx,%rax
  4015df:	48 8d 04 80          	lea    (%rax,%rax,4),%rax
  4015e3:	48 c1 e0 04          	shl    $0x4,%rax
  4015e7:	48 05 80 3a 60 00    	add    $0x603a80,%rax
  4015ed:	83 c3 01             	add    $0x1,%ebx
  4015f0:	48 83 ec 08          	sub    $0x8,%rsp
  4015f4:	50                   	push   %rax
  4015f5:	41 89 d9             	mov    %ebx,%r9d
  4015f8:	4c 8d 44 24 10       	lea    0x10(%rsp),%r8
  4015fd:	8b 0d bd 21 20 00    	mov    0x2021bd(%rip),%ecx        # 6037c0 <bomb_id>
  401603:	ba c0 33 60 00       	mov    $0x6033c0,%edx
  401608:	be e8 1d 40 00       	mov    $0x401de8,%esi
  40160d:	48 89 ef             	mov    %rbp,%rdi
  401610:	b8 00 00 00 00       	mov    $0x0,%eax
  401615:	e8 a6 f5 ff ff       	callq  400bc0 <fprintf@plt>
  40161a:	48 83 c4 10          	add    $0x10,%rsp
  40161e:	39 1d 50 24 20 00    	cmp    %ebx,0x202450(%rip)        # 603a74 <num_input_strings>
  401624:	7f b6                	jg     4015dc <send_msg+0x117>
  401626:	48 89 ef             	mov    %rbp,%rdi
  401629:	e8 02 f5 ff ff       	callq  400b30 <rewind@plt>
  40162e:	41 b8 58 1c 40 00    	mov    $0x401c58,%r8d
  401634:	b9 04 1e 40 00       	mov    $0x401e04,%ecx
  401639:	ba 09 1e 40 00       	mov    $0x401e09,%edx
  40163e:	be 20 1e 40 00       	mov    $0x401e20,%esi
  401643:	bf c0 40 60 00       	mov    $0x6040c0,%edi
  401648:	b8 00 00 00 00       	mov    $0x0,%eax
  40164d:	e8 ee f5 ff ff       	callq  400c40 <sprintf@plt>
  401652:	bf c0 40 60 00       	mov    $0x6040c0,%edi
  401657:	e8 b4 f4 ff ff       	callq  400b10 <system@plt>
  40165c:	85 c0                	test   %eax,%eax
  40165e:	74 14                	je     401674 <send_msg+0x1af>
  401660:	bf 29 1e 40 00       	mov    $0x401e29,%edi
  401665:	e8 86 f4 ff ff       	callq  400af0 <puts@plt>
  40166a:	bf 08 00 00 00       	mov    $0x8,%edi
  40166f:	e8 dc f5 ff ff       	callq  400c50 <exit@plt>
  401674:	48 89 ef             	mov    %rbp,%rdi
  401677:	e8 84 f4 ff ff       	callq  400b00 <fclose@plt>
  40167c:	85 c0                	test   %eax,%eax
  40167e:	74 14                	je     401694 <send_msg+0x1cf>
  401680:	bf 43 1e 40 00       	mov    $0x401e43,%edi
  401685:	e8 66 f4 ff ff       	callq  400af0 <puts@plt>
  40168a:	bf 08 00 00 00       	mov    $0x8,%edi
  40168f:	e8 bc f5 ff ff       	callq  400c50 <exit@plt>
  401694:	44 89 e7             	mov    %r12d,%edi
  401697:	e8 a4 f4 ff ff       	callq  400b40 <dup@plt>
  40169c:	85 c0                	test   %eax,%eax
  40169e:	74 14                	je     4016b4 <send_msg+0x1ef>
  4016a0:	bf 5c 1e 40 00       	mov    $0x401e5c,%edi
  4016a5:	e8 46 f4 ff ff       	callq  400af0 <puts@plt>
  4016aa:	bf 08 00 00 00       	mov    $0x8,%edi
  4016af:	e8 9c f5 ff ff       	callq  400c50 <exit@plt>
  4016b4:	44 89 e7             	mov    %r12d,%edi
  4016b7:	e8 94 f4 ff ff       	callq  400b50 <close@plt>
  4016bc:	85 c0                	test   %eax,%eax
  4016be:	74 14                	je     4016d4 <send_msg+0x20f>
  4016c0:	bf 77 1e 40 00       	mov    $0x401e77,%edi
  4016c5:	e8 26 f4 ff ff       	callq  400af0 <puts@plt>
  4016ca:	bf 08 00 00 00       	mov    $0x8,%edi
  4016cf:	e8 7c f5 ff ff       	callq  400c50 <exit@plt>
  4016d4:	48 83 c4 50          	add    $0x50,%rsp
  4016d8:	5b                   	pop    %rbx
  4016d9:	5d                   	pop    %rbp
  4016da:	41 5c                	pop    %r12
  4016dc:	c3                   	retq   

00000000004016dd <explode_bomb>:
  4016dd:	48 83 ec 08          	sub    $0x8,%rsp
  4016e1:	bf 8e 1e 40 00       	mov    $0x401e8e,%edi
  4016e6:	e8 05 f4 ff ff       	callq  400af0 <puts@plt>
  4016eb:	bf 97 1e 40 00       	mov    $0x401e97,%edi
  4016f0:	e8 fb f3 ff ff       	callq  400af0 <puts@plt>
  4016f5:	bf 08 00 00 00       	mov    $0x8,%edi
  4016fa:	e8 51 f5 ff ff       	callq  400c50 <exit@plt>

00000000004016ff <read_six_numbers>:
  4016ff:	48 83 ec 08          	sub    $0x8,%rsp
  401703:	48 89 f2             	mov    %rsi,%rdx
  401706:	48 8d 4e 04          	lea    0x4(%rsi),%rcx
  40170a:	48 8d 46 14          	lea    0x14(%rsi),%rax
  40170e:	50                   	push   %rax
  40170f:	48 8d 46 10          	lea    0x10(%rsi),%rax
  401713:	50                   	push   %rax
  401714:	4c 8d 4e 0c          	lea    0xc(%rsi),%r9
  401718:	4c 8d 46 08          	lea    0x8(%rsi),%r8
  40171c:	be ae 1e 40 00       	mov    $0x401eae,%esi
  401721:	b8 00 00 00 00       	mov    $0x0,%eax
  401726:	e8 d5 f4 ff ff       	callq  400c00 <__isoc99_sscanf@plt>
  40172b:	48 83 c4 10          	add    $0x10,%rsp
  40172f:	83 f8 05             	cmp    $0x5,%eax
  401732:	7f 05                	jg     401739 <read_six_numbers+0x3a>
  401734:	e8 a4 ff ff ff       	callq  4016dd <explode_bomb>
  401739:	48 83 c4 08          	add    $0x8,%rsp
  40173d:	c3                   	retq   

000000000040173e <read_line>:
  40173e:	48 83 ec 08          	sub    $0x8,%rsp
  401742:	b8 00 00 00 00       	mov    $0x0,%eax
  401747:	e8 38 fd ff ff       	callq  401484 <skip>
  40174c:	48 85 c0             	test   %rax,%rax
  40174f:	75 64                	jne    4017b5 <read_line+0x77>
  401751:	48 8b 05 10 23 20 00 	mov    0x202310(%rip),%rax        # 603a68 <stdin@@GLIBC_2.2.5>
  401758:	48 39 05 19 23 20 00 	cmp    %rax,0x202319(%rip)        # 603a78 <infile>
  40175f:	75 0f                	jne    401770 <read_line+0x32>
  401761:	bf c0 1e 40 00       	mov    $0x401ec0,%edi
  401766:	e8 85 f3 ff ff       	callq  400af0 <puts@plt>
  40176b:	e8 6d ff ff ff       	callq  4016dd <explode_bomb>
  401770:	bf de 1e 40 00       	mov    $0x401ede,%edi
  401775:	e8 56 f3 ff ff       	callq  400ad0 <getenv@plt>
  40177a:	48 85 c0             	test   %rax,%rax
  40177d:	74 0a                	je     401789 <read_line+0x4b>
  40177f:	bf 00 00 00 00       	mov    $0x0,%edi
  401784:	e8 c7 f4 ff ff       	callq  400c50 <exit@plt>
  401789:	48 8b 05 d8 22 20 00 	mov    0x2022d8(%rip),%rax        # 603a68 <stdin@@GLIBC_2.2.5>
  401790:	48 89 05 e1 22 20 00 	mov    %rax,0x2022e1(%rip)        # 603a78 <infile>
  401797:	b8 00 00 00 00       	mov    $0x0,%eax
  40179c:	e8 e3 fc ff ff       	callq  401484 <skip>
  4017a1:	48 85 c0             	test   %rax,%rax
  4017a4:	75 0f                	jne    4017b5 <read_line+0x77>
  4017a6:	bf c0 1e 40 00       	mov    $0x401ec0,%edi
  4017ab:	e8 40 f3 ff ff       	callq  400af0 <puts@plt>
  4017b0:	e8 28 ff ff ff       	callq  4016dd <explode_bomb>
  4017b5:	8b 35 b9 22 20 00    	mov    0x2022b9(%rip),%esi        # 603a74 <num_input_strings>
  4017bb:	48 63 c6             	movslq %esi,%rax
  4017be:	48 8d 14 80          	lea    (%rax,%rax,4),%rdx
  4017c2:	48 c1 e2 04          	shl    $0x4,%rdx
  4017c6:	48 81 c2 80 3a 60 00 	add    $0x603a80,%rdx
  4017cd:	b8 00 00 00 00       	mov    $0x0,%eax
  4017d2:	48 c7 c1 ff ff ff ff 	mov    $0xffffffffffffffff,%rcx
  4017d9:	48 89 d7             	mov    %rdx,%rdi
  4017dc:	f2 ae                	repnz scas %es:(%rdi),%al
  4017de:	48 f7 d1             	not    %rcx
  4017e1:	48 83 e9 01          	sub    $0x1,%rcx
  4017e5:	83 f9 4f             	cmp    $0x4f,%ecx
  4017e8:	75 0f                	jne    4017f9 <read_line+0xbb>
  4017ea:	bf e9 1e 40 00       	mov    $0x401ee9,%edi
  4017ef:	e8 fc f2 ff ff       	callq  400af0 <puts@plt>
  4017f4:	e8 e4 fe ff ff       	callq  4016dd <explode_bomb>
  4017f9:	83 e9 01             	sub    $0x1,%ecx
  4017fc:	48 63 c9             	movslq %ecx,%rcx
  4017ff:	48 63 c6             	movslq %esi,%rax
  401802:	48 8d 04 80          	lea    (%rax,%rax,4),%rax
  401806:	48 c1 e0 04          	shl    $0x4,%rax
  40180a:	c6 84 01 80 3a 60 00 	movb   $0x0,0x603a80(%rcx,%rax,1)
  401811:	00 
  401812:	8d 46 01             	lea    0x1(%rsi),%eax
  401815:	89 05 59 22 20 00    	mov    %eax,0x202259(%rip)        # 603a74 <num_input_strings>
  40181b:	48 89 d0             	mov    %rdx,%rax
  40181e:	48 83 c4 08          	add    $0x8,%rsp
  401822:	c3                   	retq   

0000000000401823 <phase_defused>:
  401823:	83 3d 4a 22 20 00 06 	cmpl   $0x6,0x20224a(%rip)        # 603a74 <num_input_strings>
  40182a:	75 66                	jne    401892 <phase_defused+0x6f>
  40182c:	48 83 ec 68          	sub    $0x68,%rsp
  401830:	48 8d 4c 24 10       	lea    0x10(%rsp),%rcx
  401835:	48 8d 54 24 0c       	lea    0xc(%rsp),%rdx
  40183a:	be 04 1f 40 00       	mov    $0x401f04,%esi
  40183f:	bf 70 3b 60 00       	mov    $0x603b70,%edi
  401844:	b8 00 00 00 00       	mov    $0x0,%eax
  401849:	e8 b2 f3 ff ff       	callq  400c00 <__isoc99_sscanf@plt>
  40184e:	83 f8 02             	cmp    $0x2,%eax
  401851:	75 31                	jne    401884 <phase_defused+0x61>
  401853:	be 0a 1f 40 00       	mov    $0x401f0a,%esi
  401858:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  40185d:	e8 a1 fa ff ff       	callq  401303 <strings_not_equal>
  401862:	85 c0                	test   %eax,%eax
  401864:	75 1e                	jne    401884 <phase_defused+0x61>
  401866:	bf 80 1c 40 00       	mov    $0x401c80,%edi
  40186b:	e8 80 f2 ff ff       	callq  400af0 <puts@plt>
  401870:	bf a8 1c 40 00       	mov    $0x401ca8,%edi
  401875:	e8 76 f2 ff ff       	callq  400af0 <puts@plt>
  40187a:	b8 00 00 00 00       	mov    $0x0,%eax
  40187f:	e8 9f f9 ff ff       	callq  401223 <secret_phase>
  401884:	bf e0 1c 40 00       	mov    $0x401ce0,%edi
  401889:	e8 62 f2 ff ff       	callq  400af0 <puts@plt>
  40188e:	48 83 c4 68          	add    $0x68,%rsp
  401892:	f3 c3                	repz retq 
  401894:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  40189b:	00 00 00 
  40189e:	66 90                	xchg   %ax,%ax

00000000004018a0 <__libc_csu_init>:
  4018a0:	41 57                	push   %r15
  4018a2:	41 89 ff             	mov    %edi,%r15d
  4018a5:	41 56                	push   %r14
  4018a7:	49 89 f6             	mov    %rsi,%r14
  4018aa:	41 55                	push   %r13
  4018ac:	49 89 d5             	mov    %rdx,%r13
  4018af:	41 54                	push   %r12
  4018b1:	4c 8d 25 58 15 20 00 	lea    0x201558(%rip),%r12        # 602e10 <__frame_dummy_init_array_entry>
  4018b8:	55                   	push   %rbp
  4018b9:	48 8d 2d 58 15 20 00 	lea    0x201558(%rip),%rbp        # 602e18 <__init_array_end>
  4018c0:	53                   	push   %rbx
  4018c1:	4c 29 e5             	sub    %r12,%rbp
  4018c4:	31 db                	xor    %ebx,%ebx
  4018c6:	48 c1 fd 03          	sar    $0x3,%rbp
  4018ca:	48 83 ec 08          	sub    $0x8,%rsp
  4018ce:	e8 c5 f1 ff ff       	callq  400a98 <_init>
  4018d3:	48 85 ed             	test   %rbp,%rbp
  4018d6:	74 1e                	je     4018f6 <__libc_csu_init+0x56>
  4018d8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  4018df:	00 
  4018e0:	4c 89 ea             	mov    %r13,%rdx
  4018e3:	4c 89 f6             	mov    %r14,%rsi
  4018e6:	44 89 ff             	mov    %r15d,%edi
  4018e9:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
  4018ed:	48 83 c3 01          	add    $0x1,%rbx
  4018f1:	48 39 eb             	cmp    %rbp,%rbx
  4018f4:	75 ea                	jne    4018e0 <__libc_csu_init+0x40>
  4018f6:	48 83 c4 08          	add    $0x8,%rsp
  4018fa:	5b                   	pop    %rbx
  4018fb:	5d                   	pop    %rbp
  4018fc:	41 5c                	pop    %r12
  4018fe:	41 5d                	pop    %r13
  401900:	41 5e                	pop    %r14
  401902:	41 5f                	pop    %r15
  401904:	c3                   	retq   
  401905:	90                   	nop
  401906:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  40190d:	00 00 00 

0000000000401910 <__libc_csu_fini>:
  401910:	f3 c3                	repz retq 
  401912:	66 90                	xchg   %ax,%ax

Disassembly of section .fini:

0000000000401914 <_fini>:
  401914:	48 83 ec 08          	sub    $0x8,%rsp
  401918:	48 83 c4 08          	add    $0x8,%rsp
  40191c:	c3                   	retq   
