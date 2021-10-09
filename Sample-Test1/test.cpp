#include "pch.h"
#include"../AandSD_lab1/Set.cpp"

TEST(Set, CopyConstructor) {
	int a[3] = { 3, 4, 5 };
	Set A(3, a);
	Set B(A);
	for (int i = 0; i < 3; i++) {
		ASSERT_EQ(A[i], B[i]);
	}
}

TEST(Set, Destructor) {
	int a[3] = { 3, 4, 5 };
	Set A(3, a);
	A.~Set();
	ASSERT_EQ(0, A.GetCardinality());
}

TEST(Set, Constructor) {
	Set B;
	ASSERT_EQ(0, B.GetCardinality());
}

TEST(Set, ConstructorWithParametrs) {
	int a[3] = { 3, 4, 5 };
	Set A(3, a);
	ASSERT_EQ(3, A.GetCardinality());
	for (int i = 0; i < 3; i++) {
		ASSERT_EQ(A[i], a[i]);
	}
}

TEST(Set, AccessOperator) {
	int a[3] = { 3, 4, 5 };
	Set A(3, a);
	int number = A[0];
	ASSERT_EQ(3, number);
}

TEST(Set, EqualityOperator) {
	int a[3] = { 3, 4, 5 };
	Set A(3, a);
	Set B;
	B = A;
	for (int i = 0; i < 3; i++) {
		ASSERT_EQ(A[i], B[i]);
	}
}

TEST(Set, SummSetWithNumber) {
	Set B;
	B = B + 1;
	ASSERT_EQ(1, B[0]);
}

TEST(Set, DifferenceSetWithNumber) {
	int a[3] = { 3, 4, 5 };
	Set A(3, a);
	A = A - 5;
	ASSERT_EQ(2, A.GetCardinality());
}

TEST(Set, SummOfSets) {
	int a[3] = { 3, 4, 5 };
	Set A(3, a);
	int b[1] = { 1 };
	Set B(1, b);
	A = A + B;
	ASSERT_EQ(1, A[3]);
}

TEST(Set, DifferenceOfSets) {
	int a[3] = { 3, 4, 5 };
	Set A(3, a);
	int b[1] = { 5 };
	Set B(1, b);
	A = A - B;
	ASSERT_EQ(2, A.GetCardinality());
}

TEST(Set, IntersectionSets) {
	int a[3] = { 3, 4, 5 };
	Set A(3, a);
	int b[1] = { 5 };
	Set B(1, b);
	Set C = IntersectionSets(A, B);
	ASSERT_EQ(1, C.GetCardinality());
	ASSERT_EQ(5, C[0]);
}

TEST(Set, GetCardinality) {
	Set A;
	ASSERT_EQ(0, A.GetCardinality());
}

TEST(Set, ExceptionAccessOperator) {
	Set A;
	ASSERT_THROW(A[2], const char*);
}

TEST(Set, ExceptionSummSetWithNumber) {
	int a[3] = { 3, 4, 5 };
	Set A(3, a);
	ASSERT_THROW(A = A + 3, const char*);
}

TEST(Set, ExceptionDifferenceSetWithNumber) {
	int a[3] = { 3, 4, 5 };
	Set A(3, a);
	ASSERT_THROW(A = A - 5, const char*);
}

TEST(Set, ExceptionConstructorWithParametrs) {
	int a[3] = { 3, 4, 5 };
	int b[3] = { 5, 5, 5 };
	ASSERT_THROW(Set A(2, a), const char*);
	ASSERT_THROW(Set B(3, b), const char*);
}
