class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<string, int> hashMap;
        for(int num:nums) // O(nlogn), find() is logn
        {
            if(hashMap.find() != hashMap.end())
            {
                hashMap[to_string(num)] += 1;
            }    
            else
            {
                hashMap[to_string(num)] = 0;
            }
        }
        
        
    }
};