// Forward declaration for template friend operator
template <class T> class CustomIterator;
template <class T> std::ostream &operator<<(std::ostream &str, const CustomIterator<T> &it);

template <class T>
class CustomIterator
{
public:
                            CustomIterator  (T *ptr);
    bool                    operator==      (const CustomIterator<T> &other);
    bool                    operator!=      (const CustomIterator<T> &other);
    bool                    hasNext         ();
    CustomIterator<T>      &next            ();
    CustomIterator<T>      &operator++      ();
    CustomIterator<T>       operator++      (int);
    T                       operator*       ();
    friend std::ostream    &operator<< <>   (std::ostream &str, const CustomIterator<T> &it);

private:
    T *m_ptr;
};

template <class T>
CustomIterator<T>::CustomIterator(T *ptr) : m_ptr(ptr)
{
}

template <class T>
bool CustomIterator<T>::operator==(const CustomIterator<T> &other)
{
    return m_ptr == other.m_ptr;
}

template <class T>
bool CustomIterator<T>::operator!=(const CustomIterator<T> &other)
{
    return m_ptr != other.m_ptr;
}

template <class T>
bool CustomIterator<T>::hasNext()
{
    return m_ptr->hasNext();
}

template <class T>
CustomIterator<T> &CustomIterator<T>::next()
{
    if(m_ptr->hasNext()) 
        m_ptr = m_ptr->next(); 
    
    return (*this);
}

template <class T>
CustomIterator<T> &CustomIterator<T>::operator++()
{
    return next();
}

template <class T>
CustomIterator<T> CustomIterator<T>::operator++(int)
{
    CustomIterator<T> tmp = CustomIterator<T>(m_ptr); 
    m_ptr = m_ptr->next(); 
    
    return tmp;
}

template <class T>
T CustomIterator<T>::operator*()
{
    return *m_ptr;
}

template <class T>
std::ostream &operator<<(std::ostream &str, const CustomIterator<T> &it)
{
    str << it.m_ptr; 
    return str;
}