#ifndef __ELFBOOT_LOADER_LXBOOT_H__
#define __ELFBOOT_LOADER_LXBOOT_H__

#define DRIVER_LXBOOT				"LXB"

#define LXBOOT_BZIMAGE_SIGNATURE	0x53726448

#define LXBOOT_KERNEL_ADDR			0x00100000
#define LXBOOT_INITRD_ADDR			0x01000000

struct lxboot_rm_header {
	uint8_t setup_sects;
	uint16_t root_flags;
	uint32_t syssize;
	uint16_t ram_size;
	uint16_t vid_mode;
	uint16_t root_dev;
	uint16_t boot_flag;
	uint16_t jump;
	uint32_t header;
	uint16_t version;
	uint32_t realmode_swtch;
	uint16_t start_sys_seg;
	uint16_t kernel_version;
	uint8_t type_of_loader;
	uint8_t loadflags;
	uint16_t setup_move_size;
	uint32_t code32_start;
	uint32_t ramdisk_image;
	uint32_t ramdisk_size;
	uint32_t bootsect_kludge;
	uint16_t heap_end_ptr;
	uint8_t ext_loader_ver;
	uint8_t ext_loader_type;
	uint32_t cmd_line_ptr;
	uint32_t initrd_addr_max;
	uint32_t kernel_alignment;
	uint8_t relocatable_kernel;
	uint8_t min_alignment;
	uint16_t xloadflags;
	uint32_t cmdline_size;
	uint32_t hardware_subarch;
	uint64_t hardware_subarch_data;
	uint32_t payload_offset;
	uint32_t payload_length;
	uint64_t setup_data;
	uint64_t pref_address;
	uint32_t init_size;
	uint32_t handover_offset;
} __packed;

struct lxboot_info {
	uint32_t signature;
	uint16_t bprotvers;
	uint8_t rmcodesec;
	uint32_t rmcodelen;
	uint32_t pmcodelen;
	struct lxboot_rm_header *rmcodehdr;
	void *rmcodebuf;
};

#endif /* __ELFBOOT_LOADER_LXBOOT_H__ */