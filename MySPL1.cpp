#include <bits/stdc++.h>
#include <conio.h>
//#include<stdlib.h>
#include <windows.h>
#define RowNum 23
#define ColNum 75
using namespace std;

typedef struct
{
    int row;
    int column;
} location;

void PrintMaze(char Maze[][ColNum+1], int row, int column);
int getInput();

void addColumn(location *ghost, int *change, int *dead, int *foodToken, char maze[RowNum][ColNum+1]);
void cutColumn(location *ghost, int *change, int *dead, int *foodToken, char maze[RowNum][ColNum+1]);
void addRow(location *ghost, int *change, int *dead, int *foodToken, char maze[RowNum][ColNum+1]);
void cutRow(location *ghost, int *change, int *dead, int *foodToken, char maze[RowNum][ColNum+1]);

void runGame()
{
    while(1)
    {
        int row = 23, column = 75;
        int input = 0;
        int food = 245;
        int moveCount = 0;
        int proceed = 0; //printFlag
        int dead = 0; //deathFlag
        int change = 0;//changeFlag
        int random;

        int foodToken1 = 0;
        int foodToken2 = 0;
        int foodToken3 = 0;
        int foodToken4 = 0;

        char Maze[row][(ColNum+1)] = {
            "###########################################################################",
            "# - - G - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - G - - #",
            "########### - - ######### - - ######### - - ################# - - #########",
            "#         # - - ######### - - ######### - - ################# - - #       #",
            "#         # - - ######### - - ######### - - ################# - - #       #",
            "#         # - - - ##### - - - - ##### - - - - - - ##### - - - - - #       #",
            "#         # - - - ##### - ### - ##### - ####### - ##### - - - - - #       #",
            "#         ##### - ##### - ### - ##### - #     # - ##### - #########       #",
            "#             # - ##### - ### - ##### - #     # - ##### - #               #",
            "#             # - ##### - ### - ##### - #     # - ##### - #               #",
            "#             # - ##### - ### - ##### - ####### - ##### - #               #",
            "#             # - - - - - - - - - - - @ - - - - - - - - - #               #",
            "#             # - ##### - ### - ##### - ####### - ##### - #               #",
            "#             # - ##### - ### - ##### - #     # - ##### - #               #",
            "#             # - ##### - ### - ##### - #     # - ##### - #               #",
            "#         ##### - ##### - ### - ##### - #     # - ##### - #########       #",
            "#         # - - - ##### - ### - ##### - ####### - ##### - - - - - #       #",
            "#         # - - - ##### - - - - ##### - - - # - - ##### - - ### - #       #",
            "#         # - - ######### - - ######### - - # - - ##### - - # # - #       #",
            "#         # - - ######### - - ######### - - # - - ##### - - # # - #       #",
            "########### - - ######### - - ######### - - # - - ##### - - ### - #########",
            "# - - G - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - G - - #",
            "###########################################################################"
            };

        location pacman;
        pacman.row = 11;
        pacman.column = 38;

        location ghost1;
        ghost1.row = 1;
        ghost1.column = 6;

        location ghost2;
        ghost2.row = 1;
        ghost2.column = 68;

        location ghost3;
        ghost3.row = 21;
        ghost3.column = 6;

        location ghost4;
        ghost4.row = 21;
        ghost4.column = 68;

        cout<<endl<<endl<<endl<<endl<<endl<<endl;
        cout<<"                                                 Press any key";
        getch();

        system("cls");

        PrintMaze(Maze, row, column);

        do{
            cout<<endl;
            cout<<"                   ";
            cout<<"press (w, a, s, d) to move";
            input = getInput();

            if(input == 'w')
            {
                if((pacman.row - 1)<0 || Maze[pacman.row-1][pacman.column] == '#')
                {
                    proceed == -1;
                }
                else
                {
                    if(Maze[pacman.row-1][pacman.column] == '-')
                    {
                        Maze[pacman.row-1][pacman.column] = ' ';
                        food = food - 1;
                    }
                    if(Maze[pacman.row-1][pacman.column] == 'G')
                    {
                        Maze[pacman.row-1][pacman.column] = 'G';
                        Maze[pacman.row][pacman.column] = ' ';
                        dead = 1;
                    }
                    else
                    {
                        Maze[pacman.row-1][pacman.column] = '@';
                        Maze[pacman.row][pacman.column] = ' ';
                        pacman.row = pacman.row - 1;
                    }
                }
            }
            else if(input == 'a')
            {
                if((pacman.column-2)<0 || Maze[pacman.row][pacman.column-2] == '#')
                {
                    proceed = -1;
                }
                else
                {
                    if(Maze[pacman.row][pacman.column-2] == '-')
                    {
                        Maze[pacman.row][pacman.column-2] = ' ';
                        food = food -1;
                    }
                    if(Maze[pacman.row][pacman.column-2] == 'G')
                    {
                        Maze[pacman.row][pacman.column-2] == 'G';
                        Maze[pacman.row][pacman.column] = ' ';
                        dead = 1;
                    }
                    else
                    {
                        Maze[pacman.row][pacman.column-2] = '@';
                        Maze[pacman.row][pacman.column] = ' ';
                        pacman.column = pacman.column - 2;
                    }
                }
            }
            else if(input == 's')
            {
                if((pacman.row + 1)>row || Maze[pacman.row+1][pacman.column] == '#')
                {
                    proceed == -1;
                }
                else
                {
                    if(Maze[pacman.row+1][pacman.column] == '-')
                    {
                        Maze[pacman.row+1][pacman.column] = ' ';
                        food = food - 1;
                    }
                    if(Maze[pacman.row+1][pacman.column] == 'G')
                    {
                        Maze[pacman.row+1][pacman.column] = 'G';
                        Maze[pacman.row][pacman.column] = ' ';
                        dead = 1;
                    }
                    else
                    {
                        Maze[pacman.row+1][pacman.column] = '@';
                        Maze[pacman.row][pacman.column] = ' ';
                        pacman.row = pacman.row + 1;
                    }
                }
            }
            else if(input == 'd')
            {
                if((pacman.column+2)>75 || Maze[pacman.row][pacman.column+2] == '#')
                {
                    proceed = -1;
                }
                else
                {
                    if(Maze[pacman.row][pacman.column+2] == '-')
                    {
                        Maze[pacman.row][pacman.column+2] = ' ';
                        food = food -1;
                    }
                    if(Maze[pacman.row][pacman.column+2] == 'G')
                    {
                        Maze[pacman.row][pacman.column+2] == 'G';
                        Maze[pacman.row][pacman.column] = ' ';
                        dead = 1;
                    }
                    else
                    {
                        Maze[pacman.row][pacman.column+2] = '@';
                        Maze[pacman.row][pacman.column] = ' ';
                        pacman.column = pacman.column + 2;
                    }
                }
            }
            else if(input == 'q')
            {
                cout<<endl<<"Quit the game?"<<endl;
                cout<<"1. press 'a' to continue"<<endl;
                cout<<"2. press 'd' to quit"<<endl;
                while(1)
                {
                    input = getInput();
                    if(input == 'a')
                    {
                        proceed = -1;
                        cout<<"Game continue "<<endl;
                        break;
                    }
                    if(input == 'd')
                    {
                        return;
                    }
                }
            }
            else
            {
                proceed = -1;
            }

            if(proceed==0)
            {
                moveCount++;
            }
// if get extra time
//will add general function,
// ghost 1
            if(proceed == 0&&dead == 0)
            {
                random = rand()%10;
                if(random == 0)
                {
                    addColumn(&ghost1, &change, &dead, &foodToken1, Maze);
                }
                if(random == 1)
                {
                    addRow(&ghost1, &change, &dead, &foodToken1, Maze);
                }
                if(random == 2)
                {
                    cutColumn(&ghost1, &change, &dead, &foodToken1, Maze);
                }
                if(random == 3)
                {
                    cutRow(&ghost1, &change, &dead, &foodToken1, Maze);
                }
                if(random>3&&random<7)
                {
                    if((ghost1.column - pacman.column)<0)
                    {
                        addColumn(&ghost1, &change, &dead, &foodToken1, Maze);
                    }
                    if((ghost1.column - pacman.column)>0)
                    {
                        cutColumn(&ghost1, &change, &dead, &foodToken1, Maze);
                    }
                    if((ghost1.row - pacman.row)<0)
                    {
                        addRow(&ghost1, &change, &dead, &foodToken1, Maze);
                    }
                    if((ghost1.row - pacman.row)>0)
                    {
                        cutRow(&ghost1, &change, &dead, &foodToken1, Maze);
                    }

                    if(!change)
                    {
                        addColumn(&ghost1, &change, &dead, &foodToken1, Maze);
                        cutColumn(&ghost1, &change, &dead, &foodToken1, Maze);
                        addRow(&ghost1, &change, &dead, &foodToken1, Maze);
                        cutRow(&ghost1, &change, &dead, &foodToken1, Maze);
                    }
                }
                if(random>6)
                {
                    if((ghost1.row - pacman.row)<0)
                    {
                        addRow(&ghost1, &change, &dead, &foodToken1, Maze);
                    }
                    if((ghost1.row - pacman.row)>0)
                    {
                        cutRow(&ghost1, &change, &dead, &foodToken1, Maze);
                    }
                    if((ghost1.column - pacman.column)<0)
                    {
                        addColumn(&ghost1, &change, &dead, &foodToken1, Maze);
                    }
                    if((ghost1.column - pacman.column)>0)
                    {
                        cutColumn(&ghost1, &change, &dead, &foodToken1, Maze);
                    }

                    if(!change)
                    {
                        addRow(&ghost1, &change, &dead, &foodToken1, Maze);
                        cutRow(&ghost1, &change, &dead, &foodToken1, Maze);
                        addColumn(&ghost1, &change, &dead, &foodToken1, Maze);
                        cutColumn(&ghost1, &change, &dead, &foodToken1, Maze);
                    }
                }
            }

            change = 0;

            if(proceed == 0&&dead == 0)
            {
                random = rand()%10;
                if(random == 0)
                {
                    addColumn(&ghost2, &change, &dead, &foodToken2, Maze);
                }
                if(random == 1)
                {
                    addRow(&ghost2, &change, &dead, &foodToken2, Maze);
                }
                if(random == 2)
                {
                    cutColumn(&ghost2, &change, &dead, &foodToken2, Maze);
                }
                if(random == 3)
                {
                    cutRow(&ghost2, &change, &dead, &foodToken2, Maze);
                }
                if(random>3&&random<7)
                {
                    if((ghost2.column - pacman.column)<0)
                    {
                        addColumn(&ghost2, &change, &dead, &foodToken2, Maze);
                    }
                    if((ghost2.column - pacman.column)>0)
                    {
                        cutColumn(&ghost2, &change, &dead, &foodToken2, Maze);
                    }
                    if((ghost2.row - pacman.row)<0)
                    {
                        addRow(&ghost2, &change, &dead, &foodToken2, Maze);
                    }
                    if((ghost2.row - pacman.row)>0)
                    {
                        cutRow(&ghost2, &change, &dead, &foodToken2, Maze);
                    }

                    if(!change)
                    {
                        addColumn(&ghost2, &change, &dead, &foodToken2, Maze);
                        cutColumn(&ghost2, &change, &dead, &foodToken2, Maze);
                        addRow(&ghost2, &change, &dead, &foodToken2, Maze);
                        cutRow(&ghost2, &change, &dead, &foodToken2, Maze);
                    }
                }
                if(random>6)
                {
                    if((ghost2.row - pacman.row)<0)
                    {
                        addRow(&ghost2, &change, &dead, &foodToken2, Maze);
                    }
                    if((ghost2.row - pacman.row)>0)
                    {
                        cutRow(&ghost2, &change, &dead, &foodToken2, Maze);
                    }
                    if((ghost2.column - pacman.column)<0)
                    {
                        addColumn(&ghost2, &change, &dead, &foodToken2, Maze);
                    }
                    if((ghost2.column - pacman.column)>0)
                    {
                        cutColumn(&ghost2, &change, &dead, &foodToken2, Maze);
                    }

                    if(!change)
                    {
                        addRow(&ghost2, &change, &dead, &foodToken2, Maze);
                        cutRow(&ghost2, &change, &dead, &foodToken2, Maze);
                        addColumn(&ghost2, &change, &dead, &foodToken2, Maze);
                        cutColumn(&ghost2, &change, &dead, &foodToken2, Maze);
                    }
                }
            }

            change = 0;

            if(proceed == 0&&dead == 0)
            {
                random = rand()%10;
                if(random == 0)
                {
                    addColumn(&ghost3, &change, &dead, &foodToken3, Maze);
                }
                if(random == 1)
                {
                    addRow(&ghost3, &change, &dead, &foodToken3, Maze);
                }
                if(random == 2)
                {
                    cutColumn(&ghost3, &change, &dead, &foodToken3, Maze);
                }
                if(random == 3)
                {
                    cutRow(&ghost3, &change, &dead, &foodToken3, Maze);
                }
                if(random>3&&random<7)
                {
                    if((ghost3.column - pacman.column)<0)
                    {
                        addColumn(&ghost3, &change, &dead, &foodToken3, Maze);
                    }
                    if((ghost3.column - pacman.column)>0)
                    {
                        cutColumn(&ghost3, &change, &dead, &foodToken3, Maze);
                    }
                    if((ghost3.row - pacman.row)<0)
                    {
                        addRow(&ghost3, &change, &dead, &foodToken3, Maze);
                    }
                    if((ghost3.row - pacman.row)>0)
                    {
                        cutRow(&ghost3, &change, &dead, &foodToken3, Maze);
                    }

                    if(!change)
                    {
                        addColumn(&ghost3, &change, &dead, &foodToken3, Maze);
                        cutColumn(&ghost3, &change, &dead, &foodToken3, Maze);
                        addRow(&ghost3, &change, &dead, &foodToken3, Maze);
                        cutRow(&ghost3, &change, &dead, &foodToken3, Maze);
                    }
                }
                if(random>6)
                {
                    if((ghost3.row - pacman.row)<0)
                    {
                        addRow(&ghost3, &change, &dead, &foodToken3, Maze);
                    }
                    if((ghost3.row - pacman.row)>0)
                    {
                        cutRow(&ghost3, &change, &dead, &foodToken3, Maze);
                    }
                    if((ghost3.column - pacman.column)<0)
                    {
                        addColumn(&ghost3, &change, &dead, &foodToken3, Maze);
                    }
                    if((ghost3.column - pacman.column)>0)
                    {
                        cutColumn(&ghost3, &change, &dead, &foodToken3, Maze);
                    }

                    if(!change)
                    {
                        addRow(&ghost3, &change, &dead, &foodToken3, Maze);
                        cutRow(&ghost3, &change, &dead, &foodToken3, Maze);
                        addColumn(&ghost3, &change, &dead, &foodToken3, Maze);
                        cutColumn(&ghost3, &change, &dead, &foodToken3, Maze);
                    }
                }
            }

            change = 1;

            if(proceed == 0&&dead == 0)
            {
                random = rand()%10;
                if(random == 0)
                {
                    addColumn(&ghost4, &change, &dead, &foodToken4, Maze);
                }
                if(random == 1)
                {
                    addRow(&ghost4, &change, &dead, &foodToken4, Maze);
                }
                if(random == 2)
                {
                    cutColumn(&ghost4, &change, &dead, &foodToken4, Maze);
                }
                if(random == 3)
                {
                    cutRow(&ghost4, &change, &dead, &foodToken4, Maze);
                }
                if(random>3&&random<7)
                {
                    if((ghost4.column - pacman.column)<0)
                    {
                        addColumn(&ghost4, &change, &dead, &foodToken4, Maze);
                    }
                    if((ghost4.column - pacman.column)>0)
                    {
                        cutColumn(&ghost4, &change, &dead, &foodToken4, Maze);
                    }
                    if((ghost4.row - pacman.row)<0)
                    {
                        addRow(&ghost4, &change, &dead, &foodToken4, Maze);
                    }
                    if((ghost4.row - pacman.row)>0)
                    {
                        cutRow(&ghost4, &change, &dead, &foodToken4, Maze);
                    }

                    if(!change)
                    {
                        addColumn(&ghost4, &change, &dead, &foodToken4, Maze);
                        cutColumn(&ghost4, &change, &dead, &foodToken4, Maze);
                        addRow(&ghost4, &change, &dead, &foodToken4, Maze);
                        cutRow(&ghost4, &change, &dead, &foodToken4, Maze);
                    }
                }
                if(random>6)
                {
                    if((ghost4.row - pacman.row)<0)
                    {
                        addRow(&ghost4, &change, &dead, &foodToken4, Maze);
                    }
                    if((ghost4.row - pacman.row)>0)
                    {
                        cutRow(&ghost4, &change, &dead, &foodToken4, Maze);
                    }
                    if((ghost4.column - pacman.column)<0)
                    {
                        addColumn(&ghost4, &change, &dead, &foodToken4, Maze);
                    }
                    if((ghost4.column - pacman.column)>0)
                    {
                        cutColumn(&ghost4, &change, &dead, &foodToken4, Maze);
                    }

                    if(!change)
                    {
                        addRow(&ghost4, &change, &dead, &foodToken4, Maze);
                        cutRow(&ghost4, &change, &dead, &foodToken4, Maze);
                        addColumn(&ghost4, &change, &dead, &foodToken4, Maze);
                        cutColumn(&ghost4, &change, &dead, &foodToken4, Maze);
                    }
                }
            }

            change = 0;


            if(!proceed)
            {
                system("cls");
                PrintMaze(Maze, row, column);
                cout<<endl<<"Total move: "<<moveCount<<endl;
                cout<<"Food remaining: "<<food<<endl;
            }

            if(dead)
            {
                break;
            }

            input = 0;
            proceed = 0;

        }while(food!=0);

        if(!dead)
        {
            cout<<endl<<"Horrah! You won the match!!!!!!!"<<endl;
        }
        else
        {
            cout<<endl<<"You lost, please try again!!!!"<<endl;
        }

        cout<<"Press any key";
        getch();

        cout<<"Do you want to play again?"<<endl;
        cout<<"1. Press 'a' to continue"<<endl;
        cout<<"2. Press 'd' to exit"<<endl;

        while(1)
        {
            input = getInput();
            if(input == 'a')
            {
                moveCount = 0;
                break;
            }
            if(input == 'd')
            {
                return;
            }
        }
    }
}

int main()
{
    system("cls");
    runGame();

    return 0;
}

void PrintMaze(char Maze[][ColNum+1], int row, int column)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    cout<<endl<<endl<<endl;
    for(int i=0; i<row; i++)
    {
        cout<<"                   ";
        for(int j=0; j<column; j++)
        {
            if(Maze[i][j]=='#'){
                SetConsoleTextAttribute(hConsole, 3);
                cout<<Maze[i][j];
            }
            else if(Maze[i][j]=='-'){
                SetConsoleTextAttribute(hConsole, 7);
                cout<<Maze[i][j];
            }
             else if(Maze[i][j]==' '){
                //SetConsoleTextAttribute(hConsole, 2);
                cout<<Maze[i][j];
            }
             else if(Maze[i][j]=='@'){
                SetConsoleTextAttribute(hConsole, 6);
                cout<<Maze[i][j];
            }
             else if(Maze[i][j]=='G'){
                SetConsoleTextAttribute(hConsole, 12);
                cout<<Maze[i][j];
            }
        }
        SetConsoleTextAttribute(hConsole, 7);
        cout<<endl;
    }
}

int getInput()
{
    int x;
    x = getch();
    return x;
}

void addColumn(location *ghost, int *change, int *dead, int *foodToken, char maze[RowNum][ColNum+1])
{
    if(*change == 0)
    {
        if((ghost->column)>ColNum || maze[ghost->row][ghost->column+2] == '#'|| maze[ghost->row][ghost->column+2] == 'G')
        {

        }
        else
        {
            if(maze[ghost->row][ghost->column+2] == '@')
            {
                *dead = 1;
            }

            if(*foodToken)
            {
                maze[ghost->row][ghost->column] = '-';
            }
            else
            {
                maze[ghost->row][ghost->column] = ' ';
            }

            if(maze[ghost->row][ghost->column+2] == '-')
            {
                *foodToken = 1;
            }
            else
            {
                *foodToken = 0;
            }

            maze[ghost->row][ghost->column+2] = 'G';
            ghost->column = ghost->column+2;
            *change = 1;
        }
    }
}

void cutColumn(location *ghost, int *change, int *dead, int *foodToken, char maze[RowNum][ColNum+1])
{
    if(*change == 0)
    {
        if((ghost->column)>ColNum || maze[ghost->row][ghost->column-2] == '#'|| maze[ghost->row][ghost->column-2] == 'G')
        {

        }
        else
        {
            if(maze[ghost->row][ghost->column-2] == '@')
            {
                *dead = 1;
            }

            if(*foodToken)
            {
                maze[ghost->row][ghost->column] = '-';
            }
            else
            {
                maze[ghost->row][ghost->column] = ' ';
            }

            if(maze[ghost->row][ghost->column-2] == '-')
            {
                *foodToken = 1;
            }
            else
            {
                *foodToken = 0;
            }

            maze[ghost->row][ghost->column-2] = 'G';
            ghost->column = ghost->column-2;
            *change = 1;
        }
    }
}
void addRow(location *ghost, int *change, int *dead, int *foodToken, char maze[RowNum][ColNum+1])
{
    if(*change == 0)
    {
        if((ghost->row + 1)>RowNum || maze[ghost->row+1][ghost->column] == '#' || maze[ghost->row+1][ghost->column] == 'G')
        {

        }
        else
        {
            if(maze[ghost->row+1][ghost->column] == '@')
            {
                *dead = 1;
            }

            if(*foodToken)
            {
                maze[ghost->row][ghost->column] = '-';
            }
            else
            {
                maze[ghost->row][ghost->column] = ' ';
            }

            if(maze[ghost->row+1][ghost->column] == '-')
            {
                *foodToken = 1;
            }
            else
            {
                *foodToken = 0;
            }

            maze[ghost->row+1][ghost->column] = 'G';
            ghost->row = ghost->row+1;
            *change = 1;
        }
    }
}

void cutRow(location *ghost, int *change, int *dead, int *foodToken, char maze[RowNum][ColNum+1])
{
    if(*change == 0)
    {
        if((ghost->row - 1)>RowNum || maze[ghost->row-1][ghost->column] == '#' || maze[ghost->row-1][ghost->column] == 'G')
        {

        }
        else
        {
            if(maze[ghost->row-1][ghost->column] == '@')
            {
                *dead = 1;
            }

            if(*foodToken)
            {
                maze[ghost->row][ghost->column] = '-';
            }
            else
            {
                maze[ghost->row][ghost->column] = ' ';
            }

            if(maze[ghost->row-1][ghost->column] == '-')
            {
                *foodToken = 1;
            }
            else
            {
                *foodToken = 0;
            }

            maze[ghost->row-1][ghost->column] = 'G';
            ghost->row = ghost->row-1;
            *change = 1;
        }
    }
}
