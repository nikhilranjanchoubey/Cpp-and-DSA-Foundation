//Given Q queries, check if the given number is present in the array or not.
//Note: Value of all the elements in the array is less than 10 to the power 5.

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cout<<"Enter no. of elements in array: "<<endl;
    cin>>n;

    vector<int> v(n);
    cout<<"Enter array elements: "<<endl;
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    const int N = 1e5 + 10;
    vector<int> freq(N, 0);
    for(int i=0;i<n;i++){
        freq[v[i]]++;
    }

    cout<<"Enter Queries: ";
    int q;
    cin>>q;
    cout << "Enter query elements:"<<endl;

    while(q--){
        int  queryelement;
        cin>>queryelement;
       int count = freq[queryelement];
        if (count > 0)
            cout << queryelement << " is present (" << count << " time(s))\n";
        else
            cout << queryelement << " is not present\n";
    }


    

    return 0;
}