/*****************************************************************************
 * HMessage.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HMessage
 *
 * (c) 2009-2014 by MVTec Software GmbH
 *               www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_MESSAGE_H
#define H_MESSAGE_H


#include "HCPPToolRef.h"


namespace Halcon {


class LIntExport HMessage: public HToolBase 
{
public:


  // Common tool class management functionality

  HMessage();
  HMessage(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Query message parameters or information about the message.
  virtual HTuple GetMessageParam(const Halcon::HTuple &GenParamName, const Halcon::HTuple &Key) const;
  // Query message parameters or information about the message.
  virtual HTuple GetMessageParam(const char *GenParamName, const char *Key) const;
  // Set message parameter or invoke commands on the message.
  virtual void SetMessageParam(const Halcon::HTuple &GenParamName, const Halcon::HTuple &Key, const Halcon::HTuple &GenParamValue) const;
  // Add a key/object pair to the message.
  virtual void SetMessageObj(const HObjectArray &ObjectData, const Halcon::HTuple &Key) const;
  // Add a key/object pair to the message.
  virtual void SetMessageObj(const HObjectArray &ObjectData, const char *Key) const;
  // Retrieve a tuple associated with the key from the message.
  virtual HTuple GetMessageTuple(const Halcon::HTuple &Key) const;
  // Retrieve a tuple associated with the key from the message.
  virtual HTuple GetMessageTuple(const char *Key) const;
  // Add a key/tuple pair to the message.
  virtual void SetMessageTuple(const Halcon::HTuple &Key, const Halcon::HTuple &TupleData) const;
  // Create a new empty message.
  virtual void CreateMessage(void);
};

}

#endif
