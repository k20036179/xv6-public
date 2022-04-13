#include "types.h"
#include "stat.h"
#include "user.h"
#include "mmu.h"

int
main(int argc, char *argv[])
{
  printf(1, "\nStart of munprotect test\n");

  int *value = (int*) sbrk(sizeof(int));

  printf(1, "\nCreated Value Address\n");

  *value = 100;

  printf(1, "\nInitial Value: %d\n", *value);

  mprotect((void*) value, 1);
  munprotect((void*) value, 1);

  printf(1, "\nRan munprotect. Now trying to change the value. (Should work.)\n");

  *value = 5;

  printf(1, "\nOld Value: 100. New Value: %d.\n", *value);

  exit();
}