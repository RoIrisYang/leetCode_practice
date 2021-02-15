class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        
        int coinTypes = coins.size();
        // cout << "amount:" << amount << ", coin types: " << coinTypes << endl;
        vector<int>amount_bestRec;
        amount_bestRec.resize(amount + 1, amount + 1);
        amount_bestRec[0] = 0;
        
        for(int i = 1; i <= amount; i++){
            for(int s = 0; s < coinTypes; s++){
                if(coins[s] <= i) // is possible to form the amount i
                    amount_bestRec[i] = min(amount_bestRec[i], amount_bestRec[i - coins[s]] + 1);
            }
            // cout << i << ": " << amount_bestRec[i] << endl;
        }
        
        if (amount < amount_bestRec[amount]) return -1; // ans not found
        else return amount_bestRec[amount];
    }
};