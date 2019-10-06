//program to left rotate an array by n positions

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int rotate;
    cin>>n;
    cin>>rotate;

    int arr[n];
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }

    int i=0;
    int lim = n-1;
    while(i<rotate)
     {   
    int temp=arr[0];
        for(int j=0;j<n;++j)
        {   
            if(j==lim)
            {
                arr[j]=temp;
            }
            
            else
            {
             arr[j]=arr[j+1];
            }
        }
        ++i;
    }

     for(int i=0;i<n;++i)
     {
        cout<<arr[i]<<" ";
     }


    return 0;
}
