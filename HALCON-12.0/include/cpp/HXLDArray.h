/*****************************************************************************
 * HXLDArray.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HXLDArray
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 */

#ifndef XLD_ARRAY_H
#define XLD_ARRAY_H


namespace Halcon {


/****************************************************************************/
/*                               HXLDArray                                  */
/****************************************************************************/

class LIntExport HXLDArray: public HObjectArray {
public:
  HXLDArray(void) : HObjectArray(), array(NULL) {}
  HXLDArray(Hlong n, HBOOL single = FALSE) : HObjectArray(n,single),
                                             array(NULL) {}  
  HXLDArray(Hkey *key, Hlong num);
  HXLDArray(const Hobject &obj);
  HXLDArray(const HXLD &xld);
  HXLDArray(const HXLDArray &arr);
  ~HXLDArray(void);

  HXLDArray &operator= (const HXLDArray &arr);

  // Tools
  virtual const char  *HClassName(void) const;
  virtual const char  *ClassName(void) const;
  virtual const char  *InstClassName(void) const;
  virtual       Hkey   Key(Hlong i) const {return array[i].Key();}
  virtual    Hobject   ElemId(Hlong i) const {return array[i].Id();}

  virtual void         Display(const HWindow &w) const;

  // Access and Manipulation
  HXLD  const  &operator[] (Hlong index) const;
  HXLD         &operator[] (Hlong index);
  HXLDArray     operator() (Hlong min, Hlong max) const;
  HXLDArray    &Append(const HXLD &xld);
  HXLDArray    &Append(const HXLDArray &xlds);
  virtual void  SetKeys(Hkey *key, Hlong num);
  virtual void  SetKeys(Hkey *key, Hlong num, Herror *err);
  void          CopyHXLDArray(const HXLDArray &in);
  virtual void  DeleteArray(void);
  // Accessing array elements without index checking -> fast AND risky
  HXLD          Elem(Hlong index) const {return array[index];}

protected:
  HXLD  *array;
private:
  void NewLength(Hlong new_num, Hlong old_num);

  // Class Functions

public:
  // Display an XLD object.
  virtual void DispXld(const Halcon::HTuple &WindowHandle) const;
  // Display an XLD object.
  virtual void DispXld(Hlong WindowHandle) const;
  // Receive an XLD object over a socket connection.
  static HXLDArray ReceiveXld(const Halcon::HSocket &Socket);
  // Send an XLD object over a socket connection.
  virtual void SendXld(const Halcon::HSocket &Socket) const;
  // Paint XLD objects into an image.
  virtual HImage PaintXld(const HImage &Image, const Halcon::HTuple &Grayval) const;
  // Paint XLD objects into an image.
  virtual HImage PaintXld(const HImage &Image, double Grayval) const;
  // Deserialize a serialized XLD object.
  static HXLDArray DeserializeXld(const Halcon::HSerializedItem &SerializedItemHandle);
  // Serialize an XLD object.
  virtual HSerializedItem SerializeXld(void) const;
  // Test whether contours or polygons are closed.
  virtual HTuple TestClosedXld(void) const;
  // Arbitrary geometric moments of contours or polygons treated as point
  // clouds.
  virtual HTuple MomentsAnyPointsXld(const Halcon::HTuple &Mode, const Halcon::HTuple &Area, const Halcon::HTuple &CenterRow, const Halcon::HTuple &CenterCol, const Halcon::HTuple &P, const Halcon::HTuple &Q) const;
  // Arbitrary geometric moments of contours or polygons treated as point
  // clouds.
  virtual HTuple MomentsAnyPointsXld(const char *Mode, double Area, double CenterRow, double CenterCol, Hlong P, Hlong Q) const;
  // Anisometry of contours or polygons treated as point clouds.
  virtual HTuple EccentricityPointsXld(void) const;
  // Parameters of the equivalent ellipse of contours or polygons treated as
  // point clouds.
  virtual HTuple EllipticAxisPointsXld(Halcon::HTuple *Rb, Halcon::HTuple *Phi) const;
  // Orientation of contours or polygons treated as point clouds.
  virtual HTuple OrientationPointsXld(void) const;
  // Geometric moments M20, M02, and M11
  // of contours or polygons treated as point clouds.
  virtual HTuple MomentsPointsXld(Halcon::HTuple *M20, Halcon::HTuple *M02) const;
  // Area and center of gravity (centroid) of contours and polygons
  // treated as point clouds.
  virtual HTuple AreaCenterPointsXld(Halcon::HTuple *Row, Halcon::HTuple *Column) const;
  // Test XLD contours or polygons for self intersection.
  virtual HTuple TestSelfIntersectionXld(const Halcon::HTuple &CloseXLD) const;
  // Test XLD contours or polygons for self intersection.
  virtual HTuple TestSelfIntersectionXld(const char *CloseXLD) const;
  // Choose all contours or polygons containing a given point.
  virtual HXLDArray SelectXldPoint(const Halcon::HTuple &Row, const Halcon::HTuple &Column) const;
  // Choose all contours or polygons containing a given point.
  virtual HXLDArray SelectXldPoint(double Row, double Column) const;
  // Test whether one or more contours or polygons enclose the given point(s).
  virtual HTuple TestXldPoint(const Halcon::HTuple &Row, const Halcon::HTuple &Column) const;
  // Test whether one or more contours or polygons enclose the given point(s).
  virtual HTuple TestXldPoint(double Row, double Column) const;
  // Select contours or polygons using shape features.
  virtual HXLDArray SelectShapeXld(const Halcon::HTuple &Features, const Halcon::HTuple &Operation, const Halcon::HTuple &Min, const Halcon::HTuple &Max) const;
  // Select contours or polygons using shape features.
  virtual HXLDArray SelectShapeXld(const char *Features, const char *Operation, double Min, double Max) const;
  // Orientation of contours or polygons.
  virtual HTuple OrientationXld(void) const;
  // Shape features derived from the ellipse parameters of contours or polygons.
  virtual HTuple EccentricityXld(Halcon::HTuple *Bulkiness, Halcon::HTuple *StructureFactor) const;
  // Shape factor for the compactness of contours or polygons.
  virtual HTuple CompactnessXld(void) const;
  // Maximum distance between two contour or polygon points.
  virtual HTuple DiameterXld(Halcon::HTuple *Column1, Halcon::HTuple *Row2, Halcon::HTuple *Column2, Halcon::HTuple *Diameter) const;
  // Shape factor for the convexity of contours or polygons.
  virtual HTuple ConvexityXld(void) const;
  // Shape factor for the circularity (similarity to a circle) of contours or
  // polygons.
  virtual HTuple CircularityXld(void) const;
  // Parameters of the equivalent ellipse of contours or polygons.
  virtual HTuple EllipticAxisXld(Halcon::HTuple *Rb, Halcon::HTuple *Phi) const;
  // Smallest enclosing rectangle with arbitrary orientation of contours or
  // polygons.
  virtual HTuple SmallestRectangle2Xld(Halcon::HTuple *Column, Halcon::HTuple *Phi, Halcon::HTuple *Length1, Halcon::HTuple *Length2) const;
  // Enclosing rectangle parallel to the coordinate axes of contours or polygons.
  virtual HTuple SmallestRectangle1Xld(Halcon::HTuple *Column1, Halcon::HTuple *Row2, Halcon::HTuple *Column2) const;
  // Smallest enclosing circle of contours or polygons.
  virtual HTuple SmallestCircleXld(Halcon::HTuple *Column, Halcon::HTuple *Radius) const;
  // Transform the shape of contours or polygons.
  virtual HXLDArray ShapeTransXld(const Halcon::HTuple &Type) const;
  // Transform the shape of contours or polygons.
  virtual HXLDArray ShapeTransXld(const char *Type) const;
  // Length of contours or polygons.
  virtual HTuple LengthXld(void) const;
  // Arbitrary geometric moments of contours or polygons.
  virtual HTuple MomentsAnyXld(const Halcon::HTuple &Mode, const Halcon::HTuple &PointOrder, const Halcon::HTuple &Area, const Halcon::HTuple &CenterRow, const Halcon::HTuple &CenterCol, const Halcon::HTuple &P, const Halcon::HTuple &Q) const;
  // Arbitrary geometric moments of contours or polygons.
  virtual HTuple MomentsAnyXld(const char *Mode, const char *PointOrder, double Area, double CenterRow, double CenterCol, Hlong P, Hlong Q) const;
  // Geometric moments M20, M02, and
  // M11 of contours or polygons.
  virtual HTuple MomentsXld(Halcon::HTuple *M20, Halcon::HTuple *M02) const;
  // Area and center of gravity (centroid) of contours and polygons.
  virtual HTuple AreaCenterXld(Halcon::HTuple *Row, Halcon::HTuple *Column, Halcon::HTuple *PointOrder) const;
  // Determine the 3D pose of a rectangle from its perspective 2D
  // projection
  virtual HTuple GetRectanglePose(const Halcon::HTuple &CameraParam, const Halcon::HTuple &Width, const Halcon::HTuple &Height, const Halcon::HTuple &WeightingMode, const Halcon::HTuple &ClippingFactor, Halcon::HTuple *CovPose, Halcon::HTuple *Error) const;
  // Determine the 3D pose of a circle from its perspective 2D projection.
  // 
  virtual HTuple GetCirclePose(const Halcon::HTuple &CameraParam, const Halcon::HTuple &Radius, const Halcon::HTuple &OutputType, Halcon::HTuple *Pose2) const;
};

}

#endif
