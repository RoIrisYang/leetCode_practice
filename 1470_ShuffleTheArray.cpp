class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int length = nums.size();
        int take_index = length - 1;
        
        for(int i = length - 1, insertIndex = n; i > n-1 && insertIndex > 0; i--, insertIndex--){  
            int processValue = nums[take_index];            
            nums.insert(nums.begin() + insertIndex, processValue);
            nums.pop_back();
        }
        return nums;
    }
};