class Solution {
public:
    int smallestRepunitDivByK(int K) {      
        int digits = 1;
        // int N = 1;
        int remainder = 1;
        set<int> remainders;
        
        while (remainder % K != 0 ) {
            remainders.insert(remainder);
            remainder = (remainder * 10 + 1) % K;
            
            if (remainders.find(remainder) != remainders.end()) return -1;
            digits++;
        }
        
        return digits;
    }
};