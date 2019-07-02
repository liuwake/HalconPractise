/*****************************************************************************
 * HIODevice.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HIODevice
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_IO_DEVICE_H
#define H_IO_DEVICE_H


#include "HCPPToolRef.h"


namespace Halcon {


class LIntExport HIODevice: public HToolBase 
{
public:

  // Tool-specific functional class constructors

  // open_io_device: Open and configure an io device.
  HIODevice(const HTuple& IOInterfaceName, 
            const HTuple& IODeviceName, 
            const HTuple& ParamName, 
            const HTuple& ParamValue);

  // open_io_device: Open and configure an io device.
  HIODevice(const char* IOInterfaceName, 
            const char* IODeviceName, 
            const char* ParamName, 
            const char* ParamValue);



  // Common tool class management functionality

  HIODevice();
  HIODevice(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Open and configure I/O channels.
  virtual HTuple OpenIoChannel(const Halcon::HTuple &IOChannelName, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue) const;
  // Query information about channels of the specified I/O device.
  // 
  virtual HTuple QueryIoDevice(const Halcon::HTuple &IOChannelName, const Halcon::HTuple &Query) const;
  // Perform an action on the I/O device.
  virtual HTuple ControlIoDevice(const Halcon::HTuple &Action, const Halcon::HTuple &Argument) const;
  // Configure a specific I/O device instance.
  virtual void SetIoDeviceParam(const Halcon::HTuple &ParamName, const Halcon::HTuple &ParamValue) const;
  // Query settings of an I/O device instance.
  // 
  virtual HTuple GetIoDeviceParam(const Halcon::HTuple &ParamName) const;
  // Query settings of an I/O device instance.
  // 
  virtual HTuple GetIoDeviceParam(const char *ParamName) const;
  // Open and configure an I/O device.
  // 
  virtual void OpenIoDevice(const Halcon::HTuple &IOInterfaceName, const Halcon::HTuple &IODeviceName, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue);
  // Perform an action on the I/O interface.
  static HTuple ControlIoInterface(const Halcon::HTuple &IOInterfaceName, const Halcon::HTuple &Action, const Halcon::HTuple &Argument);
  // Query information about the specified I/O device interface.
  static HTuple QueryIoInterface(const Halcon::HTuple &IOInterfaceName, const Halcon::HTuple &Query);
  // Query information about the specified I/O device interface.
  static HTuple QueryIoInterface(const char *IOInterfaceName, const char *Query);
};

}

#endif
