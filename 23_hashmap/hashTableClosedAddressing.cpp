/* Implement hash table with closed addressing (Separate Chaining) */

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class Hashing
{

    vector<list<int>> hashtable;
    int buckets;

public:
    Hashing(int size)
    {
        buckets = size;
        hashtable.resize(size);
    }

    int hashvalue(int key)
    {
        return key % buckets; // division method for hash function
    }

    void add(int key)
    {
        int idx = hashvalue(key);
        hashtable[idx].push_back(key);
    }

    list<int>::iterator searchke(int key)
    {
        int idx = hashvalue(key);
        return find(hashtable[idx].begin(), hashtable[idx].end(), key);
    }

    void deletekey(int key)
    {

        int idx = hashvalue(key);

        auto it = searchke(key);

        if (it != hashtable[idx].end())
        { // key is present
            hashtable[idx].erase(it);
            cout << endl;
            cout << "Key deleted successfully\n";
        }
        else
        {
            cout << "Key not found\n";
        }
    }

    void display()
    {
        for (int i = 0; i < buckets; i++)
        {
            cout << i << " -> ";
            for (auto x : hashtable[i])
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }
};

int main()
{

    Hashing h(7);

    h.add(10);
    h.add(20);
    h.add(15);
    h.add(7);
    h.add(32);

    cout << "Hash Table:\n";
    h.display();

    h.deletekey(15);

    cout << "\nAfter deletion:\n";
    h.display();

    return 0;
}