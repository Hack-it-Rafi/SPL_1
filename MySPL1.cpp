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
void add_column(position *ghost, int *change, int *dead, int *item, char arr[23][ColNum+1]);
void cut_column(position *ghost, int *change, int *dead, int *item, char arr[23][ColNum+1]);
void add_row(position *ghost, int *change, int *dead, int *item, char arr[23][ColNum+1]);
void cut_row(position *ghost, int *change, int *dead, int *item, char arr[23][ColNum+1]);

int main()
{
    int row = 23, column = 75;
    int food = 245;
    int input = 0;
    int proceed = 0;
    int change = 0;
    int dead = 0;
    int movecount = 0, charinput, advance = 1;
    char tempMaze[row][(ColNum+1)];
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

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<ColNum+1; j++)
            tempMaze[i][j] = Maze[i][j];
    }
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

    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                                 Press any key";
    getch();
    system("cls");

    PrintMaze(Maze, row, column);

    do{     //check
            cout<<endl;
            cout<<"                   ";
            cout<<"press (w, a, s, d) to move";
        input = getch();
       // if((input=='w'||input=='s'||input=='d'||input=='a')&&input!='#')
       // movecount++;

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

        if(dead ==0&& proceed==0)
        {

        }

        if(proceed==0)
            movecount++;
        proceed = 0;

   //a system("cls");a

    PrintMaze(Maze, row, column);

    if(dead == 1)
        {
            cout<<endl<<endl<<"OOPS! You hit the ghost."<<endl;
            cout<<"Score: "<<245-food<<endl;
            cout<<"Total moves: "<<movecount<<endl;
            break;
            /*cout<<"Do you want to continue?(y/n) ";
            cin>>charinput;
            if(charinput=='n')
                break;
            else {
                for(int i=0; i<row; i++)
                {
                    for(int j=0; j<ColNum+1; j++)
                    Maze[i][j] = tempMaze[i][j];
                }
            }*/
        }
    if(food == 0)
    {
        cout<<"Congratulations! You Won!"<<endl;
        cout<<"Total moves: "<<movecount<<endl;
        //cout<<"Do you want to continue?(y/n) ";
        //cin>>charinput;
       // if(charinput=='n')
            break;

    }

    }while(advance);

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

void add_column(position *ghost, int *change, int *dead, int *item, char arr[23][ColNum+1])
{
    if(*change == 0)
    {
        if((ghost->column+2)>ColNum||arr[ghost->row][ghost->column+2] == '#'||arr[ghost->row][ghost->column+2]=='G'||arr[ghost->row][ghost->column+1]=='#')
        {
            *change = 0; //change
        }
        else
        {
            if(arr[ghost->row][ghost->column+2]=='@')
            {
                *dead = -1;
            }
            if(*item)
            {
                arr[ghost->row][ghost->column] = '-';
            }
            else{
                arr[ghost->row][ghost->column] = ' ';
            }
            if(arr[ghost->row][ghost->column+2] == '-')
            {
                *item = 1;
            }
            else
                *item = 0;

            ghost->column = ghost->column+2;
            arr[ghost->row][ghost->column] = 'G';

            *change = 1;
        }
    }
}

void cut_column(position *ghost, int *change, int *dead, int *item, char arr[23][ColNum+1])
{
    if(*change == 0)
    {
        if((ghost->column-2)>ColNum||arr[ghost->row][ghost->column-2] == '#'||arr[ghost->row][ghost->column-2]=='G'||arr[ghost->row][ghost->column-1]=='#')
        {
            *change = 0; //change
        }
        else
        {
            if(arr[ghost->row][ghost->column-2]=='@')
            {
                *dead = -1;
            }
            if(*item)
            {
                arr[ghost->row][ghost->column] = '-';
            }
            else{
                arr[ghost->row][ghost->column] = ' ';
            }
            if(arr[ghost->row][ghost->column-2] == '-')
            {
                *item = 1;
            }
            else
                *item = 0;

            ghost->column = ghost->column-2;
            arr[ghost->row][ghost->column] = 'G';

            *change = 1;
        }
    }
}

void add_row(position *ghost, int *change, int *dead, int *item, char arr[23][ColNum+1])
{
    if(*change == 0)
    {
        if((ghost->row+1)>23||arr[ghost->row+1][ghost->column] == '#'||arr[ghost->row+1][ghost->column]=='G')
        {
            *change = 0; //change
        }
        else
        {
            if(arr[ghost->row+1][ghost->column]=='@')
            {
                *dead = -1;
            }
            if(*item)
            {
                arr[ghost->row][ghost->column] = '-';
            }
            else{
                arr[ghost->row][ghost->column] = ' ';
            }
            if(arr[ghost->row+1][ghost->column] == '-')
            {
                *item = 1;
            }
            else
                *item = 0;

            ghost->row = ghost->row+1;
            arr[ghost->row][ghost->column] = 'G';

            *change = 1;
        }
    }
}

void cut_row(position *ghost, int *change, int *dead, int *item, char arr[23][ColNum+1])
{
    if(*change == 0)
    {
        if((ghost->row-1)>23||arr[ghost->row-1][ghost->column] == '#'||arr[ghost->row-1][ghost->column]=='G')
        {
            *change = 0; //change
        }
        else
        {
            if(arr[ghost->row-1][ghost->column]=='@')
            {
                *dead = -1;
            }
            if(*item)
            {
                arr[ghost->row][ghost->column] = '-';
            }
            else{
                arr[ghost->row][ghost->column] = ' ';
            }
            if(arr[ghost->row-1][ghost->column] == '-')
            {
                *item = 1;
            }
            else
                *item = 0;

            ghost->row = ghost->row-1;
            arr[ghost->row][ghost->column] = 'G';

            *change = 1;
        }
    }
}

