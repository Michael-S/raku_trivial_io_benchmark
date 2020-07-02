# Copyright (c) 2020, Mike Swierczek, released under the Apache 2 License.

# Read a 100 million bytes file and print out the last 10 bytes as integers. 
# This version reads the file in 64k chunks.

my $fh := open "junk.bytes", :r, :bin;
my \buffsize = (64 * 1024);
my \loopmax = 100_000_000 div buffsize;
my int $loopcount = 0;
while $loopcount < loopmax {
  my $x := $fh.read(buffsize);
  $loopcount++;
}
my $x := $fh.read(buffsize);
my @lastTen = [];
for 1..10 {
  @lastTen.prepend($x.pop());
}
say @lastTen;
