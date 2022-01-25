#ifndef __H__main__H__
#define __H__main__H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

struct bookdata
{
	char number[15]; //图书编号 
	char name[30]; //书名 
	char author[30]; //作者名字 
	int quantity; //图书数量 
	double price; //图书市场价(会员损坏或弄丢时赔偿时做参考)
	struct bookdata *next;
};
typedef struct bookdata BOOK;

struct memberdata
{
	int id;  //会员ID
	char name[30]; //会员名字
	long long phone; //会员电话
	char password[20]; //会员密码
	int bookQuantity;
	char book[10][30];
};
typedef struct memberdata MEM;

#endif
