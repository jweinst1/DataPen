#include <cstdio>
#include "DataCopy.h"




int main(int argc, char const *argv[]) {
        long f = 5000;
        unsigned char foo[8];
        DataCopy::copyToData(f, foo);
        for (size_t i = 0; i < 8; i++) {
                std::printf("%u\n", foo[i]);
        }

        return 0;

}
