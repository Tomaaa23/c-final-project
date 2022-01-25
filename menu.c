#include"menu.h"

void startMenu(void)
{
	system("cls");
	printf("\t\t\t*==============================================*\n");
    printf("\t\t\t| | * - * - * - * 图书管理系统 * - * - * - * | |\n");
    printf("\t\t\t| *                                          * |\n");
    printf("\t\t\t| | [1] 会员登录                             | |\n");
    printf("\t\t\t| * [2] 会员注册                             * |\n");
    printf("\t\t\t| | [3] 管理员登录                           | |\n");
    printf("\t\t\t| * [4] 关于                                 * |\n");
    printf("\t\t\t| | [5] 帮助                                 | |\n");
    printf("\t\t\t| * [6] 退出系统                             * |\n");
    printf("\t\t\t*==============================================*\n");
    printf("你的选择是:");
} 
void librarianMenu(void)
{
    system("cls");
    printf("\t\t\t*============================================*\n");
    printf("\t\t\t| | * - * - * - * 管理员界面 * - * - * - * | |\n");
    printf("\t\t\t| *                                        * |\n");
    printf("\t\t\t| | [1] 添加图书                           | |\n");
    printf("\t\t\t| * [2] 删除图书                           * |\n");
    printf("\t\t\t| | [3] 查找图书信息                       | |\n");
    printf("\t\t\t| * [4] 显示所有图书信息                   * |\n");
    printf("\t\t\t| | [5] 显示所有会员信息                   | |\n");
    printf("\t\t\t| * [6] 退出管理员界面                     * |\n");
    printf("\t\t\t*============================================*\n");
    printf("你的选择是:");
}
void memberMenu(void)
{
	system("cls");
    printf("\t\t\t*==========================================*\n");
    printf("\t\t\t| | * - * - * - * 会员界面 * - * - * - * | |\n");
    printf("\t\t\t| *                                      * |\n");
    printf("\t\t\t| | [1] 查找图书                         | |\n");
    printf("\t\t\t| * [2] 借书                             * |\n");
    printf("\t\t\t| | [3] 还书                             | |\n");
    printf("\t\t\t| | [4] 显示所有图书信息                 | |\n");
    printf("\t\t\t| * [5] 退出会员界面                     * |\n");
    printf("\t\t\t*==========================================*\n");
	printf("你的选择是:");
}
