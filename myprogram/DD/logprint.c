#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>

#define pr_info(fmt, ...)  eprintf(0, verbose, pr_fmt(fmt), ##__VA_ARGS__)

char *str = "hello world\n";
int main() {
	pr_info(str);
}
