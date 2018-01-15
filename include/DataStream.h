#ifndef DATAPEN_STREAM_H
#define DATAPEN_STREAM_H
/** @AUTHORS = Joshua Weinstein
 * @EMAIL = jweinst1@berkeley.edu
 * @notes
 * -----------------------
 * Header that defines DataStream and related classes, for collecting, filtering, mapping, and reducing
 * Stores Units of Data which are linked together
 */

 #include <algorithm>

class DataUnit
{
public:
DataUnit(unsigned char* data, size_t len) : _size(len), _data(new unsigned char[_size]), _next(nullptr)
{
        std::copy(data, data + len, _data);
}

// Copy Constrcutor
DataUnit(const DataUnit& other) : _size(other.getSize()), _data(new unsigned char[_size]), _next(other.getNext())
{
        std::copy(other.getData(), other.getData() + other.getSize(), _data);
}

template<class T> DataUnit(const T& object) : _size(sizeof(T)), _data(new unsigned char[_size]), _next(nullptr)
{
        const unsigned char* objData = reinterpret_cast<const unsigned char*>(&object);
        std::copy(objData, objData + sizeof(T), _data);
}

template<class T> DataUnit(const T* object, size_t len) : _size(sizeof(T) * len), _data(new unsigned char[_size]), _next(nullptr)
{
        const unsigned char* objData = reinterpret_cast<const unsigned char*>(object);
        std::copy(objData, objData + _size, _data);
}

DataUnit& operator=(const DataUnit& other)
{
        if(this != &other)
        {
                _next = other.getNext();
                _size = other.getSize();
                std::copy(other.getData(), other.getData() + other.getSize(), _data);

        }
        return *this;
}

~DataUnit()
{
        delete[] _data;
}

const unsigned char* getData(void) const
{
        return _data;
}

size_t getSize(void) const
{
        return _size;
}

DataUnit* getNext(void)
{
        return _next;
}

bool hasNext(void) const
{
        return _next != nullptr;
}

bool operator==(const DataUnit& other) const
{
        if(other.getSize() != _size) return false;
        else
        {
                size_t counter = other.getSize();
                const unsigned char* otherData = other.getData();
                const unsigned char* thisData = _data;
                while(counter--)
                {
                        if(*otherData++ != *thisData++) return false;
                }
                return true;
        }
}

bool operator!=(const DataUnit& other) const
{
        return !(*this == other);
}

void write(unsigned char* data, size_t len)
{
        if(len <= _size)
        {
                std::copy(data, data + len, _data);
        }
}

unsigned char& operator[](const size_t index)
{
        return _data[index];
}

private:
size_t _size;
unsigned char* _data;
DataUnit* _next;
};


class DataStream
{

};



#endif // DATAPEN_STREAM_H
