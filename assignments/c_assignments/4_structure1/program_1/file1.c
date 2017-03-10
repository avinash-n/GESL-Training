/*
	Name: Bitfields in Structures
	Author: Avinash N
	Date: 24 November 2016
	Description: This program will display the size of structures
			and concept of bitfields is implemented.
*/

#include<stdio.h>
#include<stdlib.h>

#pragma pack (1)

//program to print size of structure
struct frame_1
{
	unsigned char HEC;
	unsigned short CLP:1;
	unsigned short PTI:3;
	unsigned short VCI:16;
	unsigned char VPI:8;
	unsigned char GFC:4;
};

struct frame_2
{
	unsigned short src_port;
	unsigned short dest_port;
	unsigned int seq_num;
	unsigned int ack_num;
	unsigned char header:4;
	unsigned char res:6;
	unsigned char code_bits:6;
	unsigned short window;
	unsigned short chk_sum;
	unsigned short urg;
//	unsigned int opt[];
	unsigned int data[];
};

struct frame_3
{
	unsigned char v:4;
	unsigned char hl:4;
	unsigned char st;
	unsigned short tl;
	unsigned short id;
	unsigned char f:4;
	unsigned short fo:12;
	unsigned char ttl;
	unsigned char p;
	unsigned short hc;
	unsigned int sid;
	unsigned int dip;
	unsigned int opt:20;
	unsigned int pad:12;
};

int main()
{
	printf("Size of frame 1: %2d Bytes\n", sizeof(struct frame_1));
	printf("Size of frame 2: %2d Bytes\n", sizeof(struct frame_2));
	printf("Size of frame 3: %2d Bytes\n", sizeof(struct frame_3));

	return 0;
}
