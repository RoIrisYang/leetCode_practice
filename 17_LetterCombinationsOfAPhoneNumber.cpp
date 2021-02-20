class Solution {
public:
    unordered_map<char, vector<string>> map;
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits == "") return ans;
        
        map.insert({'2', {"a", "b", "c"}});
        map.insert({'3', {"d", "e", "f"}});
        map.insert({'4', {"g", "h", "i"}});
        map.insert({'5', {"j", "k", "l"}});
        map.insert({'6', {"m", "n", "o"}});
        map.insert({'7', {"p", "q", "r", "s"}});
        map.insert({'8', {"t", "u", "v"}});
        map.insert({'9', {"w", "x", "y", "z"}});               
        
        return DFS(digits, 0);
    }
    
    vector<string> DFS(string oriDigits, int dealIndex){
        if(dealIndex == oriDigits.length() - 1){ // end
            return map[oriDigits[dealIndex]];
        }
        else{
            vector<string> res;
            vector<string> sub = DFS(oriDigits, dealIndex + 1);
            for(auto i : map[oriDigits[dealIndex]]){
                for(auto s : sub){
                    res.push_back(i + s);                    
                }
            }
            return res;
        }
    }
};