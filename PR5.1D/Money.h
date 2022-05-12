#pragma once

#include "Pair.h"

class Money : public Pair
{
public:
	Money(const long x = 0, const unsigned long y = 0);
	Money(const Money& r);
	Money(double z);
	~Money(void);

	friend Money operator -(const Money&, const Money&);
	friend Money operator *(const Money&, const double);
	friend Money operator *(const double, const Money&);

	bool operator ==(const Money&);
	bool operator !=(const Money&);
	bool operator >(const Money&);
	bool operator <(const Money&);
	bool operator >=(const Money&);
	bool operator <=(const Money&);

	operator string() const;

	Money& operator ++();
	Money& operator --();
	Money operator ++(int);
	Money operator --(int);
};