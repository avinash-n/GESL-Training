#include <stdio.h>
#include <stdlib.h>
//#include <elf.h>

#define ELF_MAGIC 16

//#define MEM_ALLOC_H(ptr) ptr = (FILE *) malloc (sizeof(myElf32_Ehdr));

//#define MEM_ALLOC_S(ptr) ptr = (FILE *) malloc (sizeof(myElf32_Shdr));

#define VALIDATE(ptr) if (!(ptr)) {\
			fprintf(stdout, "%s", "Returned NULL\n");\
			exit(1);\
			}

typedef unsigned short int myElf32_Half;
typedef unsigned int myElf32_Word;

typedef struct {
	unsigned char magic_num[ELF_MAGIC];
	myElf32_Half elfh_type;
	myElf32_Half elfh_machine;
	myElf32_Word elfh_version;
	myElf32_Word elfh_entry;
	myElf32_Word elfh_phoff;
	myElf32_Word elfh_shoff;
	myElf32_Word elfh_flags;
	myElf32_Half elfh_ehsize;
	myElf32_Half elfh_phentsize;
	myElf32_Half elfh_phnum;
	myElf32_Half elfh_shentsize;
	myElf32_Half elfh_shnum;
	myElf32_Half elfh_shstrndx;
} myElf32_Ehdr;

typedef struct {
	myElf32_Word sech_name;
	myElf32_Word sech_type;
	myElf32_Word sech_flags;
	myElf32_Word sech_addr;
	myElf32_Word sech_offset;
	myElf32_Word sech_size;
	myElf32_Word sech_link;
	myElf32_Word sech_info;
	myElf32_Word sech_addralign;
	myElf32_Word sech_entsize;
} myElf32_Shdr;
