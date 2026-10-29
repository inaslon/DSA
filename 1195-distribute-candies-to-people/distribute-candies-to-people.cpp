class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {

        queue<pair<int, int>> q;
        for (int i = 0; i < num_people; i++) {
            q.push({0, i});
        }

        int cand = 1;
            vector<int> ans(num_people, 0);
        while (candies > 0) {
            auto [c, idx] = q.front();
            q.pop();

            int ca = min(cand, candies);
            c += ca ;
            candies -= ca;
            cand++;

            ans[idx] += c;
            q.push({0, idx});
        }
    
       
        return ans;
    }
};