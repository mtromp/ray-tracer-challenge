#include "tuple.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

TEST(TupleMath, AddPointTupleToVectorTuple)
{
    raytracer::tuple expected(1, 1, 6, 1);

    raytracer::tuple a1(3, -2, 5, 1);
    raytracer::tuple a2(-2, 3, 1, 0);

    EXPECT_TRUE(expected == (a1 + a2));
}

TEST(TupleMath, SubtractPointFromPointIsVector)
{
    raytracer::vector expected(-2.0, -4.0, -6.0);

    raytracer::point p1(3, 2, 1);
    raytracer::point p2(5, 6, 7);

    EXPECT_TRUE(expected == (p1 - p2));
}

TEST(TupleMath, SubtractVectorFromPointIsPoint)
{
    raytracer::point expected(-2.0, -4.0, -6.0);

    raytracer::vector v(5.0, 6.0, 7.0);
    raytracer::point p(3.0, 2.0, 1.0);

    EXPECT_TRUE(expected == (p - v));
}

TEST(TupleMath, AddVectorToPointIsPoint)
{
    raytracer::point expected(8.0, 8.0, 8.0);

    raytracer::vector v(5.0, 6.0, 7.0);
    raytracer::point p(3.0, 2.0, 1.0);

    EXPECT_TRUE(expected == (p + v));
}

TEST(TupleMath, SubtractVectorFromVectorIsVector)
{
    raytracer::vector expected(-2.0, -4.0, -6.0);

    raytracer::vector v1(3, 2, 1);
    raytracer::vector v2(5, 6, 7);

    EXPECT_TRUE(expected == (v1 - v2));
}

TEST(TupleMath, AddVectorToVectorIsVector)
{
    raytracer::vector expected(8.0, 8.0, 8.0);

    raytracer::vector v1(3, 2, 1);
    raytracer::vector v2(5, 6, 7);

    EXPECT_TRUE(expected == (v1 + v2));
}

TEST(TupleMath, SubtractVectorFromZeroIsNegativeVector)
{
    raytracer::vector expected(-1, 2, -3);

    raytracer::vector zero(0, 0, 0);
    raytracer::vector v(1, -2, 3);

    EXPECT_TRUE(expected == (zero - v));
}

TEST(TupleMath, NegateTuple)
{
    raytracer::tuple expected(-1, 2, -3, 4);
    raytracer::tuple a(1, -2, 3, -4);

    EXPECT_TRUE(expected == -a);
}

TEST(TupleMath, MultiplyTupleByScalar)
{
    raytracer::tuple expected(3.5, -7, 10.5, -14);

    raytracer::tuple a(1, -2, 3, -4);

    EXPECT_TRUE(expected == (a * 3.5));
}

TEST(TupleMath, MultiplyTupleByFraction)
{
    raytracer::tuple expected(0.5, -1, 1.5, -2);

    raytracer::tuple a(1, -2, 3, -4);

    EXPECT_TRUE(expected == (a * 0.5));
}

TEST(TupleMath, DivideTupleByScalar)
{
    raytracer::tuple expected(0.5, -1, 1.5, -2);

    raytracer::tuple a(1, -2, 3, -4);

    EXPECT_TRUE(expected == (a / 2.0));
}

TEST(VectorMath, MultipleVectorByScalar)
{
    float scalar = 2.0;

    raytracer::vector a(1.0, 2.0, 3.0);
    raytracer::vector expected(2.0, 4.0, 6.0);

    EXPECT_TRUE(expected == a * scalar);
}


TEST(VectorMath, DotProductResultsInScalar)
{
    float expected = 20.0;

    raytracer::vector a(1.0, 2.0, 3.0);
    raytracer::vector b(2.0, 3.0, 4.0);

    EXPECT_EQ(expected, a.dot(b));
}

TEST(VectorMath, CrossProductResultsInVector)
{
    raytracer::vector expected(-1.0, 2.0, -1.0);

    raytracer::vector a(1.0, 2.0, 3.0);
    raytracer::vector b(2.0, 3.0, 4.0);
    EXPECT_TRUE(expected == (a.cross(b)));
}

TEST(VectorMath, SwitchedCrossProductResultsInVector)
{
    raytracer::vector expected(1.0, -2.0, 1.0);

    raytracer::vector a(1.0, 2.0, 3.0);
    raytracer::vector b(2.0, 3.0, 4.0);
    EXPECT_TRUE(expected == (b.cross(a)));
}
