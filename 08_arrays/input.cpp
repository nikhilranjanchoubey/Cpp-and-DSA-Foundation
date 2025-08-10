#include<iostream>
using namespace std;

int main(){

    char vowels[5];

    cout<<"Enter Vowels: "<<endl;

    // // for loop (input) 
    // for(int idx=0; idx<5; idx++){
    //     cin>>vowels[idx];
    // }
    
    // for each loop (input)

    // We use '&' to store element by reference
    // so that we can directly modify the original array values.
    // Without '&', the loop would work on a copy of each element,
    // and changes wouldn't reflect in the actual array.
    
    for(char &element:vowels){
        cin>>element;
    }


    // for loop (output)
    for(int idx=0; idx<5; idx++){
        cout<<vowels[idx]<<" ";
    }    

    return 0;
}