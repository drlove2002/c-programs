#include <stdio.h>

int hcf(a, b)
{
  if (!(a % b))
    return b;
  else
    return hcf(b, a % b);
}

int main()
{
  int x, y, gcd, lcm;

  printf("Enter two integers\n> ");
  scanf("%d%d", &x, &y);

  gcd = hcf(x, y);
  lcm = (x * y) / gcd;

  printf("GCD of %d and %d = %d\n", x, y, gcd);
  printf("LCM of %d and %d = %d\n", x, y, lcm);

  return 0;
}
