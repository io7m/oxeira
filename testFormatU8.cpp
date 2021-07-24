#include <oxeira/format.h>
#include <stdio.h>

static const uint8_t u8s[] = {
    0,   1,   10,  20,

    4,   215, 244, 79,  205, 10,  45,  60,  138, 84,  171, 32,  111, 89,  103,
    122, 211, 114, 216, 54,  3,   12,  109, 255, 40,  164, 228, 78,  183, 83,
    219, 108, 124, 35,  238, 207, 192, 233, 231, 234, 189, 188, 2,   187, 58,
    193, 100, 57,  126, 176, 29,  240, 155, 44,  141, 196, 212, 120, 185, 135,
    167, 140, 59,  64,  178, 252, 253, 210, 125, 250, 142, 224, 157, 144, 169,
    6,   104, 21,  239, 168, 22,  170, 236, 98,  249, 202, 199, 36,  75,  70,
    162, 191, 28,  16,  55,  146, 93,  165, 149, 73};

static void run(void)
{
  printf("testFormat8\n");
  printf("--\n");

  char buffer[oxeira::formatU32Size] = {0};

  for (unsigned int index = 0; index < sizeof(u8s) / sizeof(uint8_t); ++index)
  {
    buffer[oxeira::formatU8D(buffer, u8s[index])] = 0;
    printf("%s\n", buffer);
  }
}

extern "C"
{
  int main(void)
  {
    run();
    return 0;
  }
};
