class numAndCount{
public:
    int num;
    int count;
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<string, int> hashMap;
        for(int num:nums) // O(n), unordered map find() is constant
        {
            if(hashMap.find(to_string(num)) != hashMap.end())
            {
                hashMap[to_string(num)] += 1;
            }    
            else
            {
                hashMap[to_string(num)] = 0;
            }
        }
        
        // map to vector<>        
        vector<numAndCount> heap;
        for(auto hash: hashMap)
        {
            numAndCount tmp;
            tmp.num = atoi(hash.first.c_str());
            tmp.count = hash.second;
            heap.push_back(tmp);
        }
        
        // heap sort and take out the max for k times
        vector<int> ans;        
        int heapSize = heap.size();
        for (int _k = 0; _k < k; _k++){
            // build max heap
            for (int i = heapSize / 2; i >= 1 ; i--) {
                maxHeapify(heap, i, heapSize - 1);
            }
            
            // pickTheMax
            ans.push_back(heap[0].num); 
            
            // switch with the last one for next round
            swap(heap[0], heap[heapSize - 1]);
            
            // don't look at the elements after this size (those elements dealt)
            heapSize--;
        }
        
        return ans;
    }
    
    void maxHeapify(vector<numAndCount> &array, int root, int lastIdexToCare){
        int left = 2 * root;
        int right = 2 * root + 1;
        int largest;

        if (left <= lastIdexToCare && array[left].count > array[root].count)
            largest = left;
        else
            largest = root;

        if (right <= lastIdexToCare && array[right].count > array[largest].count)
            largest = right;

        if (largest != root) {
            swap(array[largest], array[root]);
            maxHeapify(array, largest, lastIdexToCare);
        }
    }
};