// Find the difference between the sum of elements,
// At even indices to the sum of elements at odd indicies.

#include<iostream>
#include<vector>
using namespace std;

int main() {

    int array[]={1,2,1,2,1,2};  // Ans: -3

    int ans_sum = 0;

    for(int i=0; i<6; i++){
        if(i%2==0){
            ans_sum += array[i];
        }
        else{
            ans_sum -= array[i];
        }
    }
    
    cout<<ans_sum<<endl;

    return 0;
}