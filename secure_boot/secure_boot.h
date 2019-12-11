#ifndef SECURE_BOOT_H
#define SECURE_BOOT_H

#include <cryptography.h>

typedef struct boot_image_header_t {
  public_key_t manufacturer_public_key;

  public_key_t device_public_key;
  signature_t device_signature;

  hash_t software_measurement;
  public_key_t software_public_key;
  secret_key_t software_secret_key;
  signature_t software_signature;

  size_t software_measured_bytes;
  uint8_t* software_measured_binary[];
} boot_image_header_t;

#endif //SECURE_BOOT_H
