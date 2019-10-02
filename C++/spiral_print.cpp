// i like this code snippet because it prints elements of of an array spirally going in anticlockwise direction
#include<iostream>
using namespace std;
int main() {
    int r,c,i,j,a[10][10];
    //enter number of rows and columns
    cin>>r>>c;
    //enter elements of array
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            cin>>a[i][j];
    int sc=0,ec=c-1,sr=0,er=r-1;
    while((sr<=er)&&(sc<=ec))
    {
        for(i=sr;i<=er;i++)
            cout<<a[i][sc]<<", ";
        sc++;
        for(j=sc;j<=ec;j++)
            cout<<a[er][j]<<", ";
        er--;
        if(sc<=ec)
        {
            for(i=er;i>=sr;i--)
                cout<<a[i][ec]<<", ";
            ec--;
        }
        if(sr<=er)
        {
            for(j=ec;j>=sc;j--)
                cout<<a[sr][j]<<", ";
            sr++;
        }
    }
    cout<<"END";
	return 0;
}
