#ifndef SECURE_BOOT_H
#define SECURE_BOOT_H

#include <hash.h>
#include <signature.h>

typedef struct bootloader_inputs_t {
  public_key_t manufacturer_public_key;
  signature_t manufacturer_signature;
  bool has_encrypted_device_key;
  bool has_encrypted_post_boot_key;
  size_t software_size;
  // PUF helper data belongs here
  // encrypted SK_D belongs here
} bootloader_inputs_t;

typedef struct bootloader_io_t {
  public_key_t device_public_key;
  public_key_t post_boot_public_key;
  secret_key_t post_boot_secret_key;
  measurement_t post_boot_measurement;
  signature_t post_boot_signature;
  bootloader_inputs_t bootloader_inputs;
} bootloader_io_t;

#endif //SECURE_BOOT_H
