/* A new racing track for kids is being built in New York with ‘n’ starting spots
The spots are located along a straight line at positions x1, x2.. xn (xi ≤ 10^9). For each i, xi+1 > xi.
At a time only ‘m’ children are allowed to enter the race.
Since the race track is for kids, they may run into each other while running.
To prevent this, we want to choose the starting spots such that the minimum distance between any two of them is as large as possible.
What is the largest minimum distance?

The first line of input will contain the value of n, the number of starting spots.
The second line of input will contain the n numbers denoting the location of each spot.
The third line will contain the value of m, number of children.

Input
5
1 2 4 8 9
3

Output
3 */

#include <iostream>
#include <vector>
using namespace std;

// Function to check if we can place 's' students
// such that the minimum distance between any two students is at least 'mid'
bool canPlaceStudents(vector<int> &pos, int s, int mid)
{
    int studentsReqd = 1;    // first student placed at pos[0]
    int lastPlaced = pos[0]; // track last placed student's position

    for (int i = 1; i < (int)pos.size(); i++)
    {
        // If current position is at least 'mid' away from last placed student
        if (pos[i] - lastPlaced >= mid)
        {
            studentsReqd++;      // place another student
            lastPlaced = pos[i]; // update last placed position

            // CORRECTED: return true if we have placed at least s students
            if (studentsReqd >= s)
            {
                return true;
            }
        }
    }

    return false; // not possible to place all students with this distance
}

// Function to find the largest minimum distance possible
// using Binary Search
int race(vector<int> &pos, int s)
{
    int n = pos.size();

    int lo = 1;                   // smallest possible distance
    int hi = pos[n - 1] - pos[0]; // largest possible distance
    int ans = -1;                 // store final answer

    // Binary Search loop
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2; // middle distance

        // If we can place students with at least 'mid' distance
        if (canPlaceStudents(pos, s, mid))
        {
            ans = mid;    // update answer
            lo = mid + 1; // try for larger distance
        }
        else
        {
            hi = mid - 1; // reduce distance
        }
    }

    return ans;
}

int main()
{
    int n;
    cout << "Enter number of positions: ";
    cin >> n; // number of positions

    vector<int> pos;

    // Input positions
    cout << "Enter positions: ";
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        pos.push_back(x);
    }

    int s;
    cout << "Enter number of students: ";
    cin >> s; // number of students

    // Print the largest minimum distance possible
    cout << "The largest minimum distance possible is: " << race(pos, s) << "\n";

    return 0;
}
