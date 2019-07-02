/*****************************************************************************
 * HNCCModel.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HNCCModel
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_NCC_MODEL_H
#define H_NCC_MODEL_H


#include "HCPPToolRef.h"


namespace Halcon {


class LIntExport HNCCModel: public HToolBase 
{
  friend class HImage;
  
public:

  // Tool-specific functional class constructors

  HNCCModel(
          const HImage &Template, 
          const HTuple &NumLevels, 
          const HTuple &AngleStart, 
          const HTuple &AngleExtent, 
          const HTuple &AngleStep, 
          const HTuple &Metric);
          
  HNCCModel(
          const HImage &Template, 
          Hlong         NumLevels, 
          double        AngleStart, 
          double        AngleExtent, 
          double        AngleStep, 
          const char   *Metric = "use_polarity");

  // Common tool class management functionality

  HNCCModel();
  HNCCModel(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Deserialize an NCC model.
  virtual void DeserializeNccModel(const Halcon::HSerializedItem &SerializedItemHandle);
  // Serialize an NCC model.
  virtual HSerializedItem SerializeNccModel() const;
  // Read an NCC model from a file.
  virtual void ReadNccModel(const Halcon::HTuple &FileName);
  // Read an NCC model from a file.
  virtual void ReadNccModel(const char *FileName);
  // Write an NCC model to a file.
  virtual void WriteNccModel(const Halcon::HTuple &FileName) const;
  // Write an NCC model to a file.
  virtual void WriteNccModel(const char *FileName) const;
  // Determine the parameters of an NCC model.
  static HTuple DetermineNccModelParams(const HImage &Template, const Halcon::HTuple &NumLevels, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &Metric, const Halcon::HTuple &Parameters, Halcon::HTuple *ParameterValue);
  // Determine the parameters of an NCC model.
  static HTuple DetermineNccModelParams(const HImage &Template, Hlong NumLevels, double AngleStart, double AngleExtent, const char *Metric, const char *Parameters, Halcon::HTuple *ParameterValue);
  // Return the parameters of an NCC model.
  virtual Hlong GetNccModelParams(Halcon::HTuple *AngleStart, Halcon::HTuple *AngleExtent, Halcon::HTuple *AngleStep, Halcon::HTuple *Metric) const;
  // Return the parameters of an NCC model.
  virtual Hlong GetNccModelParams(double *AngleStart, double *AngleExtent, double *AngleStep, char *Metric) const;
  // Return the origin (reference point) of an NCC model.
  virtual double GetNccModelOrigin(Halcon::HTuple *Column) const;
  // Return the origin (reference point) of an NCC model.
  virtual double GetNccModelOrigin(double *Column) const;
  // Set the origin (reference point) of an NCC model.
  virtual void SetNccModelOrigin(const Halcon::HTuple &Row, const Halcon::HTuple &Column) const;
  // Set the origin (reference point) of an NCC model.
  virtual void SetNccModelOrigin(double Row, double Column) const;
  // Find the best matches of an NCC model in an image.
  virtual HTuple FindNccModel(const HImage &Image, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &MinScore, const Halcon::HTuple &NumMatches, const Halcon::HTuple &MaxOverlap, const Halcon::HTuple &SubPixel, const Halcon::HTuple &NumLevels, Halcon::HTuple *Column, Halcon::HTuple *Angle, Halcon::HTuple *Score) const;
  // Find the best matches of an NCC model in an image.
  virtual HTuple FindNccModel(const HImage &Image, double AngleStart, double AngleExtent, double MinScore, Hlong NumMatches, double MaxOverlap, const char *SubPixel, Hlong NumLevels, Halcon::HTuple *Column, Halcon::HTuple *Angle, Halcon::HTuple *Score) const;
  // Set selected parameters of the NCC model.
  virtual void SetNccModelParam(const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues) const;
  // Prepare an NCC model for matching.
  virtual void CreateNccModel(const HImage &Template, const Halcon::HTuple &NumLevels, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &AngleStep, const Halcon::HTuple &Metric);
  // Prepare an NCC model for matching.
  virtual void CreateNccModel(const HImage &Template, Hlong NumLevels, double AngleStart, double AngleExtent, double AngleStep, const char *Metric);
};

}

#endif
