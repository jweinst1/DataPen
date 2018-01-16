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

// Tests the Reading ability of the Data Block
void BlockTest_3(void)
{
        long i = 444;
        DataBlock<8> iblock(i);
        long j = 0;
        iblock.read(j);
        if(j == 444) std::cout << "BlockTest_3: Passed" << std::endl;
        else std::cout << "BlockTest_3: Failed" << std::endl;
}

void BlockTest_4(void)
{
        DataBlock<3> foo;
        foo[0] = 66;
        foo[1] = 33;
        foo[2] = 77;

        DataBlock<6> parent;
        parent.write(foo);
        parent.print();
        std::cout << "BlockTest_4: Passed" << std::endl;
}


#endif //DATA_BLOCK_TEST_1_H
