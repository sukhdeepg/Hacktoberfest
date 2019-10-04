//This code snippet makes a cool loading sign on the screen
#include <iostream>
#include<windows.h> //  header file for gotoxy
#include <stdio.h>     //header file for standard input output

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
    int r,q;
    gotoxy(36,14);
    cout<<"loading...";
    gotoxy(30,15);
    for(r=1;r<=20;r++)
    {
        for(q=0;q<=100000000;q++);//to display the character slowly
        cout<<(char)177;
    }
    return 0;
}
