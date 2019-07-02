/*****************************************************************************
 * HSerial.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HSerial
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_SERIAL_H
#define H_SERIAL_H


#include "HCPPToolRef.h"


namespace Halcon {


class LIntExport HSerial: public HToolBase 
{
public:

  // Tool-specific functional class constructors

  HSerial(const HTuple &PortName);
  HSerial(const char *PortName);

  // Common tool class management functionality

  HSerial();
  HSerial(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Clear the buffer of a serial connection.
  virtual void ClearSerial(const Halcon::HTuple &Channel) const;
  // Clear the buffer of a serial connection.
  virtual void ClearSerial(const char *Channel) const;
  // Write to a serial connection.
  virtual void WriteSerial(const Halcon::HTuple &Data) const;
  // Write to a serial connection.
  virtual void WriteSerial(Hlong Data) const;
  // Read from a serial device.
  virtual HTuple ReadSerial(const Halcon::HTuple &NumCharacters) const;
  // Read from a serial device.
  virtual HTuple ReadSerial(Hlong NumCharacters) const;
  // Get the parameters of a serial device.
  virtual Hlong GetSerialParam(Halcon::HTuple *DataBits, Halcon::HTuple *FlowControl, Halcon::HTuple *Parity, Halcon::HTuple *StopBits, Halcon::HTuple *TotalTimeOut, Halcon::HTuple *InterCharTimeOut) const;
  // Get the parameters of a serial device.
  virtual Hlong GetSerialParam(Hlong *DataBits, char *FlowControl, char *Parity, Hlong *StopBits, Hlong *TotalTimeOut, Hlong *InterCharTimeOut) const;
  // Set the parameters of a serial device.
  virtual void SetSerialParam(const Halcon::HTuple &BaudRate, const Halcon::HTuple &DataBits, const Halcon::HTuple &FlowControl, const Halcon::HTuple &Parity, const Halcon::HTuple &StopBits, const Halcon::HTuple &TotalTimeOut, const Halcon::HTuple &InterCharTimeOut) const;
  // Set the parameters of a serial device.
  virtual void SetSerialParam(Hlong BaudRate, Hlong DataBits, const char *FlowControl, const char *Parity, Hlong StopBits, Hlong TotalTimeOut, Hlong InterCharTimeOut) const;
  // Open a serial device.
  virtual void OpenSerial(const Halcon::HTuple &PortName);
  // Open a serial device.
  virtual void OpenSerial(const char *PortName);
};

}

#endif
