# Digest::Tiger - Ruby interface to the Tiger message digest algorithm

## Summary

Digest::Tiger is a Ruby library for calculating message digests using
the Tiger algorithm.  The library interface conforms to the standard
Digest API.

More information about Tiger:

- http://en.wikipedia.org/wiki/Tiger_%28hash%29
- http://www.cs.technion.ac.il/~biham/Reports/Tiger/

## Requirements

- Ruby 2.2 or later

## Usage

In Gemfile:

    gem "digest-tiger"

In your ruby code:

    require "digest"

    p Digest::Tiger.hexdigest("")	# The module is auto-loaded

## License

See the file LICENSE.
