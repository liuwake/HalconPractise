/*****************************************************************************
 * HClassMLP.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HClassMlp
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_CLASS_MLP_H
#define H_CLASS_MLP_H


#include "HCPPToolRef.h"


namespace Halcon {


class LIntExport HClassMlp: public HToolBase 
{
public:

  // Tool-specific functional class constructors

  HClassMlp(const HTuple &NumInput, const HTuple &NumHidden,
            const HTuple &NumOutput, const HTuple &OutputFunction,
            const HTuple &Preprocessing, const HTuple &NumComponents,
            const HTuple &RandSeed);

  // Common tool class management functionality

  HClassMlp();
  HClassMlp(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Classify an image with a multilayer perceptron.
  virtual HRegionArray ClassifyImageClassMlp(const HImage &Image, const Halcon::HTuple &RejectionThreshold) const;
  // Classify an image with a multilayer perceptron.
  virtual HRegionArray ClassifyImageClassMlp(const HImage &Image, double RejectionThreshold) const;
  // Add training samples from an image to the training data of a
  // multilayer perceptron.
  virtual void AddSamplesImageClassMlp(const HImage &Image, const HRegionArray &ClassRegions) const;
  // Get the training data of a multilayer perceptron (MLP).
  virtual HClassTrainData GetClassTrainDataMlp() const;
  // Add training data to a multilayer perceptron (MLP).
  virtual void AddClassTrainDataMlp(const Halcon::HClassTrainData &ClassTrainDataHandle) const;
  // Selects an optimal combination of features to classify the provided data.
  virtual HTuple SelectFeatureSetMlp(const Halcon::HClassTrainData &ClassTrainDataHandle, const Halcon::HTuple &SelectionMethod, const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues, Halcon::HTuple *Score);
  // Selects an optimal combination of features to classify the provided data.
  virtual HTuple SelectFeatureSetMlp(const Halcon::HClassTrainData &ClassTrainDataHandle, const char *SelectionMethod, const char *GenParamNames, double GenParamValues, Halcon::HTuple *Score);
  // Create a look-up table using a multi-layer perceptron to classify byte
  // images.
  virtual HClassLUT CreateClassLutMlp(const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues) const;
  // Deserialize a serialized multilayer perceptron.
  virtual void DeserializeClassMlp(const Halcon::HSerializedItem &SerializedItemHandle);
  // Serialize a multilayer perceptron (MLP).
  virtual HSerializedItem SerializeClassMlp() const;
  // Read a multilayer perceptron from a file.
  virtual void ReadClassMlp(const Halcon::HTuple &FileName);
  // Read a multilayer perceptron from a file.
  virtual void ReadClassMlp(const char *FileName);
  // Write a multilayer perceptron to a file.
  virtual void WriteClassMlp(const Halcon::HTuple &FileName) const;
  // Write a multilayer perceptron to a file.
  virtual void WriteClassMlp(const char *FileName) const;
  // Read the training data of a multilayer perceptron from a file.
  virtual void ReadSamplesClassMlp(const Halcon::HTuple &FileName) const;
  // Read the training data of a multilayer perceptron from a file.
  virtual void ReadSamplesClassMlp(const char *FileName) const;
  // Write the training data of a multilayer perceptron to a file.
  virtual void WriteSamplesClassMlp(const Halcon::HTuple &FileName) const;
  // Write the training data of a multilayer perceptron to a file.
  virtual void WriteSamplesClassMlp(const char *FileName) const;
  // Calculate the class of a feature vector by a multilayer perceptron.
  virtual HTuple ClassifyClassMlp(const Halcon::HTuple &Features, const Halcon::HTuple &Num, Halcon::HTuple *Confidence) const;
  // Calculate the class of a feature vector by a multilayer perceptron.
  virtual Hlong ClassifyClassMlp(const Halcon::HTuple &Features, const Halcon::HTuple &Num, double *Confidence) const;
  // Calculate the evaluation of a feature vector by a multilayer
  // perceptron.
  virtual HTuple EvaluateClassMlp(const Halcon::HTuple &Features) const;
  // Train a multilayer perceptron.
  virtual double TrainClassMlp(const Halcon::HTuple &MaxIterations, const Halcon::HTuple &WeightTolerance, const Halcon::HTuple &ErrorTolerance, Halcon::HTuple *ErrorLog) const;
  // Train a multilayer perceptron.
  virtual double TrainClassMlp(Hlong MaxIterations, double WeightTolerance, double ErrorTolerance, Halcon::HTuple *ErrorLog) const;
  // Compute the information content of the preprocessed feature vectors
  // of a multilayer perceptron.
  virtual HTuple GetPrepInfoClassMlp(const Halcon::HTuple &Preprocessing, Halcon::HTuple *CumInformationCont) const;
  // Compute the information content of the preprocessed feature vectors
  // of a multilayer perceptron.
  virtual HTuple GetPrepInfoClassMlp(const char *Preprocessing, Halcon::HTuple *CumInformationCont) const;
  // Return the number of training samples stored in the training data of
  // a multilayer perceptron.
  virtual Hlong GetSampleNumClassMlp() const;
  // Return a training sample from the training data of a multilayer
  // perceptron.
  virtual HTuple GetSampleClassMlp(const Halcon::HTuple &IndexSample, Halcon::HTuple *Target) const;
  // Return a training sample from the training data of a multilayer
  // perceptron.
  virtual HTuple GetSampleClassMlp(Hlong IndexSample, Halcon::HTuple *Target) const;
  // Get the parameters of a rejection class.
  virtual HTuple GetRejectionParamsClassMlp(const Halcon::HTuple &GenParamName) const;
  // Get the parameters of a rejection class.
  virtual HTuple GetRejectionParamsClassMlp(const char *GenParamName) const;
  // Set the parameters of a rejection class.
  virtual void SetRejectionParamsClassMlp(const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue) const;
  // Add a training sample to the training data of a multilayer
  // perceptron.
  virtual void AddSampleClassMlp(const Halcon::HTuple &Features, const Halcon::HTuple &Target) const;
  // Return the regularization parameters of a multilayer perceptron.
  virtual HTuple GetRegularizationParamsClassMlp(const Halcon::HTuple &GenParamName) const;
  // Return the regularization parameters of a multilayer perceptron.
  virtual HTuple GetRegularizationParamsClassMlp(const char *GenParamName) const;
  // Set the regularization parameters of a multilayer perceptron.
  virtual void SetRegularizationParamsClassMlp(const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue) const;
  // Set the regularization parameters of a multilayer perceptron.
  virtual void SetRegularizationParamsClassMlp(const char *GenParamName, double GenParamValue) const;
  // Return the parameters of a multilayer perceptron.
  virtual Hlong GetParamsClassMlp(Halcon::HTuple *NumHidden, Halcon::HTuple *NumOutput, Halcon::HTuple *OutputFunction, Halcon::HTuple *Preprocessing, Halcon::HTuple *NumComponents) const;
  // Return the parameters of a multilayer perceptron.
  virtual Hlong GetParamsClassMlp(Hlong *NumHidden, Hlong *NumOutput, char *OutputFunction, char *Preprocessing, Hlong *NumComponents) const;
  // Create a multilayer perceptron for classification or regression.
  virtual void CreateClassMlp(const Halcon::HTuple &NumInput, const Halcon::HTuple &NumHidden, const Halcon::HTuple &NumOutput, const Halcon::HTuple &OutputFunction, const Halcon::HTuple &Preprocessing, const Halcon::HTuple &NumComponents, const Halcon::HTuple &RandSeed);
  // Create a multilayer perceptron for classification or regression.
  virtual void CreateClassMlp(Hlong NumInput, Hlong NumHidden, Hlong NumOutput, const char *OutputFunction, const char *Preprocessing, Hlong NumComponents, Hlong RandSeed);
};

}

#endif
