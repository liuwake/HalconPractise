/*****************************************************************************
 * HDataCode2D.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HDataCode2D
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_DATA_CODE_2D_H
#define H_DATA_CODE_2D_H


#include "HCPPToolRef.h"


namespace Halcon {


class LIntExport HDataCode2D: public HToolBase 
{
public:

  // Tool-specific functional class constructors
  
  HDataCode2D(const HTuple &SymbolType, 
              const HTuple &GenParamNames, 
              const HTuple &GenParamValues);

  // Common tool class management functionality

  HDataCode2D();
  HDataCode2D(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Get the alphanumerical results that were accumulated during the
  // search for 2D data code symbols.
  virtual HTuple GetDataCode2dResults(const Halcon::HTuple &CandidateHandle, const Halcon::HTuple &ResultNames) const;
  // Detect and read 2D data code symbols in an image or
  // train the 2D data code model.
  virtual HXLDContArray FindDataCode2d(const HImage &Image, const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues, Halcon::HTuple *ResultHandles, Halcon::HTuple *DecodedDataStrings) const;
  // Detect and read 2D data code symbols in an image or
  // train the 2D data code model.
  virtual HXLDContArray FindDataCode2d(const HImage &Image, const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues, Hlong *ResultHandles, char *DecodedDataStrings) const;
  // Detect and read 2D data code symbols in an image or
  // train the 2D data code model.
  virtual HXLDContArray FindDataCode2d(const HImage &Image, const char *GenParamNames, Hlong GenParamValues, Halcon::HTuple *ResultHandles, Halcon::HTuple *DecodedDataStrings) const;
  // Detect and read 2D data code symbols in an image or
  // train the 2D data code model.
  virtual HXLDContArray FindDataCode2d(const HImage &Image, const char *GenParamNames, Hlong GenParamValues, Hlong *ResultHandles, char *DecodedDataStrings) const;
  // Set selected parameters of the 2D data code model.
  virtual void SetDataCode2dParam(const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues) const;
  // Get one or several parameters that describe the 2D data code model.
  virtual HTuple GetDataCode2dParam(const Halcon::HTuple &GenParamNames) const;
  // Get one or several parameters that describe the 2D data code model.
  virtual HTuple GetDataCode2dParam(const char *GenParamNames) const;
  // Get for a given 2D data code model the names of the generic
  // parameters or objects that can be used in the other 2D data code
  // operators.
  virtual HTuple QueryDataCode2dParams(const Halcon::HTuple &QueryName) const;
  // Get for a given 2D data code model the names of the generic
  // parameters or objects that can be used in the other 2D data code
  // operators.
  virtual HTuple QueryDataCode2dParams(const char *QueryName) const;
  // Deserialize a serialized 2D data code model.
  virtual void DeserializeDataCode2dModel(const Halcon::HSerializedItem &SerializedItemHandle);
  // Serialize a 2D data code model.
  virtual HSerializedItem SerializeDataCode2dModel() const;
  // Read a 2D data code model from a file and create a new model.
  virtual void ReadDataCode2dModel(const Halcon::HTuple &FileName);
  // Read a 2D data code model from a file and create a new model.
  virtual void ReadDataCode2dModel(const char *FileName);
  // Writes a 2D data code model into a file.
  virtual void WriteDataCode2dModel(const Halcon::HTuple &FileName) const;
  // Writes a 2D data code model into a file.
  virtual void WriteDataCode2dModel(const char *FileName) const;
  // Create a model of a 2D data code class.
  virtual void CreateDataCode2dModel(const Halcon::HTuple &SymbolType, const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues);
};

}

#endif
