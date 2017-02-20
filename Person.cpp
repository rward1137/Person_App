#include "Person.h"
#include <string>
#include <iostream>

ostream& operator<<(ostream& os, const Person& outputP)
{
	os << "Name: " << outputP.name << ", age: " << outputP.age << "\n";
	return os;
}

istream& operator >> (istream& is, Person& inputP)
{
	is >> inputP.name >> inputP.age;
	return is;
}

void Person::setName(string n)
{
	name = n;
}

string Person::getName()
{
	return name;
}

void Person::setAge(int a)
{
	age = a;
}

int Person::getAge()
{
	return age;
}

bool Person::operator>=(const Person& p) const
{
	return (age >= p.age);
}

Person::Person()
{
	name = "";
	age = 0;
}

Person::Person(int a, string n)
{
	name = n;
	age = a;
}