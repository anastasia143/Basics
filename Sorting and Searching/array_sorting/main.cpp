#include <QCoreApplication>
#include <iostream>

#include "quick_sort.h"
#include "merge_sort.h"
#include "heap_sort.h"
#include "bubble_sort.h"
#include "insert_sort.h"

using namespace std;

int main()
{
	int size = 17;
	int* array = new int[size];

	for (int i = 0; i < size; i++) {
		array[i] = rand() % (2 * size);
		cout << array[i] << " ";
	}

	insert_sort(size, array);

	cout << endl;

	for (int i = 0; i < size; i++)
		cout << array[i] << " ";

	delete []array;
	return 0;
}
