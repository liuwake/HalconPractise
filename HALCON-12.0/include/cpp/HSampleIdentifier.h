/*****************************************************************************
 * HSampleIdentifier.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HSampleIdentifier
 *
 * (c) 2014 by MVTec Software GmbH
 *             www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_SAMPLE_IDENTIFIER_H
#define H_SAMPLE_IDENTIFIER_H

#include "HCPPToolRef.h"

namespace Halcon {


class LIntExport HSampleIdentifier: public HToolBase
{
  friend class HImage;
  
public:
  
  // Tool-specific functional class constructors
  
  HSampleIdentifier(const HTuple &ParamName, 
                    const HTuple &ParamValue);

  HSampleIdentifier(const char *ParamName, 
                    const char *ParamValue);


  // Common tool class management functionality

  HSampleIdentifier();
  HSampleIdentifier(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Deserialize a serialized sample identifier.
  virtual void DeserializeSampleIdentifier(const Halcon::HSerializedItem &SerializedItemHandle);
  // Read a sample identifier from a file.
  virtual void ReadSampleIdentifier(const Halcon::HTuple &FileName);
  // Read a sample identifier from a file.
  virtual void ReadSampleIdentifier(const char *FileName);
  // Serialize a sample identifier.
  virtual HSerializedItem SerializeSampleIdentifier() const;
  // Write a sample identifier to a file.
  virtual void WriteSampleIdentifier(const Halcon::HTuple &FileName) const;
  // Write a sample identifier to a file.
  virtual void WriteSampleIdentifier(const char *FileName) const;
  // Identify objects with a sample identifier.
  // 
  virtual HTuple ApplySampleIdentifier(const HImage &Image, const Halcon::HTuple &NumResults, const Halcon::HTuple &RatingThreshold, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue, Halcon::HTuple *Rating) const;
  // Identify objects with a sample identifier.
  // 
  virtual Hlong ApplySampleIdentifier(const HImage &Image, const Halcon::HTuple &NumResults, const Halcon::HTuple &RatingThreshold, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue, double *Rating) const;
  // Get selected parameters of a sample identifier.
  virtual double GetSampleIdentifierParam(const Halcon::HTuple &ParamName) const;
  // Get selected parameters of a sample identifier.
  virtual double GetSampleIdentifierParam(const char *ParamName) const;
  // Set selected parameters of a sample identifier.
  virtual void SetSampleIdentifierParam(const Halcon::HTuple &ParamName, const Halcon::HTuple &ParamValue) const;
  // Set selected parameters of a sample identifier.
  virtual void SetSampleIdentifierParam(const char *ParamName, double ParamValue) const;
  // Retrieve information about an object of a sample identifier.
  virtual HTuple GetSampleIdentifierObjectInfo(const Halcon::HTuple &ObjectIdx, const Halcon::HTuple &InfoName) const;
  // Retrieve information about an object of a sample identifier.
  virtual HTuple GetSampleIdentifierObjectInfo(Hlong ObjectIdx, const char *InfoName) const;
  // Define a name or a description for an object of a sample identifier.
  virtual void SetSampleIdentifierObjectInfo(const Halcon::HTuple &ObjectIdx, const Halcon::HTuple &InfoName, const Halcon::HTuple &InfoValue) const;
  // Define a name or a description for an object of a sample identifier.
  virtual void SetSampleIdentifierObjectInfo(Hlong ObjectIdx, const char *InfoName, const char *InfoValue) const;
  // Remove training data from a sample identifier.  
  virtual void RemoveSampleIdentifierTrainingData(const Halcon::HTuple &ObjectIdx, const Halcon::HTuple &ObjectSampleIdx) const;
  // Remove training data from a sample identifier.  
  virtual void RemoveSampleIdentifierTrainingData(Hlong ObjectIdx, Hlong ObjectSampleIdx) const;
  // Remove preparation data from a sample identifier.  
  virtual void RemoveSampleIdentifierPreparationData(const Halcon::HTuple &ObjectIdx, const Halcon::HTuple &ObjectSampleIdx) const;
  // Remove preparation data from a sample identifier.  
  virtual void RemoveSampleIdentifierPreparationData(Hlong ObjectIdx, Hlong ObjectSampleIdx) const;
  // Train a sample identifier.  
  virtual void TrainSampleIdentifier(const Halcon::HTuple &ParamName, const Halcon::HTuple &ParamValue) const;
  // Add training data to an existing sample identifier.
  // 
  virtual Hlong AddSampleIdentifierTrainingData(const HImage &SampleImage, const Halcon::HTuple &ObjectIdx, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue) const;
  // Adapt the internal data structure of a sample identifier to the objects to
  // be identified.  
  virtual void PrepareSampleIdentifier(const Halcon::HTuple &RemovePreparationData, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue) const;
  // Add preparation data to an existing sample identifier.
  // 
  virtual Hlong AddSampleIdentifierPreparationData(const HImage &SampleImage, const Halcon::HTuple &ObjectIdx, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue) const;
  // Create a new sample identifier.
  virtual void CreateSampleIdentifier(const Halcon::HTuple &ParamName, const Halcon::HTuple &ParamValue);
};

}

#endif
