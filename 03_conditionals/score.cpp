#include<iostream>
using namespace std;

int main (){
    
    int score;
    cout<<"Enter score: "<<endl;
    cin>>score;

    // score >80 . print Well done!
    // score = 50-80, print Can improve
    // score <50, print Poor performance

    if(score>80){
        cout<<"Well done!"<<endl;
    }
    else if(score>50){
        cout<<"Can improve"<<endl;
    }
    else{
        cout<<"Poor performance"<<endl;
    }

    return 0;
}
