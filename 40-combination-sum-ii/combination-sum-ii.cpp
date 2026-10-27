class Solution {
    vector<vector<int>> ans;

    int n;
    vector<int> arr;

    void solve(int idx, int target, vector<int> temp) {
        if (target == 0) {

            sort(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }
        if (idx >= n)
            return;

        int j = idx+1;
        while(j<n && arr[j] == arr[idx]){
            j++;
        }    

        solve(j, target, temp);

        if (target - arr[idx] >= 0) {

            temp.push_back(arr[idx]);
            solve(idx + 1, target - arr[idx], temp);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();
        sort(candidates.begin(),candidates.end());

        arr = candidates;

        ans.clear();
        vector<int> temp;
        solve(0, target, temp);
       

        return ans;
    }
};