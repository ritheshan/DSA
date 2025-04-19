#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
      
    vector<int> majorityElement(vector<int>& nums) {
        // if (nums.size()/3 < 1 ) return nums;
        unordered_map<int, int> map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]+=1;
        }
        vector<int> ans;
        for(auto [num , count]:map){
            if(count>nums.size()/3) ans.push_back(num);
            if(ans.size()==2) break;
        }

        return ans;
    }
};