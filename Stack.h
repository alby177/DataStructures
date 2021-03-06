#include "DoubleLinkedList.h"

// Forward declaration for template friend operator
template <class T> class Stack;
template <class T> std::ostream &operator<<(std::ostream &str, const Stack<T> &list);

template <class T>
class Stack
{
public:
    typedef typename DoubleLinkedList<T>::iterator iterator;
                            Stack           ();                                         // Constructor
    void                    push            (const T& data);                            // Add element on top
    T                       pop             ();                                         // Remove element on the top
    iterator                begin           ();                                         // Element on top of the stack 
    iterator                end             ();                                         // Element on the bottom of the stack 
    bool                    isEmpty         () const;                                   // Check for empty container
    std::string             toString        () const;                                   // Print stack data to string
    friend std::ostream     &operator<< <>  (std::ostream &str, const Stack &stack);    // Commodity operator overload for printing data to string

private:
    DoubleLinkedList<T> m_list;
};

template <class T>
Stack<T>::Stack() : m_list()
{
}

template <class T>
void Stack<T>::push(const T &data)
{
    m_list.append(data);
}

template <class T>
T Stack<T>::pop()
{
      return m_list.removeLast();
}

template <class T>
typename Stack<T>::iterator Stack<T>::begin()
{
    return m_list.begin();
}

template <class T>
typename Stack<T>::iterator Stack<T>::end()
{
    return m_list.end();
}

template <class T>
bool Stack<T>::isEmpty() const
{
    return m_list.isEmpty();
}

template <class T>
std::string Stack<T>::toString() const
{
    return m_list.toString();
}

template <class T>
std::ostream &operator<<(std::ostream &str, const Stack<T> &stack)
{
    str << stack.toString();
    return str;
}