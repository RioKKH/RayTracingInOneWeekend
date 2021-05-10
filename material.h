#ifndef MATERIAL_H
#define MATERIAL_H

#include "rtweekend.h"

struct hit_record;

class material
{
    public:
        // const メンバー関数
        // 従って、インスタンスがconstになっていても呼び出すことが可能なメンバー関数である
        virtual bool scatter(
                const ray & r_in, const hit_record & rec, color & attenuation, ray & scattered
                ) const = 0;
};

#endif
