class Solution {

    vector<int> arr;
    bool ispossible(int mid,int h){
       long long cnt = 0;
       for(int num:arr){
        
        double x = double(num)/double(mid);
        cnt += ceil(x);

       }

       return cnt<= h;

    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = 0;
        arr = piles;
        int low = 1,high = *max_element(piles.begin(),piles.end());

        while(low<=high){
            int mid = low+ (high - low)/2;

            if(ispossible(mid,h)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return ans;
    }
};