#include"header.h"

int main(int argc, char *argv[])
{
	struct EH eh[MAX];
	FILE *fp;
	int i;
	int j;

	if (NULL == (fp = fopen(argv[1], "r")))
		perror(argv[1]);
	
	for (i = 0; i< 2; i++) {
		fread(&eh[i], sizeof(struct EH), 1, fp);
	}
for(j = 0; j < 2; j++) {
                printf("%s", eh[j].e_ident);
                printf("%hi", eh[j].e_type);
                printf("%hi", eh[j].e_machine);
                printf("%d", eh[j].e_version);
                printf("%d", eh[j].e_entry);
        }

 

}	
