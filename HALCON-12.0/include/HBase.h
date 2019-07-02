/*****************************************************************************
 * HBase.h
 *****************************************************************************
 *
 * Project:     HALCON/libhalcon
 * Description: Basic definitions for HALCON, HALCON/C, HALCON/C++
 *              and other language interfaces
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 *
 *****************************************************************************/

#ifndef HBASE_H
#define HBASE_H

#include <stdlib.h> /* NULL */
#include "HIntDef.h"

typedef   void*   VOIDP;

/*****************************************************************************/
/* Parameter passing (Control parameters)                                    */
/*****************************************************************************/
#define UNDEF_PAR        0       /* Parameter type: no defined type          */
#define LONG_PAR         1       /* Parameter type: long                     */
#define HANDLE_PAR       LONG_PAR /* Parameter type: long                     */
#define FLOAT_PAR        2       /* Parameter type: float                    */
#define STRING_PAR       4       /* Parameter type: string                   */
/* Possible parameter types for a single element: */
#define ANY_ELEM    (LONG_PAR|FLOAT_PAR|STRING_PAR)
#define INT_PAR      LONG_PAR    /* Parameter type: int                      */
#define DOUBLE_PAR  FLOAT_PAR    /* Parameter type: double                   */
#define MIXED_PAR        8       /* Parameter type: Hcpar                    */
#define MAX_TUPLE_TYPE   MIXED_PAR/* maximum type number                     */
/* Possible parameter types for a tuple: */
#define ANY_TUPLE   (LONG_PAR|FLOAT_PAR|STRING_PAR|MIXED_PAR)
/*                      16          reserved */
/*                      32          reserved */
#define POINTER_PAR     64       /* Parameter type: pointer to any type      */
#define TUPLE_PAR      128       /* Parameter type: pointer to tuple         */
#define MAX_PAR     MIXED_PAR


/*****************************************************************************/
/* Constants and basic types                                                 */
/*****************************************************************************/
#define MAX_TUPLE_LENGTH 1000000   /* max. length of a tuple                 */
#define MAX_STRING       1024      /* max. length of a string                */

typedef UINT4            Herror;   /* Type function values (error messages)  */

typedef  long *Hkey;               /* primary key in DB (for iconic objects) */
#define  UNDEF_KEY   (Hkey)(0)     /* Undefined iconic object                */


/*****************************************************************************/
/* Structures for passing parameters between language interface and core     */
/*****************************************************************************/
#ifndef HC_NO_STRUCT_MEMBER_ALIGNMENT
/* sets the struct member alignment to avoid problems if
 * the settings of the user differ to those of the HALCON
 * version. (8 is the default alignment, generally) */
# pragma pack(push,8)
#endif
typedef union
{
  INT4_8  l;              /* 4/8 byte integer                       (input)  */
  double  d;              /* 8 byte real                            (input)  */
  char    *s;             /* pointer to strings                     (input)  */
  double  f;              /* 8 byte real (legacy 11.0)              (input)  */
} Hpar;                   /* parameter passing for the C interface           */

typedef union
{
  INT4_8  *l;             /* 4/8 byte integer                       (output) */
  double  *d;             /* 8 byte real,                           (output) */
  char    *s;             /* pointer to strings                     (output) */
  VOIDP   p;              /* pointer to var. of any type (e.g. tuple)(output)*/
  double  *f;             /* 8 byte real, (legacy 11.0)             (output) */
} Hvar;                   /* parameter passing for the C interface           */

typedef struct
{
  Hpar   par;             /* values                                          */
  INT    type;            /* type flag                                       */
} Hcpar;                  /* parameter passing for the C interface           */

typedef struct
{
  Hvar   var;             /* values                                          */
  INT    type;            /* type flag                                       */
} Hcvar;                  /* parameter passing for the C interface           */

typedef union {
  INT4_8 *l;
  double *d;
  char   **s;
  Hcpar  *cpar;
} Hcelem; /* pure type array */


typedef struct HCTUPLE
{
  Hpar  val;
  INT   type;
  char  pad[sizeof(Hcpar)-sizeof(Hpar)-sizeof(INT)]; /* padding for data
                                * structure alignement to enable val and type
                                * to get used as Hcpar structure */
  INT4_8 num;                   /* number of set array elements */
  INT4_8 capacity;              /* allocated array length */
  INT   free;                   /* free array elem when destroying tuple? */
  Hcelem elem;                  /* the actual array */
} Hctuple;
#define HCTUPLE_INITIALIZER {{0},UNDEF_PAR,{0},0,0,0,{NULL}}

typedef struct
{
  Hcvar   *variables;     /* variables (of application) to write back values */
  Hcpar   *element;       /* tuple element(s)                                */
  INT4_8  num_el;         /* number of used elements                         */
  INT4_8  length;         /* total length of array (incl. unused elements)   */
} Hcvtuple;               /* for passing control parameter variables from    */
                          /* the language to the core interface              */
#ifndef HC_NO_STRUCT_MEMBER_ALIGNMENT
# pragma pack(pop)
#endif

/*****************************************************************************/
/* Bool constants                                                            */
/*****************************************************************************/
#ifndef TRUE
#define TRUE             1
#else
#undef  TRUE
#define TRUE             1
#endif

#ifndef FALSE
#define FALSE            0
#else
#undef  FALSE
#define FALSE            0
#endif


/*****************************************************************************/
/* Pixel types of HALCON images                                              */
/*****************************************************************************/
#define UNDEF_IMAGE   (INT)0
#define BYTE_IMAGE    (INT)(1<<0)
#define INT4_IMAGE    (INT)(1<<1)
#define LONG_IMAGE    INT4_IMAGE
#define FLOAT_IMAGE   (INT)(1<<2)
#define DIR_IMAGE     (INT)(1<<3)
#define CYCLIC_IMAGE  (INT)(1<<4)
#define INT1_IMAGE    (INT)(1<<5)
/* (1<<6) omitted sofar -> use it for next new image type */
#define COMPLEX_IMAGE (INT)(1<<7)
/* (1<<8) omitted sofar -> use it for next new image type */
#define INT2_IMAGE    (INT)(1<<9)
#define UINT2_IMAGE   (INT)(1<<10)
#define VF_IMAGE      (INT)(1<<11)
#define INT8_IMAGE    (INT)(1<<12)

/*****************************************************************************/
/* Type of HALCON vector field images                                        */
/*****************************************************************************/
#define VF_ABSOLUTE   (INT4)0
#define VF_RELATIVE   (INT4)(1<<0)


/*****************************************************************************/
/* HALCON procedure (operator) handle                                        */
/*****************************************************************************/
/* This data structure contains all informations about an instance of an     */
/* HALCON operator or an HALCON thread derived from an HALCON operator       */
/* instance. The contained information describes the processing context of   */
/* HALCON operators (e.g. parameter values, debugging information, etc.).    */
/*****************************************************************************/
typedef void *Hproc_handle;


/*****************************************************************************/
/* data types for handling pthreads (POSIX threads) and mutex variables      */
/*****************************************************************************/
typedef void*          H_pthread_t;            /* pthread handle             */
typedef void*          H_pthread_mutex_t;      /* pthread mutex data type    */
typedef void*          H_pthread_cond_t;       /* pthread condition variable */
typedef void*          H_pthread_barrier_t;    /* pthread barrier variable */


/*****************************************************************************/
/* signature of the callback functions for drawing objects                   */
/*****************************************************************************/
#ifndef _WIN32
#define __stdcall
#endif
typedef Herror (__stdcall *HDrawObjectCallback)(Hlong DrawID,Hlong WindowHandle,
                                                                  char* type);

/* A define for the restrict qualifier */
#if !defined(H_RESTRICT)
# if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
   /* Compiler is in C99 mode and should know about the restrict qualifier */
#  define H_RESTRICT restrict
# else
#  if (defined(_WIN32) && defined(_MSC_VER) && _MSC_VER >= 1400) || defined(__INTEL_COMPILER)
    /* Intel Compilers and grown-up Microsoft Compilers always know a __restrict */
#   define H_RESTRICT __restrict
#  elif (defined(__linux) || defined(__APPLE__)) && defined(__GNUC__)
    /* Gcc knows about __restrict__ since at least gcc 3.0 */
#   define H_RESTRICT __restrict__
#  elif defined(__TI_COMPILER_VERSION__)
    /* TI's cgtools know about restrict. */
#   define H_RESTRICT restrict
#  else
#   define H_RESTRICT
#  endif
# endif /* __STDC_VERSION__ */
#endif /* H_RESTRICT */


/* A define for the inline qualifier */
#if !defined(H_INLINE)
#ifdef __cplusplus
#define H_INLINE inline
#else
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
/* compiler is in C99 mode and should know about the inline qualifier */
#  define H_INLINE inline
#else
#if defined(_WIN32) || defined(__alpha) || defined(__sgi)
#  define H_INLINE __inline
#else
#if defined(__linux) || defined(__APPLE__)
#  define H_INLINE __inline__
#else
#if defined(__sun)
#  define H_INLINE inline
#else
#  define H_INLINE
#endif
#endif
#endif
#endif /* __STDC_VERSION__ */
#endif /* #ifdef __cplusplus .. else */
#endif /* H_INLINE */

/* A define to force functions to be inlined */
#if defined(_WIN32)
#define H_FORCEINLINE __forceinline
#elif (defined(__linux) || defined(__APPLE__)) && defined(__GNUC__)
#define H_FORCEINLINE H_INLINE __attribute__((always_inline))
#else
#define H_FORCEINLINE H_INLINE
#endif

#endif
