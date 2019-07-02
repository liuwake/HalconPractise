/*****************************************************************************
 * HClassLUT.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HClassLUT
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_CLASS_LUT_H
#define H_CLASS_LUT_H


#include "HCPPToolRef.h"


namespace Halcon {


class LIntExport HClassLUT: public HToolBase 
{
  friend class HClassMlp;
  friend class HClassSvm;
  friend class HClassGmm;
  
public:

  // Tool-specific functional class constructors

  HClassLUT(const HClassGmm &GMMHandle, 
            const HTuple &GenParamNames, 
            const HTuple &GenParamValues);
  HClassLUT(const HClassSvm &SVMHandle,
            const HTuple &GenParamNames,
            const HTuple &GenParamValues);
  HClassLUT(const HClassMlp &MLPHandle,
            const HTuple &GenParamNames,
            const HTuple &GenParamValues);
  // Common tool class management functionality

  HClassLUT();
  HClassLUT(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Classify a byte image using a look-up table.
  virtual HRegionArray ClassifyImageClassLut(const HImage &Image) const;
  // Create a look-up table using a k-nearest neighbors
  // classifier (k-NN) to classify byte
  // images.
  virtual void CreateClassLutKnn(const Halcon::HClassKnn &KNNHandle, const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues);
  // Create a look-up table using a gaussian mixture model to classify byte
  // images.
  virtual void CreateClassLutGmm(const Halcon::HClassGmm &GMMHandle, const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues);
  // Create a look-up table using a Support-Vector-Machine to classify byte
  // images.
  virtual void CreateClassLutSvm(const Halcon::HClassSvm &SVMHandle, const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues);
  // Create a look-up table using a multi-layer perceptron to classify byte
  // images.
  virtual void CreateClassLutMlp(const Halcon::HClassMlp &MLPHandle, const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues);
};

}

#endif
