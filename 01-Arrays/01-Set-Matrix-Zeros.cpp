
// Brute Force

void markRow(int i , int j , int n , int m , vector<vector<int>>&matrix){
	for(int j=0 ; j<m ; j++){
		if(matrix[i][j] != 0){
			matrix[i][j] = -1;
		}
	}
}
void markCol(int i , int j , int n ,int m , vector<vector<int>>&matrix){
	for(int i=0 ; i<n ; i++){
		if(matrix[i][j] != 0){
			matrix[i][j] = -1;
		}
	}
}

void setZeros(vector<vector<int>> &matrix)
{
	int n = matrix.size() , m = matrix[0].size();
	for(int i=0 ;i<n ; i++){
		for(int j=0 ; j<m ; j++){
			if(matrix[i][j] == 0){
				markRow(i,j,n,m,matrix);
				markCol(i,j,n,m,matrix);
			}
		}
	}
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<m ; j++){
			if(matrix[i][j] == -1) {
				matrix[i][j] = 0;
			}
		}
	}
}

// Better

void setZeros(vector<vector<int>> &matrix)
{
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


// Optimal
void setZeros(vector<vector<int>> &matrix)
{
	int r = matrix.size();
	int c = matrix[0].size();
	int col0 = 1;
	for(int i=0 ; i<r ; i++){
		for(int j=0 ; j<c ; j++){
			if(matrix[i][j] == 0){
				matrix[i][0] = 0;
				if(j != 0){
					matrix[0][j] = 0;
				}
				else{
					col0 = 0;
				}
			}
		}
	}
	//
	for(int i=1 ; i<r ; i++){
		for(int j=1 ; j<c ; j++){
			if(matrix[i][j] != 0){
				if(matrix[i][0] == 0 || matrix[0][j] == 0){
					matrix[i][j] = 0;
				}
			}
		}
	}
	if(matrix[0][0] == 0){
		for(int i=0 ; i<c ; i++){
			matrix[0][i] = 0;
		}
	}
	if(col0 == 0){
		for(int i=0; i<r ; i++){
			matrix[i][0] = 0;
		}
	}
}

