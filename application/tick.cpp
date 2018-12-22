#include "tuple.h"
#include "canvas.h"

//#include <QCoreApplication>

#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

class world
{
public:
    world(raytracer::vector initGravity, raytracer::vector initWind):gravity(initGravity),wind(initWind)
    {
    }

    raytracer::vector gravity;
    raytracer::vector wind;
};

class projectile
{
public:
    projectile(raytracer::point initPosition, raytracer::vector initVelocity) :
                position(initPosition)
              , velocity(initVelocity)
    {}
    raytracer::point position;
    raytracer::vector velocity;
};

projectile tick( world w, projectile p)
{
    raytracer::point newPosition = p.position + p.velocity;
    raytracer::vector newVelocity = p.velocity + w.gravity + w.wind;
    return projectile(newPosition, newVelocity);
}

/*
 * The returned value must not be less than min
 * The returned value must not be more than max.
 *     scale is probably not the correct function name.
 */
int scale(float value, int min, int max)
{
    if ( value <= float(min))
    {
         return min;
    }
    if ( value >= float(max))
    {
         return max;
    }
    return std::roundl(value);
}

int main( int argc, char** argv )
{
    int canvasWidth = 900;
    int canvasHeight = 550;
    raytracer::vector gravity(0.0, -0.1, 0.0);
    raytracer::vector wind(-0.01, 0.0, 0.0);
    world aWorld(gravity, wind);

    raytracer::point position(0.0, 1.0, 0.0);
    raytracer::vector velocity(1.0, 1.8, 0.0);
    projectile aProjectile(position, velocity.normalize() * 11.25);

    raytracer::canvas theCanvas(canvasWidth, canvasHeight);
    raytracer::color red(1.0, 0.0, 0.0);

    int count = 0;

    int projectileXpoint = scale(aProjectile.position.getTuple().x, 0, canvasWidth - 1);
    int projectileYpoint = canvasHeight-1 - scale(aProjectile.position.getTuple().y, 0, canvasHeight - 1);
    theCanvas.setColor(projectileXpoint, projectileYpoint, red);

    while (aProjectile.position.getTuple().y > 0.0001)
    {
        count++;
        aProjectile = tick(aWorld, aProjectile);
        projectileXpoint = scale(aProjectile.position.getTuple().x, 0, canvasWidth - 1);
        projectileYpoint = canvasHeight-1 - scale(aProjectile.position.getTuple().y, 0, canvasHeight - 1);
        theCanvas.setColor(projectileXpoint, projectileYpoint, red);

        if (count > canvasWidth - 1)
        {
            break;
        }
    }
    std::cout << "ended loop at count: " << count << std::endl;

    //Write out the canvas to a file
    std::ofstream out("output.ppm");
    out << theCanvas.writePpm();
    out.close();

    return 0;
}
