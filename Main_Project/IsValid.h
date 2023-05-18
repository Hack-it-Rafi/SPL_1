#ifndef ISVALID_H_INCLUDED
#define ISVALID_H_INCLUDED
#include <bits/stdc++.h>
#define RowNum 23
#define ColNum 75
using namespace std;
int isValid(int x, int y)
{
    int p = false;

    if(x>0&&x<RowNum&&y>0&&y<ColNum)
        p = true;
    return p;
}


#endif // ISVALID_H_INCLUDED
