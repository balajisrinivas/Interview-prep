#include<iostream>

using namespace std;

int count(int S[], int m, int n) {
	if(n==0)
		return 1;
	else if(n<0)
		return 0;
	else if(n>=1 && m<=0)
		return 0;
	return count(S, m-1, n) + count(S, m, n-S[m-1]);
}

int main() {
	int arr[]={1,2,4};
	int m = sizeof(arr) / sizeof(arr[0]);
	int n = 5;
	cout<<count(arr, m, n);
	return 0;
}
