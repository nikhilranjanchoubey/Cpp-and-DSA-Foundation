// WAP to take input from user 
// For Cost Price and Selling Price 
// Calculate Profit and Loss

#include<iostream>
using namespace std;
int main(){

    int sp,cp;
    cout<<"Enter Selling Price: ";
    cin>>sp;
    cout<<"Enter Cost Price: ";
    cin>>cp;
    
    if(sp>cp){
        int profit = sp-cp;
        cout<<"Your profit is: "<<profit<<endl;
    }
    else if (cp>sp){
        int loss = cp-sp;
        cout<<"Your loss is: "<<loss<<endl;
    }
    else{
        cout<<"No profit or loss"<<endl;
    }

    return 0;
}