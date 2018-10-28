#ifndef CANVAS_H
#define CANVAS_H

#include "color.h"

namespace raytracer {

class canvas
{
public:
    canvas(int width, int height);
    int getWidth();
    int getHeight();
    color getColor(int x, int y);

private:
    int width;
    int height;
    color **canvasColors;
};
}
#endif // CANVAS_H
