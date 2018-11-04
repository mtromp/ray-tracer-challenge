#include "canvas.h"
#include "color.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <sstream>

using namespace testing;

class CanvasTest : public Test
{

protected:
    CanvasTest() : expectedWidth(10)
                 , expectedHeight(20)
                 , black(0.0, 0.0, 0.0)
                 , red(1.0, 0.0, 0.0)
                 , c(expectedWidth, expectedHeight)
    {
    }

    int expectedWidth, expectedHeight;
    raytracer::color black;
    raytracer::color red;
    raytracer::canvas c;
};

TEST_F(CanvasTest, SizeOfCanvasIsAsCreated)
{
    EXPECT_EQ(expectedWidth, c.getWidth());
    EXPECT_EQ(expectedHeight, c.getHeight());
}

TEST_F(CanvasTest, AllCanvasPointsAreBlack)
{
    for (int i=0; i<10;++i)
    {
        for(int j=0; j<20; ++j)
        {
            EXPECT_TRUE(black == c.getColor(i,j));
        }
    }
}

TEST_F(CanvasTest, SettingPixelToRedReturnsRedPixel)
{
    c.setColor(2, 3, red);
    EXPECT_TRUE(red == c.getColor(2,3));
}

TEST(CanvasPPMTest, PPMHeaderConsistsOf3Lines)
{
    raytracer::canvas c(5,3);
    std::string ppm = c.writePpm();
    std::istringstream strStream(ppm);
    std::string type;
    std::getline(strStream, type);
    std::string xAndY;
    std::getline(strStream, xAndY);
    std::string maxColor;
    std::getline(strStream, maxColor);

    EXPECT_EQ("P3", type);
    EXPECT_EQ("5 3", xAndY);
    EXPECT_EQ("255", maxColor);

}

TEST(CanvasPPMTest, DataRowsMatchExpected)
{
    raytracer::canvas c(5,3);
    raytracer::color c1(1.5, 0.0, 0.0);
    raytracer::color c2(0.0, 0.5, 0.0);
    raytracer::color c3(-0.5, 0.0, 1.0);
    c.setColor(0,0,c1);
    c.setColor(2,1, c2);
    c.setColor(4,2,c3);

    std::string row1, row2, row3;

    std::string ppm = c.writePpm();
    std::istringstream strStream(ppm);
    // Skip the header
    std::string header;

    for (int i = 0; i < 3; ++i)
    {
        std::getline(strStream, header);
    }
    std::getline(strStream, row1);
    std::getline(strStream, row2);
    std::getline(strStream, row3);

    EXPECT_EQ("255 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ", row1);
    EXPECT_EQ("0 0 0 0 0 0 0 128 0 0 0 0 0 0 0 ", row2);
    EXPECT_EQ("0 0 0 0 0 0 0 0 0 0 0 0 0 0 255 ", row3);

}
