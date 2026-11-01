class Solution {
public:
    int minMoves(vector<int>& nums) {
       int mine = *min_element(nums.begin(),nums.end());
       long long moves = 0;
       for(int x:nums){
        moves +=x-mine;
       }
       return moves;
    }
};