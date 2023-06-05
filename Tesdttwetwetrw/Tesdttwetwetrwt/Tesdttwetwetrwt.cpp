#include <iostream>
#include <list>
#include <string>
#include <string.h>
#include <iomanip>
#include <iostream>
#include <iomanip>
#include <limits>
#include <fstream>
#include <cctype>
#include <vector>
#include <cmath>
#include <fstream>
#include <cstdlib> 
#include <cctype> 
#include <map>
#include <stdarg.h>
#include <list>
#include <cstdarg>
using namespace std;

template <typename T>
class ListIterator {
public:
	using value_type = T;
	using reference = T&;
	using pointer = T*;

	explicit ListIterator(Node<T>* node) : current(node) {}

	reference operator*() {
		return current->val;
	}

	pointer operator->() {
		return &(current->val);
	}

	ListIterator& operator++() {
		current = current->next;
		return *this;
	}

	ListIterator operator++(int) {
		ListIterator<T> temp = *this;
		++(*this);
		return temp;
	}

	bool operator==(const ListIterator& other) const {
		return current == other.current;
	}

	bool operator!=(const ListIterator& other) const {
		return !(*this == other);
	}

private:
	Node<T>* current;
};




template <typename T>
class ConstListIterator {
public:
	using value_type = T;
	using reference = const T&;
	using pointer = const T*;

	explicit ConstListIterator(const Node<T>* node) : current(node) {}

	reference operator*() const {
		return current->val;
	}

	pointer operator->() const {
		return &(current->val);
	}

	ConstListIterator& operator++() {
		current = current->next;
		return *this;
	}

	ConstListIterator operator++(int) {
		ConstListIterator<T> temp = *this;
		++(*this);
		return temp;
	}
	bool operator==(const ConstListIterator& other) const {
		return current == other.current;
	}

	bool operator!=(const ConstListIterator& other) const {
		return !(*this == other);
	}


private:
	const Node<T>* current;
};


template <typename T>
class ReverseListIterator {
public:
	using value_type = T;
	using reference = T&;
	using pointer = T*;


	explicit ReverseListIterator(Node<T>* node) : current(node) {}

	reference operator*() const {
		return current->val;
	}

	pointer operator->() const {
		return &(current->val);
	}

	ReverseListIterator& operator++() {
		current = current->previosus;
		return *this;
	}

	ReverseListIterator operator++(int) {
		ReverseListIterator<T> temp = *this;
		++(*this);
		return temp;
	}

	ReverseListIterator& operator--() {
		current = current->next;
		return *this;
	}

	ReverseListIterator operator--(int) {
		ReverseListIterator<T> temp = *this;
		--(*this);
		return temp;
	}


	bool operator==(const ReverseListIterator& other) const {
		return current == other.current;
	}

	bool operator!=(const ReverseListIterator& other) const {
		return !(*this == other);
	}

private:
	Node<T>* current;
};

template <typename T>
class ConstReverseListIterator {
public:
	using value_type = const T;
	using reference = const T&;
	using pointer = const T*;


	explicit ConstReverseListIterator(const Node<T>* node) : current(node) {}

	reference operator*() const {
		return current->val;
	}

	pointer operator->() const {
		return &(current->val);
	}

	ConstReverseListIterator& operator++() {
		current = current->previosus;
		return *this;
	}

	ConstReverseListIterator operator++(int) {
		ConstReverseListIterator<T> temp = *this;
		++(*this);
		return temp;
	}

	ConstReverseListIterator& operator--() {
		current = current->next;
		return *this;
	}

	ConstReverseListIterator operator--(int) {
		ConstReverseListIterator<T> temp = *this;
		--(*this);
		return temp;
	}

	bool operator==(const ConstReverseListIterator& other) const {
		return current == other.current;
	}

	bool operator!=(const ConstReverseListIterator& other) const {
		return !(*this == other);
	}


private:
	const Node<T>* current;
};





template<typename T>

class Node
{
public:
	T val;
	Node<T>* next;
	Node<T>* previosus;
	Node(const T& val) {
		this->val = val;
		this->next = this;
		this->previosus = this;
	}
	Node()
	{
		val = 0;
		next = this;
		previosus = this;
	}


	~Node()
	{

	}

};

template<typename T>
class List
{
public:
	using iterator = ListIterator<T>;
	using const_iterator = ConstListIterator<T>;
	using reverse_iterator = ReverseListIterator<T>;
	using const_reverse_iterator = ConstReverseListIterator<T>;
public:

	List() {

		head = NULL;
	}
	List(const T values[]) {
		head = NULL;
		int size = sizeof(values) / sizeof(values[0]);
		const auto array_length = sizeof(values) == 0 ? 0 : size;
		for (size_t i = 0; i < array_length; i++)
		{
			add_before_head(values[i], head);
		}

	}

	~List()
	{
		Node<T>* current = head;
		Node<T>* next = NULL;
		while (current != NULL)
		{
			next = current->next;
			delete current;
			current = next;

		}

		head = nullptr;

	}

	List(const List<T>& rhs) {
		copyClass(rhs);

	}

	/*void add(T value) {

		Node* add(current)
		Node<T>* Newnode = new Node<T>(value);

		Node<T>* temp = head;

		if (head == NULL) {
			head = Newnode;
			return;

		}

		while (temp->next != NULL)
		{
			temp = temp->next;

		}
		temp->next = Newnode;



	}*/

	iterator beginn() {
		return iterator(head);
	}
	iterator end() {
		return iterator(head->previosus);
	}


	const_iterator cbegin() const {
		return const_iterator(head);
	}

	const_iterator cend() const {
		return const_iterator(head->previosus);
	}

	reverse_iterator rbegin() {
		return reverse_iterator(head->previosus);
	}
	reverse_iterator rend() {
		return reverse_iterator(head);
	}

	const_reverse_iterator rbegin() const {
		return const_reverse_iterator(head->previosus);
	}

	const_reverse_iterator rend() const {
		return const_reverse_iterator(head);
	}
	//https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp

	void add_front(T value) {
		Node<T>* Newnode = new Node<T>(value);
		Node<T>* current = head;
		if (head == NULL) {
			head = Newnode;
			Newnode->next = Newnode;
			Newnode->previosus = Newnode;
			return;

		}
		Newnode->previosus = current->previosus;
		Newnode->next = current;
		current->previosus = Newnode;
		do
		{
			current = current->next;
		} while (current->next != head);
		current->next = Newnode;
		head = Newnode;

	}
	void add_back(T value) {
		Node<T>* Newnode = new Node<T>(value);
		Node<T>* current = head;

		if (head == NULL) {
			head = Newnode;
			Newnode->next = Newnode;
			Newnode->previosus = Newnode;
			return;

		}

		/*while (current->next != head);
		{
			current = current->next;
		} */

		do
		{
			current = current->next;
		} while (current->next != head);

		current->next = Newnode;

		Newnode->next = head;
		Newnode->previosus = current;


	}

	//template<class T>
	static Node<T>* add_before_head(const T& value, Node<T>*& head) {

		Node<T>* Newnode = new Node<T>(value);
		Node<T>* current = head;
		if (head == NULL) {
			head = Newnode;
			Newnode->next = Newnode;
			Newnode->previosus = Newnode;
			return head;

		}
		else {
			Newnode->previosus = current->previosus;
			Newnode->next = current;
			current->previosus = Newnode;
			do
			{
				current = current->next;
			} while (current->next != head);
			current->next = Newnode;
			head = Newnode;

			return head;
		}
	}




	void print()const {
		Node<T>* temp = head;
		if (temp == nullptr) {
			cout << "List is empty" << endl;
			return;
		}
		cout << "List is:" << endl;
		do
		{
			cout << temp->val << " ";
			temp = temp->next;


		} while (temp != head);

		cout << endl;

	}


	void delete_at(int num) {

		Node<T>* temp1 = head;
		Node<T>* temp2 = NULL;

		while (num-- > 1)
		{
			temp2 = temp1;
			temp1 = temp1->next;
		}

		temp2->next = temp1->next;

	}
	/*delete temp1;*/
	List<T>& operator=(List<T>& rhs) {

		Node<T>* current = head;
		Node<T>* next = NULL;
		while (current != NULL)
		{
			next = current->next;
			delete current;
			current = next;

		}
		head = nullptr;

		Node<T>* temp = rhs.head;


		/*head = temp;*/



		while (temp != NULL)
		{

			add(temp->val);
			temp = temp->next;


		}

		return *this;
	}


	friend ostream& operator<<(ostream& os, const List<T>& rhs)
	{
		Node<T>* temp = head;
		os << "THList is:" << endl;
		while (temp != NULL)
		{
			os << temp->val << " ";
			temp = temp->next;
		}
		os << endl;
		return os;
	}



private:
	Node<T>* head;

protected:
	void copyClass(List rs) {
		Node<T>* current = head;
		Node<T>* next = NULL;
		while (current != NULL)
		{
			next = current->next;
			delete current;
			current = next;

		}
		head = nullptr;

		Node<T>* temp = rs.head;


		/*head = temp;*/



		while (temp != NULL)
		{

			add(temp->val);
			temp = temp->next;


		}

		/*return *this;*/

	}
};


int main()
{
	int x = 0;

	string myNum[3] = { "fsd","sadasd","dsad" };
	List<string> list3(myNum);
	list3.print();


	return 0;
}