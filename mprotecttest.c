#include "types.h"
#include "stat.h"
#include "user.h"
#include "mmu.h"

int
main(int argc, char *argv[])
{

  int *value = (int*) sbrk(sizeof(int));

  *value = 100;

  printf(1, "\nInitial Value: %d\n", *value);

  mprotect((void*) value, 1);

  printf(1, "\nRan mprotect. Now trying to change the value. (Should trap and kill the process!)\n");

  *value = 5;

  printf(1, "\nShould not print this.\n");
  
  exit();
}