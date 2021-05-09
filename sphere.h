#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vec3.h"

class sphere : public hittable
{
    public:
        sphere() {};
        sphere(point3 cen, double r) : center(cen), radius(r) {};

        // 派生クラスのでvirtual指定は本来は不要なはず
        // 特に下ではoverride指定子を使っているので、なぜvirutalを使っているのかが不明。
        // sphereも継承される可能性がある？
        virtual bool hit(
                const ray & r, double t_min, double t_max, hit_record & rec) const override;

    public:
        point3 center;
        double radius;
};

bool sphere::hit(const ray & r, double t_min, double t_max, hit_record & rec) const
{
    vec3 oc = r.origin() - center;
    auto a = r.direction().length_squared();
    auto half_b = dot(oc, r.direction());
    auto c = oc.length_squared() - radius*radius;

    auto discriminant = half_b*half_b - a*c;
    if (discriminant < 0) { return false; }
    auto sqrtd = sqrt(discriminant);

    // Find the nearest root that lies in the acceptable range.
    auto root = (-half_b - sqrtd) / a;
    if (root < t_min || t_max < root)
    {
        root = (-half_b + sqrtd) / a;
        if (root < t_min || t_max < root)
        {
            return false;
        }
    }

    rec.t = root;
    rec.p = r.at(rec.t);
    vec3 outward_normal = (rec.p - center) / radius;
    rec.set_face_normal(r, outward_normal);
    rec.normal = (rec.p - center) / radius;

    return true;
}

#endif
        
