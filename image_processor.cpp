#include "Filter.h"
#include "CommandInterpretator.h"
#include "InputOutput.h"

int main(int argc, char** argv) {
    std::vector<std::pair<Filter*, std::vector<std::string>>> comm_list;
    std::string path_in;
    std::string path_out;
    Image image;
    try {
        if (argc == 1) {
            Help();
            return 0;
        }
        if (argc == 2) {
            std::cout << "No output path";
        }
        comm_list = CommSep(argc, argv);
        path_in = argv[1];
        path_out = argv[2];
        image = Read(path_in);

        for (auto& command : comm_list) {
            image = command.first->Use(image, command.second);
            delete command.first;
        }
        Extract(image, path_out);
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        return 0;
    }
    return 0;
}