#ifndef CRYPTOGRAPHY_H
#define CRYPTOGRAPHY_H

// Hash
#include <sha3/sha3.h>

typedef struct hash_t { uint8_t x[32]; } hash_t;
typedef sha3_ctx_t hash_context_t;

static inline void hash(const void * in_data,
  size_t in_data_size,
  hash_t * out_hash) {

  // mdlen = hash output in bytes
  // digest goes to md
  sha3(in_data, in_data_size, out_hash, 32);
}

static inline void init_hash(hash_context_t * hash_context) {
  sha3_init(hash_context, 32);    // mdlen = hash output in bytes
}

static inline void extend_hash(hash_context_t * hash_context,
  const void * in_data,
  size_t in_data_size) {
  sha3_update(hash_context, in_data, in_data_size);
}

static inline void finalize_hash(hash_context_t * hash_context,
  hash_t * out_hash) {

  // digest goes to md
  sha3_final(out_hash, hash_context);
}

// Symmetric cipher

#define CBC 0
#define ECB 0
#define CTR 1
#define AES256 1
#include <aes/aes.h>

#include <string.h>
// Provides memcpy

typedef struct symmetric_key_t { uint8_t x[AES_KEYLEN]; } symmetric_key_t;
typedef struct symmetric_public_data_t { uint8_t x[AES_BLOCKLEN]; } symmetric_public_data_t;

static inline void symmetric_encrypt(const void * in_plaintext,
  size_t in_message_size,
  const symmetric_key_t * in_key,
  const symmetric_public_data_t * in_public_values,
  void * out_ciphertext) {

  struct AES_ctx ctx;
  uint8_t buffer[in_message_size]; // CAUTION: the size should never be controlled by the adversary!
  memcpy(buffer, in_plaintext, in_message_size);
  AES_init_ctx_iv(&ctx, in_key, in_public_values);
  AES_CTR_xcrypt_buffer(&ctx, buffer, in_message_size);
}

static inline void symmetric_decrypt(const void * in_ciphertext,
  size_t in_message_size,
  const symmetric_key_t * in_key,
  const symmetric_public_data_t * in_public_values,
  void * out_plaintext) {

  struct AES_ctx ctx;
  uint8_t buffer[in_message_size]; // CAUTION: the size should never be controlled by the adversary!
  memcpy(buffer, in_ciphertext, in_message_size);
  AES_init_ctx_iv(&ctx, in_key, in_public_values);
  AES_CTR_xcrypt_buffer(&ctx, buffer, in_message_size);
}

// Signatures

#define ED25519_NO_SEED 1
#include <ed25519/ed25519.h>

typedef struct public_key_seed_t { uint8_t x[32]; } key_seed_t;
typedef struct public_key_t { uint8_t x[32]; } public_key_t;
typedef struct secret_key_t { uint8_t x[64]; } secret_key_t;
typedef struct signature_t { uint8_t x[64]; } signature_t;

static inline void create_secret_signing_key(const key_seed_t * in_seed, secret_key_t * out_secret_key) {
  ed25519_create_privkey(out_secret_key, in_seed);
}

static inline void compute_public_signing_key(const secret_key_t * in_secret_key, const public_key_t * out_public_key) {
  ed25519_compute_pubkey(out_public_key, in_secret_key);
}

static inline void sign(void * in_data,
  size_t in_data_size,
  public_key_t * in_public_key,
  secret_key_t * in_secret_key,
  signature_t * out_signature) {

  ed25519_sign((uint8_t *)out_signature,
    in_data,
    in_data_size,
    (const uint8_t*)in_public_key,
    (const uint8_t*)in_secret_key);
}

#endif
