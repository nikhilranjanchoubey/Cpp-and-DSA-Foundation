#include<iostream>
#include<vector>
using namespace std;

int main() {

    vector<int> v;

    // for loop (for input)
    cout<<"Enter elements: "<<endl;
    for(int i=0; i<5; i++){
        int element;
        cin>>element;
        v.push_back(element);
    }

    // for loop (for output)
    cout<<"Using For Loop"<<endl;
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    v.insert(v.begin()+2,6);

    // for each loop (for output)
    cout<<"Using For Each Loop"<<endl;
    for(int ele:v){
        cout<<ele<<" ";
    }
    cout<<endl;

    v.erase(v.end()-2);

    // while loop (for output)
    cout<<"Using While Loop"<<endl;
    int idx=0;
    while(idx<v.size()){
        cout<<v[idx++]<<" ";

    }

    return 0;
}