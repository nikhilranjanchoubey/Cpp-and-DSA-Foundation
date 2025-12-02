/* You have ‘n’ (n ≤ 10^5) boxes of chocolate.
Each box contains a[i] (a[i] ≤ 10000) chocolates.
You need to distribute these boxes among ‘m’ students
such that the maximum number of chocolates allocated to a student is minimum.

a. One box will be allocated to exactly one student.
b. All the boxes should be allocated.
c. Each student has to be allocated at least one box.
d. Allotment should be in contiguous order, for instance, a student cannot be allocated box 1 and box 3, skipping box 2.

Calculate and return that minimum possible number.
Assume that it is always possible to distribute the chocolates.

The first line of input will contain the value of n, the number of boxes.
The second line of input will contain the n numbers denoting the number of chocolates in each box.
The third line will contain the m, number of students.

Input

4
12 34 67 90
2

Output

113 */

#include <iostream>
#include <vector>
using namespace std;

// Function to check if chocolates can be distributed such that
// no student gets more than 'mid' chocolates
bool canDistChoco(vector<int> &arr, int mid, int s) {
    int n = arr.size();
    int studentsReqd = 1;   // start with 1 student
    int currSum = 0;        // current sum of chocolates for a student

    for(int i = 0; i < n; i++) {

        // If a single chocolate packet is larger than 'mid',
        // distribution is not possible
        if(arr[i] > mid) {
            return false;
        }

        // If adding current packet exceeds 'mid',
        // assign chocolates to next student
        if(currSum + arr[i] > mid) {
            studentsReqd++;
            currSum = arr[i];

            // If students required exceed given limit 's'
            if(studentsReqd > s) return false;
        } 
        else {
            // Otherwise, keep adding chocolates to current student
            currSum += arr[i];
        }
    }
    return true; // distribution possible
}

// Function to find minimum possible maximum chocolates
// any student can get using Binary Search
int distChoco(vector<int> &arr, int s) {
    int n = arr.size();
    int lo = arr[0];   // lower bound = max single packet
    int hi = 0;        // upper bound = sum of all packets

    // Calculate lower bound and total sum
    for(int i = 0; i < arr.size(); i++) {
        if(lo < arr[i]) lo = arr[i];  // largest single packet
        hi += arr[i];                 // total chocolates
    }

    int ans = -1; // store final answer

    // Binary Search between lo and hi
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2; // middle value

        // If distribution possible with 'mid'
        if(canDistChoco(arr, mid, s)) {
            ans = mid;       // update answer
            hi = mid - 1;    // try smaller maximum
        } 
        else {
            lo = mid + 1;    // increase limit
        }
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter number of chocolate packets: ";
    cin >> n;   // number of chocolate packets

    vector<int> v;
    cout << "Enter numbers of chocolates in each packet: ";
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;   // input chocolates in each packet
        v.push_back(x);
    }

    int s;
    cout << "Enter number of students: ";
    cin >> s;   // number of students

    // Print minimum possible maximum chocolates per student
    cout << "Minimum possible maximum chocolates per student: "<< distChoco(v, s) << "\n";
    return 0;
}
