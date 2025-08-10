#include<iostream>
using namespace std;

int main(){

    int arr[] = {1, 2, 3, 4, 5};
    cout<<"Using Normal Method"<<endl;
    cout<<arr[0]<<endl;
    cout<<arr[1]<<endl;
    cout<<arr[2]<<endl;
    cout<<arr[3]<<endl;
    cout<<arr[4]<<endl;

    cout<<"\n";

    cout<<"Size of array : "<<sizeof(arr)<<endl;  // size of array
    cout<<"Length of array: "<<sizeof(arr)/sizeof(arr[0])<<endl;  // length of array

    cout<<"\n";

    // for loop 
    // for printing the elements of array
    cout<<"using For Loop"<<endl;
    for(int idx=0; idx<=4; idx ++){
        cout<<arr[idx]<<endl;
    }
     
    cout<<"\n";

    // for each loop
    cout<<"Using For Each Loop"<<endl;
    for(int element:arr){  
        cout<<element<<endl;
    }

    cout<<"\n";

    // while loop
    cout<<"Using While Loop"<<endl;
    int index=0;
    while(index<=4){
        cout<<arr[index]<<endl;
        index++;
    }

    return 0;
}