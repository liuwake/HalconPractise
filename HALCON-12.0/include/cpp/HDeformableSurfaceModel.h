/*****************************************************************************
 * HDeformableSurfaceModel.h
 *****************************************************************************
 *
 * Project:     HALCON/C++
 * Description: Class HDeformableSurfaceModel
 *
 * (c) 2014-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 *
 *****************************************************************************
 *
 *
 */

#ifndef H_DEFORMABLE_SURFACE_MODEL_H
#define H_DEFORMABLE_SURFACE_MODEL_H


#include "HCPPToolRef.h"


namespace Halcon {


class LIntExport HDeformableSurfaceModel: public HToolBase
{
public:

  // Tool-specific functional class constructors

  HDeformableSurfaceModel(const Halcon::HObjectModel3D &ObjectModel3DID,
                          const Halcon::HTuple &RelSamplingDistance,
                          const Halcon::HTuple &GenParamName,
                          const Halcon::HTuple &GenParamValue);


  // Common tool class management functionality

  HDeformableSurfaceModel();
  HDeformableSurfaceModel(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Deserialize a deformable surface model.
  virtual void DeserializeDeformableSurfaceModel(const Halcon::HSerializedItem &SerializedItemHandle);
  // Serialize a deformable surface_model.
  virtual HSerializedItem SerializeDeformableSurfaceModel() const;
  // Read a deformable surface model from a file.
  virtual void ReadDeformableSurfaceModel(const Halcon::HTuple &FileName);
  // Read a deformable surface model from a file.
  virtual void ReadDeformableSurfaceModel(const char *FileName);
  // Write a deformable surface model to a file.
  virtual void WriteDeformableSurfaceModel(const Halcon::HTuple &FileName) const;
  // Write a deformable surface model to a file.
  virtual void WriteDeformableSurfaceModel(const char *FileName) const;
  // Refine the position and deformation of a deformable surface model in a
  // 3D scene.
  virtual HTuple RefineDeformableSurfaceModel(const Halcon::HObjectModel3D &ObjectModel3D, const Halcon::HTuple &RelSamplingDistance, const Halcon::HObjectModel3D &InitialDeformationObjectModel3D, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue, Halcon::HTuple *DeformableSurfaceMatchingResult) const;
  // Refine the position and deformation of a deformable surface model in a
  // 3D scene.
  virtual double RefineDeformableSurfaceModel(const Halcon::HObjectModel3D &ObjectModel3D, const Halcon::HTuple &RelSamplingDistance, const Halcon::HObjectModel3D &InitialDeformationObjectModel3D, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue, Hlong *DeformableSurfaceMatchingResult) const;
  // Find the best match of a deformable surface model in a 3D scene.
  virtual HTuple FindDeformableSurfaceModel(const Halcon::HObjectModel3D &ObjectModel3D, const Halcon::HTuple &RelSamplingDistance, const Halcon::HTuple &MinScore, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue, Halcon::HTuple *DeformableSurfaceMatchingResult) const;
  // Find the best match of a deformable surface model in a 3D scene.
  virtual double FindDeformableSurfaceModel(const Halcon::HObjectModel3D &ObjectModel3D, const Halcon::HTuple &RelSamplingDistance, const Halcon::HTuple &MinScore, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue, Hlong *DeformableSurfaceMatchingResult) const;
  // Return the parameters and properties of a deformable surface model.
  virtual HTuple GetDeformableSurfaceModelParam(const Halcon::HTuple &ParamName) const;
  // Return the parameters and properties of a deformable surface model.
  virtual HTuple GetDeformableSurfaceModelParam(const char *ParamName) const;
  // Add a reference point to a deformable surface model.
  virtual HTuple AddDeformableSurfaceModelReferencePoint(const Halcon::HTuple &ReferencePointX, const Halcon::HTuple &ReferencePointY, const Halcon::HTuple &ReferencePointZ) const;
  // Add a reference point to a deformable surface model.
  virtual HTuple AddDeformableSurfaceModelReferencePoint(double ReferencePointX, double ReferencePointY, double ReferencePointZ) const;
  // Add a sample deformation to a deformable surface model
  virtual void AddDeformableSurfaceModelSample(const Halcon::HTuple &ObjectModel3D) const;
  // Add a sample deformation to a deformable surface model
  virtual void AddDeformableSurfaceModelSample(Hlong ObjectModel3D) const;
  // Create the data structure needed to perform deformable
  // surface-based matching.
  virtual void CreateDeformableSurfaceModel(const Halcon::HObjectModel3D &ObjectModel3D, const Halcon::HTuple &RelSamplingDistance, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue);
};

}

#endif
