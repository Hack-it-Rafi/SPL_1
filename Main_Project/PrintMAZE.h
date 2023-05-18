#ifndef PRINTMAZE_H_INCLUDED
#define PRINTMAZE_H_INCLUDED
#include <bits/stdc++.h>
#define RowNum 23
#define ColNum 75
using namespace std;

void PrintMaze(char Maze[][ColNum+1], int row, int column, int level)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     system("cls");
    cout<<endl<<endl<<endl;
    cout<<"                                                    Level: "<<level<<endl;
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


#endif // PRINTMAZE_H_INCLUDED
