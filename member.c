#include"member.h"

BOOK *memberModule(BOOK *head)
{
	printf("\n请输入你的id:");
	int id;
	scanf("%d", &id);
	printf("请输入密码:");
	char c;
	char memberPassword[20];
	int i = 0;
	while((c = getch()) != '\r')
	{
		if(c != 8)   //backspace的ASCII码是8，如果不是回撤则录入 
		{
			memberPassword[i] = c;
			putchar('*');  //输出*号
			i++;
		}
		else         //回撤则删除一位，具体实现如下 
		{
			putchar('\b');  //首先输出一个回撤符\b，使光标回撤一个 
			putchar(' ');   //然后显示空格将刚才输入的*覆盖 
			putchar('\b');  //然后再回撤一个 
			i--;			//最后让i自减 
		}
	}
	memberPassword[i] = '\0';
	if(!strcmp(memberPassword, member[id].password))
	{
		while(1)
		{
		
			system("color 3F");
			memberMenu();
			char ch;
			ch = getch();
			while(ch != '1' && ch != '2' && ch != '3' && ch != '4' && ch != '5')
			{
				ch = getch();
			}
			printf("%c", ch);
			if(ch == '1')
			{
				SearchData(head);
			}
			else if(ch == '2')
			{
				head = borrowBook(head, id);
			}
			else if(ch == '3')
			{
				head = returnBook(head, id);
			}
			else if(ch == '4')
			{
				PrintData(head);
			}
			else if(ch == '5')
			{
				break;
			}
		}
	}
	else
	{
		printf("密码错误!\n");
		printf("按任意键返回上一级菜单");
		getch();
	}
	return head;
}

int logup()
{
	static int ii = 1;
	system("cls");
	printf("你注册的会员id为%d\n", ii);
	member[ii].id = ii;
	printf("请输入你的姓名:");
	scanf(" %s", member[ii].name);
	printf("请输入你的电话:");
	scanf("%lld", &member[ii].phone);
	printf("请输入你的密码:");
	scanf(" %s", member[ii].password);
	member[ii].bookQuantity = 0;
	printf("注册完成!\n");
	printf("按任意键返回上一级菜单");
	getch();
	ii++;
	return ii - 1;
}
/*函数功能:会员借书模块
函数参数:链表头节点指针
函数返回值:修改后的链表头节点指针*/
BOOK *borrowBook(BOOK *head, int id)
{
	system("cls");
	char num[15];
	printf("请输入你要借的书的编号:");
	scanf(" %s", num);
	BOOK *pr = SearchNode1(head, num);
	if(pr != NULL)
	{
		if(pr->quantity != 0)
		{
			pr->quantity--;
			member[id].bookQuantity++;
			strcpy(member[id].book[member[id].bookQuantity], pr->name); //以借走的图书数量作为数组下标
			printf("借书成功!\n");
		}
		else
		{
			printf("该书已经全部被其他会员借走!\n");
		}
	}
	else
	{
		printf("没有找到编号为%s的图书\n", num);
	}
	printf("按任意键返回上一级菜单");
	getch();
	return head;
}
/*函数功能:会员还书模块
函数参数:链表头节点指针
函数返回值:修改后的链表头节点指针*/
BOOK *returnBook(BOOK *head, int id)
{
	system("cls");
	char num1[15];
	printf("请输入你要还的书的编号:");
	scanf(" %s", num1);
	BOOK *pr1 = SearchNode1(head, num1);
	if(pr1 != NULL)
	{
		pr1->quantity++;
		member[id].bookQuantity--;
		printf("还书成功!\n");
		
	}
	else
	{
		printf("没有找到编号为%s的图书\n", num1);
	}
	printf("按任意键返回上一级菜单");
	getch();
	return head;
}

void PrintMember(int ii)
{
	system("cls");
	printf("  ID\t会员名\t\t会员电话\t会员密码 图书数量\t图书\n");
	int j;
	for(j = 1; j <= ii; j++)
	{
		printf("%4d%10s%18lld%16s%8d\t", member[j].id, member[j].name, member[j].phone, member[j].password, member[j].bookQuantity);
		int k = 1;
		for(k = 1; k <= member[j].bookQuantity; k++)
		{
			printf("%s ", member[j].book[k]);
		}
		printf("\n");
	}
	printf("按任意键返回上一级菜单");
	getch();
}





