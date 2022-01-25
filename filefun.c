#include"filefun.h"
/*��������:������ͼ����Ϣ����������д���ı��ĵ���
��������:����ͷ�ڵ�ָ��
��������ֵ:��*/
void WritetoFile1(BOOK *head)
{
	FILE *fp;
	BOOK *p = head;
	if((fp = fopen("bookdata.txt", "w")) == NULL)   //�����ļ��Ƿ�򿪳ɹ�
    {
        printf("�ļ���ʧ��!\n");
        exit(0);
    }
	while(p != NULL)
	{
		fprintf(fp, "%s %s %s %d %f\n", p->number, p->name, p->author, p->quantity, p->price); //���ļ���д������
		p = p->next;
	}
	fclose(fp); //�ر��ļ�
}
/*��������:���ļ��ж�ȡ��Ϣ
��������:����ͷ�ڵ�ָ��
��������ֵ:����ͷ�ڵ�ָ��*/
BOOK *ReadfromFile1(BOOK *head)
{
	FILE *fp;
	if((fp = fopen("bookdata.txt", "r")) == NULL)  //����ļ��Ƿ�򿪳ɹ�����ʧ���򷵻�NULL
    {                                          //ʧ������Ϊ���ļ���δ������Ҳ���������� 
        return NULL;
    }
    while(!feof(fp))
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
		fscanf(fp, "%s %s %s %d %f", p->number, p->name, p->author, &p->quantity, &p->price);
		pr->next = NULL;
	}
    fclose(fp);
    return head;
}
/*��������:����Ա��Ϣд���ı��ļ�
��������:��Ա����
��������ֵ:��*/
void WritetoFile2(int ii, MEM member[300])
{
	FILE *fp;
	if((fp = fopen("memberdata.txt", "w")) == NULL)   //�����ļ��Ƿ�򿪳ɹ�
    {
        printf("�ļ���ʧ��!\n");
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
/*��������:���ı��ĵ��ж�ȡ��Ϣ
��������:��Ա�����ͽṹ������
��������ֵ:�ṹ�������׵�ַ*/
MEM *ReadfromFile(int ii, MEM member[300])
{
	FILE *fp;
	if((fp = fopen("bookdata.txt", "r")) == NULL)  //����ļ��Ƿ�򿪳ɹ�����ʧ���򷵻�NULL
    {                                          //ʧ������Ϊ���ļ���δ������Ҳ���������� 
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




