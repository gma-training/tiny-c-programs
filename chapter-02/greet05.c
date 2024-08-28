#include <stdio.h>
#include <time.h>

int moon_phase_index(int year, int month, int day)
{
  int d, g, e;

  d = day;
  if (month == 2)
    d += 31;
  else if (month > 2)
    d += 59 + (month - 3) * 30.6 + 0.5;
  g = (year - 1900) % 19;
  e = (11 * g + 29) % 30;
  if (e == 25 || e == 24)
    ++e;
  return ((((e + d) * 6 + 5) % 177) / 22 & 7);
}

char *moon_phase(struct tm *clock)
{
  char *phase[8] = {
    "waxing crescent",
    "at first quarter",
    "waxing gibbous",
    "full",
    "waning gibbous",
    "at last quarter",
    "waning crescent",
    "new"
  };

  int year = clock->tm_year + 1900;
  int month = clock->tm_mon;
  int day = clock->tm_mday;
  return phase[moon_phase_index(year, month, day)];
}

int main(int argc, char *argv[])
{
  time_t now;
  struct tm *clock;
  char time_string[64];

  time(&now);
  clock = localtime(&now);

  strftime(time_string, 64, "It's %R on %A %B %d, %Y", clock);

  printf("Greetings");
  if (argc > 1)
    printf(", %s", argv[1]);
  printf("!\n%s (moon: %s)\n", time_string, moon_phase(clock));

  return(0);
}
