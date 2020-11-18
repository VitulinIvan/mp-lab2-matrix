#include "Matrix.h"
#include <sstream>

using namespace std;

void AdditionMatrices(TMatrix<int> &one, TMatrix<int> &two)
{
	cout << "Addition matrices" << endl;
	cout << (one + two) << endl;
}

void SubtractionMatrices(TMatrix<int> &one, TMatrix<int> &two)
{
	cout << "Разность матриц." << endl;
	cout << (one - two) << endl;
}

void MultiplicationMatrices(TMatrix<int> &one, TMatrix<int> &two)
{
	cout << "Умножение матриц." << endl;
	cout << (one * two) << endl;
}

void CompareMatrices(TMatrix<int> &one, TMatrix<int> &two)
{
	cout << "Сравнение матриц." << endl;
	cout << "one == two (" << (one == two) << ")" << endl;
	cout << "one != two (" << (one != two) << ")" << endl;
	cout << endl;
}

void	Save(TMatrix<int> &mt)
{
	cout << "Сохранени матриц в файл." << endl;
	mt.save_to_file();
}

void	Read(TMatrix<int> &mt)
{
	cout << "Чтение матриц из файла." << endl;
	mt.read_from_file();
	cout << "Считанная матрица." << endl;
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
	cout << "Первая матрица." << endl;
	cout << one << endl;
	cout << "Вторая матрица." << endl;
	cout << two << endl;
	AdditionMatrices(one, two);
	SubtractionMatrices(one, two);
	MultiplicationMatrices(one, two);
	CompareMatrices(one, two);
	//Save(one);
	//Read(two);
	return (0);
}
