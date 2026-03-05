#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<int, string> record;
    // roll no, name

    record.insert(make_pair(3, "Ria"));
    record[1] = "Nikhil";
    record[2] = "Animesh";
    // record[3] = "Payal"; // update value
    record.insert(make_pair(3, "Payal")); // no change (nothing happens)

    for (auto pair : record)
    {
        cout << "Roll no. - " << pair.first << endl;
        cout << "Name - " << pair.second << endl;
    }
    return 0;
}