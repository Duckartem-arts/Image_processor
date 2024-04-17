#pragma once
#include "image.h"
#include <iostream>
#include <fstream>
#include <exception>

void Help();
Image Read(const std::string&);
void Extract(const Image, const std::string&);