#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int total=48;
int turnFlag=2;
int chessBoard[6][8];
int init();
int playChess();
int showChessBoard();
int main()
{
    int i,j,win=0;
    init();
    while(total!=0&&win==0)
    {
        playChess();
        for(i=5;i>=0;i--)
        {
            for(j=0;j<8;j++)
            {
                if(j>=0&&j<=4&&i>=3&&i<=5)
                {
                    if(chessBoard[i][j]==chessBoard[i-1][j+1]&&chessBoard[i-1][j+1]==chessBoard[i-2][j+2]&&chessBoard[i-2][j+2]==chessBoard[i-3][j+3])
                    {
                        if(chessBoard[i][j]==1)
                        {
                            win=1;
                            break;
                        }
                        else if(chessBoard[i][j]==2)
                        {
                            win=2;
                            break;
                        }
                    }
                }
                if(i>=3&&i<=5)
                {
                    if(chessBoard[i][j]==chessBoard[i-1][j]&&chessBoard[i-1][j]==chessBoard[i-2][j]&&chessBoard[i-2][j]==chessBoard[i-3][j])
                    {
                        if(chessBoard[i][j]==1)
                        {
                            win=1;
                            break;
                        }
                        else if(chessBoard[i][j]==2)
                        {
                            win=2;
                            break;
                        }
                    }
                }
               if(j>=0&&j<=4)
                {
                    if(chessBoard[i][j]==chessBoard[i][j+1]&&chessBoard[i][j+1]==chessBoard[i][j+2]&&chessBoard[i][j+2]==chessBoard[i][j+3])
                    {
                        if(chessBoard[i][j]==1)
                        {
                            win=1;
                            break;
                        }
                        else if(chessBoard[i][j]==2)
                        {
                            win=2;
                            break;
                        }
                    }
                }
            }
        }
    }
    if(win==1)
        printf("*******Ү����Ӯ�ˣ�\n");
    else if(win==2)
        printf("*******�ðɣ���Ӯ�ˣ�");
    else
        printf("�ѷ�ʤ����");
    return 0;
}

int init()
{
    int i;
    printf("��ʼ�ˣ��������̵ĳ�ʼ״̬��\n");
    printf(" 1 2 3 4 5 6 7 8 \n");
    for(i=0;i<6;i++)
    {
        printf("| | | | | | | | |\n");
    }
    printf("-----------------\n\n");
    return 1;
}

int playChess()
{
    int i,complete=0,pure=0;
    char colum;
    if(turnFlag%2==0)
    {
        printf(">>>�ֵ����ˣ��Ұ� 0 ���ӷ��ڵ�");
        do
        {
            srand((unsigned)time(NULL));
            int temp=rand()%8;
            for(i=0;i<6;i++)
            {
                if(chessBoard[i][temp]==0)
                {
                    chessBoard[i][temp]=1;
                    printf("%d��...\n",temp+1);
                    showChessBoard();
                    complete=1;
                    break;
                }
            }
        }while(complete==0);
        complete=0;
        turnFlag++;
        total--;
    }
    else
    {
        do
        {
            if((colum>56||colum<49)&&pure!=0)
            {
                printf("\n������һ��1-8��������\n\n");
            }
            else if(chessBoard[5][colum-49]!=0)
            {
                printf("\n����������������ѡ��һ�У�");
            }
            printf(">>>�ֵ����ˣ����x���ӣ���ѡ���кţ�1-8����");
            scanf("%c",&colum);
            fflush(stdin);
            pure=1;
        }while(colum>56||colum<49||chessBoard[5][colum-49]!=0);
        pure=0;
        for(i=0;i<6;i++)
        {
            if(chessBoard[i][colum-49]==0)
            {
                chessBoard[i][colum-49]=2;
                showChessBoard();
                break;
            }
        }
        turnFlag++;
        total--;
    }
    return 1;
}

int showChessBoard()
{
    int i,j;
    printf(" 1 2 3 4 5 6 7 8 \n");
    printf("|");
    for(i=5;i>=0;i--)
    {
        for(j=0;j<8;j++)
        {
            if(chessBoard[i][j]==1)
            {
                printf("0|");
            }
            else if(chessBoard[i][j]==2)
            {
                printf("x|");
            }
            else
            {
                printf(" |");
            }
            if(j==7)
            {
                 if(i!=0)
                 printf("\n|");
                 else
                 {
                      printf("\n-----------------\n\n");
                 }
            }
        }
    }
    return 1;
}







