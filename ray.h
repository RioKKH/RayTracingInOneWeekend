#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray
{
    public:
        // constructor
        ray() {}
        ray(const point3 & origin, const vec3 & direction) : orig(origin), dir(direction) {}

        // member function --------------------------------
        // getter of orig
        point3 origin() const { return orig; }
        // getter of dir
        vec3 direction() const { return dir; }

        point3 at(double t) const
        {
            return orig + t * dir;
        }

    public:
        // member data ------------------------------------
        point3 orig;
        vec3 dir;
};

#endif


