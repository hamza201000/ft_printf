*This project has been created as part of the 42 curriculum by haghomar.*

# ft_printf

## Description

**ft_printf** is a reimplementation of the standard C `printf` function. The goal is to create a static library named `libftprintf.a` that provides the following function:

```c
int ft_printf(const char *format, ...);
```

The function writes formatted output to the standard output and returns the number of characters printed, or `-1` if an error occurs.

## Mandatory Part

This implementation covers the mandatory requirements from the project subject.

### Supported conversions

| Conversion | Output |
|------------|--------|
| `%c` | A single character |
| `%s` | A string |
| `%p` | A pointer address in hexadecimal |
| `%d` | A signed decimal integer |
| `%i` | A signed integer in decimal |
| `%u` | An unsigned decimal integer |
| `%x` | An unsigned integer in lowercase hexadecimal |
| `%X` | An unsigned integer in uppercase hexadecimal |
| `%%` | A literal `%` character |

### External requirements

- Use `malloc`, `free`, `write`, and variadic argument functions (`va_start`, `va_arg`, `va_end`, and `va_copy`) only when necessary.
- Do not implement the original `printf` buffer management.
- The library must be named `libftprintf.a`.
- The Makefile must contain `all`, `clean`, `fclean`, and `re` rules.
- The project must compile with `cc` and the flags `-Wall -Wextra -Werror`.

A copy of the official assignment is available in [`en.subject.pdf`](./en.subject.pdf).

## Instructions

### Compilation

```bash
make
```

This creates the static library:

```text
libftprintf.a
```

Available Makefile commands:

```bash
make        # Build the library
make clean  # Remove object files
make fclean # Remove object files and libftprintf.a
make re     # Rebuild the project from scratch
```

### Usage

Create a C program that includes the project header:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s: %d, %x, %p\n", "world", 42, 42, &main);
    return (0);
}
```

Compile and run it with the library:

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o test
./test
```

## Implementation

`ft_printf` processes the format string from left to right:

1. Print ordinary characters directly.
2. When `%` is encountered, dispatch to the matching conversion handler.
3. Add the number of printed characters to a counter.
4. Return the final counter.

The implementation uses:

- `va_list` and variadic functions to access the arguments.
- `write` for output.
- Recursive unsigned integer conversion for decimal and hexadecimal formats.
- Separate functions for characters, strings, signed numbers, pointers, unsigned numbers, and hexadecimal numbers.

## Testing

Compare `ft_printf` with the standard `printf` for both output and return values:

```c
#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int original;
    int ft_result;

    original = printf("%c %s %p %d %i %u %x %X %%\n", 'A', "42", &main, -42, 42, 42, 42, 42);
    ft_result = ft_printf("%c %s %p %d %i %u %x %X %%\n", 'A', "42", &main, -42, 42, 42, 42, 42);

    printf("standard printf returned: %d\n", original);
    ft_printf("ft_printf returned: %d\n", ft_result);
    return (0);
}
```

Test edge cases such as `INT_MIN`, `INT_MAX`, `UINT_MAX`, zero, `NULL`, empty strings, and a lone `%`.

## Key concepts to understand

These are the notions to master to code and defend this project:

- **Variadic functions**: `va_list`, `va_start`, `va_arg`, `va_end`, `va_copy`. How arguments are laid out on the stack/registers and why you must know the type of each argument in advance.
- **Default argument promotions**: why `char` and `short` are promoted to `int` when passed through `...`.
- **`write(2)`**: its return value, buffering vs. unbuffered output, why `write` is used instead of `printf`.
- **Number bases**: decimal vs. hexadecimal conversion, uppercase/lowercase digits.
- **Signed vs. unsigned integers**: two's complement, `INT_MIN` edge case, why `%u` and `%x` print `UINT_MAX` correctly for negative inputs.
- **Pointers**: `%p` formatting, `unsigned long` / `uintptr_t`, behaviour with `NULL` (`(nil)` on Linux, `0x0` on macOS).
- **Static libraries**: `ar rcs`, how `libftprintf.a` is built, Makefile rules (`$(NAME)`, `all`, `clean`, `fclean`, `re`), avoiding unnecessary relinking.
- **Header files**: include guards, prototypes, allowed includes.
- **Return value handling**: counting characters and propagating `-1` if `write` fails.

## Resources

### Documentation

- `man 3 printf`: official description of the `printf` family.
- `man 3 stdarg`: `va_start`, `va_arg`, `va_end`, `va_copy`.
- `man 2 write`: system call used for output.
- [GNU C Library: Variadic Functions](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html)
- [cppreference: `printf`](https://en.cppreference.com/w/c/io/fprintf)
- [cppreference: `va_arg`](https://en.cppreference.com/w/c/variadic/va_arg)
- [Wikipedia: Printf format string](https://en.wikipedia.org/wiki/Printf_format_string)
- [Wikipedia: Two's complement](https://en.wikipedia.org/wiki/Two%27s_complement)
- [Wikipedia: Hexadecimal](https://en.wikipedia.org/wiki/Hexadecimal)

### Articles and tutorials

- [Variadic functions in C (Learn-C / GeeksforGeeks)](https://www.geeksforgeeks.org/variadic-functions-in-c/)
- [Tutorialspoint: C Variable Arguments](https://www.tutorialspoint.com/cprogramming/c_variable_arguments.htm)
- [Unlocking the Mystery of va_list: Understanding Variable Arguments in C (Abdelhalim El Bouaami, Medium)](https://abdelhalimelbouaami.medium.com/unlocking-the-mystery-of-va-list-understanding-variable-arguments-in-c-a7b2323cf6d3)
- [The GNU C Library Reference Manual, 2.44 (PDF)](https://sourceware.org/glibc/manual/2.44/pdf/libc.pdf)
- [GNU Make Manual](https://www.gnu.org/software/make/manual/make.html)
- [`ar` command and static libraries](https://www.geeksforgeeks.org/static-vs-dynamic-libraries/)

### Use of AI
AI was used as a learning and writing assistant to help explain concepts and structure this README.

Exmples ai use :
- Explaining concepts: variadic functions, `va_list`, integer promotion, two's complement, number base conversion, static libraries.
- Answering my questions while I was coding and debugging (for example, the `INT_MIN` case and the `%p` output for `NULL`).
- Suggesting edge cases to test.
- Helping to structure and write this README.

Project code was written, tested, and understood by the author.
