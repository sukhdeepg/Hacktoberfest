//This code snippet makes a cool random picture
#include <iostream>
#include<windows.h> //  header file for gotoxy
#include <stdio.h>     //header file for standard input output
#include<stdlib.h>
#include<ctime>
using namespace std;
COORD coord={0,0}; // this is global variable
                                    //center of axis is set to the top left cornor of the screen
 void gotoxy(int x,int y)
 {
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }
int main()
{
    int i,x,y;
    srand(time(0));
    for(i=0;i<100;i++)
    {
        x=rand()%100;
        y=rand()%20;
        gotoxy(x,y);
        cout<<'.';
    }
    for(i=0;i<20;i++)
        cout<<'\n';
    return 0;
}
