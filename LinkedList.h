#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include <iostream>

template <class T> class LinkedList;
template <typename T> std::ostream &operator<<(std::ostream &os, LinkedList<T> &list);

template <class T>
class LinkedList
{

    struct Node
    {
        T value;
        Node *next;

        Node(T _value) : value(_value), next(nullptr) {}
    };

public:
    class Iterator
    {
    public:
        Iterator (Node *_node) : node(_node) {}
        bool hasNext() {if (node) return node->next != nullptr;}
        void operator++() {if(node) node = node->next;}
        bool operator!=(const Iterator &iterator) {return node != iterator.node;}
        T operator*(){return node->value;}

    private:
        Node *node;
    };

    LinkedList();
    ~LinkedList();
    void append(T value);
    void insert(T value, int position);
    void remove(int position);
    Iterator begin() {return Iterator(head);}
    Iterator end() {return Iterator(nullptr);}
    inline int getSize() {return size;}
    T &operator[](int position);
    std::string toString();
    friend std::ostream &operator<<(std::ostream &os, LinkedList<T> &list)
    {
        os << list.toString();
        return os;
    }
    
private:
    Node *head;
    Node *tail;
    int size;
};

template <class T>
LinkedList<T>::LinkedList(): head(nullptr), tail(nullptr), size(0)
{

}

template <class T>
LinkedList<T>::~LinkedList()
{
    Node *current = head;
    Node *next = nullptr;

    while(current != nullptr)
    {
        next = current->next;
        delete current;
        current = next;
    }
}

template <class T>
void LinkedList<T>::append(T value)
{
    Node *temp1 = new Node(value);

    if (head == nullptr)
    {
        head = temp1;
        tail = head;
    }
    else
    {
        tail->next = temp1;
        tail = temp1;
    }

    ++size;
}

template <class T>
void LinkedList<T>::insert(T value, int position)
{
    if (position > size)
    {
        std::cerr << "Cannot insert value at a position greater than list size" << std::endl;
        return;
    }
    else if (head == nullptr || position == size)
    {
        append(value);
        return;
    }

    Node *temp1 = new Node(value);
    ++size;

    if (position == 0)
    {
        temp1->next = head;
        head = temp1;
        return;
    }

    Node *current = head;

    for (int i = 0; i < position - 1; ++i)
        current = current->next;

    temp1->next = current->next;
    current->next = temp1;
}

template <class T>
void LinkedList<T>::remove(int position)
{
    if (head == nullptr)
    {
        std::cout << "Empty list, no elements to remove" << std::endl;
        return;
    }
    else if (position >= size)
    {
        std::cout << "Cannot remove value at a position greater than list size" << std::endl;
        return;
    }

    --size;
    Node *current = head;

    if (position == 0)
    {
        head = head->next;
        delete current;
        return;
    }

    for (int i = 0; i < position - 1; ++i)
        current = current->next;

    Node *temp = current->next;
    current->next = temp->next;
    delete temp;

    if (position == size)
        tail = current;
}

template <class T>
T &LinkedList<T>::operator[](int position)
{
    if (position >= size && position != 0)
    {
        std::cerr << "Cannot find value. Position greater than size" << std::endl;
        T temp;
        return temp;
    }

    Node *current = head;

    for (int i = 0; i < position; i++)
        current = current->next;

    return current->value;
}

template <class T>
std::string LinkedList<T>::toString()
{
    std::string ret;

    for (auto node : *this)
        ret += std::to_string(node) + " ";

    return ret;
}

template <>
std::string LinkedList<std::string>::toString()
{
    std::string ret;

    for (auto node : *this)
        ret += node + " ";

    return ret;
}

#endif
