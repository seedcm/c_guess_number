#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int init(int init_count, int init_question_size)
{
    int count;
    int question;
    int question_size;
    
    srand(time(NULL));

    if (init_count == 0)
    {
        count = 5;
    }
    else
    {
        count = init_count;
    }
    if (init_question_size == 0)
    {
        question_size = 11;
    }
    else
    {
        question_size = init_question_size + 1;
    }
    question = rand() % question_size;
    
    game(count,question,question_size);
}

int game_set(void)
{
    int set_count = 0;
    int set_question_size = 0;

    while(1)
    {
        printf("请设置尝试次数: ");
        if (scanf("%d",&set_count) == 1)
        {
            printf("次数设置成功!\n");
        }
        else
        {
            scanf("%*[^\n]%*c");
            printf("无效输入!\n");
            continue;
        }
        printf("请设置数字范围: ");
        if (scanf("%d",&set_question_size) == 1)
        {
            printf("范围设置成功!\n");
        }
        else
        {
            scanf("%*[^\n]%*c");
            printf("无效输入!\n");
            continue;
        }
        printf("游戏设置已更新,回车进入游戏!\n");
        getchar();
        break;
    }

    init(set_count,set_question_size);
}

int game(int game_count, int game_question, int game_question_size)
{
    int answer;
    int count;
    count = game_count;

    while (count != 0)
    {
        scanf("%*[^\n]%*c");
        if (count != 1)
        {
            printf("你有%d次机会猜测%d以内的数字,请开始你的表演: ",count,game_question_size - 1);
        }
        else
        {
            printf("你还有最后一次机会咯,想清楚哦: ");
        }
        if (scanf("%d",&answer) != 1)
        {
            printf("无效输入!\n");
            continue;
        }
        else
        {
            if (answer < game_question)
            {
                printf("你给的数字小咯!\n");
                count --;
                continue;
            }
            else if (answer > game_question)
            {
                printf("你给的数字大咯!\n");
                count --;
                continue;
            }
            else
            {
                printf("哎哟不错哦！你猜对了！正确答案%d\n",game_question);
                break;
            }
        }
    }
    printf("游戏结束咯!\n");
    return 0;
}

int main(void)
{
    int user_select;
    while(1)
    {
        scanf("%*[^\n]%*c");
        printf("欢迎来到猜数字游戏!\n");
        printf("(1)开始游戏\t(2)游戏设置\t(0)退出游戏\n请选择: ");
        if (scanf("%d",&user_select) != 1)
        {
            printf("无效输入!\n");
            continue;
        }
        else
        {
            if (user_select == 1)
            {
                init(0,0);
            }
            if (user_select == 2)
            {
                game_set();
            }
            if (user_select == 0)
            {
                exit(0);
                return 0;
            }
        }
    }
    return 0;
}
