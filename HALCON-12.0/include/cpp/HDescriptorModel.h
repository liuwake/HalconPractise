/*****************************************************************************
 * HDescriptorModel.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HDescriptorModel
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_DESCRIPTOR_MODEL_H
#define H_DESCRIPTOR_MODEL_H

#include "HCPPToolRef.h"

namespace Halcon {


class LIntExport HDescriptorModel: public HToolBase
{
  friend class HImage;
  
public:
  
  // Tool-specific functional class constructors
  
  HDescriptorModel(
          const HImage &Template,
          const HTuple &CamParam,
          const HTuple &ReferencePose,
          const HTuple &DetectorType,
          const HTuple &DetectorParamName,
          const HTuple &DetectorParamValue,
          const HTuple &DescriptorParamName,
          const HTuple &DescriptorParamValue,
          const HTuple &Seed);

  HDescriptorModel(
          const HImage &Template,
          const HTuple &DetectorType,
          const HTuple &DetectorParamName,
          const HTuple &DetectorParamValue,
          const HTuple &DescriptorParamName,
          const HTuple &DescriptorParamValue,
          const HTuple &Seed);


  // Common tool class management functionality

  HDescriptorModel();
  HDescriptorModel(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Deserialize a descriptor model.
  virtual void DeserializeDescriptorModel(const Halcon::HSerializedItem &SerializedItemHandle);
  // Serialize a descriptor model.
  virtual HSerializedItem SerializeDescriptorModel() const;
  // Read a descriptor model from a file.
  virtual void ReadDescriptorModel(const Halcon::HTuple &FileName);
  // Read a descriptor model from a file.
  virtual void ReadDescriptorModel(const char *FileName);
  // Write a descriptor model to a file.
  virtual void WriteDescriptorModel(const Halcon::HTuple &FileName) const;
  // Write a descriptor model to a file.
  virtual void WriteDescriptorModel(const char *FileName) const;
  // Find the best matches of a calibrated descriptor model in an image and
  // return their 3D pose.
  virtual HTuple FindCalibDescriptorModel(const HImage &Image, const Halcon::HTuple &DetectorParamName, const Halcon::HTuple &DetectorParamValue, const Halcon::HTuple &DescriptorParamName, const Halcon::HTuple &DescriptorParamValue, const Halcon::HTuple &MinScore, const Halcon::HTuple &NumMatches, const Halcon::HTuple &CamParam, const Halcon::HTuple &ScoreType, Halcon::HTuple *Score) const;
  // Find the best matches of a calibrated descriptor model in an image and
  // return their 3D pose.
  virtual HTuple FindCalibDescriptorModel(const HImage &Image, const Halcon::HTuple &DetectorParamName, const Halcon::HTuple &DetectorParamValue, const Halcon::HTuple &DescriptorParamName, const Halcon::HTuple &DescriptorParamValue, const Halcon::HTuple &MinScore, const Halcon::HTuple &NumMatches, const Halcon::HTuple &CamParam, const Halcon::HTuple &ScoreType, double *Score) const;
  // Find the best matches of a descriptor model in an image.
  virtual HTuple FindUncalibDescriptorModel(const HImage &Image, const Halcon::HTuple &DetectorParamName, const Halcon::HTuple &DetectorParamValue, const Halcon::HTuple &DescriptorParamName, const Halcon::HTuple &DescriptorParamValue, const Halcon::HTuple &MinScore, const Halcon::HTuple &NumMatches, const Halcon::HTuple &ScoreType, Halcon::HTuple *Score) const;
  // Find the best matches of a descriptor model in an image.
  virtual HTuple FindUncalibDescriptorModel(const HImage &Image, const Halcon::HTuple &DetectorParamName, const Halcon::HTuple &DetectorParamValue, const Halcon::HTuple &DescriptorParamName, const Halcon::HTuple &DescriptorParamValue, const Halcon::HTuple &MinScore, const Halcon::HTuple &NumMatches, const Halcon::HTuple &ScoreType, double *Score) const;
  // Query the interest points of the descriptor model or the last processed
  // search image.
  virtual HTuple GetDescriptorModelPoints(const Halcon::HTuple &Set, const Halcon::HTuple &Subset, Halcon::HTuple *Column) const;
  // Query the interest points of the descriptor model or the last processed
  // search image.
  virtual HTuple GetDescriptorModelPoints(const char *Set, Hlong Subset, Halcon::HTuple *Column) const;
  // Return the parameters of a descriptor model.
  virtual HTuple GetDescriptorModelParams(Halcon::HTuple *DetectorParamName, Halcon::HTuple *DetectorParamValue, Halcon::HTuple *DescriptorParamName, Halcon::HTuple *DescriptorParamValue) const;
  // Create a descriptor model for calibrated perspective matching.
  virtual void CreateCalibDescriptorModel(const HImage &Template, const Halcon::HTuple &CamParam, const Halcon::HTuple &ReferencePose, const Halcon::HTuple &DetectorType, const Halcon::HTuple &DetectorParamName, const Halcon::HTuple &DetectorParamValue, const Halcon::HTuple &DescriptorParamName, const Halcon::HTuple &DescriptorParamValue, const Halcon::HTuple &Seed);
  // Prepare a descriptor model for interest point matching.
  virtual void CreateUncalibDescriptorModel(const HImage &Template, const Halcon::HTuple &DetectorType, const Halcon::HTuple &DetectorParamName, const Halcon::HTuple &DetectorParamValue, const Halcon::HTuple &DescriptorParamName, const Halcon::HTuple &DescriptorParamValue, const Halcon::HTuple &Seed);
  // Query alphanumerical results that were accumulated during descriptor-based
  // matching.
  virtual HTuple GetDescriptorModelResults(const Halcon::HTuple &ObjectID, const Halcon::HTuple &ResultNames) const;
  // Query alphanumerical results that were accumulated during descriptor-based
  // matching.
  virtual HTuple GetDescriptorModelResults(Hlong ObjectID, const char *ResultNames) const;
  // Return the origin of a descriptor model.
  virtual double GetDescriptorModelOrigin(Halcon::HTuple *Column) const;
  // Return the origin of a descriptor model.
  virtual double GetDescriptorModelOrigin(double *Column) const;
  // Sets the origin of a descriptor model.
  virtual void SetDescriptorModelOrigin(const Halcon::HTuple &Row, const Halcon::HTuple &Column) const;
  // Sets the origin of a descriptor model.
  virtual void SetDescriptorModelOrigin(double Row, double Column) const;
};

}

#endif
