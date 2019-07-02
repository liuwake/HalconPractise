/*****************************************************************************
 * HColorTransLUT.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HColorTransLUT
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_COLOR_TRANS_LUT_H
#define H_COLOR_TRANS_LUT_H


#include "HCPPToolRef.h"


namespace Halcon {


class LIntExport HColorTransLUT: public HToolBase 
{
public:

  // Tool-specific functional class constructors
  
  HColorTransLUT(const HTuple &ColorSpace, const HTuple &TransDirection,
                 const HTuple &NumBits);
  HColorTransLUT(const char *ColorSpace, const char *TransDirection,
                 Hlong NumBits = 8);

  // Common tool class management functionality

  HColorTransLUT();
  HColorTransLUT(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Color space transformation using pre-generated look-up-table.
  virtual HImage ApplyColorTransLut(const HImage &Image1, const HImage &Image2, const HImage &Image3, HImage *ImageResult2, HImage *ImageResult3) const;
  // Creates the look-up-table for transformation of an image from the
  // RGB color space to an arbitrary color space.
  virtual void CreateColorTransLut(const Halcon::HTuple &ColorSpace, const Halcon::HTuple &TransDirection, const Halcon::HTuple &NumBits);
  // Creates the look-up-table for transformation of an image from the
  // RGB color space to an arbitrary color space.
  virtual void CreateColorTransLut(const char *ColorSpace, const char *TransDirection, Hlong NumBits);
};

}

#endif
