#include"main.h"
#include"menu.h" 
#include"toolfun.h"
#include"librarian.h"
#include"member.h"
#include"myword.h"
#include"filefun.h"
int memberNumber = 0;
int main()
{
	BOOK *head = NULL;
	head = ReadfromFile1(head);
	while(1)
	{
		system("color 2F");
		startMenu();
		char ch;
		ch = getch();
		while(ch != '1' && ch != '2' && ch != '3' && ch != '4' && ch != '5' && ch != '6')
		{
			ch = getch();
		}
		printf("%c", ch);
		if(ch == '1')
		{
			head = memberModule(head);
		}
		else if(ch == '2')
		{
			memberNumber = logup();
		}
		else if(ch == '3')
		{
			head = librarianModule(head, memberNumber);
		}
		else if(ch == '4')
		{
			about(); 
		}
		else if(ch == '5')
		{
			help();
		}
		else if(ch == '6')
		{
			break;
		}
	}
	WritetoFile1(head);
	WritetoFile2(memberNumber, member);
	
    return 0;
}
