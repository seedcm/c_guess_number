#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/* 设置全局变量 */
int guess;              // 答案
int number_size;        // 需要猜测的数字大小的范围
int count;              // 可以尝试的次数
int arg_number_size;    // 参数设置数字大小的范围
int arg_count;          // 参数设置可尝试的次数
int set_number_size;    // 程序内设置数字大小的范围
int set_count;          // 程序内设置可尝试的次数
int tmp;                // 临时公用变量

/* 函数声明 */
int main_menu(void);    // 主菜单函数声明
int set_menu(void);     // 设置菜单函数声明
int game(void);         // 游戏函数声明

/* 主函数 */
int main(int argc, char** argv)
{
    int fun_main_menu;  // 主菜单--函数用变量声明
    int fun_set_menu;   // 设置菜单函数--用变量声明
    int fun_game;       // 游戏函数--变量声明

    /* 设置默认变量值 */
    number_size = 11;                   // 创建默认数字大小范围值
    count = 5;                          // 创建默认尝试次数值
    srand(time(NULL));                  // 为随机数提供随机种子
    guess = rand() % number_size;       // 利用随机种子创建默认随机数

    /* 检查是否带参数运行 */
    if (argc != 1)
    {
        /* 检查并设置参数变量值 */
        if((arg_number_size = atoi(argv[1])) == 0 && (arg_count = atoi(argv[2]) == 0))
        {
            arg_number_size = atoi(argv[1]);
            arg_count = atoi(argv[2]);
        }
        else
        {
            if ((arg_number_size = atoi(argv[1])) == 0)
            {
                arg_number_size = atoi(argv[1]);
            }
            else
            {
                ;
            }
        }
    }
    else
    {
        /* 进入主菜单函数 */
        fun_main_menu = main_menu();
    }

    return 0;
}

/* 主菜单函数 */
int main_menu(void)
{
    int fun_set_menu;   // 设置菜单函数--用变量声明
    int fun_game;       // 游戏函数--变量声明
    int menu;           // 主菜单变量

    /* 主菜单循环 */
    while (1)
    {
        /* 菜单选项 */
        printf("(1) 开始游戏\n(2) 游戏设置\n(0) 退出游戏\n");
        printf("请选择对应的序号开始: ");
        if ((scanf("%d",&menu)) == 1 || menu != 1 || menu != 2 || menu != 0)
        {
            continue;
        }
        else
        {
            if (menu == 1)
            {
                fun_game = game();
                break;
            }
            else if (menu == 2)
            {
                fun_set_menu = set_menu();
                break;
            }
            else
            {
                return 0;
            }
        }
    }
}
/* 设置菜单函数 */
int set_menu(void)
{
    printf("I am a set_menu\n");
}

/* 游戏函数 */
int game(void)
{
    printf("I am a game\n");
}

