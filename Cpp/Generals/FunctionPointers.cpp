#include<iostream>
#include<cstring>

using namespace std;

double mileToKm(double mile) {
	return mile * 1.6;
}

int main() {
	double (*func1)(double) = mileToKm;
	cout<<func1(1000)<<endl;
	char * (*func2)(const char *, int) = strchr;
	cout<<func2("Wikipedia", 'i');
	return 0;
}
