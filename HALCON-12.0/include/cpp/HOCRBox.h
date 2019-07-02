/*****************************************************************************
 * HOCRBox.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HOCRBox
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_OCR_BOX_H
#define H_OCR_BOX_H


#include "HCPPToolRef.h"


namespace Halcon {


class LIntExport HOCRBox: public HToolBase 
{
public:

  // Tool-specific functional class constructors
  
  HOCRBox(const HTuple &WidthPattern, const HTuple &HeightPattern, 
       const HTuple &Interpolation, 
       const HTuple &Features, 
       const HTuple &Character);

  // Common tool class management functionality

  HOCRBox();
  HOCRBox(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Serialize an OCR classifier.
  virtual HSerializedItem SerializeOcr() const;
  // Deserialize a serialized OCR classifier.
  virtual void DeserializeOcr(const Halcon::HSerializedItem &SerializedItemHandle);
  // Writing an OCR classifier into a file.
  virtual void WriteOcr(const Halcon::HTuple &FileName) const;
  // Writing an OCR classifier into a file.
  virtual void WriteOcr(const char *FileName) const;
  // Read an OCR classifier from a file.
  virtual void ReadOcr(const Halcon::HTuple &FileName);
  // Read an OCR classifier from a file.
  virtual void ReadOcr(const char *FileName);
  // Classify one character.
  virtual HTuple DoOcrSingle(const HRegion &Character, const HImage &Image, Halcon::HTuple *Confidences) const;
  // Classify characters.
  virtual HTuple DoOcrMulti(const HRegionArray &Character, const HImage &Image, Halcon::HTuple *Confidence) const;
  // Classify characters.
  virtual HTuple DoOcrMulti(const HRegionArray &Character, const HImage &Image, double *Confidence) const;
  // Get information about an OCR classifier.
  virtual Hlong InfoOcrClassBox(Halcon::HTuple *HeightPattern, Halcon::HTuple *Interpolation, Halcon::HTuple *WidthMaxChar, Halcon::HTuple *HeightMaxChar, Halcon::HTuple *Features, Halcon::HTuple *Characters) const;
  // Get information about an OCR classifier.
  virtual Hlong InfoOcrClassBox(Hlong *HeightPattern, Hlong *Interpolation, Hlong *WidthMaxChar, Hlong *HeightMaxChar, Halcon::HTuple *Features, Halcon::HTuple *Characters) const;
  // Create a new OCR-classifier.
  virtual void CreateOcrClassBox(const Halcon::HTuple &WidthPattern, const Halcon::HTuple &HeightPattern, const Halcon::HTuple &Interpolation, const Halcon::HTuple &Features, const Halcon::HTuple &Character);
  // Train an OCR classifier by the input of regions.
  virtual double TraindOcrClassBox(const HRegionArray &Character, const HImage &Image, const Halcon::HTuple &Class) const;
  // Train an OCR classifier by the input of regions.
  virtual double TraindOcrClassBox(const HRegionArray &Character, const HImage &Image, const char *Class) const;
  // Train an OCR classifier with the help of a training file.
  virtual double TrainfOcrClassBox(const Halcon::HTuple &TrainingFile) const;
  // Train an OCR classifier with the help of a training file.
  virtual double TrainfOcrClassBox(const char *TrainingFile) const;
  // Define a new conversion table for the characters.
  virtual void OcrChangeChar(const Halcon::HTuple &Character) const;
  // Test an OCR classifier.
  virtual HTuple TestdOcrClassBox(const HRegionArray &Character, const HImage &Image, const Halcon::HTuple &Class) const;
  // Test an OCR classifier.
  virtual HTuple TestdOcrClassBox(const HRegionArray &Character, const HImage &Image, const char *Class) const;
  // Access the features which correspond to a character.
  virtual HTuple OcrGetFeatures(const HImage &Character) const;
};

}

#endif
