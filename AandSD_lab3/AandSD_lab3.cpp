#include "Set.h"
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

int main() {

	Set<int> A;
	A + 5;
	std::cout << A << std::endl;
	std::cout << A[0] << std::endl;
	return 0;
}