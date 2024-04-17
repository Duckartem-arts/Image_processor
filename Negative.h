#pragma once

#include "Filter.h"
struct Negative : public Filter {
    Image Use(const Image& image, std::vector<std::string>) override;
    ~Negative() override = default;
};