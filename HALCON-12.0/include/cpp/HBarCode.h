/*****************************************************************************
 * HBarCode.i
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HBarCode
 *
 * (c) 2007-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */


#ifndef H_BAR_CODE_H
#define H_BAR_CODE_H


#include "HCPPToolRef.h"


namespace Halcon {


class LIntExport HBarCode: public HToolBase 
{
public:

  // Tool-specific functional class constructors

  HBarCode(const HTuple &GenParamNames, 
           const HTuple &GenParamValues);
           
  HBarCode(const char *GenParamNames, 
           const char *GenParamValues);

  // Common tool class management functionality

  HBarCode();
  HBarCode(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Deserialize a bar code model.
  virtual void DeserializeBarCodeModel(const Halcon::HSerializedItem &SerializedItemHandle);
  // Serialize a bar code model.
  virtual HSerializedItem SerializeBarCodeModel() const;
  // Read a bar code model from a file and create a new model.
  virtual void ReadBarCodeModel(const Halcon::HTuple &FileName);
  // Read a bar code model from a file and create a new model.
  virtual void ReadBarCodeModel(const char *FileName);
  // Write a bar code model to a file.
  virtual void WriteBarCodeModel(const Halcon::HTuple &FileName) const;
  // Write a bar code model to a file.
  virtual void WriteBarCodeModel(const char *FileName) const;
  // Get the alphanumerical results that were accumulated during the
  // decoding of bar code symbols.
  virtual HTuple GetBarCodeResult(const Halcon::HTuple &CandidateHandle, const Halcon::HTuple &ResultName) const;
  // Decode bar code symbols within a rectangle.
  virtual HTuple DecodeBarCodeRectangle2(const HImage &Image, const Halcon::HTuple &CodeType, const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Phi, const Halcon::HTuple &Length1, const Halcon::HTuple &Length2) const;
  // Decode bar code symbols within a rectangle.
  virtual HTuple DecodeBarCodeRectangle2(const HImage &Image, const char *CodeType, double Row, double Column, double Phi, double Length1, double Length2) const;
  // Detect and read bar code symbols in an image.
  virtual HRegionArray FindBarCode(const HImage &Image, const Halcon::HTuple &CodeType, Halcon::HTuple *DecodedDataStrings) const;
  // Detect and read bar code symbols in an image.
  virtual HRegionArray FindBarCode(const HImage &Image, const Halcon::HTuple &CodeType, char *DecodedDataStrings) const;
  // Detect and read bar code symbols in an image.
  virtual HRegionArray FindBarCode(const HImage &Image, const char *CodeType, Halcon::HTuple *DecodedDataStrings) const;
  // Detect and read bar code symbols in an image.
  virtual HRegionArray FindBarCode(const HImage &Image, const char *CodeType, char *DecodedDataStrings) const;
  // Get the names of the parameters that can be used in set_bar_code* and
  // get_bar_code* operators for a given bar code model
  virtual HTuple QueryBarCodeParams(const Halcon::HTuple &Properties) const;
  // Get the names of the parameters that can be used in set_bar_code* and
  // get_bar_code* operators for a given bar code model
  virtual HTuple QueryBarCodeParams(const char *Properties) const;
  // Get parameters that are used by the bar code reader when processing a
  // specific bar code type.
  // 
  virtual HTuple GetBarCodeParamSpecific(const Halcon::HTuple &CodeTypes, const Halcon::HTuple &GenParamNames) const;
  // Get parameters that are used by the bar code reader when processing a
  // specific bar code type.
  // 
  virtual HTuple GetBarCodeParamSpecific(const char *CodeTypes, const char *GenParamNames) const;
  // Get one or several parameters that describe the bar code model.
  virtual HTuple GetBarCodeParam(const Halcon::HTuple &GenParamNames) const;
  // Get one or several parameters that describe the bar code model.
  virtual HTuple GetBarCodeParam(const char *GenParamNames) const;
  // Set selected parameters of the bar code model for selected bar code types
  virtual void SetBarCodeParamSpecific(const Halcon::HTuple &CodeTypes, const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues) const;
  // Set selected parameters of the bar code model for selected bar code types
  virtual void SetBarCodeParamSpecific(const char *CodeTypes, const char *GenParamNames, double GenParamValues) const;
  // Set selected parameters of the bar code model.
  virtual void SetBarCodeParam(const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues) const;
  // Set selected parameters of the bar code model.
  virtual void SetBarCodeParam(const char *GenParamNames, double GenParamValues) const;
  // Create a model of a bar code reader.
  virtual void CreateBarCodeModel(const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues);
  // Create a model of a bar code reader.
  virtual void CreateBarCodeModel(const char *GenParamNames, double GenParamValues);
};

}

#endif
