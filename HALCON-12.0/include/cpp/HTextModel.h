/*****************************************************************************
 * HTextModel.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HTextModel
 *
 * (c) 2009-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_TEXT_MODEL_H
#define H_TEXT_MODEL_H


#include "HCPPToolRef.h"


namespace Halcon {


class LIntExport HTextModel: public HToolBase 
{
  friend class HImage;
  friend class HTextResult;
public:

  // Tool-specific functional class constructors

  HTextModel(const char *Mode,
             const char *MLPClassifier);

  // Common tool class management functionality

  HTextModel();
  HTextModel(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Find text in an image.
  virtual HTextResult FindText(const HImage &Image) const;
  // Query parameters of a text model.
  virtual HTuple GetTextModelParam(const Halcon::HTuple &GenParamName) const;
  // Query parameters of a text model.
  virtual HTuple GetTextModelParam(const char *GenParamName) const;
  // Set parameters of a text model.
  virtual void SetTextModelParam(const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue) const;
  // Set parameters of a text model.
  virtual void SetTextModelParam(const char *GenParamName, Hlong GenParamValue) const;
  // Create a text model.
  virtual void CreateTextModelReader(const Halcon::HTuple &Mode, const Halcon::HTuple &OCRClassifierMLP);
  // Create a text model.
  virtual void CreateTextModel(void);
};

}

#endif
