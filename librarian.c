#include"librarian.h"
#define adminPassword "hzk12345678"

BOOK *librarianModule(BOOK *head, int memberNumber)
{
	char password[20];
	printf("\n请输入管理员密码:");
	char c;
	int i = 0;
	while((c = getch()) != '\r')
	{
		if(c != 8)   //backspace的ASCII码是8，如果不是回撤则录入 
		{
			password[i] = c;
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
	if(!strcmp(password, adminPassword))
	{
		while(1)
		{
			system("color 1F");
			librarianMenu();
			char ch;
			ch = getch();
			while(ch != '1' && ch != '2' && ch != '3' && ch != '4' && ch != '5' && ch != '6')
			{
				ch = getch();
			}
			printf("%c", ch);
			if(ch == '1')
			{
				head = AppendData(head);
			}
			else if(ch == '2')
			{
				head = DeleteData(head);
			}
			else if(ch == '3')
			{
				SearchData(head);
			}
			else if(ch == '4')
			{
				PrintData(head);
			}
			else if(ch == '5')
			{
				PrintMember(memberNumber);
			}
			else if(ch == '6')
			{
				break;
			}
		}
	}
	else
	{
		printf("密码错误!\n");
	}
	
	return head;
}
