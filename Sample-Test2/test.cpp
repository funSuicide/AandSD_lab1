#include "pch.h"
#include"C:\Users\Admin\source\repos\AandSD_lab2\AandSD_lab2/Set.h"

TEST(MySet, Constructor) {
	Set<int> A;
	ASSERT_EQ(0, A.GetCardinality());

	Set<double> B;
	ASSERT_EQ(0, B.GetCardinality());

	Set<int> C;
	ASSERT_EQ(0, C.GetCardinality());
}

TEST(MySet, CopyConstructor) {
	int a[3] = { 3, 4, 5 };
	Set<int> A(3, a);
	Set<int> B(A);
	for (int i = 0; i < 3; i++) {
		ASSERT_EQ(A[i], B[i]);
	}

	double c[3] = { 3, 4, 5 };
	Set<double> C(3, c);
	Set<double> D(C);
	for (int i = 0; i < 3; i++) {
		ASSERT_EQ(C[i], D[i]);
	}

	std::string e[3] = { "a", "b", "c" };
	Set<std::string> E(3, e);
	Set<std::string> F(E);
	for (int i = 0; i < 3; i++) {
		ASSERT_EQ(F[i], E[i]);
	}
}

TEST(MySet, ConstructorWithParametrs) {
	int a[3] = { 3, 4, 5 };
	Set<int> A(3, a);
	ASSERT_EQ(3, A.GetCardinality());
	for (int i = 0; i < 3; i++) {
		ASSERT_EQ(A[i], a[i]);
	}

	double b[3] = { 3.1, 4.1, 5.1 };
	Set<double> B(3, b);
	ASSERT_EQ(3, B.GetCardinality());
	for (int i = 0; i < 3; i++) {
		ASSERT_EQ(B[i], b[i]);
	}

	std::string c[3] = { "a", "b", "c" };
	Set<std::string> C(3, c);
	ASSERT_EQ(3, C.GetCardinality());
	for (int i = 0; i < 3; i++) {
		ASSERT_EQ(C[i], c[i]);
	}
}

TEST(MySet, AccessOperator) {
	int a[3] = { 3, 4, 5 };
	Set<int> A(3, a);
	int number = A[0];
	ASSERT_EQ(3, number);

	double b[3] = { 3.1, 4.1, 5.1 };
	Set<double> B(3, b);
	double number2 = B[0];
	ASSERT_EQ(3.1, number2);

	std::string c[3] = { "a", "b", "c" };
	Set<std::string> C(3, c);
	std::string value = C[0];
	ASSERT_EQ("a", value);
}

TEST(MySet, EqualityOperator) {
	int a[3] = { 3, 4, 5 };
	Set<int> A(3, a);
	Set<int> B;
	B = A;
	for (int i = 0; i < 3; i++) {
		ASSERT_EQ(A[i], B[i]);
	}

	double c[3] = { 3.1, 4.1, 5.1 };
	Set<double> C(3, c);
	Set<double> D;
	D = C;
	for (int i = 0; i < 3; i++) {
		ASSERT_EQ(C[i], D[i]);
	}

	std::string e[3] = { "a", "b", "c" };
	Set<std::string> E(3, e);
	Set<std::string> F;
	F = E;
	for (int i = 0; i < 3; i++) {
		ASSERT_EQ(E[i], F[i]);
	}
}

TEST(MySet, SummSetWithNumber) {
	Set<int> B;
	B = B + 1;
	ASSERT_EQ(1, B[0]);

	Set<double> C;
	C = C + 1.1;
	ASSERT_EQ(1.1, C[0]);

	Set<std::string> D;
	D = D + "a";
	ASSERT_EQ("a", D[0]);
}

TEST(MySet, DifferenceSetWithNumber) {
	int a[3] = { 3, 4, 5 };
	Set<int> A(3, a);
	A = A - 5;
	ASSERT_EQ(2, A.GetCardinality());

	double b[3] = { 3.1, 4.1, 5.1 };
	Set<double> B(3, b);
	B = B - 5.1;
	ASSERT_EQ(2, B.GetCardinality());

	std::string c[3] = { "a", "b", "c" };
	Set<std::string> C(3, c);
	C = C - "a";
	ASSERT_EQ(2, C.GetCardinality());
}

TEST(MySet, SummOfSets) {
	int a[3] = { 3, 4, 5 };
	Set<int> A(3, a);
	int b[1] = { 1 };
	Set<int> B(1, b);
	A = A + B;
	ASSERT_EQ(1, A[3]);

	double c[3] = { 3.1, 4.1, 5.1 };
	Set<double> C(3, c);
	double d[1] = { 1.1 };
	Set<double> D(1, d);
	C = C + D;
	ASSERT_EQ(1.1, C[3]);

	std::string e[3] = { "a", "b", "c" };
	Set<std::string> E(3, e);
	std::string f[1] = { "v" };
	Set<std::string> F(1, f);
	E = E + F;
	ASSERT_EQ("v", E[3]);
}

TEST(MySet, DifferenceOfSets) {
	int a[3] = { 3, 4, 5 };
	Set<int> A(3, a);
	int b[1] = { 5 };
	Set<int> B(1, b);
	A = A - B;
	ASSERT_EQ(2, A.GetCardinality());

	double c[3] = { 3.1, 4.1, 5.1 };
	Set<double> C(3, c);
	double d[1] = { 5.1 };
	Set<double> D(1, d);
	C = C - D;
	ASSERT_EQ(2, C.GetCardinality());

	std::string e[3] = { "a", "b", "c" };
	Set<std::string> E(3, e);
	std::string f[1] = { "a" };
	Set<std::string> F(1, f);
	E = E - F;
	ASSERT_EQ(2, E.GetCardinality());
}

TEST(MySet, IntersectionSets) {
	int a[3] = { 3, 4, 5 };
	Set<int> A(3, a);
	int b[1] = { 5 };
	Set<int> B(1, b);
	Set<int> C = IntersectionSets(A, B);
	ASSERT_EQ(1, C.GetCardinality());
	ASSERT_EQ(5, C[0]);

	double e[3] = { 3.1, 4.1, 5.1 };
	Set<double> E(3, e);
	double f[1] = { 5.1 };
	Set<double> F(1, f);
	Set<double> T = IntersectionSets(E, F);
	ASSERT_EQ(1, T.GetCardinality());
	ASSERT_EQ(5.1, T[0]);

	std::string z[3] = { "a", "b", "c" };
	Set<std::string> Z(3, z);
	std::string w[1] = { "a" };
	Set<std::string> W(1, w);
	Set<std::string> Y = IntersectionSets(Z, W);
	ASSERT_EQ(1, Y.GetCardinality());
	ASSERT_EQ("a", Y[0]);
}

TEST(MySet, GetCardinality) {
	Set<int> A;
	ASSERT_EQ(0, A.GetCardinality());

	Set<double> B;
	ASSERT_EQ(0, B.GetCardinality());

	Set<std::string> C;
	ASSERT_EQ(0, C.GetCardinality());
}

TEST(MySet, ExceptionAccessOperator) {
	Set<int> A;
	ASSERT_THROW(A[2], const char*);

	Set<double> B;
	ASSERT_THROW(B[2], const char*);

	Set<std::string> C;
	ASSERT_THROW(C[2], const char*);
}

TEST(MySet, ExceptionSummSetWithNumber) {
	int a[3] = { 3, 4, 5 };
	Set<int> A(3, a);
	ASSERT_THROW(A = A + 3, const char*);

	double b[3] = { 3.1, 4.1, 5.1 };
	Set<double> B(3, b);
	ASSERT_THROW(B = B + 3.1, const char*);

	std::string c[3] = { "a", "b", "c" };
	Set<std::string> C(3, c);
	ASSERT_THROW(C = C + "a", const char*);
}

TEST(MySet, ExceptionDifferenceSetWithNumber) {
	int a[3] = { 3, 4, 5 };
	Set<int> A(3, a);
	ASSERT_THROW(A = A - 7, const char*);

	double b[3] = { 3.1, 4.1, 5.1 };
	Set<double> B(3, b);
	ASSERT_THROW(A = A - 7.1, const char*);

	std::string c[3] = { "a", "b", "c" };
	Set<std::string> C(3, c);
	ASSERT_THROW(C = C - "f", const char*);
}

TEST(MySet, ExceptionConstructorWithParametrs) {
	int a[3] = { 5, 5, 5 };
	ASSERT_THROW(Set<int> A(3, a), const char*);

	double b[3] = { 5.1, 5.1, 5.1 };
	ASSERT_THROW(Set<double> B(3, b), const char*);

	std::string c[3] = { "a", "a", "a" };
	ASSERT_THROW(Set<std::string> C(3, c), const char*);
}
