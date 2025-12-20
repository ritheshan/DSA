#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int size = strs.size();
        int count=0;
        for(int i = 0; i <strs[0].size(); i++){
            for(int j=0;j<size-1; j++)
            if(strs[j][i] > strs[j+1][i]){
                count++;
                break;
            }
        }
        return count;
    }
};