class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();

       vector<int> lastidx(26,-1);
       for(int i = 0;i<n;i++){
        lastidx[s[i]-'a'] =i;
       }

       vector<int> vis(26,0);

       string ans ="";
       for(int i = 0;i<n;i++){
        char ch = s[i];
        if(vis[ch-'a'] == 1) continue;

        while(!ans.empty() && ch<ans.back() && lastidx[ans.back()-'a']>i){
            vis[ans.back()-'a'] = 0;
            ans.pop_back();
        }

        vis[ch-'a'] = 1;
        ans.push_back(ch);
       }

       return ans;
    }
};