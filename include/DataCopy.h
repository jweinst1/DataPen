#ifndef DATAPEN_COPY_H
#define DATAPEN_COPY_H
//Header that defines raw data copying methods.
/** @AUTHORS = Joshua Weinstein
 * @EMAIL = jweinst1@berkeley.edu
 *
 */

struct DataCopy
{
        // Copies the data of an object of type T into data
        template<class T> static void copyToData(const T& object, unsigned char* data)
        {
                const unsigned char* reader = reinterpret_cast<const unsigned char*>(&object);
                for (size_t i = 0; i < sizeof(T); i++) {
                        data[i] = reader[i];
                }
        }

        // Reads the data of an object of type T from data into object
        template<class T> static void copyFromData(T& object, unsigned char* data)
        {
                unsigned char* writer = reinterpret_cast<unsigned char*>(&object);
                for (size_t i = 0; i < sizeof(T); i++) {
                        writer[i] = data[i];
                }
        }
};


#endif // DATAPEN_COPY_H
