#include <DataStream.h>
#include <iostream>
#include <string>



int main(int argc, char const *argv[]) {
        int* foo = new int[50];
        DataUnit strunit(foo, 50);

        std::cout << strunit.getSize() << std::endl;
        return 0;



}
