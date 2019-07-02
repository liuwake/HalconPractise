/*****************************************************************************
 * HScene3D.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HScene3D
 *
 * (c) 2007-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_SCENE_3D_H
#define H_SCENE_3D_H


#include "HCPPToolRef.h"


namespace Halcon {


class LIntExport HScene3D: public HToolBase
{
public:

  // Tool-specific functional class constructors

  HScene3D();

  // Common tool class management functionality

  HScene3D(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Get the depth or the index of instances in a displayed 3D scene.
  virtual HTuple GetDisplayScene3dInfo(const Halcon::HTuple &WindowHandle, const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Information) const;
  // Get the depth or the index of instances in a displayed 3D scene.
  virtual HTuple GetDisplayScene3dInfo(Hlong WindowHandle, double Row, double Column, const char *Information) const;
  // Set the pose of a 3D scene.
  virtual void SetScene3dToWorldPose(const Halcon::HTuple &ToWorldPose) const;
  // Set the pose of a 3D scene.
  virtual void SetScene3dToWorldPose(double ToWorldPose) const;
  // Set parameters of a 3D scene.
  virtual void SetScene3dParam(const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue) const;
  // Set parameters of a light in a 3D scene.
  virtual void SetScene3dLightParam(const Halcon::HTuple &LightIndex, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue) const;
  // Set the pose of an instance in a 3D scene.
  virtual void SetScene3dInstancePose(const Halcon::HTuple &InstanceIndex, const Halcon::HTuple &Pose) const;
  // Set the pose of an instance in a 3D scene.
  virtual void SetScene3dInstancePose(Hlong InstanceIndex, double Pose) const;
  // Set parameters of an instance in a 3D scene.
  virtual void SetScene3dInstanceParam(const Halcon::HTuple &InstanceIndex, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue) const;
  // Set the pose of a camera in a 3D scene.
  virtual void SetScene3dCameraPose(const Halcon::HTuple &CameraIndex, const Halcon::HTuple &Pose) const;
  // Set the pose of a camera in a 3D scene.
  virtual void SetScene3dCameraPose(Hlong CameraIndex, double Pose) const;
  // Render an image of a 3D scene.
  virtual HImage RenderScene3d(const Halcon::HTuple &CameraIndex) const;
  // Render an image of a 3D scene.
  virtual HImage RenderScene3d(Hlong CameraIndex) const;
  // Remove a light from a 3D scene.
  virtual void RemoveScene3dLight(const Halcon::HTuple &LightIndex) const;
  // Remove a light from a 3D scene.
  virtual void RemoveScene3dLight(Hlong LightIndex) const;
  // Remove an object instance from a 3D scene.
  virtual void RemoveScene3dInstance(const Halcon::HTuple &InstanceIndex) const;
  // Remove an object instance from a 3D scene.
  virtual void RemoveScene3dInstance(Hlong InstanceIndex) const;
  // Remove a camera from a 3D scene.
  virtual void RemoveScene3dCamera(const Halcon::HTuple &CameraIndex) const;
  // Remove a camera from a 3D scene.
  virtual void RemoveScene3dCamera(Hlong CameraIndex) const;
  // Display a 3D scene.
  virtual void DisplayScene3d(const Halcon::HTuple &WindowHandle, const Halcon::HTuple &CameraIndex) const;
  // Add a light source to a 3D scene.
  virtual Hlong AddScene3dLight(const Halcon::HTuple &LightPosition, const Halcon::HTuple &LightKind) const;
  // Add an instance of a 3D object model to a 3D scene.
  virtual Hlong AddScene3dInstance(const Halcon::HTuple &ObjectModel3D, const Halcon::HTuple &Pose) const;
  // Add a camera to a 3D scene.
  virtual Hlong AddScene3dCamera(const Halcon::HTuple &CameraParam) const;
  // Create the data structure that is needed to visualize collections of
  // 3D objects.
  virtual void CreateScene3d(void);
};

}

#endif
