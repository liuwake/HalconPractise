/*****************************************************************************
 * HDevWindowStack.h
 ***************************************************************************** 
 *
 * Project:     Halcon/C++
 * Description: Class HDevWindowStack
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 */

#ifndef H_DEVWINDOWSTACK_H
#define H_DEVWINDOWSTACK_H
#include "HalconCpp.h"

namespace Halcon {

// The class HDevWindowStack can be used to emulate the behavior of HDevelop
// graphics windows for HALCON graphics windows. It is primarily intended for
// usage in C++ programs exported from HDevelop programs containing HDevelop
// window operators (e.g. dev_set_window, dev_open_window, dev_close_window...)
class LIntExport HDevWindowStack
{
public:  

  static void Push(const HTuple &win_handle);
  static HTuple Pop();       // no window open -> return empty tuple
  static HTuple GetActive(); // no window open -> return -1
  static void SetActive(const HTuple &win_handle); // no window open -> done
  static bool IsOpen();
  static void CloseAll();
};

}

#endif


