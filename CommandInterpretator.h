#pragma once
#include "Filter.h"
#include <string>

std::vector<std::pair<Filter*, std::vector<std::string>>> CommSep(int argc, char** argv);
