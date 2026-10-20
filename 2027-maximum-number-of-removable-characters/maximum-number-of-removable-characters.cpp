class Solution {
    bool issubsequence(string& s, string& ss,vector<int>& removable,int mid) {
        string temp = s;

        for(int i = 0;i<mid;i++){
            temp[removable[i]] = '$';
        }
        int i = 0, j = 0;
        while (i < s.length() && j < ss.length()) {
            if (temp[i] != '$' && temp[i] == ss[j]) {
                j++;
            }
            i++;
        }
        if (j == ss.length())
            return true;

        return false;
    }

public:
    int maximumRemovals(string s, string p, vector<int>& removable) {

        int n = removable.size();
        int ans = 0;
        int low = 0,high = n;
        while(low<=high){

            int mid = low + (high - low)/2;


            if(issubsequence(s,p,removable,mid)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        
        return ans;
    }
};