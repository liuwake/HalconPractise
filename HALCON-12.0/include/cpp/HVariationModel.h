/*****************************************************************************
 * HVariationModel.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HVariationModel
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_VARIATION_MODEL_H
#define H_VARIATION_MODEL_H


#include "HCPPToolRef.h"


namespace Halcon {


class LIntExport HVariationModel: public HToolBase 
{
public:

  // Tool-specific functional class constructors

  HVariationModel(const HTuple &Width, const HTuple &Height, 
                  const HTuple &Type = "byte", 
                  const HTuple &Mode = "standard");
                  
  HVariationModel(Hlong Width, Hlong Height, 
                  const char *Type = "byte", 
                  const char *Mode = "standard");


  // Common tool class management functionality

  HVariationModel();
  HVariationModel(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Deserialize a variation model.
  virtual void DeserializeVariationModel(const Halcon::HSerializedItem &SerializedItemHandle);
  // Serialize a variation model.
  virtual HSerializedItem SerializeVariationModel() const;
  // Read a variation model from a file.
  virtual void ReadVariationModel(const Halcon::HTuple &FileName);
  // Read a variation model from a file.
  virtual void ReadVariationModel(const char *FileName);
  // Write a variation model to a file.
  virtual void WriteVariationModel(const Halcon::HTuple &FileName) const;
  // Write a variation model to a file.
  virtual void WriteVariationModel(const char *FileName) const;
  // Return the threshold images used for image comparison by a variation
  // model.
  virtual HImage GetThreshImagesVariationModel(HImage *MaxImage) const;
  // Return the images used for image comparison by a variation model.
  virtual HImage GetVariationModel(HImage *VarImage) const;
  // Compare an image to a variation model.
  virtual HRegionArray CompareExtVariationModel(const HImageArray &Image, const Halcon::HTuple &Mode) const;
  // Compare an image to a variation model.
  virtual HRegionArray CompareExtVariationModel(const HImageArray &Image, const char *Mode) const;
  // Compare an image to a variation model.
  virtual HRegionArray CompareVariationModel(const HImageArray &Image) const;
  // Prepare a variation model for comparison with an image.
  virtual void PrepareDirectVariationModel(const HImage &RefImage, const HImage &VarImage, const Halcon::HTuple &AbsThreshold, const Halcon::HTuple &VarThreshold) const;
  // Prepare a variation model for comparison with an image.
  virtual void PrepareDirectVariationModel(const HImage &RefImage, const HImage &VarImage, double AbsThreshold, double VarThreshold) const;
  // Prepare a variation model for comparison with an image.
  virtual void PrepareVariationModel(const Halcon::HTuple &AbsThreshold, const Halcon::HTuple &VarThreshold) const;
  // Prepare a variation model for comparison with an image.
  virtual void PrepareVariationModel(double AbsThreshold, double VarThreshold) const;
  // Train a variation model.
  virtual void TrainVariationModel(const HImageArray &Images) const;
  // Create a variation model for image comparison.
  virtual void CreateVariationModel(const Halcon::HTuple &Width, const Halcon::HTuple &Height, const Halcon::HTuple &Type, const Halcon::HTuple &Mode);
  // Create a variation model for image comparison.
  virtual void CreateVariationModel(Hlong Width, Hlong Height, const char *Type, const char *Mode);
};

}

#endif
