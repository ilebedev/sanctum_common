

/*
  adopted from https://github.com/mjosaarinen/tiny_sha3 commit dcbb3192047c2a721f5f851db591871d428036a9
  provides:
  - void * sha3(const void *message, size_t message_bytes, void *output, int output_bytes)
  - int sha3_init(sha3_ctx_t *c, int output_bytes);
  - int sha3_update(sha3_ctx_t *c, const void *message, size_t message_bytes);
  - int sha3_final(void *output, sha3_ctx_t *c);
  types: sha3_ctx_t
*/

TODO: 32B instantiation of SHA3 goes here
Include sha3/sha3.h

typedef uint8_t measurement_t[32];
typedef hash_state_t

export hash(*, size, *out)
export init_hash(*state)
export extend_hash(*state, *, size)
export finalize_hash(*state, *out)
