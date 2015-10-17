#pragma once

/** 1.7 Write an algorithm such that if an element in an MxN
 * matrix is 0, its entire row and column is set to 0.
**/

void setZeros()
{
	int rowCount = 4;
	int columnCount = 3;
	int arr[4][3] = {{1,2,0}, {1,0,8}, {2,3,6}, {1,1,1}};

	int* rows = new int[rowCount];
	int* columns = new int[columnCount];
	for (int i = 0; i < rowCount; i++)
		rows[i] = false;
	for (int i = 0; i < columnCount; i++)
		columns[i] = false;

	for (int i = 0; i < rowCount; i++)
		for (int k = 0; k < columnCount; k++) {
			if (arr[i][k] == 0) {
				rows[i] = true;
				columns[k] = true;
			}
		}

	for (int i = 0; i < rowCount; i++) {
		for (int k = 0; k < columnCount; k++) {
			if (rows[i] || columns[k])
				arr[i][k] = 0;
			cout << arr[i][k] << " ";
		}
		cout << endl;
	}

	delete[] rows;
	delete[] columns;
}
