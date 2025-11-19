
#include "BiteField.h"

int main() 
{
	std::cout << "Hello world\n";
	BitField b1;
	b1.print();
	b1.SetBit(25);
	b1.SetBit(50);
	b1.SetBit(75);
	b1.print();
	std::cout << sizeof(int)/4;
	
}