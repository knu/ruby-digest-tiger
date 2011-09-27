/************************************************

  whirlpool.c - provides Digest::Whirlpool class

  Copyright (C) 2006 Akinori MUSHA

************************************************/

#include "digest.h"
#include "whirlpool-algorithm.h"
#include "whirlpool-portability.h"

static void WP_Update(WP_Struct * const, const unsigned char * const, size_t);

static rb_digest_metadata_t whirlpool = {
    RUBY_DIGEST_API_VERSION,
    WP_DIGEST_SIZE,
    WBLOCKBYTES, 
    sizeof(WP_Struct),
    (rb_digest_hash_init_func_t)WP_Init,
    (rb_digest_hash_update_func_t)WP_Update,
    (rb_digest_hash_finish_func_t)WP_Finalize,
};

static void
WP_Update(WP_Struct * const wp, const unsigned char * const data, size_t len)
{
    WP_Add(data, len * 8, wp);
}

void
Init_whirlpool()
{
    VALUE mDigest, cDigest_Base, cDigest_Whirlpool;

    rb_require("digest");

    mDigest = rb_path2class("Digest");
    cDigest_Base = rb_path2class("Digest::Base");

    cDigest_Whirlpool = rb_define_class_under(mDigest, "Whirlpool", cDigest_Base);

    rb_ivar_set(cDigest_Whirlpool, rb_intern("metadata"),
      Data_Wrap_Struct(rb_cObject, 0, 0, &whirlpool));
}
