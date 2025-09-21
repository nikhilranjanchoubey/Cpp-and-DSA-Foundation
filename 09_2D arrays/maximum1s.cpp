/*Given a boolean 2D array, where each row is sorted. Find the row with the maximum number of 1s.*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int leftMostOneRow(vector<vector<int>> &V) {
    int leftMostOne = -1;
    int maxOneRow = -1;
    int j = V[0].size() - 1;

    // Find leftmost 1 in the first row
    while (j >= 0 && V[0][j] == 1) {
        leftMostOne = j;
        maxOneRow = 0;
        j--;
    }

    // Check remaining rows
    for (int i = 1; i < V.size(); i++) {
        while (j >= 0 && V[i][j] == 1) {
            leftMostOne = j;
            maxOneRow = i;
            j--;
        }
    }

    return maxOneRow;
}

int maximumOnesRow(vector<vector<int> >V){

int maxOnes = INT_MIN;
int maxOnesRow = -1;
int columns = V[0].size();

for(int i=0;i<V.size();i++){
    for(int j=0;j<V[i].size();j++){

        if(V[i][j]==1){
            int numberOfOnes = columns - j;
            if(numberOfOnes > maxOnes){
                maxOnes = numberOfOnes;
                maxOnesRow = i;
            }
        }
    }
}

    return maxOnesRow;
}

int main(){
    
    int n,m;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;

    vector<vector<int> > vec(n,vector<int> (m));

     cout<<"Enter elements of the array: "<<endl;
    for (int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>vec[i][j];
        }
    }

    int res1 = maximumOnesRow(vec);
    cout << "Row with maximum 1s: " << res1 << endl;

    int res2 = leftMostOneRow(vec);
    cout << "Row with maximum 1s: " << res2 << endl;

    return 0;
}


