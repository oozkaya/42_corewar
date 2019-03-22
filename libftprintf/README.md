# Printf Project

## Project Overview
ft_printf is a 42 Project that aims to mimic libc printf function

>Basics, requested from subject:
* parsing for flags, field_width, precision, length_modifier
* parsing for conversion specifier
* displaying UTF-8 characters (%C and %S)
* computing unsigned numbers in base 2 (%b), 8 (%o, %O), 10 (%u, %U) and 16 (%x, %X)
* displaying signed numbers (%d, %D, %i)
* displaying pointer address (%p)

>Bonus:
* wildcard_length_modifier (%*) : replaces precision and field_width with parameter in va_list ap
* handles colors
* handles multi fd (use ft_dprintf(int fd, char const format, ...) instead of ft_printf)
* returns the string only with ft_asprintf
* mades variadics printf family functions like `vprintf`, `vdprintf`, and `vasprinft`

```
int	ft_printf(const char *str, ...);
int	ft_dprintf(int fd, const char *str, ...);
int	ft_asprintf(char **str, const char *fmt, ...);

int	ft_vprintf(const char *str, va_list ap);
int	ft_vdprintf(int fd, const char *str, va_list ap);
int	ft_vasprintf(char **str, const char *fmt, va_list ap);
```

## Sources
https://linux.die.net/man/3/printf

## Installation & Tests
```
$> make
```
libftprintf.a is created. Then:
```
$> gcc example_main.c -L. -lftprintf -Iincludes_folder
```

## How to use examples
```
#include "ft_printf.h"

ft_printf("%sstring : %s, dec : %d, binary nb: %b, octal nb: %o, unsigned nb: %u, hexadecimal nb: %x, with uppercase: %X%s\n", F_GREEN, "42", 42, 42, 42, 42, 42, 42, F_NO);

ft_printf("%S\n", L"잘했지 ?");
```

## Resulting outputs
```
$> string : 42, dec : 42, binary nb: 101010, octal nb: 52, unsigned nb: 42, hexadecimal nb: 2a, with uppercase: 2A

$> 잘했지 ?
```