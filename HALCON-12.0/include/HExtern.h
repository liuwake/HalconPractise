/*****************************************************************************
 * HExtern.h
 *****************************************************************************
 *
 * Project:     HALCON/libhalcon
 * Description: External variables and some global procedures for
 *              language interfaces
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 *
 *****************************************************************************/

#ifndef HEXTERN_H
#define HEXTERN_H

#if defined(__cplusplus)
extern "C" {
#endif

/* global variables for image processing                                     */
                                                /* procedures description    */
extern HLibExport INT          HDoLowError;     /* error messages of HALCON  */
extern HLibExport INT4         HLowErrorAction[4]; /* action for HALCON low  */
                                                   /* level error messages   */
extern HLibExport INT          HDoLicenseError; /* license msgs of HALCON    */
extern HLibExport INT          HUseSpinLock;    /* sync initialization of
                                                 * Parallel HALCON           */
extern HLibExport INT          HStartUpThreadPool;  /* start thread pool
                                                     * initially? */
extern HLibExport INT          HShutdownThreadPool; /* shutdown thread pool
                                                     * on termination? */
extern HLibExport INT          HShuttingDown; /* currently terminating and
                                               * unloading HALCON Library? */


/* Convenience function accessors as some development environments */
/* do not directly support importing variables from C DLLs.        */

extern HLibExport void __stdcall HSetDoLicenseError(INT value);
extern HLibExport void __stdcall HSetUseSpinLock(INT value);
extern HLibExport void __stdcall HSetStartUpThreadPool(INT value);
extern HLibExport void __stdcall HSetShutdownThreadPool(INT value);

extern HLibExport INT __stdcall HGetDoLicenseError(void);
extern HLibExport INT __stdcall HGetUseSpinLock(void);
extern HLibExport INT __stdcall HGetStartUpThreadPool(void);
extern HLibExport INT __stdcall HGetShutdownThreadPool(void);
extern HLibExport INT __stdcall HGetShuttingDown(void);

/* remark: the structure above contains global HALCON system variables       */
/* which are (in the normal case) exclusively accessible via a valid         */
/* procedure handle and by using specific functions of the HALCON-Lib        */
/* source code file HInstance.c; those functions contain synchronization     */
/* mechanisms to guarantee a correct access to the variables even in case of */
/* a parallel/multithreaded/reentrant HALCON version.                        */
/* Nevertheless the structure is propagated here so that it also can be used */
/* directly, but this should be done VERY CAREFULLY!! At the moment it is    */
/* only used directly within HDevelop, which means no problem, because       */
/* HDevelop works strictly sequentially, i.e. it calls all HALCON            */
/* operators one after another;                                              */

/* Functions to tell HALCON library the interface from which it gets accessed.
 * This enables the library to adapt its default behaviour.                  */
extern HLibExport void __stdcall HSetHDevelopInt(INT AccessByHDevelop);
extern HLibExport INT  __stdcall HGetHDevelopInt(void);

#if defined(__cplusplus)
}
#endif

#endif
