#ifndef THIRD_PARTY_LIBFIDO2_SRC_CBOR_H_
#define THIRD_PARTY_LIBFIDO2_SRC_CBOR_H_

#include "third_party/libcbor/cbor.h"
#include "blob.h"
#include "types.h"

typedef struct fido_dev fido_dev_t;

/* auxiliary cbor routines */
int cbor_add_bool(cbor_item_t *, const char *, fido_opt_t);
int cbor_add_bytestring(cbor_item_t *, const char *, const unsigned char *,
                        size_t);
int cbor_add_string(cbor_item_t *, const char *, const char *);
int cbor_array_iter(const cbor_item_t *, void *,
                    int (*)(const cbor_item_t *, void *));
int cbor_build_frame(uint8_t, cbor_item_t *[], size_t, fido_blob_t *);
int cbor_bytestring_copy(const cbor_item_t *, unsigned char **, size_t *);
int cbor_map_iter(const cbor_item_t *, void *,
                  int (*)(const cbor_item_t *, const cbor_item_t *, void *));
int cbor_string_copy(const cbor_item_t *, char **);
int parse_cbor_reply(const unsigned char *, size_t, void *,
                     int (*)(const cbor_item_t *, const cbor_item_t *, void *));
int add_cbor_pin_params(fido_dev_t *, const fido_blob_t *, const es256_pk_t *,
                        const fido_blob_t *, const char *, cbor_item_t **,
                        cbor_item_t **);
void cbor_vector_free(cbor_item_t **, size_t);

#endif  // THIRD_PARTY_LIBFIDO2_SRC_CBOR_H_
