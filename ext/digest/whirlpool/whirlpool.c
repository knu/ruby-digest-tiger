/************************************************

  whirlpool.c - provides Digest::Whirlpool class

  $Author$

  Copyright (C) 2006 Akinori MUSHA

  $Id$

************************************************/

#include "digest.h"
#include "whirlpool-algorithm.h"
#include "whirlpool-portability.h"

static void WP_Update(WP_Struct * const, const unsigned char * const, size_t);

static algo_t whirlpool = {
    WP_DIGEST_SIZE,
    sizeof(WP_Struct),
    (hash_init_func_t)WP_Init,
    (hash_update_func_t)WP_Update,
    (hash_finish_func_t)WP_Finalize,
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
