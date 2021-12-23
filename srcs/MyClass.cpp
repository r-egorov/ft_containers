#include "MyClass.hpp"
#include <iostream>
#include <string>

MyClass::MyClass(void) : _n(0), _s("") {}

MyClass::MyClass(int n, std::string s) : _n(n), _s(s) {}

MyClass::MyClass(const MyClass& other)
{
    _n = other._n;
    _s = other._s;
}

MyClass::~MyClass(void) {}

MyClass&    MyClass::operator=(const MyClass& other)
{
    _n = other._n;
    _s = other._s;

    return (*this);
}

int         MyClass::getN(void) const { return(_n); }

std::string MyClass::getS(void) const { return(_s); }

void        MyClass::setN(int n) { _n = n; }

void        MyClass::setS(std::string s) { _s = s; }


std::ostream		&operator<<(std::ostream &o, MyClass const &obj)
{
	o << "MyClass(n = " << obj.getN() << ", s = \'" << obj.getS() << "\')";
	return (o);
}