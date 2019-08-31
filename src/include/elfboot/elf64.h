#ifndef __BOOT_ELF64_H__
#define __BOOT_ELF64_H__

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>

#include <boot/elf.h>

struct elf64_hdr {
	struct elf_hdr hdr;
	uint64_t e_entry;
	uint64_t e_phoff;
	uint64_t e_shoff;
	uint32_t e_flags;
	uint16_t e_ehsize;
	uint16_t e_phentsize;
	uint16_t e_phnum;
	uint16_t e_shentsize;
	uint16_t e_shnum;
	uint16_t e_shstrndx;
} __attribute__((packed));

struct elf64_shdr {
	uint32_t sh_name;
	uint32_t sh_type;
	uint64_t sh_flags;
	uint64_t sh_addr;
	uint64_t sh_offset;
	uint64_t sh_size;
	uint32_t sh_link;
	uint32_t sh_info;
	uint64_t sh_addralign;
	uint64_t sh_entsize;
} __attribute__((packed));

struct elf64_sym {
	uint32_t st_name;
	unsigned char st_info;
	unsigned char st_other;
	uint16_t st_shndx;
	uint64_t st_value;
	uint64_t st_size;
} __attribute__((packed));

struct elf64_rel {
	uint64_t r_offset;
	uint64_t r_info;
} __attribute__((packed));

struct elf64_rela {
	uint64_t r_offset;
	uint64_t r_info;
	int64_t  r_addend;
} __attribute__((packed));

struct elf64_phdr {
	uint32_t p_type;
	uint32_t p_flags;
	uint64_t p_offset;
	uint64_t p_vaddr;
	uint64_t p_paddr;
	uint64_t p_filesz;
	uint64_t p_memsz;
	uint64_t p_align;
} __attribute__((packed));

struct elf64_dyn {
	int64_t  d_tag;
	union {
		uint64_t d_val;
		uint64_t d_ptr;
	} d_un;
} __attribute__((packed));

bool elf64_check_file(struct elf64_hdr *elf64_hdr);

struct elf64_shdr *elf64_get_shdr(struct elf64_hdr *elf64_hdr);

struct elf64_shdr *elf64_get_section(struct elf64_hdr *elf64_hdr, int index);

struct elf64_phdr *elf64_get_phdr(struct elf64_hdr *elf64_hdr);

#endif /* __BOOT_ELF64_H__ */