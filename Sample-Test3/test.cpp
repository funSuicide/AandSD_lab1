#include "pch.h"
#include"C:\Users\Admin\source\repos\AandSD_lab3\AandSD_lab3/Set.h"


TEST(MySet, SummSetWithNumber) {
	Set<int> B;
	B + 1;
	ASSERT_EQ(1, B[0]);

	Set<double> C;
	C + 1.1;
	ASSERT_EQ(1.1, C[0]);

	Set<std::string> D;
	D + "a";
	ASSERT_EQ("a", D[0]);
}

TEST(MySet, GetCardinality) {
	Set<int> A;
	ASSERT_EQ(0, A.GetCardinality());

	Set<double> B;
	ASSERT_EQ(0, B.GetCardinality());

	Set<std::string> C;
	ASSERT_EQ(0, C.GetCardinality());
}

TEST(MySet, DifferenceSetWithNumber) {
	Set<int> A;
	A + 5;
	A + 7;
	A - 7;
	ASSERT_EQ(1, A.GetCardinality());

	Set<double> B;
	B + 3.1;
	B + 4.1;
	B - 4.1;
	ASSERT_EQ(1, B.GetCardinality());

	
	Set<std::string> C;
	C + "a";
	C + "b";
	C - "b";
	ASSERT_EQ(1, C.GetCardinality());
}

TEST(MySet, AccessOperator) {
	Set<int> A;
	A + 3;
	int number = A[0];
	ASSERT_EQ(3, number);

	Set<double> B;
	B + 3.1;
	double number2 = B[0];
	ASSERT_EQ(3.1, number2);

	Set<std::string> C;
	C + "a";
	std::string value = C[0];
	ASSERT_EQ("a", value);
}


TEST(MySet, SummOfSets) {
	Set<int> A;
	A + 2;
	A + 3;
	Set<int> B;
	B + 7;
	A = A + B;
	ASSERT_EQ(7, A[2]);

	Set<double> C;
	C + 0.1;
	C + 0.5;
	Set<double> D;
	D + 1.1;
	C = C + D;
	ASSERT_EQ(1.1, C[2]);

	Set<std::string> E;
	E + "a";
	Set<std::string> F;
	F + "v";
	E = E + F;
	ASSERT_EQ("v", E[1]);
}

TEST(MySet, DifferenceOfSets) {
	Set<int> A;
	Set<int> B;
	A + 3;
	A + 5;
	B + 5;
	A = A - B;
	ASSERT_EQ(1, A.GetCardinality());


	Set<double> C;
	Set<double> D;
	C + 1.1;
	C + 1.2;
	D + 1.2;
	C = C - D;
	ASSERT_EQ(1, C.GetCardinality());

	Set<std::string> E;
	Set<std::string> F;
	E + "a";
	E + "b";
	F + "b";
	E = E - F;
	ASSERT_EQ(1, E.GetCardinality());
}

TEST(MySet, IntersectionSets) {
	Set<int> A;
	Set<int> B;
	A + 1;
	A + 2;
	B + 2;
	Set<int> C = A.IntersectionSets(B);
	ASSERT_EQ(1, C.GetCardinality());
	ASSERT_EQ(2, C[0]);

	Set<double> E;
	E + 1.1;
	E + 5.1;
	Set<double> F;
	F + 5.1;
	Set<double> T = E.IntersectionSets(F);
	ASSERT_EQ(1, T.GetCardinality());
	ASSERT_EQ(5.1, T[0]);

	Set<std::string> Z;
	Set<std::string> W;
	Z + "a";
	Z + "b";
	W + "a";
	Set<std::string> Y = Z.IntersectionSets(W);
	ASSERT_EQ(1, Y.GetCardinality());
	ASSERT_EQ("a", Y[0]);
}

TEST(MySet, AccessValue) {
	Set<int> A;
	A + 1;
	ASSERT_EQ(1, *A.Contain(1));

	Set<double> B;
	B + 1.1;
	ASSERT_EQ(1.1, *B.Contain(1.1));

	Set<std::string> C;
	C + "a";
	ASSERT_EQ("a", *C.Contain("a"));
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
	Set<int> A;
	A + 2;
	ASSERT_THROW(A +2, const char*);

	Set<double> B;
	B + 3.1;
	ASSERT_THROW(B + 3.1, const char*);

	Set<std::string> C;
	C + "a";
	ASSERT_THROW(C + "a", const char*);
}

TEST(MySet, ExceptionDifferenceSetWithNumber) {
	Set<int> A;
	A + 1;
	ASSERT_THROW(A - 7, const char*);

	Set<double> B;
	B + 1.1;
	ASSERT_THROW(B - 7.1, const char*);

	Set<std::string> C;
	C + "a";
	ASSERT_THROW(C - "f", const char*);
}

TEST(MySet, ExceptionAccessValue) {
	Set<int> A;
	A + 1;
	ASSERT_THROW(A.Contain(2), const char*);

	Set<double> B;
	B + 1.1;
	ASSERT_THROW(B.Contain(2.1), const char*);

	Set<std::string> C;
	C + "a";
	ASSERT_THROW(C.Contain("b"), const char*);
}