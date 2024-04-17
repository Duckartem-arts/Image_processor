#include "InputOutput.h"

const int FILE_HEADER_SIZE = 14;
const int INFO_HEADER_SIZE = 40;

void Help() {
    std::cout << "No filters?" << std::endl;
    std::cout << "Commands           | Description" << std::endl;
    std::cout << "-neg               | Negative" << std::endl;
    std::cout << "-gs                | Grayscale" << std::endl;
    std::cout << "-crop width height | Cuts top left edge with given parameters" << std::endl;
    std::cout << "-sharp             | Sharpening" << std::endl;
    std::cout << "-edge threshold    | Edge detection" << std::endl;
}

Image Read(const std::string& path_in) {
    std::ifstream f;
    int file_width = 0;
    int file_height = 0;
    int padding = 0;
    unsigned char file_header[FILE_HEADER_SIZE];
    unsigned char info_header[INFO_HEADER_SIZE];
    f.open(path_in, std::ios::in | std::ios::binary);
    if (!f.is_open()) {
        throw std::runtime_error("Error: file not opened");
    }
    /*
    else {
        throw std::runtime_error("Error: file is opened");
    }*/
    f.read(reinterpret_cast<char*>(file_header), FILE_HEADER_SIZE);
    f.read(reinterpret_cast<char*>(info_header), INFO_HEADER_SIZE);

    if (file_header[0] != 'B' || file_header[1] != 'M' || file_header[10] != 54 ||  // DISABLE_NOLINT
        info_header[0] != 40 ||                                                     // DISABLE_NOLINT
        info_header[14] != 24) {                                                    // DISABLE_NOLINT
        throw std::runtime_error("Error: wrong file type");
    }
    file_width =
        info_header[4] + (info_header[5] << 8) + (info_header[6] << 16) + (info_header[7] << 24);  // DISABLE_NOLINT
    file_height =
        info_header[8] + (info_header[9] << 8) + (info_header[10] << 16) + (info_header[11] << 24);  // DISABLE_NOLINT
    padding = ((file_width * 3) % 4) % 4;

    Image image(file_width, file_height);

    for (int y = 0; y < file_height; ++y) {
        for (int x = 0; x < file_width; ++x) {
            unsigned char pix[3];
            f.read(reinterpret_cast<char*>(pix), 3);
            image.pix_matrix_[x][y].r = static_cast<double>(pix[2]) / 255.0;  // DISABLE_NOLINT
            image.pix_matrix_[x][y].g = static_cast<double>(pix[1]) / 255.0;  // DISABLE_NOLINT
            image.pix_matrix_[x][y].b = static_cast<double>(pix[0]) / 255.0;  // DISABLE_NOLINT
        }
        f.ignore(padding);
    }
    f.close();
    return image;
}

void Extract(const Image image, const std::string& path_out) {

    std::ofstream f;
    f.open(path_out, std::ios::out | std::ios::binary);
    if (!f.is_open()) {
        throw std::runtime_error("Error: file not extracted");
    }
    unsigned char file_header[FILE_HEADER_SIZE];
    unsigned char info_header[INFO_HEADER_SIZE];
    unsigned char bmp_pad[3] = {0, 0, 0};
    int padding = ((image.width_ * 3) % 4) % 4;
    int total_size = (image.width_ * 3 + padding) * image.height_ + FILE_HEADER_SIZE + INFO_HEADER_SIZE;
    file_header[0] = 'B';
    file_header[1] = 'M';

    file_header[2] = total_size;
    file_header[3] = total_size >> 8;   // DISABLE_NOLINT
    file_header[4] = total_size >> 16;  // DISABLE_NOLINT
    file_header[5] = total_size >> 24;  // DISABLE_NOLINT

    file_header[6] = 0;  // DISABLE_NOLINT
    file_header[7] = 0;  // DISABLE_NOLINT

    file_header[8] = 0;  // DISABLE_NOLINT
    file_header[9] = 0;  // DISABLE_NOLINT

    file_header[10] = 54;  // DISABLE_NOLINT
    file_header[11] = 0;   // DISABLE_NOLINT
    file_header[12] = 0;   // DISABLE_NOLINT
    file_header[13] = 0;   // DISABLE_NOLINT

    info_header[0] = 40;  // DISABLE_NOLINT
    info_header[1] = 0;
    info_header[2] = 0;
    info_header[3] = 0;

    info_header[4] = image.width_;
    info_header[5] = image.width_ >> 8;   // DISABLE_NOLINT
    info_header[6] = image.width_ >> 16;  // DISABLE_NOLINT
    info_header[7] = image.width_ >> 24;  // DISABLE_NOLINT

    info_header[8] = image.height_;         // DISABLE_NOLINT
    info_header[9] = image.height_ >> 8;    // DISABLE_NOLINT
    info_header[10] = image.height_ >> 16;  // DISABLE_NOLINT
    info_header[11] = image.height_ >> 24;  // DISABLE_NOLINT

    info_header[12] = 1;  // DISABLE_NOLINT
    info_header[13] = 0;  // DISABLE_NOLINT

    info_header[14] = 24;  // DISABLE_NOLINT
    info_header[15] = 0;   // DISABLE_NOLINT

    info_header[16] = 0;  // DISABLE_NOLINT
    info_header[17] = 0;  // DISABLE_NOLINT
    info_header[18] = 0;  // DISABLE_NOLINT
    info_header[19] = 0;  // DISABLE_NOLINT

    info_header[20] = 0;  // DISABLE_NOLINT
    info_header[21] = 0;  // DISABLE_NOLINT
    info_header[22] = 0;  // DISABLE_NOLINT
    info_header[23] = 0;  // DISABLE_NOLINT

    info_header[24] = 0;  // DISABLE_NOLINT
    info_header[25] = 0;  // DISABLE_NOLINT
    info_header[26] = 0;  // DISABLE_NOLINT
    info_header[27] = 0;  // DISABLE_NOLINT

    info_header[28] = 0;  // DISABLE_NOLINT
    info_header[29] = 0;  // DISABLE_NOLINT
    info_header[30] = 0;  // DISABLE_NOLINT
    info_header[31] = 0;  // DISABLE_NOLINT

    info_header[32] = 0;  // DISABLE_NOLINT
    info_header[33] = 0;  // DISABLE_NOLINT
    info_header[34] = 0;  // DISABLE_NOLINT
    info_header[35] = 0;  // DISABLE_NOLINT

    info_header[36] = 0;  // DISABLE_NOLINT
    info_header[37] = 0;  // DISABLE_NOLINT
    info_header[38] = 0;  // DISABLE_NOLINT
    info_header[39] = 0;  // DISABLE_NOLINT

    f.write(reinterpret_cast<char*>(file_header), FILE_HEADER_SIZE);
    f.write(reinterpret_cast<char*>(info_header), INFO_HEADER_SIZE);
    for (int y = 0; y < image.height_; ++y) {
        for (int x = 0; x < image.width_; ++x) {
            unsigned char r = static_cast<unsigned char>(image.pix_matrix_[x][y].r * 255.0);  // DISABLE_NOLINT
            unsigned char g = static_cast<unsigned char>(image.pix_matrix_[x][y].g * 255.0);  // DISABLE_NOLINT
            unsigned char b = static_cast<unsigned char>(image.pix_matrix_[x][y].b * 255.0);  // DISABLE_NOLINT

            unsigned char pix[3] = {b, g, r};
            f.write(reinterpret_cast<char*>(pix), 3);
        }
        f.write(reinterpret_cast<char*>(bmp_pad), padding);
    }
    f.close();
}