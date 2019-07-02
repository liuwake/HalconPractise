/*****************************************************************************
 * HDeformableSurfaceMatchingResult.h
 *****************************************************************************
 *
 * Project:     HALCON/C++
 * Description: Class HDeformableSurfaceMatchingResult
 *
 * (c) 2014-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 *
 *****************************************************************************
 *
 *
 */

#ifndef H_DEFORMABLE_SURFACE_MATCHING_RESULT_H
#define H_DEFORMABLE_SURFACE_MATCHING_RESULT_H


#include "HCPPToolRef.h"


namespace Halcon {


class LIntExport HDeformableSurfaceMatchingResult: public HToolBase
{
public:

  // Tool-specific functional class constructors

  HDeformableSurfaceMatchingResult(const Halcon::HDeformableSurfaceModel &DeformableSurfaceModel,
                                   const Halcon::HObjectModel3D &ObjectModel3D,
                                   const Halcon::HTuple &RelSamplingDistance,
                                   const Halcon::HObjectModel3D &InitialDeformationObjectModel3D,
                                   const Halcon::HTuple &GenParamName,
                                   const Halcon::HTuple &GenParamValue,
                                   Halcon::HTuple *Score);

  HDeformableSurfaceMatchingResult(const Halcon::HDeformableSurfaceModel &DeformableSurfaceModel,
                                   const Halcon::HObjectModel3D &ObjectModel3D,
                                   const Halcon::HTuple &RelSamplingDistance,
                                   const Halcon::HTuple &MinScore,
                                   const Halcon::HTuple &GenParamName,
                                   const Halcon::HTuple &GenParamValue,
                                   Halcon::HTuple *Score);

  // Common tool class management functionality

  HDeformableSurfaceMatchingResult();
  HDeformableSurfaceMatchingResult(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Get details of a result from deformable surface based matching.
  virtual HTuple GetDeformableSurfaceMatchingResult(const Halcon::HTuple &ResultName, const Halcon::HTuple &ResultIndex) const;
  // Get details of a result from deformable surface based matching.
  virtual HTuple GetDeformableSurfaceMatchingResult(const char *ResultName, Hlong ResultIndex) const;
  // Refine the position and deformation of a deformable surface model in a
  // 3D scene.
  virtual HTuple RefineDeformableSurfaceModel(const Halcon::HDeformableSurfaceModel &DeformableSurfaceModel, const Halcon::HObjectModel3D &ObjectModel3D, const Halcon::HTuple &RelSamplingDistance, const Halcon::HObjectModel3D &InitialDeformationObjectModel3D, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue);
  // Find the best match of a deformable surface model in a 3D scene.
  virtual HTuple FindDeformableSurfaceModel(const Halcon::HDeformableSurfaceModel &DeformableSurfaceModel, const Halcon::HObjectModel3D &ObjectModel3D, const Halcon::HTuple &RelSamplingDistance, const Halcon::HTuple &MinScore, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue);
};

}

#endif
