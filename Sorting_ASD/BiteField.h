#pragma once

#include <iostream>

typedef int MyType;

class BitField
{
private:
	int size;
	//array
	MyType* arr;
	int n;
public:

	BitField(int n = 100)
	{
		this->n = n;
		size = n / sizeof(MyType) / 8 + 1;
		arr = new MyType[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = 0;
		}
	}
	void printArray()
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << "Element [" << i << "]" << " = " << arr[i] << std::endl;
		}
	}
	void print()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < sizeof(MyType) * 8; j++)
			{
				std::cout << GetBit(i, j);
				if (i * sizeof(MyType) * 8 + j == n - 1)
				{
					break;
				}
			}

			std::cout << " ";
		}
		std::cout << std::endl;
	}
	int GetBit(int i, int j)
	{
		MyType el = arr[i];
		MyType mask = 1 << j;
		int result = el & mask;
		return result == 0 ? 0 : 1;
	}
	void SetBit(int k)
	{
		int i = k / (sizeof(MyType) * 8);
		int j = k % (sizeof(MyType) * 8);
		MyType el = arr[i];
		MyType mask = 1 << j;
		arr[i] = arr[i] | mask;
		//arr[i] |= mask;
	}
	void ClrBit() //очистка 
	{
		//111111101111
		//arr[i] = arr[i] | mask;

	}
};

class Set
{
	BitField b1;
public:
	void Add(int k);
	void Del(int k);
	bool Contain();
	void print(); // ƒолжен печатать числа которые добавлены
};