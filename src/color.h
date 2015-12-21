#pragma once

#include <global.h>

#include <Eigen/Core>

struct Color3f : public Eigen::Array3f {
public:
    typedef Eigen::Array3f Base;

    Color3f(float value = 0.f) : Base(value, value, value) {}
    Color3f(float r, float g, float b) : Base(r, g, b) {}

    template <typename Derived>
    Color3f(const Eigen::ArrayBase<Derived>& p) : Base(p) {}

    template <typename Derived>
    Color3f &operator=(const Eigen::ArrayBase<Derived>& p) {
        this->Base::operator=(p);
        return *this;
    }

    float &r() { return x(); }
    const float &r() const { return x(); }

    float &g() { return y(); }
    const float &g() const { return y(); }

    float &b() { return z(); }
    const float &b() const { return z(); }

    float getLuminance() const {
        return coeff(0) * 0.212671f + coeff(1) * 0.715160f + coeff(2) * 0.072169f;
    }

    std::string toString() const {
        std::ostringstream out;
        out << "[" << coeff(0) << ", " << coeff(1) << ", " << coeff(2) << "]";
        return out.str();
    }
};