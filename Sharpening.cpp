#include "Sharpening.h"

Image Sharpening::Use(const Image& image, const std::vector<std::string> par) {
    Image new_image(image.width_, image.height_);
    for (int y = 0; y < new_image.height_; ++y) {
        for (int x = 0; x < new_image.width_; ++x) {
            double r = 0;
            double g = 0;
            double b = 0;
            if (x == 0) {
                if (y == 0) {
                    r = std::min(1.0, std::max(0.0, 3 * image.pix_matrix_[x][y].r - image.pix_matrix_[x + 1][y].r -
                                                        image.pix_matrix_[x][y + 1].r));
                    g = std::min(1.0, std::max(0.0, 3 * image.pix_matrix_[x][y].g - image.pix_matrix_[x + 1][y].g -
                                                        image.pix_matrix_[x][y + 1].g));
                    b = std::min(1.0, std::max(0.0, 3 * image.pix_matrix_[x][y].b - image.pix_matrix_[x + 1][y].b -
                                                        image.pix_matrix_[x][y + 1].b));
                } else if (y == new_image.height_ - 1) {
                    r = std::min(1.0, std::max(0.0, 3 * image.pix_matrix_[x][y].r - image.pix_matrix_[x + 1][y].r -
                                                        image.pix_matrix_[x][y - 1].r));
                    g = std::min(1.0, std::max(0.0, 3 * image.pix_matrix_[x][y].g - image.pix_matrix_[x + 1][y].g -
                                                        image.pix_matrix_[x][y - 1].g));
                    b = std::min(1.0, std::max(0.0, 3 * image.pix_matrix_[x][y].b - image.pix_matrix_[x + 1][y].b -
                                                        image.pix_matrix_[x][y - 1].b));
                } else {
                    r = std::min(1.0, std::max(0.0, 4 * image.pix_matrix_[x][y].r - image.pix_matrix_[x + 1][y].r -
                                                        image.pix_matrix_[x][y + 1].r - image.pix_matrix_[x][y - 1].r));
                    g = std::min(1.0, std::max(0.0, 4 * image.pix_matrix_[x][y].g - image.pix_matrix_[x + 1][y].g -
                                                        image.pix_matrix_[x][y + 1].g - image.pix_matrix_[x][y - 1].g));
                    b = std::min(1.0, std::max(0.0, 4 * image.pix_matrix_[x][y].b - image.pix_matrix_[x + 1][y].b -
                                                        image.pix_matrix_[x][y + 1].b - image.pix_matrix_[x][y - 1].b));
                }
            } else if (x == new_image.width_ - 1) {
                if (y == 0) {
                    r = std::min(1.0, std::max(0.0, 3 * image.pix_matrix_[x][y].r - image.pix_matrix_[x - 1][y].r -
                                                        image.pix_matrix_[x][y + 1].r));
                    g = std::min(1.0, std::max(0.0, 3 * image.pix_matrix_[x][y].g - image.pix_matrix_[x - 1][y].g -
                                                        image.pix_matrix_[x][y + 1].g));
                    b = std::min(1.0, std::max(0.0, 3 * image.pix_matrix_[x][y].b - image.pix_matrix_[x - 1][y].b -
                                                        image.pix_matrix_[x][y + 1].b));
                } else if (y == new_image.height_ - 1) {
                    r = std::min(1.0, std::max(0.0, 3 * image.pix_matrix_[x][y].r - image.pix_matrix_[x - 1][y].r -
                                                        image.pix_matrix_[x][y - 1].r));
                    g = std::min(1.0, std::max(0.0, 3 * image.pix_matrix_[x][y].g - image.pix_matrix_[x - 1][y].g -
                                                        image.pix_matrix_[x][y - 1].g));
                    b = std::min(1.0, std::max(0.0, 3 * image.pix_matrix_[x][y].b - image.pix_matrix_[x - 1][y].b -
                                                        image.pix_matrix_[x][y - 1].b));
                } else {
                    r = std::min(1.0, std::max(0.0, 4 * image.pix_matrix_[x][y].r - image.pix_matrix_[x - 1][y].r -
                                                        image.pix_matrix_[x][y + 1].r - image.pix_matrix_[x][y - 1].r));
                    g = std::min(1.0, std::max(0.0, 4 * image.pix_matrix_[x][y].g - image.pix_matrix_[x - 1][y].g -
                                                        image.pix_matrix_[x][y + 1].g - image.pix_matrix_[x][y - 1].g));
                    b = std::min(1.0, std::max(0.0, 4 * image.pix_matrix_[x][y].b - image.pix_matrix_[x - 1][y].b -
                                                        image.pix_matrix_[x][y + 1].b - image.pix_matrix_[x][y - 1].b));
                }
            } else {
                if (y == 0) {
                    r = std::min(1.0, std::max(0.0, 4 * image.pix_matrix_[x][y].r - image.pix_matrix_[x + 1][y].r -
                                                        image.pix_matrix_[x][y + 1].r - image.pix_matrix_[x - 1][y].r));
                    g = std::min(1.0, std::max(0.0, 4 * image.pix_matrix_[x][y].g - image.pix_matrix_[x + 1][y].g -
                                                        image.pix_matrix_[x][y + 1].g - image.pix_matrix_[x - 1][y].g));
                    b = std::min(1.0, std::max(0.0, 4 * image.pix_matrix_[x][y].b - image.pix_matrix_[x + 1][y].b -
                                                        image.pix_matrix_[x][y + 1].b - image.pix_matrix_[x - 1][y].b));
                } else if (y == new_image.height_ - 1) {
                    r = std::min(1.0, std::max(0.0, 4 * image.pix_matrix_[x][y].r - image.pix_matrix_[x + 1][y].r -
                                                        image.pix_matrix_[x][y - 1].r - image.pix_matrix_[x - 1][y].r));
                    g = std::min(1.0, std::max(0.0, 4 * image.pix_matrix_[x][y].g - image.pix_matrix_[x + 1][y].g -
                                                        image.pix_matrix_[x][y - 1].g - image.pix_matrix_[x - 1][y].g));
                    b = std::min(1.0, std::max(0.0, 4 * image.pix_matrix_[x][y].b - image.pix_matrix_[x + 1][y].b -
                                                        image.pix_matrix_[x][y - 1].b - image.pix_matrix_[x - 1][y].b));
                } else {
                    r = std::min(1.0, std::max(0.0, 5 * image.pix_matrix_[x][y].r -  // DISABLE_NOLINT
                                                        image.pix_matrix_[x + 1][y].r - image.pix_matrix_[x][y + 1].r -
                                                        image.pix_matrix_[x - 1][y].r - image.pix_matrix_[x][y - 1].r));
                    g = std::min(1.0, std::max(0.0, 5 * image.pix_matrix_[x][y].g -  // DISABLE_NOLINT
                                                        image.pix_matrix_[x + 1][y].g - image.pix_matrix_[x][y + 1].g -
                                                        image.pix_matrix_[x - 1][y].g - image.pix_matrix_[x][y - 1].g));
                    b = std::min(1.0, std::max(0.0, 5 * image.pix_matrix_[x][y].b -  // DISABLE_NOLINT
                                                        image.pix_matrix_[x + 1][y].b - image.pix_matrix_[x][y + 1].b -
                                                        image.pix_matrix_[x - 1][y].b - image.pix_matrix_[x][y - 1].b));
                }
            }
            new_image.pix_matrix_[x][y].r = r;
            new_image.pix_matrix_[x][y].g = g;
            new_image.pix_matrix_[x][y].b = b;
        }
    }
    return new_image;
}
