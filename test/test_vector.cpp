#include "Vector.h"

#include <gtest.h>


TEST(TVector, create_vector)
{
	TVector<int> V(5, 0);
	EXPECT_NO_THROW();
}

TEST(TVector, create_vector_throw_size)
{
	EXPECT_ANY_THROW(TVector<int> V(-10, 0););
}

TEST(TVector, create_vector_throw_start_index)
{
	EXPECT_ANY_THROW(TVector<int> V(0, -10););
}

TEST(TVector, can_get_value_by_operation_square_brackets)
{
	TVector<int> V1(5, 0);
	for (int i = 0; i < 5; i++)
		V1[i] = i;
	EXPECT_EQ(4, V1[4]);
}

TEST(TVector, can_get_value_by_operation_square_brackets_throw_bigger_than_size)
{
	TVector<int> V1(5, 0);
	for (int i = 0; i < 5; i++)
		V1[i] = i;
	EXPECT_ANY_THROW(V1[6];);
}

TEST(TVector, can_get_value_by_operation_square_brackets_throw_negative_index)
{
	TVector<int> V1(5, 0);
	for (int i = 0; i < 5; i++)
		V1[i] = i;
	EXPECT_ANY_THROW(V1[-1];);
}

TEST(TVector, can_get_value_on_pos)
{
	TVector<int> V1(5, 0);
	for (int i = 0; i < 5; i++)
		V1[i] = i;
	EXPECT_EQ(2,V1.GetValue(2));
}

TEST(TVector, can_get_value_on_pos_throw_bigger_than_size)
{
	TVector<int> V1(5, 0);
	for (int i = 0; i < 5; i++)
		V1[i] = i;
	EXPECT_ANY_THROW(V1.GetValue(6););
}

TEST(TVector, can_get_value_on_pos_throw_negative_index)
{
	TVector<int> V1(5, 0);
	for (int i = 0; i < 5; i++)
		V1[i] = i;
	EXPECT_ANY_THROW(V1.GetValue(-1););
}

TEST(TVector, bool_operator_equation_true)
{
	TVector<int> V1(5, 0);
	for (int i = 0; i < 5; i++)
		V1[i] = i;
	TVector<int> V2(5, 0);
	for (int i = 0; i < 5; i++)
		V2[i] = i;
	EXPECT_EQ(true, V1 == V2);
}

TEST(TVector, bool_operator_equation_false)
{
	TVector<int> V1(5, 0);
	for (int i = 0; i < 5; i++)
		V1[i] = i;
	TVector<int> V2(5, 0);
	for (int i = 0; i < 5; i++)
		V2[i] = i + 1;
	EXPECT_EQ(false, V1 == V2);
}

TEST(TVector, bool_operator_non_equation_true)
{
	
	TVector<int> V1(5, 0);
	for (int i = 0; i < 5; i++)
		V1[i] = i;
	TVector<int> V2(5, 0);
	for (int i = 0; i < 5; i++)
		V2[i] = i+1;
	
	EXPECT_EQ(true, V1 != V2);
}

TEST(TVector, bool_operator_non_equation_false)
{

	TVector<int> V1(5, 0);
	for (int i = 0; i < 5; i++)
		V1[i] = i;
	TVector<int> V2(5, 0);
	for (int i = 0; i < 5; i++)
		V2[i] = i;

	EXPECT_EQ(false, V1 != V2);
}

TEST(TVector, operator_assignments)
{
	TVector<int> V1(5, 0);
	for (int i = 0; i < 5; i++)
		V1[i] = i;
	TVector<int> V2(5, 0);
	TVector<int> V3(5, 0);
	for (int i = 0; i < 5; i++)
		V3[i] = i;
	V2 = V1;
	EXPECT_EQ(true, V2==V3);
}

TEST(TVector, operator_assignments_with_different_size)
{
	TVector<int> V1(5, 0);
	for (int i = 0; i < 5; i++)
		V1[i] = i;
	TVector<int> V2(3, 0);
	TVector<int> V3(5, 0);
	for (int i = 0; i < 5; i++)
		V3[i] = i;
	V2 = V1;
	EXPECT_EQ(true, V2 == V3);
}

TEST(TVector, operator_addition_value)
{
	TVector<int> V1(7, 0);
	for (int i = 0; i < 7; i++)
		V1[i] = i;
	TVector<int> V2(7, 0);
	for (int i = 0; i < 7; i++)
		V2[i] = i + 3;
	V1 = V1 + 3;
	EXPECT_EQ(true, V1 == V2);
}

TEST(TVector, operator_addition_other_vector)
{
	int k = 0;
	TVector<int> V1(4, 0);
	for (int i = 0; i < 4; i++)
		V1[i] = i;
	TVector<int> V2(4, 0);
	for (int i = 0; i < 4; i++)
		V2[i] = i + 2;
	TVector<int> V3(4, 0);
	for (int i = 0; i < 4; i++)
	{
		k = k + 2;
		V3[i] = k;
	}
	V1 = V1 + V2;
	EXPECT_EQ(true, V3 == V1);
}

TEST(TVector, operator_addition_other_vector_throw_different_sizes)
{
	int k = 0;
	TVector<int> V1(4, 0);
	for (int i = 0; i < 4; i++)
		V1[i] = i;
	TVector<int> V2(7, 0);
	for (int i = 0; i < 7; i++)
		V2[i] = i + 2;
	EXPECT_ANY_THROW(V1 = V1 + V2;);
}

TEST(TVector, operator_subtraction_value)
{
	TVector<int> V1(7, 0);
	for (int i = 0; i < 7; i++)
		V1[i] = i;
	TVector<int> V2(7, 0);
	for (int i = 0; i < 7; i++)
		V2[i] = i - 5;
	V1 = V1 - 5;
	EXPECT_EQ(true, V1 == V2);
}

TEST(TVector, operator_subtraction_other_vector)
{
	int k = 0;
	TVector<int> V1(4, 0);
	for (int i = 0; i < 4; i++)
		V1[i] = i;
	TVector<int> V2(4, 0);
	for (int i = 0; i < 4; i++)
		V2[i] = i - 2;
	TVector<int> V3(4, 0);
	for (int i = 0; i < 4; i++)
		V3[i] = 2;
	V1 = V1 - V2;
	EXPECT_EQ(true, V3 == V1);
}

TEST(TVector, operator_subtraction_other_vector_throw_different_sizes)
{
	int k = 0;
	TVector<int> V1(4, 0);
	for (int i = 0; i < 4; i++)
		V1[i] = i;
	TVector<int> V2(7, 0);
	for (int i = 0; i < 7; i++)
		V2[i] = i - 2;
	EXPECT_ANY_THROW(V1 = V1 + V2;);
}

TEST(TVector, operator_multiplication_value)
{
	TVector<int> V1(7, 0);
	for (int i = 0; i < 7; i++)
		V1[i] = i;
	TVector<int> V2(7, 0);
	for (int i = 0; i < 7; i++)
		V2[i] = i * 4;
	V1 = V1 * 4;
	EXPECT_EQ(true, V1 == V2);
}

TEST(TVector, operator_multiplication_negative_value)
{
	TVector<int> V1(7, 0);
	for (int i = 0; i < 7; i++)
		V1[i] = i;
	TVector<int> V2(7, 0);
	for (int i = 0; i < 7; i++)
		V2[i] = i * (-4);
	V1 = V1 * (-4);
	EXPECT_EQ(true, V1 == V2);
}

TEST(TVector, operator_multiplication_other_vector)
{
	int k = 0;
	TVector<int> V1(4, 0);
	for (int i = 0; i < 4; i++)
		V1[i] = i;
	TVector<int> V2(4, 0);
	for (int i = 0; i < 4; i++)
		V2[i] = i + 2;
	TVector<int> V3(4, 0);
	V3[0] = 0;
	V3[1] = 3;
	V3[2] = 8;
	V3[3] = 15;
	V1 = V1 * V2;
	EXPECT_EQ(true, V3 == V1);
}

TEST(TVector, operator_multiplication_other_negative_vector)
{
	int k = 0;
	TVector<int> V1(4, 0);
	for (int i = 0; i < 4; i++)
		V1[i] = i;
	TVector<int> V2(4, 0);
	for (int i = 0; i < 4; i++)
		V2[i] = i *(-1);
	TVector<int> V3(4, 0);
	V3[0] = 0;
	V3[1] = -1;
	V3[2] = -4;
	V3[3] = -9;
	V1 = V1 * V2;
	EXPECT_EQ(true, V3 == V1);
}

TEST(TVector, operator_multiplication_other_vector_throw_different_sizes)
{
	int k = 0;
	TVector<int> V1(4, 0);
	for (int i = 0; i < 4; i++)
		V1[i] = i;
	TVector<int> V2(7, 0);
	for (int i = 0; i < 7; i++)
		V2[i] = i + 2;
	EXPECT_ANY_THROW(V1 = V1 * V2;);
}