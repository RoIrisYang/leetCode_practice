class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        
        vector<int> rec(n + 1, 0);
        rec[1] = 1;
        rec[2] = 2;
        
        for(int step = 3; step <= n; step++){
            rec[step] = rec[step-1] + rec[step-2];            
        }
        
        return rec[n];
    }
};