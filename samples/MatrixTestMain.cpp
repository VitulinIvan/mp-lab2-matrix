#include "Matrix.h"
#include <sstream>

void AdditionMatrices(TMatrix<int>& one, TMatrix<int>& two)
{
	cout << "�������� ������." << endl;
	cout << (one + two) << endl;
}

void SubtractionMatrices(TMatrix<int>& one, TMatrix<int>& two)
{
	cout << "�������� ������." << endl;
	cout << (one - two) << endl;
}

void MultiplicationMatrices(TMatrix<int>& one, TMatrix<int>& two)
{
	cout << "��������� ������." << endl;
	cout << (one * two) << endl;
}

void CompareMatrices(TMatrix<int>& one, TMatrix<int>& two)
{
	cout << "��������� ������." << endl;
	cout << "one == two (" << (one == two) << ")" << endl;
	cout << "one != two (" << (one != two) << ")" << endl;
	cout << endl;
}

void	Save(TMatrix<int>& mt)
{
	cout << "��������� ������ � ����." << endl;
	mt.save_to_file();
}

void	Read(TMatrix<int>& mt)
{
	cout << "������ ������ �� �����." << endl;
	mt.read_from_file();
	cout << "��������� �������." << endl;
	cout << mt << endl;
}

int main(void)
{
	setlocale(LC_CTYPE, "Russian");
	stringstream ss("1 2 3 4 5 6 7 8 9");
	stringstream cc("9 8 7 6 5 4 3 2 1");
	TMatrix<int> one(3);
	TMatrix<int> two(3);
	ss >> one;
	cc >> two;
	cout << "������ �������." << endl;
	cout << one << endl;
	cout << "������ �������." << endl;
	cout << two << endl;
	AdditionMatrices(one, two);
	SubtractionMatrices(one, two);
	MultiplicationMatrices(one, two);
	CompareMatrices(one, two);
	Save(one);
	Read(two);
	return (0);
}