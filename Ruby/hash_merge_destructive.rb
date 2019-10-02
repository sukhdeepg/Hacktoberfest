# destructive hash merging is one of my favorite features of ruby
# because the syntax is so clean

hashA = { "foo" => "bar", "bin" => "baz" }
hashB = { "a" => 1, "b" => 2, "foo" => "you" }

hashA.merge!(hashB)
puts hashA # {"foo"=>"you", "bin"=>"baz", "a"=>1, "b"=>2}

hashA = { "foo" => "bar", "bin" => "baz" }
hashB = { "a" => 1, "b" => 2, "foo" => "you" }

hashB.merge!(hashA)
puts hashB # {"a"=>1, "b"=>2, "foo"=>"bar", "bin"=>"baz"}
