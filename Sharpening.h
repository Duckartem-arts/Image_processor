#pragma once

#include "Filter.h"
#include <algorithm>

struct Sharpening : public Filter {
    Image Use(const Image&, const std::vector<std::string>) override;
    ~Sharpening() override = default;
};