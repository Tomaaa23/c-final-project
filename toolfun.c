#include"toolfun.h"

/*��������:�½�һ���ڵ���ӵ�����ĩβ 
��������:����ͷ�ڵ�ָ��
��������ֵ:��ӽڵ�������ͷ�ڵ�ָ��*/
BOOK *AppendNode(BOOK *head)
{
	BOOK *p = NULL;
	BOOK *pr = head;
	p = (BOOK *)malloc(sizeof(BOOK)); //Ϊ�½��ڵ������ڴ� 
	if(p == NULL)
	{
		printf("û���㹻���ڴ���!\n");
		exit(0);
	}
	if(head == NULL) //��Ϊ�ձ�����Ϊ�׽ڵ� 
	{
		head = p;
	}
	else
	{
		while(pr->next != NULL) //��Ϊ�ǿգ�����ӵ�����ĩβ 
		{
			pr = pr->next;
		}
		pr->next = p;
	}
	pr = p;
	printf("������ͼ����Ϣ...\n");
	printf("ͼ����:");
	scanf("%s", p->number);
	printf("����:");
	scanf(" %s", p->name);
	printf("������:");
	scanf(" %s", p->author);
	printf("ͼ������:");
	scanf("%d", &p->quantity);
	printf("�г��۸�:");
	scanf("%lf", &p->price);
	pr->next = NULL;
	return head;
}
/*��������:����ͼ���Ų���ͼ��
��������:����ͷ�ڵ�ָ�룬Ŀ��ͼ����
��������ֵ:�ҵ���Ϊ�����ͼ����Ϣ�Ľڵ�ָ�룬û�ҵ���ΪNULL*/
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
/*��������:����ͼ��������ͼ��
��������:����ͷ�ڵ�ָ�룬Ŀ��ͼ���� 
��������ֵ:�ҵ���Ϊ�����ͼ����Ϣ�Ľڵ�ָ�룬û�ҵ���ΪNULL*/
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
/*��������:ѡ�����ͼ���Ż���ͼ��������ͼ��
��������:����ͷ�ڵ�ָ��
��������ֵ:��*/
void SearchData(BOOK *head)
{
	system("cls");
	printf("1.����ͼ���������� 2.����ͼ����������\n���ѡ����:");
	char c;
	c = getch();
	while(c != '1' && c != '2')
	{
		c = getch();
	}
	printf("%c\n", c);
	if(c == '1')
	{
		printf("ͼ����:");
		char str1[15];
		scanf(" %s", str1);
		BOOK *pr1;
		pr1 = SearchNode1(head, str1);
		if(pr1 != NULL)
		{
			printf("\t���\t\t����\t\t������ ���� �г���\n");
			printf("%12s%16s%18s%4d%8.2f\n", pr1->number, pr1->name, pr1->author, pr1->quantity, pr1->price);
		}
		else
		{
			printf("û���ҵ����Ϊ%s��ͼ��\n", str1);
		}
	}
	else if(c == '2')
	{
		printf("ͼ����:");
		char str2[30];
		scanf(" %s", str2);
		BOOK *pr2;
		pr2 = SearchNode1(head, str2);
		if(pr2 != NULL)
		{
			printf("\t���\t\t����\t\t������ ���� �г���\n");
			printf("%12s%16s%18s%4d%8.2f\n", pr2->number, pr2->name, pr2->author, pr2->quantity, pr2->price);
		}
		else
		{
			printf("û���ҵ�����Ϊ%s��ͼ��\n", str2);
		}
	}
	printf("�������������һ���˵�\n");
	getch();
	
}
/*��������:����ͼ����ɾ��ͼ����Ϣ
��������:����ͷ�ڵ�ָ�룬Ŀ��ͼ����
��������ֵ:ɾ���������ͷ�ڵ�ָ��*/ 
BOOK *DeleteNode1(BOOK *head, const char nodeNum[15])
{
	BOOK *p = head, *pr = head;
	if(head = NULL)
	{
		printf("û����Ϣ\n");
		return head;
	}
	while(strcmp(nodeNum, p->number) && p->next != NULL) //������������ 
	{
		pr = p;
		p = p->next;
	}
	if(!strcmp(nodeNum, p->number)) //���ҵ���ɾ�� 
	{
		if(p = head)  //��Ŀ��ڵ�Ϊ�׽ڵ㣬��headָ��ڶ����ڵ� 
		{
			head = p->next;
		}
		else          //��Ŀ��ڵ㲻���׽ڵ㣬��ǰһ�ڵ�ָ��ָ��ǰ�ڵ����һ�ڵ�
		{
			pr->next = p->next;
		}
		free(p);  //�ͷ�ɾ���ڵ���ڴ�
		printf("ɾ���ɹ�!\n");
	}
	else  //û�ҵ��������ʾ 
	{
		printf("û���ҵ����Ϊ%s��ͼ��", nodeNum);
	}
	
	return head;
}
/*��������:����ͼ����ɾ��ͼ����Ϣ
��������:����ͷ�ڵ�ָ�룬Ŀ��ͼ���� 
��������ֵ:ɾ���������ͷ�ڵ�ָ��*/ 
BOOK *DeleteNode2(BOOK *head, const char nodeName[30])
{
	BOOK *p = head, *pr = head;
	if(head = NULL)
	{
		printf("û����Ϣ\n");
		return head;
	}
	while(strcmp(nodeName, p->name) && p->next != NULL) //������������ 
	{
		pr = p;
		p = p->next;
	}
	if(!strcmp(nodeName, p->name)) //���ҵ���ɾ�� 
	{
		if(p = head)  //��Ŀ��ڵ�Ϊ�׽ڵ㣬��headָ��ڶ����ڵ� 
		{
			head = p->next;
		}
		else          //��Ŀ��ڵ㲻���׽ڵ㣬��ǰһ�ڵ�ָ��ָ��ǰ�ڵ����һ�ڵ� 
		{
			pr->next = p->next;
		}
		free(p);  //�ͷ�ɾ���ڵ���ڴ� 
		printf("ɾ���ɹ�!\n");
	}
	else  //û�ҵ��������ʾ 
	{
		printf("û���ҵ�����Ϊ%s��ͼ��", nodeName);
	}
	
	return head;
}
/*��������:��ӡͼ����Ϣ
��������:����ͷ�ڵ�ָ��
��������ֵ:��*/ 
void PrintData(BOOK *head)
{
	system("cls");
	BOOK *p = head;
	printf("\t���\t\t����\t\t������ ���� �г���\n");
	while(p != NULL) //�������� 
	{
		printf("%12s%16s%18s%4d%8.2f\n", p->number, p->name, p->author, p->quantity, p->price);
		p = p->next;
	}
	printf("�������������һ���˵�\n");
	getch();
}
/*��������:�����������ͼ����Ϣ
��������:����ͷ�ڵ�ָ��
��������ֵ:�����Ϣ�������ͷ�ڵ�ָ��*/
BOOK *AppendData(BOOK *head)
{
	system("cls");
	int i = 0;
	char ch;
	do
	{
		head = AppendNode(head);
		printf("��Ҫ�������ͼ����Ϣ��(y/n)?");
		ch = getch();
		while(ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n')
		{
			ch = getch();
		}
		printf("%c\n", ch);
		i++;
	}while(ch == 'Y' || ch == 'y');
	printf("%d��ͼ����Ϣ��¼��ϵͳ!\n", i);
	return head;
}
/*��������:ѡ�����ͼ���Ż���ͼ������ɾ��ͼ����Ϣ
��������:����ͷ�ڵ�ָ��
��������ֵ:ɾ����Ϣ�������ͷ�ڵ�ָ��*/
BOOK *DeleteData(BOOK *head)
{
	system("cls");
	char c;
	printf("1.����ͼ����ɾ�� 2.����ͼ����ɾ��\n���ѡ����:");
	c = getch();
	while(c != '1' && c != '2')
	{
		c = getch();
	}
	printf("%c\n", c);
	if(c == '1')
	{
		printf("������ͼ����:");
		char str1[15];
		scanf(" %s", str1);
		DeleteNode1(head, str1);
	}
	else if(c == '2')
	{
		printf("����������:");
		char str2[30];
		scanf(" %s", str2);
		DeleteNode2(head, str2);
	}
	printf("���������������һ���˵�\n");
	getch();
	return head;
}




