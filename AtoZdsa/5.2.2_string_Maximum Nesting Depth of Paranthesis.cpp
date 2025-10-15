#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDepth(string s) {
        int count=0;
        int Max=0;
        for(auto c: s){
            if(c=='('){
                count++;

            }else if(c==')'){
                count--;
            }
            Max=max(count,Max);
        }

        return Max;
    }
};