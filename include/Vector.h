// исключение повторного включения файла.
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <fstream>

using namespace std;

template <class ValType>
class TVector
{
protected:
	ValType *pVector;
	int Size;			// размер вектора
	int StartIndex;		// индекс первого элемента вектора (!!!EndIndex)
public:
	TVector(int s = 10, int si = 0);
	TVector(const TVector &v);						// конструктор копирования
   	~TVector();
	int GetSize() const { return (Size); }			// размер вектора
	int GetStartIndex() const {return (StartIndex);}// индекс первого элемента
	ValType& GetValue (int pos) const;				// доступ с контролем индекса
	ValType& operator[](int pos);					// доступ
	bool operator==(const TVector &v);				// сравнение
	bool operator!=(const TVector &v);				// сравнение
	TVector& operator= (const TVector &v);			// присванивание
	// скалярные операции         
	TVector operator+ (const ValType &val);
	TVector operator- (const ValType &val);
	TVector operator* (const ValType &val);
	// векторные операции
	TVector operator+ (const TVector &v);
	TVector operator- (const TVector &v);
	TVector operator* (const TVector &v);
	// ввод вывод
	friend istream& operator>>(istream &in, TVector &v)
	{
		for (int i = 0; i < v.Size; i++) in >> v.GetValue(i);
		return (in);
	}
	friend ostream& operator<<(ostream &out, const TVector &v)
	{
		for (int i = 0; i < v.Size; i++) out << v.GetValue(i) << ' ';
		return (out);
	}
};

template <class ValType>
TVector<ValType>::TVector(int s, int si)
{
	if (s < 0 || si < 0)
		throw exception();
	Size = s;
	StartIndex = si;
	pVector = new ValType[(unsigned int)s];
}

template <class ValType>
TVector<ValType>::TVector(const TVector<ValType>& v)
{
	if (&v == this)
		return;
	Size = v.Size;
	StartIndex = v.StartIndex;
	pVector = new ValType[(unsigned int)Size];
	for (int i = 0; i < Size; i++)
		pVector[i] = v.pVector[i];
}

template <class ValType>
TVector<ValType>::~TVector()
{
	if (pVector != NULL)
		delete[] pVector;
	pVector = NULL;
}

template <class ValType>
ValType& TVector<ValType>::GetValue(int pos) const
{
	if (pos < 0 || pos > Size)
		throw exception();
	return (pVector[pos]);
}

template <class ValType>
ValType& TVector<ValType>::operator[](int pos)	 // доступ
{
	if (pos < 0 || pos > Size)
		throw exception();
	return (pVector[pos]);
}

template <class ValType>
bool TVector<ValType>::operator==(const TVector& v)
{
	if (Size != v.Size)
		return (false);
	for (int i = 0; i < Size; i++)
		if (pVector[i] != v.pVector[i])
			return (false);
	return (true);
}

template <class ValType>
bool TVector<ValType>::operator!=(const TVector& v)
{
	return (!(*this == v));
}

template <class ValType>
TVector<ValType>& TVector<ValType>::operator=(const TVector& v)
{
	if (this == &v)
		return (*this);
	if (Size != v.Size)
	{
		delete[] pVector;
		pVector = new ValType[(unsigned int)v.Size];
	}
	Size = v.Size;
	StartIndex = v.StartIndex;
	for (int i = 0; i < Size; i++)
		pVector[i] = v.pVector[i];
	return (*this);
}

template <class ValType>
TVector<ValType> TVector<ValType>::operator+(const ValType& val)
{
	TVector newVec(Size, StartIndex);
	for (int i = 0; i < newVec.Size; i++)
		newVec.pVector[i] = pVector[i] + val;
	return (newVec);
}

template <class ValType>
TVector<ValType> TVector<ValType>::operator-(const ValType& val)
{
	TVector newVec(Size, StartIndex);
	for (int i = 0; i < newVec.Size; i++)
		newVec.pVector[i] = pVector[i] - val;
	return (newVec);
}

template <class ValType>
TVector<ValType> TVector<ValType>::operator*(const ValType& val)
{
	TVector newVec(Size, StartIndex);
	for (int i = 0; i < newVec.Size; i++)
		newVec.pVector[i] = pVector[i] * val;
	return (newVec);
}

template <class ValType>
TVector<ValType> TVector<ValType>::operator+(const TVector& v)
{
	if (Size != v.Size)
		throw exception();
	TVector newVec(Size, StartIndex);
	for (int i = 0; i < newVec.Size; i++)
		newVec.pVector[i] = pVector[i] + v.pVector[i];
	return (newVec);
}

template <class ValType>
TVector<ValType> TVector<ValType>::operator-(const TVector& v)
{
	if (Size != v.Size)
		throw exception();
	TVector newVec(Size, StartIndex);
	for (int i = 0; i < newVec.Size; i++)
		newVec.pVector[i] = pVector[i] - v.pVector[i];
	return (newVec);
}

template <class ValType>
TVector<ValType> TVector<ValType>::operator*(const TVector& v)
{
	if (Size != v.Size)
		throw exception();
	TVector newVec(Size, StartIndex);
	for (int i = 0; i < newVec.Size; i++)
		newVec.pVector[i] = pVector[i] * v.pVector[i];
	return (newVec);
}