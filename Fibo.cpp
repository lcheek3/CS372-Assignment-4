//Lucas Cheek
//CS372
//Assignment 4
//Function file

#include <iostream>
#include "Fibo.h"

//For this small example, including the base class seemed unecessary. For this program it would look something like:
/*
class Fibo
{
public:
virtual void print() = 0;
};
*/
//and the other classes would derive from it. It wouldn't actually be useful to add though.

//class Real_Fibo
Real_Fibo::Real_Fibo(int n) {
	std::cout << "Real_fibo construction called" << std::endl;
	_result = slow_fibo(n);
	std::cout << "Real_fibo calculation done" << std::endl;
}
void Real_Fibo::print() {
	std::cout << "result: " << _result << std::endl;
}
int Real_Fibo::slow_fibo(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return slow_fibo(n - 1) + slow_fibo(n - 2);
}
//end class Real_Fibo

//class Proxy_Fibo
Proxy_Fibo::Proxy_Fibo(int n) {
	std::cout << "Fibo wrapper construction called" << std::endl;
	_n = n;
}
Proxy_Fibo::~Proxy_Fibo() {
	delete _real_fibo_pointer;
}
void Proxy_Fibo::print() {
	if (!_real_fibo_pointer)
		_real_fibo_pointer = new Real_Fibo(_n);
	_real_fibo_pointer->print();
}
//end class Proxy_Fibo