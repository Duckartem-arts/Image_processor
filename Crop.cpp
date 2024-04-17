#include "Crop.h"

Image Crop::Use(const Image& image, const std::vector<std::string> par) {
    int new_width = std::min(image.width_, std::stoi(par[0]));
    int new_height = std::min(image.height_, std::stoi(par[1]));
    Image new_image(new_width, new_height);
    for (int y = 0; y < new_height; ++y) {
        for (int x = 0; x < new_width; ++x) {
            new_image.pix_matrix_[x][y] = image.pix_matrix_[x][y + image.height_ - new_height];
        }
    }
    return new_image;
}
