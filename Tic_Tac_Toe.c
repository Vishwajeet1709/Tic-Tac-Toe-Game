#include<stdio.h>
#include<conio.h>>
#include<windows.h>
void MultiPlayer(char arr[3][3], int a, char name);
int SmartComputer(char arr[3][3]);
void DevilComputer(char arr[3][3],char c);
int Winning(char arr[3][3],char);
void PrintArr(char arr[3][3])
{
    int i,j;
    char symbol1=196,symbol2=179;
       printf("\n\n");
   for(i=0;i<3;i++)
    {
        printf("\t ");
        for(j=0;j<3;j++)
        {
            printf(" %c ",arr[i][j]);
            if(j<2)
            {
                printf("%c",symbol2);
            }
        }
        if(i<2)
        printf("\n\t %c%c%c%c%c%c%c%c%c%c%c\n",symbol1,symbol1,symbol1,symbol2,symbol1,symbol1,symbol1,symbol2,symbol1,symbol1,symbol1);
    }
}
int main()
{
    int choice,i,j;
    char move,name[20],c,player1[20],player2[20],arr[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};

    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,3);

    printf("\n\n\tEnter your name : ");
    gets(name);
    strupr(name);
    system("cls");

    printf("\n\n\tWELCOME %s, IN OUR TIC TAC TOE GAME!\n",name);
    SetConsoleTextAttribute(h,4);
    printf("\n\t Enter your choice.\n\t 01. Multi player.\n\t 02. Smart Computer.\n\t 03. Devil Computer.\n\t 04. Exit\n\t ");
    scanf("%d",&choice);
    SetConsoleTextAttribute(h,5);
    PrintArr(arr);
    printf("\nEnter a key to continue the game : ");
    getch();
    switch(choice)
    {
        case 1 : SetConsoleTextAttribute(h,2);
                 system("cls");
                 printf("\n\tMulti player\n");
                 printf("\n\tEnter the name of player 1 (for O) : ");
                 scanf("%s",&player1);
                 printf("\n\tEnter the name of player 2 (For X) : ");
                 scanf("%s",&player2);

            for(i=1;i<10;i++)
                {
                system("cls");
                PrintArr(arr);
                if(i%2)
                {
                    printf("\n\nEnter your move %s (player O) : ",player1);
                }
                else
                {
                    printf("\n\nEnter your move %s (player X) : ",player2);
                }
                scanf("%s",&move);
                MultiPlayer(arr,i,move);
                if(Winning(arr,'O'))
                {
                    system("cls");
                    PrintArr(arr);
                    printf("\n\nCongratulation %s, you have won the game.\n\n",player1);
                    getch();
                    return 0;
                }
                else if(Winning(arr,'X'))
                    {
                        system("cls");
                        PrintArr(arr);
                        printf("\n\nCongratulation %s, you have won the game.\n\n",player2);
                        getch();
                        return 0;
                    }
                }
                system("cls");
                PrintArr(arr);
                printf("\n\n\tMatch Draw!!!\n\n");
                getch();
        break;
        case 2 :SetConsoleTextAttribute(h,7);
                system("cls");
                printf("\nSmart Computer\n");
                while(1)
                {
                    system("cls");
                    PrintArr(arr);
                    printf("\n\nEnter your move %s (player O) : ",name);
                    scanf("%c",&move);
                    MultiPlayer(arr, 1, move);
                    if(Winning(arr,'O'))
                    {
                        system("cls");
                        PrintArr(arr);
                        printf("\n\nCongratulation You Have Won The game.\n\n");
                        break;
                    }
                    SmartComputer(arr);
                    if(Winning(arr,'X'))
                    {
                        system("cls");
                        PrintArr(arr);
                        printf("\n\nYou lose, Better Luck Next Time.\n\n");
                        break;
                    }
                }

        break;
        case 3 : printf("\n\tDevil Computer\n");
        break;
        case 4 : printf("\n\tExit\n");
        default : printf("\n\tInvalid Choice");
    }
    return 0;
}
void MultiPlayer(char arr[3][3], int player, char move)
{
   int i,j;
   for(i=0;i<3;i++)
   {
       for(j=0;j<3;j++)
       {
           if(arr[i][j]==move)
           {
               if(player%2)
               {
                   arr[i][j]='O';
               }
               else
               {
                   arr[i][j]='X';
               }
           }
       }
   }
}
int Winning(char a[3][3], char value)
{
    int i;
    for(i=0;i<3;i++)
    {
        if(a[i][0]==value && a[i][0]==a[i][1] && a[i][1]==a[i][2])
            return 1;
    }
    for(i=0;i<3;i++)
    {
        if(a[0][i]==value && a[0][i]==a[1][i] && a[1][i]==a[2][i])
            return 1;
    }
    if(a[0][0]==value && a[0][0]==a[1][1] && a[1][1]==a[2][2])
        {
            return 1;
        }
    else if(a[0][2]==value && a[0][2]==a[1][1] && a[1][1]==a[2][0])
        {
            return 1;
        }

    return 0;
}
int SmartComputer(char a[3][3])
{
    int i;
    for(i=0;i<3;i++)
    {
        if(a[i][0]==a[i][1] && a[i][2]!='O')
            {
                a[i][2]='X';
                printf("Working 8");getch();
                return 0;
            }
        else if(a[i][1]==a[i][2] && a[i][0]!='O')
            {
                a[i][0]='X';
                return 0;
            }
        else if(a[i][0]==a[i][2] && a[i][1]!='O')
            {
                a[i][1]='X';
                return 0;
            }
    }
    for(i=0;i<3;i++)
    {
        if(a[0][i]==a[1][i] && a[2][i]!='O')
            {
                a[2][i]='X';
                return 0;
            }
        else if(a[1][i]==a[2][i] && a[0][i]!='O')
            {
                a[0][i]='X';
                return 0;
            }
        else if(a[0][i]==a[2][i])
            {
                a[1][i]='X';
                return 0;
            }
    }
    if(a[0][0]==a[2][2] || a[0][2]==a[2][0] && a[1][1]!='O')
    {
        a[1][1]='X';
        return 0;
    }
}
