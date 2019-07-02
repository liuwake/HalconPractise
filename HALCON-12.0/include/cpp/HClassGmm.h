/*****************************************************************************
 * HClassGMM.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HClassGmm
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_CLASS_GMM_H
#define H_CLASS_GMM_H


#include "HCPPToolRef.h"


namespace Halcon {


class LIntExport HClassGmm: public HToolBase 
{
public:

  // Tool-specific functional class constructors

  HClassGmm(const HTuple &NumDim, const HTuple &NumClasses,
            const HTuple &NumCenters, const HTuple &CovarType,
            const HTuple &Preprocessing, const HTuple &NumComponents,
            const HTuple &RandSeed);

  // Common tool class management functionality

  HClassGmm();
  HClassGmm(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Classify an image with a Gaussian Mixture Model.
  virtual HRegionArray ClassifyImageClassGmm(const HImage &Image, const Halcon::HTuple &RejectionThreshold) const;
  // Classify an image with a Gaussian Mixture Model.
  virtual HRegionArray ClassifyImageClassGmm(const HImage &Image, double RejectionThreshold) const;
  // Add training samples from an image to the training data of a
  // Gaussian Mixture Model.
  virtual void AddSamplesImageClassGmm(const HImage &Image, const HRegionArray &ClassRegions, const Halcon::HTuple &Randomize) const;
  // Add training samples from an image to the training data of a
  // Gaussian Mixture Model.
  virtual void AddSamplesImageClassGmm(const HImage &Image, const HRegionArray &ClassRegions, double Randomize) const;
  // Get the training data of a Gaussian Mixture Model (GMM).
  virtual HClassTrainData GetClassTrainDataGmm() const;
  // Add training data to a Gaussian Mixture Model (GMM).
  virtual void AddClassTrainDataGmm(const Halcon::HClassTrainData &ClassTrainDataHandle) const;
  // Selects an optimal combination from a set of features to classify the 
  // provided data.
  virtual HTuple SelectFeatureSetGmm(const Halcon::HClassTrainData &ClassTrainDataHandle, const Halcon::HTuple &SelectionMethod, const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues, Halcon::HTuple *Score);
  // Selects an optimal combination from a set of features to classify the 
  // provided data.
  virtual HTuple SelectFeatureSetGmm(const Halcon::HClassTrainData &ClassTrainDataHandle, const char *SelectionMethod, const char *GenParamNames, double GenParamValues, Halcon::HTuple *Score);
  // Create a look-up table using a gaussian mixture model to classify byte
  // images.
  virtual HClassLUT CreateClassLutGmm(const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues) const;
  // Deserialize a serialized Gaussian Mixture Model.
  virtual void DeserializeClassGmm(const Halcon::HSerializedItem &SerializedItemHandle);
  // Serialize a Gaussian Mixture Model (GMM).
  virtual HSerializedItem SerializeClassGmm() const;
  // Read a Gaussian Mixture Model from a file.
  virtual void ReadClassGmm(const Halcon::HTuple &FileName);
  // Read a Gaussian Mixture Model from a file.
  virtual void ReadClassGmm(const char *FileName);
  // Write a Gaussian Mixture Model to a file.
  virtual void WriteClassGmm(const Halcon::HTuple &FileName) const;
  // Write a Gaussian Mixture Model to a file.
  virtual void WriteClassGmm(const char *FileName) const;
  // Read the training data of a Gaussian Mixture Model from a file.
  virtual void ReadSamplesClassGmm(const Halcon::HTuple &FileName) const;
  // Read the training data of a Gaussian Mixture Model from a file.
  virtual void ReadSamplesClassGmm(const char *FileName) const;
  // Write the training data of a Gaussian Mixture Model to a file.
  virtual void WriteSamplesClassGmm(const Halcon::HTuple &FileName) const;
  // Write the training data of a Gaussian Mixture Model to a file.
  virtual void WriteSamplesClassGmm(const char *FileName) const;
  // Calculate the class of a feature vector by a Gaussian Mixture
  // Model.
  virtual HTuple ClassifyClassGmm(const Halcon::HTuple &Features, const Halcon::HTuple &Num, Halcon::HTuple *ClassProb, Halcon::HTuple *Density, Halcon::HTuple *KSigmaProb) const;
  // Evaluate a feature vector by a Gaussian Mixture Model.
  virtual HTuple EvaluateClassGmm(const Halcon::HTuple &Features, Halcon::HTuple *Density, Halcon::HTuple *KSigmaProb) const;
  // Evaluate a feature vector by a Gaussian Mixture Model.
  virtual HTuple EvaluateClassGmm(const Halcon::HTuple &Features, double *Density, double *KSigmaProb) const;
  // Train a Gaussian Mixture Model.
  virtual HTuple TrainClassGmm(const Halcon::HTuple &MaxIter, const Halcon::HTuple &Threshold, const Halcon::HTuple &ClassPriors, const Halcon::HTuple &Regularize, Halcon::HTuple *Iter) const;
  // Train a Gaussian Mixture Model.
  virtual HTuple TrainClassGmm(Hlong MaxIter, double Threshold, const char *ClassPriors, double Regularize, Halcon::HTuple *Iter) const;
  // Compute the information content of the preprocessed feature vectors
  // of a GMM.
  virtual HTuple GetPrepInfoClassGmm(const Halcon::HTuple &Preprocessing, Halcon::HTuple *CumInformationCont) const;
  // Compute the information content of the preprocessed feature vectors
  // of a GMM.
  virtual HTuple GetPrepInfoClassGmm(const char *Preprocessing, Halcon::HTuple *CumInformationCont) const;
  // Return the number of training samples stored in the training data of
  // a Gaussian Mixture Model (GMM).
  virtual Hlong GetSampleNumClassGmm() const;
  // Return a training sample from the training data of a Gaussian
  // Mixture Models (GMM).
  virtual HTuple GetSampleClassGmm(const Halcon::HTuple &NumSample, Halcon::HTuple *ClassID) const;
  // Return a training sample from the training data of a Gaussian
  // Mixture Models (GMM).
  virtual HTuple GetSampleClassGmm(const Halcon::HTuple &NumSample, Hlong *ClassID) const;
  // Return a training sample from the training data of a Gaussian
  // Mixture Models (GMM).
  virtual HTuple GetSampleClassGmm(Hlong NumSample, Halcon::HTuple *ClassID) const;
  // Return a training sample from the training data of a Gaussian
  // Mixture Models (GMM).
  virtual HTuple GetSampleClassGmm(Hlong NumSample, Hlong *ClassID) const;
  // Add a training sample to the training data of a Gaussian Mixture
  // Model.
  virtual void AddSampleClassGmm(const Halcon::HTuple &Features, const Halcon::HTuple &ClassID, const Halcon::HTuple &Randomize) const;
  // Return the parameters of a Gaussian Mixture Model.
  virtual Hlong GetParamsClassGmm(Halcon::HTuple *NumClasses, Halcon::HTuple *MinCenters, Halcon::HTuple *MaxCenters, Halcon::HTuple *CovarType) const;
  // Return the parameters of a Gaussian Mixture Model.
  virtual Hlong GetParamsClassGmm(Hlong *NumClasses, Halcon::HTuple *MinCenters, Halcon::HTuple *MaxCenters, char *CovarType) const;
  // Create a Gaussian Mixture Model for classification
  virtual void CreateClassGmm(const Halcon::HTuple &NumDim, const Halcon::HTuple &NumClasses, const Halcon::HTuple &NumCenters, const Halcon::HTuple &CovarType, const Halcon::HTuple &Preprocessing, const Halcon::HTuple &NumComponents, const Halcon::HTuple &RandSeed);
  // Create a Gaussian Mixture Model for classification
  virtual void CreateClassGmm(Hlong NumDim, Hlong NumClasses, Hlong NumCenters, const char *CovarType, const char *Preprocessing, Hlong NumComponents, Hlong RandSeed);
};

}

#endif
