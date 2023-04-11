#include <cmath>

const double pi = 3.14159265358979323846;
float lerp(float a, float b, float t) {
    return a + (b - a) * t;
}

float loop(float v, float a, float b) {
    float r = b - a;
    while (v < a) v += r;
    while (v >= b) v -= r;
    return v;
}

float clamp(float v, float a, float b) {
    return std::min(std::max(v, a), b);
}