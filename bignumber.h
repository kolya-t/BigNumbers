#ifndef BIGNUMBER_H
#define BIGNUMBER_H

#include <list.h>
#include <string>

typedef List<short> Lst;

class BigNumber {
public:
    BigNumber(int value = 0);
    BigNumber(std::string value);
    BigNumber(const BigNumber& orig);
public:
    BigNumber operator+(const BigNumber&);
    BigNumber& operator=(const BigNumber&);
    void print() const;
private:
    Lst _list;
    bool isDigit(char) const;
};

#endif // BIGNUMBER_H
