
#include "BiteField.h"

int main() 
{
	/*std::cout << "Hello world\n";
	BitField b1;
	b1.print();
    std::cout << std::endl;
	b1.SetBit(25);
	b1.SetBit(50);
	b1.SetBit(75);
	b1.print();
    b1.ClrBit(50);
    b1.print();*/
	std::cout << "---------Class Set----------" << std::endl;

	Set mySet(50);
	mySet.IsEmpty();
	mySet.Add(1);
	mySet.Add(18);
	mySet.Add(25);
	mySet.Count();
	mySet.print();
	mySet.Del(25);
	mySet.print();

;	Set set2(20);
	set2.Add(5);
	set2.Add(2);
	set2.Add(21);
	set2.print();

	std::cout << "Union: ";
	Set unionSet = mySet.Union(set2);
	unionSet.print();

	Set intersectionSet = unionSet.Intersection(mySet);
	std::cout << "Intersection: ";
	intersectionSet.print();

	Set difference = unionSet.Difference(mySet);
	std::cout << "Difference: ";
	difference.print();
	
	Set SymmDiff = unionSet.SymmetricDifference(set2);
	std::cout << "SymmetricalDifference: ";
	SymmDiff.print();

	
}