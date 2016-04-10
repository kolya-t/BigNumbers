#include "huge.h"
#include <string>

/* Конструктор по-умолчанию */
Huge::Huge() {
    list.push_back(0);
}

/* Формирование большого числа из строки */
Huge::Huge(const std::string& string) {
    int length = 0;
    num_type number = 0;

    /* разделение на подсписки по 9 цифр */
    List<std::string> stringList;
    std::string temp = "";
    for (char c : reverseString(string)) {
        if (isDigit(c)) {
            if (length == MAX_DIGITS) {
                stringList.push_back(reverseString(temp));
                length = 0;
                temp = "";
            }

            ++length;
            temp += c;
        }
    }
    if (temp != "") {
        stringList.push_back(reverseString(temp));
    }

    /* Формирование большого числа */
    auto iter = stringList.cbegin();
    do {
        for (char c : iter->value) {
            number = number * 10 + (c - '0');
        }
        list.push_back(number);
        number = 0;
        iter = iter->next;
    } while (iter != stringList.cbegin());

}

/* Копирования списка */
Huge::Huge(const List<num_type>& origList) : list(origList) {}

/* Конструктор копирования */
Huge::Huge(const Huge& orig) : list(orig.list) {}

/* Перегрузка оператора присваивания */
Huge& Huge::operator=(const Huge& other) {
    if (this != &other) {
        this->list = other.list;
    }
    return *this;
}

/* Проверка, является ли символ цифрой */
bool Huge::isDigit(char c) {
    return c >= '0' && c <= '9';
}

/* Возвращает длину числа */
short Huge::getLength(num_type number) {
    short length = 0;
    do {
        number /= 10;
        ++length;
    } while (number != 0);
    return length;
}

/* Возвращает строку из count нулей */
std::string Huge::zeros(short count) {
    std::string returnString = "";
    for (short i = 0; i < count; i++) {
        returnString += '0';
    }
    return returnString;
}

/* Реверсирование строки */
std::string Huge::reverseString(const std::string& src) {
    std::string reversedString;
    for (char c : src) {
        reversedString = c + reversedString;
    }
    return reversedString;
}

/* Возведение base в стпень p */
num_type Huge::pow(num_type base, short p) {
    num_type retValue = 1;
    for (int i = 0; i < p; i++) {
        retValue *= base;
    }
    return retValue;
}
