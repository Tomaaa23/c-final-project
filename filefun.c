#include"filefun.h"
/*函数功能:将储存图书信息的链表数据写入文本文档中
函数参数:链表头节点指针
函数返回值:无*/
void WritetoFile1(BOOK *head)
{
	FILE *fp;
	BOOK *p = head;
	if((fp = fopen("bookdata.txt", "w")) == NULL)   //检验文件是否打开成功
    {
        printf("文件打开失败!\n");
        exit(0);
    }
	while(p != NULL)
	{
		fprintf(fp, "%s %s %s %d %f\n", p->number, p->name, p->author, p->quantity, p->price); //向文件里写入数据
		p = p->next;
	}
	fclose(fp); //关闭文件
}
/*函数功能:从文件中读取信息
函数参数:链表头节点指针
函数返回值:链表头节点指针*/
BOOK *ReadfromFile1(BOOK *head)
{
	FILE *fp;
	if((fp = fopen("bookdata.txt", "r")) == NULL)  //检测文件是否打开成功，若失败则返回NULL
    {                                          //失败是因为该文件还未创建，也读不了数据 
        return NULL;
    }
    while(!feof(fp))
    {
    	BOOK *p = NULL;
		BOOK *pr = head;
		p = (BOOK *)malloc(sizeof(BOOK)); //为新建节点申请内存 
		if(p == NULL)
		{
			printf("没有足够的内存了!\n");
			exit(0);
		}
		if(head == NULL) //若为空表，则置为首节点 
		{
			head = p;
		}
		else
		{
			while(pr->next != NULL) //若为非空，则添加到链表末尾 
			{
				pr = pr->next;
			}
			pr->next = p;
		}
		pr = p;
		fscanf(fp, "%s %s %s %d %f", p->number, p->name, p->author, &p->quantity, &p->price);
		pr->next = NULL;
	}
    fclose(fp);
    return head;
}
/*函数功能:将会员信息写入文本文件
函数参数:会员人数
函数返回值:无*/
void WritetoFile2(int ii, MEM member[300])
{
	FILE *fp;
	if((fp = fopen("memberdata.txt", "w")) == NULL)   //检验文件是否打开成功
    {
        printf("文件打开失败!\n");
        exit(0);
    }
    int j;
	for(j = 1; j <= ii; j++)
	{
		fprintf(fp, "%d %s %lld %s %d ", member[j].id, member[j].name, member[j].phone, member[j].password, member[j].bookQuantity);
		int k = 1;
		for(k = 1; k <= member[j].bookQuantity; k++)
		{
			fprintf(fp, "%s ", member[j].book[k]);
		}
		printf("\n");
	}
}
/*函数功能:从文本文档中读取信息
函数参数:会员人数和结构体数组
函数返回值:结构体数组首地址*/
MEM *ReadfromFile(int ii, MEM member[300])
{
	FILE *fp;
	if((fp = fopen("bookdata.txt", "r")) == NULL)  //检测文件是否打开成功，若失败则返回NULL
    {                                          //失败是因为该文件还未创建，也读不了数据 
        return;
    }
    while(!feof(fp))
    {
    	int j;
		for(j = 1; j <= ii; j++)
		{
			fscanf(fp, "%d %s %lld %s %d ", &member[j].id, member[j].name, &member[j].phone, member[j].password, &member[j].bookQuantity);
			int k = 1;
			for(k = 1; k <= member[j].bookQuantity; k++)
			{
				fscanf(fp, "%s ", member[j].book[k]);
			}
		}
	}
	fclose(fp);
	return member;
}




