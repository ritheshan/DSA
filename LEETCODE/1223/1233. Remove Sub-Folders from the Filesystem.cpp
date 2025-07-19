#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> res;
        for (const string& f : folder) {
            if (res.empty() ||
                f.substr(0, res.back().size() + 1) != res.back() + "/") {
                res.push_back(f);
            }
        }
        return res;
    }
};