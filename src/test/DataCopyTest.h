#ifndef DATAPEN_COPY_TEST_H
#define DATAPEN_COPY_TEST_H
// Header for data copy tests

#include <iostream>
#include "DataCopy.h"

void CopyTest_1(void)
{
        unsigned char buf[50];
        long i = 5000;
        DataCopy::copyToData(i, buf);
        std::cout << "[test copy]: size = 8, result = "
                  << static_cast<unsigned>(buf[0]) << ", "
                  << static_cast<unsigned>(buf[1]) << ", "
                  << static_cast<unsigned>(buf[2]) << ", "
                  << static_cast<unsigned>(buf[3]) << ", "
                  << static_cast<unsigned>(buf[4]) << ", "
                  << static_cast<unsigned>(buf[5]) << ", "
                  << static_cast<unsigned>(buf[6]) << ", "
                  << static_cast<unsigned>(buf[7]) << " "
                  << std::endl;
        if(buf[0] != 0) std::cout << "CopyTest_1: Passed" << std::endl;
        else std::cout << "CopyTest_1: Failed" << std::endl;
}

#endif // DATAPEN_COPY_TEST_H
