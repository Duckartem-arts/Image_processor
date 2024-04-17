#include "image.h"
#include <stdexcept>

Image::Image(int width, int height) {
    width_ = (width);
    height_ = (height);

    pix_matrix_ = (std::vector<std::vector<Pixel>>(width, std::vector<Pixel>(height, {0, 0, 0})));
}
