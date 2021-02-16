class Solution {
public:
    int findMin(vector<int>& nums) {
        int length = nums.size();
        int left = 0, right = length -1;
        int ans = nums[0];
        while(left <= right){
            int middle = (left + right) / 2;
            
            if(nums[middle] < nums[0]){ 
                // may be the key
                ans = nums[middle];
                right = middle - 1;
            }
            else{
                left = middle + 1;
            }
        }
        
        return ans;
    }
};