template <class T>
class CustomIterator
{
public:
    CustomIterator(T *ptr) : m_ptr(ptr){}
    inline bool operator==(const CustomIterator<T> &other){return m_ptr == other.m_ptr;}
    inline bool operator!=(const CustomIterator<T> &other){return m_ptr != other.m_ptr;}
    inline bool hasNext(){return m_ptr->hasNext();}
    inline CustomIterator<T> &next(){if(m_ptr->hasNext()) m_ptr = m_ptr->next(); return (*this);}
    inline CustomIterator<T> &operator++(){return next();}
    inline CustomIterator<T> operator++(int){CustomIterator<T> tmp = CustomIterator<T>(m_ptr); m_ptr = m_ptr->next(); return tmp;}
    // inline CustomIterator<T> &operator--(){--m_ptr; return (*this);}
    inline T operator*(){return *m_ptr;}
    friend std::ostream &operator<<(std::ostream &str, const CustomIterator<T> &it){str << it.m_ptr; return str;}

private:
    T *m_ptr;
};