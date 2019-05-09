// 猜数字

#include <stdlib.h>     // 包含srand函数
#include <stdio.h>
#include <time.h>       // 为随机数提供随机种子
#define SIZE 11         // 十以内的数字,101为一百以内，1001为一千以内，10001为一万以内。
#define COUNT 5         // 设置尝试次数

int main(int argc,char** argv)        // (待补充)程序开始前可设置数字范围大小
{
    int guess, answer, size, count, parameter;

    if (argc == 2)      // 判断带参数执行的参数个数是否为1
    {
        if ((parameter = atoi(argv[1])) != 0)       // 判断参数是否为int型
        {
            size = parameter;       // 为int型则使用参数值
        }
        else
        {
            size = SIZE;        // 否则使用定义值
        }
    }
    else
    {
        size = SIZE;
    }

    // 获取随机数
    srand(time(NULL));      // 创建随机数种子
    guess = rand() % size;    // 创建一定范围内的随机数并赋值给整型变量guess
    count = COUNT;

    // 循环体开始
    while (count != 0)
    {
        printf("你有%d次机会尝试猜出%d以内的正确数字：",count,size - 1);
        if (scanf("%d",&answer) != 1)   // 判断输入的值类型是否正确
        {
            printf("值类型错误!请重试!\n");
            scanf("%*[^\n]*c");     // **清除缓冲区数据，避免造成死循环**
            continue;
        }
        else if (guess == answer)
        {
            printf("恭喜你猜对了!正确答案是%d!\n",guess);
            break;
        }
        else
        {
            if (answer > guess)
            {
                printf("你猜的数字太大了!");
            }
            else
            {
                printf("你猜的数字太小了!");
            }
            printf("加油哦！");
            continue;
        }
    }

    return 0;
}


