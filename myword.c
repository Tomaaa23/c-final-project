#include"myword.h"

/*函数功能:"关于"的话
函数参数:无 
函数返回值:无*/
void about(void)
{
	system("cls");
	system("color 3f");
	printf("程序名称：图书管理系统\n");
	printf("版本：1.0\n");
	printf("开发时间：2022.1.6\n");
	printf("开发者信息:\n");
	printf("南昌大学2021级计算机Ⅱ类2102班胡志康，学号8008121053\n");
	printf("我的邮箱：tomaaa23@163.com，可以通过邮箱与我交流讨论\n");
	printf("我的博客:tomaaa23.github.io，有兴趣可以去看看，我偶尔会发文章记一些笔记或者记录我的生活\n");
	printf("按任意键返回上一级菜单");
	getch();
}
/*函数功能:"帮助"的话
函数参数:无
函数返回值:无*/
void help(void)
{
	system("cls");
	system("color 3f");
	printf("本程序是c语言大作业图书管理系统\n");
	printf("有图书管理员和用户两种使用人，图书管理员账号唯一密码是我的名字首字母加生日(hzk20030818)\n");
	printf("会员账号可以注册，第几个注册id就是多少\n");
	printf("管理员可以添加删除查看图书信息，也可以查看会员信息\n");
	printf("会员可以借书还书查看图书信息\n");
	printf("本程序的每一步均有提示帮助你使用该系统\n");
	printf("按任意键返回上一级菜单");
	getch();
}
