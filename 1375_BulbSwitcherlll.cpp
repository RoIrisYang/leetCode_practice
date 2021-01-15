class Solution {
public:
    int curOn_max = 0;
    int moment = 0;
    int numTimesAllBlue(vector<int>& light) {
        // All the bulb turned on before must shin
        for (int l = 0; l < light.size(); l++){
            // check if the curOn_max is light[i] - 1
            // ex. light[i] = 63, curOn_max = 62, l = 62 (start from 0); 
            //     > new curOn_max = 63 -> true     
            curOn_max = max(curOn_max, light[l]);
            if(curOn_max == l + 1){
                moment++;
            }
        }
        
        return moment;
    }
};