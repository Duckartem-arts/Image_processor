#pragma once
#include "Filter.h"

struct Grayscale : public Filter {
    Image Use(const Image&, const std::vector<std::string>) override;
    ~Grayscale() override = default;
};