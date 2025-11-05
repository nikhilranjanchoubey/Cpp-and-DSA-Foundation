#include <iostream>
using namespace std;

// Recursive function to check if a number is a palindrome
bool isPalindrome(int num, int *temp) {
    // Base case: single-digit comparison
    if (num >= 0 && num <= 9) {
        int lastDigitOfTemp = (*temp) % 10;
        (*temp) /= 10;
        return (num == lastDigitOfTemp);
    }

    // Recursive call and digit comparison
    bool result = (isPalindrome(num / 10, temp) && (num % 10 == (*temp) % 10));
    (*temp) /= 10; // Move temp pointer to next digit
    return result;
}

int main() {
    int num = 12621;
    int anotherNum = num;
    int *temp = &anotherNum;

    // Call the recursive function and print result
    if (isPalindrome(num, temp)) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Not Palindrome" << endl;
    }

    return 0;
}