class Solution {
    void dfs(int u, int p, vector<vector<int>>& graph, vector<vector<int>>& ans,
             vector<int> &temp) {
        temp.push_back(u);
        if(u == graph.size()-1){
               ans.push_back(temp);;
        
        }
        for (int v : graph[u]) {
            if (v == p)
                continue;
            dfs(v, u, graph, ans, temp);
        }

     temp.pop_back();
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> temp;

        dfs(0,-1,graph,ans,temp);

        return ans;
    }
};