#include "canvas.h"

#include <algorithm>
#include <sstream>

using namespace raytracer;

canvas::canvas(int width, int height) : width(width), height(height)
{
    this->canvasColors = new color*[this->width];
    for (int i=0; i<this->width; ++i)
    {
        this->canvasColors[i] = new color[this->height];
    }
}

int canvas::getWidth()
{
    return this->width;
}

int canvas::getHeight()
{
    return this->height;
}

raytracer::color canvas::getColor(int x, int y) const
{
    return this->canvasColors[x][y];
}
void canvas::setColor(int x, int y, color value)
{
    this->canvasColors[x][y] = value;
}

std::string canvas::writePpm() const
{
    std::ostringstream ppmData;
    ppmData << "P3" << std::endl;
    ppmData << this->width << " " << this->height << std::endl;
    ppmData << "255" << std::endl;

    int charCount = 0;
    bool newLine = true;
    int rgb[3];

    for (int row = 0; row < height; ++row)
    {
        for (int column = 0; column < width; ++column)
        {
            raytracer::color tmpColor = this->getColor(column, row);

            rgb[0] = std::clamp(static_cast<int>(tmpColor.getRed()*256.0), 0, 255);
            rgb[1] = std::clamp(static_cast<int>(tmpColor.getGreen()*256.0), 0, 255);
            rgb[2] = std::clamp(static_cast<int>(tmpColor.getBlue()*256.0), 0, 255);

            for (int k=0; k < 3; ++k)
            {
                if (! newLine)
                {
                    if (charCount < 66)
                    {
                        ppmData << " ";
                        ++charCount;
                    } else {
                        ppmData << std::endl;
                        newLine = true;
                        charCount = 0;
                    }
                }
                ppmData << rgb[k];
                charCount = charCount + 3;
                newLine = false;
            } // for k
        } // for column
        ppmData << std::endl;
        charCount = 0;
        newLine = true;
    } // for row

    return ppmData.str();
}

