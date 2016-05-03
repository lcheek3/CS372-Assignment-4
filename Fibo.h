//Lucas Cheek
//CS372
//Assignment 4
//Header file

#ifndef FIBO_H_INCLUDED
#define FIBO_H_INCLUDED

//For this small example, including the base class seemed unecessary. For this program it would look something like:
/*
class Fibo
{
public:
virtual void print() = 0;
};
*/
//and the other classes would derive from it. It wouldn't actually be useful to add though.

class Real_Fibo {
public:
	Real_Fibo(int n);
	void print();
private:
	int _result;
	int slow_fibo(int n);
};

//Wrapper class for Real_Fibo. Does not construct Real_Fibo until it is used.
class Proxy_Fibo {
public:
	Proxy_Fibo(int n);
	~Proxy_Fibo();
	void print();
private:
	int _n;
	Real_Fibo *_real_fibo_pointer;
};

#endif
