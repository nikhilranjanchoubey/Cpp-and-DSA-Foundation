#include <iostream>
#include <map>
using namespace std;

int main()
{
    multimap<string, int> directory;

    directory.insert(make_pair("Nikhil", 345628));
    directory.insert(make_pair("Urvi", 743628));
    directory.insert(make_pair("Sanket", 695028));
    directory.insert(make_pair("Urvi", 8925028));

    // directory["Urvi"] = 278192; // not allowed (nmultimap)

    for (auto pair : directory)
    {
        cout << "Name - " << pair.first << endl;
        cout << "Phone no. - " << pair.second << endl;
    }

    return 0;
}
