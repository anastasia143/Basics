#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <forward_list>
#include <fstream>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

#include "exception_example.h"

using namespace std;


// Copy constructor, equals, destructor

class IntArray {
public:
	IntArray(IntArray const &a)
		: size_(a.size_)
		, data_(new int[size_])
	{
		for (size_t i = 0; i != size_; ++i)
			data_[i] = a.data_[i];
	}
	~IntArray() {
		delete [] data_;
	}
	IntArray &operator=( IntArray const& a)
	{
		if (this != &a) {
			delete[] data_;
			size_ = a.size_;
			data_ = new int[size_];
			for (size_t i = 0; i != size_; ++i)
			data_[i] = a.data_[i];
		}
		return *this;
		/* if (this != &a)
		IntArray(a).swap(*this );
		return *this;*/
	}
private:
	size_t size_;
	int * data_;
};


// Operator overloading

struct Vector {
	Vector(double x, double y)
		: x(x)
		, y(y) { }
	Vector operator-() const
	{
		return Vector(-x, -y);
	}
	Vector operator-(Vector const& p) const
	{
		return Vector(x - p.x, y - p.y);
	}
	Vector operator*=(double d)
	{
		x *= d;
		y *= d;
		return *this;
	}
	double operator []( size_t i) const
	{
		return (i == 0) ? x : y;
	}
	//bool operator()( double d) const { ... }
	//void operator()( double a, double b) { ... }
	double x, y;
};

Vector operator-(Vector const& v)
{
	return Vector(-v.x, -v.y);
}
Vector operator+(Vector const& v,Vector const& w)
{
	return Vector(v.x + w.x, v.y + w.y);
}
Vector operator*(Vector const& v, double d)
{
	return Vector(v.x * d, v.y * d);
}
Vector operator*(double d, Vector const& v) {
	return v * d;
}

// compare
bool anagramComparator(string &str1, string &str2)
{
	sort(str1.begin(), str2.end());
	sort(str2.begin(), str2.end());
	return str1.compare(str2);
}

void anagramSort(vector<string> &strVector) {
	sort(strVector.begin(), strVector.end(), anagramComparator);
}


struct Person
{
	Person(int weight, int height)
		: weight(weight)
		, height(height) { }

	int weight;
	int height;
};

struct SortByWeight
{
	bool operator()(Person &p1, Person &p2)
	{
		return (p1.weight < p2.weight);
	}
};

struct SortByHeight
{
	bool operator()(Person &p1, Person &p2)
	{
		return (p1.height < p2.height);
	}
};


int main()
{

	// Array
	// (p + k) — сдвиг на k ячеек типа int вправо.
	// (p - k) — сдвиг на k ячеек типа int влево.
	// (q - p) — количество ячеек между указателями.
	// p[k] эквивалентно *(p + k).
	int m[10] = {1, 2, 3, 4, 5};
	int* p = &m[0]; // адрес начала массива
	int* q = &m[9]; // адрес последнего элемента

	// Char*
	char c1 [100] = "Hello";
	char c2[] = ", world!";
	size_t strLen = strlen(c1);
	strcat(c1, c2);
	int strCmp = (strcmp(c1, c2) == 0);

	// String
	string s1 = "Hello";
	string s2 = ", world!";
	size_t strLen2 = s1.size();
	s1 = s1 + s2;
	int strCmp2 = (s1 == s2);

	// Files
	string name;
	ifstream input("input.txt");
	input >> name;
	ofstream output("output.txt");
	output << "Hi , " << name << endl;

	// Rand
	cout << "random number = " << rand() << endl; // запуск генератора случайных чисел

	function();


	/** STL **/

	/// 1. Sequences (Arrays/Linked Lists): ordered collections


	// vector = a dynamic array, like C array (i.e., capable of random access) with the ability to resize itself automatically
	// when inserting or erasing an object. Inserting an element to the back of the vector at the end takes amortized constant time.
	// Removing the last element takes only constant time, because no resizing happens. Inserting and erasing at the beginning or in
	// the middle is linear in time.
	// A specialization for type bool exists, which optimizes for space by storing bool values as bits.
	vector<int> mVector2 = {3,4};
	mVector2.push_back(4);
	mVector2.push_back(9);
	mVector2.pop_back();

	vector<Person> mVector;
	sort(mVector.begin(), mVector.end(),[](Person const &a, Person const &b){ return a.weight < b.weight; });
	sort(mVector.begin(), mVector.end(), SortByHeight());

	// list = a doubly linked list; elements are not stored in contiguous memory. Opposite performance from a vector. Slow lookup
	// and access (linear time), but once a position has been found, quick insertion and deletion (constant time).
	list<int> mList = {2,3};
	mList.push_back(5);
	mList.push_front(2);
	mList.pop_back();
	mList.pop_front();
	mList.clear();
	size_t listSize = mList.size();

	mList.sort();

	// list (c++11)
	list<Person> mList2;
	for (Person const &p: mList2) {
	}

	for (std::list<int>::iterator it = mList.begin(); it != mList.end(); ++it)
		std::cout << " " << *it;

	// slist
	forward_list<int> mSlist;
	mSlist.push_front(0);
	mSlist.push_front(1);
	mSlist.insert_after(mSlist.begin(), 2);

	forward_list<int>::iterator back = mSlist.begin();
	back = mSlist.insert_after(back, 3);
	back = mSlist.insert_after(back, 4);
	back = mSlist.insert_after(back, 5);

	// deque = a vector with insertion/erase at the beginning or end in amortized constant time, however lacking some guarantees on iterator validity after altering the deque.
	// Both vectors and deques provide a very similar interface and can be used for similar purposes, but internally both
	// work in quite different ways: While vectors use a single array that needs to be occasionally reallocated for growth,
	// the elements of a deque can be scattered in different chunks of storage, with the container keeping the necessary information
	// internally to provide direct access to any of its elements in constant time and with a uniform sequential interface (through iterators).
	// Therefore, deques are a little more complex internally than vectors, but this allows them to grow more efficiently under certain circumstances,
	// especially with very long sequences, where reallocations become more expensive.
	deque<int> myDeque(5);

	for (int i = 0; i < myDeque.size(); i++) {
		myDeque[i] = 0;
	}
	int element = myDeque[0];
	if (myDeque.empty()) {
	}


	/// 2. Container adaptors
	// queue = Provides FIFO queue interface in terms of push/pop/front/back operations.
	// Any sequence supporting operations front(), back(), push_back(), and pop_front() can
	// be used to instantiate queue (e.g. list and deque).
	queue<int> myQueue;
	myQueue.push(4);
	myQueue.pop();
	int queueSize = myQueue.size();
	int elem = myQueue.front();
	int elem2 = myQueue.back();

	// priority queue = Provides priority queue interface in terms of push/pop/top
	// operations (the element with the highest priority is on top).
	// Any random-access sequence supporting operations front(), push_back(), and pop_back()
	// can be used to instantiate priority_queue (e.g. vector and deque). It is implemented using a heap.
	// Elements should additionally support comparison (to determine which element has a higher priority
	// and should be popped first).
	priority_queue<int> prQueue;
	prQueue.push(4);
	prQueue.pop();
	int prQueueElem = prQueue.top();

	// stack = Provides LIFO stack interface in terms of push/pop/top operations (the last-inserted element is on top).
	// Any sequence supporting operations back(), push_back(), and pop_back() can be used to
	// instantiate stack (e.g. vector, list, and deque).
	stack<int> myStack;
	myStack.push(6);
	myStack.push(4);
	myStack.pop();
	int stackSize = myStack.size();
	int elem3 = myStack.top();

	/// 3. Associative containers: unordered collections
	// set = a mathematical set; inserting/erasing elements in a set does not invalidate iterators
	// pointing in the set. Provides set operations union, intersection, difference, symmetric difference
	// and test of inclusion. Type of data must implement comparison operator < or custom comparator function
	// must be specified; such comparison operator or comparator function must guarantee strict weak ordering, otherwise behavior is undefined. Typically implemented using a self-balancing binary search tree.
	set<int> s;

	for (int i = 1; i <= 100; i++) {
		s.insert(i);
	}
	bool setEmpty = s.empty();
	if (s.find(42) != s.end()) {
		// 42 присутствует
	}
	else {
		// 42 не присутствует
	}
	s.erase(s.find(42));


	std::map<char,int> mymap;
	std::map<char,int>::iterator it;

	mymap['a'] = 50;
	mymap['b'] = 100;
	mymap['c'] = 150;

	it = mymap.find('b');
	if (it != mymap.end())
		mymap.erase(it);

	cout << "elements in mymap:" << '\n';
	cout << "a => " << mymap.find('a')->second << '\n';
	cout << "a => " << mymap.find('a')->first << '\n';


	// multiset = same as a set, but allows duplicate elements (mathematical Multiset).
	multiset<int> mymultiset;
	mymultiset.insert(4);

	// map = an associative array; allows mapping from one data item (a key) to another (a value).
	// Type of key must implement comparison operator < or custom comparator function must be specified; such comparison operator or comparator function must guarantee strict weak ordering, otherwise behavior is undefined. Typically implemented using a self-balancing binary search tree.

	// multimap = same as a map, but allows duplicate keys.
	multimap<string, int> mymultimap;
	mymultimap.insert(pair<string, int>("b", 3));

	// hash_set
	// hash_multiset
	// hash_map
	// hash_multimap	simil

	/// 4. Other types of containers
	// bitset	stores series of bits similar to a fixed-sized vector of bools. Implements bitwise operations
	// and lacks iterators. Not a sequence. Provides random access.
	// valarray = another C-like array like vector, but is designed for high speed numerics at the expense of
	// some programming ease and general purpose use. It has many features that make it ideally suited for use with vector processors in traditional vector supercomputers and SIMD units in consumer-level scalar processors, and also ease vector mathematics programming even in scalar computers.

	/// 5. Simple containers
	// pair
	pair<int,int> headPair = make_pair(2, 3);
	return 0;
}
