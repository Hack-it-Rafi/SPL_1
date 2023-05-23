#include <bits/stdc++.h>
#include <conio.h>
//#include<stdlib.h>
#include <windows.h>
#include "GetInput.h"
#include "RunGame.h"
#define RowNum 23
#define ColNum 75
using namespace std;

int main()
{
    system("cls");
    int score, level, input;
    string name;
    int counter, want;

    while(1){
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                                 Choose Options:"<<endl<<endl;
    cout<<"                                                 1. Play Game"<<endl;
    cout<<"                                                 2. Score Board"<<endl;
    cout<<"                                                 3. Help"<<endl;
    cout<<"                                                 4. About"<<endl;
    cout<<"                                                 5. Exit"<<endl;
    want = getch();
    if(want == '1')
    {
        system("cls");
    while(1){
    FILE *fp;
    fp = fopen("ScoreFile.txt", "a");

    if(fp == NULL)
    {
        cout<<"Error opening the file!"<<endl;
        return 0;
    }
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                                 Press any key";
        getch();
    system("cls");
     cout<<endl<<endl<<endl<<endl<<endl<<endl;
     cout<<"Enter your name: ";
     cin>>name;
     score = runGame();
     if(score<2000){
        level = 1;
        score = score - 1000;
    }
    else {
        level = 2;
        score = score - 2000;
    }

    fprintf(fp, "\n%-15s %-15d %-15d", name.c_str(), level, score);
    fclose(fp);
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
                counter = 1;
                break;
            }
            if(input == 'd')
            {
                counter = 0;
                break;
            }
        }
        if(counter == 0)
            break;
    }
    }
    else if(want == '2')
    {
        system("cls");
        FILE *fh;
        fh = fopen("ScoreFile.txt", "r");
        if(fh != NULL)
        {
            char c;
            while((c = fgetc(fh)) != EOF)
                putchar(c);

            fclose(fh);
        }
        else
            cout<<"Error opening file."<<endl;
        cout<<endl<<endl<<"                                         Press any key";
        getch();
        system("cls");
    }
    else if(want == '3')
    {
        system("cls");
        cout<<endl<<endl<<endl<<endl<<endl<<endl;
        cout<<"                                             Instructions: "<<endl;
        cout<<"                               --------------------------------------------"<<endl<<endl;
        cout<<"                                        Press 'w' to move up;"<<endl;
        cout<<"                                        Press 's' to move  down;"<<endl;
        cout<<"                                        Press 'a' to move left;"<<endl;
        cout<<"                                        Press 'd' to move right;"<<endl<<endl;
        cout<<endl<<endl<<"                                             Press any key";
        getch();
        system("cls");
    }
    else if(want == '4')
    {
        system("cls");
        cout<<endl<<endl<<endl<<endl<<endl<<endl;
        cout<<"                                             Developer: "<<endl;
        cout<<"                               --------------------------------------------"<<endl<<endl;
        cout<<"                                        Imamul Hossain Rafi"<<endl;
        cout<<"                                             BSSE-1323"<<endl;
        cout<<"                                                IIT"<<endl;
        cout<<endl<<endl<<"                                            Press any key";
        getch();
        system("cls");
    }
    else if(want == '5')
    {
        return 0;
    }
    else
        system("cls");
    }
    return 0;
}
