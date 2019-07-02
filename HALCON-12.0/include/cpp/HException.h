/*****************************************************************************
 * HException.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Error handling
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */



#ifndef H_EXCEPTION_H
#define H_EXCEPTION_H

#include "HSync.h"

#include <new>

namespace Halcon {


class HException;

// Handler for user defined exception handling.
// Used with InstallHHandler()
typedef void (*Handler)(const Halcon::HException &exception);


// Macros to generate an exception with file name and line number

#define H_EXCEPTION(PROC,VAL) {                                             \
  H_SYNC_DEF_INT(num_locks);                                                \
                                                                            \
  H_SYNC_LEAVE_ALL_CS_LOCKS(num_locks);                                     \
  Halcon::HException hexc = Halcon::HException(__FILE__,__LINE__,PROC,VAL); \
  hexc.React();                                                             \
  H_SYNC_REENTER_ALL_CS_LOCKS(num_locks);                                   \
}

#define H_EXCEPTIONF(PROC,ERR_NUM,ERR_TEXT) {                           \
  H_SYNC_DEF_INT(num_locks);                                            \
                                                                        \
  H_SYNC_LEAVE_ALL_CS_LOCKS(num_locks);                                 \
  Halcon::HException hexc = Halcon::HException(__FILE__,__LINE__,PROC,  \
                                               ERR_NUM,ERR_TEXT);       \
  hexc.React();                                                         \
  H_SYNC_REENTER_ALL_CS_LOCKS(num_locks);                               \
}


// Macros to allocate new instances with error handling,
// for 0 return / bad_alloc exception (compiler specific).


// Check new assignment with HCkNew(dest = new type,"proc"),
// it will raise an HException on allocation errors.
#define HCkNew(ASSIGN_NEW)      XHCkNew(ASSIGN_NEW)
#define XHCkNew(ASSIGN_NEW) {              \
try                                        \
{                                          \
  if (!(ASSIGN_NEW))                       \
    H_EXCEPTION("new","Out of memory");    \
}                                          \
catch (std::bad_alloc)                     \
{                                          \
  H_EXCEPTION("new","Out of memory");      \
}}


// Some classes, like HException, need to react to allocation
// errors without raising further exceptions
#define H_NEW_NO_THROW(DEST, TYPE) {       \
try                                        \
{                                          \
  DEST = new TYPE;                         \
}                                          \
catch (std::bad_alloc)                     \
{                                          \
  DEST = NULL;                             \
}}


/* defines how to protect critical database accesses 
 *---------------------------------------------------------------------------*/
#ifdef H_PARALLEL            /* Parallel HALCON: lock the global proc handle */
# define H_ENTER_CPP_CS 
# define H_LEAVE_CPP_CS 
#else
# ifdef _REENTRANT          /* thread save HALCON: H_SYNC_*_CRITICAL_SECTION */

#  define H_ENTER_CPP_CS H_SYNC_ENTER_CRITICAL_SECTION
#  define H_LEAVE_CPP_CS H_SYNC_LEAVE_CRITICAL_SECTION

# else                       /* not parallel, not thread save: no protection */

#  define H_ENTER_CPP_CS 
#  define H_LEAVE_CPP_CS

# endif
#endif

#define HCppGetHROSysPar(PROC_HANDLE)           \
  {                                             \
    Herror err;                                 \
    err = HGetHROSysPar(&(PROC_HANDLE));        \
    if (err != H_MSG_OK) {                      \
      char err_text[MAX_STRING];                \
      (void)HErrorMessage(err,err_text);             \
      H_LEAVE_CPP_CS;                           \
      H_EXCEPTION("",err_text);                 \
    }                                           \
  }

#define HCppGetHProc(PROC_HANDLE)               \
  {                                             \
    PROC_HANDLE = HTSProcHandle();              \
  }

#define HCppCreateHProc(PROC_HANDLE)            \
  {                                             \
    Herror err;                                 \
    err = HGetHProc(-1, &(PROC_HANDLE));        \
    if (err != H_MSG_OK) {                      \
      char err_text[MAX_STRING];                \
      (void)HErrorMessage(err,err_text);             \
      H_LEAVE_CPP_CS;                           \
      H_EXCEPTION("",err_text);                 \
    }                                           \
  }

#define HCppDeleteHProc(PROC_HANDLE)                  \
  {                                                   \
    Herror err;                                       \
    err = HPutHProc((PROC_HANDLE));                   \
    if (err != H_MSG_OK) {                            \
      char err_text[MAX_STRING];                      \
      (void)HErrorMessage(err,err_text);                   \
      H_LEAVE_CPP_CS;                                 \
      H_EXCEPTION("",err_text);                       \
    }                                                 \
  }

#define HTextExLock(PROC) {                     \
    Hproc_handle_ ph;                           \
    H_ENTER_CPP_CS;                             \
    HCppGetHProc(ph);                           \
    Herror err = PROC; /* the procedure call */ \
    if (err != H_MSG_OK) {                      \
      char err_text[MAX_STRING];                \
      (void)HErrorMessage(err,err_text);             \
      H_LEAVE_CPP_CS;                           \
      H_EXCEPTION("",err_text);                 \
    }                                           \
    else                                        \
    {                                           \
      H_LEAVE_CPP_CS;                           \
    }                                           \
  }

#define HTextEx(PROC_HANDLE,PROC) {               \
    Herror err = PROC;                            \
    if (err != H_MSG_OK) {                        \
      char err_text[MAX_STRING];                  \
      (void)HErrorMessage(err,err_text);               \
      H_LEAVE_CPP_CS;                             \
      H_EXCEPTION("",err_text);                   \
    }                                             \
  }


class LIntExport HException {
public:
  HException(const HException &except);
  HException(const char *f, Hlong l, const char *p, Herror e, const char *m);
  HException(const char *f, Hlong l, const char *p, const char *m);
  HException(const char *f, Hlong l, const char *p, Herror e);
  HException(const HTuple &tuple);
  ~HException();
  
  void           React(void);
  static Handler InstallHHandler(Handler proc);
  // default exception handler
  void           PrintException(void);
  void          ToHTuple(HTuple *exception) const;
  static void   GetExceptionData(const HTuple &exception, 
                                 const HTuple &name, HTuple *value);
  HException     &operator = (const HException &except);
  
  static Handler handler;   /* handler in use */
  Hlong          line;      /* line number where error occured */
  char           *file;     /* file name where error occured */
  char           *proc;     /* Name of procedure/operator */
  Herror         err;       /* error number */
  char           *message;  /* error text */
  Halcon::HTuple *user_data; /* user defined error data */

private:

  void InitException(const char *f, Hlong l, const char *p,
                     Herror e, const char *m, const HTuple& ud);

};


}


#endif
