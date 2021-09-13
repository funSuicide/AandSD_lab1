#include "Set.h"
#include <iostream>
#include <conio.h>
using namespace std;

void Menu(Set&A);

int GetKey()
{
	int Key = _getch();
	if ((Key == 0) || (Key == 224)) Key = _getch();
	return Key;
}

int main()
{
	std::cout << "Hello, User^_^!\n";
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
				int Size;
				std::cout << "Ented a size: ";
				std::cin >> Size;

				int* NewSet = new int[Size];
				for (int i = 0; i < Size; i++) {
					std::cout << "[" << i << "]: ";
					std::cin >> NewSet[i];
				}
				Set B(Size, NewSet);
				A = A + B;
				B.~Set();
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
				int Size;
				std::cout << "Ented a size: ";
				std::cin >> Size;

				int* NewSet = new int[Size];
				for (int i = 0; i < Size; i++) {
					std::cout << "[" << i << "]: ";
					std::cin >> NewSet[i];
				}

				Set B(Size, NewSet);
				A = A - B;
				B.~Set();
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
				int Size;
				std::cout << "Ented a size: ";
				std::cin >> Size;

				int* NewSet = new int[Size];
				for (int i = 0; i < Size; i++) {
					std::cout << "[" << i << "]: ";
					std::cin >> NewSet[i];
				}

				Set B(Size, NewSet);
				A = IntersectionSets(A, B);
				B.~Set();
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
			exit(0);
			break;
		default: printf("Select [0-3]");
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
				int Number;
				std::cout << "Ented a number: ";
				std::cin >> Number;
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
				int Number;
				std::cout << "Ented a number: ";
				std::cin >> Number;
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
			exit(0);
			break;
		default: printf("Выберите 1 из предложенных вариантов [0-5]");
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
					int Size;
					std::cout << "Ented a size: ";
					std::cin >> Size;

					int* NewSet = new int[Size];
					for (int i = 0; i < Size; i++) {
						std::cout << "[" << i << "]: ";
						std::cin >> NewSet[i];
					}
					Set A(Size, NewSet);
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
			case 52:
				system("cls");
				printf("Thank you! ^_^\n");
				exit(0);
			break;
			default: printf("Select [0-3]");
			}
		}
	}



