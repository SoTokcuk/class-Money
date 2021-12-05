#include <iostream>
#include"Header.h"
using namespace std;
int main()
{
	double pounds, shillings, penny, pounds1, shillings1, penny1;
	cout << "Enter counter of pounds:";
	cin >> pounds;
	cout << "Enter counter of shillings:";
	cin >> shillings;
	cout << "Enter counter of penny:";
	cin >> penny;
	cout << "Enter second counter of pounds:";
	cin >> pounds1;
	cout << "Enter second  counter of shillings:";
	cin >> shillings1;
	cout << "Enter second counter of penny:";
	cin >> penny1;
	Money money(pounds, shillings, penny);
	cout << "Enter the first value of money:" << money << endl;
	Money money1(pounds1, shillings1, penny1);
	cout << "Enter the second value of money:" << money1 << endl;
	cout << "Sum of money:" << money + money1 << endl;
	cout << "Difference of money:" << money - money1 << endl;
	cout << "Unary minus for first value of money:" << -money << endl;
	if (money == money1)
	{
		cout << "The first value of money is equal to the second\n";
	}
	if (money != money1)
	{
		cout << "The first value of money is not equal to the second\n";
	}
	if (money < money1)
	{
		cout << "The first value of money is smaller than the second\n";
	}
	if (money > money1)
	{
		cout << "The first value of money is larger than the second\n";
	}
	if (money >= money1)
	{
		cout << "The first value of money is greater than or equal to the second\n";
	}
	if (money <= money1)
	{
		cout << "The first value of money is less than or equal to the second\n";
	}
	cout << "Operator += :" << (money += money1) << endl;
	cout << "Operator -= :" << (money -= money1) << endl;
	try
	{
		money.setPenny(penny);
		money1.setPenny(penny1);
		money.setShilling(shillings);
		money1.setShilling(shillings1);
	}
	catch (const std::exception& ex)
	{
		cout << "Wrong value of money:" << ex.what();
	}
	return 0;
}