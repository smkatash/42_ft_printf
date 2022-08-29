# 42_ft_printf
Re-implementation of printf()

- Following conversions are handled:

- %c Prints a single character.
- %s Prints a string (as defined by the common C convention).
- %p The void * pointer argument has to be printed in hexadecimal format.
- %d Prints a decimal (base 10) number.
- %i Prints an integer in base 10.
- %u Prints an unsigned decimal (base 10) number.
- %x Prints a number in hexadecimal (base 16) lowercase format.
- %X Prints a number in hexadecimal (base 16) uppercase format.
- %% Prints a percent sign.
- Manage any combination of the following flags: ’-0.’ and the field minimum width
under all conversions.
- Manage all the following flags: ’# +’ (Yes, one of them is a space)
