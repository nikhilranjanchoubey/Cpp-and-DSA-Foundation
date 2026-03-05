/* Sum of Repetitive Elements

You are given an integer n, representing the number of elements.
Then, you will be given n elements.
You have to return the sum of repetitive elements i.e.
the elements that appear more than one time.

Input:
n = 7
Elements = [1, 1, 2, 1, 3, 3, 3]

Output:
4

Explanation:
The repetitive elements are 1, 3 and the sum is 4. */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int n;
    cout << "Total no. of elements: " << endl;
    cin >> n;

    vector<int> input(n);

    cout << "Enter " << n << " elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        // storing frequency of every element in input array
        m[input[i]]++;
    }
    int sum = 0;
    // finding sum of repetitive elements
    // pair - element, frequency
    for (auto pair : m)
    {
        if (pair.second > 1)
        { // element is repetitive
            sum += pair.first;
        }
    }
    cout << "ANS - " << sum << endl;

    return 0;
}