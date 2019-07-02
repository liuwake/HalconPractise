/*****************************************************************************
 * HSurfaceMatchingResult.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HSurfaceMatchingResult
 *
 * (c) 2007-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_SURFACE_MATCHING_RESULT_H
#define H_SURFACE_MATCHING_RESULT_H


#include "HCPPToolRef.h"


namespace Halcon {


class LIntExport HSurfaceMatchingResult: public HToolBase
{
public:

  // Tool-specific functional class constructors

  HSurfaceMatchingResult(const Halcon::HSurfaceModel &SurfaceModelID,
                         const Halcon::HObjectModel3D &ObjectModel3DID, 
                         const Halcon::HTuple &InitialPose, 
                         const Halcon::HTuple &MinScore, 
                         const Halcon::HTuple &ReturnResultHandle, 
                         const Halcon::HTuple &GenParamName, 
                         const Halcon::HTuple &GenParamValue, 
                         Halcon::HTuple *Pose,
                         Halcon::HTuple *Score);
                         
  HSurfaceMatchingResult(const Halcon::HSurfaceModel &SurfaceModelID, 
                         const Halcon::HObjectModel3D &ObjectModel3DID, 
                         const Halcon::HTuple &RelSamplingDistance, 
                         const Halcon::HTuple &RefPointFraction, 
                         const Halcon::HTuple &MinScore, 
                         const Halcon::HTuple &ReturnResultHandle, 
                         const Halcon::HTuple &GenParamName, 
                         const Halcon::HTuple &GenParamValue, 
                         Halcon::HTuple *Pose,
                         Halcon::HTuple *Score);

  // Common tool class management functionality

  HSurfaceMatchingResult();
  HSurfaceMatchingResult(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Get details of a result from surface based matching.
  virtual HTuple GetSurfaceMatchingResult(const Halcon::HTuple &ResultName, const Halcon::HTuple &ResultIndex) const;
  // Get details of a result from surface based matching.
  virtual HTuple GetSurfaceMatchingResult(const char *ResultName, Hlong ResultIndex) const;
  // Free the memory of all surface matching results.
  static void ClearAllSurfaceMatchingResults(void);
  // Refine the pose of a surface model in a 3D scene.
  virtual HTuple RefineSurfaceModelPose(const Halcon::HSurfaceModel &SurfaceModelID, const Halcon::HObjectModel3D &ObjectModel3D, const Halcon::HTuple &InitialPose, const Halcon::HTuple &MinScore, const Halcon::HTuple &ReturnResultHandle, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue, Halcon::HTuple *Score);
  // Find the best matches of a surface model in a 3D scene.
  virtual HTuple FindSurfaceModel(const Halcon::HSurfaceModel &SurfaceModelID, const Halcon::HObjectModel3D &ObjectModel3D, const Halcon::HTuple &RelSamplingDistance, const Halcon::HTuple &KeyPointFraction, const Halcon::HTuple &MinScore, const Halcon::HTuple &ReturnResultHandle, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue, Halcon::HTuple *Score);
};

}

#endif
