/*Give an array of names of the fruits;
you are supposed to sort it in lexicographical order
using the selection sort

Input : ["papaya","lime","watermelon","apple","mango","kiwi"]
Output : ["apple","kiwi","lime","mango","papaya","watermelon"]*/

#include<iostream>
#include<cstring> // For strcmp function to compare strings
using namespace std;

// Function to perform selection sort on an array of strings
void selectionSort(char fruit[][60], int n){

    // Outer loop to iterate over each element except the last
    for(int i = 0; i < n - 1; i++){

        // Assume the current index has the minimum element
        int min_index = i;

        // Inner loop to find the actual minimum element in the unsorted part
        for(int j = i + 1; j < n; j++){
            // Compare strings lexicographically using strcmp
            // If fruit[j] is smaller, update min_index
            if(strcmp(fruit[min_index], fruit[j]) > 0)
                min_index = j;
        }

        // Swap the found minimum element with the current element
        if(i != min_index){
            swap(fruit[i], fruit[min_index]);
        }
    }

    return;
}

int main(){

    // Initialize the array of fruit names
    char fruit[][60] = {"papaya", "lime", "watermelon", "apple", "mango", "kiwi"};

    // Calculate the number of fruits in the array
    int n = sizeof(fruit) / sizeof(fruit[0]);

    // Sort the array using selection sort
    selectionSort(fruit, n);

    // Print the sorted array
    cout << "Sorted fruits in lexicographical order: ";
    for(int i = 0; i < n; i++){
        cout << fruit[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
   SHORT EXPLANATION OF strcmp():

   strcmp(a, b) compares two strings a and b:

   → returns < 0   if a comes BEFORE b in dictionary order
   → returns > 0   if a comes AFTER b in dictionary order
   → returns 0     if both strings are EQUAL
*/