# coding: utf-8
lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require 'digest/tiger/version'

Gem::Specification.new do |spec|
  spec.name          = "digest-tiger"
  spec.version       = Digest::Tiger::VERSION
  spec.authors       = ["Akinori MUSHA"]
  spec.email         = ["knu@idaemons.org"]
  spec.description   = %q{This is a Digest module implementing the Tiger hashing algorithm.
The size of a Tiger hash value is 192 bits.
}
  spec.summary       = %q{A Digest module implementing the Tiger hashing algorithm}
  spec.homepage      = "https://github.com/knu/ruby-digest-extra"
  spec.license       = "BSD"

  spec.files         = `git ls-files`.split($/)
  spec.executables   = spec.files.grep(%r{^bin/}) { |f| File.basename(f) }
  spec.test_files    = spec.files.grep(%r{^(test|spec|features)/})
  spec.extensions    = ["ext/digest/tiger/extconf.rb"]
  spec.required_ruby_version = "~> 2.2"

  spec.extra_rdoc_files = [
    "LICENSE",
    "README.rdoc"
  ]

  spec.add_development_dependency "bundler", "~> 1.3"
  spec.add_development_dependency "rake"
end
