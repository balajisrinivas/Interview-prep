#include<iostream>
#include<limits>
 
using namespace std;

int MAX_INT = numeric_limits<int>::max(); 

int minJumps(int arr[], int l, int r) {
	cout<<l<<"\t"<<r<<endl;
	if(l == r)
		return 0;
	else if(arr[l] == 0)
		return MAX_INT;
	else {
		int min = MAX_INT;
		for(int i=l+1; i<=r && i<= l+arr[l]; i++) {
			int local_min = minJumps(arr, i, r);
			if(local_min+1 < min && local_min != MAX_INT)
				min = local_min+1;
		}
		return min;
	}
}

int main() {
	int arr[] = {1, 3, 6, 3, 2, 3, 6, 8, 9, 5};
	int num = sizeof(arr) / sizeof(arr[0]);
	cout<<minJumps(arr, 0, num-1)<<endl;
	return 0;
}
