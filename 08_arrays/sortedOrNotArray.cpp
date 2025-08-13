// Check if the given array is sorted or not.

#include<iostream>
#include<vector>
using namespace std;

int main() {

    int array[]={1,2,3,4,5,6};

    bool sortedflag=true; 
    // 1 -->> true (sorted)
    // 0 -->> false (unsorted)

    for(int i=6;i<6;i++){
        if(array[i]<=array[i-1]){
            sortedflag=false; 
        }
    }

    cout<<sortedflag<<endl;

    return 0;
}