#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        long long totalApples = 0;
        for (int a : apple) totalApples += a;

        sort(capacity.begin(), capacity.end(), greater<int>());

        long long curr = 0;
        int boxes = 0;
        for (int c : capacity) {
            curr += c;
            boxes++;
            if (curr >= totalApples) break;
        }
        return boxes;
    }
};