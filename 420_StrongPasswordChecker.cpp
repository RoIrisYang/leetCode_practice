class Solution {
public:
    int strongPasswordChecker(string password) {
        int length = password.length();
        if(length == 0) return 6;
        
        /* Understand the password*/
        int lowerCase = 0, upperCase = 0, oneDigit = 0;        
        int insertion = 0, replacement = 0, deletion = 0;
        
        vector<char> repeatCheckWindow;
        for(int i = 0; i < length; i++)
        {
            if (48 <= password[i] && password[i] <= 57) oneDigit++;
            else if (97 <= password[i] && password[i] <= 122) lowerCase++;
            else if (65 <= password[i] && password[i] <= 90) upperCase++;           
            
            repeatCheckWindow.push_back(password[i]);
            if (repeatCheckWindow.size() >= 3) {
                if(repeatCheckWindow[0] == repeatCheckWindow[1] && repeatCheckWindow[1] == repeatCheckWindow[2])
                {
                    replacement++;
                    repeatCheckWindow.clear();
                }
                else
                {
                    repeatCheckWindow.erase(repeatCheckWindow.begin());
                }
            }
        }
        
        int missingType = 0;
        if (!oneDigit) missingType++;
        if (!lowerCase) missingType++;
        if (!upperCase) missingType++;
                
        // 6 < only insert
        if(length < 6){ 
            insertion = 6 - length;
            return max(missingType, insertion);
        }
        
        // 6 - 20: only replacement
        else if(length < 20){
            return max(missingType, replacement);
        }
        
        // > 20: only delete
        else{
            deletion = length - 20;
            return max(max(missingType, replacement), deletion);
        }
    }
};