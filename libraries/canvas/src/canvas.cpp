#include "canvas.h"

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

raytracer::color canvas::getColor(int x, int y)
{
    return this->canvasColors[x][y];
}
