int stringcompare(char *src, char *dst)
{
	int i = 0;

	for( i = 0; 
	     (*(src + i) != '\0') && (*(dst + i) != '\0'); 
	     i++) {
		if ( *(src + i) == *(dst + i)) {
			continue;
		} else {
			if ( *(src + i) > *(dst + i) ) {
				return 1;
				break;
			} else {
				return -1;
				break;
			}
		}
	} 
	while((*(src +i) == '\0') || (*(dst + i) == '\0')) {
		if ((*(src + i) == '\0') && (*(dst + i) == '\0')) {
			return 0;
		} else if( *(src + i) == '\0') {
			return -1;
		} else {
			return 1;
		}
	}
}
