#ifndef DATA_BLOCK_TEST_1_H
#define DATA_BLOCK_TEST_1_H
//Header for DataBlock tests


#include "DataBlock.h"
#include <iostream>

void BlockTest_1(void)
{
        int i = 6;
        DataBlock<4> iblock;
        iblock.write(i);
        if(iblock[0] == 6) std::cout << "BlockTest_1: Passed" << std::endl;
        else std::cout << "BlockTest_1: Failed" << std::endl;
}

void BlockTest_2(void)
{
        int i = 6;
        DataBlock<4> iblock;
        iblock.write(i);
        iblock[0] = 66;
        if(iblock[0] == 66) std::cout << "BlockTest_2: Passed" << std::endl;
        else std::cout << "BlockTest_2: Failed" << std::endl;
}

#endif //DATA_BLOCK_TEST_1_H
