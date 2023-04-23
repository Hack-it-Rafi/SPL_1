#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#define ColNum 75
using namespace std;

int ROW = 23, COL= 75;
typedef struct{
    int row;
    int col;
}location;

void PrintMaze(char Maze[][ColNum+1])
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    cout<<endl<<endl<<endl;
    for(int i=0; i<ROW; i++)
    {
        cout<<"                   ";
        for(int j=0; j<COL; j++)
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

void runGame()
{
    while(1){

    int userInput = 0;
    int valid = 0;
    int printFlag = 0;
    int direction = 0;
    int deadFlag = 0;
    int temp = 0;
    char Maze[ROW][ColNum+1] = {
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

    location Pacman, Ghost1, Ghost2, Ghost3, Ghost4;

    Pacman.row = 11;
    Pacman.col = 38;

    Ghost1.row = 1;
    Ghost1.col = 6;

    Ghost2.row = 1;
    Ghost2.col = 68;

    Ghost3.row = 21;
    Ghost3.col = 6;

    Ghost4.row = 21;
    Ghost4.col = 68;

    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                                 Press any key";
    getch();
    //Beep(500, 300);
    system("cls");

    PrintMaze(Maze);

    while(1)
    {
        cout<<endl;
        cout<<"                   ";
        cout<<"press (w, a, s, d) to move";

        userInput = getch();

        if(userInput == 'w')
            movePlayer((Pacman.row-1), Pacman.col, &Pacman, &valid, &printFlag, &deadFlag);
        else if(userInput == 'a')
            movePlayer((Pacman.row), (Pacman.col-2), &Pacman, &valid, &printFlag, &deadFlag);
        else if(userInput == 's')
            movePlayer((Pacman.row+1), Pacman.col, &Pacman, &valid, &printFlag, &deadFlag);
        else if(userInput == 'd')
            movePlayer(Pacman.row, (Pacman.col+2), &Pacman, &valid, &printFlag, &deadFlag);
        else


        if(!valid)
            continue;

        int changeFlag = 0;
         if(valid&&printFlag){
            direction = GhostLogic(Ghost1, Pacman);
            if(direction = UP)
                ghost_min_row(Ghost1, &changeFlag, &deadFlag)
            else if(direction = LEFT)
                ghost_min_col(Ghost1, &changeFlag, &deadFlag);
            else if(direction = DOWN)
                ghost_add_row(Ghost1, &changeFlag, &deadFlag);
            else if(direction = RIGHT)
                ghost_add_col(Ghost1, &changeFlag, &deadFlag)
            else

         }

         if(valid&&printFlag){
            direction = GhostLogic(Ghost4, Pacman);
            if(direction = UP)
                ghost_min_row(Ghost4, &changeFlag, &deadFlag)
            else if(direction = LEFT)
                ghost_min_col(Ghost4, &changeFlag, &deadFlag);
            else if(direction = DOWN)
                ghost_add_row(Ghost4, &changeFlag, &deadFlag);
            else if(direction = RIGHT)
                ghost_add_col(Ghost4, &changeFlag, &deadFlag)
            else

         }

         if(valid&&printFlag)
         {
             temp = rand()%10;

             if(temp == 0)
             {
                 ghost_min_row(Ghost2, &changeFlag, &deadFlag);
             }

             else if(temp == 1)
             {
                 ghost_min_col(Ghost2, &changeFlag, &deadFlag);
             }

             else if(temp == 2)
             {
                 ghost_add_row(Ghost2, &changeFlag, &deadFlag);
             }

             else if(temp == 3)
             {
                 ghost_add_col(Ghost2, &changeFlag, &deadFlag);
             }

             else if(temp>3&&temp<7)
             {
                 if((Ghost2.col - Pacman.col)>0)
                 {
                     ghost_min_col(Ghost4, &changeFlag, &deadFlag);
                 }

                 if((Ghost2.col - Pacman.col)<0)
                 {
                     ghost_add_col(Ghost2, &changeFlag, &deadFlag);
                 }

                 if((Ghost2.row - Pacman.row)>0)
                 {
                     ghost_min_row(Ghost2, &changeFlag, &deadFlag);
                 }

                 if((Ghost2.row - Pacman.row)<0)
                 {
                     ghost_add_row(Ghost2, &changeFlag, &deadFlag);
                 }

                 if(!changeFlag)
                 {
                     ghost_min_col(Ghost4, &changeFlag, &deadFlag);
                     ghost_add_col(Ghost2, &changeFlag, &deadFlag);
                     ghost_min_row(Ghost2, &changeFlag, &deadFlag);
                     ghost_add_row(Ghost2, &changeFlag, &deadFlag);
                 }
             }

             else if(temp>6)
             {
                  if((Ghost2.row - Pacman.row)>0)
                 {
                     ghost_min_row(Ghost2, &changeFlag, &deadFlag);
                 }

                 if((Ghost2.row - Pacman.row)<0)
                 {
                     ghost_add_row(Ghost2, &changeFlag, &deadFlag);
                 }

                 if((Ghost2.col - Pacman.col)>0)
                 {
                     ghost_min_col(Ghost4, &changeFlag, &deadFlag);
                 }

                 if((Ghost2.col - Pacman.col)<0)
                 {
                     ghost_add_col(Ghost2, &changeFlag, &deadFlag);
                 }

                 if(!changeFlag)
                 {
                     ghost_min_row(Ghost2, &changeFlag, &deadFlag);
                     ghost_add_row(Ghost2, &changeFlag, &deadFlag);
                     ghost_min_col(Ghost4, &changeFlag, &deadFlag);
                     ghost_add_col(Ghost2, &changeFlag, &deadFlag);
                 }
             }

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
