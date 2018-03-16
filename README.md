# ft_printf : Refactoring the printf library

## Project Overview
ft_printf aims to mimic the function of printf (included in <stdio.h>).

## How to use it

### Download and compile the library

```
git clone https://github.com/mgia/ft_printf.git ~/ft_printf
cd ~/ft_printf
make
```

### Compile with your files

To use this static library, include it in your header file and during compilation time.

Add the following include in your header.h or in your file :
```
#include "ft_printf.h"
```
Followed by the command to compile :
```
gcc -I includes -o [Name] [Source files].c -L. -lftprintf
```
And execute the program :
```
./a.out
```

## Score
`100/100`
