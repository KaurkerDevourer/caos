
prog:     file format elf64-x86-64


Disassembly of section .interp:

0000000000000318 <.interp>:
 318:	2f                   	(bad)  
 319:	6c                   	insb   (%dx),%es:(%rdi)
 31a:	69 62 36 34 2f 6c 64 	imul   $0x646c2f34,0x36(%rdx),%esp
 321:	2d 6c 69 6e 75       	sub    $0x756e696c,%eax
 326:	78 2d                	js     355 <__abi_tag-0x27>
 328:	78 38                	js     362 <__abi_tag-0x1a>
 32a:	36 2d 36 34 2e 73    	ss sub $0x732e3436,%eax
 330:	6f                   	outsl  %ds:(%rsi),(%dx)
 331:	2e 32 00             	cs xor (%rax),%al

Disassembly of section .note.gnu.property:

0000000000000338 <.note.gnu.property>:
 338:	04 00                	add    $0x0,%al
 33a:	00 00                	add    %al,(%rax)
 33c:	10 00                	adc    %al,(%rax)
 33e:	00 00                	add    %al,(%rax)
 340:	05 00 00 00 47       	add    $0x47000000,%eax
 345:	4e 55                	rex.WRX push %rbp
 347:	00 02                	add    %al,(%rdx)
 349:	80 00 c0             	addb   $0xc0,(%rax)
 34c:	04 00                	add    $0x0,%al
 34e:	00 00                	add    %al,(%rax)
 350:	01 00                	add    %eax,(%rax)
 352:	00 00                	add    %al,(%rax)
 354:	00 00                	add    %al,(%rax)
	...

Disassembly of section .note.gnu.build-id:

0000000000000358 <.note.gnu.build-id>:
 358:	04 00                	add    $0x0,%al
 35a:	00 00                	add    %al,(%rax)
 35c:	14 00                	adc    $0x0,%al
 35e:	00 00                	add    %al,(%rax)
 360:	03 00                	add    (%rax),%eax
 362:	00 00                	add    %al,(%rax)
 364:	47                   	rex.RXB
 365:	4e 55                	rex.WRX push %rbp
 367:	00 03                	add    %al,(%rbx)
 369:	4c 07                	rex.WR (bad) 
 36b:	75 d2                	jne    33f <__abi_tag-0x3d>
 36d:	24 9e                	and    $0x9e,%al
 36f:	fc                   	cld    
 370:	43 f7 a2 8b ef ac f5 	rex.XB mull -0xa531075(%r10)
 377:	2d d8 d9 74 27       	sub    $0x2774d9d8,%eax

Disassembly of section .note.ABI-tag:

000000000000037c <__abi_tag>:
 37c:	04 00                	add    $0x0,%al
 37e:	00 00                	add    %al,(%rax)
 380:	10 00                	adc    %al,(%rax)
 382:	00 00                	add    %al,(%rax)
 384:	01 00                	add    %eax,(%rax)
 386:	00 00                	add    %al,(%rax)
 388:	47                   	rex.RXB
 389:	4e 55                	rex.WRX push %rbp
 38b:	00 00                	add    %al,(%rax)
 38d:	00 00                	add    %al,(%rax)
 38f:	00 03                	add    %al,(%rbx)
 391:	00 00                	add    %al,(%rax)
 393:	00 02                	add    %al,(%rdx)
 395:	00 00                	add    %al,(%rax)
 397:	00 00                	add    %al,(%rax)
 399:	00 00                	add    %al,(%rax)
	...

Disassembly of section .gnu.hash:

00000000000003a0 <.gnu.hash>:
 3a0:	02 00                	add    (%rax),%al
 3a2:	00 00                	add    %al,(%rax)
 3a4:	06                   	(bad)  
 3a5:	00 00                	add    %al,(%rax)
 3a7:	00 01                	add    %al,(%rcx)
 3a9:	00 00                	add    %al,(%rax)
 3ab:	00 06                	add    %al,(%rsi)
 3ad:	00 00                	add    %al,(%rax)
 3af:	00 00                	add    %al,(%rax)
 3b1:	00 81 00 00 00 00    	add    %al,0x0(%rcx)
 3b7:	00 06                	add    %al,(%rsi)
 3b9:	00 00                	add    %al,(%rax)
 3bb:	00 00                	add    %al,(%rax)
 3bd:	00 00                	add    %al,(%rax)
 3bf:	00 d1                	add    %dl,%cl
 3c1:	65 ce                	gs (bad) 
 3c3:	6d                   	insl   (%dx),%es:(%rdi)

Disassembly of section .dynsym:

00000000000003c8 <.dynsym>:
	...
 3e0:	10 00                	adc    %al,(%rax)
 3e2:	00 00                	add    %al,(%rax)
 3e4:	12 00                	adc    (%rax),%al
	...
 3f6:	00 00                	add    %al,(%rax)
 3f8:	4a 00 00             	rex.WX add %al,(%rax)
 3fb:	00 20                	add    %ah,(%rax)
	...
 40d:	00 00                	add    %al,(%rax)
 40f:	00 22                	add    %ah,(%rdx)
 411:	00 00                	add    %al,(%rax)
 413:	00 12                	add    %dl,(%rdx)
	...
 425:	00 00                	add    %al,(%rax)
 427:	00 66 00             	add    %ah,0x0(%rsi)
 42a:	00 00                	add    %al,(%rax)
 42c:	20 00                	and    %al,(%rax)
	...
 43e:	00 00                	add    %al,(%rax)
 440:	75 00                	jne    442 <__abi_tag+0xc6>
 442:	00 00                	add    %al,(%rax)
 444:	20 00                	and    %al,(%rax)
	...
 456:	00 00                	add    %al,(%rax)
 458:	01 00                	add    %eax,(%rax)
 45a:	00 00                	add    %al,(%rax)
 45c:	22 00                	and    (%rax),%al
	...

Disassembly of section .dynstr:

0000000000000470 <.dynstr>:
 470:	00 5f 5f             	add    %bl,0x5f(%rdi)
 473:	63 78 61             	movsxd 0x61(%rax),%edi
 476:	5f                   	pop    %rdi
 477:	66 69 6e 61 6c 69    	imul   $0x696c,0x61(%rsi),%bp
 47d:	7a 65                	jp     4e4 <__abi_tag+0x168>
 47f:	00 5f 5f             	add    %bl,0x5f(%rdi)
 482:	6c                   	insb   (%dx),%es:(%rdi)
 483:	69 62 63 5f 73 74 61 	imul   $0x6174735f,0x63(%rdx),%esp
 48a:	72 74                	jb     500 <__abi_tag+0x184>
 48c:	5f                   	pop    %rdi
 48d:	6d                   	insl   (%dx),%es:(%rdi)
 48e:	61                   	(bad)  
 48f:	69 6e 00 70 72 69 6e 	imul   $0x6e697270,0x0(%rsi),%ebp
 496:	74 66                	je     4fe <__abi_tag+0x182>
 498:	00 6c 69 62          	add    %ch,0x62(%rcx,%rbp,2)
 49c:	63 2e                	movsxd (%rsi),%ebp
 49e:	73 6f                	jae    50f <__abi_tag+0x193>
 4a0:	2e 36 00 47 4c       	cs ss add %al,0x4c(%rdi)
 4a5:	49                   	rex.WB
 4a6:	42                   	rex.X
 4a7:	43 5f                	rex.XB pop %r15
 4a9:	32 2e                	xor    (%rsi),%ch
 4ab:	32 2e                	xor    (%rsi),%ch
 4ad:	35 00 47 4c 49       	xor    $0x494c4700,%eax
 4b2:	42                   	rex.X
 4b3:	43 5f                	rex.XB pop %r15
 4b5:	32 2e                	xor    (%rsi),%ch
 4b7:	33 34 00             	xor    (%rax,%rax,1),%esi
 4ba:	5f                   	pop    %rdi
 4bb:	49 54                	rex.WB push %r12
 4bd:	4d 5f                	rex.WRB pop %r15
 4bf:	64 65 72 65          	fs gs jb 528 <__abi_tag+0x1ac>
 4c3:	67 69 73 74 65 72 54 	imul   $0x4d547265,0x74(%ebx),%esi
 4ca:	4d 
 4cb:	43 6c                	rex.XB insb (%dx),%es:(%rdi)
 4cd:	6f                   	outsl  %ds:(%rsi),(%dx)
 4ce:	6e                   	outsb  %ds:(%rsi),(%dx)
 4cf:	65 54                	gs push %rsp
 4d1:	61                   	(bad)  
 4d2:	62                   	(bad)  
 4d3:	6c                   	insb   (%dx),%es:(%rdi)
 4d4:	65 00 5f 5f          	add    %bl,%gs:0x5f(%rdi)
 4d8:	67 6d                	insl   (%dx),%es:(%edi)
 4da:	6f                   	outsl  %ds:(%rsi),(%dx)
 4db:	6e                   	outsb  %ds:(%rsi),(%dx)
 4dc:	5f                   	pop    %rdi
 4dd:	73 74                	jae    553 <__abi_tag+0x1d7>
 4df:	61                   	(bad)  
 4e0:	72 74                	jb     556 <__abi_tag+0x1da>
 4e2:	5f                   	pop    %rdi
 4e3:	5f                   	pop    %rdi
 4e4:	00 5f 49             	add    %bl,0x49(%rdi)
 4e7:	54                   	push   %rsp
 4e8:	4d 5f                	rex.WRB pop %r15
 4ea:	72 65                	jb     551 <__abi_tag+0x1d5>
 4ec:	67 69 73 74 65 72 54 	imul   $0x4d547265,0x74(%ebx),%esi
 4f3:	4d 
 4f4:	43 6c                	rex.XB insb (%dx),%es:(%rdi)
 4f6:	6f                   	outsl  %ds:(%rsi),(%dx)
 4f7:	6e                   	outsb  %ds:(%rsi),(%dx)
 4f8:	65 54                	gs push %rsp
 4fa:	61                   	(bad)  
 4fb:	62                   	.byte 0x62
 4fc:	6c                   	insb   (%dx),%es:(%rdi)
 4fd:	65                   	gs
	...

Disassembly of section .gnu.version:

0000000000000500 <.gnu.version>:
 500:	00 00                	add    %al,(%rax)
 502:	02 00                	add    (%rax),%al
 504:	01 00                	add    %eax,(%rax)
 506:	03 00                	add    (%rax),%eax
 508:	01 00                	add    %eax,(%rax)
 50a:	01 00                	add    %eax,(%rax)
 50c:	03 00                	add    (%rax),%eax

Disassembly of section .gnu.version_r:

0000000000000510 <.gnu.version_r>:
 510:	01 00                	add    %eax,(%rax)
 512:	02 00                	add    (%rax),%al
 514:	29 00                	sub    %eax,(%rax)
 516:	00 00                	add    %al,(%rax)
 518:	10 00                	adc    %al,(%rax)
 51a:	00 00                	add    %al,(%rax)
 51c:	00 00                	add    %al,(%rax)
 51e:	00 00                	add    %al,(%rax)
 520:	75 1a                	jne    53c <__abi_tag+0x1c0>
 522:	69 09 00 00 03 00    	imul   $0x30000,(%rcx),%ecx
 528:	33 00                	xor    (%rax),%eax
 52a:	00 00                	add    %al,(%rax)
 52c:	10 00                	adc    %al,(%rax)
 52e:	00 00                	add    %al,(%rax)
 530:	b4 91                	mov    $0x91,%ah
 532:	96                   	xchg   %eax,%esi
 533:	06                   	(bad)  
 534:	00 00                	add    %al,(%rax)
 536:	02 00                	add    (%rax),%al
 538:	3f                   	(bad)  
 539:	00 00                	add    %al,(%rax)
 53b:	00 00                	add    %al,(%rax)
 53d:	00 00                	add    %al,(%rax)
	...

Disassembly of section .rela.dyn:

0000000000000540 <.rela.dyn>:
 540:	e8 3d 00 00 00       	call   582 <__abi_tag+0x206>
 545:	00 00                	add    %al,(%rax)
 547:	00 08                	add    %cl,(%rax)
 549:	00 00                	add    %al,(%rax)
 54b:	00 00                	add    %al,(%rax)
 54d:	00 00                	add    %al,(%rax)
 54f:	00 30                	add    %dh,(%rax)
 551:	11 00                	adc    %eax,(%rax)
 553:	00 00                	add    %al,(%rax)
 555:	00 00                	add    %al,(%rax)
 557:	00 f0                	add    %dh,%al
 559:	3d 00 00 00 00       	cmp    $0x0,%eax
 55e:	00 00                	add    %al,(%rax)
 560:	08 00                	or     %al,(%rax)
 562:	00 00                	add    %al,(%rax)
 564:	00 00                	add    %al,(%rax)
 566:	00 00                	add    %al,(%rax)
 568:	f0 10 00             	lock adc %al,(%rax)
 56b:	00 00                	add    %al,(%rax)
 56d:	00 00                	add    %al,(%rax)
 56f:	00 28                	add    %ch,(%rax)
 571:	40 00 00             	rex add %al,(%rax)
 574:	00 00                	add    %al,(%rax)
 576:	00 00                	add    %al,(%rax)
 578:	08 00                	or     %al,(%rax)
 57a:	00 00                	add    %al,(%rax)
 57c:	00 00                	add    %al,(%rax)
 57e:	00 00                	add    %al,(%rax)
 580:	28 40 00             	sub    %al,0x0(%rax)
 583:	00 00                	add    %al,(%rax)
 585:	00 00                	add    %al,(%rax)
 587:	00 d8                	add    %bl,%al
 589:	3f                   	(bad)  
 58a:	00 00                	add    %al,(%rax)
 58c:	00 00                	add    %al,(%rax)
 58e:	00 00                	add    %al,(%rax)
 590:	06                   	(bad)  
 591:	00 00                	add    %al,(%rax)
 593:	00 01                	add    %al,(%rcx)
	...
 59d:	00 00                	add    %al,(%rax)
 59f:	00 e0                	add    %ah,%al
 5a1:	3f                   	(bad)  
 5a2:	00 00                	add    %al,(%rax)
 5a4:	00 00                	add    %al,(%rax)
 5a6:	00 00                	add    %al,(%rax)
 5a8:	06                   	(bad)  
 5a9:	00 00                	add    %al,(%rax)
 5ab:	00 02                	add    %al,(%rdx)
	...
 5b5:	00 00                	add    %al,(%rax)
 5b7:	00 e8                	add    %ch,%al
 5b9:	3f                   	(bad)  
 5ba:	00 00                	add    %al,(%rax)
 5bc:	00 00                	add    %al,(%rax)
 5be:	00 00                	add    %al,(%rax)
 5c0:	06                   	(bad)  
 5c1:	00 00                	add    %al,(%rax)
 5c3:	00 04 00             	add    %al,(%rax,%rax,1)
	...
 5ce:	00 00                	add    %al,(%rax)
 5d0:	f0 3f                	lock (bad) 
 5d2:	00 00                	add    %al,(%rax)
 5d4:	00 00                	add    %al,(%rax)
 5d6:	00 00                	add    %al,(%rax)
 5d8:	06                   	(bad)  
 5d9:	00 00                	add    %al,(%rax)
 5db:	00 05 00 00 00 00    	add    %al,0x0(%rip)        # 5e1 <__abi_tag+0x265>
 5e1:	00 00                	add    %al,(%rax)
 5e3:	00 00                	add    %al,(%rax)
 5e5:	00 00                	add    %al,(%rax)
 5e7:	00 f8                	add    %bh,%al
 5e9:	3f                   	(bad)  
 5ea:	00 00                	add    %al,(%rax)
 5ec:	00 00                	add    %al,(%rax)
 5ee:	00 00                	add    %al,(%rax)
 5f0:	06                   	(bad)  
 5f1:	00 00                	add    %al,(%rax)
 5f3:	00 06                	add    %al,(%rsi)
	...

Disassembly of section .rela.plt:

0000000000000600 <.rela.plt>:
 600:	18 40 00             	sbb    %al,0x0(%rax)
 603:	00 00                	add    %al,(%rax)
 605:	00 00                	add    %al,(%rax)
 607:	00 07                	add    %al,(%rdi)
 609:	00 00                	add    %al,(%rax)
 60b:	00 03                	add    %al,(%rbx)
	...

Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64 
    1004:	48 83 ec 08          	sub    $0x8,%rsp
    1008:	48 8b 05 d9 2f 00 00 	mov    0x2fd9(%rip),%rax        # 3fe8 <__gmon_start__@Base>
    100f:	48 85 c0             	test   %rax,%rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	call   *%rax
    1016:	48 83 c4 08          	add    $0x8,%rsp
    101a:	c3                   	ret    

Disassembly of section .plt:

0000000000001020 <printf@plt-0x10>:
    1020:	ff 35 e2 2f 00 00    	push   0x2fe2(%rip)        # 4008 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	ff 25 e4 2f 00 00    	jmp    *0x2fe4(%rip)        # 4010 <_GLOBAL_OFFSET_TABLE_+0x10>
    102c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000001030 <printf@plt>:
    1030:	ff 25 e2 2f 00 00    	jmp    *0x2fe2(%rip)        # 4018 <printf@GLIBC_2.2.5>
    1036:	68 00 00 00 00       	push   $0x0
    103b:	e9 e0 ff ff ff       	jmp    1020 <_init+0x20>

Disassembly of section .plt.got:

0000000000001040 <__cxa_finalize@plt>:
    1040:	ff 25 b2 2f 00 00    	jmp    *0x2fb2(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    1046:	66 90                	xchg   %ax,%ax

Disassembly of section .text:

0000000000001050 <_start>:
    1050:	f3 0f 1e fa          	endbr64 
    1054:	31 ed                	xor    %ebp,%ebp
    1056:	49 89 d1             	mov    %rdx,%r9
    1059:	5e                   	pop    %rsi
    105a:	48 89 e2             	mov    %rsp,%rdx
    105d:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    1061:	50                   	push   %rax
    1062:	54                   	push   %rsp
    1063:	45 31 c0             	xor    %r8d,%r8d
    1066:	31 c9                	xor    %ecx,%ecx
    1068:	48 8d 3d f1 00 00 00 	lea    0xf1(%rip),%rdi        # 1160 <main>
    106f:	ff 15 63 2f 00 00    	call   *0x2f63(%rip)        # 3fd8 <__libc_start_main@GLIBC_2.34>
    1075:	f4                   	hlt    
    1076:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
    107d:	00 00 00 

0000000000001080 <deregister_tm_clones>:
    1080:	48 8d 3d a9 2f 00 00 	lea    0x2fa9(%rip),%rdi        # 4030 <__TMC_END__>
    1087:	48 8d 05 a2 2f 00 00 	lea    0x2fa2(%rip),%rax        # 4030 <__TMC_END__>
    108e:	48 39 f8             	cmp    %rdi,%rax
    1091:	74 15                	je     10a8 <deregister_tm_clones+0x28>
    1093:	48 8b 05 46 2f 00 00 	mov    0x2f46(%rip),%rax        # 3fe0 <_ITM_deregisterTMCloneTable@Base>
    109a:	48 85 c0             	test   %rax,%rax
    109d:	74 09                	je     10a8 <deregister_tm_clones+0x28>
    109f:	ff e0                	jmp    *%rax
    10a1:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    10a8:	c3                   	ret    
    10a9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000010b0 <register_tm_clones>:
    10b0:	48 8d 3d 79 2f 00 00 	lea    0x2f79(%rip),%rdi        # 4030 <__TMC_END__>
    10b7:	48 8d 35 72 2f 00 00 	lea    0x2f72(%rip),%rsi        # 4030 <__TMC_END__>
    10be:	48 29 fe             	sub    %rdi,%rsi
    10c1:	48 89 f0             	mov    %rsi,%rax
    10c4:	48 c1 ee 3f          	shr    $0x3f,%rsi
    10c8:	48 c1 f8 03          	sar    $0x3,%rax
    10cc:	48 01 c6             	add    %rax,%rsi
    10cf:	48 d1 fe             	sar    %rsi
    10d2:	74 14                	je     10e8 <register_tm_clones+0x38>
    10d4:	48 8b 05 15 2f 00 00 	mov    0x2f15(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable@Base>
    10db:	48 85 c0             	test   %rax,%rax
    10de:	74 08                	je     10e8 <register_tm_clones+0x38>
    10e0:	ff e0                	jmp    *%rax
    10e2:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    10e8:	c3                   	ret    
    10e9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000010f0 <__do_global_dtors_aux>:
    10f0:	f3 0f 1e fa          	endbr64 
    10f4:	80 3d 35 2f 00 00 00 	cmpb   $0x0,0x2f35(%rip)        # 4030 <__TMC_END__>
    10fb:	75 2b                	jne    1128 <__do_global_dtors_aux+0x38>
    10fd:	55                   	push   %rbp
    10fe:	48 83 3d f2 2e 00 00 	cmpq   $0x0,0x2ef2(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    1105:	00 
    1106:	48 89 e5             	mov    %rsp,%rbp
    1109:	74 0c                	je     1117 <__do_global_dtors_aux+0x27>
    110b:	48 8b 3d 16 2f 00 00 	mov    0x2f16(%rip),%rdi        # 4028 <__dso_handle>
    1112:	e8 29 ff ff ff       	call   1040 <__cxa_finalize@plt>
    1117:	e8 64 ff ff ff       	call   1080 <deregister_tm_clones>
    111c:	c6 05 0d 2f 00 00 01 	movb   $0x1,0x2f0d(%rip)        # 4030 <__TMC_END__>
    1123:	5d                   	pop    %rbp
    1124:	c3                   	ret    
    1125:	0f 1f 00             	nopl   (%rax)
    1128:	c3                   	ret    
    1129:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001130 <frame_dummy>:
    1130:	f3 0f 1e fa          	endbr64 
    1134:	e9 77 ff ff ff       	jmp    10b0 <register_tm_clones>
    1139:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001140 <add>:
    1140:	8d 04 37             	lea    (%rdi,%rsi,1),%eax
    1143:	c3                   	ret    
    1144:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
    114b:	00 00 00 
    114e:	66 90                	xchg   %ax,%ax

0000000000001150 <_Z3addii>:
    1150:	8d 04 37             	lea    (%rdi,%rsi,1),%eax
    1153:	c3                   	ret    
    1154:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
    115b:	00 00 00 
    115e:	66 90                	xchg   %ax,%ax

0000000000001160 <main>:
    1160:	50                   	push   %rax
    1161:	48 8d 3d 9c 0e 00 00 	lea    0xe9c(%rip),%rdi        # 2004 <_IO_stdin_used+0x4>
    1168:	be 05 00 00 00       	mov    $0x5,%esi
    116d:	31 c0                	xor    %eax,%eax
    116f:	e8 bc fe ff ff       	call   1030 <printf@plt>
    1174:	31 c0                	xor    %eax,%eax
    1176:	59                   	pop    %rcx
    1177:	c3                   	ret    

Disassembly of section .fini:

0000000000001178 <_fini>:
    1178:	f3 0f 1e fa          	endbr64 
    117c:	48 83 ec 08          	sub    $0x8,%rsp
    1180:	48 83 c4 08          	add    $0x8,%rsp
    1184:	c3                   	ret    

Disassembly of section .rodata:

0000000000002000 <_IO_stdin_used>:
    2000:	01 00                	add    %eax,(%rax)
    2002:	02 00                	add    (%rax),%al
    2004:	32 20                	xor    (%rax),%ah
    2006:	2b 20                	sub    (%rax),%esp
    2008:	33 20                	xor    (%rax),%esp
    200a:	3d 20 25 64 0a       	cmp    $0xa642520,%eax
	...

Disassembly of section .eh_frame_hdr:

0000000000002010 <__GNU_EH_FRAME_HDR>:
    2010:	01 1b                	add    %ebx,(%rbx)
    2012:	03 3b                	add    (%rbx),%edi
    2014:	3c 00                	cmp    $0x0,%al
    2016:	00 00                	add    %al,(%rax)
    2018:	06                   	(bad)  
    2019:	00 00                	add    %al,(%rax)
    201b:	00 10                	add    %dl,(%rax)
    201d:	f0 ff                	lock (bad) 
    201f:	ff 70 00             	push   0x0(%rax)
    2022:	00 00                	add    %al,(%rax)
    2024:	30 f0                	xor    %dh,%al
    2026:	ff                   	(bad)  
    2027:	ff 98 00 00 00 40    	lcall  *0x40000000(%rax)
    202d:	f0 ff                	lock (bad) 
    202f:	ff 58 00             	lcall  *0x0(%rax)
    2032:	00 00                	add    %al,(%rax)
    2034:	30 f1                	xor    %dh,%cl
    2036:	ff                   	(bad)  
    2037:	ff b0 00 00 00 40    	push   0x40000000(%rax)
    203d:	f1                   	int1   
    203e:	ff                   	(bad)  
    203f:	ff c8                	dec    %eax
    2041:	00 00                	add    %al,(%rax)
    2043:	00 50 f1             	add    %dl,-0xf(%rax)
    2046:	ff                   	(bad)  
    2047:	ff                   	(bad)  
    2048:	dc 00                	faddl  (%rax)
	...

Disassembly of section .eh_frame:

0000000000002050 <__FRAME_END__-0xb4>:
    2050:	14 00                	adc    $0x0,%al
    2052:	00 00                	add    %al,(%rax)
    2054:	00 00                	add    %al,(%rax)
    2056:	00 00                	add    %al,(%rax)
    2058:	01 7a 52             	add    %edi,0x52(%rdx)
    205b:	00 01                	add    %al,(%rcx)
    205d:	78 10                	js     206f <__GNU_EH_FRAME_HDR+0x5f>
    205f:	01 1b                	add    %ebx,(%rbx)
    2061:	0c 07                	or     $0x7,%al
    2063:	08 90 01 00 00 14    	or     %dl,0x14000001(%rax)
    2069:	00 00                	add    %al,(%rax)
    206b:	00 1c 00             	add    %bl,(%rax,%rax,1)
    206e:	00 00                	add    %al,(%rax)
    2070:	e0 ef                	loopne 2061 <__GNU_EH_FRAME_HDR+0x51>
    2072:	ff                   	(bad)  
    2073:	ff 26                	jmp    *(%rsi)
    2075:	00 00                	add    %al,(%rax)
    2077:	00 00                	add    %al,(%rax)
    2079:	44 07                	rex.R (bad) 
    207b:	10 00                	adc    %al,(%rax)
    207d:	00 00                	add    %al,(%rax)
    207f:	00 24 00             	add    %ah,(%rax,%rax,1)
    2082:	00 00                	add    %al,(%rax)
    2084:	34 00                	xor    $0x0,%al
    2086:	00 00                	add    %al,(%rax)
    2088:	98                   	cwtl   
    2089:	ef                   	out    %eax,(%dx)
    208a:	ff                   	(bad)  
    208b:	ff 20                	jmp    *(%rax)
    208d:	00 00                	add    %al,(%rax)
    208f:	00 00                	add    %al,(%rax)
    2091:	0e                   	(bad)  
    2092:	10 46 0e             	adc    %al,0xe(%rsi)
    2095:	18 4a 0f             	sbb    %cl,0xf(%rdx)
    2098:	0b 77 08             	or     0x8(%rdi),%esi
    209b:	80 00 3f             	addb   $0x3f,(%rax)
    209e:	1a 3b                	sbb    (%rbx),%bh
    20a0:	2a 33                	sub    (%rbx),%dh
    20a2:	24 22                	and    $0x22,%al
    20a4:	00 00                	add    %al,(%rax)
    20a6:	00 00                	add    %al,(%rax)
    20a8:	14 00                	adc    $0x0,%al
    20aa:	00 00                	add    %al,(%rax)
    20ac:	5c                   	pop    %rsp
    20ad:	00 00                	add    %al,(%rax)
    20af:	00 90 ef ff ff 08    	add    %dl,0x8ffffef(%rax)
	...
    20bd:	00 00                	add    %al,(%rax)
    20bf:	00 14 00             	add    %dl,(%rax,%rax,1)
    20c2:	00 00                	add    %al,(%rax)
    20c4:	74 00                	je     20c6 <__GNU_EH_FRAME_HDR+0xb6>
    20c6:	00 00                	add    %al,(%rax)
    20c8:	78 f0                	js     20ba <__GNU_EH_FRAME_HDR+0xaa>
    20ca:	ff                   	(bad)  
    20cb:	ff 04 00             	incl   (%rax,%rax,1)
	...
    20d6:	00 00                	add    %al,(%rax)
    20d8:	10 00                	adc    %al,(%rax)
    20da:	00 00                	add    %al,(%rax)
    20dc:	8c 00                	mov    %es,(%rax)
    20de:	00 00                	add    %al,(%rax)
    20e0:	70 f0                	jo     20d2 <__GNU_EH_FRAME_HDR+0xc2>
    20e2:	ff                   	(bad)  
    20e3:	ff 04 00             	incl   (%rax,%rax,1)
    20e6:	00 00                	add    %al,(%rax)
    20e8:	00 00                	add    %al,(%rax)
    20ea:	00 00                	add    %al,(%rax)
    20ec:	14 00                	adc    $0x0,%al
    20ee:	00 00                	add    %al,(%rax)
    20f0:	a0 00 00 00 6c f0 ff 	movabs 0x18fffff06c000000,%al
    20f7:	ff 18 
    20f9:	00 00                	add    %al,(%rax)
    20fb:	00 00                	add    %al,(%rax)
    20fd:	41 0e                	rex.B (bad) 
    20ff:	10 56 0e             	adc    %dl,0xe(%rsi)
    2102:	08 00                	or     %al,(%rax)

0000000000002104 <__FRAME_END__>:
    2104:	00 00                	add    %al,(%rax)
	...

Disassembly of section .init_array:

0000000000003de8 <__frame_dummy_init_array_entry>:
    3de8:	30 11                	xor    %dl,(%rcx)
    3dea:	00 00                	add    %al,(%rax)
    3dec:	00 00                	add    %al,(%rax)
	...

Disassembly of section .fini_array:

0000000000003df0 <__do_global_dtors_aux_fini_array_entry>:
    3df0:	f0 10 00             	lock adc %al,(%rax)
    3df3:	00 00                	add    %al,(%rax)
    3df5:	00 00                	add    %al,(%rax)
	...

Disassembly of section .dynamic:

0000000000003df8 <_DYNAMIC>:
    3df8:	01 00                	add    %eax,(%rax)
    3dfa:	00 00                	add    %al,(%rax)
    3dfc:	00 00                	add    %al,(%rax)
    3dfe:	00 00                	add    %al,(%rax)
    3e00:	29 00                	sub    %eax,(%rax)
    3e02:	00 00                	add    %al,(%rax)
    3e04:	00 00                	add    %al,(%rax)
    3e06:	00 00                	add    %al,(%rax)
    3e08:	0c 00                	or     $0x0,%al
    3e0a:	00 00                	add    %al,(%rax)
    3e0c:	00 00                	add    %al,(%rax)
    3e0e:	00 00                	add    %al,(%rax)
    3e10:	00 10                	add    %dl,(%rax)
    3e12:	00 00                	add    %al,(%rax)
    3e14:	00 00                	add    %al,(%rax)
    3e16:	00 00                	add    %al,(%rax)
    3e18:	0d 00 00 00 00       	or     $0x0,%eax
    3e1d:	00 00                	add    %al,(%rax)
    3e1f:	00 78 11             	add    %bh,0x11(%rax)
    3e22:	00 00                	add    %al,(%rax)
    3e24:	00 00                	add    %al,(%rax)
    3e26:	00 00                	add    %al,(%rax)
    3e28:	19 00                	sbb    %eax,(%rax)
    3e2a:	00 00                	add    %al,(%rax)
    3e2c:	00 00                	add    %al,(%rax)
    3e2e:	00 00                	add    %al,(%rax)
    3e30:	e8 3d 00 00 00       	call   3e72 <_DYNAMIC+0x7a>
    3e35:	00 00                	add    %al,(%rax)
    3e37:	00 1b                	add    %bl,(%rbx)
    3e39:	00 00                	add    %al,(%rax)
    3e3b:	00 00                	add    %al,(%rax)
    3e3d:	00 00                	add    %al,(%rax)
    3e3f:	00 08                	add    %cl,(%rax)
    3e41:	00 00                	add    %al,(%rax)
    3e43:	00 00                	add    %al,(%rax)
    3e45:	00 00                	add    %al,(%rax)
    3e47:	00 1a                	add    %bl,(%rdx)
    3e49:	00 00                	add    %al,(%rax)
    3e4b:	00 00                	add    %al,(%rax)
    3e4d:	00 00                	add    %al,(%rax)
    3e4f:	00 f0                	add    %dh,%al
    3e51:	3d 00 00 00 00       	cmp    $0x0,%eax
    3e56:	00 00                	add    %al,(%rax)
    3e58:	1c 00                	sbb    $0x0,%al
    3e5a:	00 00                	add    %al,(%rax)
    3e5c:	00 00                	add    %al,(%rax)
    3e5e:	00 00                	add    %al,(%rax)
    3e60:	08 00                	or     %al,(%rax)
    3e62:	00 00                	add    %al,(%rax)
    3e64:	00 00                	add    %al,(%rax)
    3e66:	00 00                	add    %al,(%rax)
    3e68:	f5                   	cmc    
    3e69:	fe                   	(bad)  
    3e6a:	ff 6f 00             	ljmp   *0x0(%rdi)
    3e6d:	00 00                	add    %al,(%rax)
    3e6f:	00 a0 03 00 00 00    	add    %ah,0x3(%rax)
    3e75:	00 00                	add    %al,(%rax)
    3e77:	00 05 00 00 00 00    	add    %al,0x0(%rip)        # 3e7d <_DYNAMIC+0x85>
    3e7d:	00 00                	add    %al,(%rax)
    3e7f:	00 70 04             	add    %dh,0x4(%rax)
    3e82:	00 00                	add    %al,(%rax)
    3e84:	00 00                	add    %al,(%rax)
    3e86:	00 00                	add    %al,(%rax)
    3e88:	06                   	(bad)  
    3e89:	00 00                	add    %al,(%rax)
    3e8b:	00 00                	add    %al,(%rax)
    3e8d:	00 00                	add    %al,(%rax)
    3e8f:	00 c8                	add    %cl,%al
    3e91:	03 00                	add    (%rax),%eax
    3e93:	00 00                	add    %al,(%rax)
    3e95:	00 00                	add    %al,(%rax)
    3e97:	00 0a                	add    %cl,(%rdx)
    3e99:	00 00                	add    %al,(%rax)
    3e9b:	00 00                	add    %al,(%rax)
    3e9d:	00 00                	add    %al,(%rax)
    3e9f:	00 8f 00 00 00 00    	add    %cl,0x0(%rdi)
    3ea5:	00 00                	add    %al,(%rax)
    3ea7:	00 0b                	add    %cl,(%rbx)
    3ea9:	00 00                	add    %al,(%rax)
    3eab:	00 00                	add    %al,(%rax)
    3ead:	00 00                	add    %al,(%rax)
    3eaf:	00 18                	add    %bl,(%rax)
    3eb1:	00 00                	add    %al,(%rax)
    3eb3:	00 00                	add    %al,(%rax)
    3eb5:	00 00                	add    %al,(%rax)
    3eb7:	00 15 00 00 00 00    	add    %dl,0x0(%rip)        # 3ebd <_DYNAMIC+0xc5>
	...
    3ec5:	00 00                	add    %al,(%rax)
    3ec7:	00 03                	add    %al,(%rbx)
	...
    3ed1:	40 00 00             	rex add %al,(%rax)
    3ed4:	00 00                	add    %al,(%rax)
    3ed6:	00 00                	add    %al,(%rax)
    3ed8:	02 00                	add    (%rax),%al
    3eda:	00 00                	add    %al,(%rax)
    3edc:	00 00                	add    %al,(%rax)
    3ede:	00 00                	add    %al,(%rax)
    3ee0:	18 00                	sbb    %al,(%rax)
    3ee2:	00 00                	add    %al,(%rax)
    3ee4:	00 00                	add    %al,(%rax)
    3ee6:	00 00                	add    %al,(%rax)
    3ee8:	14 00                	adc    $0x0,%al
    3eea:	00 00                	add    %al,(%rax)
    3eec:	00 00                	add    %al,(%rax)
    3eee:	00 00                	add    %al,(%rax)
    3ef0:	07                   	(bad)  
    3ef1:	00 00                	add    %al,(%rax)
    3ef3:	00 00                	add    %al,(%rax)
    3ef5:	00 00                	add    %al,(%rax)
    3ef7:	00 17                	add    %dl,(%rdi)
	...
    3f01:	06                   	(bad)  
    3f02:	00 00                	add    %al,(%rax)
    3f04:	00 00                	add    %al,(%rax)
    3f06:	00 00                	add    %al,(%rax)
    3f08:	07                   	(bad)  
    3f09:	00 00                	add    %al,(%rax)
    3f0b:	00 00                	add    %al,(%rax)
    3f0d:	00 00                	add    %al,(%rax)
    3f0f:	00 40 05             	add    %al,0x5(%rax)
    3f12:	00 00                	add    %al,(%rax)
    3f14:	00 00                	add    %al,(%rax)
    3f16:	00 00                	add    %al,(%rax)
    3f18:	08 00                	or     %al,(%rax)
    3f1a:	00 00                	add    %al,(%rax)
    3f1c:	00 00                	add    %al,(%rax)
    3f1e:	00 00                	add    %al,(%rax)
    3f20:	c0 00 00             	rolb   $0x0,(%rax)
    3f23:	00 00                	add    %al,(%rax)
    3f25:	00 00                	add    %al,(%rax)
    3f27:	00 09                	add    %cl,(%rcx)
    3f29:	00 00                	add    %al,(%rax)
    3f2b:	00 00                	add    %al,(%rax)
    3f2d:	00 00                	add    %al,(%rax)
    3f2f:	00 18                	add    %bl,(%rax)
    3f31:	00 00                	add    %al,(%rax)
    3f33:	00 00                	add    %al,(%rax)
    3f35:	00 00                	add    %al,(%rax)
    3f37:	00 fb                	add    %bh,%bl
    3f39:	ff                   	(bad)  
    3f3a:	ff 6f 00             	ljmp   *0x0(%rdi)
    3f3d:	00 00                	add    %al,(%rax)
    3f3f:	00 00                	add    %al,(%rax)
    3f41:	00 00                	add    %al,(%rax)
    3f43:	08 00                	or     %al,(%rax)
    3f45:	00 00                	add    %al,(%rax)
    3f47:	00 fe                	add    %bh,%dh
    3f49:	ff                   	(bad)  
    3f4a:	ff 6f 00             	ljmp   *0x0(%rdi)
    3f4d:	00 00                	add    %al,(%rax)
    3f4f:	00 10                	add    %dl,(%rax)
    3f51:	05 00 00 00 00       	add    $0x0,%eax
    3f56:	00 00                	add    %al,(%rax)
    3f58:	ff                   	(bad)  
    3f59:	ff                   	(bad)  
    3f5a:	ff 6f 00             	ljmp   *0x0(%rdi)
    3f5d:	00 00                	add    %al,(%rax)
    3f5f:	00 01                	add    %al,(%rcx)
    3f61:	00 00                	add    %al,(%rax)
    3f63:	00 00                	add    %al,(%rax)
    3f65:	00 00                	add    %al,(%rax)
    3f67:	00 f0                	add    %dh,%al
    3f69:	ff                   	(bad)  
    3f6a:	ff 6f 00             	ljmp   *0x0(%rdi)
    3f6d:	00 00                	add    %al,(%rax)
    3f6f:	00 00                	add    %al,(%rax)
    3f71:	05 00 00 00 00       	add    $0x0,%eax
    3f76:	00 00                	add    %al,(%rax)
    3f78:	f9                   	stc    
    3f79:	ff                   	(bad)  
    3f7a:	ff 6f 00             	ljmp   *0x0(%rdi)
    3f7d:	00 00                	add    %al,(%rax)
    3f7f:	00 03                	add    %al,(%rbx)
	...

Disassembly of section .got:

0000000000003fd8 <.got>:
	...

Disassembly of section .got.plt:

0000000000004000 <_GLOBAL_OFFSET_TABLE_>:
    4000:	f8                   	clc    
    4001:	3d 00 00 00 00       	cmp    $0x0,%eax
	...
    4016:	00 00                	add    %al,(%rax)
    4018:	36 10 00             	ss adc %al,(%rax)
    401b:	00 00                	add    %al,(%rax)
    401d:	00 00                	add    %al,(%rax)
	...

Disassembly of section .data:

0000000000004020 <__data_start>:
	...

0000000000004028 <__dso_handle>:
    4028:	28 40 00             	sub    %al,0x0(%rax)
    402b:	00 00                	add    %al,(%rax)
    402d:	00 00                	add    %al,(%rax)
	...

Disassembly of section .bss:

0000000000004030 <completed.0>:
	...

Disassembly of section .comment:

0000000000000000 <.comment>:
   0:	47                   	rex.RXB
   1:	43                   	rex.XB
   2:	43 3a 20             	rex.XB cmp (%r8),%spl
   5:	28 55 62             	sub    %dl,0x62(%rbp)
   8:	75 6e                	jne    78 <__abi_tag-0x304>
   a:	74 75                	je     81 <__abi_tag-0x2fb>
   c:	20 31                	and    %dh,(%rcx)
   e:	32 2e                	xor    (%rsi),%ch
  10:	33 2e                	xor    (%rsi),%ebp
  12:	30 2d 31 75 62 75    	xor    %ch,0x75627531(%rip)        # 75627549 <_end+0x75623511>
  18:	6e                   	outsb  %ds:(%rsi),(%dx)
  19:	74 75                	je     90 <__abi_tag-0x2ec>
  1b:	31 7e 32             	xor    %edi,0x32(%rsi)
  1e:	32 2e                	xor    (%rsi),%ch
  20:	30 34 2e             	xor    %dh,(%rsi,%rbp,1)
  23:	32 29                	xor    (%rcx),%ch
  25:	20 31                	and    %dh,(%rcx)
  27:	32 2e                	xor    (%rsi),%ch
  29:	33 2e                	xor    (%rsi),%ebp
  2b:	30 00                	xor    %al,(%rax)
  2d:	55                   	push   %rbp
  2e:	62 75 6e 74 75       	(bad)
  33:	20 63 6c             	and    %ah,0x6c(%rbx)
  36:	61                   	(bad)  
  37:	6e                   	outsb  %ds:(%rsi),(%dx)
  38:	67 20 76 65          	and    %dh,0x65(%esi)
  3c:	72 73                	jb     b1 <__abi_tag-0x2cb>
  3e:	69 6f 6e 20 31 34 2e 	imul   $0x2e343120,0x6e(%rdi),%ebp
  45:	30 2e                	xor    %ch,(%rsi)
  47:	30 2d 31 75 62 75    	xor    %ch,0x75627531(%rip)        # 7562757e <_end+0x75623546>
  4d:	6e                   	outsb  %ds:(%rsi),(%dx)
  4e:	74 75                	je     c5 <__abi_tag-0x2b7>
  50:	31 2e                	xor    %ebp,(%rsi)
  52:	31 00                	xor    %eax,(%rax)
