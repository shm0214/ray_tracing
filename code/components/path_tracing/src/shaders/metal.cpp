#include "shaders/metal.hpp"
#include "samplers/SamplerInstance.hpp"

#include "Onb.hpp"

namespace PathTracer {

metal::metal(Material& material, vector<Texture>& textures)
    : Shader(material, textures) {
    auto diffuseColor =
        material.getProperty<Property::Wrapper::RGBType>("diffuseColor");
    if (diffuseColor)
        albedo = (*diffuseColor).value;
    else
        albedo = {0.8, 0.8, 0.8};
}
Scattered metal::shade(const Ray& ray,
                            const Vec3& hitPoint,
                            const Vec3& normal) const {
    Vec3 origin = hitPoint;
    // if (normal == Vec3{0, 0, 1}) {
    //     direction = random;
    // }
    // else if (normal == Vec3{0, 0, -1}) {
    //     direction = -random;
    // }
    // else {
    //     Vec3 z{0, 0, 1};
    //     float angle = -acos(glm::dot(z, normal));
    //     Vec3 axis =  glm::cross(normal, z);
    //     Mat4x4 rotate = glm::rotate(Mat4x4{1}, angle, axis);
    //     direction = rotate*Vec4{random, 1};
    // }
    // direction = glm::normalize(direction);

   /* Onb onb{normal};
    Vec3 direction = glm::normalize(onb.local(random));*/
    //������ߵķ������������߷���+2b
    Vec3 direction = ray.direction - 2*glm::dot(ray.direction, normal)*normal;
    float pdf = 1 / (2 * PI);
    auto attenuation = albedo / PI;
    return {Ray{origin, direction}, attenuation, Vec3{0}, pdf};
}
Vec3 metal::eval(const Vec3& in,
                      const Vec3& out,
                      const Vec3& normal) const {
    float cos = glm::dot(normal, out);
    if (cos > 0.0f)
        return albedo / PI;
    else
        return {};
}
}