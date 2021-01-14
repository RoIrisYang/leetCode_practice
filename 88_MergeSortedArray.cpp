class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int outputSize = nums1.size();
        int m_ = m;
        int n1_flag = 0;
        for(int i = 0; i < nums2.size(); i++){
            while(nums2[i] > nums1[n1_flag] && n1_flag < m_){
                n1_flag++;
            }
            nums1.insert(nums1.begin() + n1_flag, nums2[i]);  
            m_++;
            nums1.pop_back();
        }
    }
};