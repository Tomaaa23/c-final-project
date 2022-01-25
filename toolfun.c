#include"toolfun.h"

/*函数功能:新建一个节点添加到链表末尾 
函数参数:链表头节点指针
函数返回值:添加节点后的链表头节点指针*/
BOOK *AppendNode(BOOK *head)
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
	printf("请输入图书信息...\n");
	printf("图书编号:");
	scanf("%s", p->number);
	printf("书名:");
	scanf(" %s", p->name);
	printf("作者名:");
	scanf(" %s", p->author);
	printf("图书数量:");
	scanf("%d", &p->quantity);
	printf("市场价格:");
	scanf("%lf", &p->price);
	pr->next = NULL;
	return head;
}
/*函数功能:根据图书编号查找图书
函数参数:链表头节点指针，目标图书编号
函数返回值:找到则为储存该图书信息的节点指针，没找到则为NULL*/
BOOK *SearchNode1(BOOK *head, const char nodeNum[15])
{
	BOOK *p = head;
	while(p != NULL)
	{
		if(!strcmp(p->number, nodeNum))
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
} 
/*函数功能:根据图书名查找图书
函数参数:链表头节点指针，目标图书名 
函数返回值:找到则为储存该图书信息的节点指针，没找到则为NULL*/
BOOK *SearchNode2(BOOK *head, const char nodeName[15])
{
	BOOK *p = head;
	while(p != NULL)
	{
		if(!strcmp(p->name, nodeName))
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}
/*函数功能:选择根据图书编号或者图书名查找图书
函数参数:链表头节点指针
函数返回值:无*/
void SearchData(BOOK *head)
{
	system("cls");
	printf("1.根据图书编号来查找 2.根据图书名来查找\n你的选择是:");
	char c;
	c = getch();
	while(c != '1' && c != '2')
	{
		c = getch();
	}
	printf("%c\n", c);
	if(c == '1')
	{
		printf("图书编号:");
		char str1[15];
		scanf(" %s", str1);
		BOOK *pr1;
		pr1 = SearchNode1(head, str1);
		if(pr1 != NULL)
		{
			printf("\t编号\t\t书名\t\t作者名 数量 市场价\n");
			printf("%12s%16s%18s%4d%8.2f\n", pr1->number, pr1->name, pr1->author, pr1->quantity, pr1->price);
		}
		else
		{
			printf("没有找到编号为%s的图书\n", str1);
		}
	}
	else if(c == '2')
	{
		printf("图书名:");
		char str2[30];
		scanf(" %s", str2);
		BOOK *pr2;
		pr2 = SearchNode1(head, str2);
		if(pr2 != NULL)
		{
			printf("\t编号\t\t书名\t\t作者名 数量 市场价\n");
			printf("%12s%16s%18s%4d%8.2f\n", pr2->number, pr2->name, pr2->author, pr2->quantity, pr2->price);
		}
		else
		{
			printf("没有找到书名为%s的图书\n", str2);
		}
	}
	printf("按任意键返回上一级菜单\n");
	getch();
	
}
/*函数功能:根据图书编号删除图书信息
函数参数:链表头节点指针，目标图书编号
函数返回值:删除后的链表头节点指针*/ 
BOOK *DeleteNode1(BOOK *head, const char nodeNum[15])
{
	BOOK *p = head, *pr = head;
	if(head = NULL)
	{
		printf("没有信息\n");
		return head;
	}
	while(strcmp(nodeNum, p->number) && p->next != NULL) //遍历整个链表 
	{
		pr = p;
		p = p->next;
	}
	if(!strcmp(nodeNum, p->number)) //若找到则删除 
	{
		if(p = head)  //若目标节点为首节点，则将head指向第二个节点 
		{
			head = p->next;
		}
		else          //若目标节点不是首节点，则将前一节点指针指向当前节点的下一节点
		{
			pr->next = p->next;
		}
		free(p);  //释放删除节点的内存
		printf("删除成功!\n");
	}
	else  //没找到则给出提示 
	{
		printf("没有找到编号为%s的图书", nodeNum);
	}
	
	return head;
}
/*函数功能:根据图书名删除图书信息
函数参数:链表头节点指针，目标图书名 
函数返回值:删除后的链表头节点指针*/ 
BOOK *DeleteNode2(BOOK *head, const char nodeName[30])
{
	BOOK *p = head, *pr = head;
	if(head = NULL)
	{
		printf("没有信息\n");
		return head;
	}
	while(strcmp(nodeName, p->name) && p->next != NULL) //遍历整个链表 
	{
		pr = p;
		p = p->next;
	}
	if(!strcmp(nodeName, p->name)) //若找到则删除 
	{
		if(p = head)  //若目标节点为首节点，则将head指向第二个节点 
		{
			head = p->next;
		}
		else          //若目标节点不是首节点，则将前一节点指针指向当前节点的下一节点 
		{
			pr->next = p->next;
		}
		free(p);  //释放删除节点的内存 
		printf("删除成功!\n");
	}
	else  //没找到则给出提示 
	{
		printf("没有找到书名为%s的图书", nodeName);
	}
	
	return head;
}
/*函数功能:打印图书信息
函数参数:链表头节点指针
函数返回值:无*/ 
void PrintData(BOOK *head)
{
	system("cls");
	BOOK *p = head;
	printf("\t编号\t\t书名\t\t作者名 数量 市场价\n");
	while(p != NULL) //遍历链表 
	{
		printf("%12s%16s%18s%4d%8.2f\n", p->number, p->name, p->author, p->quantity, p->price);
		p = p->next;
	}
	printf("按任意键返回上一级菜单\n");
	getch();
}
/*函数功能:向链表中添加图书信息
函数参数:链表头节点指针
函数返回值:添加信息后的链表头节点指针*/
BOOK *AppendData(BOOK *head)
{
	system("cls");
	int i = 0;
	char ch;
	do
	{
		head = AppendNode(head);
		printf("你要继续添加图书信息吗(y/n)?");
		ch = getch();
		while(ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n')
		{
			ch = getch();
		}
		printf("%c\n", ch);
		i++;
	}while(ch == 'Y' || ch == 'y');
	printf("%d本图书信息被录入系统!\n", i);
	return head;
}
/*函数功能:选择根据图书编号或者图书名来删除图书信息
函数参数:链表头节点指针
函数返回值:删除信息后的链表头节点指针*/
BOOK *DeleteData(BOOK *head)
{
	system("cls");
	char c;
	printf("1.根据图书编号删除 2.根据图书名删除\n你的选择是:");
	c = getch();
	while(c != '1' && c != '2')
	{
		c = getch();
	}
	printf("%c\n", c);
	if(c == '1')
	{
		printf("请输入图书编号:");
		char str1[15];
		scanf(" %s", str1);
		DeleteNode1(head, str1);
	}
	else if(c == '2')
	{
		printf("请输入书名:");
		char str2[30];
		scanf(" %s", str2);
		DeleteNode2(head, str2);
	}
	printf("输入任意键返回上一级菜单\n");
	getch();
	return head;
}




