/*****************************************************************************
 * HStereoModel.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HStereoModel
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_STEREO_MODEL_H
#define H_STEREO_MODEL_H


#include "HCPPToolRef.h"


namespace Halcon {


class LIntExport HStereoModel: public HToolBase 
{
public:

  // Tool-specific functional class constructors
  HStereoModel(const Halcon::HCameraSetupModel &CameraSetupModel,
               const Halcon::HTuple &Method,
               const Halcon::HTuple &GenParamNames,
               const Halcon::HTuple &GenParamValues);
  HStereoModel(const Halcon::HCameraSetupModel &CameraSetupModel,
               const char *Method, const char *GenParamNames,
               double GenParamValues);
  // Common tool class management functionality

  HStereoModel();
  HStereoModel(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Reconstruct 3D points from calibrated multi-view stereo images.
  virtual HTuple ReconstructPointsStereo(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &CovIP, const Halcon::HTuple &CameraIdx, const Halcon::HTuple &PointIdx, Halcon::HTuple *Y, Halcon::HTuple *Z, Halcon::HTuple *CovWP, Halcon::HTuple *PointIdxOut) const;
  // Reconstruct 3D points from calibrated multi-view stereo images.
  virtual double ReconstructPointsStereo(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &CovIP, const Halcon::HTuple &CameraIdx, const Halcon::HTuple &PointIdx, double *Y, double *Z, double *CovWP, Hlong *PointIdxOut) const;
  // Reconstruct surface from calibrated multi-view stereo images.
  virtual HObjectModel3D ReconstructSurfaceStereo(const HImageArray &Images) const;
  // Return the list of image pairs set in a stereo model.
  virtual HTuple GetStereoModelImagePairs(Halcon::HTuple *To) const;
  // Specify image pairs to be used for surface stereo reconstruction.
  virtual void SetStereoModelImagePairs(const Halcon::HTuple &From, const Halcon::HTuple &To) const;
  // Get stereo model parameters.
  virtual HTuple GetStereoModelParam(const Halcon::HTuple &ParamName) const;
  // Get stereo model parameters.
  virtual HTuple GetStereoModelParam(const char *ParamName) const;
  // Set stereo model parameters.
  virtual void SetStereoModelParam(const Halcon::HTuple &ParamName, const Halcon::HTuple &ParamValue) const;
  // Create a HALCON stereo model.
  virtual void CreateStereoModel(const Halcon::HCameraSetupModel &CameraSetupModelID, const Halcon::HTuple &Method, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue);
};

}

#endif
