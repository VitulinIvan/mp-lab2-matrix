// исключение повторного включения файла.
#pragma once

#include "Vector.h"

template <class ValType>
class TMatrix : public TVector<TVector<ValType> > {
public:
	TMatrix(int s = 10);
	TMatrix(const TMatrix &mt);
	TMatrix(const TVector<TVector<ValType> > &mt);
	//TVector& GetVector(int pos);
	bool operator==(const TMatrix &mt);
	bool operator!=(const TMatrix &mt);
	TMatrix& operator= (const TMatrix &mt);
	TMatrix operator+ (const TMatrix &mt);
	TMatrix operator- (const TMatrix &mt);
	TMatrix operator* (const TMatrix &mt);
	// ввод / вывод
	friend istream& operator>>(istream &in, TMatrix &mt)
   	{
		for (int i = 0; i < mt.Size; i++)
			in >> mt.pVector[i];
		return (in);
	}
	friend ostream & operator<<( ostream &out, const TMatrix &mt)
   	{
		for (int i = 0; i < mt.Size; i++)
			out << mt.pVector[i] << endl;
		return (out);
	}
	ValType GetSum(const int i, const int j, const TMatrix &mt)
	{
		ValType sum = (ValType)0;
		for (int k = 0; k < mt.Size; k++)
			sum += TVector<TVector<ValType> >::pVector[i][k] * mt.pVector[k][j];
		return (sum);
	}
	void read_from_file();
	void save_to_file();
};

template <class ValType>
TMatrix<ValType>::TMatrix(int s) : TVector<TVector<ValType> >(s)
{
	if (s < 0)
		throw exception();
	for (int i = 0; i < s; i++)
		TVector<TVector<ValType> >::pVector[i] = TVector<ValType>(s, i);
}

template <class ValType> //конструктор копирования
TMatrix<ValType>::TMatrix(const TMatrix<ValType>& mt) :
	TVector<TVector<ValType> >(mt) { }

template <class ValType> // конструктор преобразования.
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> >& mt) :
	TVector<TVector<ValType> >(mt) { }

template <class ValType>
bool TMatrix<ValType>::operator==(const TMatrix<ValType>& mt)
{
	if (TVector<TVector<ValType> >::Size != mt.Size)
		return (false);
	for (int i = 0; i < mt.Size; i++)
		if (TVector<TVector<ValType> >::pVector[i] != mt.pVector[i])
			return (false);
	return (true);
}

template <class ValType>
bool TMatrix<ValType>::operator!=(const TMatrix<ValType>& mt)
{
	return (!(*this == mt));
}

template <class ValType>
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType>& mt)
{
	if (this == &mt)
		return (*this);
	if (TVector<TVector<ValType> >::Size != mt.Size)
	{
		delete[] TVector<TVector<ValType> >::pVector;
		TVector<TVector<ValType> >::pVector =
			new TVector<ValType>[(unsigned int)mt.Size];
	}
	TVector<TVector<ValType> >::Size = mt.Size;
	TVector<TVector<ValType> >::StartIndex = mt.StartIndex;
	for (int i = 0; i < mt.Size; i++)
		TVector<TVector<ValType> >::pVector[i] = mt.pVector[i];
	return (*this);
}

template <class ValType>
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType>& mt)
{
	return (TVector<TVector<ValType> >::operator+(mt));
}

template <class ValType>
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType>& mt)
{
	return (TVector<TVector<ValType> >::operator-(mt));
}

template <class ValType>
TMatrix<ValType> TMatrix<ValType>::operator*(const TMatrix<ValType>& mt)
{
	if (TVector<TVector<ValType> >::Size != mt.Size)
	{
		cout << "The wrong size of matrices." << endl; // По условию матрицы квадратные по условию в тексте ЛР
		throw exception();
	}
	TMatrix newMatrix(mt.Size);
	for (int i = 0; i < mt.Size; i++)
		for (int j = 0; j < mt.Size; j++)
			newMatrix[i][j] = GetSum(i, j, mt);
	return (newMatrix);
}

template <class ValType>
void TMatrix<ValType>::save_to_file() //Доп. задание №2 запись
{
	string fileName = "MatrixO.txt";

	
	ofstream output(fileName);
	if (!output)
	{
		cout << "Error open file " << fileName << endl;
		return;
	}
	output << this->GetSize() << endl;
	output << *this;
	output.close();
}

template <class ValType>
void TMatrix<ValType>::read_from_file() //Допю задание №2 чтение
{
	string	fileName = "MatrixI.txt";
	string	line;
	int		Size;

	
	ifstream input(fileName);
	if (!input)
	{
		cout << "Error open file " << fileName << endl;
		return;
	}
	input >> Size;
	*this = TMatrix<ValType>(Size);
	for (int i = 0; i < Size; i++)
	{
		getline(input, line);
		input >> (*this)[i];
	}
	input.close();
}
