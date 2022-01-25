#ifndef __H__member__H__
#define __H__member__H__

#include"main.h"
#include"toolfun.h"

MEM member[300];
BOOK *memberModule(BOOK *head);
int logup(void);
BOOK *borrowBook(BOOK *head, int id);
BOOK *returnBook(BOOK *head, int id);
void PrintMember(int ii);

#endif
