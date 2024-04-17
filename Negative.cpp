#include "Negative.h"

Image Negative::Use(const Image &image, std::vector<std::string> par) {
    Image new_image(image.width_, image.height_);
    for (int y = 0; y < new_image.height_; ++y) {
        for (int x = 0; x < new_image.width_; ++x) {
            new_image.pix_matrix_[x][y].r = 1.0 - image.pix_matrix_[x][y].r;
            new_image.pix_matrix_[x][y].g = 1.0 - image.pix_matrix_[x][y].g;
            new_image.pix_matrix_[x][y].b = 1.0 - image.pix_matrix_[x][y].b;
        }
    }
    return new_image;
}