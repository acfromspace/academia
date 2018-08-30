****************************************************************************
PROGRAMS
****************************************************************************

int main (int argc, char ** argv)
// Command Line Arguments
// Has 2 Arguments
{
    // Number of bytes to allocate for memory for 64 bit (80) or 32 bit (40)
    int *heap = (int *) malloc(sizeof(int) * numOfElements);
    // Malloc is a void pointer, doesn't know where it's pointing at
}

echo "Hello World"
    // A program that standard out line argument

nano test.call

#include <Stdio.h>

int main(int argc, char** argv)
{
    int i;
    for (i = 1; i < argc; i++) {e <
        printf("%s ", argv[i]);
    }
    return 0;
    // 0 is equivalent to ./a.out
}

echo Hello World > filename
    Creates a filename and within it shows Hello World (via cat command)

#include <Stdio.h>

int main(int argc, char** argv)
{
    char buff[256];
    scanf("%[^\n]s", buff);
    printf("$s\n",buff);
    return 0;
}

echo hello world | ./a.out > somewhere
    Shows nothing because it just makes a file named "somewhere".

nano somewhere

somewhere:
    hello world
    other place
    more

cat somewher

****************************************************************************
VOCAB
****************************************************************************

array
// A contiguous section of memory

pointers
// Reference to a specific value

int *arr;
arr = 0x37049088;
(*arr) = 3;
(*(arr+1)) = 4;
*(arr+2) = 15;

Hexadecimal 10 = Normal 16 (There''s another name than normal)

equivalent coding syntax for C:
arr[0] <-> *(arr + 0)
arr[1] <-> *(arr + 1)

argv''s value in memory: 00 12 12 14
argv''s address in memory: 0x00121214

./a.out = 1st argument 
Hello = 2nd argument
World = 3rd argument

memory1:
00 00 01 AC
// This contains . / a . o u t \0
// \0 = whitespace

memory2:
00 10 20 30
// This contains H e l l o \0 W o

*(*(argv+0) + 4) finds "o" (in out)

Why learn memory syntax within a computer?
To learn how computer''s memory works.

How do we get arrays?
We call it: int arr[10];

What does the return value do?
It is the exit value.

How else do we get information out of a program?
printf
STDOUT (Standard out)
    Also known as a socket, file, stream
STTERR (Standard error)

How do we get information inside a program?
cmd line argument
STDIN

IORedirection ???

****************************************************************************
ALERT: NEW LANGUAGE
****************************************************************************

Bash
    It''s a shell which are user interaction program that is primarily responsible for maintaining user experience.
    This maintains the running programs on the computer.
    Linux is solely ran through bash.

./.aout < filename
    STDIN
    Spits the filename

./a.out > filename
    STDOUT 
    ???

./a.out >> append