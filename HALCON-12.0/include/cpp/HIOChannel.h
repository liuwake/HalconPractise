/*****************************************************************************
 * HIOChannel.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HIOChannel
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_IO_CHANNEL_H
#define H_IO_CHANNEL_H


#include "HCPPToolRef.h"


namespace Halcon {


class LIntExport HIOChannel: public HToolBase 
{
public:

  // Tool-specific functional class constructors

  // open_io_channel: Open and configure an io device.
  HIOChannel(const HIODevice& IODeviceHandle, 
             const char * IOChannelName,
             const HTuple& ParamName, 
             const HTuple& ParamValue);


  // Common tool class management functionality

  HIOChannel();
  HIOChannel(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Perform an action on I/O channels.
  virtual HTuple ControlIoChannel(const Halcon::HTuple &ParamAction, const Halcon::HTuple &ParamArgument) const;
  // Write a value to the specified I/O channels.
  virtual HTuple WriteIoChannel(const Halcon::HTuple &Value) const;
  // Read a value from the specified I/O channels.
  virtual HTuple ReadIoChannel(Halcon::HTuple *Status) const;
  // Set specific parameters of I/O channels.
  virtual void SetIoChannelParam(const Halcon::HTuple &ParamName, const Halcon::HTuple &ParamValue) const;
  // Query specific parameters of I/O channels.
  virtual HTuple GetIoChannelParam(const Halcon::HTuple &ParamName) const;
  // Query specific parameters of I/O channels.
  virtual HTuple GetIoChannelParam(const char *ParamName) const;
  // Open and configure I/O channels.
  virtual void OpenIoChannel(const Halcon::HIODevice &IODeviceHandle, const Halcon::HTuple &IOChannelName, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue);
};

}

#endif
