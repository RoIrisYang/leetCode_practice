class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        /* better solution O(n + m): map + stack */        
        unordered_map<int, int> hashMap; // num : nextMax  
        stack<int> st;
        for(auto n: nums2){
            while(st.size() && st.top() < n){
                // when n is bigger, find the next biigest for st.top()
                hashMap[st.top()] = n;
                st.pop();
            }
            st.push(n);
        }
        
        vector<int> ans;
        for(auto n: nums1) 
        {
            int answer = hashMap[n] ? hashMap[n] : -1;
            ans.push_back(answer);
        } 
        return ans;
    }
};


/* brute force solution O(m^2): map */
/* 
unordered_map<int, int> hashMap;
int nums2_size = nums2.size();
for(int m = 0; m < nums2_size; m++){ // construct ans table                 
    hashMap[nums2[m]] = nums2[m];

    int next = m + 1;
    while(next < nums2_size && hashMap[nums2[m]] == nums2[m]){
        if(hashMap[nums2[m]] < nums2[next]) hashMap[nums2[m]] = nums2[next];
        next++;
    }

    if(hashMap[nums2[m]] == nums2[m]){ hashMap[nums2[m]] = -1;}
}

vector<int> ans;
for(auto n: nums1) 
{
    ans.push_back(hashMap[n]);
} 
return ans;
*/