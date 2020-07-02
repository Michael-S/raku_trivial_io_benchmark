# Copyright (c) 2020, Mike Swierczek, released under the Apache 2 License.

# Read a 100 million bytes file and print out the last 10 bytes as integers. 
# This version reads 1 byte at a time, and is painfully slow.

my $fh = open "junk.bytes", :r, :bin;
my int $count = 0;
my Buf $x;
while $count < 99_999_990 {
  $x := $fh.read(1);
  $count++;
}
my @lastTen := [];
while @lastTen.elems < 10 {
  $x := $fh.read(1);
  if ($x.bytes == 0) {
    last;
  }
  @lastTen.append($x.pop());
}
say @lastTen;    
