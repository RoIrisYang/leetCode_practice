class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // use the concept of longest common subsequence
        int length = nums.size(); 
        if(length == 1) return 1;
        vector<int> dp_rec(length, 1);
        
        int maxAns = 1;
        for(int i = 1; i < length; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){ // bigger to accumulate
                    dp_rec[i] = max(dp_rec[i], dp_rec[j] + 1);
                }
            }
            
            maxAns = max(maxAns, dp_rec[i]);
        }
        
        return maxAns;
    }
};