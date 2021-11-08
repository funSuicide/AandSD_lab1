#pragma once
#include <iostream>
#include <string>
#include <vector>

template <class T>
class Set {
	std::vector<T> v;
public:
	auto Contain(T element)const {
		for (auto it = v.begin(); it != v.end(); it++) {
			if (*it == element) return it;
		}
		throw "[!]: This element is missing in the set!\n";
	}

	T operator[](int index) const {
		int idx = 0;
		if ((index >= v.size()) || (index < 0) || (v.size() == 0)) throw "[!]: Incorrect index!\n";
		for (auto it = v.begin(); it != v.end(); it++) {
			if (idx == index) return *it;
			idx++;
		}
	}

	Set<T> operator + (const Set &rhs) {
		Set<T> tmp(*this);
		for (auto it = rhs.v.begin(); it != rhs.v.end(); it++) {
			bool flag = true;
			for (auto iter = v.begin(); iter != v.end(); iter++) {
				if (*it == *iter) {
					flag = false;
					break;
				}
			}
			if (flag == true) {
				tmp.v.push_back(*it);
			}
		}
		return tmp;
	}
	
	Set<T> operator - (const Set<T> &rhs) {
		Set<T> tmp(*this);
		for (auto it = rhs.v.begin(); it != rhs.v.end(); it++) {
			for (auto iter = v.begin(); iter != v.end(); iter++) {
				if (*it == *iter) {
					tmp - *iter;
					break;
				}
			}
		}
		return tmp;
	}
	
	Set<T> IntersectionSets(const Set<T> &rhs) {
		Set<T> tmp;
		for (auto it = rhs.v.begin(); it != rhs.v.end(); it++) {
			for (auto iter = v.begin(); iter != v.end(); iter++) {
				if (*it == *iter) {
					tmp.v.push_back(*it);
					break;
				}
			}
		}
		return tmp;
	}

	void ClearSet() {
		v.clear();
	}

	void operator + (T value) {
		for (auto it = v.begin(); it != v.end(); it++)
		{
			if (*it == value) throw "[!]: The specified value already belongs to the set!\n";
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
};