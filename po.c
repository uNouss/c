#include <stdio.h>

void main(){
  int c[2] = {10,20};
  int* p = c;
  char mesg[6] = "hello\0";
  char* s = mesg;

  
  printf("&c=Ox%x p=0x%x\n", &c, p);
  *(p) = *(p) + *(p+1);
  printf("c=%d *p=%d\n", c[0], *(p));
  mesg[1] = 'a';
  *(s+2) = 'L';
  printf("c=%s s =%c\n", mesg, *(s+1));
}
