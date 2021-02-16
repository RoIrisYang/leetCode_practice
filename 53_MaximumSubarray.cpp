class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int arrSize = nums.size();
        if(arrSize == 1) return nums[0];
        
        vector<int> rec(arrSize, 0);
        rec[0] = nums[0];
        int maxSum = rec[0];
        
        for(int i = 1; i < arrSize; i++){
            rec[i] = nums[i] + (rec[i-1] > 0 ? rec[i-1] : 0);
            if(rec[i] > maxSum) maxSum = rec[i];
        }       
        
        return maxSum;
    }
};