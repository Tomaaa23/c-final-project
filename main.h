#ifndef __H__main__H__
#define __H__main__H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

struct bookdata
{
	char number[15]; //ͼ���� 
	char name[30]; //���� 
	char author[30]; //�������� 
	int quantity; //ͼ������ 
	double price; //ͼ���г���(��Ա�𻵻�Ū��ʱ�⳥ʱ���ο�)
	struct bookdata *next;
};
typedef struct bookdata BOOK;

struct memberdata
{
	int id;  //��ԱID
	char name[30]; //��Ա����
	long long phone; //��Ա�绰
	char password[20]; //��Ա����
	int bookQuantity;
	char book[10][30];
};
typedef struct memberdata MEM;

#endif
