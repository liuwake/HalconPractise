/*****************************************************************************
 * HCondition.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HCondition
 *
 * (c) 2009-2014 by MVTec Software GmbH
 *               www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_CONDITION_H
#define H_CONDITION_H


#include "HCPPToolRef.h"


namespace Halcon {


class LIntExport HCondition: public HToolBase 
{
public:

  // Tool-specific functional class constructors
  HCondition(const HTuple &AttrName,const HTuple &AttrValue);
  //HCondition(const char *AttrName,const char *AttrValue);

  // Common tool class management functionality

  HCondition();
  HCondition(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Signal a condition synchronization object.
  virtual void BroadcastCondition() const;
  // Signal a condition synchronization object.
  virtual void SignalCondition() const;
  // Bounded wait on the signal of a condition synchronization object.
  virtual void TimedWaitCondition(const Halcon::HMutex &MutexHandle, const Halcon::HTuple &Timeout) const;
  // Bounded wait on the signal of a condition synchronization object.
  virtual void TimedWaitCondition(const Halcon::HMutex &MutexHandle, Hlong Timeout) const;
  // wait on the signal of a condition synchronization object.
  virtual void WaitCondition(const Halcon::HMutex &MutexHandle) const;
  // Create a condition variable synchronization object.
  virtual void CreateCondition(const Halcon::HTuple &AttribName, const Halcon::HTuple &AttribValue);
};

}

#endif
