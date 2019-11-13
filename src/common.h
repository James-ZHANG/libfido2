#ifndef THIRD_PARTY_LIBFIDO2_SRC_COMMON_H_
#define THIRD_PARTY_LIBFIDO2_SRC_COMMON_H_

#include <stdlib.h>

typedef struct fido_assert fido_assert_t;
typedef struct fido_cbor_info fido_cbor_info_t;
typedef struct fido_cred fido_cred_t;
typedef struct fido_dev fido_dev_t;
typedef struct fido_dev_info fido_dev_info_t;
typedef struct es256_pk es256_pk_t;
typedef struct es256_sk es256_sk_t;
typedef struct rs256_pk rs256_pk_t;
typedef struct eddsa_pk eddsa_pk_t;
typedef struct fido_rp fido_rp_t;
typedef struct fido_user fido_user_t;
typedef struct fido_attstmt fido_attstmt_t;
typedef struct fido_authdata fido_authdata_t;
typedef struct fido_attcred fido_attcred_t;

typedef void *fido_dev_io_open_t(const char *);
typedef void fido_dev_io_close_t(void *);
typedef int fido_dev_io_read_t(void *, unsigned char *, size_t, int);
typedef int fido_dev_io_write_t(void *, const unsigned char *, size_t);

typedef struct fido_dev_io {
  fido_dev_io_open_t *open;
  fido_dev_io_close_t *close;
  fido_dev_io_read_t *read;
  fido_dev_io_write_t *write;
} fido_dev_io_t;

typedef enum {
  FIDO_OPT_OMIT = 0, /* use authenticator's default */
  FIDO_OPT_FALSE,    /* explicitly set option to false */
  FIDO_OPT_TRUE,     /* explicitly set option to true */
} fido_opt_t;

#endif  // THIRD_PARTY_LIBFIDO2_SRC_COMMON_H_
