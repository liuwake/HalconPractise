/*****************************************************************************
 * HOCRKnn.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HOCRKnn
 *
 * (c) 2011-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_OCR_KNN_H
#define H_OCR_KNN_H


#include "HCPPToolRef.h"


namespace Halcon {


class LIntExport HOCRKnn: public HToolBase 
{
public:

  // Tool-specific functional class constructors

  HOCRKnn(const HTuple &WidthCharacter, const HTuple &HeightCharacter, 
          const HTuple &Interpolation, const HTuple &Features, 
          const HTuple &Characters, const HTuple &GenParamNames, 
          const HTuple &GenParamValues);


  // Common tool class management functionality

  HOCRKnn();
  HOCRKnn(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Classify a related group of characters with an OCR classifier.
  virtual HTuple DoOcrWordKnn(const HRegionArray &Character, const HImage &Image, const Halcon::HTuple &Expression, const Halcon::HTuple &NumAlternatives, const Halcon::HTuple &NumCorrections, Halcon::HTuple *Confidence, Halcon::HTuple *Word, Halcon::HTuple *Score) const;
  // Classify a related group of characters with an OCR classifier.
  virtual HTuple DoOcrWordKnn(const HRegionArray &Character, const HImage &Image, const Halcon::HTuple &Expression, const Halcon::HTuple &NumAlternatives, const Halcon::HTuple &NumCorrections, double *Confidence, char *Word, double *Score) const;
  // Classify a related group of characters with an OCR classifier.
  virtual HTuple DoOcrWordKnn(const HRegionArray &Character, const HImage &Image, const char *Expression, Hlong NumAlternatives, Hlong NumCorrections, Halcon::HTuple *Confidence, Halcon::HTuple *Word, Halcon::HTuple *Score) const;
  // Classify a related group of characters with an OCR classifier.
  virtual HTuple DoOcrWordKnn(const HRegionArray &Character, const HImage &Image, const char *Expression, Hlong NumAlternatives, Hlong NumCorrections, double *Confidence, char *Word, double *Score) const;
  // Deserialize a serialized k-NN-based OCR classifier.
  virtual void DeserializeOcrClassKnn(const Halcon::HSerializedItem &SerializedItemHandle);
  // Serialize a k-NN-based OCR classifier.
  virtual HSerializedItem SerializeOcrClassKnn() const;
  // Read an OCR classifier from a file.
  virtual void ReadOcrClassKnn(const Halcon::HTuple &FileName);
  // Read an OCR classifier from a file.
  virtual void ReadOcrClassKnn(const char *FileName);
  // Write a k-NN classifier for an OCR task to a file.
  virtual void WriteOcrClassKnn(const Halcon::HTuple &FileName) const;
  // Write a k-NN classifier for an OCR task to a file.
  virtual void WriteOcrClassKnn(const char *FileName) const;
  // Clear all OCR classifiers.
  static void ClearAllOcrClassKnn(void);
  // Create an OCR classifier using a k-Nearest Neighbor (k-NN) classifier.
  virtual void CreateOcrClassKnn(const Halcon::HTuple &WidthCharacter, const Halcon::HTuple &HeightCharacter, const Halcon::HTuple &Interpolation, const Halcon::HTuple &Features, const Halcon::HTuple &Characters, const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues);
  // Trains an k-NN classifier for an OCR task.
  virtual void TrainfOcrClassKnn(const Halcon::HTuple &TrainingFile, const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues) const;
  // Compute the features of a character.
  virtual HTuple GetFeaturesOcrClassKnn(const HImage &Character, const Halcon::HTuple &Transform) const;
  // Compute the features of a character.
  virtual HTuple GetFeaturesOcrClassKnn(const HImage &Character, const char *Transform) const;
  // Return the parameters of an OCR classifier.
  virtual Hlong GetParamsOcrClassKnn(Halcon::HTuple *HeightCharacter, Halcon::HTuple *Interpolation, Halcon::HTuple *Features, Halcon::HTuple *Characters, Halcon::HTuple *Preprocessing, Halcon::HTuple *NumTrees) const;
  // Return the parameters of an OCR classifier.
  virtual Hlong GetParamsOcrClassKnn(Hlong *HeightCharacter, char *Interpolation, char *Features, Halcon::HTuple *Characters, char *Preprocessing, Hlong *NumTrees) const;
  // Classify multiple characters with an k-NN classifier.
  virtual HTuple DoOcrMultiClassKnn(const HRegionArray &Character, const HImage &Image, Halcon::HTuple *Confidence) const;
  // Classify multiple characters with an k-NN classifier.
  virtual HTuple DoOcrMultiClassKnn(const HRegionArray &Character, const HImage &Image, double *Confidence) const;
  // Classify a single character with an OCR classifier.
  virtual HTuple DoOcrSingleClassKnn(const HRegion &Character, const HImage &Image, const Halcon::HTuple &NumClasses, const Halcon::HTuple &NumNeighbors, Halcon::HTuple *Confidence) const;
  // Classify a single character with an OCR classifier.
  virtual HTuple DoOcrSingleClassKnn(const HRegion &Character, const HImage &Image, const Halcon::HTuple &NumClasses, const Halcon::HTuple &NumNeighbors, double *Confidence) const;
  // Select an optimal combination of features to classify OCR data.
  virtual HTuple SelectFeatureSetTrainfKnn(const Halcon::HTuple &TrainingFile, const Halcon::HTuple &FeatureList, const Halcon::HTuple &SelectionMethod, const Halcon::HTuple &Width, const Halcon::HTuple &Height, const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues, Halcon::HTuple *Score);
  // Select an optimal combination of features to classify OCR data.
  virtual HTuple SelectFeatureSetTrainfKnn(const char *TrainingFile, const char *FeatureList, const char *SelectionMethod, Hlong Width, Hlong Height, const char *GenParamNames, double GenParamValues, Halcon::HTuple *Score);
};

}

#endif
