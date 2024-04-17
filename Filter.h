#pragma once
#include "image.h"
#include <string>

struct Filter {
    virtual Image Use(const Image&, const std::vector<std::string>) = 0;
    virtual ~Filter(){};
};
