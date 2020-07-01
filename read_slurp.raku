# Copyright (c) 2020, Mike Swierczek, released under the Apache 2 License.

# Read a 100 million bytes file and print out the last 10 bytes as integers. 
# This version reads it all at once.

my $fh = open "junk.bytes", :r, :bin;
my $x = $fh.slurp;
say "Read " ~ $x.bytes ~ ".";
my @lastTen = [];
for 1..10 {
  @lastTen.prepend($x.pop());
}
say @lastTen;

