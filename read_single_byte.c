#include<stdio.h>
// Copyright (c) 2020, Mike Swierczek, released under the Apache 2 License.

// Read a 100 million bytes file and print out the last 10 bytes as integers. 
// This is the C version, reading 1 byte at a time.  It may not be good /
// idiomatic C, I haven't written C professionally in a long time.

int main() {
int counter;
FILE *ptr_myfile;
unsigned char c;

ptr_myfile=fopen("junk.bytes","rb");
if (!ptr_myfile) {
  printf("Unable to open file!");
  return 1;
}
for ( counter=0; counter <= 99999989; counter++) {
  fread(&c,sizeof(c),1,ptr_myfile);
}
printf("[");
for ( counter=0; counter <= 9; counter++) {
  fread(&c,sizeof(c),1,ptr_myfile);
  printf("%u", c);  
  if (counter < 9) {
    printf(", ");
  }
}
printf("]\n");
fclose(ptr_myfile);
return 0;
}
