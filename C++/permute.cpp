/*  program to generate all permutations of a given string using backtracking.  */

#include <iostream> 
#include <set>
#include <string>
using namespace std;

set<string> permute(set<string>x,string a, int l, int h){
    if(l == h){
        x.insert(a);
        return x;
    }
    
    for(int i=l; i<=h; i++){
        swap(a[i],a[l]);
        x = permute(x,a, l+1, h);
        swap(a[i],a[l]);
    }
    
    return x; 
}
int main()
 {
  string s; 
  cin>>s; 
  set<string>a; 
  a = permute(a, s, 0, s.size()-1);
  for(auto i = a.begin(); i!=a.end(); i++){
      cout<<*i<<" ";
  }
  cout<<"\n";
  return 0;
}
