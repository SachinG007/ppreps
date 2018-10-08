{
#include <bits/stdc++.h>
using namespace std;
#define MAX 100
vector<string> printPath(int m[MAX][MAX], int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	
	int m[100][100];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>m[i][j];
		}
	}
	
	vector<string> res = printPath(m,n);
	for(int i=0;i<res.size();i++)
	cout<<res[i]<<" ";
	cout<<endl;
}
	return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The function returns a sorted array of strings which represents
the directions mouse will take to reach the destination.
You are required to complete the below method. */
void pathUtil(vector<string> &v, string &str, int m[MAX][MAX],bool vis[MAX][MAX], int cx, int cy, int n){
    
    if(cx == n-1 && cy == n-1){
        v.push_back(str);
        return;
    }
    
    if(cx>=0 && cx<n && cy>=0 && cy<n){
    if(m[cx+1][cy] == 1 && !vis[cx+1][cy]){
        vis[cx+1][cy] = true;
        str = str + 'D';
        pathUtil(v, str, m, vis, cx+1,cy,n );
        str.pop_back();
        vis[cx+1][cy] = false;
    }
    
    if(m[cx-1][cy] == 1 && !vis[cx-1][cy]){
        vis[cx-1][cy] = true;
        str = str + 'U';
        pathUtil(v, str, m, vis, cx-1,cy,n );
        str.pop_back();
        vis[cx-1][cy] = false;
    }
    
    if(m[cx][cy+1] == 1 && !vis[cx][cy+1]){
        vis[cx][cy+1] = true;
        str = str + 'R';
        pathUtil(v, str, m, vis, cx,cy+1,n );
        str.pop_back();
        vis[cx][cy+1] = false;
    }

    if(m[cx][cy-1] == 1 && !vis[cx][cy-1]){
        vis[cx][cy-1] = true;
        str = str + 'L';
        pathUtil(v, str, m, vis, cx,cy-1,n );
        str.pop_back();
        vis[cx][cy-1] = false;
    }    
    }
}

vector<string> printPath(int m[MAX][MAX], int n)
{
    //Your code here	
    vector<string> v;
    string str;
    bool vis[MAX][MAX];
    
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            vis[i][j] = false;
        }
    }
    vis[0][0] = true;
    
    pathUtil(v, str, m, vis, 0,0,n );
    sort(v.begin(),v.end());
    return v;
}