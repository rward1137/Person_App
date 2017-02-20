#pragma once
#ifndef _Person_h
#define _Person_h
#include <string>
#include <iostream>

using namespace std;

class Person
{
	friend ostream& operator<<(ostream&, const Person&);

	friend istream& operator >> (istream&, Person&);

public:
	void setName(string n);

	string getName();

	void setAge(int a);

	int getAge();

	bool operator>=(const Person&) const;

	Person();

	Person(int a, string n);

private:
	int age;
	string name;
};
#endif