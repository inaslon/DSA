class Solution {
    vector<vector<int>> ans;
    int n;
    vector<int> arr;

    void solve(int idx, int target, vector<int>& temp) {
        if (target == 0) {
            
         
            ans.push_back(temp);
            return;
        }
        if (idx >= n)
            return;

        solve(idx+1,target,temp);

        if(target-arr[idx]>=0){
            temp.push_back(arr[idx]);
            solve(idx,target-arr[idx],temp);
            temp.pop_back();
        }    

    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        arr = candidates;
        vector<int> temp;
        ans.clear();
        solve(0,target,temp);
    


        return ans;
    }
};