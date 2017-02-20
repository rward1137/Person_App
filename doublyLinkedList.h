#ifndef H_doublyLinkedList
#define H_doublyLinkedList 

#include <iostream>
#include <cassert>

using namespace std;

//Definition of the node
template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type> *next;
	nodeType<Type> *back;
};

template <class Type>
class doublyLinkedList
{
public:
	//Overload the assignment operator.
	const doublyLinkedList<Type>& operator=
		(const doublyLinkedList<Type> &);

	//Function to initialize the list to an empty state.
	//Postcondition: first = nullptr; last = nullptr; count = 0;
	void initializeList();

	//Function to determine whether the list is empty.
	//Postcondition: Returns true if the list is empty,
	//               otherwise returns false.
	bool isEmptyList() const;

	//Function to delete all the nodes from the list.
	//Postcondition: first = nullptr; last = nullptr; count = 0;
	void destroy();

	//Function to output the info contained in each node.
	void print() const;

	//Function to output the info contained in each node
	//in reverse order.
	void reversePrint() const;

	//Function to return the number of nodes in the list.
	//Postcondition: The value of count is returned.
	int length() const;

	//Function to return the first element of the list.
	//Precondition: The list must exist and must not be empty.
	//Postcondition: If the list is empty, the program 
	//               terminates; otherwise, the first 
	//               element of the list is returned. 
	Type front() const;

	//Function to return the last element of the list.
	//Precondition: The list must exist and must not be empty.
	//Postcondition: If the list is empty, the program
	//               terminates; otherwise, the last
	//               element of the list is returned.
	Type back() const;

	//Function to determine whether searchItem is in the list.
	//Postcondition: Returns true if searchItem is found in
	//               the list, otherwise returns false.
	bool search(const Type& searchItem) const;

	//Function to insert insertItem in the list.
	//Precondition: If the list is nonempty, it must be in
	//              order.
	//Postcondition: insertItem is inserted at the proper place
	//               in the list, first points to the first
	//               node, last points to the last node of the
	//               new list, and count is incremented by 1.
	void insert(const Type& insertItem);

	//Function to delete deleteItem from the list. 
	//Postcondition: If found, the node containing deleteItem
	//               is deleted from the list; first points
	//               to the first node of the new list, last
	//               points to the last node of the new list,
	//               and count is decremented by 1; otherwise,
	//               an appropriate message is printed. 
	void deleteNode(const Type& deleteItem);

	//default constructor
	//Initializes the list to an empty state.
	//Postcondition: first = nullptr; last = nullptr; count = 0;
	doublyLinkedList();

	//copy constructor
	doublyLinkedList(const doublyLinkedList<Type>& otherList);

	//destructor
	//Postcondition: The list object is destroyed.
	~doublyLinkedList();

protected:
	int count;
	nodeType<Type> *first; //pointer to the first node
	nodeType<Type> *last;  //pointer to the last node

private:
	//Function to make a copy of otherList.
	//Postcondition: A copy of otherList is created and
	//               assigned to this list.
	void copyList(const doublyLinkedList<Type>& otherList);
};

template <class Type>
doublyLinkedList<Type>::doublyLinkedList()
{
	first = nullptr;
	last = nullptr;
	count = 0;
}

template <class Type>
bool doublyLinkedList<Type>::isEmptyList() const
{
	return (first == nullptr);
}

template <class Type>
void doublyLinkedList<Type>::destroy()
{
	nodeType<Type>  *temp; //pointer to delete the node

	while (first != nullptr)
	{
		temp = first;
		first = first->next;
		delete temp;
	}

	last = nullptr;
	count = 0;
}

template <class Type>
void doublyLinkedList<Type>::initializeList()
{
	destroy();
}

template <class Type>
int doublyLinkedList<Type>::length() const
{
	return count;
}

template <class Type>
void doublyLinkedList<Type>::print() const
{
	nodeType<Type> *current; //pointer to traverse the list

	current = first;  //set current to point to the first node

	while (current != nullptr)
	{
		cout << current->info << "  ";  //output info
		current = current->next;
	}//end while
}//end print


template <class Type>
void doublyLinkedList<Type>::reversePrint() const
{
	nodeType<Type> *current; //pointer to traverse 
							 //the list

	current = last;  //set current to point to the 
					 //last node

	while (current != nullptr)
	{
		cout << current->info << "  ";
		current = current->back;
	}//end while
}//end reversePrint

template <class Type>
bool doublyLinkedList<Type>::
search(const Type& searchItem) const
{
	bool found = false;
	nodeType<Type> *current; //pointer to traverse the list

	current = first;

	while (current != nullptr && !found)
		if (current->info >= searchItem)
			found = true;
		else
			current = current->next;

	if (found)
		found = (current->info == searchItem); //test for 
											   //equality

	return found;
}//end search

template <class Type>
Type doublyLinkedList<Type>::front() const
{
	assert(first != nullptr);

	return first->info;
}

template <class Type>
Type doublyLinkedList<Type>::back() const
{
	assert(last != nullptr);

	return last->info;
}

template <class Type>
void doublyLinkedList<Type>::insert(const Type& insertItem)
{
	nodeType<Type> *current;      //pointer to traverse the list
	nodeType<Type> *trailCurrent = nullptr; //pointer just before current
	nodeType<Type> *newNode;      //pointer to create a node
	bool found;

	newNode = new nodeType<Type>; //create the node
	newNode->info = insertItem;  //store the new item in the node
	newNode->next = nullptr;
	newNode->back = nullptr;

	if (first == nullptr) //if the list is empty, newNode is 
						  //the only node
	{
		first = newNode;
		last = newNode;
		count++;
	}
	else
	{
		found = false;
		current = first;

		while (current != nullptr && !found) //search the list
			if (current->info >= insertItem)
				found = true;
			else
			{
				trailCurrent = current;
				current = current->next;
			}

		if (current == first) //insert newNode before first
		{
			first->back = newNode;
			newNode->next = first;
			first = newNode;
			count++;
		}
		else
		{
			//insert newNode between trailCurrent and current
			if (current != nullptr)
			{
				trailCurrent->next = newNode;
				newNode->back = trailCurrent;
				newNode->next = current;
				current->back = newNode;
			}
			else
			{
				trailCurrent->next = newNode;
				newNode->back = trailCurrent;
				last = newNode;
			}

			count++;
		}//end else
	}//end else
}//end insert

template <class Type>
void doublyLinkedList<Type>::deleteNode(const Type& deleteItem)
{
	nodeType<Type> *current; //pointer to traverse the list
	nodeType<Type> *trailCurrent; //pointer just before current

	bool found;

	if (first == nullptr)
		cout << "Cannot delete from an empty list." << endl;
	else if (first->info == deleteItem) //node to be deleted is  
										//the first node
	{
		current = first;
		first = first->next;

		if (first != nullptr)
			first->back = nullptr;
		else
			last = nullptr;

		count--;

		delete current;
	}
	else
	{
		found = false;
		current = first;

		while (current != nullptr && !found)  //search the list
			if (current->info >= deleteItem)
				found = true;
			else
				current = current->next;

		if (current == nullptr)
			cout << "The item to be deleted is not in "
			<< "the list." << endl;
		else if (current->info == deleteItem) //check for 
											  //equality
		{
			trailCurrent = current->back;
			trailCurrent->next = current->next;

			if (current->next != nullptr)
				current->next->back = trailCurrent;

			if (current == last)
				last = trailCurrent;

			count--;
			delete current;
		}
		else
			cout << "The item to be deleted is not in list."
			<< endl;
	}//end else
}//end deleteNode

template<class Type>
void doublyLinkedList<Type>::copyList(const doublyLinkedList<Type>& otherList)
{
	//ENTER CODE HERE (20%)
	nodeType<Type> *newNode; //pointer to create a node
	nodeType<Type> *current; //pointer to traverse the list
	nodeType<Type> *trailCurrent; //pointer just before current


								  //if this list is not empty, make it empty
	if (first != nullptr)
		destroyList();

	if (otherList.first == nullptr) //otherList is empty
	{
		first = nullptr;
		last = nullptr;
		count = 0;
	}
	else
	{
		current = otherList.first; //current now points to the list to be copied
		count = otherList.count;

		//copy the first node
		first = new nodeType<Type>; //create the node
		first->info = current->info; //copy the node info
		first->next = current->next; //set the node next link to null
		first->back = current->back; //copy the node back link

		last = first; //make last point to the first node

		current = current->next; //make current point to the next node

								 //copy the remaining list
		while (current != nullptr)
		{
			newNode = new nodeType<Type>; //create the node
			newNode->info = current->info; //copy the node info
			newNode->next = current->next; //set the node next link to null
			newNode->back = current->back;

			last = newNode;
			current = current->next;
		}
	}

}//end copyList

template<class Type>
doublyLinkedList<Type>::doublyLinkedList(const doublyLinkedList<Type>& otherList)
{
	//ENTER CODE HERE (20%)
	first = nullptr;
	copyList(otherList);
}

template<class Type>
const doublyLinkedList<Type>& doublyLinkedList<Type>::operator=
(const doublyLinkedList<Type>& otherList)
{
	//ENTER CODE HERE (20%)
	if (this != &otherList)
	{
		copyList(otherList);
	}
	return *this;
}

template <class Type>
doublyLinkedList<Type>::~doublyLinkedList()
{
	cout << "Definition of the destructor is left as an exercise." << endl;
	cout << "See Programming Execrise 9." << endl;
}
#endif