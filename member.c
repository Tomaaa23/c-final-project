#include"member.h"

BOOK *memberModule(BOOK *head)
{
	printf("\n���������id:");
	int id;
	scanf("%d", &id);
	printf("����������:");
	char c;
	char memberPassword[20];
	int i = 0;
	while((c = getch()) != '\r')
	{
		if(c != 8)   //backspace��ASCII����8��������ǻس���¼�� 
		{
			memberPassword[i] = c;
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
		printf("�������!\n");
		printf("�������������һ���˵�");
		getch();
	}
	return head;
}

int logup()
{
	static int ii = 1;
	system("cls");
	printf("��ע��Ļ�ԱidΪ%d\n", ii);
	member[ii].id = ii;
	printf("�������������:");
	scanf(" %s", member[ii].name);
	printf("��������ĵ绰:");
	scanf("%lld", &member[ii].phone);
	printf("�������������:");
	scanf(" %s", member[ii].password);
	member[ii].bookQuantity = 0;
	printf("ע�����!\n");
	printf("�������������һ���˵�");
	getch();
	ii++;
	return ii - 1;
}
/*��������:��Ա����ģ��
��������:����ͷ�ڵ�ָ��
��������ֵ:�޸ĺ������ͷ�ڵ�ָ��*/
BOOK *borrowBook(BOOK *head, int id)
{
	system("cls");
	char num[15];
	printf("��������Ҫ�����ı��:");
	scanf(" %s", num);
	BOOK *pr = SearchNode1(head, num);
	if(pr != NULL)
	{
		if(pr->quantity != 0)
		{
			pr->quantity--;
			member[id].bookQuantity++;
			strcpy(member[id].book[member[id].bookQuantity], pr->name); //�Խ��ߵ�ͼ��������Ϊ�����±�
			printf("����ɹ�!\n");
		}
		else
		{
			printf("�����Ѿ�ȫ����������Ա����!\n");
		}
	}
	else
	{
		printf("û���ҵ����Ϊ%s��ͼ��\n", num);
	}
	printf("�������������һ���˵�");
	getch();
	return head;
}
/*��������:��Ա����ģ��
��������:����ͷ�ڵ�ָ��
��������ֵ:�޸ĺ������ͷ�ڵ�ָ��*/
BOOK *returnBook(BOOK *head, int id)
{
	system("cls");
	char num1[15];
	printf("��������Ҫ������ı��:");
	scanf(" %s", num1);
	BOOK *pr1 = SearchNode1(head, num1);
	if(pr1 != NULL)
	{
		pr1->quantity++;
		member[id].bookQuantity--;
		printf("����ɹ�!\n");
		
	}
	else
	{
		printf("û���ҵ����Ϊ%s��ͼ��\n", num1);
	}
	printf("�������������һ���˵�");
	getch();
	return head;
}

void PrintMember(int ii)
{
	system("cls");
	printf("  ID\t��Ա��\t\t��Ա�绰\t��Ա���� ͼ������\tͼ��\n");
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
	printf("�������������һ���˵�");
	getch();
}





