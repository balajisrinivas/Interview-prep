#include<iostream>
#include<algorithm>
#include<cstdlib>

#define MAXINT 65535

using namespace std;

void print_array(int arr[], int n) {
	for(int i=0; i<n; i++) {
		cout<<arr[i]<<"\t";
	}
	cout<<endl;
}

void print_coins(int S[], int d[], int n) {
	while(n>0) {
		cout<<d[S[n]]<<"\t";
		n = n - d[S[n]];
	}
	cout<<endl;
}

void coinchange(int d[], int k, int n) {
	int C[n+1], S[n+1];
	int min, coin;
	C[0] = 0;
	for(int p=1; p<=n; p++)
	{	
		min = MAXINT;
		for(int i=0; i<k; i++) {
			if(d[i]<=p) {
				if(min>(1+C[p-d[i]])) {
					min = 1+C[p-d[i]];
					coin = i;
				}
			}
		}
		C[p] = min;
		S[p] = coin;
	}
	print_array(C, n+1);
	print_array(S, n+1);
	print_coins(S, d, n);
}

int main(int argc, char *argv[]) {
	int arr[] = {1,2,4};
	int m = sizeof(arr) / sizeof(arr[0]);
	int n = atoi(argv[1]);
	coinchange(arr, m , n);
	return 0;
}	
				
