#include <iostream>
#include <stack>
#include <map>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    
	    int n;cin>>n;
	    int *a = new int[n];
	    stack<int> s;
	    map<int,int> ans;
	    for(int i=0;i<n;i++){
	        cin >> a[i];
	    }
	    int j =0;
	    s.push(a[j]);

	    for(j=1;j<n;j++){

	        if(s.top()>a[j]){
	            s.push(a[j]);
	        }
	        else{
	            while(s.empty()==false && s.top() < a[j] ){
	                ans[s.top()] = a[j];
	                s.pop();
	            }
	            s.push(a[j]);
	        }
	    }
	    
	    if(!s.empty()){
	        while(!s.empty()){
    	        ans[s.top()] = -1;
    	        s.pop();
	        }
	    }
	    
	    for(int i =0;i<n;i++){
	        cout << ans[a[i]]<<" ";
	    }
	    cout << endl;
	    

	}
	return 0;
}