/*****************************************************************************
 * HMutex.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HMutex
 *
 * (c) 2009-2014 by MVTec Software GmbH
 *               www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_MUTEX_H
#define H_MUTEX_H


#include "HCPPToolRef.h"


namespace Halcon {


class LIntExport HMutex: public HToolBase 
{
public:

  // Tool-specific functional class constructors
  
  HMutex(const HTuple &AttrName, const HTuple &AttrValue);
  //HMutex(const char *AttrName, const char *AttrValue);

  // Common tool class management functionality

  HMutex();
  HMutex(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Unlock a mutex synchronization object.
  virtual void UnlockMutex() const;
  // Lock a mutex synchronization object.
  virtual Hlong TryLockMutex() const;
  // Lock a mutex synchronization object.
  virtual void LockMutex() const;
  // Create a mutual exclusion synchronization object.
  virtual void CreateMutex(const Halcon::HTuple &AttribName, const Halcon::HTuple &AttribValue);
};

}

#endif
