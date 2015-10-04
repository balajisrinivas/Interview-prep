#include<iostream>

using namespace std;

class Number
{
	public:
		int add(int a, int b) {
			return a+b;
		}

		int multiply(int a, int b) {
			return a*b;
		}
		static int negate(int a) {
			return -a;
		}
};

int bar1(int a, int b, Number *number, int(Number::*funcp)(int, int)) {
	return (number->*funcp)(a, b);
}

int bar2(int a, int b, Number number, int(Number::*funcp)(int, int)) {
	return (number.*funcp)(a, b);
}

typedef int(Number::*Number_funcp)(int, int);

int bar3(int a, int b, Number number, Number_funcp number_funcp) {
	return (number.*number_funcp)(a, b);
}

typedef int(*Funcp)(int);

int bar4(int a, Funcp funcp) {
	return funcp(a);
}

int main() {
	Number n;
	cout<<bar1(100, 200, &n, &Number::add)<<endl;
	cout<<bar2(100, 400, n, &Number::add)<<endl;
	cout<<bar3(100, 400, n, &Number::multiply)<<endl;
	cout<<bar4(300, &Number::negate)<<endl;
	return 0;
}
