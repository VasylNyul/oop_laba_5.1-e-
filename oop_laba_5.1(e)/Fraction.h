#include "Object.h"
#include "Error_ex.h"
#include "MyError.h"
#include <iostream>
#include <sstream>
#include <string>
#pragma once

using namespace std;

class Fraction : public Object
{
private:
	long first;
	short second;
public:
	int get_a() const { return first; };
	int get_b() const { return second; };
	void set_a(unsigned int value) { first = value; }
	void set_b(unsigned int value) { second = value; }

	Fraction();
	Fraction(long, short);
	Fraction(const Fraction&);
	~Fraction() { }

	operator string() const;

	Fraction& operator ++();
	Fraction& operator --();
	Fraction operator ++(int);
	Fraction operator --(int);

	friend ostream& operator <<(ostream&, const Fraction&);
	friend istream& operator >>(istream&, Fraction&) throw(Error_ex,  bad_exception, MyError, char);

	friend Fraction operator - (const Fraction&, const Fraction&);

	friend bool operator < (Fraction&, Fraction&);
	friend bool operator == (Fraction&, Fraction&);
	friend bool operator > (Fraction&, Fraction&);
	friend bool operator <= (Fraction&, Fraction&);
	friend bool operator != (Fraction&, Fraction&);
	friend bool operator >= (Fraction&, Fraction&);

};


