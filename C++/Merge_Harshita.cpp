#include<iostream> 
#include<algorithm> // merge operations 
#include<vector> // for vector 
using namespace std; 
int main() 
{ 
 // Initializing 1st vector 
 vector<int> v1 = {1, 3, 4, 5, 20, 30}; 
      
 // Initializing 2nd vector 
 vector<int> v2 = {1, 5, 6, 7, 25, 30}; 
      
 // Declaring resultant vector 
 // for mergeing 
 vector<int> v3(12); 
      
 // Using merge() to merge vectors v1 and v2 
 // and storing result in v3 
 merge(v1.begin(), v1.end(), v2.begin(),  
                   v2.end(), v3.begin()); 
      
 // Displaying resultant container 
 cout << "The new container after merging is :\n"; 
 for (int &x : v3)  
     cout << x << " "; 
 cout << endl; 
   
 // Initializing new vector 
 vector<int> v4 = {1, 3, 4, 5, 6, 20, 25, 30}; 
   
 // Using include() to check if v4 contains v1 
 includes(v4.begin(), v4.end(), v1.begin(), v1.end())? 
        cout << "v4 includes v1": 
        cout << "v4 does'nt include v1"; 
   
 return 0;     
}