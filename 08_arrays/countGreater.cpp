// Count the number of elements strictly greater than value x.

#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> v(6);
    cout << "Enter 6 elements:\n";
    for(int i = 0; i < v.size(); i++) {
        cin >> v[i];
    }

    cout << "Enter x: ";
    int x;
    cin >> x;

    int count = 0;
    for(int i = 0; i < v.size(); i++) {
        if(v[i] > x) {
            count++;
        }
    }

    cout << "Number of elements strictly greater than " << x << " is: " << count << endl;

    return 0;
}