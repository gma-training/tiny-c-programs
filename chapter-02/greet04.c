#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])
{
  time_t now;
  struct tm *clock;
  char time_string[64];

  time(&now);
  clock = localtime(&now);

  strftime(time_string, 64, "It's %R on %A %B %d, %Y%n", clock);

  printf("Greetings");
  if (argc > 1)
    printf(", %s", argv[1]);
  printf("!\n%s", time_string);

  return(0);
}
