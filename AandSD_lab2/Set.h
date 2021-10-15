#pragma once
#include <iostream>
#include <string>

template <class T>
class Set {
	T *array;
	int cardinality;
public:
	Set() {
		array = nullptr;
		cardinality = 0;
	}

	Set(int cardinality, T*array) {
		for (int i = 0; i < cardinality; i++) {
			for (int j = 0; j < cardinality; j++) {
				if ((array[i] == array[j]) && i != j) throw "[!]: Invalid array format\n";
			}
		}
		this->cardinality = cardinality;
		this->array = new T[this->cardinality];
		for (int i = 0; i < this->cardinality; i++) {
			this->array[i] = array[i];
		}
	}

	Set(const Set<T> &rhs) {
		cardinality = rhs.cardinality;
		array = new T[cardinality];
		for (int i = 0; i < cardinality; i++) {
			array[i] = rhs.array[i];
		}
	}

	~Set() {
		delete[]array;
		array = 0;
		cardinality = 0;
	}

	T operator [] (int index) const{
		if (index >= cardinality) throw "[!]: Incorrect access by index\n";
		else return array[index];
	}

	Set<T> operator = (const Set<T> &rhs) {
		if (this == &rhs) {
			return *this;
		}

		this->~Set();
		cardinality = rhs.cardinality;
		array = new T[cardinality];
		for (int i = 0; i < cardinality; i++) {
			array[i] = rhs.array[i];
		}
		return *this;
	}

	Set<T> operator + (const Set &rhs) {
		Set<T> tmp(*this);
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

	Set<T> operator - (const Set<T> &rhs) {
		Set<T> tmp(*this);
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

	Set<T> operator + (T value) {
		for (int i = 0; i < cardinality; i++) {
			if (array[i] == value) throw "[!]: The specified value already belongs to the set\n";
		}
		Set<T> tmp;
		tmp.cardinality = this->cardinality + 1;
		tmp.array = new T[tmp.cardinality];
		for (int i = 0; i < tmp.cardinality - 1; i++)
		{
			tmp.array[i] = array[i];
		}
		tmp.array[tmp.cardinality - 1] = value;
		return tmp;
	}

	Set<T> operator - (T value) {
		int counter = -1;
		for (int i = 0; i < cardinality; i++) {
			if (array[i] == value) counter = i;
		}
		if (counter != -1) {
			Set<T> tmp;
			tmp.cardinality = this->cardinality - 1;
			tmp.array = new T[tmp.cardinality];
			if (counter == 0) {
				for (int i = 0; i < tmp.cardinality; i++)
				{
					tmp.array[i] = array[i + 1];
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

	int GetCardinality() const {
		return cardinality;
	}

	friend std::ostream& operator << (std::ostream &out, const Set<T> &rhs) {
		out << "Cardinality is " << rhs.cardinality << "\n";
		out << "Set = { ";
		for (int i = 0; i < rhs.cardinality; i++) {
			out << rhs.array[i] << " ";
		}
		out << "}";
		return out;
	}

	friend Set<T> IntersectionSets(Set<T> &rhs1, Set<T> &rhs2) {
		Set<T> tmp;
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
};


