#include<vector>
using namespace std;
class Solution {
public: 
    vector<int> generateRow(int row){
        vector<int> ansrow;
        int ans=1;
        ansrow.push_back(ans);
        for(int col=1;col<row;col++){
            ans=ans*(row-col);
            ans=ans/col;
            ansrow.push_back(ans);
        }
        return ansrow;

        

    }
    vector<vector<int>> ans;
    vector<vector<int>> generate(int numRows) {
        for(int i=1;i<=numRows;i++){
          
           vector<int> temp=generateRow(i);
            ans.push_back(temp);
        }
        return ans;
    }
};