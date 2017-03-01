/* Static function to get current sec and usec.  */
int system_uptime (struct timeval *tv, struct timezone *tz)
{
  static unsigned long prev = 0;
  static unsigned long wraparound_count = 0;
  u_int32_t uptime;
  static long base = 0;
  static long offset = 0;
  long leap;
  long diff;
  u_int32_t j;

  j = jiffies;
  uptime = j / HZ;  /*change jiffies to seconds */

  /* Check for wraparound. */
  if (prev > j)
	wraparound_count++;
  
  /* System uptime.  */
  uptime = wraparound_count * WRAPAROUND_VALUE + uptime;
  prev = uptime;	   
  
  /* Get tv_sec and tv_usec.  */
  jiffies_to_timeval(jiffies,tv);

  /* Deffernce between gettimeofday sec and uptime.  */
  leap = tv->tv_sec - uptime;

  /* Remember base diff for adjustment.  */
  if (! base)
	base = leap;

  /* Basically we use gettimeofday's return value because it is the
	 only way to get required granularity.	But when diff is very
	 different we adjust the value using base value.  */
  diff = (leap - base) + offset;

  /* When system time go forward than 2 sec.  */
  if (diff > 2 || diff < -2)
	offset -= diff;

  /* Adjust second.  */
  tv->tv_sec += offset;

  return 0;
}
