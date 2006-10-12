/************************************************

  tiger_init.c - provides Digest::Tiger class

  $Author$

  Copyright (C) 2006 Akinori MUSHA

  $Id$

************************************************/

#include "digest.h"
#include "tiger.h"

static algo_t tiger = {
    TIGER_DIGEST_LENGTH,
    sizeof(tiger_state_t),
    (hash_init_func_t)tiger_init,
    (hash_update_func_t)tiger_update,
    (hash_finish_func_t)tiger_final,
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
