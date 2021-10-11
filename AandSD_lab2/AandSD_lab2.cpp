#include "Set.h"
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;
//
int CheckNumber() {
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

double CheckNumberDouble() {
	char Data[32];
	char Mask[12] = { '1','2','3','4','5','6','7','8','9','0', '-', '.' };
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
	double Number = (double)atof(Data);
	return Number;
}

int GetKey()
{
	int Key = _getch();
	if ((Key == 0) || (Key == 224)) Key = _getch();
	return Key;
}

void MenuInt(Set<int> &rhs);
void MenuDouble(Set<double> &rhs);
void MenuString(Set<std::string> &rhs);


int main()
{
	Set<int> A;
	Set<double> B;
	Set<std::string> C;

	int Repeat = 1;
	std::cout << "Hello, User ^_^!\n\n";
	std::cout << "[0]: Set of int\n[1]: Set of double\n[2]: Set of string\n"<< std::endl;
	while (Repeat != 0)
	{
		int k = GetKey();
		switch (k)
		{
		case 48:
			system("cls");
			MenuInt(A);
			break;
		case 49:
			system("cls");
			MenuDouble(B);
			break;
		case 50:
			system("cls");
			MenuString(C);
			break;
		default: std::cout << "Select [0-2]" << endl;
		}
	}
}


void MenuWorkSetsString(Set<std::string>&A) {
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

				std::string* NewSet = new std::string[Size];
				std::cin.ignore();
				for (int i = 0; i < Size; i++) {
					std::cout << "[" << i << "]: ";
					std::getline(std::cin, NewSet[i]);
				}
				Set<std::string> B(Size, NewSet);
				A = A + B;
			}
			catch (const char* err)
			{
				std::cerr << err;
			}
			MenuWorkSetsString(A);
			break;
		}
		case 49:
		{
			system("cls");
			try
			{
				std::cout << "Ented a size: ";
				int Size = CheckNumber();
				if (Size < 0) Size *= -1;

				std::string* NewSet = new std::string[Size];
				std::cin.ignore();
				for (int i = 0; i < Size; i++) {
					std::cout << "[" << i << "]: ";
					std::getline(std::cin, NewSet[i]);
				}

				Set<std::string> B(Size, NewSet);
				A = A - B;
			}
			catch (const char* err)
			{
				std::cerr << err;
			}
			MenuWorkSetsString(A);
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
				std::string* NewSet = new std::string[Size];
				std::cin.ignore();
				for (int i = 0; i < Size; i++) {
					std::cout << "[" << i << "]: ";
					std::getline(std::cin, NewSet[i]);
				}
				Set<std::string> B(Size, NewSet);
				A = IntersectionSets(A, B);
			}
			catch (const char* err)
			{
				std::cerr << err;
			}
			MenuWorkSetsString(A);
			break;
		}
		case 51:
			system("cls");
			MenuString(A);
			break;
		default: std::cout << "Select [0-3]" << std::endl;
		}
	}
}


void MenuSetString(Set<std::string>&A) {
	int Repeat = 1;
	std::cout << A << std::endl;
	std::cout << "[0]: Add an element to a set\n[1]: Remove an element from a set\n[2]: Back\n" << std::endl;
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
				std::cout << "Ented an element: ";
				std::string str;
				std::getline(std::cin, str);
				A = A + str;
			}
			catch (const char* err)
			{
				std::cerr << err;
			}
			MenuSetString(A);
			break;
		}
		case 49:
			system("cls");
			try
			{
				std::cout << "Ented an element: ";
				std::string str;
				std::getline(std::cin, str);
				A = A - str;
			}
			catch (const char* err)
			{
				std::cerr << err;
			}
			MenuSetString(A);
			break;
		case 50:
			system("cls");
			MenuString(A);
			break;
		default: std::cout << "Select [0-3]" << std::endl;
		}
	}
}

void MenuString(Set<std::string>&A) {
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
					std::string* NewSet = new std::string[Size];
					std::cin.ignore();
					for (int i = 0; i < Size; i++) {
						std::cout << "[" << i << "]: ";
						getline(std::cin, NewSet[i]);
					}
					Set<std::string> B(Size, NewSet);
					A = B;
				}
				catch (const char* err)
				{
					std::cerr << err;
				}
				MenuString(A);
			}
			break;
		case 49:
			system("cls");
			MenuSetString(A);
			break;
		case 50:
			system("cls");
			MenuWorkSetsString(A);
			break;
		case 51:
			system("cls");
			A.~Set();
			MenuString(A);
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

void MenuWorkSetsDouble(Set<double>&A) {
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

				double* NewSet = new double[Size];
				for (int i = 0; i < Size; i++) {
					std::cout << "[" << i << "]: ";
					NewSet[i] = CheckNumberDouble();
				}
				Set<double> B(Size, NewSet);
				A = A + B;
			}
			catch (const char* err)
			{
				std::cerr << err;
			}
			MenuWorkSetsDouble(A);
			break;
		}
		case 49:
		{
			system("cls");
			try
			{
				std::cout << "Ented a size: ";
				int Size = CheckNumber();
				if (Size < 0) Size *= -1;

				double* NewSet = new double[Size];
				for (int i = 0; i < Size; i++) {
					std::cout << "[" << i << "]: ";
					NewSet[i] = CheckNumberDouble();
				}

				Set<double> B(Size, NewSet);
				A = A - B;
			}
			catch (const char* err)
			{
				std::cerr << err;
			}
			MenuWorkSetsDouble(A);
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
				double* NewSet = new double[Size];
				for (int i = 0; i < Size; i++) {
					std::cout << "[" << i << "]: ";
					NewSet[i] = CheckNumberDouble();
				}
				Set<double> B(Size, NewSet);
				A = IntersectionSets(A, B);
			}
			catch (const char* err)
			{
				std::cerr << err;
			}
			MenuWorkSetsDouble(A);
			break;
		}
		case 51:
			system("cls");
			MenuDouble(A);
			break;
		default: std::cout << "Select [0-3]" << std::endl;
		}
	}
}


void MenuSetDouble(Set<double>&A) {
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
				double Number = CheckNumberDouble();
				A = A + Number;
			}
			catch (const char* err)
			{
				std::cerr << err;
			}
			MenuSetDouble(A);
			break;
		}
		case 49:
			system("cls");
			try
			{
				std::cout << "Ented a number: ";
				double Number = CheckNumberDouble();
				A = A - Number;
			}
			catch (const char* err)
			{
				std::cerr << err;
			}
			MenuSetDouble(A);
			break;
		case 50:
			system("cls");
			MenuDouble(A);
			break;
		default: std::cout << "Select [0-2]" << std::endl;
		}
	}
}

void MenuDouble(Set<double>&A) {
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
					double* NewSet = new double[Size];
					for (int i = 0; i < Size; i++) {
						std::cout << "[" << i << "]: ";
						NewSet[i] = CheckNumberDouble();
					}
					Set<double> B(Size, NewSet);
					A = B;
				}
				catch (const char* err)
				{
					std::cerr << err;
				}
				MenuDouble(A);
			}
			break;
		case 49:
			system("cls");
			MenuSetDouble(A);
			break;
		case 50:
			system("cls");
			MenuWorkSetsDouble(A);
			break;
		case 51:
			system("cls");
			A.~Set();
			MenuDouble(A);
			break;
		case 52:
			system("cls");
			A.~Set();
			std::cout << "Thank you!^_^" << std::endl;
			exit(0);
			break;
		default: std::cout << "Select [0-4]" << std::endl;
		}
	}
}

void MenuWorkSetsInt(Set<int>&A) {
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
				Set<int> B(Size, NewSet);
				A = A + B;
			}
			catch (const char* err)
			{
				std::cerr << err;
			}
			MenuWorkSetsInt(A);
			break;
		}
		case 49:
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

				Set<int> B(Size, NewSet);
				A = A - B;
			}
			catch (const char* err)
			{
				std::cerr << err;
			}
			MenuWorkSetsInt(A);
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
				Set<int> B(Size, NewSet);
				A = IntersectionSets(A, B);
			}
			catch (const char* err)
			{
				std::cerr << err;
			}
			MenuWorkSetsInt(A);
			break;
		}
		case 51:
			system("cls");
			MenuInt(A);
			break;
		default: std::cout << "Select [0-3]" << std::endl;
		}
	}
}


void MenuSetInt(Set<int>&A) {
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
			MenuSetInt(A);
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
			MenuSetInt(A);
			break;
		case 50:
			system("cls");
			MenuInt(A);
			break;
		default: std::cout << "Select [0-2]" << std::endl;
		}
	}
}


void MenuInt(Set<int>&A) {
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
					Set<int> B(Size, NewSet);
					A = B;
				}
				catch (const char* err)
				{
					std::cerr << err;
				}
				MenuInt(A);
			}
			break;
		case 49:
			system("cls");
			MenuSetInt(A);
			break;
		case 50:
			system("cls");
			MenuWorkSetsInt(A);
			break;
		case 51:
			system("cls");
			A.~Set();
			MenuInt(A);
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