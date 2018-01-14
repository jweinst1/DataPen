#include <DataStream.h>
#include <cstdio>



int main(int argc, char const *argv[]) {
        unsigned char bits[] = {66, 66, 66, 66, 88};
        DataUnit unit(bits, 5);
        std::printf("bytes are %u, %u\n", *unit.data(), *(unit.data() + 1));
        return 0;

}
