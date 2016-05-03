//Lucas Cheek
//CS372
//Assignment 4
//Main file

#include <iostream>
#include <vector>
#include "Fibo.h"


//I chose to use create a Proxy design pattern for this assignment.
//As a toy example, my real class does a computationally intesive thing (slow fibo) on creation.
//The proxy class, however, does not create the real class until something is done with it. In this case, print the fibo number at the n specified.

//my source for this assignment was: https://sourcemaking.com/design_patterns/proxy



int main() {
	std::cout << "First, a raw call to Real_Fibo:" << std::endl;
	Real_Fibo rawFib(40);
	rawFib.print();
	std::cout << "that took a while! Now I'll make 10 of the 'same' fibo" << std::endl;
	std::cout << "only I'll call the proxy instead." << std::endl;
	std::vector<Proxy_Fibo> fibArr;
	for (int i = 0; i < 10; i++) {
		Proxy_Fibo tempFib(40);
		fibArr.push_back(tempFib);
	}
	std::cout << "Very fast! Now I'll actually try to print one of them." << std::endl;
	fibArr[0].print();
}