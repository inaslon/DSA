class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {

        vector<int> days{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        vector<int> prefday(days.size(), 0);

        for (int i = 1; i < days.size(); i++) {
            prefday[i] = prefday[i - 1] + days[i];
        }

        int AA, AL, BA, BL;
        AA = prefday[stoi(arriveAlice.substr(0, 2)) - 1] +
             stoi(arriveAlice.substr(3, 2));
        AL = prefday[stoi(leaveAlice.substr(0, 2)) - 1] +
             stoi(leaveAlice.substr(3, 2));

        BA = prefday[stoi(arriveBob.substr(0, 2)) - 1] +
             stoi(arriveBob.substr(3, 2));
        BL = prefday[stoi(leaveBob.substr(0, 2)) - 1] +
             stoi(leaveBob.substr(3, 2));

        int start =  max(AA, BA); 
        int end =  min(AL, BL);

        int ans = end- start+1;

        return ans<0?0:ans;
    }
};