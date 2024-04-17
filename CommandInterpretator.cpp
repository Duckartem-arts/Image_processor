#include "CommandInterpretator.h"
#include "Negative.h"
#include "Grayscale.h"
#include "Sharpening.h"
#include "EdgeDetection.h"
#include "Crop.h"
#include <typeinfo>
#include <exception>

std::vector<std::pair<Filter*, std::vector<std::string>>> CommSep(int argc, char** argv) {
    std::vector<std::pair<Filter*, std::vector<std::string>>> comm_list;
    if (argc <= 2) {
        return comm_list;
    }
    for (int i = 3; i < argc; ++i) {
        std::string comm = argv[i];
        if (comm == "-neg") {
            Negative* ptr = new Negative;
            comm_list.push_back({ptr, {}});
        } else if (comm == "-gs") {
            Grayscale* ptr = new Grayscale;
            comm_list.push_back({ptr, {}});
        } else if (comm == "-sharp") {
            Sharpening* ptr = new Sharpening;
            comm_list.push_back({ptr, {}});
        } else if (comm == "-edge") {
            if (i + 1 >= argc) {
                throw std::runtime_error("No parameters given");
            }
            ++i;
            try {
                std::stod(argv[i]);
            } catch (std::exception& e) {
                throw std::runtime_error("Invalid parameter type");
            }
            EdgeDetection* ptr = new EdgeDetection;
            comm_list.push_back({ptr, {argv[i]}});
        } /* else if (comm == "-crop") {
            if (i + 2 >= argc) {
                throw std::runtime_error("Not enough parameters");
            }
            std::vector<std::string> par;
            ++i;
            par.push_back(argv[i]);
            ++i;
            par.push_back(argv[i]);
            try {
                std::stoi(par[0]);
                std::stoi(par[1]);
            } catch (std::exception& e) {
                throw std::runtime_error("Invalid parameters type");
            }
            Crop* ptr = new Crop;
            comm_list.push_back(std::make_pair(ptr, par));
        }
        */
    }
    return comm_list;
}
