/*****************************************************************************
 * HOCRSvm.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HOCRSvm
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_OCRSVM_H
#define H_OCRSVM_H


#include "HCPPToolRef.h"


namespace Halcon {


class LIntExport HOCRSvm: public HToolBase 
{
public:

  // Tool-specific functional class constructors

  HOCRSvm(const HTuple &WidthCharacter, const HTuple &HeightCharacter, 
          const HTuple &Interpolation, const HTuple &Features, 
          const HTuple &Characters, const HTuple &KernelType,
          const HTuple &KernelParam, const HTuple &Nu, const HTuple &Mode,
          const HTuple &Preprocessing, const HTuple &NumComponents);

  // Common tool class management functionality

  HOCRSvm();
  HOCRSvm(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Select an optimal combination of features to classify OCR data
  // from a (protected) training file.
  virtual HTuple SelectFeatureSetTrainfSvmProtected(const Halcon::HTuple &TrainingFile, const Halcon::HTuple &Password, const Halcon::HTuple &FeatureList, const Halcon::HTuple &SelectionMethod, const Halcon::HTuple &Width, const Halcon::HTuple &Height, const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues, Halcon::HTuple *Score);
  // Select an optimal combination of features to classify OCR data
  // from a (protected) training file.
  virtual HTuple SelectFeatureSetTrainfSvmProtected(const char *TrainingFile, const char *Password, const char *FeatureList, const char *SelectionMethod, Hlong Width, Hlong Height, const char *GenParamNames, double GenParamValues, Halcon::HTuple *Score);
  // Selects an optimal combination of features to classify OCR  data.
  virtual HTuple SelectFeatureSetTrainfSvm(const Halcon::HTuple &TrainingFile, const Halcon::HTuple &FeatureList, const Halcon::HTuple &SelectionMethod, const Halcon::HTuple &Width, const Halcon::HTuple &Height, const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues, Halcon::HTuple *Score);
  // Selects an optimal combination of features to classify OCR  data.
  virtual HTuple SelectFeatureSetTrainfSvm(const char *TrainingFile, const char *FeatureList, const char *SelectionMethod, Hlong Width, Hlong Height, const char *GenParamNames, double GenParamValues, Halcon::HTuple *Score);
  // Deserialize a serialized SVM-based OCR classifier.
  virtual void DeserializeOcrClassSvm(const Halcon::HSerializedItem &SerializedItemHandle);
  // Serialize a SVM-based OCR classifier
  virtual HSerializedItem SerializeOcrClassSvm() const;
  // Read a SVM-based OCR classifier from a file.
  virtual void ReadOcrClassSvm(const Halcon::HTuple &FileName);
  // Read a SVM-based OCR classifier from a file.
  virtual void ReadOcrClassSvm(const char *FileName);
  // Write an OCR classifier to a file.
  virtual void WriteOcrClassSvm(const Halcon::HTuple &FileName) const;
  // Write an OCR classifier to a file.
  virtual void WriteOcrClassSvm(const char *FileName) const;
  // Compute the features of a character.
  virtual HTuple GetFeaturesOcrClassSvm(const HImage &Character, const Halcon::HTuple &Transform) const;
  // Compute the features of a character.
  virtual HTuple GetFeaturesOcrClassSvm(const HImage &Character, const char *Transform) const;
  // Classify a related group of characters with an OCR classifier.
  virtual HTuple DoOcrWordSvm(const HRegionArray &Character, const HImage &Image, const Halcon::HTuple &Expression, const Halcon::HTuple &NumAlternatives, const Halcon::HTuple &NumCorrections, Halcon::HTuple *Word, Halcon::HTuple *Score) const;
  // Classify a related group of characters with an OCR classifier.
  virtual HTuple DoOcrWordSvm(const HRegionArray &Character, const HImage &Image, const Halcon::HTuple &Expression, const Halcon::HTuple &NumAlternatives, const Halcon::HTuple &NumCorrections, char *Word, double *Score) const;
  // Classify a related group of characters with an OCR classifier.
  virtual HTuple DoOcrWordSvm(const HRegionArray &Character, const HImage &Image, const char *Expression, Hlong NumAlternatives, Hlong NumCorrections, Halcon::HTuple *Word, Halcon::HTuple *Score) const;
  // Classify a related group of characters with an OCR classifier.
  virtual HTuple DoOcrWordSvm(const HRegionArray &Character, const HImage &Image, const char *Expression, Hlong NumAlternatives, Hlong NumCorrections, char *Word, double *Score) const;
  // Classify multiple characters with an SVM-based OCR classifier.
  virtual HTuple DoOcrMultiClassSvm(const HRegionArray &Character, const HImage &Image) const;
  // Classify a single character with an SVM-based OCR classifier.
  virtual HTuple DoOcrSingleClassSvm(const HRegion &Character, const HImage &Image, const Halcon::HTuple &Num) const;
  // Approximate a trained SVM-based OCR classifier by a reduced SVM.
  virtual HOCRSvm ReduceOcrClassSvm(const Halcon::HTuple &Method, const Halcon::HTuple &MinRemainingSV, const Halcon::HTuple &MaxError) const;
  // Approximate a trained SVM-based OCR classifier by a reduced SVM.
  virtual HOCRSvm ReduceOcrClassSvm(const char *Method, Hlong MinRemainingSV, double MaxError) const;
  // Train an OCR classifier with data from a (protected) training file.
  virtual void TrainfOcrClassSvmProtected(const Halcon::HTuple &TrainingFile, const Halcon::HTuple &Password, const Halcon::HTuple &Epsilon, const Halcon::HTuple &TrainMode) const;
  // Train an OCR classifier.
  virtual void TrainfOcrClassSvm(const Halcon::HTuple &TrainingFile, const Halcon::HTuple &Epsilon, const Halcon::HTuple &TrainMode) const;
  // Compute the information content of the preprocessed feature vectors
  // of an SVM-based OCR classifier.
  virtual HTuple GetPrepInfoOcrClassSvm(const Halcon::HTuple &TrainingFile, const Halcon::HTuple &Preprocessing, Halcon::HTuple *CumInformationCont) const;
  // Compute the information content of the preprocessed feature vectors
  // of an SVM-based OCR classifier.
  virtual HTuple GetPrepInfoOcrClassSvm(const char *TrainingFile, const char *Preprocessing, Halcon::HTuple *CumInformationCont) const;
  // Return the number of support vectors of an OCR classifier.
  virtual Hlong GetSupportVectorNumOcrClassSvm(Halcon::HTuple *NumSVPerSVM) const;
  // Return the index of a support vector from a trained OCR classifier that is
  // based on support vector machines.
  virtual double GetSupportVectorOcrClassSvm(const Halcon::HTuple &IndexSupportVector) const;
  // Return the parameters of an OCR classifier.
  virtual Hlong GetParamsOcrClassSvm(Halcon::HTuple *HeightCharacter, Halcon::HTuple *Interpolation, Halcon::HTuple *Features, Halcon::HTuple *Characters, Halcon::HTuple *KernelType, Halcon::HTuple *KernelParam, Halcon::HTuple *Nu, Halcon::HTuple *Mode, Halcon::HTuple *Preprocessing, Halcon::HTuple *NumComponents) const;
  // Return the parameters of an OCR classifier.
  virtual Hlong GetParamsOcrClassSvm(Hlong *HeightCharacter, char *Interpolation, char *Features, Halcon::HTuple *Characters, char *KernelType, double *KernelParam, double *Nu, char *Mode, char *Preprocessing, Hlong *NumComponents) const;
  // Create an OCR classifier using a support vector machine.
  virtual void CreateOcrClassSvm(const Halcon::HTuple &WidthCharacter, const Halcon::HTuple &HeightCharacter, const Halcon::HTuple &Interpolation, const Halcon::HTuple &Features, const Halcon::HTuple &Characters, const Halcon::HTuple &KernelType, const Halcon::HTuple &KernelParam, const Halcon::HTuple &Nu, const Halcon::HTuple &Mode, const Halcon::HTuple &Preprocessing, const Halcon::HTuple &NumComponents);
};

}

#endif
