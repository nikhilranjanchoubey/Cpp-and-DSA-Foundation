#include<iostream>
using namespace std;

// int main() {
//     int x = 9;
//     int &y = x;
//     cout<<x<<" "<<y<<"\n";
//     y = 88;
//     cout<<x<<" "<<y<<"\n";
    
//     return 0;
// }

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int x = 9;
    int c = 1;
    int &y = x;
    swap(x, c);
    cout<<x<<" "<<c;

    return 0;
}