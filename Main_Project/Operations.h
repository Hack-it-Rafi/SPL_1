#ifndef OPERATIONS_H_INCLUDED
#define OPERATIONS_H_INCLUDED
#include <bits/stdc++.h>
#include "Structures.h"
#define RowNum 23
#define ColNum 75
using namespace std;

void addColumn(location *ghost, int *change, int *dead, int *foodToken, char maze[RowNum][ColNum+1])
{
    if(*change == 0)
    {
        if((ghost->column)>ColNum || maze[ghost->row][ghost->column+2] == '#'|| maze[ghost->row][ghost->column+2] == 'G')
        {}
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
        {}
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
        {}
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
        {}
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


#endif // OPERATIONS_H_INCLUDED
