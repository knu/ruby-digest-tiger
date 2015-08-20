#include "ruby.h"
#include <sys/types.h>

#if defined(HAVE_SYS_CDEFS_H)
# include <sys/cdefs.h>
#endif

#if defined(HAVE_INTTYPES_H)
# include <inttypes.h>
#elif !defined __CYGWIN__ || !defined __uint8_t_defined
typedef unsigned char uint8_t;
typedef unsigned int  uint32_t;
# if SIZEOF_LONG == 8
typedef unsigned long uint64_t;
# elif SIZEOF_LONG_LONG == 8
typedef unsigned LONG_LONG uint64_t;
# else
#  define NO_UINT64_T
# endif
#endif

/* The following macro denotes that an optimization    */
/* for Alpha is required. It is used only for          */
/* optimization of time. Otherwise it does nothing.    */
#if SIZEOF_LONG == 8
#define OPTIMIZE_FOR_ALPHA
#endif

/* NOTE that this code is NOT FULLY OPTIMIZED for any  */
/* machine. Assembly code might be much faster on some */
/* machines, especially if the code is compiled with   */
/* gcc.                                                */

/* The number of passes of the hash function.          */
/* Three passes are recommended.                       */
/* Use four passes when you need extra security.       */
/* Must be at least three.                             */
#define PASSES 3

typedef struct {
    uint64_t state[3];
    uint32_t len;
    uint32_t remlen;
    uint8_t  rembuf[64];
} tiger_state_t;

#define TIGER_DIGEST_LENGTH	( 3 * sizeof(uint64_t))
#define TIGER_BLOCK_LENGTH	(64 * sizeof(uint8_t))

int tiger_init(tiger_state_t *ctx);
void tiger_update(tiger_state_t *ctx, uint8_t *str, uint32_t length);
int tiger_final(tiger_state_t *ctx, uint8_t *result);
