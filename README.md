# 42_ft_printf
Re-implementation of printf()

<img width="100" alt="image" src="https://user-images.githubusercontent.com/76934648/187242121-44dd175a-5f27-4c82-a995-bf5adb7e0656.png">

## 💡 About the project

> _This project is pretty straight forward. You will recode printf. You will mainly learn how to use variadic arguments._

	This project consists of coding a library that contains a simplified version (more
	information below) of the printf function.

## Following conversions are handled:
> - %c Prints a single character.
> - %s Prints a string (as defined by the common C convention).
> - %p The void * pointer argument has to be printed in hexadecimal format.
> - %d Prints a decimal (base 10) number.
> - %i Prints an integer in base 10.
> - %u Prints an unsigned decimal (base 10) number.
> - %x Prints a number in hexadecimal (base 16) lowercase format.
> - %X Prints a number in hexadecimal (base 16) uppercase format.
> - %% Prints a percent sign.
> - Manage any combination of the following flags: ’-0.’ and the field minimum width
under all conversions.
> - Manage all the following flags: ’# +’ (Yes, one of them is a space)._

## Usage

### Requirements

The function is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling the library**

To compile, go to the library path and run:

```shell
$ make
```

**2. Using it in your code**

To use the library functions in your code, simply include its header:

```C
#include "ft_printf.h"
```

