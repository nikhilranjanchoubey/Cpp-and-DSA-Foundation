// Find the second largest element in the given array

#include<iostream>
#include<climits>
using namespace std;

// int largestElementIndex(int array[], int size){
//     int max=INT_MIN;
//     int maxindex=-1;
//     for(int i=0;i<size;i++){
//         if(array[i]>max){
//             max=array[i];
//             maxindex=i;
//         }
//     }
//     return maxindex;
// }

int secondLargestElement(int array[], int size){

    int max=INT_MIN;
    int second_max = INT_MIN;

    for(int i=0;i<size;i++){
        if(array[i]>max){
            max=array[i];
        }
    }

    for(int i=0;i<size;i++){
        if(array[i]>second_max && array[i]!=max){
            second_max = array[i];

        }
    }
    return second_max;
}


int main(){

    int array[]={2,3,5,7,6,1,7}; 
    int n=7; // size of array
    // int indexoflargest = largestElementIndex(array,n);

    // //array[indexoflargest]=-1;
    // int largestelement = array[indexoflargest];
    // for (int i=0;i<n;i++){
    //     if (array[i]==largestelement){
    //         array[i]=-1;
    //     }
    // }
    // int indexofsecondlargest = largestElementIndex(array,n);
    // cout<<array[indexofsecondlargest]<<endl;

    cout<<secondLargestElement(array, n)<<endl;

    return 0;
}