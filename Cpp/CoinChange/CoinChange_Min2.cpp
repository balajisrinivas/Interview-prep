#include<iostream>
#include<algorithm>

#define MAXINT 65535
#define MAXROWS 100
#define MAXCOLS 100

int table[MAXROWS][MAXCOLS];

using namespace std;

void print_coins(int d[], int x, int y) {
	if(x==0 && y==0)
		return;
	if(y>0 && table[x][y] == table[x][y-1])
		print_coins(d, x, y-1);
	else if(table[x][y] == table[x-d[y]][y]+1) {
		cout<<d[y]<<"\t";
		print_coins(d, x-d[y], y);
	}
}

void print_array(int m, int n) {
	for(int i=0; i<n+1; i++) {
		for(int j=0; j<m; j++) {
			cout<<table[i][j]<<"\t";
		}
		cout<<endl;
	}
}

int count(int S[], int m, int n) {
	int i, j, x, y;
	for(i=0;i<m;i++)
		table[0][i] = 0;

	for(i=1;i<=n;i++) {
		for(j=0;j<m;j++) {
			x = (i-S[j] >= 0) ? table[i-S[j]][j]+1 : MAXINT;;
			y = (j>=1) ? table[i][j-1] : MAXINT;
			table[i][j] = min(x, y);
		}
	}
	print_array(m, n);
	return table[n][m-1];
}

 

int main() {
	int arr[] = {1,3,4};
	int m = sizeof(arr) / sizeof(arr[0]);
	int n = 15;
	cout << count(arr, m, n)<<endl;
	print_coins(arr, n, m-1);
	return 0;
}
