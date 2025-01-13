#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumLength(string s)
    {
        map<char, int> map;
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            map[s[i]]++;
            if (map[s[i]] % 2 == 0 && map[s[i]] != 0)
            {
                map[s[i]] = 2;
            }
            else
            {
                map[s[i]] = 1;
            }
        }
        for (int i = 0; i < map.size(); i++)
        {
            count += map[i];
        }
        return count;
    }
};