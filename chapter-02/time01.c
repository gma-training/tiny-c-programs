#include <stdio.h>
#include <time.h>

int main()
{
  time_t now;

  time(&now);
  printf("The computer thinks it's %ld\n", now);
  printf("I prefer to call it %s", ctime(&now));

  return(0);
}
