#ifndef THIRD_PARTY_LIBFIDO2_SRC_LOG_H_
#define THIRD_PARTY_LIBFIDO2_SRC_LOG_H_

#include <stdlib.h>

/* log */
#ifdef FIDO_NO_DIAGNOSTIC
#define log_init(...) \
  do { /* nothing */  \
  } while (0)
#define log_debug(...) \
  do { /* nothing */   \
  } while (0)
#define log_xxd(...) \
  do { /* nothing */ \
  } while (0)
#else
#ifdef __GNUC__
void log_init(void);
void log_debug(const char *, ...) __attribute__((__format__(printf, 1, 2)));
void log_xxd(const void *, size_t);
#else
void log_init(void);
void log_debug(const char *, ...);
void log_xxd(const void *, size_t);
#endif /* __GNUC__ */
#endif /* FIDO_NO_DIAGNOSTIC */

#endif  // THIRD_PARTY_LIBFIDO2_SRC_LOG_H_
