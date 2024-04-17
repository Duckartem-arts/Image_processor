#pragma once
#include "Filter.h"
#include <algorithm>

struct Crop : public Filter {
    Image Use(const Image&, const std::vector<std::string>) override;
    ~Crop() override = default;
};