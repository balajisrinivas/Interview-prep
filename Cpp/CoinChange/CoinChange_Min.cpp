#include<iostream>
#include<algorithm>
#define MAXINT 65535

using namespace std;

int mincount(int S[], int m, int n) {
	if(n==0)
		return 0;
	if(n<0)
		return MAXINT;
	if(n>0 && m<=0)
		return MAXINT;
	return min(mincount(S, m-1, n), mincount(S, m, n-S[m-1])+1);
}

int main() {
	int arr[] = {2, 4, 5};
	int m = sizeof(arr) / sizeof(arr[0]);
	int n = 3;
	cout<<mincount(arr, m, n)<<endl;
	return 0;
}
