# _printf Proyect
***
The function _printf is used to print a specified type of data in the standar output. Depending on the options of format that passed as a argument, the output varies.

## Synopsis
```C
int _printf(const char *format, ...);
```
Writes, in stdout, a string form the argume
| Options % | Description|
|:---------:|:----------:|   
|c          |Print a char which is pased as an argument (va_list ap) to the stdout.             |
|s          |Writes, in stdout, a string form the arguments of (va_list ap).                    |
|d - i      |The integer argument which is given and we convert it to a string and it´s printed.|
|b          |A unsigned integer argument is converted to binary.                                |
|u          |Prints a Unsigned integer.                                                         |
|o          |A unsigned integer argument is converted to octal (base 8).                        |
|x          |A unsigned integer argument is converted to hexadecimal (base 16), in lower case.  |
|X          |A unsigned integer argument is converted to hexadecimal (base 16), in upper case.  |
|S          |Prints a string, Non printable characters (0 < ASCII value < 32 or >= 127) are printed this way: \x, followed by the ASCII code value in hexadecimal (upper case - always 2 characters)|
## Usage

```C
# ouputs a string of characters followed by a new line - $Hello World.

_printf("Hello %s\n", "World.");

# outputs a character followed by a new line - $Hello World.

_printf("Hel%co World%c", 'l', '.');

# outputs an integer (to output an int can use %d and %i) followed by a new line - $I was born in 4/1/2003.

_printf("I was born in %d/%d/%i%i/\n", '4', '1', '200', '3');

# outputs the conversion from integer to binary followed by a new line - $10 + 10 = 100

_printf("%b + %b = %b", 10, 10, 100);

# outputs the unsigned int followed by a new line - $4294967295

_printf("%u\n", UINT_MAX);

# outputs the conversion from integer to octal followed by a new line - $5670

_printf("%o\n", 3000);

# outputs the conversion from integer to hexadecimal (in lower case) followed by a new line - $4bc9

_printf("%x\n", 19401);

# outputs the conversion from integer to hexadecimal (in upper case) followed by a new line - $4BC9

_printf("%X\n", 19401);

# outputs a string with specified - $Best\x0ASchool

_printf("%S\n", "Best\nSchool");
```

## Exit values

***
If success _printf() returns the number of characters to be printed, if format is NULL the function return -1 and lastly format is empty (_printf("");) return 0.

## Bugs
```C
# Incerting a percentage followed by a space and the character 'a' _printf prints - $% a
_printf("% a");
# Incerting a percentage followed by a space and the character 'p' _printf prints - $% p
_printf("% p");
```

## Authors
The authors of this proyect are @FrancoMuVa @DiegoPla1104 @Vicky01396.
