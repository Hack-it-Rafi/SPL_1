#include <bits/stdc++.h>
#include <conio.h>
//#include<stdlib.h>
#include <windows.h>
#define ColNum 75
using namespace std;

typedef struct
{
    int row;
    int column;
} location;

void PrintMaze(char Maze[][ColNum+1], int row, int column);

int main()
{
    int row = 23, column = 75;
    int food = 245;
    int input = 0;
    int proceed = 0;
    int dead = 0;
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
    "###########################################################################",
    };
    location pacman;
    pacman.row = 11;
    pacman.column= 38;

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

    PrintMaze(Maze, row, column);

    do{     //check
            cout<<"press (w, a, s, d) to move";
        input = getch();

        if(input == 'w')
        {
            if(Maze[pacman.row-1][pacman.column] == '#' || (pacman.row-1)<0)
            {
                proceed = -1; //what
            }
            else
            {
                if(Maze[pacman.row-1][pacman.column] == '-')
                {
                    Maze[pacman.row-1][pacman.column] = ' ';
                    food = food-1;
                }

                if(Maze[pacman.row-1][pacman.column] == 'G')
                {
                    //check
                    Maze[pacman.row][pacman.column] = ' ';
                    dead = 1;
                }
                else{
                    Maze[pacman.row-1][pacman.column] = '@';
                    Maze[pacman.row][pacman.column] = ' ';
                    pacman.row = pacman.row-1;
                }
            }
        }

        else if(input == 'a')
        {
            if(Maze[pacman.row][pacman.column-2] == '#'|| (pacman.column-2)<0)   //check
            {
                proceed = -1;    //what
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
                    dead = 1;
                    //check
                    Maze[pacman.row][pacman.column] = ' ';
                }
                else
                {
                    Maze[pacman.row][pacman.column] = ' ';
                    Maze[pacman.row][pacman.column-2] = '@';
                    pacman.column = pacman.column - 2;
                }
            }
        }

       else if(input == 's')
        {
            if(Maze[pacman.row+1][pacman.column] == '#' || pacman.row>23)
            {
                proceed = -1;//check
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
                    //check
                    Maze[pacman.row][pacman.column] = ' ';
                    dead = 1;
                }
                else
                {
                    Maze[pacman.row+1][pacman.column] = '@';
                    Maze[pacman.row][pacman.column] = ' ';
                    pacman.row = pacman.row+1;
                }
            }
        }

        else if(input == 'd')
        {
            if(Maze[pacman.row][pacman.column+2] == '#'|| (pacman.column+2)>ColNum) // check
            {
                proceed = -1;
            }
            else
            {
                if(Maze[pacman.row][pacman.column+2] == '-')
                {
                    Maze[pacman.row][pacman.column+2] = ' ';
                    food = food-1;
                }

                if(Maze[pacman.row][pacman.column+2] == 'G')
                {
                    //check
                    Maze[pacman.row][pacman.column] = ' ';
                    dead = 1;
                }
                else
                {
                    Maze[pacman.row][pacman.column+2] = '@';
                    Maze[pacman.row][pacman.column] = ' ';
                    pacman.column = pacman.column+2;
                }
            }
        }

    system("cls");

    PrintMaze(Maze, row, column);

    if(dead == 1)
        {
            cout<<endl<<endl<<"OOPS! You hit the ghost."<<endl;
            cout<<"Score: "<<245-food;
            break;
        }
    if(food == 0)
    {
        cout<<"Congratulations! You Won!";
        break;
    }

    }while(1);

    return 0;
}
void PrintMaze(char Maze[][ColNum+1], int row, int column)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            if(Maze[i][j]=='#'){
                SetConsoleTextAttribute(hConsole, 8);
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
                SetConsoleTextAttribute(hConsole, 1);
                cout<<Maze[i][j];
            }
        }
        SetConsoleTextAttribute(hConsole, 7);
        cout<<endl;
    }
}
