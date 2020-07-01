#include<stdio.h>
// Copyright (c) 2020, Mike Swierczek, released under the Apache 2 License.

// Read a 100 million bytes file and print out the last 10 bytes as integers. 
// This is the C version, reading 64 byte at a time.  It may not be good /
// idiomatic C, I haven't written it professionally in a long time.

unsigned char buffer[64 * 1024];

int main() {
int counter;
FILE *ptr_myfile;
int loopmax = 100000000 / sizeof(buffer);
int last_read_length = 100000000 - (loopmax * sizeof(buffer));

ptr_myfile=fopen("junk.bytes","rb");
if (!ptr_myfile) {
printf("Unable to open file!");
return 1;
}
for (counter=0; counter <= loopmax; counter++) {
  fread(&buffer,sizeof(buffer),1,ptr_myfile);
}
fread(&buffer,last_read_length,1,ptr_myfile);
printf("[");
for (counter = last_read_length - 10; counter < last_read_length; counter++) {
  printf("%u", buffer[counter]);
  if (counter < last_read_length -1) {
    printf(", ");
  }
}
printf("]\n");
fclose(ptr_myfile);
return 0;
}
