/*****************************************************************************
 * HClassGMM.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HClassGmm
 *
 * (c) 2011-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_CLASS_KNN_H
#define H_CLASS_KNN_H


#include "HCPPToolRef.h"


namespace Halcon {


class LIntExport HClassKnn: public HToolBase 
{
public:

  // Tool-specific functional class constructors

  HClassKnn(const HTuple &NumDim);
  HClassKnn(const Hlong  &NumDim);


  // Common tool class management functionality

  HClassKnn();
  HClassKnn(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Classify an image with a k-Nearest-Neighbor classifier.
  virtual HRegionArray ClassifyImageClassKnn(const HImage &Image, HImage *DistanceImage, const Halcon::HTuple &RejectionThreshold) const;
  // Classify an image with a k-Nearest-Neighbor classifier.
  virtual HRegionArray ClassifyImageClassKnn(const HImage &Image, HImage *DistanceImage, double RejectionThreshold) const;
  // Add training samples from an image to the training data of a
  // k-Nearest-Neighbor classifier.
  virtual void AddSamplesImageClassKnn(const HImage &Image, const HRegionArray &ClassRegions) const;
  // Get the training data of a k-nearest neighbors (k-NN) classifier.
  virtual HClassTrainData GetClassTrainDataKnn() const;
  // Add training data to a k-nearest neighbors (k-NN) classifier.
  virtual void AddClassTrainDataKnn(const Halcon::HClassTrainData &ClassTrainDataHandle) const;
  // Selects an optimal subset from a set of features to solve a certain 
  // classification problem.
  virtual HTuple SelectFeatureSetKnn(const Halcon::HClassTrainData &ClassTrainDataHandle, const Halcon::HTuple &SelectionMethod, const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues, Halcon::HTuple *Score);
  // Selects an optimal subset from a set of features to solve a certain 
  // classification problem.
  virtual HTuple SelectFeatureSetKnn(const Halcon::HClassTrainData &ClassTrainDataHandle, const char *SelectionMethod, const char *GenParamNames, double GenParamValues, Halcon::HTuple *Score);
  // Clear all k-NN classifiers.
  static void ClearAllClassKnn(void);
  // Return the number of training samples stored in the training data of
  // a k-nearest neighbors (k-NN) classifier.
  virtual Hlong GetSampleNumClassKnn() const;
  // Return a training sample from the training data of a k-nearest neighbors 
  // (k-NN) classifier.
  virtual HTuple GetSampleClassKnn(const Halcon::HTuple &IndexSample, Halcon::HTuple *ClassID) const;
  // Return a training sample from the training data of a k-nearest neighbors 
  // (k-NN) classifier.
  virtual HTuple GetSampleClassKnn(Hlong IndexSample, Halcon::HTuple *ClassID) const;
  // Deserialize a serialized k-NN classifier.
  virtual void DeserializeClassKnn(const Halcon::HSerializedItem &SerializedItemHandle);
  // Serialize a k-NN classifier.
  virtual HSerializedItem SerializeClassKnn() const;
  // Read the k-NN classifier from a file.
  virtual void ReadClassKnn(const Halcon::HTuple &FileName);
  // Read the k-NN classifier from a file.
  virtual void ReadClassKnn(const char *FileName);
  // Save the k-NN classifier in a file.
  virtual void WriteClassKnn(const Halcon::HTuple &FileName) const;
  // Save the k-NN classifier in a file.
  virtual void WriteClassKnn(const char *FileName) const;
  // Get parameters of a k-NN classification.
  virtual HTuple GetParamsClassKnn(const Halcon::HTuple &GenParamNames) const;
  // Set parameters for k-NN classification.
  virtual void SetParamsClassKnn(const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues) const;
  // Search for the next neighbors for a given feature vector.
  virtual HTuple ClassifyClassKnn(const Halcon::HTuple &Features, Halcon::HTuple *Rating) const;
  // Creates the search trees for a k-NN classifier.
  virtual void TrainClassKnn(const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues) const;
  // Add a sample to a  k-nearest neighbors (k-NN) classifier.
  virtual void AddSampleClassKnn(const Halcon::HTuple &Features, const Halcon::HTuple &ClassID) const;
  // Add a sample to a  k-nearest neighbors (k-NN) classifier.
  virtual void AddSampleClassKnn(double Features, Hlong ClassID) const;
  // Create a k-nearest neighbors (k-NN) classifier.
  virtual void CreateClassKnn(const Halcon::HTuple &NumDim);
  // Create a look-up table using a k-nearest neighbors
  // classifier (k-NN) to classify byte
  // images.
  virtual HClassLUT CreateClassLutKnn(const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues) const;
};

}

#endif
