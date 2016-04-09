#include "binary.h"

Binary::Binary() {
    list.push_back(0);
}

Binary::Binary(std::string str, Binary::Format format) {
    // задано число в двоичном формате
    if (format == Binary::Bin) {
        for (char c  : str) {
            if  (isBinaryDigit(c)) {
                list.push_front(c - '0');
            }
        }
    }

    // задано число в десятичном формате
    else if (format == Binary::Dec) {
        // !!!TODO!!!
    }

    // некорректные параметры
    if (list.empty()) {
        list.push_back(0);
    }
}

std::string Binary::decToBin(std::string src) {

}

bool Binary::isBinaryDigit(char c) {
    return c == '0' || c == '1';
}

