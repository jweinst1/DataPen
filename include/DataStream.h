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
DataUnit(unsigned char* data, size_t len) : _size(len), _data(new unsigned char[_size])
{
        std::copy(data, data + len, _data);
}

~DataUnit()
{
        delete[] _data;
}

const unsigned char* data(void) const
{
        return _data;
}
private:
size_t _size;
unsigned char* _data;
};



#endif // DATAPEN_STREAM_H
