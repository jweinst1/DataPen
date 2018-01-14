#include <DataStream.h>
#include <iostream>
#include <string>



int main(int argc, char const *argv[]) {
        std::string foo = "Hello!\n";
        DataUnit strunit(foo);

        std::cout << strunit.getSize() << std::endl;
        return 0;


}
