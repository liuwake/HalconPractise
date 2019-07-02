/*****************************************************************************
 * HShapeModel3D.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HShapeModel3D
 *
 * (c) 2007-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_SHAPE_MODEL_3D_H
#define H_SHAPE_MODEL_3D_H


#include "HCPPToolRef.h"


namespace Halcon {


class LIntExport HShapeModel3D: public HToolBase 
{
public:

  // Tool-specific functional class constructors

  HShapeModel3D(
          const HObjectModel3D &ObjectModel3DID,
          const HTuple &CamParam, 
          const HTuple &RefRotX, 
          const HTuple &RefRotY, 
          const HTuple &RefRotZ,
          const HTuple &OrderOfRotation,
          const HTuple &LongitudeMin,
          const HTuple &LongitudeMax,
          const HTuple &LatitudeMin,
          const HTuple &LatitudeMax,
          const HTuple &CamRollMin,
          const HTuple &CamRollMax,
          const HTuple &DistMin,
          const HTuple &DistMax,
          const HTuple &MinContrast, 
          const HTuple &GenParamNames, 
          const HTuple &GenParamValues);
          
  HShapeModel3D(
          const HObjectModel3D &ObjectModel3DID,
          const HTuple   &CamParam,
          const double RefRotX,
          const double RefRotY,
          const double RefRotZ,
          const char   *OrderOfRotation,
          const double LongitudeMin,
          const double LongitudeMax,
          const double LatitudeMin,
          const double LatitudeMax,
          const double CamRollMin,
          const double CamRollMax,
          const double DistMin,
          const double DistMax,
          const Hlong  MinContrast, 
          const HTuple &GenParamNames, 
          const HTuple &GenParamValues);
          

  // Common tool class management functionality

  HShapeModel3D();
  HShapeModel3D(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Deserialize a serialized 3D shape model.
  virtual void DeserializeShapeModel3d(const Halcon::HSerializedItem &SerializedItemHandle);
  // Serialize a 3D shape model.
  virtual HSerializedItem SerializeShapeModel3d() const;
  // Read a 3D shape model from a file.
  virtual void ReadShapeModel3d(const Halcon::HTuple &FileName);
  // Read a 3D shape model from a file.
  virtual void ReadShapeModel3d(const char *FileName);
  // Write a 3D shape model to a file.
  virtual void WriteShapeModel3d(const Halcon::HTuple &FileName) const;
  // Write a 3D shape model to a file.
  virtual void WriteShapeModel3d(const char *FileName) const;
  // Transform a pose that refers to the coordinate system of a 3D object
  // model to a pose that refers to the reference coordinate system of a
  // 3D shape model and vice versa.
  virtual HTuple TransPoseShapeModel3d(const Halcon::HTuple &PoseIn, const Halcon::HTuple &Transformation) const;
  // Project the edges of a 3D shape model into image coordinates.
  virtual HXLDContArray ProjectShapeModel3d(const Halcon::HTuple &CamParam, const Halcon::HTuple &Pose, const Halcon::HTuple &HiddenSurfaceRemoval, const Halcon::HTuple &MinFaceAngle) const;
  // Return the contour representation of a 3D shape model view.
  virtual HXLDContArray GetShapeModel3dContours(const Halcon::HTuple &Level, const Halcon::HTuple &View, Halcon::HTuple *ViewPose) const;
  // Return the contour representation of a 3D shape model view.
  virtual HXLDContArray GetShapeModel3dContours(Hlong Level, Hlong View, Halcon::HTuple *ViewPose) const;
  // Return the parameters of a 3D shape model.
  virtual HTuple GetShapeModel3dParams(const Halcon::HTuple &GenParamNames) const;
  // Return the parameters of a 3D shape model.
  virtual HTuple GetShapeModel3dParams(const char *GenParamNames) const;
  // Find the best matches of a 3D shape model in an image.
  virtual HTuple FindShapeModel3d(const HImage &Image, const Halcon::HTuple &MinScore, const Halcon::HTuple &Greediness, const Halcon::HTuple &NumLevels, const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues, Halcon::HTuple *CovPose, Halcon::HTuple *Score) const;
  // Prepare a 3D object model for matching.
  virtual void CreateShapeModel3d(const Halcon::HObjectModel3D &ObjectModel3D, const Halcon::HTuple &CamParam, const Halcon::HTuple &RefRotX, const Halcon::HTuple &RefRotY, const Halcon::HTuple &RefRotZ, const Halcon::HTuple &OrderOfRotation, const Halcon::HTuple &LongitudeMin, const Halcon::HTuple &LongitudeMax, const Halcon::HTuple &LatitudeMin, const Halcon::HTuple &LatitudeMax, const Halcon::HTuple &CamRollMin, const Halcon::HTuple &CamRollMax, const Halcon::HTuple &DistMin, const Halcon::HTuple &DistMax, const Halcon::HTuple &MinContrast, const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues);
};

}

#endif
