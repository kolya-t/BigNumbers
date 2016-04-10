#include "bignumber.h"

// конструктор большого числа из числа int
BigNumber::BigNumber(int value) {
    do {
        _list.push_back(value % 10);
        value /= 10;
    } while (value != 0);
}

// конструктор большого числа из строки
BigNumber::BigNumber(std::string string) {
    for (char c : string) {
        if (isDigit(c)) {
            _list.push_front(c - '0');
        }
    }

    if (_list.empty()) {
        _list.push_back(0);
    }
}

BigNumber::BigNumber(const BigNumber& orig) : _list(orig._list) {}

// сложение больших чисел
BigNumber BigNumber::operator+(const BigNumber& num2) {
    BigNumber retNumber;
    Lst retList;

    // итератор первого слагаемого
    auto itr1 = this->_list.cbegin();
    // достигнут ли конец первого слагаемого
    bool isEnd1 = this->_list.empty();
    // итератор второго слагаемого
    auto itr2 = num2._list.cbegin();
    // достигнут ли конец второго слагаемого
    bool isEnd2 = num2._list.empty();

    char overflow = 0;
    // пока не достигнут конец хотя бы одного числа
    while (!(isEnd1 || isEnd2)) {
        /* складываем два разряда и переполнение
         * из суммы прошлых разрядов */
        short temp = itr1->value + itr2->value + overflow;
        // находим переполнение для следубщей суммы
        overflow = temp / 10;
        // получаем результат суммы разрядов без переполнения
        temp = temp % 10;
        // добавялем сумму разрядов в список
        retList.push_back(temp);

        /* Переходим к следующему разряду, проверяя,
         * закончилось ли число */
        itr1 = itr1->next;
        if (itr1 == this->_list.cbegin()) {
            isEnd1 = true;
        }
        itr2 = itr2->next;
        if (itr2 == num2._list.cbegin()) {
            isEnd2 = true;
        }
    }
    /* После того, как мы достигли конца одного числа, нужно
     * проверить, достигнут ли конец другого числа, так как
     * слагаемые могут быть разной длины. Если конец не был
     * достигнут, тогда добавляем непройденную часть числа
     * в начало результата, учитывая переполнение */
    if (!isEnd1) {
        while (itr1 != this->_list.cbegin()) {
            short temp = itr1->value + overflow;
            overflow = temp / 10;
            temp = temp % 10;
            retList.push_back(temp);

            itr1 = itr1->next;
        }
    } else if (!isEnd2) {
        while (itr2 != num2._list.cbegin()) {
            short temp = itr2->value + overflow;
            overflow = temp / 10;
            temp = temp % 10;
            retList.push_back(temp);

            itr2 = itr2->next;
        }
    }

    if (overflow) {
        retList.push_back(overflow);
    }


    retNumber._list = retList;
    return retNumber;
}

BigNumber& BigNumber::operator=(const BigNumber& num2) {
    this->_list = num2._list;
    return *this;
}

void BigNumber::print() const {
    // создание списка
    Lst listToPrint;
    const Lst::Node* iterator = _list.cbegin();
    do {
        listToPrint.push_front(iterator->value);
        iterator = iterator->next;
    } while (iterator != _list.cbegin());

    //распечатка
    iterator = listToPrint.cbegin();
    do {
        cout << iterator->value;
        iterator = iterator->next;
    } while (iterator != listToPrint.cbegin());
}

bool BigNumber::isDigit(char c) const {
    return c >= '0' && c <= '9';
}


