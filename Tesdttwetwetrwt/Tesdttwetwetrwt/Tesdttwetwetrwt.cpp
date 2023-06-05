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



template<typename T>

class Node
{
public:

	T val;
	Node<T>* next;
	Node<T>* previosus;

	Node() {
		this->next = this;
		this->previosus = this;
	}

	Node(const T& val, Node<T>* next, Node<T>* previous) {
		this->val = val;

		this->next = next;
		this->previosus = previous;

		previous -> next = this;
		next->previosus = this;
	}

	Node(const T& val) {
		this->val = val;
		this->next = this;
		this->previosus = this;
	}
	


	~Node()
	{

	}

};

template<typename T>
class Iterator
{
private:
	Node<T>* curren;
public:
	Iterator() {

	}

	Iterator(Node<T>* node_ptr) {
		curren = node_ptr;
	}

	Iterator& operator++() {
		curren = curren->next;
		return *this;
	}

	Iterator operator++ (int) {
		Node<T>* temp = curren;
		curren = curren->next;
		return Iterator(temp);
	}
	Iterator operator-- (int) {
		Node<T>* temp = curren;
		curren = curren->previosus;
		return Iterator(temp);

	}
	Iterator& operator-- () {
		curren = curren->previosus;
		return *this;
	}
	bool operator== (const Iterator& other) const {
		return curren == other.curren;
	}

	bool operator!= (const Iterator& other) const {
		return !(*this == other);
	}

	T& operator*() const { return curren->val; }
	T* operator->() { return &(curren->val); }


};



template<typename T>
class reverse_iteratorr
{
private:
	Node<T>* current;
public:
	reverse_iteratorr() {
		
	}

	reverse_iteratorr(Node<T>* node_ptr) {
		current = node_ptr;
	}

	reverse_iteratorr& operator++() {
		current = current->next;
		return *this;
	}

	reverse_iteratorr operator++ (int) {
		Node<T>* temp = current;
		current = current->next;
		return reverse_iteratorr(temp);
	}
	reverse_iteratorr operator-- (int) {
		Node<T>* temp = current;
		current = current->previosus;
		return reverse_iteratorr(temp);

	}
	reverse_iteratorr& operator-- () {
		current = current->previosus;
		return *this;
	}
	bool operator== (const reverse_iteratorr& other) const {
		return current == other.current;
	}

	bool operator!= (const reverse_iteratorr& other) const {
		return !(*this == other);
	}

	T& operator*() const { return current->val; }
	T* operator->() { return &(current->val); }


};


template<typename T>
class List
{
public:
	template <typename T>
	using Reverse_iteratorr = reverse_iteratorr<T>;
	template <typename T>
	using iterator = Iterator<T>;

	
	
public:

	List() {
		head = new Node<T>();
	}
	List(const T values[], int size) {
		head = new Node<T>();
		//const auto size = sizeof(values) == 0 ? 0 : size;
		for (int i = 0; i < size; ++i)
		{
			add_before_head(values[i], head);
		}

	}

	~List()
	{
		Node<T>* current = head;
		Node<T>* next = NULL;

		do {
			next = current->next;
			delete current;
			current = next;

		} while (current != head);

		head = nullptr;

	}

	List(const List<T>& rhs) {
		copyClass(rhs);

	}


	iterator<T> beginn() {
		return iterator<T>(head->next);
	}
	iterator<T> end() {
		return iterator<T>(head);
	}
	reverse_iteratorr<T> beginnn() {
		return reverse_iteratorr<T>(head->previosus);
	}
	reverse_iteratorr<T> endd() {
		return reverse_iteratorr<T>(head);
	}
	

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


		if (isListEmpty(head)) {
			Node<T>* newNode = new Node<T>(value,head,head);
			
			return head;
		}
		else {
			Node<T>* newNode = new Node<T>(value, head, head->previosus);

			return head;
		}
		return 0;
	}

	static bool isListEmpty(Node<T>* head) {
		return head->next == head && head->previosus == head;
	}




	void print()const {
		Node<T>* temp = head->next;
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


	string myNum[3] = { "fsd","sadasd","dsad" };
	int x = 3;
	List<string> list3(myNum, x);
	list3.print();

   
	/*int i1=0, i2 = 0;
	cout <<"i1= "<< ++i1<<endl;
	cout << "i1= "<< i2++<<endl;
	cout << "--------------- " << endl;
	cout << "i1= " << i1 << endl;
	cout << "i1= " << i2 << endl;*/
	cout << "--------------- " << endl;

	for (Iterator<string> it = list3.beginn();
		it != list3.end();
		it++)
	{
		cout << "f: " << *it << " ";
	}
	cout << endl;

	cout << "--------------- " << endl;
	string myNumM[3] = { "fsDd","sadaDsd","dsDad" };
	int xY = 3;
	List<string> list33(myNumM, xY);
	

	for (reverse_iteratorr<string> iter = list33.beginnn();
		iter != list33.endd();
		iter++)
	{
		cout << *iter << " ";
	}

	return 0;
}