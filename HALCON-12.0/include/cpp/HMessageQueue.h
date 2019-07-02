/*****************************************************************************
 * HMessageQueue.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HMessageQueue
 *
 * (c) 2009-2014 by MVTec Software GmbH
 *               www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_MESSAGEQUEUE_H
#define H_MESSAGEQUEUE_H


#include "HCPPToolRef.h"


namespace Halcon {


class LIntExport HMessageQueue: public HToolBase 
{
public:

  // Tool-specific functional class constructors

  // Common tool class management functionality

  HMessageQueue();
  HMessageQueue(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Query message queue parameters or information about the queue.
  virtual HTuple GetMessageQueueParam(const Halcon::HTuple &GenParamName) const;
  // Query message queue parameters or information about the queue.
  virtual HTuple GetMessageQueueParam(const char *GenParamName) const;
  // Set message queue parameters or invokes commands on the queue.
  virtual void SetMessageQueueParam(const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue) const;
  // Receive one or more messages from the message queue.
  virtual HTuple DequeueMessage(const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue) const;
  // Enqueue one or more messages to the message queue.
  virtual void EnqueueMessage(const Halcon::HTuple &MessageHandle, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue) const;
  // Create a new empty message queue.
  virtual void CreateMessageQueue(void);
};

}

#endif
