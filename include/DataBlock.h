#ifndef DATAPEN_BLOCK_H
#define DATAPEN_BLOCK_H
/** @AUTHORS = Joshua Weinstein
 * @EMAIL = jweinst1@berkeley.edu
 *
 */
// Header that defines the DataBlock class
// DataBlock deals with single chunks of data as bytes

#include <cstdio>

// Template sized block of data that can be written over
template<long size>
class DataBlock
{
public:
DataBlock()
{
        clean();
}
// Constructor from Data
DataBlock(const unsigned char* data, long length)
{
        clean();
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

template<class T> void write(const T* object, long length)
{
        if(length <= size )
        {
                const unsigned char* data = reinterpret_cast<const unsigned char*>(object);
                for(long i=0; i<length; i++) _data[i] = data[i];
        }
}

template<class T> void write(const T* object)
{
        if(sizeof(T) <= size)
        {
                const unsigned char* data = reinterpret_cast<const unsigned char*>(object);
                for(long i=0; i<sizeof(T); i++) _data[i] = data[i];
        }
}

template<class T> void write(const T& object)
{
        if(sizeof(T) <= size)
        {
                const unsigned char* data = reinterpret_cast<const unsigned char*>(&object);
                for(long i=0; i<sizeof(T); i++) _data[i] = data[i];
        }
}

// READ methods

// Reads the entire block into a buffer
void read(unsigned char* buf) const
{
        for (long i = 0; i < size; i++)
        {
                buf[i] = _data[i];
        }
}

//Reads one size of T from the block into the pointer buf.
template<class T> void read(T* object) const
{
        if(sizeof(T) <= size)
        {
                unsigned char* bufData = reinterpret_cast<unsigned char*>(object);
                for (long i = 0; i < sizeof(T); i++)
                {
                        bufData[i] = _data[i];
                }
        }

}

// Reads one size of T into a reference of type T
template<class T> void read(T& object) const
{
        if(sizeof(T) <= size)
        {
                unsigned char* bufData = reinterpret_cast<unsigned char*>(&object);
                for (long i = 0; i < sizeof(T); i++)
                {
                        bufData[i] = _data[i];
                }
        }

}

void print(void) const
{
        std::printf("[ ");
        for (long i = 0; i < size; i++)
        {
                std::printf("%u ", _data[i]);
        }
        std::printf("]\n");
}

// Clears all the data in the block
void clean(void)
{
        for(long i = 0; i<size; i++) _data[i] = 0;
}


private:
unsigned char _data[size];
};

#endif // DATAPEN_BLOCK_H
