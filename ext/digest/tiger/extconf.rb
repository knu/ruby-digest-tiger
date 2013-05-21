require 'mkmf'

$defs << "-DHAVE_CONFIG_H"
$INCFLAGS << " -I$(srcdir)/.. -I$(hdrdir)/ruby"

have_header('ruby/digest.h')

$preload = %w[digest]

create_makefile('digest/tiger')
