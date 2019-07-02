/*****************************************************************************
 * HEvent.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HEvent
 *
 * (c) 2009-2014 by MVTec Software GmbH
 *               www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_EVENT_H
#define H_EVENT_H


#include "HCPPToolRef.h"


namespace Halcon {


class LIntExport HEvent: public HToolBase 
{
public:

  // Tool-specific functional class constructors
  HEvent(const HTuple &AttrName, const HTuple &AttrValue);
  // HEvent(const char *AttrName, const char *AttrValue);

  // Common tool class management functionality

  HEvent();
  HEvent(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Unlock an event synchronization object.
  // 
  virtual void SignalEvent() const;
  // Lock an event synchronization object only it is unlocked.
  virtual Hlong TryWaitEvent() const;
  // Lock an event synchronization object.
  virtual void WaitEvent() const;
  // Create an event synchronization object.
  virtual void CreateEvent(const Halcon::HTuple &AttribName, const Halcon::HTuple &AttribValue);
};

}

#endif
