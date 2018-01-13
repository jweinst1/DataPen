#ifndef DATAPEN_BLOCH_H
#define DATAPEN_BLOCH_H
// Header that defines the DataBlock class
// DataBlock deals with single chunks of data as bytes

template<long size>
class DataBlock
{
public:
DataBlock()
{

}
// Constructor from Data
DataBlock(const unsigned char* data, long length)
{
        for(long i=0; i<length; i++) _data[i] = data[i];
}
~DataBlock()
{

}

unsigned char& operator[](long index)
{
        return _data[index];
}

const unsigned char* begin(void) const
{
        return _data;
}

const unsigned char* end(void) const
{
        return _data + size;
}

void write(const unsigned char* data, long length)
{
        if(length <= size )
        {
                for(long i=0; i<length; i++) _data[i] = data[i];
        }
}

template<class T> void write(const T* object)
{
        if(sizeof(T) <= size)
        {
                unsigned char* data = reinterpret_cast<unsigned char*>(object);
                for(long i=0; i<sizeof(T); i++) _data[i] = data[i];
        }
}
private:
unsigned char _data[size];
};

#endif // DATAPEN_BLOCH_H
