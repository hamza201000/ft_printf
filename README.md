*This project has been created as part of the 42 curriculum by haghomar.*

# ft_printf

## Description

**ft_printf** is a re-implementation of the standard C `printf` function. The goal is to build a static library, `libftprintf.a`, containing a function with the following prototype:

```c
int ft_printf(const char *format, ...);
```

It writes formatted output to the standard output and returns the number of characters printed (or `-1` on error), exactly like the original `printf`.

The project teaches how **variadic functions** work in C (`<stdarg.h>`), how to structure a program around a simple **dispatcher**, and how to convert numbers to text in different bases without relying on the standard library.

### Supported conversions

| Specifier | Description                                             |
|-----------|---------------------------------------------------------|
| `%c`      | A single character                                      |
| `%s`      | A string (prints `(null)` if the pointer is `NULL`)     |
| `%p`      | A pointer address in hexadecimal (`0x...`, `(nil)` if `NULL`) |
| `%d`      | A signed decimal integer                                |
| `%i`      | A signed integer (decimal)                              |
| `%u`      | An unsigned decimal integer                             |
| `%x`      | An unsigned integer in lowercase hexadecimal            |
| `%X`      | An unsigned integer in uppercase hexadecimal            |
| `%%`      | A literal percent sign                                  |


## Instructions

### Compilation

The project is compiled with `cc` and the flags `-Wall -Wextra -Werror`.

```bash
make        # builds libftprintf.a
make clean  # removes object files
make fclean # removes object files and libftprintf.a
make re     # fclean + make
```

### Usage in your own program

```c
#include "ft_printf.h"

int main(void)
{
    int len;

    len = ft_printf("Hello %s! You are number %d (hex: %x)\n", "world", 42, 42);
    ft_printf("Printed %d characters\n", len);
    return (0);
}
```

Compile and link with the library:

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o test
./test
```

### Testing

Compare your output and return value against the real `printf`:

```c
int a = printf("%p|%s|%c|%u|%X\n", &a, NULL, 'x', 4294967295u, 255);
int b = ft_printf("%p|%s|%c|%u|%X\n", &b, NULL, 'x', 4294967295u, 255);
```

Edge cases worth testing: `INT_MIN`, `INT_MAX`, `UINT_MAX`, `0`, `NULL` string, `NULL` pointer, empty string, a lone `%` at the end of the format string, and `%%`.

## Algorithm and data structure

### Algorithm: single-pass parsing with a dispatcher

`ft_printf` reads the format string **once, from left to right**:

1. If the current character is not `%`, it is written as is.
2. If it is `%`, the next character is the **conversion specifier**. A dispatch function (`if / else if` chain or a `switch`) calls the matching handler (`ft_putchar`, `ft_putstr`, `ft_putnbr`, `ft_putunsigned`, `ft_puthex`, `ft_putptr`...).
3. Every handler **returns the number of characters it wrote**. `ft_printf` adds these values into a single counter that is returned at the end.

**Why this approach?**

- It is simple, readable, and respects the 42 Norm (small functions, few lines each).
- Time complexity is **O(n)** with n = length of the output; the format string is never scanned twice.
- Adding a new specifier only requires one new handler and one new line in the dispatcher, which keeps the code easy to extend (e.g. for the bonus).
- Returning the count from each handler avoids global variables and avoids a second pass to compute the length.

### Number conversion: recursion on the base

Integers are converted with a **recursive function** that divides the number by the base:

```c
// idea (unsigned, base 16)
if (n >= base)
    count += put_base(n / base, base, charset);
count += write(1, &charset[n % base], 1);
```

- Digits come out in the correct order without needing to reverse a buffer.
- The same function handles base 10 (`%u`) and base 16 (`%x`, `%X`). Only the charset changes: `"0123456789"`, `"0123456789abcdef"` or `"0123456789ABCDEF"`.
- For `%d` / `%i`, the value is cast to `long` (or handled as a special case) so that `INT_MIN` (-2147483648) can be negated safely without overflow.
- For `%p`, the pointer is cast to `unsigned long` (64 bits) before conversion, so the whole address is preserved.

### Data structure

No complex data structure is needed:

- `va_list` (from `<stdarg.h>`) to walk through the variable arguments.
- An `int` counter for the number of printed characters.
- Constant strings (charsets) for digit conversion.

A buffer was deliberately **not** used: calling `write` directly keeps the code simple and avoids memory management. The trade-off is more system calls; a buffered version would be faster but is not required by the subject.

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

AI (Claude, chatgpt) was used as a **learning and writing assistant**, not as a code generator for the project itself. Update this list so it reflects what you really did:

- Explaining concepts: variadic functions, `va_list`, integer promotion, two's complement, number base conversion, static libraries.
- Answering my questions while I was coding and debugging (for example, the `INT_MIN` case and the `%p` output for `NULL`).
- Suggesting edge cases to test.
- Helping to structure and write this README.

All the code was written, tested, and understood by me, and I am able to explain every part of it.