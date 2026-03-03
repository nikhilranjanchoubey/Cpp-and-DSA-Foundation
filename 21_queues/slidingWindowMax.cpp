/* You are given an array of integers nums, there is a sliding window of size k
which is moving from the very left of the array to the very right. You can only
see the k numbers in the window. Each time the sliding window moves right
by one position. Return the max. sliding window wich basically contains the
max element in each window. */

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void max_window(vector<int> &arr, int k)
{
    deque<int> dq;

    // Process first window
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && arr[dq.back()] < arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    // Process remaining windows
    for (int i = k; i < arr.size(); i++)
    {
        // Print max of previous window
        cout << arr[dq.front()] << " ";

        // Remove elements out of this window
        if (!dq.empty() && dq.front() == i - k)
            dq.pop_front();

        // Remove smaller elements
        while (!dq.empty() && arr[dq.back()] < arr[i])
        {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    // Print max of last window
    cout << arr[dq.front()] << endl;
}

int main()
{
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    max_window(arr, k);

    return 0;
}