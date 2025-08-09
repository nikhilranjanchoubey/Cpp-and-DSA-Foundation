// Given the age of a person,
// Write a function to check if the person is eligible to vote or not.

#include<iostream>
using namespace std;

bool checkEligibility(int age,int limit){
    if(age >= limit){
        // person is eligible
        return true;
    }
    else {
        // person is not eligible
        return false;
    }

}



int main(){

    int voting_limit = 18;
    int is_eligible_for_voting = checkEligibility(21, voting_limit);
    if(is_eligible_for_voting){
        cout<<"YES, the current person is eligible to vote";
    }
    else {
        cout<<"NO, the current person is not eligible to vote";
    }

    return 0;
}