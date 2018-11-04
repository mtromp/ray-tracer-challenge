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

    for (int row = 0; row < height; ++row)
    {
        for (int column = 0; column < width; ++column)
        {
            raytracer::color tmpColor = this->getColor(column, row);
            int red = std::clamp(static_cast<int>(tmpColor.getRed()*256.0), 0, 255);
            int green = std::clamp(static_cast<int>(tmpColor.getGreen()*256.0), 0, 255);
            int blue = std::clamp(static_cast<int>(tmpColor.getBlue()*256.0), 0, 255);

            ppmData << red << " " << green << " " << blue << " ";
        }
        ppmData << std::endl;
    }

    return ppmData.str();
}

