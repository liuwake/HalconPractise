/*****************************************************************************
 * HSurfaceModel.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HSurfaceModel
 *
 * (c) 2007-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_SURFACE_MODEL_H
#define H_SURFACE_MODEL_H


#include "HCPPToolRef.h"


namespace Halcon {


class LIntExport HSurfaceModel: public HToolBase
{
public:

  // Tool-specific functional class constructors

  HSurfaceModel(const Halcon::HObjectModel3D &ObjectModel3DID, 
                const Halcon::HTuple &RelSamplingDistance, 
                const Halcon::HTuple &GenParamName, 
                const Halcon::HTuple &GenParamValue);


  // Common tool class management functionality

  HSurfaceModel();
  HSurfaceModel(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Free the memory of all surface models.
  static void ClearAllSurfaceModels(void);
  // Deserialize a surface model.
  virtual void DeserializeSurfaceModel(const Halcon::HSerializedItem &SerializedItemHandle);
  // Serialize a surface_model.
  virtual HSerializedItem SerializeSurfaceModel() const;
  // Read a surface model from a file.
  virtual void ReadSurfaceModel(const Halcon::HTuple &FileName);
  // Read a surface model from a file.
  virtual void ReadSurfaceModel(const char *FileName);
  // Write a surface model to a file.
  virtual void WriteSurfaceModel(const Halcon::HTuple &FileName) const;
  // Write a surface model to a file.
  virtual void WriteSurfaceModel(const char *FileName) const;
  // Refine the pose of a surface model in a 3D scene.
  virtual HTuple RefineSurfaceModelPose(const Halcon::HObjectModel3D &ObjectModel3D, const Halcon::HTuple &InitialPose, const Halcon::HTuple &MinScore, const Halcon::HTuple &ReturnResultHandle, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue, Halcon::HTuple *Score, Halcon::HTuple *SurfaceMatchingResultID) const;
  // Refine the pose of a surface model in a 3D scene.
  virtual HTuple RefineSurfaceModelPose(const Halcon::HObjectModel3D &ObjectModel3D, const Halcon::HTuple &InitialPose, const Halcon::HTuple &MinScore, const Halcon::HTuple &ReturnResultHandle, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue, Halcon::HTuple *Score, Hlong *SurfaceMatchingResultID) const;
  // Find the best matches of a surface model in a 3D scene.
  virtual HTuple FindSurfaceModel(const Halcon::HObjectModel3D &ObjectModel3D, const Halcon::HTuple &RelSamplingDistance, const Halcon::HTuple &KeyPointFraction, const Halcon::HTuple &MinScore, const Halcon::HTuple &ReturnResultHandle, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue, Halcon::HTuple *Score, Halcon::HTuple *SurfaceMatchingResultID) const;
  // Find the best matches of a surface model in a 3D scene.
  virtual HTuple FindSurfaceModel(const Halcon::HObjectModel3D &ObjectModel3D, const Halcon::HTuple &RelSamplingDistance, const Halcon::HTuple &KeyPointFraction, const Halcon::HTuple &MinScore, const Halcon::HTuple &ReturnResultHandle, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue, Halcon::HTuple *Score, Hlong *SurfaceMatchingResultID) const;
  // Return the parameters and properties of a surface model.
  virtual HTuple GetSurfaceModelParam(const Halcon::HTuple &ParamName) const;
  // Return the parameters and properties of a surface model.
  virtual HTuple GetSurfaceModelParam(const char *ParamName) const;
  // Create the data structure needed to perform surface-based matching.
  virtual void CreateSurfaceModel(const Halcon::HObjectModel3D &ObjectModel3D, const Halcon::HTuple &RelSamplingDistance, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue);
};

}

#endif
