//This is my another favorite code snippet because it can be used to play board games

#include <iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;

int main()
{
    int numberofdice,i;
    cout<<"Enter number of dice you want: ";
    cin>>numberofdice;
    srand(time(0));
    char ch='q';
    while(ch!='e')
    {
        for(i=0;i<numberofdice;i++)
        {
            cout<<rand()%7;
            cout<<'\t';
        }
        cin>>ch;
    }
    return 0;
}
