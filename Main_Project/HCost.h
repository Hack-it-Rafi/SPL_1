#ifndef HCOST_H_INCLUDED
#define HCOST_H_INCLUDED
#include <bits/stdc++.h>
#define RowNum 23
#define ColNum 75
using namespace std;

int hcost(int x, int y, int px, int py, char maze[RowNum][ColNum+1])
{
    if(maze[x][y] == '#' || maze[px][py] == '#')
        return INT_MAX;

    return abs(px-x)+(abs(py-y));
}

#endif // HCOST_H_INCLUDED
