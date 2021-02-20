class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {        
        int left = 0, right = nums.size() - 1;
        int ans = left;
        while(left <= right){
            int middle = (left + right) / 2;
            
            if(nums[middle] == target) return middle;
            else if (nums[middle] < target){
                left = middle + 1;    
                ans = left;
            }
            else { // nums[middle] > target
                right = middle - 1;
            }            
        }
        
        // not found
        
        if(right == nums.size() - 1) ans = nums.size(); // new at the end of nums        
        
        return ans; 
    }
};