#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

/**
 * specifiers: cspdiuxX%
 * flags: ’-0.’ ’# +’
 */

int i = 42;
int d = 22;
unsigned int u = 123;
unsigned int x = 255;
char *s = "Hello";
char c = 'A';

void test_d(void)
{
	int org = printf("|%5d| |%-5d| |%+5d| |%-+5d| |%-+5d| |%05d| |%2.3d| |%.d| |%5.1d| |%-+5d|\n",
		d,d,d,d,d,d,d,d,d ,0);

	int ft = ft_printf("|%5d| |%-5d| |%+5d| |%-+5d| |%-+5d| |%05d| |%2.3d| |%.d| |%5.1d| |%-+5d|\n",
		d,d,d,d,d,d,d,d,d ,0);
	if (org == ft)
	{
		ft_printf("OK\n");
		printf("OK\n");
	}
	else
		printf("KO\n");
}

void	test_i(void)
{
	ft_printf("Test i\n");
	int org = printf("|%5i| |%-5i| |%+5i| |%-+5i| |%-+5i| |%05i| |%.3i| |%.i| |%5.3i| |%-+5i|\n",
		i,i,i,i, i, i,i,i, i ,0);

	int ft = ft_printf("|%5i| |%-5i| |%+5i| |%-+5i| |%-+5i| |%05i| |%.3i| |%.i| |%5.3i| |%-+5i|\n",
		i,i,i,i, i, i,i,i, i ,0);
	if (org == ft)
	{
		ft_printf("OK\n");
		printf("OK\n");
	}
	else
		printf("KO\n");
}

void test_u(void)
{
	ft_printf("Test u\n");

	int org = printf("|%5u| |%-5u| |%+5u| |%-+5u| |%-+5u| |%05u| |%5.2u| |%.u| |%5.3u| |%-+5u|\n",
		u,u,u,u,u,u,u,u,u,0);

	int ft = ft_printf("|%5u| |%-5u| |%+5u| |%-+5u| |%-+5u| |%05u| |%5.2u| |%.u| |%5.3u| |%-+5u|\n",
		u,u,u,u,u,u,u,u,u,0);
	if (org == ft)
	{
		ft_printf("OK\n");
		printf("OK\n");
	}
	else
		printf("KO\n");
}

void test_x(void)
{
	ft_printf("Test x\n");

	int org = printf("|%5x| |%-5x| |%+5x| |%-+5x| |%-+5x| |%05x| |%.3x| |%.x| |%5.3x| |%-+5x|\n",
		x,x,x,x,x,x,x,x,x,0);

	int ft = ft_printf("|%5x| |%-5x| |%+5x| |%-+5x| |%-+5x| |%05x| |%.3x| |%.x| |%5.3x| |%-+5x|\n",
		x,x,x,x,x,x,x,x,x,0);
	if (org == ft)
	{
		ft_printf("OK\n");
		printf("OK\n");
	}
	else
		printf("KO\n");
}

void test_s()
{
	ft_printf("Test s\n");

	int org = printf("|%5s| |%-5s| |%+5s| |%-+5s| |%-+5s| |%05s| |%.3s| |%.s| |%5.3s| |%-10s|\n",
		s,s,s,s,s,s,s,s,s,s);

	int ft = ft_printf("|%5s| |%-5s| |%+5s| |%-+5s| |%-+5s| |%05s| |%.3s| |%.s| |%5.3s| |%-10s|\n",
		s,s,s,s,s,s,s,s,s,s);
	if (org == ft)
	{
		ft_printf("OK\n");
		printf("OK\n");
	}
	else
		printf("KO\n");
}

void test_p()
{
	ft_printf("Test p\n");
	int org = printf("|%5p| |%-5p| |%+5p| |%-+5p| |%-+5p| |%05p| |%.3p| |%.p| |%20.15p| |%-10p|\n",
		s,s,s,s,s,s,s,s,s,s, s);

	int ft = ft_printf("|%5p| |%-5p| |%+5p| |%-+5p| |%-+5p| |%05p| |%.3p| |%.p| |%20.15p| |%-10p|\n",
		s,s,s,s,s,s,s,s,s,s, s);
	if (org == ft)
	{
		ft_printf("OK\n");
		printf("OK\n");
	}
	else
		printf("KO\n");
}

void test_c()
{
	ft_printf("Test c\n");
	int org = printf("|%p| |%5c| |%-5c| |%+5c| |%-+5c| |%-+5c| |%05c| |%.3c| |%.c| |%5.3c| |%-10c|\n",
		c, c,c,c,c,c,c,c,c,c,c);

	int ft = ft_printf("|%p| |%5c| |%-5c| |%+5c| |%-+5c| |%-+5c| |%05c| |%.3c| |%.c| |%5.3c| |%-10c|\n",
		c,c,c,c,c,c,c,c,c,c);
	if (org == ft)
	{
		ft_printf("OK\n");
		printf("OK\n");
	}
	else
		printf("KO\n");


}

void o_test()
{
	ft_printf("Flag 0\n");
	// int ft = ft_printf(" %09i %010i %011i %012i %013i %014i %015i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	// int org = printf(" %09i %010i %011i %012i %013i %014i %015i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

	// if (org == ft)
	// {
	// 	ft_printf("OK\n");
	// 	printf("OK\n");
	// }
	// else
		// printf("KO\n");

	// 	printf(" %04d \n", -14);
	// ft_printf(" %04d \n", -14);
	// printf(" %05d \n", -15);
	// ft_printf(" %05d \n", -15);
	printf(" %06d \n", -16);
	ft_printf(" %06d \n", -16);
	printf(" %+d\n", -10);
	ft_printf(" %+d\n", -10);
	// printf(" %011d ", LONG_MAX);
	// ft_printf(" %011d ", LONG_MAX);
	// printf(" %013d \n", UINT_MAX);
	// ft_printf(" %013d \n", UINT_MAX);
}

void	dot_test()
{

}

int main()
{

// test_d();

// test_i();
// test_u();

// test_x();
// test_p();
// test_s();
// test_c();

o_test();


    return 0;
}

// #include "ft_printf.h"
// #include <stdio.h>
// #include <limits.h>

// int	main()
// {
// 	ft_printf("%%");
// 	printf("%%");

// 	int x = ft_printf("My: 'c' = %c\n", 'a');
// 	int y = printf("Or: 'c' = %c\n", 'b');

// 	printf("Count 'c': my = %i, org = %i\n", x, y);

// 	int a = ft_printf("My: 's' = %s\n", "my_string");
// 	int b = printf("Or: 's' = %s\n", "or_string");
	
// 	printf("Count 's': my = %i, org = %i\n", a, b);

// 	int q = ft_printf("My: 'i' = %i%ii%i\n", 3, 2, -3);
// 	int w = printf("Or: 'i' = %i%ii%i\n", 3, 2, -3);
	
// 	printf("Count 'i': my = %i, org = %i\n", q, w);

// 	// int e = ft_printf("My: 'd' =  %d %d %d %d %d %d %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
// 	// int r = printf("Or: 'd' =  %d %d %d %d %d %d %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);


// 	int n = ft_printf("My: 'u' = %u%uu%u\n", 1, 2, 3);
// 	int m = printf("Or: 'u' = %u%uu%u\n", 1, 2, 3);

// 	printf("Count 'd': my = %i, org = %i\n", n, m);

// 	int t = ft_printf("My: 'x' = %x\n", -1234);
// 	int o = printf("Or: 'x' = %x\n", -1234);

// 	printf("Count 'x': my = %i, org = %i\n", t, o);

// 	int f = ft_printf("My: 'X' = %X\n", -1234);
// 	int g = printf("Or: 'X' = %X\n", -1234);

// 	printf("Count 'X': my = %i, org = %i\n", f, g);

// 	char *p = NULL;
// 	int i = 0;
// 	int h = ft_printf("My: 'p' = %p %p \n", p, &i);
// 	int j = printf("Or: 'p' = %p %p \n", p, &i);
	
// 	printf("Count: my = %i, org = %i\n", h, j);
	
	
// 	printf("Or: NULL %s NULL \n", ((char *)0));
// 	ft_printf("My: NULL %s NULL \n", ((char *)0));

// 	return (0);


// }


