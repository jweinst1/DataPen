#ifndef DATAPEN_COPY_H
#define DATAPEN_COPY_H
//Header that defines raw data copying methods.

struct DataCopy
{
        template<class T> static void copyToData(const T& object, unsigned char* data)
        {
                const unsigned char* reader = reinterpret_cast<const unsigned char*>(&object);
                for (size_t i = 0; i < sizeof(T); i++) {
                        data[i] = reader[i];
                }
        }
};


#endif // DATAPEN_COPY_H
