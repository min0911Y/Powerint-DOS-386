/*
* limits.h
* This file has no copyright assigned and is placed in the Public Domain.
* This file is a part of the mingw-runtime package.
* No warranty is given; refer to the file DISCLAIMER within the package.
*
* Functions for manipulating paths and directories (included from io.h)
* plus functions for setting the current drive.
*
* Defines constants for the sizes of integral types.
*
* NOTE: GCC should supply a version of this header and it should be safe to
* use that version instead of this one (maybe safer).
*
*/
#ifndef _LIMITS_H_
#define _LIMITS_H_
/* All the headers include this file. */
/*
* File system limits
*
* TODO: NAME_MAX and OPEN_MAX are file system limits or not? Are they the
* same as FILENAME_MAX and FOPEN_MAX from stdio.h?
* NOTE: Apparently the actual size of PATH_MAX is 260, but a space is
* required for the NUL. TODO: Test?
*/
#define PATH_MAX (259)
/*
* Characteristics of the char data type.
*
* TODO: Is MB_LEN_MAX correct?
*/
#define CHAR_BIT 8
#define MB_LEN_MAX 2
#define SCHAR_MIN (-128)
#define SCHAR_MAX 127
#define UCHAR_MAX 255
/* TODO: Is this safe? I think it might just be testing the preprocessor,
* not the compiler itself... */
#if ('\x80' < 0)
#define CHAR_MIN SCHAR_MIN
#define CHAR_MAX SCHAR_MAX
#else
#define CHAR_MIN 0
#define CHAR_MAX UCHAR_MAX
#endif
/*
* Maximum and minimum values for ints.
*/
#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX-1)
#define UINT_MAX 0xffffffff
/*
* Maximum and minimum values for shorts.
*/
#define SHRT_MAX 32767
#define SHRT_MIN (-SHRT_MAX-1)
#define USHRT_MAX 0xffff
/*
* Maximum and minimum values for longs and unsigned longs.
*
* TODO: This is not correct for Alphas, which have 64 bit longs.
*/
#define LONG_MAX 2147483647L
#define LONG_MIN (-LONG_MAX-1)
#define ULONG_MAX 0xffffffffUL
/*
* The GNU C compiler also allows 'long long int'
*/
#if !defined(__STRICT_ANSI__) && defined(__GNUC__)
#define LONG_LONG_MAX 9223370L
#define LONG_LONG_MIN (-LONG_LONG_MAX-1)
#define ULONG_LONG_MAX (2ULL * LONG_LONG_MAX + 1)
/* ISO C9x macro names */
#define LLONG_MAX LONG_LONG_MAX
#define LLONG_MIN LONG_LONG_MIN
#define ULLONG_MAX ULONG_LONG_MAX
/* MSVC compatibility */
#define _I64_MIN LONG_LONG_MIN
#define _I64_MAX LONG_LONG_MAX
#define _UI64_MAX ULONG_LONG_MAX
#endif /* Not Strict ANSI and GNU C compiler */
#endif /* not _LIMITS_H_ */