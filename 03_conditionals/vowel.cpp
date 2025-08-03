// WAP to print the alphabet is vowel or consonants.

#include<iostream>
using namespace std;

int main (){
 
    char character;
    cout<<"Enter a Alphabet(in small letter): ";
    cin>>character;

    switch (character){
        case 'a':
            cout<<"Vowel"<<endl;
            break;
        case 'e':
            cout<<"Vowel"<<endl;
            break;
        case 'i':
            cout<<"Vowel"<<endl;
            break;
        case 'o':
            cout<<"Vowel"<<endl;
            break;
        case 'u':
            cout<<"Vowel"<<endl;
            break;
        default :
            cout<<"Consonants"<<endl;
    }

    return 0;
}