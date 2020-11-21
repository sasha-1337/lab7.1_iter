#include <iostream>
#include <iomanip>
#include <time.h>
#include <Windows.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i< rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

void Change(int** a, const int row1, const int row2, const int colCount)
{
	int tmp;
	for (int j = 0; j < colCount; j++)
	{
		tmp = a[row1][j];
		a[row1][j] = a[row2][j];
		a[row2][j] = tmp;
	}
}

void Sort(int** a, const int rowCount, const int colCount) 
{
	for (int i0 = 0; i0 < rowCount - 1; i0++)
		for (int i1 = 0; i1 < rowCount - i0 - 1; i1++)
			if ((a[i1][0] > a[i1 + 1][0])
				||
				(a[i1][0] == a[i1 + 1][0] &&
					a[i1][1] > a[i1 + 1][1])
				||
				(a[i1][0] == a[i1 + 1][0] &&
					a[i1][1] == a[i1 + 1][1] &&
					a[i1][3] < a[i1 + 1][3]))
				Change(a, i1, i1 + 1, colCount);
}

int Calc(int** a, const int rowCount, const int colCount, int &S, int &t)
{
	S = 0;
	t = 0;
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if (!(a[i][j] % 2)) 
			{
				S += a[i][j];
				t++;
				a[i][j] = 0;
			}
	return S;
	return t;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	int Low = -12;
	int High = 23;

	int rowCount = 7;
	int colCount = 6;

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];

	cout << " Матриця: " << endl;
	Create(a, rowCount, colCount, Low, High);
	Print(a, rowCount, colCount);
	cout << " Відсортована матриця: " << endl;
	Sort(a, rowCount, colCount);
	Print(a, rowCount, colCount);

	int S = 0;
	int t = 0;
	cout << " Матриця тільки з непарними елементами: " << endl;
	Calc(a, rowCount, colCount, S, t);
	Print(a, rowCount, colCount);
	cout << " S = " << S << endl;
	cout << " Кількість: " << t << endl;
	

	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;

	system("pause");
	return 0;
}