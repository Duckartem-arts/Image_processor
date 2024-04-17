#pragma once
#include <vector>

struct Pixel {
    double r, g, b;
    Pixel(){};
    Pixel(double r, double g, double b){};
};

struct Image {
    int width_;
    int height_;
    std::vector<std::vector<Pixel>> pix_matrix_;
    Image(){};
    Image(int, int);
};
