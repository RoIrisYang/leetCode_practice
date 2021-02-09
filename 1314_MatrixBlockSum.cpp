class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m = mat.size();
        int n = mat[0].size();      
        cout << m << " "<< n << endl;
        
        // add row
        for(int i = 0; i < m; i++){
            for(int j = 1; j < n; j++){
                mat[i][j] += mat[i][j-1];
            }            
        }
        // add column
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if (i > 0) mat[i][j] += mat[i-1][j];
            }
        }
                
        vector<vector<int>>ans(m);
        // compute        
        for(int i = 0; i < m; i++){        
            ans[i].resize(n);
            for(int j = 0; j < n; j++){
                int rightBottom_i, rightBottom_j;
                int leftTop_i, leftTop_j;
                                
                // find right bottom
                if(i + K >= m || K >= m){ rightBottom_i = m - 1;}                
                else{ rightBottom_i = i + K;}
                
                
                if(j + K >= n || K >= n){ rightBottom_j = n - 1;}                
                else{rightBottom_j = j + K;}
                
                bool minus_up = true, minus_left = true;
                // find left top
                if(i <= K){ 
                    leftTop_i = 0;
                    minus_up = false;
                }
                else { leftTop_i = i - K - 1;}
                
                if(j <= K){ 
                    leftTop_j = 0;
                    minus_left = false;
                }
                else { leftTop_j = j - K - 1;}    
                
                cout << i << ", " << j << ": ";
                cout << leftTop_i << ", " << leftTop_j;
                cout << " | ";
                cout << rightBottom_i << ", " << rightBottom_j;
                cout << " | ";
                cout << minus_up << ", " << minus_left;
                
                ans[i][j] = mat[rightBottom_i][rightBottom_j];                
                if(minus_up && minus_left){
                    ans[i][j] -= mat[leftTop_i][rightBottom_j]; // up
                    ans[i][j] -= mat[rightBottom_i][leftTop_j]; // left                    
                    ans[i][j] += mat[leftTop_i][leftTop_j]; // add the repeat minus part back
                }
                else if(minus_up){
                    ans[i][j] -= mat[leftTop_i][rightBottom_j]; // up
                }
                else if(minus_left){
                    ans[i][j] -= mat[rightBottom_i][leftTop_j]; // left
                }
                
                cout << endl;                    
            }
        }
        
        return ans;
    }
};