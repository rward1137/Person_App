#include <iostream>
#include <string>
#include "doublyLinkedList.h"
#include "Person.h"

using namespace std;
int main()
{
	Person person;
	doublyLinkedList<Person> people;
	int count = 0;
	string tempName;
	int tempAge;

	while (tempName != "-1" && count < 99)
	{
		cout << "\nEnter name (-1 to stop): ";
		cin >> tempName;

		if (tempName != "-1")
		{
			cout << "\nEnter age of " << tempName << ": ";
			cin >> tempAge;
			person.setName(tempName);
			person.setAge(tempAge);

			people.insert(person);

			count++;
		}
	}


	cout << endl << endl;

	people.print();

	system("pause");
}