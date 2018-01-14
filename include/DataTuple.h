#ifndef DATAPEN_TUPLE_H
#define DATAPEN_TUPLE_H
/** @AUTHORS = Joshua Weinstein
 * @EMAIL = jweinst1@berkeley.edu
 *
 */
// Header that defines the Data Tuple Class

typedef std::size_t size_t;

struct TupleType
{
        enum Type
        {
                Int,
                Long,
                Char,
                Uchar,
                Str
        };
        static size_t size(Type type)
        {
                switch(type)
                {
                case Int: return 4;
                case Long: return 8;
                case Char: return 1;
                case Uchar: return 1;
                case Str: return 0;
                }
        }
};



class DataTuple
{
public:
DataTuple(size_t size) : _size(size), _data(new unsigned char[size])
{
}
~DataTuple()
{
        delete[] _data;
}

const unsigned char* data(void) const
{
        return _data;
}

//Copies by assignment one object of type T into the tuple.
template<class T> void put(const T& object)
{
        if(sizeof(T) <= _size)
        {
                T* typedData = reinterpret_cast<T*>(_data);
                *typedData = object;
        }
}
private:
size_t _size;
unsigned char* _data;
};


#endif //DATAPEN_TUPLE_H
