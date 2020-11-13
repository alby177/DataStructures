#include <string>
#include <typeinfo>

// Forward declaration for template friend operator
template <class T> class DoubleLinkedList;
template <class T> std::ostream &operator<<(std::ostream &str, const DoubleLinkedList<T> &list);

template <class T>
class DoubleLinkedList 
{
public:
                            DoubleLinkedList();
                           ~DoubleLinkedList();
    inline unsigned int     getSize         () const                                            {return m_size;}        // Constructor
    inline bool             isEmpty         () const                                            {return m_size == 0;}   // Destructor
    void                    append          (const T &data);                                                            // Append element to the end of the list
    void                    operator+=      (const T &data);                                                            // Append element to the end of the list
    void                    prepend         (const T &data);                                                            // Prepend element to the begin of the list
    void                    insert          (const unsigned int position, const T &data);                               // Insert element at position in the list
    T                       remove          (const unsigned int position);                                              // Remove position element from the list
    T                       removeLast      ();                                                                         // Remove last element from the list
    T                       removeFirst     ();                                                                         // Remove first element from the list
    T                      &at              (const unsigned int position);                                              // Get data at position
    T                      &operator[]      (const unsigned int position);                                              // Get data at position
    void                    clear           ();                                                                         // Clear all data list
    std::string             toString        () const;                                                                   // Format data for string output
    friend std::ostream    &operator<< <>   (std::ostream &str, const DoubleLinkedList &list);                          // Commodity stream operator overload

private:

    struct Node
    {
        Node() : m_data(), m_prev(nullptr), m_next(nullptr) {}
        Node(const T &data, Node *prev = nullptr, Node *next = nullptr) : m_data(data), m_prev(prev), m_next(next) {}

        T m_data;
        Node *m_prev;
        Node *m_next; 
    };

    T                       removeInternal  (Node *node);

    unsigned int            m_size;
    Node                   *m_head;
    Node                   *m_tail;
};

template <class T>
DoubleLinkedList<T>::DoubleLinkedList() : m_size(0), m_head(nullptr), m_tail(nullptr) 
{
}

template <class T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
    clear();
}

template <class T>
void DoubleLinkedList<T>::append(const T &data)
{
    Node *tmp = new Node(data);

    if(isEmpty())
        m_head = tmp;
    else
    {
        tmp->m_prev = m_tail;
        m_tail->m_next = tmp;
    }

    m_tail = tmp;
    
    ++m_size;        
}

template <class T>
void DoubleLinkedList<T>::operator+=(const T &data)
{
    return append(data);
}

template <class T>
void DoubleLinkedList<T>::prepend(const T &data)
{
    if(isEmpty())
        return append(data);

    Node *tmp = new Node(data);
    
    tmp->m_prev = nullptr;
    tmp->m_next = m_head;
    m_head->m_prev = tmp;
    
    m_head = tmp;
    
    ++m_size;    
}

template <class T>
void DoubleLinkedList<T>::insert(const unsigned int position, const T &data)
{
    if(position > m_size)       throw std::exception();
    else if(position == m_size) return append(data);
    else if(position == 0)      return prepend(data);


    int i = 0;
    Node *current = nullptr;
    if(position > m_size / 2)
    {
        for(current = m_tail; i < m_size - position; ++i)
            current = current->m_prev;  
    }
    else
    {
        for(current = m_head; i < position - 1; ++i)
            current = current->m_next;  
    }

    Node *tmp = new Node(data);
    tmp->m_prev = current;
    tmp->m_next = current->m_next;
    current->m_next = tmp;
    tmp->m_next->m_prev = tmp;
    
    ++m_size;  
}

template <class T>
T DoubleLinkedList<T>::remove(const unsigned int position)
{
    if(position >= m_size) throw std::exception();

    int i = 0;
    Node *current = nullptr;
    if(position > m_size / 2)
    {
        for(current = m_tail; i < m_size - 1 - position; ++i)
            current = current->m_prev;  
    }
    else
    {
        for(current = m_head; i < position; ++i)
            current = current->m_next;  
    }

    return removeInternal(current);
}

template <class T>
T DoubleLinkedList<T>::removeFirst()
{
    if(isEmpty()) throw std::exception();

    T data = m_head->m_data;

    Node *nodeToRemove = m_head;
    m_head = m_head->m_next;
    delete nodeToRemove;
    nodeToRemove = nullptr;
    --m_size;

    if(isEmpty())
        m_tail = nullptr;
    else
        m_head->m_prev = nullptr;

    return data;
}

template <class T>
T DoubleLinkedList<T>::removeLast()
{
    if(isEmpty()) throw std::exception();

    T data = m_tail->m_data;

    Node *nodeToRemove = m_tail;
    m_tail = m_tail->m_prev;
    delete nodeToRemove;
    nodeToRemove = nullptr;
    --m_size;

    if(isEmpty())
        m_head = nullptr;
    else
        m_tail->m_next = nullptr;

    return data;   
}

template <class T>
T DoubleLinkedList<T>::removeInternal(Node *node)
{
    if(node->m_prev == nullptr) return removeFirst();
    if(node->m_next == nullptr) return removeLast();

    node->m_prev->m_next = node->m_next;
    node->m_next->m_prev = node->m_prev;

    T data = node->m_data;

    node->m_prev = nullptr;
    node->m_next = nullptr;
    delete node;
    node = nullptr;
    --m_size;
    
    return data;
}

template <class T>
T &DoubleLinkedList<T>::at(const unsigned int position)
{
    if (position >= m_size) throw std::exception();

    int i = 0;
    Node *current = nullptr;

    if(position > m_size / 2)
    {
        for(current = m_tail; i < m_size - 1 - position; ++i)
            current = current->m_prev;  
    }
    else
    {
        for(current = m_head; i < position; ++i)
            current = current->m_next;  
    }

    return current->m_data;    
}

template <class T>
T &DoubleLinkedList<T>::operator[](const unsigned int position)
{
    return at(position);
}

template <class T>
void DoubleLinkedList<T>::clear()
{
    Node *current = m_head;
    Node *next = nullptr;

    while(current)
    {
        next = current->m_next;
        delete current;
        current = next;
    }

    m_size = 0;
    m_head = nullptr;   
    m_tail = nullptr;   
}

template <class T>
std::string DoubleLinkedList<T>::toString() const
{
    std::string res = std::string(typeid(T).name()) + " double linked list content is: [";
    
    Node *current = m_head;
    while(current)
    {
        res += std::to_string(current->m_data) + ", ";
        current = current->m_next;
    }

    // Remove last comma
    if(!isEmpty())
    {
        res.pop_back();
        res.pop_back();
    }
    res += "]";

    return res;
}

template <>
std::string DoubleLinkedList<std::string>::toString() const
{
    std::string res = "std::string double linked list content is: [";
    
    Node *current = m_head;
    while(current)
    {
        res += current->m_data + ", ";
        current = current->m_next;
    }

    // Remove last comma
    if(!isEmpty())
    {
        res.pop_back();
        res.pop_back();
    }
    res += "]";

    return res;
}

template <typename T>
std::ostream &operator<<(std::ostream &str, const DoubleLinkedList<T> &list)
{
    str << list.toString(); 
    return str;
}