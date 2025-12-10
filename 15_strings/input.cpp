#include <iostream>
#include <string>
using namespace std;

int main()
{

    string str;

    cout << "Input: ";
    // cin>>str;
    getline(cin, str);

    cout << "Output: " << str << endl;

    return 0;
}