/*****************************************************************************
 * HBarCode2D.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HBarCode2D
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_BAR_CODE_2D_H
#define H_BAR_CODE_2D_H


namespace Halcon {


class LIntExport HBarCode2D: public HRootObject {
public:
  HBarCode2D(void) {id = -1;} 
  HBarCode2D(const HTuple &CodeType, 
             const HTuple &GenParamNames, 
             const HTuple &GenParamValues);

private:
  // Internal Cleanup
  void Cleanup(void);

public:
  // Tools
  const char *ClassName(void) const {return "HBarCode2D";}

  // Cast Operator
  operator HTuple () const {return GetHandle();}

  // Access and Manipulation
  HTuple GetHandle(void) const {return id;}
  void   SetHandle(Hlong ID) {id = ID;}

private:
  HTuple  id;
public:
  // Decode 2D bar code data.
  virtual HTuple Decode2dBarCode(const Halcon::HTuple &BarCodeDimension, const Halcon::HTuple &BarCodeData, Halcon::HTuple *CorrSymbolData, Halcon::HTuple *DecodedData, Halcon::HTuple *DecodingError, Halcon::HTuple *StructuredAppend) const;
  // Decode 2D bar code data.
  virtual HTuple Decode2dBarCode(const Halcon::HTuple &BarCodeDimension, const Halcon::HTuple &BarCodeData, Halcon::HTuple *CorrSymbolData, Halcon::HTuple *DecodedData, Hlong *DecodingError, Halcon::HTuple *StructuredAppend) const;
  // Extract the data values of the elements (in ECC 200: "modules") inside a
  // bar code region ("Data Matrix symbol") and their positions in the image.
  virtual HTuple Get2dBarCodePos(const HRegion &BarCodeRegion, const HImage &Image, const Halcon::HTuple &CodeRegDescr, const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues, Halcon::HTuple *BarCodeData, Halcon::HTuple *DataElementRow, Halcon::HTuple *DataElementCol) const;
  // Extract the values of the data elements (in ECC 200: "modules") inside a
  // bar code region ("Data Matrix symbol").
  virtual HTuple Get2dBarCode(const HRegion &BarCodeRegion, const HImage &Image, const Halcon::HTuple &CodeRegDescr, const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues, Halcon::HTuple *BarCodeData) const;
  // Find regions that might contain a 2D bar code.
  virtual HRegionArray Find2dBarCode(const HImage &Image, const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues, Halcon::HTuple *CodeRegDescr) const;
  // Generate a generic description of a 2D bar code class.
  virtual void Gen2dBarCodeDescr(const Halcon::HTuple &CodeType, const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues);
};

}

#endif
