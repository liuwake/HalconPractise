/*****************************************************************************
 * HalconCpp.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Defines / types / extern declarations for HALCON/C++ interface
 *
 * (c) 2010-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 *****************************************************************************/


#ifndef HALCON_CPP_H
#define HALCON_CPP_H


// Architecture limitations

#if !defined(HCPP_NO_INT_OVERLOADS)
#define HCPP_INT_OVERLOADS
#endif

#if !defined(HCPP_NO_USE_IOSTREAM)
#define HCPP_USE_IOSTREAM
#endif


// HALCON library includes

#include "Halcon.h"

// interface version
// do not define a number because it can be loaded in parallel to version 10
#define HCPP_INTERFACE_VERSION_11


// Standard C++ library includes

#ifdef HCPP_USE_IOSTREAM
#include <iostream>
#endif


// Resolve known macro name collisions

#if defined(_WIN32)
/* FindText, CreateMutex, CreateEvent, and DeleteFile are also functions of the
 * Windows API. There are defines on FindTextW, CreateMutexW, CreateEventW, and
 * DeleteFileW if UNICODE is defined, otherwise there are defines on
 * FindTextA, CreateMutexA, CreateMutexA, and DeleteFileA.
 * These defines are undefined here. If you want to use the corresponding
 * Windows API calls, you must use FindTextA, FindTextW, CreateMutexA,
 * CreateMutexW, CreateEventA, CreateEventW, DeleteFileA, or DeleteFileW
 * directly. */
#undef FindText
#undef CreateMutex
#undef CreateEvent
#undef DeleteFile
#endif

// Macro to deprecate a method
#if defined __GNUC__ &&  !defined HC_NO_LEGACY_WARNING
#  define GCC_VERSION (__GNUC__ * 10 + __GNUC_MINOR__)
#  if defined __INTEL_COMPILER || GCC_VERSION < 45
#    define HDEPRECATED( OBJ, MSG)   OBJ __attribute__ ((deprecated))
#  else
#    define HDEPRECATED( OBJ, MSG)   OBJ __attribute__ ((deprecated(MSG)))
#  endif
#elif defined(_MSC_VER)  &&  !defined HC_NO_LEGACY_WARNING
#  define HDEPRECATED( OBJ, MSG)   __declspec(deprecated(MSG)) OBJ
#else
// no mechanism implemented for this compiler
#  define HDEPRECATED( OBJ, MSG)   OBJ
#endif


// HALCON/C++ types

namespace HalconCpp
{

#if defined(HCPP_LEGACY_API)
// Allow usage of legacy exception handler
#define HCPP_LEGACY_EXCEPTION
#endif

// HALCON/C++ forward declarations

class HTuple;
class HVector;
class HString;
class HException;
class HDevWindowStack;
class HObjectBase;
class HToolBase;
class HDataBase;

// Fully generated classes
#include "HalconCppForwards.h"

class HDataCode2DArray;

}


// HALCON/C++ includes

#include "HTuple.h"
#include "HVector.h"
#include "HString.h"
#include "HException.h"
#include "HDevWindowStack.h"
#include "HObjectBase.h"
#include "HToolBase.h"
#include "HDataBase.h"
#include "HOperatorOverloads.h"


// Fully generated classes
#include "HalconCppIncludes.h"

// Include inline functions for streaming operations
#include "HIOStream.h"

// Defining the following two preprocessor constants
// enables a restricted source code compatibility mode
// for procedural legacy code

// Definining HCPP_LEGACY_API provides declarations for
// Hobject and HTuple members that are 

#if defined(HCPP_LEGACY_API)

// Allow to resolve obsolete class Hobject
namespace HalconCpp
{
  typedef HalconCpp::HObject Hobject;
}

// Allow to use global operator signatures with Herror return values */

#include "HOperatorSetLegacy.h"



// Defining HCPP_LEGACY_NAMESPACE will textually
// replace all references to the Halcon namespace with
// HalconCpp, with potential for name conflicts.

#if defined(HCPP_LEGACY_NAMESPACE)
// Remap namespace Halcon to HalconCpp
#define Halcon HalconCpp
#endif 

#endif // HCPP_LEGACY_API

#endif // HALCON_CPP_H
