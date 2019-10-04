//This is my favorite code snippet because it can be used to play board games

#include <iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;

int main()
{
    srand(time(0));
    char ch='q';
    while(ch!='e')
    {
        cout<<rand()%7;
        cout<<'\t';
        cin>>ch;
    }
    return 0;
}
