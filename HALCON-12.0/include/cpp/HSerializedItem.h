/*****************************************************************************
 * HSerializedItem.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HSerializedItem
 *
 * (c) 2011-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 * $
 * $
 *
 */

#ifndef H_SERIALIZED_ITEM_H
#define H_SERIALIZED_ITEM_H


#include "HCPPToolRef.h"


namespace Halcon {


class LIntExport HSerializedItem: public HToolBase 
{
public:

  // Tool-specific functional class constructors
  
  HSerializedItem(
      const HTuple &Pointer, const HTuple &Size, const HTuple &Copy); 

  HSerializedItem(
      const Hlong pointer, const Hlong size, const char *copy);

  // Common tool class management functionality

  HSerializedItem();
  HSerializedItem(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Receive a serialized item over a socket connection.
  virtual void ReceiveSerializedItem(const Halcon::HSocket &Socket);
  // Send a serialized item over a socket connection.
  virtual void SendSerializedItem(const Halcon::HSocket &Socket) const;
  // Write a serialized item to a file.
  virtual void FwriteSerializedItem(const Halcon::HFile &FileHandle) const;
  // Read a serialized item from a file.
  virtual void FreadSerializedItem(const Halcon::HFile &FileHandle);
  // Delete all current existing serialized items.
  static void ClearAllSerializedItems(void);
  // Access the data pointer of a serialized item.
  virtual Hlong GetSerializedItemPtr(Halcon::HTuple *Size) const;
  // Access the data pointer of a serialized item.
  virtual Hlong GetSerializedItemPtr(Hlong *Size) const;
  // Create a serialized item.
  virtual void CreateSerializedItemPtr(const Halcon::HTuple &Pointer, const Halcon::HTuple &Size, const Halcon::HTuple &Copy);
  // Create a serialized item.
  virtual void CreateSerializedItemPtr(Hlong Pointer, Hlong Size, const char *Copy);
};

}

#endif
