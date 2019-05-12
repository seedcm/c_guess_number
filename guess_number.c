#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int game(void);
int game_set(void);

int main(void)
{
    while(1)
    {
        int ext;

        if (ext == 0)
        {
            break;
        }
        else if (ext == 1)
        {
            continue;
        }
        else
        {
            printf("(1) 开始游戏\n(2) 游戏设置\n(0) 退出游戏\n");
            scanf("%d",&menu_select);

            if (menu_select == 1)
            {
                ext = game();
            }
            else if (menu_select == 2)
            {
                ext = game_set();
            }
            else if (menu_select == 0)
            {
                exit(0);
                return 0;
            }
            else
            {
                continue;
            }
            break;
        }
    }
    return 0;
}

int game_set(void)
{
    int ext;

    while(1)
    {
        if (ext == 1)
        {
            break;
        }
        else if (ext == 0)
        {
            return 1;
        }
        else
        {
            printf("(1) 设置猜测范围\n(2) 设置可尝试次数\n(0) 返回主菜单\n");
            if (scanf("%d",&ext) != 1)
            {
                printf("无效输入!");
                continue;
            }
            else
            {
                if (ext == 1)
                {
                    printf("请输入范围: ");
                    scanf("%d",&size);


                
            
