#include <asm/boot.h>
#include <asm/segment.h>
#include <asm/linkage.h>

.section .data

	.global boot_gdt
	.align 0x10

boot_gdt:

	#
	# Null segment
	#

	GDT_SEG_NULL

	#
	# Real mode code and data segment
	#

	GDT_SEG(0, 0x0000FFFF, 0x9A, 0x00)
	GDT_SEG(0, 0x0000FFFF, 0x92, 0x00)

	#
	# Protected mode code and data segment
	#

	GDT_SEG(0, 0xFFFFFFFF, 0x9A, 0xCF)
	GDT_SEG(0, 0xFFFFFFFF, 0x92, 0xCF)
boot_gdt_end:

	.global boot_gdt_desc
	.align 0x10

boot_gdt_desc:
	.word (boot_gdt_end - boot_gdt - 1)
	.long (boot_gdt)

boot_idt_real:
	.word 0x3FF
	.long 0

boot_idt_prot:
	.word 0
boot_idt_prot_addr:
	.long 0

.section .real, "ax", @progbits

.code16

GLOBAL(pmmode_jmp)
	xorw    %ax, %ax
	movw    %ax, %ds

	movl    %cr0, %eax
	orl     $0x1, %eax
	movl    %eax, %cr0

	ljmp	$GDT_CODE32, $.protcseg

.code32

.protcseg:
	movw    $GDT_DATA32, %ax
	movw    %ax, %ds
	movw    %ax, %es
	movw    %ax, %fs
	movw    %ax, %gs
	movw    %ax, %ss

	/*
	 * Switch IDTs
	 */

	sidt    boot_idt_real
	lidt    boot_idt_prot

	/*
	 * Hack: Only enable interrupts if there is an IDT present for protected
	 * mode. Otherwise we will cause a triple fault.
	 */

	cmpl    $0, boot_idt_prot_addr
	jz      .pmmode_jmp_done

	sti

LOCAL(.pmmode_jmp_done)

	retw
ENDPROC(pmmode_jmp)

GLOBAL(rmmode_jmp)
	cli

	/*
	 * Switch IDTs
	 */

	sidt    boot_idt_prot
	lidt    boot_idt_real

	movw    $GDT_DATA16, %ax
	movw    %ax, %ds
	movw    %ax, %es
	movw    %ax, %fs
	movw    %ax, %gs
	movw    %ax, %ss

	ljmp    $GDT_CODE16, $.protcseg16

.code16

.protcseg16:
	movl    %cr0,	%eax
	andl    $(~1), %eax
	movl    %eax,	%cr0

	ljmp    $0, $.realcseg

.realcseg:
	xorw    %ax, %ax
	movw    %ax, %ds
	movw    %ax, %es
	movw    %ax, %fs
	movw    %ax, %gs
	movw    %ax, %ss

	/*
	 * Use retl instead of ret to pop the correct
	 * amount of bytes from the stack.
	 */

	retl
