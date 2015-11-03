#pragma once
#include <vector>

using namespace std;

/** 9.7 A circus is designing a tower routine consisting of people standing
 * atop one another’s shoulders. For practical and aesthetic reasons, each
 * person must be both shorter and lighter than the person below him or her.
 * Given the heights and weights of each person in the circus, write a method
 * to compute the largest possible number of people in such a tower.
 *
 * EXAMPLE:
 * Input (ht, wt): (65, 100) (70, 150) (56, 90) (75, 190) (60, 95) (68, 110)
 * Output: The longest tower is length 6 and includes from top to bottom:
 * (56, 90) (60,95) (65,100) (68,110) (70,150) (75,190)
**/

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
	bool operator() (Person &p1, Person &p2)
	{
		return (p1.weight < p2.weight);
	}
};

struct SortByHeight
{
	bool operator() (Person &p1, Person &p2)
	{
		return (p1.height < p2.height);
	}
};

vector<Person> &findMaxSeq(vector<Person> &vec)
{
	SortByHeight sortByHeight;
	SortByWeight sortByWeight;
	sort(vec.begin(), vec.end(), sortByHeight);
	sort(vec.begin(), vec.end(), sortByWeight);

	vector<Person> *maxSeq = new vector<Person>;
	vector<Person> *curSeq = new vector<Person>;
	curSeq->push_back(vec.at(0));

	int size = vec.size();
	for (int i = 1; i < size; i++) {
		Person p1 = vec.at(i - 1);
		Person p2 = vec.at(i);

		if (p1.height < p2.height && p1.weight < p2.weight) {
//			curSeq->push_back(p2);
		}
		else {
			if (curSeq->size() > maxSeq->size()) {
				delete maxSeq;
				maxSeq = new vector<Person>(*curSeq);
			}
			curSeq->clear();
			curSeq->push_back(p2);
		}
	}
	delete curSeq;
	return *maxSeq;
}

void test3()
{
	vector<Person> vec;
	vec.push_back(Person(65, 100));
	vec.push_back(Person(70, 150));
	vec.push_back(Person(56, 90));
	vec.push_back(Person(75, 190));
	vec.push_back(Person(60, 95));
	vec.push_back(Person(68, 110));

	vector<Person> maxSeq = findMaxSeq(vec);
	cout << "hey" << endl;
	for (Person const &p: maxSeq) {
		cout << "(" << p.weight << "," << p.height << "), ";
	}
}


