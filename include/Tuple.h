#ifndef TUPLE_H
#define TUPLE_H

#include <iostream>
#include <cstdarg>


// General Tuple template class
template<class T>
class Tuple
{
public:
Tuple(size_t len ...) : _count(len), _items(new T[_count])
{
        va_list conArgs;
        va_start(conArgs, len);
        for(size_t i =0; i<len; i++)
        {
                _items[i] = va_arg(conArgs, T);
        }
        va_end(conArgs);
}
~Tuple()
{
        delete[] _items;
}

T& operator[](size_t index)
{
        return _items[index % _count];
}

size_t getCount(void) const
{
        return _count;
}
private:
T* _items;
size_t _count;
};

#endif
