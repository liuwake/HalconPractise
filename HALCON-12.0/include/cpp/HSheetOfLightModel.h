/*****************************************************************************
 * HSheetOfLightModel.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HSheetOfLightModel
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_SHEET_OF_LIGHT_MODEL_H
#define H_SHEET_OF_LIGHT_MODEL_H


#include "HCPPToolRef.h"


namespace Halcon {


class LIntExport HSheetOfLightModel: public HToolBase 
{
public:

  // Tool-specific functional class constructors
  
  HSheetOfLightModel(const HRegion &ProfileRegion, 
                     const HTuple &GenParamNames, 
                     const HTuple &GenParamValues);

  HSheetOfLightModel(const HRegion &ProfileRegion, 
                     const char    *GenParamNames, 
                     const char    *GenParamValues);

  // Common tool class management functionality

  HSheetOfLightModel();
  HSheetOfLightModel(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Read a sheet-of-light model from a file and create a new model.
  virtual void ReadSheetOfLightModel(const Halcon::HTuple &FileName);
  // Read a sheet-of-light model from a file and create a new model.
  virtual void ReadSheetOfLightModel(const char *FileName);
  // Write a sheet-of-light model to a file.
  virtual void WriteSheetOfLightModel(const Halcon::HTuple &FileName) const;
  // Write a sheet-of-light model to a file.
  virtual void WriteSheetOfLightModel(const char *FileName) const;
  // Deserialize a sheet-of-light model.
  virtual void DeserializeSheetOfLightModel(const Halcon::HSerializedItem &SerializedItemHandle);
  // Serialize a sheet-of-light model.
  virtual HSerializedItem SerializeSheetOfLightModel() const;
  // Calibrate a sheet-of-light setup with a 3D calibration object.
  virtual double CalibrateSheetOfLight() const;
  // Get the result of a calibrated measurement performed with the 
  // sheet-of-light technique as a 3D object model.
  virtual HObjectModel3D GetSheetOfLightResultObjectModel3d() const;
  // Get the iconic results of a measurement performed with the sheet-of light
  // technique.
  virtual HImage GetSheetOfLightResult(const Halcon::HTuple &ResultName) const;
  // Get the iconic results of a measurement performed with the sheet-of light
  // technique.
  virtual HImage GetSheetOfLightResult(const char *ResultName) const;
  // Apply the calibration transformations to the input disparity image.
  virtual void ApplySheetOfLightCalibration(const HImage &Disparity) const;
  // Set sheet of light profiles by measured disparities.
  virtual void SetProfileSheetOfLight(const HImage &ProfileDisparityImage, const Halcon::HTuple &MovementPoses) const;
  // Process the profile image provided as input and store the resulting
  // disparity to the sheet-of-light model.
  virtual void MeasureProfileSheetOfLight(const HImage &ProfileImage, const Halcon::HTuple &MovementPose) const;
  // Set selected parameters of the sheet-of-light model.
  virtual void SetSheetOfLightParam(const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue) const;
  // Get the value of a parameter, which has been set in a sheet-of-light model.
  virtual HTuple GetSheetOfLightParam(const Halcon::HTuple &GenParamName) const;
  // Get the value of a parameter, which has been set in a sheet-of-light model.
  virtual HTuple GetSheetOfLightParam(const char *GenParamName) const;
  // For a given sheet-of-light model get the names of the generic iconic
  // or control parameters that can be used in the different
  // sheet-of-light operators.
  virtual HTuple QuerySheetOfLightParams(const Halcon::HTuple &QueryName) const;
  // For a given sheet-of-light model get the names of the generic iconic
  // or control parameters that can be used in the different
  // sheet-of-light operators.
  virtual HTuple QuerySheetOfLightParams(const char *QueryName) const;
  // Reset a sheet-of-light model.
  virtual void ResetSheetOfLightModel() const;
  // Create a model to perform 3D-measurements using the sheet-of-light
  // technique.
  virtual void CreateSheetOfLightModel(const HRegion &ProfileRegion, const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues);
  // Create a model to perform 3D-measurements using the sheet-of-light
  // technique.
  virtual void CreateSheetOfLightModel(const HRegion &ProfileRegion, const char *GenParamNames, Hlong GenParamValues);
};

}

#endif
