# _printf Proyect
***
The function _printf is used to print a specified type of data in the standar output. Depending o      n the options of format that passed as a argument, the output varies.

## Synopsis
```C
int _printf(const char *format, ...);
```

## Options
***
The character % is followed by zero or more of the followings flags: c, s, d and i.

### c

Print a char which is pased as an argument (va_list ap) to the stdout.

### s

Writes, in stdout, a string form the arguments of (va_list ap).

### d, i

The integer argument which is given and we convert it to a string and it´s printed.

## Usage

```C
# ouputs a string of characters followed by a new line - $Hello World.

_printf("Hello %s\n", "World.");

# outputs a character followed by a new line - $Hello World.

_printf("Hel%co World%c", 'l', '.');

# outputs an integer (to output an int can use %d and %i) followed by a new line - $I was born in 4/1/2003.

_printf("I was born in %d/%d/%i%i/\n", '4', '1', '200', '3');
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





