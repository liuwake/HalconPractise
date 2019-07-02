/*****************************************************************************
 * HDeclSpec.h
 ***************************************************************************** 
 *
 * Project:     HALCON/libhalcon
 * Description: Windows DLL specifications
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************/

#ifndef HALCON_DECL_SPEC_H
#define HALCON_DECL_SPEC_H

#if defined(_WIN32) && !defined (_NODLL)
#if defined(_HLibDLL)
#define HLibExport __declspec(dllexport)
#else
#define HLibExport __declspec(dllimport)
#endif
#if defined(_LIntDLL)
#define LIntExport __declspec(dllexport)
#else
#define LIntExport __declspec(dllimport)
#endif
#define HUserExport __declspec(dllexport)
#define HUserImport __declspec(dllimport)
#else /* not _WIN32 */
#if defined(__GNUC__) && (__GNUC__ >= 4)
#define HLibExport __attribute__ ((visibility("default")))
#define LIntExport __attribute__ ((visibility("default")))
#define HUserExport __attribute__ ((visibility("default")))
#else  /* Not gcc 4.0 or higher */
#if defined(__sun) && (defined(__SUNPRO_C) || defined(__SUNPRO_CC))
#define HLibExport __global
#define LIntExport __global
#define HUserExport __global
#else  /* Any other Unix */
#define HLibExport 
#define LIntExport 
#define HUserExport 
#endif /* Any other Unix */
#endif /* Not gcc 4.0 or higher */
#define HUserImport
#endif /* not _WIN32 */

#endif
