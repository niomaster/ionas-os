#include "io.h"

int main()
{
    __asm
    (
          "mov ax, #0xb800"
          "mov es, ax"
          "seg es"
          "mov [0], #0x41"
          "seg es"
          "mov [1], #0x1f"
          "blaat"
    );

    writeXY(0, 0, "Hello World!", 0x10);
}
