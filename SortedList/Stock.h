//****************************************************************************************************
//
//      File:                Stock.h
//
//      Student:             Leon Krugliakov
//
//      Assignment:          Program #
//
//      Course Name:         Data Structures II
//
//      Course Number:       COSC 3100 - 11
//
//      Due:                 December 1st, 2020
//
//
//      This program creates two arrays. One full of integers and the other
//		full of stock objects. Then it randomizes the order of the elements
//		in the array and presents them. Then it proceeds to do four different
//		sorting algorithems on both arrays and displaying them each time.
//		Those algorithems are QuickSort and HeapSort both in forward and
//		reverse orders.
//
//      Other files required:
//		    1.    SortedList.cpp - contains the main function
//			3.	  SortedList.h - Contains the SortedList class
//
//****************************************************************************************************

#ifndef STOCK_H
#define STOCK_H

//****************************************************************************************************

#include <iostream>
#include <string>

//****************************************************************************************************

using namespace std;

//****************************************************************************************************

class Stock
{
private:
	string name,
		symbol;
	double price;
public:
	Stock(const string& name = "", const string& symbol = "", double price = 0);
	Stock(const Stock& s);
	void display() const;
	string getName() const;
	string getSymbol() const;
	double getPrice() const;
	void setName(string name);
	void setSymbol(string symbol);
	void setPrice(double price);
	bool operator==(const Stock& right) const;
	bool operator!=(const Stock& right) const;
	int hash(int size);
	bool operator>(const Stock& s) const;
	bool operator<(const Stock& s) const;

	friend ostream& operator<<(ostream& os, const Stock& s);
	friend ostream& operator<(ostream& os, const Stock& s);
};

//****************************************************************************************************

Stock::Stock(const string& name, const string& symbol, double price)
{
	this->name = name;
	this->symbol = symbol;
	this->price = price;
}

//****************************************************************************************************

Stock::Stock(const Stock& s)
{
	this->name = s.name;
	this->symbol = s.symbol;
	this->price = s.price;
}

//****************************************************************************************************

void Stock::display() const
{
	cout << "Company Name: " << name << endl
		<< "Symbol:" << symbol << endl
		<< "Price:" << price << endl << endl;
}

//****************************************************************************************************

string Stock::getName() const
{
	return name;
}

//****************************************************************************************************

string Stock::getSymbol() const
{
	return symbol;
}

//****************************************************************************************************

double Stock::getPrice() const
{
	return price;
}

//****************************************************************************************************

void Stock::setName(string name)
{
	this->name = name;
}

//****************************************************************************************************

void Stock::setSymbol(string symbol)
{
	this->symbol = symbol;
}

//****************************************************************************************************

void Stock::setPrice(double price)
{
	this->price = price;
}

//****************************************************************************************************

bool Stock::operator==(const Stock& right) const
{
	bool equal = false;

	if (this->name == right.name ||
		this->symbol == right.symbol)
	{
		equal = true;
	}

	return equal;
}

//****************************************************************************************************

bool Stock::operator!=(const Stock& right) const
{
	return !(*this == right);
}

//****************************************************************************************************

bool Stock::operator<(const Stock& right) const
{
	return (this->symbol < right.symbol);
}

//****************************************************************************************************

bool Stock::operator>(const Stock& right) const
{
	return (this->symbol > right.symbol);
}

//****************************************************************************************************

int Stock::hash(int size)
{
	int key = 0;

	string stringKey = symbol + name + to_string(price);

	for (size_t i = 0; i < stringKey.length(); i++)
	{
		key += (int)stringKey[i];
	}

	return (key % (size - 1));
}

//****************************************************************************************************

ostream& operator<<(ostream& os, const Stock& s)
{
	os << "Company Name: " << s.getName() << endl <<
		"Symbol:" << s.getSymbol() << endl <<
		"Price:" << s.getPrice() << endl;

	return os;
}

//****************************************************************************************************

#endif STOCK_H