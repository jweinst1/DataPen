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

void write(unsigned char* data, size_t len)
{
        if(len <= _size)
        {
                std::copy(data, data + len, _data);
        }
}

private:
size_t _size;
unsigned char* _data;
DataUnit* _next;
};



#endif // DATAPEN_STREAM_H
