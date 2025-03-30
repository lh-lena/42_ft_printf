#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

/**
 * specifiers: cspdiuxX%
 * flags: ’-0.’ ’# +’
Specifier Effect of # Flag
%x	Adds leading 0x if the number is non-zero
%X	Adds leading 0X if the number is non-zero
%d, %i, %u, %s, %c	No effect

No effect: [c] -> '#' '+' ' ' '-' '.' '0'
No effect: [s] -> '#' '+' ' ' '-' '.' '0'
No effect: [d] -> '#' 
No effect: [i] -> '#' 
No effect: [u] -> '#' 

If the 0 and - flags both appear, the 0 flag is ignored.
If a precision is given with an integer conversion (d, i, o,
    u, x, and X), the 0 flag is ignored.
printf("%-08.3d", 1); 001     $
printf("%-08.3d"); 9551728 $ (random value)

 */

void test_d(void)
{
    // Right-align, minimum width 5 (default, no flag)
           // Output: |   42|
int i = 42;
ft_printf("%d\n", 0);
// ft_printf(" %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
// int org = printf("|%5d| |%-5d| |%+5d| |%-+5d| |%-+5d| |%05d| |%.3d| |%.d| |%5.3d|\n",i,i,i,i, i, i,i,i, i );

// int ft = ft_printf("|%5d| |%-5d| |%+5d| |%-+5d| |%-+5d| |%05d| |%.3d| |%.d| |%5.3d|\n",i,i,i,i, i, i,i,i, i );
// if (org == ft)
// {
//     ft_printf("OK\n");
//     printf("OK\n");
// }
// else
//     printf("KO\n");

// Left-align, minimum width 5 // Output: |42   |
// printf("|%-5d|\n", 42);      

// Right-align, minimum width 5 // Output: |  +42|
// printf("|%+5d|\n", 42);      

// Left-align, minimum width 5 // Output: |-42  |
// printf("|%-+5d|\n", -42);      
// printf("|%-+5d|\n", -42);      // Output: |-42  |

// Zero-pad to width 5
// printf("|%05d|\n", 42);      // Output: |00042|

// Specify precision (at least 3 digits)
// printf("|%.3d|\n", 42);      // Output: |042|
// printf("|%.d|\n", 42);      // Output: |42|

// Width 5 and precision 3 (note padding for width)
// printf("|%5.3d|\n", 42);     // Output: |  042|
}

void test_u(void)
{
    // Width 5, zero-padded
printf("|%05u|\n", 123);     // Output: |00123|

// Width 5, left-aligned
printf("|%-5u|\n", 123);     // Output: |123  |

// Precision 3 (at least 3 digits)
printf("|%.3u|\n", 123);     // Output: |123|

// Width 5, precision 3
printf("|%5.3u|\n", 123);    // Output: |  123|
}

void test_x(void)
{
    // Width 5, zero-padded
printf("|%05x|\n", 255);     // Output: |000ff|

// Width 5, left-aligned
printf("|%-5x|\n", 255);     // Output: |ff   |

// Precision 3 (at least 3 digits)
printf("|%.3x|\n", 255);     // Output: |0ff|

// Width 5, precision 3
printf("|%5.3x|\n", 255);    // Output: | 0ff|

// Use # flag to add leading 0x for hex notation
printf("|%#5x|\n", 255);     // Output: | 0xff|

}

void test_s()
{

// Width 10
printf("|%10s|\n", "Hello");   // Output: |     Hello|

// Left-align with width 10
printf("|%-10s|\n", "Hello");  // Output: |Hello     |

// Left-align with width 10 Precision 3
printf("|%-10.3s|\n", "Hello");  // Output: |Hel       |

// Precision 3 (limits to 3 characters)
printf("|%.3s|\n", "Hello");   // Output: |Hel|

// Width 10, precision 3
printf("|%10.3s|\n", "Hello"); // Output: |       Hel|


}

void test_c()
{
    ft_printf("|%c|\n", 'A');       // Output: |A|
    printf("|%#c|\n", 'A');      // Output: |A|
    printf("|%+c|\n", 'A');      // Output: |A|
    printf("|% c|\n", 'A');      // Output: |A|
    // Width 5
    printf("|%5c|\n", 'A');       // Output: |    A|

    // Left-align with width 5
    printf("|%-5c|\n", 'A');      // Output: |A    |

}

int main()
{
    // printf("%d %#x; %d %#x",16,17);
    // 17 0x11; 16 0x10
//     printf("%4X\n",3);
//     printf("%04X\n",3);
//     printf("%%\n");
//     printf("%#x\n", 17); // 0x11
// printf("%#3X\n", 17); //0X11
// printf("%#3f\n", 1.42); //1.420000
// printf("%#A\n", 1.42); //0X1.6B851EB851EB8P+0
// // printf("%#"); // incomplete format specifier
// printf("%#o\n", 0); // Output: "012" (adds leading zero)
// // printf("%#p\n", 0); //  results in undefined behavior with 'p' conversion specifier
// printf("%#f\n", 10.0); // Output: "10.000000"
// printf("%#.0f\n", 10.0); // Output: "10." (shows the decimal point even if no precision)

// ft_printf("%-+05i", 1234);

test_d();

// test_u();

// test_x();

// test_s();
// test_c();


    return 0;
}

/* #include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main()
{
	ft_printf("%%");
	printf("%%");

	int x = ft_printf("My: 'c' = %c\n", 'a');
	int y = printf("Or: 'c' = %c\n", 'b');

	printf("Count 'c': my = %i, org = %i\n", x, y);

	int a = ft_printf("My: 's' = %s\n", "my_string");
	int b = printf("Or: 's' = %s\n", "or_string");
	
	printf("Count 's': my = %i, org = %i\n", a, b);

	int q = ft_printf("My: 'i' = %i%ii%i\n", 3, 2, -3);
	int w = printf("Or: 'i' = %i%ii%i\n", 3, 2, -3);
	
	printf("Count 'i': my = %i, org = %i\n", q, w);

	// int e = ft_printf("My: 'd' =  %d %d %d %d %d %d %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	// int r = printf("Or: 'd' =  %d %d %d %d %d %d %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);


	int n = ft_printf("My: 'u' = %u%uu%u\n", 1, 2, 3);
	int m = printf("Or: 'u' = %u%uu%u\n", 1, 2, 3);

	printf("Count 'd': my = %i, org = %i\n", n, m);

	int t = ft_printf("My: 'x' = %x\n", -1234);
	int o = printf("Or: 'x' = %x\n", -1234);

	printf("Count 'x': my = %i, org = %i\n", t, o);

	int f = ft_printf("My: 'X' = %X\n", -1234);
	int g = printf("Or: 'X' = %X\n", -1234);

	printf("Count 'X': my = %i, org = %i\n", f, g);

	char *p = NULL;
	int i = 0;
	int h = ft_printf("My: 'p' = %p %p \n", p, &i);
	int j = printf("Or: 'p' = %p %p \n", p, &i);
	
	printf("Count: my = %i, org = %i\n", h, j);
	
	
	printf("Or: NULL %s NULL \n", ((char *)0));
	ft_printf("My: NULL %s NULL \n", ((char *)0));

	return (0);


}
 */