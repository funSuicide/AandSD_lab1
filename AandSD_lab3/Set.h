#pragma once
#include <iostream>
#include <string>
#include <vector>

template <class T>
class Set {
	std::vector<T> v;
public:
	auto Contain(T element)const
	{
		auto index = v.begin();
		if (*index == element) return index;
		while (*index != element)
		{
			++index;
			if (*index == element) return index;
		}
		throw "[!]: This element is missing in the set!\n";
	}

	T operator[](int index) const
	{
		if ((index >= v.size()) || (index < 0) || (v.size() == 0)) throw "[!]: Incorrect index!\n";
		return v[index];
	}

	/*
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
	*/
	void operator + (T value) {
		for (auto it = v.begin(); it != v.end(); it++)
		{
			if (*it == value) throw "[!]: The specified value already belongs to the set\n!";
		}
		v.push_back(value);
	}

	void operator - (T value)
	{
		if (v.size() == 0) throw "[!]: No elements exist!\n";
		auto index = Contain(value);
		v.erase(index);
	}

	unsigned GetCardinality() const {
		return v.size();
	}

	friend std::ostream& operator << (std::ostream &out, const Set<T> &rhs) {
		out << "Cardinality is " << rhs.GetCardinality() << "\n";
		out << "Set = { ";
		for (auto it = rhs.v.begin(); it != rhs.v.end(); it++) {
			out << *it << " ";
		}
		out << "}";
		return out;
	}

	/*
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
	*/
};