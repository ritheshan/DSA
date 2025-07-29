#include <bits/stdc++.h>
using namespace std;


/******************************************************
🔹 1. stringstream — Tokenizing/Splitting Strings
******************************************************/
#include <sstream>
string s = "I love C++";
stringstream ss(s);
string word;
while (ss >> word) {
    cout << word << endl;
}
// Output:
// I
// love
// C++


/******************************************************
🔹 2. getline — Split by Custom Delimiter
******************************************************/
#include <sstream>
string s = "apple,banana,grape";
stringstream ss(s);
string token;
while (getline(ss, token, ',')) {
    cout << token << endl;
}
// Output:
// apple
// banana
// grape


/******************************************************
🔹 3. erase + remove — Remove All Occurrences of a Character
******************************************************/
#include <algorithm>
string s = "a b c d";
s.erase(remove(s.begin(), s.end(), ' '), s.end()); // "abcd"
cout << s << endl;


/******************************************************
🔹 4. reverse() — Reverse String or Vector
******************************************************/
#include <algorithm>
string s = "hello";
reverse(s.begin(), s.end());  // s = "olleh"
cout << s << endl;


/******************************************************
🔹 5. find() and substr() — Search and Slice
******************************************************/
string s = "helloworld";
int pos = s.find("world");       // pos = 5
string sub = s.substr(0, 5);     // sub = "hello"
cout << pos << " " << sub << endl;


/******************************************************
🔹 6. to_string() and stoi() — Convert Between String and Int
******************************************************/
int n = 42;
string str = to_string(n);         // str = "42"
int x = stoi("123");               // x = 123
cout << str << " " << x << endl;


/******************************************************
🔹 7. isalpha(), isdigit(), isalnum() — Character Classification
******************************************************/
#include <cctype>
char c = 'A';
if (isalpha(c)) cout << "Letter\n";
if (isdigit(c)) cout << "Digit\n";
if (isalnum(c)) cout << "Alphanumeric\n";


/******************************************************
🔹 8. set / unordered_set — Uniqueness Check
******************************************************/
#include <unordered_set>
string s = "abca";
unordered_set<char> seen;
for (char c : s) {
    if (seen.count(c)) {
        cout << "Duplicate: " << c << endl;
    }
    seen.insert(c);
}


/******************************************************
🔹 9. map / unordered_map — Frequency Count
******************************************************/
#include <unordered_map>
string s = "aabc";
unordered_map<char, int> freq;
for (char c : s) freq[c]++;
for (auto &[ch, cnt] : freq) {
    cout << ch << " → " << cnt << endl;
}
// Output:
// a → 2
// b → 1
// c → 1


/******************************************************
🔹 10. sort() + Lambda — Custom Sorting
******************************************************/
#include <algorithm>
vector<string> words = {"hi", "hello", "hey"};

// Sort by string length (ascending)
sort(words.begin(), words.end(), [](string &a, string &b) {
    return a.length() < b.length();
});

// Sort by last character
sort(words.begin(), words.end(), [](string &a, string &b) {
    return a.back() < b.back();
});

// Output the sorted vector
for (auto &w : words) {
    cout << w << " ";
}
cout << endl;


/******************************************************
✅ Summary Table — Quick Reference
******************************************************/

// Tool              | Use Case
// ------------------|-------------------------------
// stringstream       Tokenizing/splitting strings
// getline()          Splitting by custom delimiter
// erase + remove     Removing characters (like spaces)
// reverse()          Reversing strings or vectors
// find, substr       Searching and slicing strings
// to_string, stoi    Convert between string & int
// isalpha, isdigit   Character classification
// set, unordered_set Uniqueness checking
// map, unordered_map Frequency/count tracking
// sort() + lambda    Custom sorting of words/strings

#include <bits/stdc++.h>
using namespace std;

/*
========================================
💡 What is a Lambda Function?
- An inline anonymous function.
- Introduced in C++11.
- Commonly used with STL: sort(), for_each(), etc.

Syntax:
auto func = [capture](parameters) -> returnType {
    // body
};
========================================
*/


/******************************************************
🔹 1. Basic Lambda
******************************************************/
auto greet = []() {
    cout << "Hello, Lambda!" << endl;
};
greet();  // Output: Hello, Lambda!


/******************************************************
🔹 2. Lambda with Parameters
******************************************************/
auto add = [](int a, int b) {
    return a + b;
};
cout << add(3, 5);  // Output: 8


/******************************************************
🔹 3. Lambda with Return Type
******************************************************/
auto multiply = [](int a, int b) -> long long {
    return 1LL * a * b;
};


/******************************************************
🔹 4. Lambda with Captures
******************************************************/
int x = 10;
auto printX = [x]() { // capture by value
    cout << x;
};
printX(); // Output: 10

int y = 20;
auto modifyY = [&y]() { // capture by reference
    y += 10;
};
modifyY();
cout << y; // Output: 30


/******************************************************
🔹 5. Capture Modes Summary
******************************************************/

// []        -> capture nothing
// [x]       -> capture x by value
// [&x]      -> capture x by reference
// [=]       -> capture all used variables by value
// [&]       -> capture all used variables by reference
// [=, &x]   -> all by value, x by ref
// [&, x]    -> all by ref, x by value


/******************************************************
🔹 6. Lambda in sort() — Custom Sorting
******************************************************/
vector<string> words = {"hi", "hello", "a"};

sort(words.begin(), words.end(), [](string &a, string &b) {
    return a.length() < b.length(); // by increasing length
});


/******************************************************
🔹 7. Lambda with Helper Inside sort() (e.g., Vowel Count)
******************************************************/
auto countVowels = [](const string &s) {
    int cnt = 0;
    for (char c : s) {
        c = tolower(c);
        if (c == 'a'||c == 'e'||c == 'i'||c == 'o'||c == 'u') cnt++;
    }
    return cnt;
};

sort(words.begin(), words.end(), [&](string &a, string &b) {
    return countVowels(a) < countVowels(b);
});


/******************************************************
🔹 8. for_each() with Lambda
******************************************************/
vector<int> arr = {1, 2, 3};
for_each(arr.begin(), arr.end(), [](int x) {
    cout << x * 2 << " ";
});


/******************************************************
🔹 9. count_if(), all_of(), any_of()
******************************************************/
vector<int> nums = {1, 3, 5};
bool allOdd = all_of(nums.begin(), nums.end(), [](int x) {
    return x % 2 == 1;
});
cout << (allOdd ? "All odd" : "Not all odd");


/******************************************************
🔹 10. accumulate() with Lambda
******************************************************/
#include <numeric>
int sum = accumulate(nums.begin(), nums.end(), 0, [](int acc, int x) {
    return acc + x;
});


/******************************************************
🔹 11. Lambda with std::function (Named function object)
******************************************************/
#include <functional>
function<int(int, int)> maxFunc = [](int a, int b) {
    return max(a, b);
};


/******************************************************
🔹 12. Real Use Case: Sort Pairs by Second then First
******************************************************/
vector<pair<int, int>> vp = {{1, 3}, {2, 2}, {2, 3}};
sort(vp.begin(), vp.end(), [](pair<int,int> &a, pair<int,int> &b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
});


/******************************************************
🔹 Bonus: Lambda with string tools in DSA
******************************************************/
stringstream ss("  hello   world  ");
string word;
vector<string> tokens;
while (ss >> word) tokens.push_back(word);

reverse(tokens.begin(), tokens.end());

for (auto &w : tokens) cout << w << " ";  // "world hello"


/******************************************************
📌 Summary of Tools Often Used with Lambda
******************************************************/

// STL + Lambda Combo:
- sort(vec.begin(), vec.end(), [](auto a, auto b) { ... });
- for_each(...);
- count_if(...);
- all_of(...);
- accumulate(...);

// Also pair well with:
- map / unordered_map
- set / unordered_set
- stringstream / getline
- isalpha, isdigit, etc.
- to_string / stoi / substr / find

/*******************************************************************************************
🔹 13. regex — Pattern Matching in Strings
*******************************************************************************************/
#include <regex>
{
    string s = "abc123xyz";
    regex re("[0-9]+");  // Match one or more digits
    smatch match;
    if (regex_search(s, match, re)) {
        cout << "First number: " << match[0] << endl;  // Output: 123
    }
}

/*******************************************************************************************
🔹 14. transform — Convert Case of Entire String
*******************************************************************************************/
{
    string s = "HeLLo";
    transform(s.begin(), s.end(), s.begin(), ::tolower);  // "hello"
    transform(s.begin(), s.end(), s.begin(), ::toupper);  // "HELLO"
    cout << s << endl;
}

/*******************************************************************************************
🔹 15. next_permutation — Generate All Permutations
*******************************************************************************************/
{
    string s = "abc";
    sort(s.begin(), s.end());
    do {
        cout << s << " ";
    } while (next_permutation(s.begin(), s.end()));
    // Output: abc acb bac bca cab cba
}

/*******************************************************************************************
🔹 16. replace — Replace All Occurrences of a Character
*******************************************************************************************/
{
    string s = "a b c d";
    replace(s.begin(), s.end(), ' ', '_');  // "a_b_c_d"
    cout << s << endl;
}

/*******************************************************************************************
🔹 17. unique + erase — Remove Consecutive Duplicates
*******************************************************************************************/
{
    string s = "aaabbccc";
    s.erase(unique(s.begin(), s.end()), s.end());  // "abc"
    cout << s << endl;
}

/*******************************************************************************************
🔹 18. string::compare — Lexicographical Comparison
*******************************************************************************************/
{
    string a = "apple", b = "banana";
    if (a.compare(b) < 0)
        cout << "apple comes before banana" << endl;
}

/*******************************************************************************************
🔹 19. distance — Get Index from Iterator
*******************************************************************************************/
{
    string s = "hello";
    auto it = find(s.begin(), s.end(), 'e');
    if (it != s.end()) {
        int idx = distance(s.begin(), it);
        cout << "'e' is at index: " << idx << endl;  // Output: 1
    }
}

/*******************************************************************************************
🔹 20. bitset — Binary Representation of Numbers
*******************************************************************************************/
#include <bitset>
{
    bitset<8> b(5);  // Binary: 00000101
    cout << b.to_string() << endl;
}

/*******************************************************************************************
🔹 21. find_if — First Character Matching Condition
*******************************************************************************************/
{
    string s = "aB3$";
    auto it = find_if(s.begin(), s.end(), [](char c) {
        return isdigit(c);
    });
    if (it != s.end()) cout << "First digit: " << *it << endl;  // Output: 3
}

/*******************************************************************************************
🔹 22. stack with strings — Reverse or Palindrome Problems
*******************************************************************************************/
{
    string s = "racecar";
    stack<char> st;
    for (char c : s) st.push(c);

    string rev = "";
    while (!st.empty()) {
        rev += st.top();
        st.pop();
    }

    cout << (rev == s ? "Palindrome" : "Not Palindrome") << endl;
}

/*******************************************************************************************
🔹 23. string::front(), back(), empty()
*******************************************************************************************/
{
    string s = "hello";
    cout << s.front() << " " << s.back() << endl;  // Output: h o
    if (!s.empty()) cout << "String is not empty" << endl;
}

/*******************************************************************************************
🔹 Bonus Summary — Tools Not in Original Code
*******************************************************************************************/
// Tool             | Purpose
// -----------------|---------------------------------------------------
// regex            | Pattern matching with regular expressions
// transform        | Convert whole string to upper/lower case
// next_permutation | Generate all permutations
// replace          | Replace all characters
// unique + erase   | Remove consecutive duplicates
// compare()        | Lexicographical comparison
// distance()       | Index from iterator
// bitset           | Binary representation of integers
// find_if          | Search by condition with lambda
// stack            | Useful in reversing, palindromes, balancing
// front/back/empty | Quick string property access