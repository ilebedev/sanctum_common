#ifndef HTIF_H
#define HTIF_H

#include <stdint.h>

extern volatile uint64_t tohost;
extern volatile uint64_t fromhost;

# define TOHOST_CMD(dev, cmd, payload) \
  (((uint64_t)(dev) << 56) | ((uint64_t)(cmd) << 48) | (uint64_t)(payload))

#define FROMHOST_DEV(fromhost_value) ((uint64_t)(fromhost_value) >> 56)
#define FROMHOST_CMD(fromhost_value) ((uint64_t)(fromhost_value) << 8 >> 56)
#define FROMHOST_DATA(fromhost_value) ((uint64_t)(fromhost_value) << 16 >> 16)

void htif_putchar(uint8_t c);

uint64_t htif_getchar() ;

void print_char(char c);

void print_str(char* s);

void print_int(uint64_t n);

#endif // HTIF_H
