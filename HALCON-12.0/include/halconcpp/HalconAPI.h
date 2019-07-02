/*****************************************************************************
 * HalconAPI.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Internal communication with HALCON library.
 *              Exposed for use by extension packages only.
 *
 * (c) 2010-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 *****************************************************************************/



#ifndef HCPP_HALCON_API_H
#define HCPP_HALCON_API_H


#include "HSync.h"
#include "hlib/DBNew.h"
#include "hlib/HInstance.h"


namespace HalconCpp 
{

class LIntExport HalconAPI
{

public:


  // Create operator call
  static Hproc_handle PreCall(INT proc_index);
  
  // Execute operator call
  static void CallProcedure(Hproc_handle proc);
  
  // Finalize operator call
  static void PostCall(Hproc_handle proc, Herror err = H_MSG_OK);


  // Store iconic input parameters

  static void Store(Hproc_handle proc, INT par, const HObjectBase& obj);
  static void Store(Hproc_handle proc, INT par, Hkey key);


  // Load iconic output parameters
  
  static void Load(Hproc_handle proc, INT par, HObjectBase* obj);
  static void Load(Hproc_handle proc, INT par, Hkey* key);
  

  // Store input control parameters

  static void Store(Hproc_handle proc, INT par, Hlong value);
  static void Store(Hproc_handle proc, INT par, double value);
  static void Store(Hproc_handle proc, INT par, const char* value);
  static void Store(Hproc_handle proc, INT par, const HString& value);
  static void Store(Hproc_handle proc, INT par, const HTuple &tuple);

  static void Store(Hproc_handle proc, INT par, const HToolBase &tool);
  static HTuple StoreKA(Hproc_handle proc, INT par, const HDataBase &data);
  static HTuple StoreKA(Hproc_handle proc, INT par, const HToolArray& tools);
  static HTuple StoreKA(Hproc_handle proc, INT par, const HDataArray& data);
  static void Store(Hproc_handle proc, INT par, void* pointer);


  // Load output control parameters

  static void Load(Hproc_handle proc, INT par, Hlong* value);
  static void Load(Hproc_handle proc, INT par, double* value);
  static void Load(Hproc_handle proc, INT par, HString* value);
  static void Load(Hproc_handle proc, INT par, HTuple* tuple);

  static void Load(Hproc_handle proc, INT par, HToolBase* tool);
  static void Load(Hproc_handle proc, INT par, HDataBase* data);
  static void Load(Hproc_handle proc, INT par, HToolArray* tools);
  static void Load(Hproc_handle proc, INT par, HDataArray* data);
  static void Load(Hproc_handle proc, INT par, void** pointer);

  // Initialize output control parameters
  static void InitOutp(Hproc_handle proc, INT par);


  // Iconic object manipulation

  static Hkey CopyObject(Hkey key);
  static Hkey SelectObject(Hkey key, Hlong index);
  static bool TestEqualObj(Hkey key1, Hkey key2);
  static void ClearObject(Hkey key);
  static void AssertObjectClass(Hkey key, const char* assert_class);
};


}


#endif
