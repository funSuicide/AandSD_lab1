#include "Set.h"
#include <iostream>
#include <conio.h>
using namespace std;

void Menu(Set&A);

int CheckNumber(){
	char Data[32];
	char Mask[12] = { '1','2','3','4','5','6','7','8','9','0', '-' };
	int Checker = 0;
	int Count = 0;
	std::cin >> Data;
	for (int i = 0; i < strlen(Data); i++)
		{
		if (Data[i] == '-') Count++;
			for (int j = 0; j < 12; j++)
			{
			if (Data[i] == Mask[j]) Checker++;
			}
	}
	if ((Checker != strlen(Data)) || (Checker == 0) || (Count > 1)) throw "[!]: Incorrect data format...\n";
	int Number = (int)atof(Data);
	return Number;
}

int GetKey()
{
	int Key = _getch();
	if ((Key == 0) || (Key == 224)) Key = _getch();
	return Key;
}

int main()
{
	std::cout << "Hello, User ^_^!\n\n";
	Set A;
	Menu(A);
}

void MenuWorkSets(Set&A) {
	int Repeat = 1;
	std::cout << A << std::endl;
	std::cout << "[0]: Sum of sets\n[1]: Difference of sets\n[2]: Union of sets\n[3]: Back\n" << std::endl;
	while (Repeat != 0)
	{
		int k = GetKey();
		switch (k)
		{
		case 48:
		{
			system("cls");
			try
			{
				std::cout << "Ented a size: ";
				int Size = CheckNumber();
				if (Size < 0) Size *= -1;

				int* NewSet = new int[Size];
				for (int i = 0; i < Size; i++) {
					std::cout << "[" << i << "]: ";
					NewSet[i] = CheckNumber();
				}
				Set B(Size, NewSet);
				A = A + B;
			}
			catch (const char* err)
			{
				std::cerr << err;
			}
			MenuWorkSets(A);
			break;
		}
		case 49:
		{
			system("cls");
			try
			{
				std::cout << "Ented a size: ";
				int Size  = CheckNumber();
				if (Size < 0) Size *= -1;

				int* NewSet = new int[Size];
				for (int i = 0; i < Size; i++) {
					std::cout << "[" << i << "]: ";
					NewSet[i] = CheckNumber();
				}

				Set B(Size, NewSet);
				A = A - B;
			}
			catch (const char* err)
			{
				std::cerr << err;
			}
			MenuWorkSets(A);
			break;
		}
		case 50:
		{
			system("cls");
			try
			{
				std::cout << "Ented a size: ";
				int Size = CheckNumber();
				if (Size < 0) Size *= -1;
				int* NewSet = new int[Size];
				for (int i = 0; i < Size; i++) {
					std::cout << "[" << i << "]: ";
					NewSet[i] = CheckNumber();
				}
				Set B(Size, NewSet);
				A = IntersectionSets(A, B);
			}
			catch (const char* err)
			{
				std::cerr << err;
			}
			MenuWorkSets(A);
			break;
		}
		case 51:
			system("cls");
			Menu(A);
			break;
		default: std::cout << "Select [0-3]" << std::endl;
		}
	}
}

void MenuSet(Set&A) {
	int Repeat = 1;
	std::cout << A << std::endl;
	std::cout << "[0]: Add a number to a set\n[1]: Remove a number from a set\n[2]: Back\n" << std::endl;
	while (Repeat != 0)
	{
		int k = GetKey();
		switch (k)
		{
		case 48:
		{
			system("cls");
			try
			{
				std::cout << "Ented a number: ";
				int Number = CheckNumber();
				A = A + Number;
			}
			catch (const char* err)
			{
				std::cerr << err;
			}
			MenuSet(A);
			break;
		}
		case 49:
			system("cls");
			try
			{
				std::cout << "Ented a number: ";
				int Number = CheckNumber();
				A = A - Number;
			}
			catch (const char* err)
			{
				std::cerr << err;
			}
			MenuSet(A);
			break;
		case 50:
			system("cls");
			Menu(A);
			break;
		default: std::cout << "Select [0-2]" << std::endl;
		}
	}
}

void Menu(Set&A){
	int Repeat = 1;
	std::cout << A << std::endl;
	std::cout << "[0]: Create a new set\n[1]: Edit a set\n[2]: Operations with sets\n[3]: Clear Set\n[4]: Exit the program\n" << std::endl;
	while (Repeat != 0)
		{
			int k = GetKey();
			switch (k)
				{
			case 48:
				system("cls");
				{
					A.~Set();
					try {
						std::cout << "Enter a size: ";
						int Size = CheckNumber();
						if (Size < 0) Size *= -1;
						int* NewSet = new int[Size];
						for (int i = 0; i < Size; i++) {
							std::cout << "[" << i << "]: ";
							NewSet[i] = CheckNumber();
						}
						Set B(Size, NewSet);
						A = B;
					}
					catch (const char* err)
					{
						std::cerr << err;
					}
					Menu(A);
				}
				break;
			case 49:
				system("cls");
				MenuSet(A);
				break;
			case 50:
				system("cls");
				MenuWorkSets(A);
				break;
			case 51:
				system("cls");
				A.~Set();
				Menu(A);
				break;
			case 52:
				system("cls");
				A.~Set();
				std::cout << "Thank you! ^_^" << std::endl;
				exit(0);
				break;
			default: std::cout << "Select [0-4]" << std::endl;
		}
	}
}



