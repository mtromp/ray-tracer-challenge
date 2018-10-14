#include "tuple.h"

//#include <QCoreApplication>

#include <iostream>

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

int main( int argc, char** argv )
{
    raytracer::vector gravity(0.0, -0.1, 0.0);
    raytracer::vector wind(-0.01, 0.0, 0.0);
    world aWorld(gravity, wind);
    raytracer::point position(0.0, 1.0, 0.0);
    raytracer::vector velocity(1.0, 1.0, 0.0);
    projectile aProjectile(position, velocity.normalize());

    int count = 0;
    std::cout << count
              << "  Position: "
              << aProjectile.position.getTuple().x << " "
              << aProjectile.position.getTuple().y << " "
              << aProjectile.position.getTuple().z
              << std::endl;
    std::cout << count
              << "  Velocity: "
              << aProjectile.velocity.getTuple().x << " "
              << aProjectile.velocity.getTuple().y << " "
              << aProjectile.velocity.getTuple().z
              << std::endl;

    while (aProjectile.position.getTuple().y > 0.0001)
    {
        count++;
        aProjectile = tick(aWorld, aProjectile);
        std::cout << count
                  << "  Position: "
                  << aProjectile.position.getTuple().x << " "
                  << aProjectile.position.getTuple().y << " "
                  << aProjectile.position.getTuple().z
                  << std::endl;
        std::cout << count
                  << "  Velocity: "
                  << aProjectile.velocity.getTuple().x << " "
                  << aProjectile.velocity.getTuple().y << " "
                  << aProjectile.velocity.getTuple().z
                  << std::endl;

        if (count > 20)
        {
            break;
        }
    }

    return 0;
}
