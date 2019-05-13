#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count;
int guess_number;
int guess_number_size;

int init(int user_count, int user_guess_number)
{
    srand(time(NULL));
    guess_number_size = user_guess_number;
    if (user_count == 0) 
    {
        count = 5;
    }
    else 
    {
        count = user_count;
    }
    if (user_guess_number == 0) 
    {
        guess_number = rand() % 11;
    }
    else
    {
        guess_number = rand() % user_guess_number;
    }
    printf("初始化完成!\n");
    return count,guess_number,guess_number_size;
}

int game(void)
{
    int answer;
    int p_count = count;
    while(1)
    {
        scanf("%*[^\n]%*c");
        printf("你有%d次机会猜%d以内的数字!请开始你的表演: ",count,guess_number_size);
        if (scanf("%d",&answer) != 1)
        {
            printf("输入无效!\n");
            continue;
        }
        else
        {
            if (answer == guess_number)
            {
                printf("恭喜你!猜对了，正确答案是%d\n",guess_number);
                break;
            }
            else if (answer > guess_number)
            {
                printf("你的数字有点大!\n");
                p_count--;
                continue;
            }
            else if (answer < guess_number)
            {
                printf("你的数字有点小!\n");
                p_count--;
                continue;
            }
            else if (p_count == 0)
            {
                printf("不好意思，你的次数用完了!\n");
                menu();
            }
            else
            {
                printf("不对哦!\n");
                p_count--;
                continue;
            }
        }
    }
    return 0;
}

int game_set(void)
{
    int user_select;
    int user_count;
    int user_size;
    while(1)
    {
        scanf("%*[^\n]%*c");
        printf("(1)更改数字大小\n(2)更改尝试次数\n(0)确认并返回\n");
        printf("请选择: ");
        if (scanf("%d",&user_select) != 1)
        {
            continue;
        }
        else
        {
            if (user_select == 1) 
            {
                printf("请输入要改变的值: ");
                if (scanf("%d",&user_size) != 1)
                {
                    printf("输入错误!\n");
                    continue;
                }
                else
                {
                    printf("数字大小更改完成!\n");
                }
            }
            else if (user_select == 2)
            {
                printf("请输入更改的数值: ");
                if (scanf("%d",&user_count) != 1)
                {
                    printf("输入错误 !\n");
                    continue;
                }
                else
                {
                    printf("尝试数值更改完成!\n");
                }
            }
            else if (user_select == 0)
            {
                menu();
            }
            else
            {
                printf("输入不可识别!\n");
                return 1;
            }
        }
    }
    init(user_count,user_size);
    return 0;
}

int menu(void)
{
    int user_select;
    while(1)
    {
        scanf("%*[^\n}%*c");
        printf("(1)开始游戏\n(2)游戏设置\n(0)退出游戏\n");
        printf("请选择: ");
        if (scanf("%d",&user_select) != 1)
        {
            printf("无效输入!\n");
            continue;
        }
        else
        {
            if (user_select == 1)
            {
                game();
            }
            else if (user_select == 2)
            {
                game_set();
            }
            else if (user_select == 0)
            {
                exit(0);
                return 0;
            }
            else
            {
                printf("选项不可识别!\n");
                continue;
            }
        }
    }
    return 0;
}


int main(void)
{
    printf("count = %d\tgame_number = %d\tgame_number_size = %d\n",count,guess_number,guess_number_size);
    init(0,0);
    printf("count = %d\tgame_number = %d\tgame_number_size = %d\n",count,guess_number,guess_number_size);

    menu();
    return 0;
}
