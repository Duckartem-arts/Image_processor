#include "Grayscale.h"

Image Grayscale::Use(const Image& image, const std::vector<std::string> par) {
    Image new_image(image.width_, image.height_);
    for (int y = 0; y < new_image.height_; ++y) {
        for (int x = 0; x < new_image.width_; ++x) {
            double k = 0.299 * image.pix_matrix_[x][y].r + 0.587 * image.pix_matrix_[x][y].g +  // DISABLE_NOLINT
                       0.114 * image.pix_matrix_[x][y].b;                                       // DISABLE_NOLINT
            new_image.pix_matrix_[x][y].r = k;
            new_image.pix_matrix_[x][y].g = k;
            new_image.pix_matrix_[x][y].b = k;
        }
    }
    return new_image;
}
