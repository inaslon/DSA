class Solution {
    string s1,s2;
    int m,n;
    int dp[502][502];
    int solve(int i, int j){
        if( i== m && j == n) return 0;
        if(i == m ){
            return n-j;
        }
        if(j ==n) return m-i;

        if(dp[i][j] !=-1) return dp[i][j];


        if(s1[i] == s2[j]){
            return  dp[i][j] = solve(i+1,j+1);
        }

        return  dp[i][j] = min({1+solve(i,j+1),1+solve(i+1,j),1+ solve(i+1,j+1)});
    }
public:
    int minDistance(string word1, string word2) {
        
        s1 = word1;
        s2 = word2;
        m = s1.length();
        n = s2.length();
        memset(dp,-1,sizeof(dp));
        return solve(0,0);
    }
};