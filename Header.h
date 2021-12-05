#pragma once
#include <ostream>
class Money
{
private:
	double Pound;
	double Shillings;
	double Penny;
public:
	Money(double pound, double shilling, double penny);
	Money();
	void setPound(double pound);
	void setShilling(double shillings);
	void setPenny(double penny);
	double getPound() const;
	double getShilling() const;
	double getPenny() const;
	Money operator + (const Money& m) const;
	Money operator - (const Money& m)const;
	bool operator == (const Money& m);
	bool operator < (const Money& m);
	bool operator != (const Money& m);
	bool operator > (const Money& m);
	bool operator >= (const Money& m);
	bool operator <= (const Money& m);
	Money operator-();
	friend std::ostream& operator<< (std::ostream& out, const Money& m);
	friend Money operator += (Money& m, const Money& m1);
	friend Money operator -= (Money& m, const Money& m1);
};