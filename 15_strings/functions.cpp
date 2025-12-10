#include <iostream>
#include <string>
#include <algorithm> // reverse()
#include <cstring>   // strcat()
using namespace std;

int main()
{

    // 1. reverse()
    // string str = "hello";
    // reverse(str.begin(), str.end());
    // cout << str << endl;
    // OUTPUT 1 → olleh
    // -----------------------------------------

    // 2. substr()
    // string str = "survive";
    // cout << str.substr(1, 4) << endl;
    // OUTPUT 2 → urvi
    // -----------------------------------------

    // 3. "+" operator
    // string s1 = "college";
    // string s2 = "wallah";
    // s1 += s2;
    // cout << s1 << endl;
    // OUTPUT 3 → collegewallah
    // -----------------------------------------

    // 4. strcat()
    // char s1[20] = "college";
    // char s2[20] = "wallah";
    // strcat(s1, s2);
    // cout << s1 << endl;
    // OUTPUT 4 → collegewallah
    // -----------------------------------------

    // 5. push_back()
    // string s1 = "abcd";
    // char ch = 'e';
    // s1.push_back(ch);
    // cout << s1 << endl;
    // OUTPUT 5 → abcde
    // -----------------------------------------

    // 6. size()
    // string str = "Nikhil";
    // cout << str.size() << endl;
    // OUTPUT 6 (1st) → 6

    // char ch[20] = "Ranjan";
    // cout << strlen(ch) << endl;
    // OUTPUT 6 (2nd) → 6
    // -----------------------------------------

    // 7. to_string()
    // int num = 432;
    // string str = to_string(num);
    // str += "1";
    // cout << str << endl;
    // OUTPUT 7 → 4321
    // -----------------------------------------

    return 0;
}
