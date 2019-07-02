/*****************************************************************************
 * HObjectModel3D.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HObjectModel3D
 *
 * (c) 2007-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_OBJECT_MODEL_3D_H
#define H_OBJECT_MODEL_3D_H


#include "HCPPToolRef.h"


namespace Halcon {


class LIntExport HObjectModel3D: public HToolBase
{
public:

  // Tool-specific functional class constructors

  HObjectModel3D(const HTuple &FileName, 
                 const HTuple &Scale,
                 const HTuple &GenParamNames, 
                 const HTuple &GenParamValues,
                 HTuple *DxfStatus);

  HObjectModel3D(const HImage &X, 
                 const HImage &Y, 
                 const HImage &Z);
                 
  HObjectModel3D(const HTuple &X,
                 const HTuple &Y,
                 const HTuple &Z);

  HObjectModel3D(double X,
                 double Y,
                 double Z);

  // Common tool class management functionality

  HObjectModel3D();
  HObjectModel3D(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Get the result of a calibrated measurement performed with the 
  // sheet-of-light technique as a 3D object model.
  virtual void GetSheetOfLightResultObjectModel3d(const Halcon::HSheetOfLightModel &SheetOfLightModelID);
  // Fit 3D primitives into a set of 3D points.
  virtual HTuple FitPrimitivesObjectModel3d(const Halcon::HTuple &ParamName, const Halcon::HTuple &ParamValue) const;
  // Segment a set of 3D points into sub-sets with similar characteristics.
  virtual HTuple SegmentObjectModel3d(const Halcon::HTuple &ParamName, const Halcon::HTuple &ParamValue) const;
  // Calculate the 3D surface normals of a 3D object model.
  virtual HTuple SurfaceNormalsObjectModel3d(const Halcon::HTuple &Method, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue) const;
  // Calculate the 3D surface normals of a 3D object model.
  virtual HTuple SurfaceNormalsObjectModel3d(const char *Method, const char *GenParamName, double GenParamValue) const;
  // Smooth the 3D points of a 3D object model.
  virtual HTuple SmoothObjectModel3d(const Halcon::HTuple &Method, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue) const;
  // Smooth the 3D points of a 3D object model.
  virtual HTuple SmoothObjectModel3d(const char *Method, const char *GenParamName, double GenParamValue) const;
  // Create a surface triangulation for a 3D object model.
  virtual HTuple TriangulateObjectModel3d(const Halcon::HTuple &Method, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue, Halcon::HTuple *Information) const;
  // Create a surface triangulation for a 3D object model.
  virtual HTuple TriangulateObjectModel3d(const Halcon::HTuple &Method, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue, Hlong *Information) const;
  // Create a surface triangulation for a 3D object model.
  virtual HTuple TriangulateObjectModel3d(const char *Method, const char *GenParamName, double GenParamValue, Halcon::HTuple *Information) const;
  // Create a surface triangulation for a 3D object model.
  virtual HTuple TriangulateObjectModel3d(const char *Method, const char *GenParamName, double GenParamValue, Hlong *Information) const;
  // Reconstruct surface from calibrated multi-view stereo images.
  virtual void ReconstructSurfaceStereo(const HImageArray &Images, const Halcon::HStereoModel &StereoModelID);
  // Refine the position and deformation of a deformable surface model in a
  // 3D scene.
  virtual HTuple RefineDeformableSurfaceModel(const Halcon::HDeformableSurfaceModel &DeformableSurfaceModel, const Halcon::HTuple &RelSamplingDistance, const Halcon::HObjectModel3D &InitialDeformationObjectModel3D, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue, Halcon::HTuple *DeformableSurfaceMatchingResult) const;
  // Refine the position and deformation of a deformable surface model in a
  // 3D scene.
  virtual double RefineDeformableSurfaceModel(const Halcon::HDeformableSurfaceModel &DeformableSurfaceModel, const Halcon::HTuple &RelSamplingDistance, const Halcon::HObjectModel3D &InitialDeformationObjectModel3D, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue, Hlong *DeformableSurfaceMatchingResult) const;
  // Find the best match of a deformable surface model in a 3D scene.
  virtual HTuple FindDeformableSurfaceModel(const Halcon::HDeformableSurfaceModel &DeformableSurfaceModel, const Halcon::HTuple &RelSamplingDistance, const Halcon::HTuple &MinScore, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue, Halcon::HTuple *DeformableSurfaceMatchingResult) const;
  // Find the best match of a deformable surface model in a 3D scene.
  virtual double FindDeformableSurfaceModel(const Halcon::HDeformableSurfaceModel &DeformableSurfaceModel, const Halcon::HTuple &RelSamplingDistance, const Halcon::HTuple &MinScore, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue, Hlong *DeformableSurfaceMatchingResult) const;
  // Add a sample deformation to a deformable surface model
  virtual void AddDeformableSurfaceModelSample(const Halcon::HDeformableSurfaceModel &DeformableSurfaceModel) const;
  // Create the data structure needed to perform deformable
  // surface-based matching.
  virtual HDeformableSurfaceModel CreateDeformableSurfaceModel(const Halcon::HTuple &RelSamplingDistance, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue) const;
  // Refine the pose of a surface model in a 3D scene.
  virtual HTuple RefineSurfaceModelPose(const Halcon::HSurfaceModel &SurfaceModelID, const Halcon::HTuple &InitialPose, const Halcon::HTuple &MinScore, const Halcon::HTuple &ReturnResultHandle, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue, Halcon::HTuple *Score, Halcon::HTuple *SurfaceMatchingResultID) const;
  // Refine the pose of a surface model in a 3D scene.
  virtual HTuple RefineSurfaceModelPose(const Halcon::HSurfaceModel &SurfaceModelID, const Halcon::HTuple &InitialPose, const Halcon::HTuple &MinScore, const Halcon::HTuple &ReturnResultHandle, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue, Halcon::HTuple *Score, Hlong *SurfaceMatchingResultID) const;
  // Find the best matches of a surface model in a 3D scene.
  virtual HTuple FindSurfaceModel(const Halcon::HSurfaceModel &SurfaceModelID, const Halcon::HTuple &RelSamplingDistance, const Halcon::HTuple &KeyPointFraction, const Halcon::HTuple &MinScore, const Halcon::HTuple &ReturnResultHandle, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue, Halcon::HTuple *Score, Halcon::HTuple *SurfaceMatchingResultID) const;
  // Find the best matches of a surface model in a 3D scene.
  virtual HTuple FindSurfaceModel(const Halcon::HSurfaceModel &SurfaceModelID, const Halcon::HTuple &RelSamplingDistance, const Halcon::HTuple &KeyPointFraction, const Halcon::HTuple &MinScore, const Halcon::HTuple &ReturnResultHandle, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue, Halcon::HTuple *Score, Hlong *SurfaceMatchingResultID) const;
  // Create the data structure needed to perform surface-based matching.
  virtual HSurfaceModel CreateSurfaceModel(const Halcon::HTuple &RelSamplingDistance, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue) const;
  // Simplify a triangulated 3D object model.
  virtual HTuple SimplifyObjectModel3d(const Halcon::HTuple &Method, const Halcon::HTuple &Amount, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue) const;
  // Compute the distances of the points of one 3D object model to another
  // 3D object model.
  virtual void DistanceObjectModel3d(const Halcon::HObjectModel3D &ObjectModel3DTo, const Halcon::HTuple &Pose, const Halcon::HTuple &MaxDistance, const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues) const;
  // Combine several 3D object models to a new 3D object model.
  virtual HObjectModel3D UnionObjectModel3d(const Halcon::HTuple &Method) const;
  // Combine several 3D object models to a new 3D object model.
  virtual HObjectModel3D UnionObjectModel3d(const char *Method) const;
  // Set attributes of a 3D object model.
  virtual void SetObjectModel3dAttribMod(const Halcon::HTuple &AttribName, const Halcon::HTuple &AttachExtAttribTo, const Halcon::HTuple &AttribValues) const;
  // Set attributes of a 3D object model.
  virtual void SetObjectModel3dAttribMod(const char *AttribName, const char *AttachExtAttribTo, double AttribValues) const;
  // Set attributes of a 3D object model.
  virtual HObjectModel3D SetObjectModel3dAttrib(const Halcon::HTuple &AttribName, const Halcon::HTuple &AttachExtAttribTo, const Halcon::HTuple &AttribValues) const;
  // Set attributes of a 3D object model.
  virtual HObjectModel3D SetObjectModel3dAttrib(const char *AttribName, const char *AttachExtAttribTo, double AttribValues) const;
  // Create an empty 3D object model.
  virtual void GenEmptyObjectModel3d(void);
  // Sample a 3D object model.
  virtual HTuple SampleObjectModel3d(const Halcon::HTuple &Method, const Halcon::HTuple &SampleDistance, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue) const;
  // Sample a 3D object model.
  virtual HTuple SampleObjectModel3d(const char *Method, double SampleDistance, const char *GenParamName, double GenParamValue) const;
  // Improve the relative transformations between 3D object models based on 
  // their overlaps.
  virtual HTuple RegisterObjectModel3dGlobal(const Halcon::HTuple &HomMats3D, const Halcon::HTuple &From, const Halcon::HTuple &To, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue, Halcon::HTuple *Scores) const;
  // Search for a transformation between two 3D object models.
  virtual HTuple RegisterObjectModel3dPair(const Halcon::HObjectModel3D &ObjectModel3D2, const Halcon::HTuple &Method, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue, Halcon::HTuple *Score) const;
  // Search for a transformation between two 3D object models.
  virtual HTuple RegisterObjectModel3dPair(const Halcon::HObjectModel3D &ObjectModel3D2, const char *Method, const char *GenParamName, double GenParamValue, Halcon::HTuple *Score) const;
  // Create a 3D object model that represents a point cloud from a set of 3D points.
  virtual void GenObjectModel3dFromPoints(const Halcon::HTuple &X, const Halcon::HTuple &Y, const Halcon::HTuple &Z);
  // Create a 3D object model that represents a point cloud from a set of 3D points.
  virtual void GenObjectModel3dFromPoints(double X, double Y, double Z);
  // Create a 3D object model that represents a box.
  virtual void GenBoxObjectModel3d(const Halcon::HTuple &Pose, const Halcon::HTuple &LengthX, const Halcon::HTuple &LengthY, const Halcon::HTuple &LengthZ);
  // Create a 3D object model that represents a plane.
  virtual void GenPlaneObjectModel3d(const Halcon::HTuple &Pose, const Halcon::HTuple &XExtent, const Halcon::HTuple &YExtent);
  // Create a 3D object model that represents a sphere from x,y,z coordinates.
  virtual void GenSphereObjectModel3dCenter(const Halcon::HTuple &X, const Halcon::HTuple &Y, const Halcon::HTuple &Z, const Halcon::HTuple &Radius);
  // Create a 3D object model that represents a sphere from x,y,z coordinates.
  virtual void GenSphereObjectModel3dCenter(double X, double Y, double Z, double Radius);
  // Create a 3D object model that represents a sphere.
  virtual void GenSphereObjectModel3d(const Halcon::HTuple &Pose, const Halcon::HTuple &Radius);
  // Create a 3D object model that represents a cylinder.
  virtual void GenCylinderObjectModel3d(const Halcon::HTuple &Pose, const Halcon::HTuple &Radius, const Halcon::HTuple &MinExtent, const Halcon::HTuple &MaxExtent);
  //  Calculate the smallest bounding box around the points of a 
  //  3D object model.
  virtual HTuple SmallestBoundingBoxObjectModel3d(const Halcon::HTuple &Type, Halcon::HTuple *Length1, Halcon::HTuple *Length2, Halcon::HTuple *Length3) const;
  //  Calculate the smallest bounding box around the points of a 
  //  3D object model.
  virtual HTuple SmallestBoundingBoxObjectModel3d(const Halcon::HTuple &Type, double *Length1, double *Length2, double *Length3) const;
  //  Calculate the smallest bounding box around the points of a 
  //  3D object model.
  virtual HTuple SmallestBoundingBoxObjectModel3d(const char *Type, Halcon::HTuple *Length1, Halcon::HTuple *Length2, Halcon::HTuple *Length3) const;
  //  Calculate the smallest bounding box around the points of a 
  //  3D object model.
  virtual HTuple SmallestBoundingBoxObjectModel3d(const char *Type, double *Length1, double *Length2, double *Length3) const;
  // Calculate the smallest sphere around the points of a 3D object model.
  virtual HTuple SmallestSphereObjectModel3d(Halcon::HTuple *Radius) const;
  // Calculate the smallest sphere around the points of a 3D object model.
  virtual HTuple SmallestSphereObjectModel3d(double *Radius) const;
  // Intersect a 3D object model with a plane.
  virtual HTuple IntersectPlaneObjectModel3d(const Halcon::HTuple &Plane) const;
  // Calculate the convex hull of a 3D object model. 
  virtual HTuple ConvexHullObjectModel3d() const;
  // Select 3D object models from an array of 3D object models according 
  // to global features.
  virtual HTuple SelectObjectModel3d(const Halcon::HTuple &Feature, const Halcon::HTuple &Operation, const Halcon::HTuple &MinValue, const Halcon::HTuple &MaxValue) const;
  // Select 3D object models from an array of 3D object models according 
  // to global features.
  virtual HTuple SelectObjectModel3d(const char *Feature, const char *Operation, double MinValue, double MaxValue) const;
  // Calculate the area of all faces of a 3D object model.
  virtual HTuple AreaObjectModel3d() const;
  // Calculate the maximal diameter of a 3D object model.
  virtual HTuple MaxDiameterObjectModel3d() const;
  // Calculates the mean or the central moment of second order for a 3D object 
  // model.
  virtual HTuple MomentsObjectModel3d(const Halcon::HTuple &MomentsToCalculate) const;
  // Calculates the mean or the central moment of second order for a 3D object 
  // model.
  virtual HTuple MomentsObjectModel3d(const char *MomentsToCalculate) const;
  // Calculate the volume of a 3D object model relative to a plane.
  virtual HTuple VolumeObjectModel3dRelativeToPlane(const Halcon::HTuple &Plane, const Halcon::HTuple &Mode, const Halcon::HTuple &UseFaceOrientation) const;
  // Remove points from a 3D object model by projecting it to a virtual view 
  // and removing all points outside of a given region.
  virtual HTuple ReduceObjectModel3dByView(const HRegionArray &Region, const Halcon::HTuple &CamParam, const Halcon::HTuple &Pose) const;
  // Determine the connected components of the
  // 3D object model.
  virtual HTuple ConnectionObjectModel3d(const Halcon::HTuple &Feature, const Halcon::HTuple &Value) const;
  // Determine the connected components of the
  // 3D object model.
  virtual HTuple ConnectionObjectModel3d(const char *Feature, double Value) const;
  // Apply a threshold to an attribute of 3D object models.
  virtual HTuple SelectPointsObjectModel3d(const Halcon::HTuple &Attrib, const Halcon::HTuple &MinValue, const Halcon::HTuple &MaxValue) const;
  // Apply a threshold to an attribute of 3D object models.
  virtual HTuple SelectPointsObjectModel3d(const char *Attrib, double MinValue, double MaxValue) const;
  // Get the depth or the index of a displayed 3D object model.
  static HTuple GetDispObjectModel3dInfo(const Halcon::HTuple &WindowHandle, const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Information);
  // Get the depth or the index of a displayed 3D object model.
  static HTuple GetDispObjectModel3dInfo(Hlong WindowHandle, double Row, double Column, const char *Information);
  // Render 3D object models to get an image.
  virtual HImage RenderObjectModel3d(const Halcon::HTuple &CamParam, const Halcon::HTuple &Pose, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue) const;
  // Display 3D object models.
  virtual void DispObjectModel3d(const Halcon::HTuple &WindowHandle, const Halcon::HTuple &CamParam, const Halcon::HTuple &Pose, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue) const;
  // Copy a 3D object model.
  virtual HObjectModel3D CopyObjectModel3d(const Halcon::HTuple &Attributes) const;
  // Prepare a 3D object model for a certain operation.
  virtual void PrepareObjectModel3d(const Halcon::HTuple &Purpose, const Halcon::HTuple &OverwriteData, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue) const;
  // Transform 3D points from a 3D object model to images.
  virtual HImage ObjectModel3dToXyz(HImage *Y, HImage *Z, const Halcon::HTuple &Type, const Halcon::HTuple &CamParam, const Halcon::HTuple &Pose) const;
  // Transform 3D points from images to a 3D object model.
  virtual void XyzToObjectModel3d(const HImage &X, const HImage &Y, const HImage &Z);
  // Return attributes of 3D object models.
  virtual HTuple GetObjectModel3dParams(const Halcon::HTuple &ParamName) const;
  // Return attributes of 3D object models.
  virtual HTuple GetObjectModel3dParams(const char *ParamName) const;
  // Project a 3D object model into image coordinates.
  virtual HXLDContArray ProjectObjectModel3d(const Halcon::HTuple &CamParam, const Halcon::HTuple &Pose, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue) const;
  // Apply a rigid 3D transformation to 3D object models.
  virtual HTuple RigidTransObjectModel3d(const Halcon::HTuple &Pose) const;
  // Apply an arbitrary projective 3D transformation to 3D object models.
  virtual HTuple ProjectiveTransObjectModel3d(const Halcon::HTuple &HomMat3D) const;
  // Apply an arbitrary affine 3D transformation to 3D object models.
  virtual HTuple AffineTransObjectModel3d(const Halcon::HTuple &HomMat3D) const;
  // Serialize a 3D object model.
  virtual HSerializedItem SerializeObjectModel3d() const;
  // Deserialize a serialized 3D object model.
  virtual void DeserializeObjectModel3d(const Halcon::HSerializedItem &SerializedItemHandle);
  // Writes a 3D object model to a file.
  virtual void WriteObjectModel3d(const Halcon::HTuple &FileType, const Halcon::HTuple &FileName, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue) const;
  // Read a 3D object model from a file.
  virtual HTuple ReadObjectModel3d(const Halcon::HTuple &FileName, const Halcon::HTuple &Scale, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue);
  // Read a 3D object model from a DXF file.
  virtual HTuple ReadObjectModel3dDxf(const Halcon::HTuple &FileName, const Halcon::HTuple &Scale, const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues);
  // Compute the calibrated scene flow between two stereo image pairs.
  virtual void SceneFlowCalib(const HImageArray &ImageRect1T1, const HImageArray &ImageRect2T1, const HImageArray &ImageRect1T2, const HImageArray &ImageRect2T2, const HImageArray &Disparity, const Halcon::HTuple &SmoothingFlow, const Halcon::HTuple &SmoothingDisparity, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue, const Halcon::HTuple &CamParamRect1, const Halcon::HTuple &CamParamRect2, const Halcon::HTuple &RelPoseRect);
};

}

#endif
