class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        
        sort(courses.begin(),courses.end(),[](auto &a, auto &b){

            return a[1]<b[1];
        });

        int sum = 0;
        priority_queue<int> pq;

        for(auto a:courses){

            sum += a[0];
            pq.push(a[0]);

            if(sum>a[1]){
                sum -=pq.top();
                pq.pop();
            }
        }


        return pq.size();
    }
};