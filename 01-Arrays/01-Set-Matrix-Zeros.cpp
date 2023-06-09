// Brute Force
class Solution {
public:
    void markRow(int i , int n , int m , vector<vector<int>> &matrix){
        for(int j=0 ; j<m ; j++){
            if(matrix[i][j] != 0){
                matrix[i][j] = -1;
            }
        }
    }
    void markCol(int j , int n , int m , vector<vector<int>> &matrix){
        for(int i=0 ; i<n ; i++){
            if(matrix[i][j] != 0){
                matrix[i][j] = -1;
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size() ,m = matrix[0].size();
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(matrix[i][j] == 0){
                    markRow(i,n,m,matrix);
                    markCol(j,n,m,matrix);
                }
            }
        }
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(matrix[i][j] == -1){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// Better
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size();
        vector<int>row(n , 1) , col(m , 1);
        for(int i=0 ;i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(matrix[i][j] == 0){
                    row[i] = 0;
                    col[j] = 0;
                }
            }
        }
        for(int i=0 ;i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(row[i] == 0 || col[j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// Optimal
class Solution {
	public:
	void setZeros(vector<vector<int>> &matrix){
		int n = matrix.size() , m = matrix[0].size();
		int col0 = 1;
		for(int i=0 ; i<n ; i++){
			for(int j=0 ;j<m ; j++){
				if(matrix[i][j] == 0){
					if(j==0){
						col0 = 0;
						matrix[i][0] = 0;
					}
					else{
						matrix[0][j] = 0; // mark for row
						matrix[i][0] = 0; // mark for col
					}
				}
			}
		}
		for(int i=1 ; i<n ; i++){
			for(int j=1 ; j<m ; j++){
				if(matrix[i][j] != 0){
					if(matrix[i][0] == 0 || matrix[0][j] == 0){
						matrix[i][j] = 0;
					}
				}
			}
		}
		if(matrix[0][0] == 0){
			// mark first row
			for(int j=0 ;j<m ; j++){
				matrix[0][j] = 0;
			}
		}
		if(col0 == 0){
			// mark first column
			for(int i=0 ; i<n ; i++){
				matrix[i][0] = 0;
			}
		}
	}
};