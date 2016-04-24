#ifndef HUGE_H
#define HUGE_H
#define MAX_DIGITS (Huge::getLength((num_type) - 1) - 1)

#include <stdint.h>
#include "list.h"
#include <iostream>

/* Для использования другого типа данных измените эту строку.
 * Возможно использование только беззнаковых типов данных */
typedef uint32_t num_type;


class Huge {
public:
    Huge();
    Huge(const std::string&);
    Huge(const List<num_type>&);
    Huge(const Huge&);

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
            os << " " // Пробел между разрядами
               << zeros(MAX_DIGITS - getLength(iterator->value))
               << iterator->value;

            iterator = iterator->next;
        }

        return os;
    }

    // Сложение больших чисел
    friend inline Huge operator+(const Huge& obj1, const Huge& obj2) {
        List<num_type> result_list;
        auto iterator1 = obj1.list.cbegin();
        bool end1 = false;
        auto iterator2 = obj2.list.cbegin();
        bool end2 = false;

        num_type overflow = 0; // переполнение разряда
        num_type tmp = 0;
        do {
            // складываем разряды
            tmp = iterator1->value + iterator2->value + overflow;
            // получаем переполнение, если оно есть
            overflow = tmp / pow(10, MAX_DIGITS);
            /* отсекаем переполнение и добавляем
             * остаток в список разрядов результата */
            result_list.push_back(tmp % pow(10, MAX_DIGITS));

            // переходим к следующему разряду.
            iterator1 = iterator1->next;
            // проверяем, закончилось ли число
            if (iterator1 == obj1.list.cbegin()) {
                end1 = true;
            }
            // тоже самое со вторым слагаемым
            iterator2 = iterator2->next;
            if (iterator2 == obj2.list.cbegin()) {
                end2 = true;
            }
        } while (!end1 && !end2);

        // если первое число не закончилось
        if (!end1) {
            while (iterator1 != obj1.list.cbegin()) {
                // выполняем действия, аналогичные выполняемым выше
                tmp = iterator1->value + overflow;
                overflow = tmp / pow (10, MAX_DIGITS);
                result_list.push_back(tmp % pow(10, MAX_DIGITS));

                iterator1 = iterator1->next;
            }
        }
        // если второе число не закончилось
        else if (!end2) {
            while (iterator2 != obj2.list.cbegin()) {
                tmp = iterator2->value + overflow;
                overflow = tmp / pow (10, MAX_DIGITS);
                result_list.push_back(tmp % pow(10, MAX_DIGITS));

                iterator2 = iterator2->next;
            }
        }

        // если осталось переполнение, добавим его в нвоый разряд
        if (overflow != 0) {
            result_list.push_back(overflow);
        }

        return Huge(result_list);
    }

    Huge& operator=(const Huge&);

    static bool         isDigit(char);
    static short        getLength(num_type);
    static std::string  zeros(short);
    static std::string  reverseString(const std::string&);
    static num_type     pow(num_type, short);
private:
    List<num_type> list;
};

#endif // HUGE_H
