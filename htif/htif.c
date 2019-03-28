
#include <stdint.h>

volatile uint64_t htif_tohost __attribute__((section(".htif.tohost")));
volatile uint64_t htif_fromhost __attribute__((section(".htif.fromhost")));
