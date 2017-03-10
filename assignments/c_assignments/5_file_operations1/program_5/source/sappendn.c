void sappendn(char *src, char *dst, int n)
{
	int i = 0;
	int m1 = stringlength(src) - 1;
	int m2 = stringlength(dst) - 1;

	for ( i = 0; (i <  n) && (*(dst + i) != '\0') ; i++) {
		*(src + (m1 + i)) = *( dst + i);
	}
	*(src + (m1 + n)) = '\0';
}
