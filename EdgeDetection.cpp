#include "EdgeDetection.h"

Image EdgeDetection::Use(const Image& prom_image, const std::vector<std::string> par) {
    double threshold = std::stod(par[0]);  // DISABLE_NOLINT
    Image image(prom_image.width_, prom_image.height_);
    for (int y = 0; y < image.height_; ++y) {
        for (int x = 0; x < image.width_; ++x) {
            double k = 0.299 * prom_image.pix_matrix_[x][y].r +  // DISABLE_NOLINT
                       0.587 * prom_image.pix_matrix_[x][y].g +  // DISABLE_NOLINT
                       0.114 * prom_image.pix_matrix_[x][y].b;   // DISABLE_NOLINT
            image.pix_matrix_[x][y].r = k;
            image.pix_matrix_[x][y].g = k;
            image.pix_matrix_[x][y].b = k;
        }
    }
    Image new_image(image.width_, image.height_);
    for (int y = 0; y < new_image.height_; ++y) {
        for (int x = 0; x < new_image.width_; ++x) {
            double r = 0;
            if (x == 0) {
                if (y == 0) {
                    r = std::min(1.0, std::max(0.0, 2 * image.pix_matrix_[x][y].r - image.pix_matrix_[x + 1][y].r -
                                                        image.pix_matrix_[x][y + 1].r));
                } else if (y == new_image.height_ - 1) {
                    r = std::min(1.0, std::max(0.0, 2 * image.pix_matrix_[x][y].r - image.pix_matrix_[x + 1][y].r -
                                                        image.pix_matrix_[x][y - 1].r));
                } else {
                    r = std::min(1.0, std::max(0.0, 3 * image.pix_matrix_[x][y].r - image.pix_matrix_[x + 1][y].r -
                                                        image.pix_matrix_[x][y + 1].r - image.pix_matrix_[x][y - 1].r));
                }
            } else if (x == new_image.width_ - 1) {
                if (y == 0) {
                    r = std::min(1.0, std::max(0.0, 2 * image.pix_matrix_[x][y].r - image.pix_matrix_[x - 1][y].r -
                                                        image.pix_matrix_[x][y + 1].r));
                } else if (y == new_image.height_ - 1) {
                    r = std::min(1.0, std::max(0.0, 2 * image.pix_matrix_[x][y].r - image.pix_matrix_[x - 1][y].r -
                                                        image.pix_matrix_[x][y - 1].r));
                } else {
                    r = std::min(1.0, std::max(0.0, 3 * image.pix_matrix_[x][y].r - image.pix_matrix_[x - 1][y].r -
                                                        image.pix_matrix_[x][y + 1].r - image.pix_matrix_[x][y - 1].r));
                }
            } else {
                if (y == 0) {
                    r = std::min(1.0, std::max(0.0, 3 * image.pix_matrix_[x][y].r - image.pix_matrix_[x + 1][y].r -
                                                        image.pix_matrix_[x][y + 1].r - image.pix_matrix_[x - 1][y].r));
                } else if (y == new_image.height_ - 1) {
                    r = std::min(1.0, std::max(0.0, 3 * image.pix_matrix_[x][y].r - image.pix_matrix_[x + 1][y].r -
                                                        image.pix_matrix_[x][y - 1].r - image.pix_matrix_[x - 1][y].r));
                } else {
                    r = std::min(1.0, std::max(0.0, 4 * image.pix_matrix_[x][y].r -  // DISABLE_NOLINT
                                                        image.pix_matrix_[x + 1][y].r - image.pix_matrix_[x][y + 1].r -
                                                        image.pix_matrix_[x - 1][y].r - image.pix_matrix_[x][y - 1].r));
                }
            }
            if (r - threshold <= 0.0) {
                new_image.pix_matrix_[x][y].r = 0;
                new_image.pix_matrix_[x][y].g = 0;
                new_image.pix_matrix_[x][y].b = 0;
            } else {
                new_image.pix_matrix_[x][y].r = 1;
                new_image.pix_matrix_[x][y].g = 1;
                new_image.pix_matrix_[x][y].b = 1;
            }
        }
    }
    return new_image;
}