class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {

        set<int> st;
        int n = seats.size();

        for(int i = 0;i<n;i++){
            if(seats[i]!= 0 ){
                st.insert(i);
            }
        }

        int ans = 0;

        for(int i = 0;i<n;i++){
            if(seats[i] == 0){

                auto it = st.lower_bound(i);

                int left = INT_MAX;
                int right = INT_MAX;

                if(it != st.end()){

                    right = *it-i;
                }

                if(it != st.begin()){
                    --it;
                    left = i- *it;
                }

                int dis = min(left,right);
                ans = max(ans,dis);
            }
        }

        return ans;
        
    }
};