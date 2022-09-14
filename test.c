//测试三子棋游戏

#include <stdio.h>
#include "../lib/game.c"

void menu()
{
    printf("############################\n");
    printf("#####  1.play  0.exit  #####\n");
    printf("############################\n");
}

void game()
{
    char ret = 0;
    char board[ROW][COL] = {0};
    InitBoard(board, ROW, COL);
    DisplayBoard(board,ROW,COL);
    while(1)
    {
        PlayerMove(board, ROW, COL);
        DisplayBoard(board, ROW, COL);
        ret = IsWin(board, ROW, COL);
        if(ret != 'C')
        {
            break;
        }
        ComputerMove(board, ROW, COL);
        DisplayBoard(board, ROW, COL);
        ret = IsWin(board, ROW, COL);
        if(ret != 'C')
        {
            break;
        }
    }
    if (ret == 'O')
    {
        printf("玩家赢\n");
    }
    else if(ret == 'X')
    {
        printf("电脑赢\n");
    }
    else
    {
        printf("平局\n");
    }
}

void test()
{
    int input=0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("请选择:>");
        scanf("%d",&input);
        switch(input)
        {
        case 1:
            printf("\n三子棋\n");
            game();
            break;
        case 0:
            printf("\n退出游戏\n");
            break;
        default:
            printf("选择错误，重选捏\n\n");
            break;
        }
    }while(input);
}

int main()
{
    test();
    return 0;
}