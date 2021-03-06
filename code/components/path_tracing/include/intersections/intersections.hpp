#pragma once
#ifndef __INTERSECTIONS_HPP__
#define __INTERSECTIONS_HPP__

#include "HitRecord.hpp"
#include "Ray.hpp"
#include "scene/Bounds.hpp"
#include "scene/Scene.hpp"

namespace PathTracer {
namespace Intersection {
HitRecord xTriangle(const Ray& ray,
                    const Triangle& t,
                    float tMin = 0.f,
                    float tMax = FLOAT_INF);
HitRecord xSphere(const Ray& ray,
                  const Sphere& s,
                  float tMin = 0.f,
                  float tMax = FLOAT_INF);
HitRecord xPlane(const Ray& ray,
                 const Plane& p,
                 float tMin = 0.f,
                 float tMax = FLOAT_INF);
HitRecord xAreaLight(const Ray& ray,
                     const AreaLight& a,
                     float tMin = 0.f,
                     float tMax = FLOAT_INF);
HitRecord xMesh(const Ray& ray,
                const Mesh& a,
                float tMin = 0.f,
                float tMax = FLOAT_INF);
bool xBounds(const Ray& ray, const Bounds& b);
HitRecord closestHitObject(BVH* bvh, const Ray& ray);
}  // namespace Intersection
}  // namespace PathTracer

#endif