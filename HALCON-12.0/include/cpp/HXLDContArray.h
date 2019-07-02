/*****************************************************************************
 * HXLDContArray.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HXLDContArray
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef XLD_CONT_ARRAY_H
#define XLD_CONT_ARRAY_H


namespace Halcon {


/****************************************************************************/
/*                               HXLDContArray                              */
/****************************************************************************/

class LIntExport HXLDContArray: public HXLDArray {
public:
  HXLDContArray(void) : HXLDArray() {}
  HXLDContArray(Hkey *key, Hlong num);
  HXLDContArray(const Hobject &obj);
  HXLDContArray(const HXLDCont &cont);
  HXLDContArray(const HXLD &xld);
  HXLDContArray(const HXLDContArray &arr);
  HXLDContArray(const HXLDArray &arr);
  ~HXLDContArray(void) {}

  HXLDContArray &operator= (const HXLDContArray &arr);
  HXLDContArray &operator= (const HXLDArray &arr);

  // Tools
  virtual const char *HClassName(void) const;
  virtual const char *ClassName(void) const;
  virtual const char *InstClassName(void) const;
  virtual INT4        ClassDBID(void) const {return XLD_CONTOUR_ID;}
  virtual Hkey        Key(Hlong i) const {return array[i].Key();}
  virtual Hobject     ElemId(Hlong i) const {return array[i].Id();}

  // Access and Manipulation
  HXLDCont  const &operator[] (Hlong index) const;
  HXLDCont        &operator[] (Hlong index);
  HXLDContArray    operator() (Hlong min, Hlong max) const;
  HXLDContArray   &Append(const HXLDCont &cont);
  HXLDContArray   &Append(const HXLD &xld);
  HXLDContArray   &Append(const HXLDContArray &conts);
  HXLDContArray   &Append(const HXLDArray &xlds);
  virtual void     SetKeys(Hkey *key, Hlong num);
  virtual void SetKeys(Hkey *key, Hlong num, Herror *err);
  void             CopyHXLDContArray(const HXLDContArray &in);
  void             CopyHXLDArray(const HXLDArray &in);

private:
  void NewLength(Hlong new_num, Hlong old_num);

  // Class Functions

public:
  // Compute the union of cotangential contours.
  virtual HXLDContArray UnionCotangentialContoursXld(const Halcon::HTuple &FitClippingLength, const Halcon::HTuple &FitLength, const Halcon::HTuple &MaxTangAngle, const Halcon::HTuple &MaxDist, const Halcon::HTuple &MaxDistPerp, const Halcon::HTuple &MaxOverlap, const Halcon::HTuple &Mode) const;
  // Compute the union of cotangential contours.
  virtual HXLDContArray UnionCotangentialContoursXld(double FitClippingLength, double FitLength, double MaxTangAngle, double MaxDist, double MaxDistPerp, double MaxOverlap, const char *Mode) const;
  // Transform a contour in polar coordinates back to cartesian coordinates
  virtual HXLDContArray PolarTransContourXldInv(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleEnd, const Halcon::HTuple &RadiusStart, const Halcon::HTuple &RadiusEnd, const Halcon::HTuple &WidthIn, const Halcon::HTuple &HeightIn, const Halcon::HTuple &Width, const Halcon::HTuple &Height) const;
  // Transform a contour in polar coordinates back to cartesian coordinates
  virtual HXLDContArray PolarTransContourXldInv(double Row, double Column, double AngleStart, double AngleEnd, double RadiusStart, double RadiusEnd, Hlong WidthIn, Hlong HeightIn, Hlong Width, Hlong Height) const;
  // Transform a contour in an annular arc to polar coordinates.
  virtual HXLDContArray PolarTransContourXld(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleEnd, const Halcon::HTuple &RadiusStart, const Halcon::HTuple &RadiusEnd, const Halcon::HTuple &Width, const Halcon::HTuple &Height) const;
  // Transform a contour in an annular arc to polar coordinates.
  virtual HXLDContArray PolarTransContourXld(double Row, double Column, double AngleStart, double AngleEnd, double RadiusStart, double RadiusEnd, Hlong Width, Hlong Height) const;
  // Compute the union of closed contours.
  virtual HXLDContArray Union2ClosedContoursXld(const HXLDContArray &Contours2) const;
  // Compute the symmetric difference of closed contours.
  virtual HXLDContArray SymmDifferenceClosedContoursXld(const HXLDContArray &Contours2) const;
  // Compute the difference of closed contours.
  virtual HXLDContArray DifferenceClosedContoursXld(const HXLDContArray &Sub) const;
  // Intersect closed contours.
  virtual HXLDContArray IntersectionClosedContoursXld(const HXLDContArray &Contours2) const;
  // Compute the union of contours that belong to the same circle.
  virtual HXLDContArray UnionCocircularContoursXld(const Halcon::HTuple &MaxArcAngleDiff, const Halcon::HTuple &MaxArcOverlap, const Halcon::HTuple &MaxTangentAngle, const Halcon::HTuple &MaxDist, const Halcon::HTuple &MaxRadiusDiff, const Halcon::HTuple &MaxCenterDist, const Halcon::HTuple &MergeSmallContours, const Halcon::HTuple &Iterations) const;
  // Compute the union of contours that belong to the same circle.
  virtual HXLDContArray UnionCocircularContoursXld(double MaxArcAngleDiff, double MaxArcOverlap, double MaxTangentAngle, double MaxDist, double MaxRadiusDiff, double MaxCenterDist, const char *MergeSmallContours, Hlong Iterations) const;
  // Crop an XLD contour.
  virtual HXLDContArray CropContoursXld(const Halcon::HTuple &Row1, const Halcon::HTuple &Col1, const Halcon::HTuple &Row2, const Halcon::HTuple &Col2, const Halcon::HTuple &CloseContours) const;
  // Crop an XLD contour.
  virtual HXLDContArray CropContoursXld(double Row1, double Col1, double Row2, double Col2, const char *CloseContours) const;
  // Generate one XLD contour in the shape of a cross for each input point.
  static HXLDContArray GenCrossContourXld(const Halcon::HTuple &Row, const Halcon::HTuple &Col, const Halcon::HTuple &Size, const Halcon::HTuple &Angle);
  // Generate one XLD contour in the shape of a cross for each input point.
  static HXLDContArray GenCrossContourXld(double Row, double Col, double Size, double Angle);
  // Sort contours with respect to their relative position.
  virtual HXLDContArray SortContoursXld(const Halcon::HTuple &SortMode, const Halcon::HTuple &Order, const Halcon::HTuple &RowOrCol) const;
  // Sort contours with respect to their relative position.
  virtual HXLDContArray SortContoursXld(const char *SortMode, const char *Order, const char *RowOrCol) const;
  // Merge XLD contours from successive line scan images.
  virtual HXLDContArray MergeContLineScanXld(const HXLDContArray &PrevConts, HXLDContArray *PrevMergedConts, const Halcon::HTuple &ImageHeight, const Halcon::HTuple &Margin, const Halcon::HTuple &MergeBorder, const Halcon::HTuple &MaxImagesCont) const;
  // Merge XLD contours from successive line scan images.
  virtual HXLDContArray MergeContLineScanXld(const HXLDContArray &PrevConts, HXLDContArray *PrevMergedConts, Hlong ImageHeight, double Margin, const char *MergeBorder, Hlong MaxImagesCont) const;
  // Read XLD contours to a file in ARC/INFO generate format.
  static HXLDContArray ReadContourXldArcInfo(const Halcon::HTuple &FileName);
  // Read XLD contours to a file in ARC/INFO generate format.
  static HXLDContArray ReadContourXldArcInfo(const char *FileName);
  // Write XLD contours to a file in ARC/INFO generate format.
  virtual void WriteContourXldArcInfo(const Halcon::HTuple &FileName) const;
  // Write XLD contours to a file in ARC/INFO generate format.
  virtual void WriteContourXldArcInfo(const char *FileName) const;
  // Compute the parallel contour of an XLD contour.
  virtual HXLDContArray GenParallelContourXld(const Halcon::HTuple &Mode, const Halcon::HTuple &Distance) const;
  // Compute the parallel contour of an XLD contour.
  virtual HXLDContArray GenParallelContourXld(const char *Mode, double Distance) const;
  // Create an XLD contour in the shape of a rectangle.
  static HXLDContArray GenRectangle2ContourXld(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Phi, const Halcon::HTuple &Length1, const Halcon::HTuple &Length2);
  // Create an XLD contour in the shape of a rectangle.
  static HXLDContArray GenRectangle2ContourXld(double Row, double Column, double Phi, double Length1, double Length2);
  // Fit rectangles to XLD contours.
  virtual HTuple FitRectangle2ContourXld(const Halcon::HTuple &Algorithm, const Halcon::HTuple &MaxNumPoints, const Halcon::HTuple &MaxClosureDist, const Halcon::HTuple &ClippingEndPoints, const Halcon::HTuple &Iterations, const Halcon::HTuple &ClippingFactor, Halcon::HTuple *Column, Halcon::HTuple *Phi, Halcon::HTuple *Length1, Halcon::HTuple *Length2, Halcon::HTuple *PointOrder) const;
  // Fit rectangles to XLD contours.
  virtual HTuple FitRectangle2ContourXld(const char *Algorithm, Hlong MaxNumPoints, double MaxClosureDist, Hlong ClippingEndPoints, Hlong Iterations, double ClippingFactor, Halcon::HTuple *Column, Halcon::HTuple *Phi, Halcon::HTuple *Length1, Halcon::HTuple *Length2, Halcon::HTuple *PointOrder) const;
  // Segment XLD contour parts whose local attributes fulfill given 
  // conditions.
  virtual HXLDContArray SegmentContourAttribXld(const Halcon::HTuple &Attribute, const Halcon::HTuple &Operation, const Halcon::HTuple &Min, const Halcon::HTuple &Max) const;
  // Segment XLD contour parts whose local attributes fulfill given 
  // conditions.
  virtual HXLDContArray SegmentContourAttribXld(const char *Attribute, const char *Operation, double Min, double Max) const;
  // Segment XLD contours into line segments and circular or elliptic arcs.
  virtual HXLDContArray SegmentContoursXld(const Halcon::HTuple &Mode, const Halcon::HTuple &SmoothCont, const Halcon::HTuple &MaxLineDist1, const Halcon::HTuple &MaxLineDist2) const;
  // Segment XLD contours into line segments and circular or elliptic arcs.
  virtual HXLDContArray SegmentContoursXld(const char *Mode, Hlong SmoothCont, double MaxLineDist1, double MaxLineDist2) const;
  // Approximate XLD contours by circles.
  virtual HTuple FitCircleContourXld(const Halcon::HTuple &Algorithm, const Halcon::HTuple &MaxNumPoints, const Halcon::HTuple &MaxClosureDist, const Halcon::HTuple &ClippingEndPoints, const Halcon::HTuple &Iterations, const Halcon::HTuple &ClippingFactor, Halcon::HTuple *Column, Halcon::HTuple *Radius, Halcon::HTuple *StartPhi, Halcon::HTuple *EndPhi, Halcon::HTuple *PointOrder) const;
  // Approximate XLD contours by circles.
  virtual HTuple FitCircleContourXld(const char *Algorithm, Hlong MaxNumPoints, double MaxClosureDist, Hlong ClippingEndPoints, Hlong Iterations, double ClippingFactor, Halcon::HTuple *Column, Halcon::HTuple *Radius, Halcon::HTuple *StartPhi, Halcon::HTuple *EndPhi, Halcon::HTuple *PointOrder) const;
  // Approximate XLD contours by line segments.
  virtual HTuple FitLineContourXld(const Halcon::HTuple &Algorithm, const Halcon::HTuple &MaxNumPoints, const Halcon::HTuple &ClippingEndPoints, const Halcon::HTuple &Iterations, const Halcon::HTuple &ClippingFactor, Halcon::HTuple *ColBegin, Halcon::HTuple *RowEnd, Halcon::HTuple *ColEnd, Halcon::HTuple *Nr, Halcon::HTuple *Nc, Halcon::HTuple *Dist) const;
  // Approximate XLD contours by line segments.
  virtual HTuple FitLineContourXld(const char *Algorithm, Hlong MaxNumPoints, Hlong ClippingEndPoints, Hlong Iterations, double ClippingFactor, Halcon::HTuple *ColBegin, Halcon::HTuple *RowEnd, Halcon::HTuple *ColEnd, Halcon::HTuple *Nr, Halcon::HTuple *Nc, Halcon::HTuple *Dist) const;
  // Compute the distance of contours to an ellipse.
  virtual HTuple DistEllipseContourXld(const Halcon::HTuple &Mode, const Halcon::HTuple &MaxNumPoints, const Halcon::HTuple &ClippingEndPoints, const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Phi, const Halcon::HTuple &Radius1, const Halcon::HTuple &Radius2, Halcon::HTuple *MaxDist, Halcon::HTuple *AvgDist, Halcon::HTuple *SigmaDist) const;
  // Compute the distance of contours to an ellipse.
  virtual HTuple DistEllipseContourXld(const char *Mode, Hlong MaxNumPoints, Hlong ClippingEndPoints, double Row, double Column, double Phi, double Radius1, double Radius2, Halcon::HTuple *MaxDist, Halcon::HTuple *AvgDist, Halcon::HTuple *SigmaDist) const;
  // Approximate XLD contours by ellipses or elliptic arcs.
  virtual HTuple FitEllipseContourXld(const Halcon::HTuple &Algorithm, const Halcon::HTuple &MaxNumPoints, const Halcon::HTuple &MaxClosureDist, const Halcon::HTuple &ClippingEndPoints, const Halcon::HTuple &VossTabSize, const Halcon::HTuple &Iterations, const Halcon::HTuple &ClippingFactor, Halcon::HTuple *Column, Halcon::HTuple *Phi, Halcon::HTuple *Radius1, Halcon::HTuple *Radius2, Halcon::HTuple *StartPhi, Halcon::HTuple *EndPhi, Halcon::HTuple *PointOrder) const;
  // Approximate XLD contours by ellipses or elliptic arcs.
  virtual HTuple FitEllipseContourXld(const char *Algorithm, Hlong MaxNumPoints, double MaxClosureDist, Hlong ClippingEndPoints, Hlong VossTabSize, Hlong Iterations, double ClippingFactor, Halcon::HTuple *Column, Halcon::HTuple *Phi, Halcon::HTuple *Radius1, Halcon::HTuple *Radius2, Halcon::HTuple *StartPhi, Halcon::HTuple *EndPhi, Halcon::HTuple *PointOrder) const;
  // Create XLD contours corresponding to circles or circular arcs.
  static HXLDContArray GenCircleContourXld(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Radius, const Halcon::HTuple &StartPhi, const Halcon::HTuple &EndPhi, const Halcon::HTuple &PointOrder, const Halcon::HTuple &Resolution);
  // Create XLD contours corresponding to circles or circular arcs.
  static HXLDContArray GenCircleContourXld(double Row, double Column, double Radius, double StartPhi, double EndPhi, const char *PointOrder, double Resolution);
  // Create an XLD contour that corresponds to an elliptic arc.
  static HXLDContArray GenEllipseContourXld(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Phi, const Halcon::HTuple &Radius1, const Halcon::HTuple &Radius2, const Halcon::HTuple &StartPhi, const Halcon::HTuple &EndPhi, const Halcon::HTuple &PointOrder, const Halcon::HTuple &Resolution);
  // Create an XLD contour that corresponds to an elliptic arc.
  static HXLDContArray GenEllipseContourXld(double Row, double Column, double Phi, double Radius1, double Radius2, double StartPhi, double EndPhi, const char *PointOrder, double Resolution);
  // Add noise to XLD contours.
  virtual HXLDContArray AddNoiseWhiteContourXld(const Halcon::HTuple &NumRegrPoints, const Halcon::HTuple &Amp) const;
  // Add noise to XLD contours.
  virtual HXLDContArray AddNoiseWhiteContourXld(Hlong NumRegrPoints, double Amp) const;
  // Approximate XLD contours by polygons.
  virtual HXLDPolyArray GenPolygonsXld(const Halcon::HTuple &Type, const Halcon::HTuple &Alpha) const;
  // Approximate XLD contours by polygons.
  virtual HXLDPolyArray GenPolygonsXld(const char *Type, double Alpha) const;
  // Apply a projective transformation to an XLD contour.
  virtual HXLDContArray ProjectiveTransContourXld(const Halcon::HTuple &HomMat2D) const;
  // Apply an arbitrary affine 2D transformation to XLD contours.
  virtual HXLDContArray AffineTransContourXld(const Halcon::HTuple &HomMat2D) const;
  // Close an XLD contour.
  virtual HXLDContArray CloseContoursXld(void) const;
  // Clip the end points of an XLD contour.
  virtual HXLDContArray ClipEndPointsContoursXld(const Halcon::HTuple &Mode, const Halcon::HTuple &Length) const;
  // Clip the end points of an XLD contour.
  virtual HXLDContArray ClipEndPointsContoursXld(const char *Mode, double Length) const;
  // Clip an XLD contour.
  virtual HXLDContArray ClipContoursXld(const Halcon::HTuple &Row1, const Halcon::HTuple &Column1, const Halcon::HTuple &Row2, const Halcon::HTuple &Column2) const;
  // Clip an XLD contour.
  virtual HXLDContArray ClipContoursXld(Hlong Row1, Hlong Column1, Hlong Row2, Hlong Column2) const;
  // Select XLD contours with a local maximum of gray values.
  virtual HXLDContArray LocalMaxContoursXld(const HImage &Image, const Halcon::HTuple &MinPercent, const Halcon::HTuple &MinDiff, const Halcon::HTuple &Distance) const;
  // Select XLD contours with a local maximum of gray values.
  virtual HXLDContArray LocalMaxContoursXld(const HImage &Image, Hlong MinPercent, Hlong MinDiff, Hlong Distance) const;
  // Compute the union of neighboring straight contours that have a similar 
  // distance from a given line.
  virtual HXLDContArray UnionStraightContoursHistoXld(HXLDContArray *SelectedContours, const Halcon::HTuple &RefLineStartRow, const Halcon::HTuple &RefLineStartColumn, const Halcon::HTuple &RefLineEndRow, const Halcon::HTuple &RefLineEndColumn, const Halcon::HTuple &Width, const Halcon::HTuple &MaxWidth, const Halcon::HTuple &FilterSize, Halcon::HTuple *HistoValues) const;
  // Compute the union of neighboring straight contours that have a similar 
  // distance from a given line.
  virtual HXLDContArray UnionStraightContoursHistoXld(HXLDContArray *SelectedContours, Hlong RefLineStartRow, Hlong RefLineStartColumn, Hlong RefLineEndRow, Hlong RefLineEndColumn, Hlong Width, Hlong MaxWidth, Hlong FilterSize, Halcon::HTuple *HistoValues) const;
  // Compute the union of neighboring straight contours that have a similar 
  // direction.
  virtual HXLDContArray UnionStraightContoursXld(const Halcon::HTuple &MaxDist, const Halcon::HTuple &MaxDiff, const Halcon::HTuple &Percent, const Halcon::HTuple &Mode, const Halcon::HTuple &Iterations) const;
  // Compute the union of collinear contours 
  // (operator with extended functionality).
  virtual HXLDContArray UnionCollinearContoursExtXld(const Halcon::HTuple &MaxDistAbs, const Halcon::HTuple &MaxDistRel, const Halcon::HTuple &MaxShift, const Halcon::HTuple &MaxAngle, const Halcon::HTuple &MaxOverlap, const Halcon::HTuple &MaxRegrError, const Halcon::HTuple &MaxCosts, const Halcon::HTuple &WeightDist, const Halcon::HTuple &WeightShift, const Halcon::HTuple &WeightAngle, const Halcon::HTuple &WeightLink, const Halcon::HTuple &WeightRegr, const Halcon::HTuple &Mode) const;
  // Compute the union of collinear contours 
  // (operator with extended functionality).
  virtual HXLDContArray UnionCollinearContoursExtXld(double MaxDistAbs, double MaxDistRel, double MaxShift, double MaxAngle, double MaxOverlap, double MaxRegrError, double MaxCosts, double WeightDist, double WeightShift, double WeightAngle, double WeightLink, double WeightRegr, const char *Mode) const;
  // Unite approximately collinear contours.
  virtual HXLDContArray UnionCollinearContoursXld(const Halcon::HTuple &MaxDistAbs, const Halcon::HTuple &MaxDistRel, const Halcon::HTuple &MaxShift, const Halcon::HTuple &MaxAngle, const Halcon::HTuple &Mode) const;
  // Unite approximately collinear contours.
  virtual HXLDContArray UnionCollinearContoursXld(double MaxDistAbs, double MaxDistRel, double MaxShift, double MaxAngle, const char *Mode) const;
  // Compute the union of contours whose end points are close together.
  virtual HXLDContArray UnionAdjacentContoursXld(const Halcon::HTuple &MaxDistAbs, const Halcon::HTuple &MaxDistRel, const Halcon::HTuple &Mode) const;
  // Compute the union of contours whose end points are close together.
  virtual HXLDContArray UnionAdjacentContoursXld(double MaxDistAbs, double MaxDistRel, const char *Mode) const;
  // Select XLD contours according to several features.
  virtual HXLDContArray SelectContoursXld(const Halcon::HTuple &Feature, const Halcon::HTuple &Min1, const Halcon::HTuple &Max1, const Halcon::HTuple &Min2, const Halcon::HTuple &Max2) const;
  // Select XLD contours according to several features.
  virtual HXLDContArray SelectContoursXld(const char *Feature, double Min1, double Max1, double Min2, double Max2) const;
  // Return XLD contour parameters.
  virtual HTuple GetRegressParamsXld(Halcon::HTuple *Nx, Halcon::HTuple *Ny, Halcon::HTuple *Dist, Halcon::HTuple *Fpx, Halcon::HTuple *Fpy, Halcon::HTuple *Lpx, Halcon::HTuple *Lpy, Halcon::HTuple *Mean, Halcon::HTuple *Deviation) const;
  // Calculate the parameters of a regression line to an XLD contour.
  virtual HXLDContArray RegressContoursXld(const Halcon::HTuple &Mode, const Halcon::HTuple &Iterations) const;
  // Calculate the parameters of a regression line to an XLD contour.
  virtual HXLDContArray RegressContoursXld(const char *Mode, Hlong Iterations) const;
  // Smooth an XLD contour.
  virtual HXLDContArray SmoothContoursXld(const Halcon::HTuple &NumRegrPoints) const;
  // Smooth an XLD contour.
  virtual HXLDContArray SmoothContoursXld(Hlong NumRegrPoints) const;
  // Return the number of points in an XLD contour.
  virtual HTuple ContourPointNumXld(void) const;
  // Create a region from an XLD contour.
  virtual HRegionArray GenRegionContourXld(const Halcon::HTuple &Mode) const;
  // Create a region from an XLD contour.
  virtual HRegionArray GenRegionContourXld(const char *Mode) const;
  // Prepare a shape model for anisotropic scale invariant matching
  // from XLD contours.
  virtual HShapeModel CreateAnisoShapeModelXld(const Halcon::HTuple &NumLevels, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &AngleStep, const Halcon::HTuple &ScaleRMin, const Halcon::HTuple &ScaleRMax, const Halcon::HTuple &ScaleRStep, const Halcon::HTuple &ScaleCMin, const Halcon::HTuple &ScaleCMax, const Halcon::HTuple &ScaleCStep, const Halcon::HTuple &Optimization, const Halcon::HTuple &Metric, const Halcon::HTuple &MinContrast) const;
  // Prepare a shape model for anisotropic scale invariant matching
  // from XLD contours.
  virtual HShapeModel CreateAnisoShapeModelXld(Hlong NumLevels, double AngleStart, double AngleExtent, double AngleStep, double ScaleRMin, double ScaleRMax, double ScaleRStep, double ScaleCMin, double ScaleCMax, double ScaleCStep, const char *Optimization, const char *Metric, Hlong MinContrast) const;
  // Prepare a shape model for scale invariant matching from XLD contours.
  virtual HShapeModel CreateScaledShapeModelXld(const Halcon::HTuple &NumLevels, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &AngleStep, const Halcon::HTuple &ScaleMin, const Halcon::HTuple &ScaleMax, const Halcon::HTuple &ScaleStep, const Halcon::HTuple &Optimization, const Halcon::HTuple &Metric, const Halcon::HTuple &MinContrast) const;
  // Prepare a shape model for scale invariant matching from XLD contours.
  virtual HShapeModel CreateScaledShapeModelXld(Hlong NumLevels, double AngleStart, double AngleExtent, double AngleStep, double ScaleMin, double ScaleMax, double ScaleStep, const char *Optimization, const char *Metric, Hlong MinContrast) const;
  // Prepare a shape model for matching from XLD contours.
  virtual HShapeModel CreateShapeModelXld(const Halcon::HTuple &NumLevels, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &AngleStep, const Halcon::HTuple &Optimization, const Halcon::HTuple &Metric, const Halcon::HTuple &MinContrast) const;
  // Prepare a shape model for matching from XLD contours.
  virtual HShapeModel CreateShapeModelXld(Hlong NumLevels, double AngleStart, double AngleExtent, double AngleStep, const char *Optimization, const char *Metric, Hlong MinContrast) const;
  // Prepare a deformable model for local deformable matching from XLD contours.
  virtual HDeformableModel CreateLocalDeformableModelXld(const Halcon::HTuple &NumLevels, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &AngleStep, const Halcon::HTuple &ScaleRMin, const Halcon::HTuple &ScaleRMax, const Halcon::HTuple &ScaleRStep, const Halcon::HTuple &ScaleCMin, const Halcon::HTuple &ScaleCMax, const Halcon::HTuple &ScaleCStep, const Halcon::HTuple &Optimization, const Halcon::HTuple &Metric, const Halcon::HTuple &MinContrast, const Halcon::HTuple &ParamName, const Halcon::HTuple &ParamValue) const;
  // Prepare a deformable model for planar calibrated matching from XLD contours.
  virtual HDeformableModel CreatePlanarCalibDeformableModelXld(const Halcon::HTuple &CamParam, const Halcon::HTuple &ReferencePose, const Halcon::HTuple &NumLevels, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &AngleStep, const Halcon::HTuple &ScaleRMin, const Halcon::HTuple &ScaleRMax, const Halcon::HTuple &ScaleRStep, const Halcon::HTuple &ScaleCMin, const Halcon::HTuple &ScaleCMax, const Halcon::HTuple &ScaleCStep, const Halcon::HTuple &Optimization, const Halcon::HTuple &Metric, const Halcon::HTuple &MinContrast, const Halcon::HTuple &ParamName, const Halcon::HTuple &ParamValue) const;
  // Prepare a deformable model for planar uncalibrated matching
  // from XLD contours.
  virtual HDeformableModel CreatePlanarUncalibDeformableModelXld(const Halcon::HTuple &NumLevels, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &AngleStep, const Halcon::HTuple &ScaleRMin, const Halcon::HTuple &ScaleRMax, const Halcon::HTuple &ScaleRStep, const Halcon::HTuple &ScaleCMin, const Halcon::HTuple &ScaleCMax, const Halcon::HTuple &ScaleCStep, const Halcon::HTuple &Optimization, const Halcon::HTuple &Metric, const Halcon::HTuple &MinContrast, const Halcon::HTuple &ParamName, const Halcon::HTuple &ParamValue) const;
  // Calculate the pointwise distance from one contour to another.
  virtual HXLDContArray DistanceContoursXld(const HXLDContArray &ContourTo, const Halcon::HTuple &Mode) const;
  // Calculate the pointwise distance from one contour to another.
  virtual HXLDContArray DistanceContoursXld(const HXLDContArray &ContourTo, const char *Mode) const;
  // Calculate the minimum distance between two contours.
  virtual HTuple DistanceCcMin(const HXLDContArray &Contour2, const Halcon::HTuple &Mode) const;
  // Calculate the minimum distance between two contours.
  virtual HTuple DistanceCcMin(const HXLDContArray &Contour2, const char *Mode) const;
  // Calculate the distance between two contours.
  virtual HTuple DistanceCc(const HXLDContArray &Contour2, const Halcon::HTuple &Mode, Halcon::HTuple *DistanceMax) const;
  // Calculate the distance between two contours.
  virtual HTuple DistanceCc(const HXLDContArray &Contour2, const char *Mode, Halcon::HTuple *DistanceMax) const;
  // Read XLD contours from a DXF file.
  static HXLDContArray ReadContourXldDxf(const Halcon::HTuple &FileName, const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues, Halcon::HTuple *DxfStatus);
  // Read XLD contours from a DXF file.
  static HXLDContArray ReadContourXldDxf(const char *FileName, const char *GenParamNames, double GenParamValues, Halcon::HTuple *DxfStatus);
  // Write XLD contours to a file in DXF format.
  virtual void WriteContourXldDxf(const Halcon::HTuple &FileName) const;
  // Write XLD contours to a file in DXF format.
  virtual void WriteContourXldDxf(const char *FileName) const;
  // Calibrate the radial distortion.
  virtual HXLDContArray RadialDistortionSelfCalibration(const Halcon::HTuple &Width, const Halcon::HTuple &Height, const Halcon::HTuple &InlierThreshold, const Halcon::HTuple &RandSeed, const Halcon::HTuple &DistortionModel, const Halcon::HTuple &DistortionCenter, const Halcon::HTuple &PrincipalPointVar, Halcon::HTuple *CameraParam) const;
  // Calibrate the radial distortion.
  virtual HXLDContArray RadialDistortionSelfCalibration(Hlong Width, Hlong Height, double InlierThreshold, Hlong RandSeed, const char *DistortionModel, const char *DistortionCenter, double PrincipalPointVar, Halcon::HTuple *CameraParam) const;
  // Transform an XLD contour into the plane z=0 of a world coordinate system.
  virtual HXLDContArray ContourToWorldPlaneXld(const Halcon::HTuple &CameraParam, const Halcon::HTuple &WorldPose, const Halcon::HTuple &Scale) const;
  // Change the radial distortion of contours.
  virtual HXLDContArray ChangeRadialDistortionContoursXld(const Halcon::HTuple &CamParamIn, const Halcon::HTuple &CamParamOut) const;
};

}

#endif
