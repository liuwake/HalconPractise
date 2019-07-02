/*****************************************************************************
 * HClassTrainData.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HClassTrainData
 *
 * (c) 2011-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_CLASS_TRAIN_DATA_H
#define H_CLASS_TRAIN_DATA_H


#include "HCPPToolRef.h"


namespace Halcon {


class LIntExport HClassTrainData: public HToolBase 
{
public:

  // Tool-specific functional class constructors

  HClassTrainData(const HTuple &NumDim);
  HClassTrainData(const Hlong  &NumDim);


  // Common tool class management functionality

  HClassTrainData();
  HClassTrainData(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Deserialize serialized training data for classifiers.
  virtual void DeserializeClassTrainData(const Halcon::HSerializedItem &SerializedItemHandle);
  // Serialize training data for classifiers.
  virtual HSerializedItem SerializeClassTrainData() const;
  // Read the training data for classifiers from a file.
  virtual void ReadClassTrainData(const Halcon::HTuple &FileName);
  // Read the training data for classifiers from a file.
  virtual void ReadClassTrainData(const char *FileName);
  // Save the training data for classifiers in a file.
  virtual void WriteClassTrainData(const Halcon::HTuple &FileName) const;
  // Save the training data for classifiers in a file.
  virtual void WriteClassTrainData(const char *FileName) const;
  // Select certain features from training data to create 
  // training data containing less features.
  virtual HClassTrainData SelectSubFeatureClassTrainData(const Halcon::HTuple &SubFeatureIndices) const;
  // Define subfeatures in training data.
  virtual void SetFeatureLengthsClassTrainData(const Halcon::HTuple &SubFeatureLength, const Halcon::HTuple &Names) const;
  // Get the training data of a Gaussian Mixture Model (GMM).
  virtual void GetClassTrainDataGmm(const Halcon::HClassGmm &GMMHandle);
  // Add training data to a Gaussian Mixture Model (GMM).
  virtual void AddClassTrainDataGmm(const Halcon::HClassGmm &GMMHandle) const;
  // Get the training data of a multilayer perceptron (MLP).
  virtual void GetClassTrainDataMlp(const Halcon::HClassMlp &MLPHandle);
  // Add training data to a multilayer perceptron (MLP).
  virtual void AddClassTrainDataMlp(const Halcon::HClassMlp &MLPHandle) const;
  // Get the training data of a k-nearest neighbors (k-NN) classifier.
  virtual void GetClassTrainDataKnn(const Halcon::HClassKnn &KNNHandle);
  // Add training data to a k-nearest neighbors (k-NN) classifier.
  virtual void AddClassTrainDataKnn(const Halcon::HClassKnn &KNNHandle) const;
  // Get the training data of a support vector machine (SVM).
  virtual void GetClassTrainDataSvm(const Halcon::HClassSvm &SVMHandle);
  // Add training data to a support vector machine (SVM).
  virtual void AddClassTrainDataSvm(const Halcon::HClassSvm &SVMHandle) const;
  // Return the number of training samples stored in the training data.
  virtual Hlong GetSampleNumClassTrainData() const;
  // Return a training sample from training data.
  virtual HTuple GetSampleClassTrainData(const Halcon::HTuple &IndexSample, Halcon::HTuple *ClassID) const;
  // Return a training sample from training data.
  virtual HTuple GetSampleClassTrainData(const Halcon::HTuple &IndexSample, Hlong *ClassID) const;
  // Return a training sample from training data.
  virtual HTuple GetSampleClassTrainData(Hlong IndexSample, Halcon::HTuple *ClassID) const;
  // Return a training sample from training data.
  virtual HTuple GetSampleClassTrainData(Hlong IndexSample, Hlong *ClassID) const;
  // Clear all training data for classifiers.
  static void ClearAllClassTrainData(void);
  // Add a training sample to training data.
  virtual void AddSampleClassTrainData(const Halcon::HTuple &Order, const Halcon::HTuple &Features, const Halcon::HTuple &ClassID) const;
  // Create a handle for training data for classifiers.
  virtual void CreateClassTrainData(const Halcon::HTuple &NumDim);
  // Create a handle for training data for classifiers.
  virtual void CreateClassTrainData(Hlong NumDim);
  // Selects an optimal combination of features to classify the provided data.
  virtual HClassMlp SelectFeatureSetMlp(const Halcon::HTuple &SelectionMethod, const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues, Halcon::HTuple *SelectedFeatureIndices, Halcon::HTuple *Score) const;
  // Selects an optimal combination of features to classify the provided data.
  virtual HClassMlp SelectFeatureSetMlp(const char *SelectionMethod, const char *GenParamNames, double GenParamValues, Halcon::HTuple *SelectedFeatureIndices, Halcon::HTuple *Score) const;
  // Selects an optimal combination of features to classify the provided data.
  virtual HClassSvm SelectFeatureSetSvm(const Halcon::HTuple &SelectionMethod, const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues, Halcon::HTuple *SelectedFeatureIndices, Halcon::HTuple *Score) const;
  // Selects an optimal combination of features to classify the provided data.
  virtual HClassSvm SelectFeatureSetSvm(const char *SelectionMethod, const char *GenParamNames, double GenParamValues, Halcon::HTuple *SelectedFeatureIndices, Halcon::HTuple *Score) const;
  // Selects an optimal combination from a set of features to classify the 
  // provided data.
  virtual HClassGmm SelectFeatureSetGmm(const Halcon::HTuple &SelectionMethod, const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues, Halcon::HTuple *SelectedFeatureIndices, Halcon::HTuple *Score) const;
  // Selects an optimal combination from a set of features to classify the 
  // provided data.
  virtual HClassGmm SelectFeatureSetGmm(const char *SelectionMethod, const char *GenParamNames, double GenParamValues, Halcon::HTuple *SelectedFeatureIndices, Halcon::HTuple *Score) const;
  // Selects an optimal subset from a set of features to solve a certain 
  // classification problem.
  virtual HClassKnn SelectFeatureSetKnn(const Halcon::HTuple &SelectionMethod, const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues, Halcon::HTuple *SelectedFeatureIndices, Halcon::HTuple *Score) const;
  // Selects an optimal subset from a set of features to solve a certain 
  // classification problem.
  virtual HClassKnn SelectFeatureSetKnn(const char *SelectionMethod, const char *GenParamNames, double GenParamValues, Halcon::HTuple *SelectedFeatureIndices, Halcon::HTuple *Score) const;
};

}

#endif
