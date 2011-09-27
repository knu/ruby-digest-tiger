require 'mkmf'

$defs << "-DHAVE_CONFIG_H"
$INCFLAGS << " -I$(srcdir)/.. -I$(hdrdir)/ruby"

$preload = %w[digest]

create_makefile('digest/whirlpool')
