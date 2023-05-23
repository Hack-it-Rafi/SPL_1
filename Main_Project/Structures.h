#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED
#include <bits/stdc++.h>
#define RowNum 23
#define ColNum 75
using namespace std;

typedef struct
{
    int row;
    int column;
} location;

struct Cell
{
    int x;
    int y;
    int f;
    int g;
    int h;
}cell[RowNum*ColNum];

struct Status
{
    int open;
    int closed;
    int cellInx;
}status[RowNum+1][ColNum+1];

#endif // STRUCTURES_H_INCLUDED
