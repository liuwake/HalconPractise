/*****************************************************************************
 * HComputeDevice.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HComputeDevice
 *
 * (c) 2009-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_COMPUTE_DEVICE_H
#define H_COMPUTE_DEVICE_H


#include "HCPPToolRef.h"


namespace Halcon {


class LIntExport HComputeDevice: public HToolBase 
{
  
public:

  // Tool-specific functional class constructors

  //HComputeDevice(const long DeviceIdentifier);
  HComputeDevice(const HTuple &DeviceIdentifier);

  // Common tool class management functionality

  HComputeDevice();
  HComputeDevice(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Query compute device parameters.
  virtual HTuple GetComputeDeviceParam(const Halcon::HTuple &ParamName) const;
  // Query compute device parameters.
  virtual HTuple GetComputeDeviceParam(const char *ParamName) const;
  // Set parameters of an compute device.
  virtual void SetComputeDeviceParam(const Halcon::HTuple &ParamName, const Halcon::HTuple &ParamValue) const;
  // Close all compute devices.
  static void ReleaseAllComputeDevices(void);
  // Close a compute_device.
  virtual void ReleaseComputeDevice() const;
  // Deactivate all compute devices.
  static void DeactivateAllComputeDevices(void);
  // Deactivate a compute device.
  virtual void DeactivateComputeDevice() const;
  // Activate a compute device.
  virtual void ActivateComputeDevice() const;
  // Initialize a compute device.
  virtual void InitComputeDevice(const Halcon::HTuple &Operators) const;
  // Open a compute device.
  virtual void OpenComputeDevice(const Halcon::HTuple &DeviceIdentifier);
  // Open a compute device.
  virtual void OpenComputeDevice(Hlong DeviceIdentifier);
  // Get information on a compute device.
  static HTuple GetComputeDeviceInfo(const Halcon::HTuple &DeviceIdentifier, const Halcon::HTuple &InfoName);
  // Get information on a compute device.
  static HTuple GetComputeDeviceInfo(Hlong DeviceIdentifier, const char *InfoName);
  // Get the list of available compute devices.
  static HTuple QueryAvailableComputeDevices(void);
};

}

#endif
