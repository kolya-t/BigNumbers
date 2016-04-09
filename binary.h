#ifndef BINARY_H
#define BINARY_H

#include "list.h"
#include <string>

typedef List<bool> Lst;

using std::string;

class Binary {
public:
    enum Format {
        Bin,
        Dec
    };

    Binary();
    Binary(string str, Format format);

    static string decToBin(string);
private:
    Lst list;
    int length;
private:
    static bool isBinaryDigit(char c);
};

#endif // BINARY_H
