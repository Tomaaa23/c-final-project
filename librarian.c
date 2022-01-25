#include"librarian.h"
#define adminPassword "hzk12345678"

BOOK *librarianModule(BOOK *head, int memberNumber)
{
	char password[20];
	printf("\n���������Ա����:");
	char c;
	int i = 0;
	while((c = getch()) != '\r')
	{
		if(c != 8)   //backspace��ASCII����8��������ǻس���¼�� 
		{
			password[i] = c;
			putchar('*');  //���*�� 
			i++;
		}
		else         //�س���ɾ��һλ������ʵ������ 
		{
			putchar('\b');  //�������һ���س���\b��ʹ���س�һ�� 
			putchar(' ');   //Ȼ����ʾ�ո񽫸ղ������*���� 
			putchar('\b');  //Ȼ���ٻس�һ�� 
			i--;			//�����i�Լ� 
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
		printf("�������!\n");
	}
	
	return head;
}
