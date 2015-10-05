#include<iostream>
#include<limits>

#define MIN(a,b) (a<b)?a:b ;

using namespace std;

int MAX_INT = numeric_limits<int>::max();

int minJumps(int arr[], int n) {
	int *jumps = new int[n];
	int min;
	if(arr[0] == 0)
		return MAX_INT;
	jumps[0] = 0;
	for(int i=1; i<n; i++) {
		jumps[i] = MAX_INT;
		for(int j=0; j<i; j++) {
			if(j+arr[j] >= i) 
				jumps[i] = MIN(jumps[i], jumps[j]+1); 
		}
	}
	return jumps[n-1];
}

int main() {
	int arr[] = {1, 3, 6, 1, 0, 9};
	int size = sizeof(arr) / sizeof(arr[0]);
	cout<<minJumps(arr, size)<<endl;
	return 0;
}
