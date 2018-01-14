#include <DataStream.h>
#include <iostream>



int main(int argc, char const *argv[]) {
        unsigned char bits[] = {66, 66, 66, 66, 88};
        DataUnit unit(bits, 5);
        DataUnit unit2(bits, 5);
        std::cout << (unit == unit2) << std::endl;
        return 0;


}
