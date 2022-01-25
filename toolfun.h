#ifndef __H__toolfun__H__
#define __H__toolfun__H__

#include"main.h"
BOOK *AppendNode(BOOK *head);
BOOK *SearchNode1(BOOK *head, const char nodeNum[15]);
BOOK *SearchNode2(BOOK *head, const char nodeNume[15]);
void SearchData(BOOK *head);
BOOK *DeleteNode1(BOOK *head, const char nodeNum[15]);
BOOK *DeleteNode2(BOOK *head, const char nodeName[30]);
void PrintData(BOOK *head);
BOOK *AppendData(BOOK *head);
BOOK *DeleteData(BOOK *head);

#endif
