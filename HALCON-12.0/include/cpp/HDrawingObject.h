/*****************************************************************************
 * HDrawingObject.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HDrawingObject
 *
 * (c) 2014 by MVTec Software GmbH
 *             www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_DRAWING_OBJECT_H
#define H_DRAWING_OBJECT_H

#include "HCPPToolRef.h"

namespace Halcon {


class LIntExport HDrawingObject: public HToolBase
{
public:
  
  // Tool-specific functional class constructors
  // rectangle1
  HDrawingObject(const HTuple& Row1,
              const HTuple& Column1,
              const HTuple& Row2,
              const HTuple& Column2);

  // circle
  HDrawingObject(const HTuple& Row,
              const HTuple& Column,
              const HTuple& Radius);


  // Common tool class management functionality

  HDrawingObject();
  HDrawingObject(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Add a callback function to a drawing object.
  virtual void SetDrawingObjectCallback(const Halcon::HTuple &DrawObjectEvent, const Halcon::HTuple &CallbackFunction) const;
  // Add a callback function to a drawing object.
  virtual void SetDrawingObjectCallback(const char *DrawObjectEvent, Hlong CallbackFunction) const;
  // Detach the background image from a HALCON window.
  static void DetachBackgroundFromWindow(const Halcon::HTuple &WindowHandle);
  // Detach the background image from a HALCON window.
  static void DetachBackgroundFromWindow(Hlong WindowHandle);
  // Attach a background image to a HALCON window.
  static void AttachBackgroundToWindow(const HImage &Image, const Halcon::HTuple &WindowHandle);
  // Attach a background image to a HALCON window.
  static void AttachBackgroundToWindow(const HImage &Image, Hlong WindowHandle);
  // Create a text object which can be moved interactively.
  virtual void CreateDrawingObjectText(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &String);
  // Create a text object which can be moved interactively.
  virtual void CreateDrawingObjectText(Hlong Row, Hlong Column, const char *String);
  // Set the parameters of a drawing object.
  virtual void SetDrawingObjectParams(const Halcon::HTuple &ParamNames, const Halcon::HTuple &ParamValues) const;
  // Set the parameters of a drawing object.
  virtual void SetDrawingObjectParams(const char *ParamNames, double ParamValues) const;
  // Get the parameters of a drawing object.
  virtual HTuple GetDrawingObjectParams(const Halcon::HTuple &ParamNames) const;
  // Get the parameters of a drawing object.
  virtual HTuple GetDrawingObjectParams(const char *ParamNames) const;
  // Set the contour of an interactive draw XLD.
  virtual void SetDrawingObjectXld(const HXLDCont &Contour) const;
  // Create a XLD contour which can be modified interactively.
  virtual void CreateDrawingObjectXld(const Halcon::HTuple &Row, const Halcon::HTuple &Column);
  // Create a circle sector which can be modified interactively.
  virtual void CreateDrawingObjectCircleSector(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Radius, const Halcon::HTuple &StartAngle, const Halcon::HTuple &EndAngle);
  // Create a circle sector which can be modified interactively.
  virtual void CreateDrawingObjectCircleSector(double Row, double Column, double Radius, double StartAngle, double EndAngle);
  // Create an elliptic sector which can be modified interactively.
  virtual void CreateDrawingObjectEllipseSector(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Phi, const Halcon::HTuple &Radius1, const Halcon::HTuple &Radius2, const Halcon::HTuple &StartAngle, const Halcon::HTuple &EndAngle);
  // Create an elliptic sector which can be modified interactively.
  virtual void CreateDrawingObjectEllipseSector(double Row, double Column, double Phi, double Radius1, double Radius2, double StartAngle, double EndAngle);
  // Create a line which can be modified interactively.
  virtual void CreateDrawingObjectLine(const Halcon::HTuple &Row1, const Halcon::HTuple &Column1, const Halcon::HTuple &Row2, const Halcon::HTuple &Column2);
  // Create a line which can be modified interactively.
  virtual void CreateDrawingObjectLine(double Row1, double Column1, double Row2, double Column2);
  // Create a circle which can be modified interactively.
  virtual void CreateDrawingObjectCircle(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Radius);
  // Create a circle which can be modified interactively.
  virtual void CreateDrawingObjectCircle(double Row, double Column, double Radius);
  // Create an ellipse which can be modified interactively.
  virtual void CreateDrawingObjectEllipse(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Phi, const Halcon::HTuple &Radius1, const Halcon::HTuple &Radius2);
  // Create an ellipse which can be modified interactively.
  virtual void CreateDrawingObjectEllipse(double Row, double Column, double Phi, double Radius1, double Radius2);
  // Create a rectangle of any orientation which can be modified interactively.
  virtual void CreateDrawingObjectRectangle2(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Phi, const Halcon::HTuple &Length1, const Halcon::HTuple &Length2);
  // Create a rectangle of any orientation which can be modified interactively.
  virtual void CreateDrawingObjectRectangle2(double Row, double Column, double Phi, double Length1, double Length2);
  // Create a rectangle parallel to the coordinate axis which can be
  // modified interactively.
  virtual void CreateDrawingObjectRectangle1(const Halcon::HTuple &Row1, const Halcon::HTuple &Column1, const Halcon::HTuple &Row2, const Halcon::HTuple &Column2);
  // Create a rectangle parallel to the coordinate axis which can be
  // modified interactively.
  virtual void CreateDrawingObjectRectangle1(double Row1, double Column1, double Row2, double Column2);
};

}

#endif
