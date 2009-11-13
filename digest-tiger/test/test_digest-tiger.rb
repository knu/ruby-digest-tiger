require 'test/unit'

begin
  require 'digest/tiger'
rescue LoadError
  require 'rubygems'
  require 'digest/tiger'
end

class TC_Digest_Tiger < Test::Unit::TestCase
  def cases
    [
     {
       :data => '',
       :hexdigest => '3293ac630c13f0245f92bbb1766e16167a4e58492dde73f3',
     }, {
       :data => 'The quick brown fox jumps over the lazy dog',
       :hexdigest => '6d12a41e72e644f017b6f0e2f7b44c6285f06dd5d2c5b075',
     }
    ]
  end

  def test_s_hexdigest
    cases.each { |h|
      assert_equal(h[:hexdigest], Digest::Tiger.hexdigest(h[:data]))
    }
  end
end
