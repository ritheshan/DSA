
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int> map ;
        int sum=0;
        int rem=0;
        int maxLen=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum==k){
               maxLen=max(maxLen,i+1) ;
               
            }
            rem=sum-k;
            if(map.find(rem)!=map.end()){
                int len=i-map[rem];
                maxLen=max(maxLen,len);
                
            }
            // here where the code is different from previous one  , this case arises when there [2,0,0,3] for k=3 , it gives result as 1 for maxlen , but it should be 3 i.e{0,0,3}
            if(map.find(sum)==map.end()){
                map[sum]=i;
            }
            
        }
        return maxLen;
    }
};