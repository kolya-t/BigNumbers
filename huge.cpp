#include "huge.h"
#include <string>

/* Конструктор по-умолчанию */
Huge::Huge() {
    list.push_back(0);
}

/* Формирования большого числа из строки.
 * TODO: Имеется следующий баг: если первая цифра
 * следующего разряда - 0, то она не записывается.
 * Исправить это в выводе */
Huge::Huge(std::string string) {
    int length = 0;
    num_type number = 0;

    for (char c : string) {
        if (isDigit(c)) {
            /* Если разряд уже содержит максимальное количество
             * цифр,тогда переходим к следующему разряду */
            if (length == MAX_DIGITS) {
                length = 0;
                list.push_front(number);
                number = 0;
            }

            // считываем очередную цифру разряда
            ++length;
            number = number * 10 + (c - '0');
        }
    }

    list.push_front(number);
}

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
