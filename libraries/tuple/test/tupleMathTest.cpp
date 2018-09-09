#include "tuple.h"
#include "point.h"
#include "vector.h"

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
