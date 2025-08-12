// Find the last occurrence of an element x in a given array
#include<iostream>
#include<vector>
using namespace std;

int main() {

    vector<int> v(6);

    for(int i=0; i<6; i++){
        cin>>v[i];
    }

    cout<<"Enter x: ";
    int x;
    cin>>x;

    int occurence = -1;

    //finds the last occurrence by updating index each time x is found
     for(int i=0; i<v.size(); i++){
        if (v[i]==x){
            occurence=i;
        }
    }
    cout<<occurence<<endl; // Prints last occurrence (from forward scan)

    //finds the last occurrence directly by scanning from end
       for(int i=v.size()-1; i>=0; i--){
        if (v[i]==x){
            occurence=i;
            break;
        }
    }
    cout<<occurence<<endl; // Prints last occurrence (from reverse scan)

    return 0;
}