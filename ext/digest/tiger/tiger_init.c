/************************************************

  tiger_init.c - provides Digest::Tiger class

  Copyright (C) 2006-2013 Akinori MUSHA

************************************************/

#ifdef HAVE_RUBY_DIGEST_H
#include "ruby/digest.h"
#else
#include "digest.h"
#endif
#include "tiger.h"

static rb_digest_metadata_t tiger = {
    RUBY_DIGEST_API_VERSION,
    TIGER_DIGEST_LENGTH,
    TIGER_BLOCK_LENGTH,
    sizeof(tiger_state_t),
    (rb_digest_hash_init_func_t)tiger_init,
    (rb_digest_hash_update_func_t)tiger_update,
    (rb_digest_hash_finish_func_t)tiger_final,
};

void
Init_tiger()
{
    VALUE mDigest, cDigest_Base, cDigest_Tiger;

    rb_require("digest");

    mDigest = rb_path2class("Digest");
    cDigest_Base = rb_path2class("Digest::Base");

    cDigest_Tiger = rb_define_class_under(mDigest, "Tiger", cDigest_Base);

    rb_ivar_set(cDigest_Tiger, rb_intern("metadata"),
      Data_Wrap_Struct(rb_cObject, 0, 0, &tiger));
}
