/*****************************************************************************
 * HSocket.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HSocket
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_SOCKET_H
#define H_SOCKET_H


#include "HCPPToolRef.h"


namespace Halcon {


class LIntExport HSocket: public HToolBase 
{
public:

  // Tool-specific functional class constructors

  HSocket(const HTuple &Port,
          const Halcon::HTuple &GenParamName,
          const Halcon::HTuple &GenParamValue);
  HSocket(Hlong Port);
  HSocket(const HTuple &HostName,
          const HTuple &Port,
          const Halcon::HTuple &GenParamName,
          const Halcon::HTuple &GenParamValue);
  HSocket(const char *HostName, Hlong Port);

  // Common tool class management functionality

  HSocket();
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Receive an image over a socket connection.
  virtual HImageArray ReceiveImage() const;
  // Send an image over a socket connection.
  virtual void SendImage(const HImageArray &Image) const;
  // Receive regions over a socket connection.
  virtual HRegionArray ReceiveRegion() const;
  // Send regions over a socket connection.
  virtual void SendRegion(const HRegionArray &Region) const;
  // Receive an XLD object over a socket connection.
  virtual HXLDArray ReceiveXld() const;
  // Send an XLD object over a socket connection.
  virtual void SendXld(const HXLDArray &XLD) const;
  // Receive a tuple over a socket connection.
  virtual HTuple ReceiveTuple() const;
  // Send a tuple over a socket connection.
  virtual void SendTuple(const Halcon::HTuple &Tuple) const;
  // Receive arbitrary data from external devices or applications using a
  // generic socket connection.
  virtual HTuple ReceiveData(const Halcon::HTuple &Format, Halcon::HTuple *From) const;
  // Receive arbitrary data from external devices or applications using a
  // generic socket connection.
  virtual HTuple ReceiveData(const Halcon::HTuple &Format, char *From) const;
  // Receive arbitrary data from external devices or applications using a
  // generic socket connection.
  virtual HTuple ReceiveData(const char *Format, Halcon::HTuple *From) const;
  // Receive arbitrary data from external devices or applications using a
  // generic socket connection.
  virtual HTuple ReceiveData(const char *Format, char *From) const;
  // Send arbitrary data to external devices or applications using a
  // generic socket communication.
  virtual void SendData(const Halcon::HTuple &Format, const Halcon::HTuple &Data, const Halcon::HTuple &To) const;
  // Get the value of a socket parameter.
  virtual HTuple GetSocketParam(const Halcon::HTuple &ParamName) const;
  // Get the value of a socket parameter.
  virtual HTuple GetSocketParam(const char *ParamName) const;
  // Set a socket parameter.
  virtual void SetSocketParam(const Halcon::HTuple &ParamName, const Halcon::HTuple &ParamValue) const;
  // Determine the HALCON data type of the next socket data.
  virtual HTuple GetNextSocketDataType() const;
  // Get the socket descriptor of a socket used by the operating system.
  virtual Hlong GetSocketDescriptor() const;
  // Get the timeout of a socket.
  virtual double GetSocketTimeout() const;
  // Set the timeout of a socket.
  virtual void SetSocketTimeout(const Halcon::HTuple &Timeout) const;
  // Set the timeout of a socket.
  virtual void SetSocketTimeout(double Timeout) const;
  // Close all opened sockets.
  static void CloseAllSockets(void);
  // Accept a connection request on a listening socket of the protocol type
  //  'HALCON' or 'TCP'/'TCP4'/'TCP6'.
  virtual HSocket SocketAcceptConnect(const Halcon::HTuple &Wait) const;
  // Accept a connection request on a listening socket of the protocol type
  //  'HALCON' or 'TCP'/'TCP4'/'TCP6'.
  virtual HSocket SocketAcceptConnect(const char *Wait) const;
  // Open a socket and connect it to an accepting socket.
  virtual void OpenSocketConnect(const Halcon::HTuple &HostName, const Halcon::HTuple &Port, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue);
  // Open a socket that accepts connection requests.
  virtual void OpenSocketAccept(const Halcon::HTuple &Port, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue);
  // Receive a serialized item over a socket connection.
  virtual HSerializedItem ReceiveSerializedItem() const;
  // Send a serialized item over a socket connection.
  virtual void SendSerializedItem(const Halcon::HSerializedItem &SerializedItemHandle) const;
};

}

#endif
