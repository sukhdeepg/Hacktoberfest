//This is my favourite code snippet because it uses recursion to remove consecutive duplicates and 
//reduces an input to its simplest form.
#include <iostream>
using namespace std;

void removeConsecutiveDuplicates(char *input){
    if(input[0]=='\0'){
        return;
    }
    else if(input[0]==input[1]){
        for(int i=0;input[i]!='\0';i++){
            input[i]=input[i+1];
        }
        return removeConsecutiveDuplicates(input);
    }
    else{
        return removeConsecutiveDuplicates(input+1);
    }
}
/* Driver program to test above functions */
int main(){
    char arr1[] = "aabccba";
    char* ptr = arr1;
    removeConsecutiveDuplicates(ptr);
    int i{0};
    while(arr1[i]!='\0'){
        cout<<arr1[i];
        i++;
    }cout<<endl;
    return 0;
}