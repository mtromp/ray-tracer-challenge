#include "canvas.h"
#include "color.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

TEST(CanvasTest, SizeOfCanvasIsAsCreated)
{
    int expectedWidth = 10;
    int expectedHeight = 20;
    raytracer::canvas c(expectedWidth, expectedHeight);

    EXPECT_EQ(expectedWidth, c.getWidth());
    EXPECT_EQ(expectedHeight, c.getHeight());
}

TEST(CanvasTest, AllCanvasPointsAreBlack)
{
    raytracer::canvas c(10, 20);
    raytracer::color black(0.0, 0.0, 0.0);

    for (int i=0; i<10;++i)
    {
        for(int j=0; j<20; ++j)
        {
            EXPECT_TRUE(black == c.getColor(i,j));
        }
    }
}

