/*****************************************************************************
 * HBarCode1D.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HBarCode1D
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_BAR_CODE_1D_H
#define H_BAR_CODE_1D_H


namespace Halcon {


class LIntExport HBarCode1D: public HRootObject {
public:
  HBarCode1D(void) {id = -1;} 
  HBarCode1D(const HTuple &CodeName, 
             const HTuple &MinCharacters, 
             const HTuple &MaxCharacters);
  HBarCode1D(const char *CodeName, 
             Hlong MinCharacters, 
             Hlong MaxCharacters);
  HBarCode1D(const HTuple &MinCodeLength, 
             const HTuple &MaxCodeLength, 
             const HTuple &ElementSizes, 
             const HTuple &StartElement, 
             const HTuple &StopElement, 
             const HTuple &MaxSizeRatio, 
             const HTuple &DiscreteCode);
  HBarCode1D(Hlong MinCodeLength, 
             Hlong MaxCodeLength, 
             Hlong ElementSizes, 
             Hlong StartElement, 
             Hlong StopElement, 
             double MaxSizeRatio = 2.5, 
             const char *DiscreteCode = "false");

private:
  // Internal Cleanup
  void Cleanup(void);

public:
  // Tools
  const char *ClassName(void) const {return "HBarCode1D";}

  // Cast Operator
  operator HTuple () const {return GetHandle();}

  // Access and Manipulation
  HTuple GetHandle(void) const {return id;}
  void   SetHandle(HTuple ID) {id = ID;}

private:
  HTuple  id;
public:
  // Generate a discrete bar code from the elements widths.
  virtual HTuple Discrete1dBarCode(const Halcon::HTuple &Elements) const;
  // Decoding of a sequence of elements of a bar code.
  virtual HTuple Decode1dBarCode(const Halcon::HTuple &BarCodeElements, Halcon::HTuple *Reference, Halcon::HTuple *IsCorrect) const;
  // Decoding of a sequence of elements of a bar code.
  virtual HTuple Decode1dBarCode(const Halcon::HTuple &BarCodeElements, Halcon::HTuple *Reference, Hlong *IsCorrect) const;
  // Extract the widths of the elements inside a bar code region.
  virtual HTuple Get1dBarCodeScanline(const HImage &BarCodeRegion, const Halcon::HTuple &GenericName, const Halcon::HTuple &GenericValue, const Halcon::HTuple &Orientation, const Halcon::HTuple &StopIfFound, Halcon::HTuple *ScanlineNumPoints, Halcon::HTuple *ScanlineDecoded, Halcon::HTuple *ScanlinePointsRow, Halcon::HTuple *ScanlinePointsColumn) const;
  // Extract the widths of the elements inside a bar code region.
  virtual HTuple Get1dBarCodeScanline(const HImage &BarCodeRegion, const Halcon::HTuple &GenericName, const Halcon::HTuple &GenericValue, const Halcon::HTuple &Orientation, const Halcon::HTuple &StopIfFound, Hlong *ScanlineNumPoints, Hlong *ScanlineDecoded, double *ScanlinePointsRow, double *ScanlinePointsColumn) const;
  // Extract the widths of the elements inside a bar code region.
  virtual HTuple Get1dBarCode(const HImage &BarCodeRegion, const Halcon::HTuple &GenericName, const Halcon::HTuple &GenericValue, const Halcon::HTuple &Orientation) const;
  // Look for multiple bar code regions in an image.
  virtual HRegionArray Find1dBarCodeRegion(const HImage &Image, const Halcon::HTuple &GenericName, const Halcon::HTuple &GenericValue, Halcon::HTuple *Orientation) const;
  // Look for multiple bar code regions in an image.
  virtual HRegionArray Find1dBarCodeRegion(const HImage &Image, const Halcon::HTuple &GenericName, const Halcon::HTuple &GenericValue, double *Orientation) const;
  // Look for one bar code in an image.
  virtual HRegion Find1dBarCodeScanline(const HImage &Image, const Halcon::HTuple &GenericName, const Halcon::HTuple &GenericValue, const Halcon::HTuple &StopIfFound, Halcon::HTuple *BarcodeFound, Halcon::HTuple *BarCodeElements, Halcon::HTuple *Orientation, Halcon::HTuple *ScanlineNumPoints, Halcon::HTuple *ScanlineDecoded, Halcon::HTuple *ScanlinePointsRow, Halcon::HTuple *ScanlinePointsColumn) const;
  // Look for one bar code in an image.
  virtual HRegion Find1dBarCodeScanline(const HImage &Image, const Halcon::HTuple &GenericName, const Halcon::HTuple &GenericValue, const Halcon::HTuple &StopIfFound, Hlong *BarcodeFound, Halcon::HTuple *BarCodeElements, double *Orientation, Hlong *ScanlineNumPoints, Hlong *ScanlineDecoded, double *ScanlinePointsRow, double *ScanlinePointsColumn) const;
  // Look for one bar code in an image.
  virtual HRegion Find1dBarCode(const HImage &Image, const Halcon::HTuple &GenericName, const Halcon::HTuple &GenericValue, Halcon::HTuple *BarcodeFound, Halcon::HTuple *BarCodeElements, Halcon::HTuple *Orientation) const;
  // Look for one bar code in an image.
  virtual HRegion Find1dBarCode(const HImage &Image, const Halcon::HTuple &GenericName, const Halcon::HTuple &GenericValue, Hlong *BarcodeFound, Halcon::HTuple *BarCodeElements, double *Orientation) const;
  // Generate a description of a 1D bar code.
  virtual void Gen1dBarCodeDescr(const Halcon::HTuple &CodeName, const Halcon::HTuple &MinCharacters, const Halcon::HTuple &MaxCharacters);
  // Generate a description of a 1D bar code.
  virtual void Gen1dBarCodeDescr(const char *CodeName, Hlong MinCharacters, Hlong MaxCharacters);
  // Generate a generic description of a 1D bar code.
  virtual void Gen1dBarCodeDescrGen(const Halcon::HTuple &MinCodeLength, const Halcon::HTuple &MaxCodeLength, const Halcon::HTuple &ElementSizes, const Halcon::HTuple &StartElement, const Halcon::HTuple &StopElement, const Halcon::HTuple &MaxSizeRatio, const Halcon::HTuple &DiscreteCode);
  // Generate a generic description of a 1D bar code.
  virtual void Gen1dBarCodeDescrGen(Hlong MinCodeLength, Hlong MaxCodeLength, Hlong ElementSizes, Hlong StartElement, Hlong StopElement, double MaxSizeRatio, const char *DiscreteCode);
};

}

#endif
