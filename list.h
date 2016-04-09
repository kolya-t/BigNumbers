#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::ostream;

template <typename T>
class List {
public:
    List();
    List(const List<T>& orig);
    ~List();
public:

    struct Node {
        Node() : next(0), value(T()) {}
        Node* next;
        T     value;
    };

    void        push_back  (const T&      );
    void        push_front (const T&      );
    void        append     (const T&      );
    void        append     (const List<T>&);
    void        prepend    (const T&      );
    void        prepend    (const List<T>&);
    void        print      (              ) const;
    bool        empty      (              ) const;
    bool        contains   (const T&      ) const;
    void        clear      (              );
    Node*       begin      (              );
    Node*       end        (              );
    const Node* cbegin     (              ) const;
    const Node* cend       (              ) const;
    List<T>&    operator=  (const List<T>&);

    friend inline ostream& operator<<(ostream& os, const List<T> list) {
        if (list.empty()) {
            return os;
        }
        Node* iterator = list.head;
        while (iterator != list.tail) {
            os << iterator->value << ", ";
            iterator = iterator->next;
        }
        os << iterator->value;
        return os;
    }

private:
    Node* head;
    Node* tail;
};

// конструктор по-умолчанию
template <typename T>
List<T>::List() : head(0), tail(0) {}

// конструктор копирования
template <typename T>
List<T>::List(const List<T>& orig) : head(0), tail(0) {
    if (orig.empty()) {
        return;
    }
    Node* iterator = orig.head;
    do {
        push_back(iterator->value);
        iterator = iterator->next;
    } while (iterator != orig.head);
}

// деструктор
template<typename T>
List<T>::~List() {
    clear();
}

// вставка элемента в конец
template <typename T>
void List<T>::push_back(const T& value) {
    Node* temp = new Node;
    temp->value = value;
    if (empty()) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
    // после хвоста будет голова
    tail->next = head;
}

// вставка элемента в начало списка
template <typename T>
void List<T>::push_front(const T& value) {
    Node* temp = new Node;
    temp->value = value;

    temp->next = head;
    head = temp;

    // если вставляем элемент впервые
    if (head->next == 0) {
        tail = head;
    }
    tail->next = head;
}

// вставить элемент в конец списка
template <typename T>
void List<T>::append(const T& value) {
    push_back(value);
}

// добавить записи из списка в конец
template <typename T>
void List<T>::append(const List<T>& list) {
    if (list.empty()) {
        return;
    }
    Node* itr = list.head;
    do {
        push_back(itr->value);
        itr = itr->next;
    } while (itr != list.head);
}

// вставить элемент в начало списка
template <typename T>
void List<T>::prepend(const T& value) {
    push_front(prepend);
}

// вставить элементы списка list в начало текущего списка
template <typename T>
void List<T>::prepend(const List<T>& list) {
    List<T>* temp = new List<T>(list);
    temp->append(*this);
    clear();
    head = temp->head;
    tail = temp->tail;
}

// распечатка значений
template <typename T>
void List<T>::print() const {
    if (empty()) {
        cout << "List is empty." << endl;
        return;
    }
    Node* itr = head;
    do {
        cout << itr->value << " ";
        itr = itr->next;
    } while (itr != head);
    cout << endl;
}

// пуст ли список
template <typename T>
bool List<T>::empty() const {
    return head == 0;
}

// содержится ли элемент в списке
template <typename T>
bool List<T>::contains(const T& value) const {
    if (empty()) {
        return false;
    }

    bool isFound = false;
    Node* iterator = head;
    do {
        if (iterator->value == value) {
            isFound = true;
            break;
        }
        iterator = iterator->next;
    } while (iterator != head);
    return isFound;
}

// очистка всего списка
template <typename T>
void List<T>::clear() {
    if (empty()) {
        return;
    }
    Node* temp;
    while (head != tail) {
        temp = head->next;
        delete head;
        head = temp;
    }
    delete head;
    head = tail = 0;
}

template <typename T>
typename List<T>::Node* List<T>::begin() {
    return head;
}

template <typename T>
typename List<T>::Node* List<T>::end() {
    return tail;
}

// возвращает указатель на первый элемент списка
template <typename T>
const typename List<T>::Node* List<T>::cbegin() const {
    return head;
}

// возвращает последний элемент списка
template <typename T>
const typename List<T>::Node* List<T>::cend() const {
    return tail;
}

// перегрузка оператора присваивания
template <typename T>
List<T>& List<T>::operator=(const List<T>& list) {
    clear();
    Node* iterator = list.head;
    if (iterator) {
        do {
            push_back(iterator->value);
            iterator = iterator->next;
        } while (iterator != list.head);
    }
    return *this;
}

#endif // LIST_H
