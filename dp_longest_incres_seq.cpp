
/* A Naive C/C++ recursive implementation of LIS problem */
#include<stdio.h> 
#include<stdlib.h>

int lis_util(int arr[], int n, int*max){

	if(n==1){
		return 1;
	}

	int max_current = 1;
	for(int i = 0; i<n;i++){
		int current_lis = lis_util(arr,n, &max);
		if(arr[i-1]<arr[j-1] && current_lis + 1 > max_current]){

			max_current = current_lis + 1;
		}
	}

	if(max < max_current){
		max = max_current;
	}

	return max_current;

}

int lis(int arr[], int n){

	int max = 1;
	lis_util(arr,n,&max);

	return max;
}