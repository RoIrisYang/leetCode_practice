class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        bool comment = false;        
        string debug = "";
        vector<string> output;
        int startCommentIndex, endCommentIndex;
        for(int i=0; i < source.size(); i++) {
            string output_s = "";
            for (int w = 0; w < source[i].length(); w++){                
                if(!comment && w < source[i].length() - 1 && source[i][w] == '/' && source[i][w + 1] == '*') // find '/*'
                {
                    comment = true;  
                    w++;
                    startCommentIndex = i;
                    
                }
                else if(comment && w < source[i].length() - 1 && source[i][w] == '*' && source[i][w + 1] == '/') // find '*/'
                {
                    comment = false;
                    w++;
                    endCommentIndex = i;
                }
                else if(!comment && w < source[i].length() - 1 && source[i][w] == '/' && source[i][w + 1] == '/') // find '//'
                {                
                    if (w != 0)
                        source[i] = source[i].substr(0, w);
                    else
                        source[i] = "";
                
                }
                else if(!comment) { 
                    output_s += source[i][w];
                }
            }     
            if (output_s != "")
            {
                if (!comment && startCommentIndex != endCommentIndex && endCommentIndex == i)
                {
                    output[output.size()-1] += output_s;
                    startCommentIndex = endCommentIndex;
                }
                else { output.push_back(output_s); }
            }
        }                    
        
        return output;
    }
};