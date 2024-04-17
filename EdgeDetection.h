#pragma once
#include "Filter.h"

struct EdgeDetection : public Filter {
    Image Use(const Image&, const std::vector<std::string>) override;
    ~EdgeDetection() override = default;
};