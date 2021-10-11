#pragma once
#include "Set.h"

Set::Set() {
	array = nullptr;
	cardinality = 0;
}

Set::Set(int cardinality, int *array) {
	for (int i = 0; i < cardinality; i++) {
		for (int j = 0; j < cardinality; j++) {
			if ((array[i] == array[j]) && i!=j) throw "[!]: Invalid array format\n";
		}
	}
	this->cardinality = cardinality;
	this->array = new int[this->cardinality];
	for (int i = 0; i < this->cardinality; i++) {
		this->array[i] = array[i];
	}
}

Set::Set(const Set &rhs) {
	cardinality = rhs.cardinality;
	array = new int[cardinality];
	for (int i = 0; i < cardinality; i++) {
		array[i] = rhs.array[i];
	}
}

Set::~Set() {
	delete[]array;
	array = 0;
	cardinality = 0;
}

int& Set::operator [] (const int index) {
	if (index >= cardinality) throw "[!]: Incorrect access by index\n";
	else return array[index];
}

Set Set::operator = (const Set &rhs) {
	if (this == &rhs) {
		return *this;
	}

	this->~Set();
	cardinality = rhs.cardinality;
	array = new int[cardinality];
	for (int i = 0; i < cardinality; i++) {
		array[i] = rhs.array[i];
	}
	return *this;
}

Set Set::operator + (const Set &rhs) {
	Set tmp(*this);
	for (int i = 0; i < rhs.cardinality; i++) {
		bool flag = true;
		for (int j = 0; j < cardinality; j++) {
			if (rhs.array[i] == array[j]) {
				flag = false;
				break;
			}
		}
		if (flag == true) {
			tmp = tmp + rhs.array[i];
		}
	}
	return tmp;
}

Set Set::operator - (const Set &rhs) {
	Set tmp(*this);
	for (int i = 0; i < rhs.cardinality; i++) {
		for (int j = 0; j < cardinality; j++) {
			if (rhs.array[i] == array[j]) {
				tmp = tmp - rhs.array[i];
				break;
			}
		}
	}
	return tmp;
}

Set Set::operator + (const int value) {
	for (int i = 0; i < cardinality; i++) {
		if (array[i] == value) throw "[!]: The specified value already belongs to the set\n";
	}
	Set tmp;
	tmp.cardinality = this->cardinality + 1;
	tmp.array = new int[tmp.cardinality];
	for (int i = 0; i < tmp.cardinality - 1; i++)
	{
		tmp.array[i] = array[i];
	}
	tmp.array[tmp.cardinality - 1] = value;
	return tmp;
}

Set Set::operator - (const int value) {
	int counter = -1;
	for (int i = 0; i < cardinality; i++) {
		if (array[i] == value) counter = i;
	}
	if (counter != -1) {
		Set tmp;
		tmp.cardinality = this->cardinality - 1;
		tmp.array = new int[tmp.cardinality];
		if (counter == 0) {
			for (int i = 0; i < tmp.cardinality; i++)
			{
				tmp.array[i] = array[i+1];
			}
		}
		for (int i = 0; i < counter; i++)
		{
			tmp.array[i] = array[i];
		}
		for (int i = counter + 1; i < cardinality; i++)
		{
			tmp.array[i-1] = array[i];
		}
		return tmp;
	}
	else throw ("[!]: This element is missing in the set\n");
}

std::ostream& operator << (std::ostream &out, const Set &rhs) {
	out << "Cardinality is " << rhs.cardinality << "\n";
	out << "Set = { ";
	for (int i = 0; i < rhs.cardinality; i++) {
		out << rhs.array[i] << " ";
	}
	out << "}";
	return out;
}

Set IntersectionSets(const Set &rhs1, const Set &rhs2) {
	Set tmp;
	for (int i = 0; i < rhs1.cardinality; i++) {
		for (int j = 0; j < rhs2.cardinality; j++) {
			if (rhs1.array[i] == rhs2.array[j]) {
				tmp = tmp + rhs1.array[i];
				break;
			}
		}
	}
	return tmp;
}

int Set::GetCardinality() const {
	return cardinality;
}