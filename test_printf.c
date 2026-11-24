/*
** test_printf.c
** Tests ft_printf (%c %d %s) against the real printf.
**
** Compile (adapt to your project):
**   cc -Wall -Wextra -Wno-format -Wno-format-security test_printf.c libftprintf.a -o test_printf
**   ./test_printf
**
** If you have no library, compile your sources directly:
**   cc -Wno-format test_printf.c ft_printf.c <your other .c files> -o test_printf
*/

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <fcntl.h>
#include "ft_printf.h"

// int ft_printf(const char *format, ...); /* change if your prototype differs */

#define BUF_SIZE 70000
#define TMP_FILE "/tmp/ft_printf_test_output.txt"

static int g_pass = 0;
static int g_fail = 0;

/* Runs `call` with stdout redirected to a file, then loads it into buf/len */
#define CAPTURE(buf, len, call)                                       \
	do                                                                \
	{                                                                 \
		fflush(stdout);                                               \
		int _save = dup(1);                                           \
		int _fd = open(TMP_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0600); \
		dup2(_fd, 1);                                                 \
		close(_fd);                                                   \
		call;                                                         \
		fflush(stdout);                                               \
		dup2(_save, 1);                                               \
		close(_save);                                                 \
		_fd = open(TMP_FILE, O_RDONLY);                               \
		len = (int)read(_fd, buf, BUF_SIZE - 1);                      \
		if (len < 0)                                                  \
			len = 0;                                                  \
		buf[len] = '\0';                                              \
		close(_fd);                                                   \
	} while (0)

#define TEST(...)                                                           \
	do                                                                      \
	{                                                                       \
		static char _b1[BUF_SIZE], _b2[BUF_SIZE];                           \
		int _r1, _r2, _l1, _l2;                                             \
		CAPTURE(_b1, _l1, _r1 = printf(__VA_ARGS__));                       \
		CAPTURE(_b2, _l2, _r2 = ft_printf(__VA_ARGS__));                    \
		if (_r1 == _r2 && _l1 == _l2 && memcmp(_b1, _b2, _l1) == 0)         \
		{                                                                   \
			g_pass++;                                                       \
			fprintf(stderr, "\033[32m[OK]\033[0m   %s\n", #__VA_ARGS__);    \
		}                                                                   \
		else                                                                \
		{                                                                   \
			g_fail++;                                                       \
			fprintf(stderr, "\033[31m[FAIL]\033[0m %s\n", #__VA_ARGS__);    \
			fprintf(stderr, "   printf    (ret=%d): [%.200s]\n", _r1, _b1); \
			fprintf(stderr, "   ft_printf (ret=%d): [%.200s]\n", _r2, _b2); \
		}                                                                   \
	} while (0)

static void section(const char *name)
{
	fprintf(stderr, "\n=== %s ===\n", name);
}

int main(void)
{
	/* ---------------------------------------------------------- */
	section("NO CONVERSION");
	TEST("");
	TEST("Hello world");
	TEST("Hello world\n");
	TEST("   spaces   and\ttabs\n");
	TEST("a");

	/* ---------------------------------------------------------- */
	section("%c");
	TEST("%c", 'a');
	TEST("%c", 'Z');
	TEST("%c", '0');
	TEST("%c", ' ');
	TEST("%c", '\n');
	TEST("%c", '\t');
	TEST("%c", '\0'); /* null byte: return value must be 1 */
	TEST("%c", 127);
	TEST("%c", 255);
	TEST("%c", -1);
	TEST("%c", 256 + 'a'); /* converted to unsigned char */
	TEST("[%c]", 'x');
	TEST("%c%c%c", 'a', 'b', 'c');
	TEST("%c %c %c", '4', '2', '!');
	TEST("%c%c", '\0', 'a');
	TEST("a%cb", '\0');
	TEST("Hello %c world", 'X');
	TEST("%c", 'a' - 1);

	/* ---------------------------------------------------------- */
	section("%s");
	TEST("%s", "hello");
	TEST("%s", "");
	TEST("%s", " ");
	TEST("%s", "Hello world!");
	TEST("%s", "line1\nline2\n");
	TEST("%s", "tab\there");
	TEST("%s", "with a % sign");
	TEST("%s", "%s %d %c"); /* the string content is NOT a format */
	TEST("[%s]", "abc");
	TEST("%s%s", "abc", "def");
	TEST("%s %s %s", "one", "two", "three");
	TEST("%s", (char *)NULL); /* printf prints "(null)" */
	TEST("[%s]", (char *)NULL);
	TEST("%s and %s", (char *)NULL, "ok");
	TEST("%s", "42 is the answer 42");
	TEST("%s", "\x01\x02\x03 control chars");
	{
		/* very long string */
		static char big[5000];
		memset(big, 'A', sizeof(big) - 1);
		big[sizeof(big) - 1] = '\0';
		TEST("%s", big);
		TEST("start %s end", big);
	}

	/* ---------------------------------------------------------- */
	section("%d");
	TEST("%d", 0);
	TEST("%d", 1);
	TEST("%d", -1);
	TEST("%d", 9);
	TEST("%d", 10);
	TEST("%d", -9);
	TEST("%d", -10);
	TEST("%d", 42);
	TEST("%d", -42);
	TEST("%d", 99);
	TEST("%d", 100);
	TEST("%d", 1000);
	TEST("%d", 123456789);
	TEST("%d", -123456789);
	TEST("%d", 1000000000);
	TEST("%d", INT_MAX);
	TEST("%d", INT_MIN); /* classic trap: -INT_MIN overflows */
	TEST("%d", INT_MAX - 1);
	TEST("%d", INT_MIN + 1);
	TEST("%d", 2147483647);
	TEST("%d", -2147483648);
	TEST("[%d]", 42);
	TEST("%d%d", 1, 2);
	TEST("%d %d %d", 1, -2, 3);
	TEST("%d,%d", INT_MAX, INT_MIN);
	TEST("The answer is %d!", 42);
	TEST("%d", (int)3000000000u); /* wraps to negative */

	/* ---------------------------------------------------------- */
	section("MIXED");
	TEST("%c%s%d", 'a', "bc", 42);
	TEST("%d%s%c", 42, "bc", 'a');
	TEST("%s%c%d", "x", 'y', -1);
	TEST("char=%c str=%s int=%d", 'A', "hello", 123);
	TEST("%c is %d in ascii", 'A', 'A');
	TEST("%s has %d characters", "hello", 5);
	TEST("%s %c %d %s %c %d", "a", 'b', 1, "c", 'd', 2);
	TEST("%c%c%c%c%c%c%c%c%c%c", '0', '1', '2', '3', '4', '5', '6', '7', '8', '9');
	TEST("%d%d%d%d%d%d%d%d%d%d", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
	TEST("|%s|%s|%s|", "", "", "");
	TEST("|%c|%s|%d|", '\0', (char *)NULL, INT_MIN);
	TEST("%s%s%s%s%s", "a", "b", "c", "d", "e");
	TEST("%d\n%s\n%c\n", 42, "text", 'z');

	/* ---------------------------------------------------------- */
	section("RETURN VALUE (checked by every test above, explicit here)");
	{
		int a = printf("12345");
		int b = ft_printf("12345");
		fflush(stdout);
		fprintf(stderr, "\n%s plain text: printf=%d ft_printf=%d\n",
				(a == b) ? "OK  " : "FAIL", a, b);
		(a == b) ? g_pass++ : g_fail++;

		a = printf("%d", INT_MIN);
		b = ft_printf("%d", INT_MIN);
		fflush(stdout);
		fprintf(stderr, "\n%s INT_MIN: printf=%d ft_printf=%d\n",
				(a == b) ? "OK  " : "FAIL", a, b);
		(a == b) ? g_pass++ : g_fail++;

		a = printf("%c", '\0');
		b = ft_printf("%c", '\0');
		fflush(stdout);
		fprintf(stderr, "\n%s null char: printf=%d ft_printf=%d\n",
				(a == b) ? "OK  " : "FAIL", a, b);
		(a == b) ? g_pass++ : g_fail++;
	}

	/* ---------------------------------------------------------- */
	/* Optional: only if you ALSO handle %% (compile with -DTEST_PERCENT) */
#ifdef TEST_PERCENT
	section("%% (optional)");
	TEST("%%");
	TEST("100%%");
	TEST("%%%c%%", 'a');
	TEST("%d%%", 50);
#endif

	fprintf(stderr, "\n==============================\n");
	fprintf(stderr, "PASSED: %d   FAILED: %d\n", g_pass, g_fail);
	fprintf(stderr, "==============================\n");
	unlink(TMP_FILE);
	return (g_fail != 0);
}