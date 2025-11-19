#pragma once

#include <iostream>

typedef int MyType;

class BitField
{
private:
    int size;
    MyType* arr;
    int n;
public:

    BitField(int n = 100)
    {
        this->n = n;
        size = n / (sizeof(MyType) * 8) + 1; 
        arr = new MyType[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }

    ~BitField()
    {
        delete[] arr;
    }

    BitField(const BitField& other)
    {
        n = other.n;
        size = other.size;
        arr = new MyType[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = other.arr[i];
        }
    }

    //оператор присваивания
    BitField& operator=(const BitField& other)
    {
        if (this != &other)
        {
            delete[] arr;
            n = other.n;
            size = other.size;
            arr = new MyType[size];
            for (int i = 0; i < size; i++)
            {
                arr[i] = other.arr[i];
            }
        }
        return *this;
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

    
    int GetBit(int k)
    {
        if (k < 0 || k >= n) return 0;  
        int i = k / (sizeof(MyType) * 8);
        int j = k % (sizeof(MyType) * 8);
        MyType el = arr[i];
        MyType mask = 1 << j;
        int result = el & mask;
        return result == 0 ? 0 : 1;
    }

    int GetBit(int i, int j)  
    {
        if (i < 0 || i >= size || j < 0 || j >= sizeof(MyType) * 8)
            return 0;
        MyType el = arr[i];
        MyType mask = 1 << j;
        int result = el & mask;
        return result == 0 ? 0 : 1;
    }

    void SetBit(int k)
    {
        if (k < 0 || k >= n) return;
        int i = k / (sizeof(MyType) * 8);
        int j = k % (sizeof(MyType) * 8);
        MyType mask = 1 << j;
        arr[i] = arr[i] | mask;
    }

    void ClrBit(int k)  // очистка бита
    {
        if (k < 0 || k >= n) return; 
        int i = k / (sizeof(MyType) * 8);
        int j = k % (sizeof(MyType) * 8);
        MyType mask = ~(1 << j);  //инвертированная маска
        arr[i] = arr[i] & mask;   
    }

    void ToggleBit(int k) 
    {
        if (k < 0 || k >= n) return;
        int i = k / (sizeof(MyType) * 8);
        int j = k % (sizeof(MyType) * 8);
        MyType mask = 1 << j;
        arr[i] = arr[i] ^ mask; 
    }

    int GetCapacity() const { return n; }
};

class Set
{
    BitField b1;
public:
    Set(int capacity = 100) : b1(capacity) {}

    void Add(int k)
    {
        if (k >= 0 && k < b1.GetCapacity())
            b1.SetBit(k);
    }

    void Del(int k)
    {
        if (k >= 0 && k < b1.GetCapacity())
            b1.ClrBit(k);
    }

    bool Contain(int k)  
    {
        if (k < 0 || k >= b1.GetCapacity())
            return false;
        return b1.GetBit(k) == 1;
    }

    void print()  
    {
        std::cout << "Set elements: ";
        bool isEmpty = true;

        for (int i = 0; i < b1.GetCapacity(); i++)
        {
            if (b1.GetBit(i) == 1)
            {
                std::cout << i << " ";
                isEmpty = false;
            }
        }

        if (isEmpty)
            std::cout << "empty";

        std::cout << std::endl;
    }

    void Clear()  
    {
        for (int i = 0; i < b1.GetCapacity(); i++)
        {
            b1.ClrBit(i);
        }
    }

    int Count()  
    {
        int count = 0;
        for (int i = 0; i < b1.GetCapacity(); i++)
        {
            if (b1.GetBit(i) == 1)
                count++;
        }
        return count;
    }

    bool IsEmpty()
    {
        return Count() == 0;
    }
};