/*****************************************************************************
 * HClassSVM.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HClassSvm
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_CLASS_SVM_H
#define H_CLASS_SVM_H


#include "HCPPToolRef.h"


namespace Halcon {


class LIntExport HClassSvm: public HToolBase 
{
public:

  // Tool-specific functional class constructors
  
  HClassSvm(const HTuple &NumFeatures, const HTuple &KernelType,
            const HTuple &KernelParam, const HTuple &Nu,
            const HTuple &NumClasses, const HTuple &Mode,
            const HTuple &Preprocessing, const HTuple &NumComponents);

  // Common tool class management functionality

  HClassSvm();
  HClassSvm(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Classify an image with a support vector machine.
  virtual HRegionArray ClassifyImageClassSvm(const HImage &Image) const;
  // Add training samples from an image to the training data of a support
  // vector machine.
  virtual void AddSamplesImageClassSvm(const HImage &Image, const HRegionArray &ClassRegions) const;
  // Get the training data of a support vector machine (SVM).
  virtual HClassTrainData GetClassTrainDataSvm() const;
  // Add training data to a support vector machine (SVM).
  virtual void AddClassTrainDataSvm(const Halcon::HClassTrainData &ClassTrainDataHandle) const;
  // Selects an optimal combination of features to classify the provided data.
  virtual HTuple SelectFeatureSetSvm(const Halcon::HClassTrainData &ClassTrainDataHandle, const Halcon::HTuple &SelectionMethod, const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues, Halcon::HTuple *Score);
  // Selects an optimal combination of features to classify the provided data.
  virtual HTuple SelectFeatureSetSvm(const Halcon::HClassTrainData &ClassTrainDataHandle, const char *SelectionMethod, const char *GenParamNames, double GenParamValues, Halcon::HTuple *Score);
  // Create a look-up table using a Support-Vector-Machine to classify byte
  // images.
  virtual HClassLUT CreateClassLutSvm(const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues) const;
  // Deserialize a serialized support vector machine (SVM).
  virtual void DeserializeClassSvm(const Halcon::HSerializedItem &SerializedItemHandle);
  // Serialize a support vector machine (SVM).
  virtual HSerializedItem SerializeClassSvm() const;
  // Read a support vector machine from a file.
  virtual void ReadClassSvm(const Halcon::HTuple &FileName);
  // Read a support vector machine from a file.
  virtual void ReadClassSvm(const char *FileName);
  // Write a support vector machine to a file.
  virtual void WriteClassSvm(const Halcon::HTuple &FileName) const;
  // Write a support vector machine to a file.
  virtual void WriteClassSvm(const char *FileName) const;
  // Read the training data of a support vector machine from a file.
  virtual void ReadSamplesClassSvm(const Halcon::HTuple &FileName) const;
  // Read the training data of a support vector machine from a file.
  virtual void ReadSamplesClassSvm(const char *FileName) const;
  // Write the training data of a support vector machine to a file.
  virtual void WriteSamplesClassSvm(const Halcon::HTuple &FileName) const;
  // Write the training data of a support vector machine to a file.
  virtual void WriteSamplesClassSvm(const char *FileName) const;
  // Evaluate a feature vector by a support vector machine.
  virtual HTuple EvaluateClassSvm(const Halcon::HTuple &Features) const;
  // Classify a feature vector by a support vector machine.
  virtual HTuple ClassifyClassSvm(const Halcon::HTuple &Features, const Halcon::HTuple &Num) const;
  // Approximate a trained support vector machine by a reduced support
  // vector machine for faster classification.
  virtual HClassSvm ReduceClassSvm(const Halcon::HTuple &Method, const Halcon::HTuple &MinRemainingSV, const Halcon::HTuple &MaxError) const;
  // Approximate a trained support vector machine by a reduced support
  // vector machine for faster classification.
  virtual HClassSvm ReduceClassSvm(const char *Method, Hlong MinRemainingSV, double MaxError) const;
  // Train a support vector machine.
  virtual void TrainClassSvm(const Halcon::HTuple &Epsilon, const Halcon::HTuple &TrainMode) const;
  // Compute the information content of the preprocessed feature vectors
  // of a support vector machine
  virtual HTuple GetPrepInfoClassSvm(const Halcon::HTuple &Preprocessing, Halcon::HTuple *CumInformationCont) const;
  // Compute the information content of the preprocessed feature vectors
  // of a support vector machine
  virtual HTuple GetPrepInfoClassSvm(const char *Preprocessing, Halcon::HTuple *CumInformationCont) const;
  // Return the number of support vectors of a support vector machine.
  virtual Hlong GetSupportVectorNumClassSvm(Halcon::HTuple *NumSVPerSVM) const;
  // Return the index of a support vector from a trained support vector
  // machine.
  virtual double GetSupportVectorClassSvm(const Halcon::HTuple &IndexSupportVector) const;
  // Return the number of training samples stored in the training data of
  // a support vector machine.
  virtual Hlong GetSampleNumClassSvm() const;
  // Return a training sample from the training data of a support vector
  // machine.
  virtual HTuple GetSampleClassSvm(const Halcon::HTuple &IndexSample, Halcon::HTuple *Target) const;
  // Return a training sample from the training data of a support vector
  // machine.
  virtual HTuple GetSampleClassSvm(const Halcon::HTuple &IndexSample, Hlong *Target) const;
  // Return a training sample from the training data of a support vector
  // machine.
  virtual HTuple GetSampleClassSvm(Hlong IndexSample, Halcon::HTuple *Target) const;
  // Return a training sample from the training data of a support vector
  // machine.
  virtual HTuple GetSampleClassSvm(Hlong IndexSample, Hlong *Target) const;
  // Add a training sample to the training data of a support vector
  // machine.
  virtual void AddSampleClassSvm(const Halcon::HTuple &Features, const Halcon::HTuple &Class) const;
  // Return the parameters of a support vector machine.
  virtual Hlong GetParamsClassSvm(Halcon::HTuple *KernelType, Halcon::HTuple *KernelParam, Halcon::HTuple *Nu, Halcon::HTuple *NumClasses, Halcon::HTuple *Mode, Halcon::HTuple *Preprocessing, Halcon::HTuple *NumComponents) const;
  // Return the parameters of a support vector machine.
  virtual Hlong GetParamsClassSvm(char *KernelType, double *KernelParam, double *Nu, Hlong *NumClasses, char *Mode, char *Preprocessing, Hlong *NumComponents) const;
  // Create a support vector machine for pattern classification.
  virtual void CreateClassSvm(const Halcon::HTuple &NumFeatures, const Halcon::HTuple &KernelType, const Halcon::HTuple &KernelParam, const Halcon::HTuple &Nu, const Halcon::HTuple &NumClasses, const Halcon::HTuple &Mode, const Halcon::HTuple &Preprocessing, const Halcon::HTuple &NumComponents);
  // Create a support vector machine for pattern classification.
  virtual void CreateClassSvm(Hlong NumFeatures, const char *KernelType, double KernelParam, double Nu, Hlong NumClasses, const char *Mode, const char *Preprocessing, Hlong NumComponents);
};

}

#endif
