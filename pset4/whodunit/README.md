# Questions

## What's `stdint.h`?

* 'stdint.h' is a header file that declares integers of certain "widths", or the number of bits required to store it in memory.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

* uint8t is an integer type that is unsigned - has no memory allocated for a postive/negative denotion - and takes up 8 bits of memory.  Similarly, uint32t and uint16t are unsigned integer storage
* types with 32 and 16 bits respectively allocated.  int32t is a signed integer type with 32 bits of memory allocated, enabling a user to attach a positive/negative denotion to their integer.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

* A BYTE is 8 bits, or one byte (duh).  A DWORD allows 32 bits (4 bytes), a LONG alows at least 32 bits (4 bytes), and a WORD allows 16 bits (2 bytes).

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

* 424d.

## What's the difference between `bfSize` and `biSize`?

* bfSize si the size in bytes of a bitmap file, while the biSize is the number of bytes required by any given structure.

## What does it mean if `biHeight` is negative?

* A negative biHeight implies that the bitmap in question is top-down with its origin in the upper left corner, signifying that any device reading it should start their and proceed through the data
* to construct the image

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

* The biBitcount.

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

* If it doesn't create/find an outfile to write to.

## Why is the third argument to `fread` always `1` in our code?

* So that our read function only passes one block of hexadecimal data at a time from our BMP file

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

* 3

## What does `fseek` do?

* Allows you to change the location of the file pointer to another place in memory

## What is `SEEK_CUR`?

* SEEK_CUR is a piece of fseek that specifies that the user wants to move the pointer to a specific location in memory
