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

/*
bool lowerCase = false, upperCase = false, oneDigit = false;
bool repeat3butNotSticky = false;        
int length = password.length();
unordered_map<char, int> hashMap;
int maxCount = 0;
char maxCountChar;
for(int i = 0; i < length; i++)
{
    if (48 <= password[i] && password[i] <= 57) oneDigit = true;
    
    if (97 <= password[i] && password[i] <= 122) lowerCase = true;
    
    if (65 <= password[i] && password[i] <= 90) upperCase = true;
    
    // three repeating characters
    char hashKey = password[i];
    if(hashMap.find(hashKey) != hashMap.end()) hashMap[hashKey] += 1;
    else hashMap[hashKey] = 1;
    
    if (hashMap[hashKey] > maxCount){
        maxCountChar = hashKey;
        maxCount = hashMap[hashKey];
    } 
    
    if (hashMap[hashKey] == 3)
    { 
        bool i_i = (1 <= i && i < length - 1 && !(password[i-1] == password[i] && password[i+1] == password[i]));
        bool ii_ = (2 <= i && (password[i - 1] == password[i] || password[i - 2] == password[i]));
        bool _ii = (i < length - 2  && (password[i + 1] == password[i] || password[i + 2] == password[i]));
        if (!i_i && !ii_ && !_ii)
        {
            repeat3butNotSticky = true;
        }                
    }
}
        
string newPassword = password;

if (!lowerCase) newPassword += "a";
if (!upperCase) newPassword += "A";
if (!oneDigit)  newPassword += "0";
                
int outputSteps = newPassword.length() - password.length();     
length = newPassword.length();
if(length < 6) {outputSteps += 6 - length;}            
else if(20 < length) {outputSteps += length - 20;}
            
if (!repeat3butNotSticky && maxCount == 3){                 
    outputSteps++; // swap to other position or add 1 char
}

return outputSteps;
*/