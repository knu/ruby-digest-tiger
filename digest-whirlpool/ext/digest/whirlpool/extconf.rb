# $Id$

require 'mkmf'

$defs << "-DHAVE_CONFIG_H"
$INCFLAGS << " -I$(srcdir)/.."

$preload = %w[digest]

create_makefile('digest/whirlpool')
