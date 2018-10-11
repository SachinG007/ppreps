#include <iostream>
using namespace std;
const int MAX = 50;

void Util(bool vis[MAX][MAX], int mat[MAX][MAX], int &length, int row, int col, int N, int M){
    
    vis[row][col] = true;
    length ++;
    
    if(row-1>=0 && col-1 >=0 && mat[row-1][col-1]==1 && !vis[row-1][col-1]){
        Util(vis, mat, length, row-1, col-1, N, M);
    }
    if(row-1 >=0 && mat[row-1][col]==1 && !vis[row-1][col]){
        Util(vis, mat, length, row-1, col, N, M);
    }
    if(row-1 >=0 && col+1<M && mat[row-1][col+ 1]==1 && !vis[row-1][col+1]){
        Util(vis, mat, length, row-1, col+1,  N, M);
    }
    if(col-1 >=0 && mat[row][col-1]==1 && !vis[row][col-1]){
        Util(vis, mat, length, row, col-1, N, M);
    }
    if(col+1<M && mat[row][col+1]==1 && !vis[row][col+1]){
        Util(vis, mat, length, row, col+1, N, M);
    }
    if(row+1<N && col-1>=0 && mat[row+1][col-1]==1 && !vis[row+1][col-1]){
        Util(vis, mat, length, row+1, col-1, N, M);
    }
    if(row+1<N && mat[row+1][col]==1 && !vis[row+1][col]){
        Util(vis, mat, length, row+1, col, N, M);
    }
    if(row+1<N && col+1<M && mat[row+1][col+1]==1 && !vis[row+1][col+1]){
        Util(vis, mat, length, row+1, col+1, N, M);
    }
    
    
}

int main() {
	//code
	int t;
	bool vis[MAX][MAX];
	int mat[MAX][MAX];
	
	cin >> t;
	while(t--){
	    int n,m;
	    cin >>n >>m;
	    for(int i=0; i<n;i++){
	        for(int j=0;j<m;j++){
	            vis[i][j] = false;
	            cin >> mat[i][j];
	        }
	    }
	    int max_len = 0;
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(mat[i][j] == 1 && !vis[i][j]){
	                int length = 0;
             	    Util(vis, mat, length, i , j, n, m);  
             	    if(length > max_len){
             	        max_len = length;
             	    }
	            }
	        }
	    }
	    
	    cout << max_len <<endl;
	    
	}
	return 0;
}