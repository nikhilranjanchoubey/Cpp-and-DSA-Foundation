#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> directory;

    directory["Naman"] = 3876;
    directory["Animesh"] = 74529;
    directory["Ritu"] = 265289;

    // for (auto element : directory)
    // {
    //     cout << "Name - " << element.first << endl;
    //     cout << "Phone no. - " << element.second << endl;
    // }

    map<string, int>::iterator itr;
    for (itr = directory.begin(); itr != directory.end(); itr++)
    {
        cout << itr->first << "- " << itr->second << endl;
    }

    return 0;
}