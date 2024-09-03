# get_next_line

`get_next_line` is a C function designed to read and return a single line from a file descriptor, making it easier to handle input from files or standard input one line at a time. The bonus version extends this functionality by allowing simultaneous reading from multiple file descriptors, which is particularly useful in complex programs where input is required from multiple sources.

this project was developed as part of the 42 curriculum, where the goal was to deepen the understanding of file handling, memory management, and the intricacies of C programming. This function is versatile and can be used in a wide range of applications where line-by-line processing of input is required.

## Installation

To use `get_next_line` in your project, clone the repository and include the necessary source files:

```bash
git clone https://github.com/yourusername/get_next_line.git
cd 42_getnextline
```
either compile the files into a library and link it in your project's Makefile:
```bash
make
# lib: 42_getnextline/gnl.a
```
or simply #include the correct header ("get_next_line.h" or "get_next_line_bonus.h" if you want to read from multiple file descriptors).


## Example

this example program will read from a file one line at a time and display it on the standard output.
```c
#include "get_next_line.h"

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```
make sure you have the example.txt file and you can try the program like this:
```bash
cc main.c 42_getnextline/gnl.a -o example
./example
```