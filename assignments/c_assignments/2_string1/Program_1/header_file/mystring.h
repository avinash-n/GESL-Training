/* Header file for string functions */

#define MAX_STRING_LENGTH 128

/* Declaration of string_n_copy function defined in str_n_cpy.c */
void str_n_cpy(char *, char *, int);

/* Declaration of validate function defined in validation.c */
int validate(char *);

/* Squeeze consecutive similar characters */
void str_squeeze(char *, char *);

/* Compare rotated string */
int str_r_cmp(char *, char *);

/* Find string length */
int str_len(char *);

/* Find the address of first occurance of a character in a string */
int *chr_addr(char *, char *);

/* Append string_2 at the end of string_1 */
void str_cat(char *, char *);

/* Insert a character into a string at a given position */
void chr_ins(char *, char *, int );

/* Declaration of string copy function defined in str_cpy.c */
void string_copy(char *, char *);
