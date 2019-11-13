#ifndef THIRD_PARTY_LIBFIDO2_EXAMPLES_UTIL_H_
#define THIRD_PARTY_LIBFIDO2_EXAMPLES_UTIL_H_

#include <stdlib.h>

int write_ec_pubkey(const char *path, const void *ptr, size_t len);
int write_rsa_pubkey(const char *path, const void *ptr, size_t len);
int write_eddsa_pubkey(const char *path, const void *ptr, size_t len);
int write_blob(const char *path, const unsigned char *ptr, size_t len);
int read_blob(const char *path, unsigned char **ptr, size_t *len);
int base10(const char *str, long long *ll);

#endif  // THIRD_PARTY_LIBFIDO2_EXAMPLES_UTIL_H_
