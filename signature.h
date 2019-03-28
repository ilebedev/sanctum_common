

TODO: instantiation of ed25519+sha3 goes here

#define ED25519_NO_SEED 1
#include "src/ed25519.h"

/* Adopted from https://github.com/orlp/ed25519
  Modified to use SHA3
  provides:
  - void ed25519_create_keypair(t_pubkey *public_key, t_privkey *private_key, t_seed *seed);
  - void ed25519_sign(t_signature *signature,
                      const unsigned uint8_t *message,
                      size_t message_len,
                      t_pubkey *public_key,
                      t_privkey *private_key);
*/

#include <stdint.h>

typedef uint8_t public_key_t[32];
typedef uint8_t secret_key_t[64];
typedef uint8_t signature_t[64];
typedef uint8_t kdf_seed_t[32];
