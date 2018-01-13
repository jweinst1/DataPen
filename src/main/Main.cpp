#include <iostream>
#include "DataBlock.h"



int main(int argc, char const *argv[]) {
        DataBlock<20> pot;
        long g = 400000;
        pot.write(g);
        pot.print();
        long f = 0;
        pot.read(f);
        std::cout << f << std::endl;
        return 0;

}
