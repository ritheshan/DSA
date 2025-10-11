#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeOuterParentheses(string s) {
        int balance = 0;
        string res;
        for(char c : s){
            if(c=='('){
                
                if(balance >0 ) res +='(';
                balance++;
            }else{
                balance--;
                if(balance>0) res +=')';
            }
        }
        return res;
    }
};