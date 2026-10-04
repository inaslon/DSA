class Solution {
public:
    bool checkValidString(string s) {

        int maxopen = 0;
        int minopen = 0;

        for( auto ch : s){

            if(ch == '('){
                maxopen++;
                minopen++;
            }
            else if(ch == ')'){
                maxopen--;
                minopen--;

                if(maxopen<0){
                    return false;
                }
                minopen = max(minopen,0);
            }
            else{
                maxopen++;
                minopen--;
                
                minopen = max(minopen,0);

            }
        }

        return minopen == 0;
        
    }
};