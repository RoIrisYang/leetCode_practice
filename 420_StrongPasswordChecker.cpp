class Solution {
public:
    int strongPasswordChecker(string password) {
        int length = password.length();
        if(length == 0) return 6;
        
        /* Understand the password*/
        int lowerCase = 0, upperCase = 0, oneDigit = 0;        
        int insertion = 0, replacement = 0, deletion = 0;
        
        char curChar = '_';
        int repeat = 0;
        int delete1 = 0, delete2 = 0; // delete 1 or 2 to save a replacement
        for(int i = 0; i < length; i++)
        {
            if (48 <= password[i] && password[i] <= 57) oneDigit++;
            else if (97 <= password[i] && password[i] <= 122) lowerCase++;
            else if (65 <= password[i] && password[i] <= 90) upperCase++;           
            
            if (password[i] != curChar || i == length - 1)
            {
                if (i == length - 1)
                {
                    if (password[i] == curChar) repeat++;
                }
                
                if (repeat >= 3)
                {
                    replacement += repeat / 3;
                    if (repeat % 3 == 0) delete1++;
                    else if(repeat % 3 == 1) delete2++;
                }
                curChar = password[i];
                repeat = 1;
            }
            else
            {
                repeat++;
            }
        }
        
        int missingType = 0;
        if (!oneDigit) missingType++;
        if (!lowerCase) missingType++;
        if (!upperCase) missingType++;        
        
        int leftDeletion;                
        // 6 < only insert
        if(length < 6){ 
            insertion = 6 - length;
            return max(missingType, insertion);
        }
        
        // 6 - 20: only replacement
        else if(length <= 20){
            return max(missingType, replacement);
        }
        
        // > 20: only delete
        else{
            deletion = length - 20;
            
            // deal with repeat deletion
            replacement -= min(deletion, delete1); // see if the deleton can cover replacement for every repeat lenth % 3 == 0
            
            leftDeletion = max(deletion - delete1, 0); // if the deletion are all used
            replacement -= min(leftDeletion, delete2 * 2) / 2;
            // delete twice to cover 1 replacement, /2 is to count how many replacement is covered
            
            leftDeletion = max(deletion - delete1 - delete2 * 2, 0);
            replacement -= leftDeletion / 3; // when delete 3 to cover a replacement
            
            return max(missingType, replacement) + deletion;
        }
    }
};