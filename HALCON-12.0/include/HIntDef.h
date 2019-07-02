/*****************************************************************************
 * HIntDef.h
 *****************************************************************************
 *
 * Project:     HALCON/libhalcon
 * Description: Definition of HALCON data types
 *              These definitions can be controlled by the compiler
 *              The size of the data type is always in byte _not_ in bits
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 *
 *****************************************************************************/

#ifndef HINTDEF_H
#define HINTDEF_H

#ifndef __midl
#  include <stdlib.h> /* RAND_MAX */
#  include <float.h>  /* FLT_MAX, DBL_MAX, ... */
#  include <limits.h> /* LONG_MAX, INT_MAX, ... */
#endif

#ifdef _WIN32
# ifndef __midl
#  include <windows.h>
# endif
#else
#  define  INT      int               /* integer, signed   2-8 Byte      */
#  define  UINT     unsigned int      /* integer, unsigned 2-8 Byte      */
#  define  UINT_MIN 0
#endif

#ifndef _DOUBLE8
#  define DOUBLE8   double
#else
#  ifndef TRIMEDIA
#    define DOUBLE8 _DOUBLE8
#  else
#    define DOUBLE8 long double
#  endif
#endif

#ifdef SPARC
#  ifndef DBL_MAX
#    define DBL_MAX MAXDOUBLE
#  endif
#  ifndef DBL_MIN
#    define DBL_MIN MINDOUBLE
#  endif
#  ifndef FLT_MAX
#    define FLT_MAX MAXFLOAT
#  endif
#  ifndef FLT_MIN
#    define FLT_MIN MINFLOAT
#  endif
#endif

#ifdef __vxworks
#  include <types/vxTypesBase.h>
#  ifndef DBL_MAX
#    define DBL_MAX _ARCH_DBL_MAX
#  endif
#  ifndef DBL_MIN
#    define DBL_MIN _ARCH_DBL_MIN
#  endif
#  ifndef FLT_MAX
#    define FLT_MAX _ARCH_FLT_MAX
#  endif
#  ifndef FLT_MIN
#    define FLT_MIN _ARCH_FLT_MIN
#  endif
#endif

#ifndef FLT_EPSILON
#  define FLT_EPSILON 1E-5
#endif

#ifndef DBL_EPSILON
#  define DBL_EPSILON 1E-9
#endif

#ifndef RAND_MAX
#  define RAND_MAX MAXINT
#endif


#if defined(__CHAR_UNSIGNED__) || defined(__sgi)
#define  INT1      signed char       /* integer, signed 1 Byte         */
#define  INT1_MIN  SCHAR_MIN
#define  INT1_MAX  SCHAR_MAX
#else
#define  INT1      char              /* integer, signed 1 Byte         */
#define  INT1_MIN  CHAR_MIN
#define  INT1_MAX  CHAR_MAX
#endif
#define  UINT1     unsigned char     /* integer, unsigned 1 Byte       */
#define  UINT1_MIN 0
#define  UINT1_MAX UCHAR_MAX


#define  INT2      short             /* integer, signed 2 Byte         */
#define  INT2_MIN  SHRT_MIN
#define  INT2_MAX  SHRT_MAX
#define  UINT2     unsigned INT2     /* integer, unsigned 2 Byte       */
#define  UINT2_MIN 0
#define  UINT2_MAX USHRT_MAX


#define  INT4      int               /* integer, signed 4 Byte         */
#define  INT4_MIN  INT_MIN
#define  INT4_MAX  INT_MAX
#define  UINT4     unsigned INT4     /* integer, unsigned 4 Byte       */
#define  UINT4_MIN 0
#define  UINT4_MAX UINT_MAX


/* INT4_8 is 4 bytes on all 32-bit and 8 bytes on all 64-bit platforms */
#ifndef _WIN64  /* LP64 data model */
#  if !defined(_TMS320C6X)
#    define HINT4_8       long      /* workaround for preprocessor bug */
#    define INT4_8        HINT4_8
#    define INT4_8_FORMAT "l"
#    define INT4_8_MIN    LONG_MIN
#    define INT4_8_MAX    LONG_MAX
#    define UINT4_8_MIN   0UL
#    define UINT4_8_MAX   ULONG_MAX
#  else         /* _TMS320C6X long is really 40Bit, but sizeof(long)=8 */
#    define INT4_8        int
#    define INT4_8_FORMAT ""
#    define INT4_8_MIN    INT_MIN
#    define INT4_8_MAX    INT_MAX
#    define UINT4_8_MIN   0
#    define UINT4_8_MAX   UINT_MAX
#  endif
#else          /* LLP64 data model */
#  define INT4_8        __int64
#  define INT4_8_FORMAT "I64"
#  define INT4_8_MIN    _I64_MIN
#  define INT4_8_MAX    _I64_MAX
#  define UINT4_8_MIN   0UL
#  define UINT4_8_MAX   _UI64_MAX
#endif
/* INT4_8 is a integer, signed 4 or 8 byte                             */
#define  UINT4_8     unsigned INT4_8 /* integer, unsigned 4 or 8 Byte  */

/* Hlong/Hulong is the same as INT4_8/UINT4_8 and different from long  */
#define HLONG_FORMAT INT4_8_FORMAT
#define LONG_FORMAT INT4_8_FORMAT /* deprecated, use HLONG_FORMAT     */
typedef INT4_8  Hlong;
#define HLONG_MIN  INT4_8_MIN
#define HLONG_MAX  INT4_8_MAX
typedef UINT4_8 Hulong;
#define HULONG_MIN UINT4_8_MIN
#define HULONG_MAX UINT4_8_MAX

/* HINT8/HUINT8 is always 64-bit integer                               */
#if defined(_WIN32) || defined(_WIN64)
#  define HINT8        __int64
#  define HINT8_FORMAT "I64"
#  define HINT8_MIN    _I64_MIN
#  define HINT8_MAX    _I64_MAX
#  define HUINT8_MIN   0UL
#  define HUINT8_MAX   _UI64_MAX
#else
#  if defined(__alpha)
#    define HINT8        long
#    define HINT8_FORMAT "l"
#    define HINT8_MIN    LONG_MIN
#    define HINT8_MAX    LONG_MAX
#    define HUINT8_MIN   0UL
#    define HUINT8_MAX   ULONG_MAX
#  else
#    define HINT8        long long
#    define HINT8_FORMAT "ll"
#    ifndef LLONG_MAX
#      define LLONG_MAX    9223372036854775807LL
#    endif
#    ifndef LLONG_MIN
#      define LLONG_MIN    (-LLONG_MAX-1LL)
#    endif
#    ifndef ULLONG_MAX
#      define ULLONG_MAX   18446744073709551615ULL
#    endif
#    define HINT8_MIN    LLONG_MIN
#    define HINT8_MAX    LLONG_MAX
#    define HUINT8_MIN   0ULL
#    define HUINT8_MAX   ULLONG_MAX
#  endif
#endif
/* HINT8 is a integer, signed 8 byte                                    */
#define  HUINT8     unsigned HINT8    /* integer, unsigned 8 Byte       */


#if !defined(HC_LARGE_IMAGES)
#define HIMGCOOR_MIN INT2_MIN
#define HIMGCOOR_MAX INT2_MAX
#define HITEMCNT_MIN INT4_MIN
#define HITEMCNT_MAX INT4_MAX
#define HSUBCOOR_MIN FLT_MIN
#define HSUBCOOR_MAX FLT_MAX
#define HSUBCOOR_EPS FLT_EPSILON
#define HSUBATTR_MIN FLT_MIN
#define HSUBATTR_MAX FLT_MAX
#else
#define HIMGCOOR_MIN INT4_MIN
#define HIMGCOOR_MAX INT4_MAX
#define HITEMCNT_MIN INT4_8_MIN
#define HITEMCNT_MAX INT4_8_MAX
#define HSUBCOOR_MIN DBL_MIN
#define HSUBCOOR_MAX DBL_MAX
#define HSUBCOOR_EPS DBL_EPSILON
#define HSUBATTR_MIN DBL_MIN
#define HSUBATTR_MAX DBL_MAX
#endif

/* Define the largest double that can safely be casted to INT4_8 without
 * turning negative.
 */
#if INT4_8_MAX==INT4_MAX
#  define INT_4_8_MAXDOUBLE (double)INT4_MAX
#else
#  define INT_4_8_MAXDOUBLE (double)(HINT8_MAX-1023)
#endif

/* At least an address must fit into MACHINE_WORD */
#define _MACHINE_WORD INT4_8

#define  MACHINE_WORD _MACHINE_WORD /* only for memory management     */
                                    /* (HAlloc.c)                     */


#endif
