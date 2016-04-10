#ifndef HUGE_H
#define HUGE_H

#include <stdint.h>
#include "list.h"
#include <iostream>

#define MAX_DIGITS 9
typedef uint32_t num_type;


class Huge {
public:
    Huge();
    Huge(std::string);
    Huge(const Huge&);

    /* TODO: Исправить вывод нулей перед разрядом */
    // Вывод большого числа
    friend inline std::ostream& operator<<(std::ostream& os, const Huge& obj) {
        List<num_type> reverse_list;

        // формирование реверсированного списка
        auto iterator = obj.list.cbegin();
        do {
            reverse_list.push_front(iterator->value);
            iterator = iterator->next;
        } while (iterator != obj.list.cbegin());

        /* распечатка реверсированного списка */
        // первый разряд
        iterator = reverse_list.cbegin();
        os << iterator->value;

        // остальные разряды
        iterator = iterator->next;
        while (iterator != reverse_list.cbegin()) {
            // добавляем в начало разряда нули, если они должны быть
            os << " "
               << zeros(MAX_DIGITS - getLength(iterator->value))
               << iterator->value;

            iterator = iterator->next;
        }

        return os;
    }

    // Сложение больших чисел
    friend inline Huge operator+(const Huge& obj1, const Huge& obj2) {
        List<num_type> return_list;
        auto iterator1 = obj1.list.cbegin();
        auto iterator2 = obj2.list.cbegin();


    }

    Huge& operator=(const Huge&);

    static bool isDigit(char);
    static short getLength(num_type);
    static std::string zeros(short);
    static std::string reverseString(std::string);

private:
    List<num_type> list;
};

#endif // HUGE_H
