#include "myelf.h"

int main(int argc, char *argv[]) {
	FILE *fp = NULL;
	FILE *fp_sh = NULL;
	char *str = NULL;
	myElf32_Ehdr my_Ehdr;
	myElf32_Shdr my_Shdr;
	int i;


	fp = fopen(argv[1], "r");
	VALIDATE(fp);

// ELF header
	fread(&my_Ehdr, 52, 1, fp);

	fprintf(stdout, "%s", "ELF Header:\n");
	printf("Magic:%16.x\n", my_Ehdr.magic_num);
	fprintf(stdout, "%s", "Class:\t\t\t\t\tELF32\n");
	fprintf(stdout, "%s", "Data:\t\t\t\t\t2's complement, little endian\n");
	fprintf(stdout, "%s", "Version:\t\t\t\t1 (current)\n");
	fprintf(stdout, "%s", "OS/ABI:\t\t\t\t\tUNIX - System V\n");
	fprintf(stdout, "%s", "ABI Version:\t\t\t\t0\n");
	printf("Type:\t\t\t\t\t%d\n", my_Ehdr.elfh_type);
	printf("Machine:\t\t\t\t%d\n", my_Ehdr.elfh_machine);
	printf("Version:\t\t\t\t%p\n", my_Ehdr.elfh_version);
	printf("Entry point address:\t\t\t%p\n", my_Ehdr.elfh_entry);
	printf("Start of program header:\t\t%d (bytes into file)\n", my_Ehdr.elfh_phoff);
	printf("Start of section header:\t\t%d (bytes into file)\n", my_Ehdr.elfh_shoff);
	printf("Flags:\t\t\t\t\t0x%d\n", my_Ehdr.elfh_flags);
	printf("Size of this header:\t\t\t%d (bytes)\n", my_Ehdr.elfh_ehsize);
	printf("Size of program headers:\t\t%d (bytes)\n", my_Ehdr.elfh_phentsize);
	printf("Number of program header:\t\t%d\n", my_Ehdr.elfh_phnum);
	printf("Size of section headers:\t\t%d (bytes)\n", my_Ehdr.elfh_shentsize);
	printf("Number of section headers:\t\t%d\n", my_Ehdr.elfh_shnum);
	printf("Section header string table index:\t%d\n", my_Ehdr.elfh_shstrndx);
	printf("\n");

// Section header

	fseek(fp, my_Ehdr.elfh_shoff, SEEK_SET);

	fseek(fp_sh, my_Ehdr.elfh_shoff + (my_Ehdr.elfh_shentsize * my_Ehdr.elfh_shstrndx), SEEK_SET);

	fread(&my_Shdr, sizeof(my_Shdr), 1, fp_sh);

	if (NULL == (str = (char *) malloc (my_Shdr.sech_size))) {
		printf("Malloc is failed!");
		exit(1);
	}

	fseek(fp_sh, my_Shdr.sech_offset, SEEK_SET);
	fread(&str, my_Shdr.sech_size, 1, fp_sh);
	
	fprintf(stdout, "%s", "Section Headers:\n");
	fprintf(stdout, "%s", "[Nr]\tName\t\tType\t\tAddr\t  Off\t  Size\t  ES Flg  Lk  Inf Al\n");

	for (i = 0; i < my_Ehdr.elfh_shnum; i++) {
	fread(&my_Shdr, my_Ehdr.elfh_shentsize, 1, fp);
	
	printf("[%2d]\t", i);
	printf("%d\t\t", my_Shdr.sech_name);	// string table

	switch (my_Shdr.sech_type) {
	case 0:
		printf("NULL\t\t"); 
		break;
	case 1:
		printf("PROGBITS\t"); 
		break;
	case 2:
		printf("SYMTAB\t\t"); 
		break;
	case 3:
		printf("SYRTAB\t\t"); 
		break;
	case 4:
		printf("RELA\t\t"); 
		break;
	case 5:
		printf("HASH\t\t"); 
		break;
	case 6:
		printf("DYNAMIC\t\t"); 
		break;
	case 7:
		printf("NOTE\t\t"); 
		break;
	case 8:
		printf("NOBITS\t\t"); 
		break;
	case 9:
		printf("REL\t\t"); 
		break;
	case 10:
		printf("SHLIB\t\t"); 
		break;
	case 11:
		printf("DYNSYM\t\t"); 
		break;
	case 14:
		printf("INIT_ARRAY\t"); 
		break;
	case 15:
		printf("FINI_ARRAY\t"); 
		break;
	case 1879048182:
		printf("GNU_HASH\t"); 
		break;
	case 1879048191:
		printf("VERSYM\t\t"); 
		break;
	case 1879048190:
		printf("VERNEED\t\t"); 
		break;
}

//	printf("%d\t", my_Shdr.sech_type);
	printf("%08x  ", my_Shdr.sech_addr);
	printf("%06x  ", my_Shdr.sech_offset);
	printf("%06x  ", my_Shdr.sech_size);
	printf("%02x  ", my_Shdr.sech_entsize);
//	printf("%x\t", my_Shdr.sech_flags);	
	switch (my_Shdr.sech_flags) {
	case 0x2:
		printf(" A  ");
		break;
	case 0x3:
		printf("WA  ");
		break;
	case 0x6:
		printf("AX  ");
		break;
	case 0x30:
		printf("MS  ");
		break;
	default:
		printf("    ");
	}
	printf("%02d  ", my_Shdr.sech_link);
	printf("%02d  ", my_Shdr.sech_info);
	printf("%02d\n", my_Shdr.sech_addralign);
	}

	free(fp);

	return 0;
}
