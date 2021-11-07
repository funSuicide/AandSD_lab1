#include "Set.h"
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

int main() {

	Set<int> A;
	A + 5;
	A + 7;
	Set<int> B;
	B + 5;
	B + 3;

	Set<int> C = A.IntersectionSets(B);
	Set<int> D = A + B;

	std::cout << A << std::endl;
	std::cout << A[0] << std::endl;
	std::cout << C << std::endl;
	std::cout << D << std::endl;
	return 0;
}