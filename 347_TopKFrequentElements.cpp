class numAndCount{
public:
    int num;
    int count;
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;  
        unordered_map<string, int> hashMap;
        for(int num:nums) // O(n), unordered map find() is constant
        {
            if(hashMap.find(to_string(num)) != hashMap.end())
            {
                hashMap[to_string(num)] += 1;
            }    
            else
            {
                hashMap[to_string(num)] = 1;
            }
        }
        
        // map to vector<>        
        vector<numAndCount> heap;
        numAndCount nul;
        heap.push_back(nul);
        for(auto hash: hashMap)
        {
            numAndCount tmp;
            tmp.num = atoi(hash.first.c_str());
            tmp.count = hash.second;
            heap.push_back(tmp);
        }        
        
        // build max heap 
        int heapSize = heap.size() - 1;
        for (int i = heapSize / 2; i > 0 ; i--) {
            maxHeapify(heap, i, heapSize);
        }
        
         // heap sort and take out the max for k time   
        for (int _k = 0; _k < k; _k++){                      
            // pickTheMax
            ans.push_back(heap[1].num); 
            
            // switch with the last one for next round
            swap(heap[1], heap[heapSize]);
            
            // don't look at the elements after this size (those elements dealt)
            heapSize--;
            
            maxHeapify(heap, 1, heapSize);
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