#include"header.h"

int main(int argc, char *argv[])
{
	struct EH eh[MAX];
	FILE *fp;
	int i;

	if (NULL == (fp = fopen(argv[1], "w+")))
		perror(argv[1]);
	
	for (i = 0; i < 2; i++) {
		scanf("%s", eh[i].e_ident);
		scanf("%hi", &eh[i].e_type);
		scanf("%hi", &eh[i].e_machine);
		scanf("%d", &eh[i].e_version);
		scanf("%d", &eh[i].e_entry);
	}
	for (i = 0; i< 2; i++) {
		fwrite(&eh[i], sizeof(struct EH), 1, fp);
}
}	
