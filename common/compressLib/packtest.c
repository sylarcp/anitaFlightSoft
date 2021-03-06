#include <stdio.h>
#include <stdlib.h>
#include "compresslib.h"

int main(int argc, char* argv[]){
     short nwords;
     int packedbytes;
     unsigned short testword[65536];
     unsigned int testcode[65536];
     unsigned char packed[200000];
     short i;
     if (argc!=2){
	  fprintf(stderr,"Usage: packtest <1/2 number of words to code and pack>");
	  exit(-1);
     }
     sscanf(argv[1],"%hu",&nwords);
     for (i=0;i<2*nwords+1;i++){
	  testword[i]=bifurcate((short)(i-nwords)); 
	  testcode[i]=fibonacci(testword[i]);
     }
     packedbytes=codepack(2*nwords+1,testcode,packed);
     printf("%i\n",packedbytes);
     for (i=0;i<packedbytes;i++){
	  printf("%02x\n",packed[i]);
     }
}
