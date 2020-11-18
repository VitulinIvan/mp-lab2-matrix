#include "Matrix.h"

#include <gtest.h>
#include <sstream>

TEST(TMatrix, create_matrix)
{
	TMatrix<int> M(3);
	EXPECT_NO_THROW();
}

TEST(TMatrix, create_matrix_throw)
{
	EXPECT_ANY_THROW(TMatrix<int> M(-3););
}

TEST(TMatrix, bool_operator_equation_true)
{
	stringstream s1("1 2 3 4 5 6 7 8 9");
	stringstream s2("1 2 3 4 5 6 7 8 9");
	TMatrix<int> M1(3);
	TMatrix<int> M2(3);
	s1 >> M1;
	s2 >> M2;
	EXPECT_EQ(true, M1 == M2);
}

TEST(TMatrix, bool_operator_equation_false)
{
	stringstream s1("1 2 3 4 5 6 7 8 9");
	stringstream s2("-1 2 -3 4 -5 6 -7 8 -9");
	TMatrix<int> M1(3);
	TMatrix<int> M2(3);
	s1 >> M1;
	s2 >> M2;
	EXPECT_EQ(false, M1 == M2);
}

TEST(TMatrix, bool_operator_non_equation_true)
{
	stringstream s1("1 2 3 4 5 6 7 8 9");
	stringstream s2("-1 -2 -3 -4 -5 -6 -7 -8 -9");
	TMatrix<int> M1(3);
	TMatrix<int> M2(3);
	s1 >> M1;
	s2 >> M2;
	EXPECT_EQ(true, M1 != M2);
}

TEST(TMatrix, bool_operator_non_equation_false)
{
	stringstream s1("1 2 3 4 5 6 7 8 9");
	stringstream s2("1 2 3 4 5 6 7 8 9");
	TMatrix<int> M1(3);
	TMatrix<int> M2(3);
	s1 >> M1;
	s2 >> M2;
	EXPECT_EQ(false, M1 != M2);
}

TEST(TMatrix, operator_assignment)
{
	stringstream s1("1 2 3 4 5 6 7 8 9");
	TMatrix<int> M1(3);
	s1 >> M1;
	TMatrix<int> M2(3);
	M2 = M1;
	EXPECT_EQ(true, M1 == M2);
}

TEST(TMatrix, operator_assignment_with_different_size)
{
	stringstream s1("1 2 3 4 5 6 7 8 9");
	TMatrix<int> M1(3);
	s1 >> M1;
	TMatrix<int> M2(5);
	M2 = M1;
	EXPECT_EQ(true, M1 == M2);
}

TEST(TMatrix, operator_addition)
{
	stringstream s1("1 2 3 4 5 6 7 8 9");
	stringstream s2("9 8 7 6 5 4 3 2 1");
	stringstream s3("10 10 10 10 10 10 10 10 10");
	TMatrix<int> M1(3), M2(3), M3(3);
	s1 >> M1;
	s2 >> M2;
	s3 >> M3;
	M1 = M1 + M2;
	EXPECT_EQ(true, M3 == M1);
}

TEST(TMatrix, operator_subtraction)
{
	stringstream s1("1 2 3 4 5 6 7 8 9");
	stringstream s2("9 8 7 6 5 4 3 2 1");
	stringstream s3("8 6 4 2 0 -2 -4 -6 -8");
	TMatrix<int> M1(3), M2(3), M3(3);
	s1 >> M1;	
	s2 >> M2;	
	s3 >> M3;	
	M1 = M2 - M1;
	EXPECT_EQ(true, M3 == M1);
}

TEST(TMatrix, operator_multiplication)
{
	stringstream s1("-1 2 3 4 -5 6 7 8 -9");
	stringstream s2("9 -8 7 6 -5 4 3 -2 1");
	stringstream s3("12 -8 4 24 -19 14 84 -78 72");
	TMatrix<int> M1(3), M2(3), M3(3);
	s1 >> M1;
	s2 >> M2;
	s3 >> M3;
	M1 = M1 * M2;
	EXPECT_EQ(true, M3 == M1);
}

TEST(TMatrix, operator_multiplication_throw_different_size)
{
	stringstream s1("-1 2 3 4 -5 6 7 8 -9");
	stringstream s2("9 -8 7 6 -5 4 3 -2 1 32 15 65 85 0 3 5");
	TMatrix<int> M1(3), M2(4);
	s1 >> M1;
	s2 >> M2;
	EXPECT_ANY_THROW(M1 = M1 * M2;);
}

TEST(TMatrix, read_from_file)
{
	stringstream s1("1 2 3 4 4 5 6 4 7 8 9 4 4 4 4 4");
	TMatrix<int> M1(4), M2(0);
	s1 >> M1;
	M2.read_from_file();
	EXPECT_EQ(true, M1 == M2);
}

TEST(TMatrix, save_to_file)
{
	stringstream s1("1 2 3 4 4 5 6 4 7 8 9 4 0 0 0 0");
	TMatrix<int> M1(4);
	s1 >> M1;
	M1.save_to_file();
	EXPECT_NO_THROW();
}

