#include <iostream>
#include <fstream>
using namespace std;

// matrix is two dimensional array. You should transposition matrix
void transposition(int rows, int cols, int **matrix) {
	for (int i = 0; i < cols; i++) {
		cout << matrix[0][i];

		for (int j = 1; j < rows; j++) {
			cout << " " << matrix[j][i];
		}

		cout << endl;
	}
}

int main(int argc, char** argv)
{
	ifstream ifs;
	ifs.open("test02.txt");
	
	int rows;
	int cols;
	ifs >> rows;
	ifs >> cols;
	int** matrix = new int*[rows];
	try
	{
		int i = 0;
		int j = 0;
		for (int i = 0; i < rows; i++) {
			matrix[i] = new int[cols];
			for (int j = 0; j < cols; j++) {
				ifs >> matrix[i][j];
			}
		}
		transposition(rows, cols, matrix);
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

	ifs.close();
	return 0;
}
