#pragma once
#include <iostream>

class Set {
	int *array;
	int cardinality;
public:
	Set(); 
	Set(int cardinality, int *set); 
	Set(const Set &rhs); 
	~Set(); 

	int& operator [] (const int index); 
	Set operator = (const Set &rhs);
	Set operator + (const Set &rhs);
	Set operator - (const Set &rhs);
	Set operator + (const int value);
	Set operator - (const int value);

	int GetCardinality() const;

	friend std::ostream& operator << (std::ostream &out, const Set &rhs);
	friend Set IntersectionSets(const Set &rhs1, const Set &rhs2);
};

