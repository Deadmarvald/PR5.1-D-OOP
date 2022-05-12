#pragma once

#include<iostream>
#include<sstream>
#include<string>
#include "Exception.h"
#include "MyException.h"

using namespace std;

class Pair
{
private:
	long hrn;
	unsigned long kop;

public:
	Pair(const long x = 0, const unsigned long y = 0);
	Pair(const Pair& r);
	~Pair(void);

	long GetHrn() const { return hrn; }
	unsigned long GetKop() const { return kop; }

	void SetHrn(long value);
	void SetKop(unsigned long value);

	operator string() const;
	friend ostream& operator << (ostream&, const Pair&);
	friend istream& operator >> (istream&, Pair&);
};