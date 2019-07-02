/*****************************************************************************
 * HRegion.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Types for regions
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */


#ifndef H_REGION_H
#define H_REGION_H

#include "HErrorDef.h"
#include "HConst.h"
#include "IPType.h"


namespace Halcon {


/****************************************************************************/
/*                               HRegion                                    */
/****************************************************************************/
class HRegionArray;
class LIntExport HRegion: public HAbstractRegion, public HObject {
  friend class HRegionArray;
public:
  HRegion(void): HObject(), rl(0) {}
  HRegion(Hkey key): HObject(key), rl(0) {}
  HRegion(const Hobject &obj);
  HRegion(const HDChord &line);
  HRegion(const HDPoint2D &point);
  HRegion(const HRectangle1 &obj);
  HRegion(const HRectangle2 &obj);
  HRegion(const HCircle &obj);
  HRegion(const HEllipse &obj);
  HRegion(const char *file);
  HRegion(const HAbstractRegion *base);
  HRegion(const HRegion &reg);
  HRegion(const HRegionArray &arr);
  ~HRegion(void) {}
  HRegion &operator = (const HRegion &reg);
  HRegion &operator = (const HRegionArray &arr);

  // Tools
  void                Transform(const HAffineTrans &transform, int mode);
  virtual       void  Display(const HWindow &w) const;
  virtual const char *HClassName(void) const;
  virtual const char *ClassName(void) const;
  virtual const char *InstClassName(void) const;
  virtual       INT4  ClassDBID(void) const {return REGION_ID;}
  virtual       void  CheckMyObjClass(void) const;
          HBool       Shared(void) const;

  Hrlregion *GetRL(void) const;

  // Infix Operations
  HRegion  operator * (double scale) const;
  HRegion  operator >> (double radius) const;
  HRegion &operator >>= (double radius);
  HRegion  operator << (double radius) const;
  HRegion &operator <<= (double radius);
  HRegion  operator + (const HDPoint2D &point) const;
  HRegion &operator += (const HDPoint2D &point);
  HRegion &operator ++ (void);
  HRegion  operator + (const HRegion &reg) const;
  HRegion &operator += (const HRegion &reg);
  HRegion  operator - (const HRegion &reg) const;
  HRegion &operator -= (const HRegion &reg);
  HRegion &operator -- (void);
  HRegion  operator ~ (void) const;
  HRegion  operator ! (void) const;
  HRegion  operator & (const HRegion &reg) const;
  HRegion &operator &= (const HRegion &reg);
  HRegion  operator | (const HRegion &reg) const;
  HRegion &operator |= (const HRegion &reg);
  HRegion  operator / (const HRegion &reg) const;
  HRegion &operator /= (const HRegion &reg);
  HBool     operator == (const HRegion &reg) const;
  HBool     operator >= (const HRegion &reg) const;
  HBool     operator > (const HRegion &reg) const;
  HBool     operator <= (const HRegion &reg) const;
  HBool     operator < (const HRegion &reg) const;

#ifdef WIN32EXTRA
  void*    operator new(size_t nSize);
  void     operator delete (void* p);
#endif
  double Phi(void) const;
  double Ra(void) const;
  double Rb(void) const;

  // Features
  double Anisometry(void) const;
  double Bulkiness(void) const;
  double StructureFactor(void) const;
  // Area
  Hlong Area(void) const;
  // Center
  double X(void) const {return Col();}
  double Y(void) const {return Row();}
  double Row(void) const;
  double Col(void) const;
  // Moments
  double M11(void) const;
  double M20(void) const;
  double M02(void) const;
  double Ia(void) const;
  double Ib(void) const;
  
  // Class Methods
  static Hlong NumData(void);

  HAbstractRegion  *CopyAbstractRegion(void) const;
  HAbstractRegion  *NewEmpty(void) const;
  HRectangle1      BoundingBox(void) const;
  HRectangle1      SmallestRectangle1(void) const;
  HBool            In(const HDPoint2D &p) const;
  void             Insert(const HDPoint2D &p);
  void             Delete(const HDPoint2D &p);
  HBool            IsEmpty(void) const;
  HAbstractRegion  *ToRLRegion(void) const;
  HAbstractRegion  *ToHRegion(void) const;

private:
  Hrlregion  *rl;
  void  setRLptr(void) const;

public:
  // Generate XLD contours from regions.
  virtual HXLDCont GenContourRegionXld(const Halcon::HTuple &Mode) const;
  // Generate XLD contours from regions.
  virtual HXLDCont GenContourRegionXld(const char *Mode) const;
  // Convert a skeleton into XLD contours.
  virtual HXLDContArray GenContoursSkeletonXld(const Halcon::HTuple &Length, const Halcon::HTuple &Mode) const;
  // Convert a skeleton into XLD contours.
  virtual HXLDContArray GenContoursSkeletonXld(Hlong Length, const char *Mode) const;
  // Receive regions over a socket connection.
  static HRegion ReceiveRegion(const Halcon::HSocket &Socket);
  // Send regions over a socket connection.
  virtual void SendRegion(const Halcon::HSocket &Socket) const;
  // Create a model to perform 3D-measurements using the sheet-of-light
  // technique.
  virtual HSheetOfLightModel CreateSheetOfLightModel(const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues) const;
  // Create a model to perform 3D-measurements using the sheet-of-light
  // technique.
  virtual HSheetOfLightModel CreateSheetOfLightModel(const char *GenParamNames, Hlong GenParamValues) const;
  // Selects characters from a given region.
  virtual HRegion SelectCharacters(const Halcon::HTuple &DotPrint, const Halcon::HTuple &StrokeWidth, const Halcon::HTuple &CharWidth, const Halcon::HTuple &CharHeight, const Halcon::HTuple &Punctuation, const Halcon::HTuple &DiacriticMarks, const Halcon::HTuple &PartitionMethod, const Halcon::HTuple &PartitionLines, const Halcon::HTuple &FragmentDistance, const Halcon::HTuple &ConnectFragments, const Halcon::HTuple &ClutterSizeMax, const Halcon::HTuple &StopAfter) const;
  // Segments characters in a given region of an image.
  virtual HImage SegmentCharacters(const HImage &Image, HRegion *RegionForeground, const Halcon::HTuple &Method, const Halcon::HTuple &EliminateLines, const Halcon::HTuple &DotPrint, const Halcon::HTuple &StrokeWidth, const Halcon::HTuple &CharWidth, const Halcon::HTuple &CharHeight, const Halcon::HTuple &ThresholdOffset, const Halcon::HTuple &Contrast, Hlong *UsedThreshold) const;
  // Determines the slant of characters of a text line or paragraph.
  virtual double TextLineSlant(const HImage &Image, const Halcon::HTuple &CharHeight, const Halcon::HTuple &SlantFrom, const Halcon::HTuple &SlantTo) const;
  // Determines the slant of characters of a text line or paragraph.
  virtual double TextLineSlant(const HImage &Image, Hlong CharHeight, double SlantFrom, double SlantTo) const;
  // Determines the orientation of a text line or paragraph.
  virtual double TextLineOrientation(const HImage &Image, const Halcon::HTuple &CharHeight, const Halcon::HTuple &OrientationFrom, const Halcon::HTuple &OrientationTo) const;
  // Determines the orientation of a text line or paragraph.
  virtual double TextLineOrientation(const HImage &Image, Hlong CharHeight, double OrientationFrom, double OrientationTo) const;
  // Construct classes for class_ndim_norm.
  virtual HTuple LearnNdimNorm(const HRegion &Background, const HImage &Image, const Halcon::HTuple &Metric, const Halcon::HTuple &Distance, const Halcon::HTuple &MinNumberPercent, Halcon::HTuple *Center, double *Quality) const;
  // Construct classes for class_ndim_norm.
  virtual HTuple LearnNdimNorm(const HRegion &Background, const HImage &Image, const char *Metric, double Distance, double MinNumberPercent, Halcon::HTuple *Center, double *Quality) const;
  // Construct classes for class_ndim_norm.
  virtual HTuple LearnNdimNorm(const HRegionArray &Background, const HImageArray &Image, const Halcon::HTuple &Metric, const Halcon::HTuple &Distance, const Halcon::HTuple &MinNumberPercent, Halcon::HTuple *Center, double *Quality) const;
  // Construct classes for class_ndim_norm.
  virtual HTuple LearnNdimNorm(const HRegionArray &Background, const HImageArray &Image, const char *Metric, double Distance, double MinNumberPercent, Halcon::HTuple *Center, double *Quality) const;
  // Train a classificator using a multi-channel image.
  virtual void LearnNdimBox(const HRegion &Background, const HImage &MultiChannelImage, const Halcon::HClassBox &ClassifHandle) const;
  // Train a classificator using a multi-channel image.
  virtual void LearnNdimBox(const HRegionArray &Background, const HImageArray &MultiChannelImage, const Halcon::HClassBox &ClassifHandle) const;
  // Transform a region in polar coordinates back to cartesian
  // coordinates.
  virtual HRegion PolarTransRegionInv(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleEnd, const Halcon::HTuple &RadiusStart, const Halcon::HTuple &RadiusEnd, const Halcon::HTuple &WidthIn, const Halcon::HTuple &HeightIn, const Halcon::HTuple &Width, const Halcon::HTuple &Height, const Halcon::HTuple &Interpolation) const;
  // Transform a region in polar coordinates back to cartesian
  // coordinates.
  virtual HRegion PolarTransRegionInv(double Row, double Column, double AngleStart, double AngleEnd, double RadiusStart, double RadiusEnd, Hlong WidthIn, Hlong HeightIn, Hlong Width, Hlong Height, const char *Interpolation) const;
  // Transform a region within an annular arc to polar coordinates.
  virtual HRegion PolarTransRegion(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleEnd, const Halcon::HTuple &RadiusStart, const Halcon::HTuple &RadiusEnd, const Halcon::HTuple &Width, const Halcon::HTuple &Height, const Halcon::HTuple &Interpolation) const;
  // Transform a region within an annular arc to polar coordinates.
  virtual HRegion PolarTransRegion(double Row, double Column, double AngleStart, double AngleEnd, double RadiusStart, double RadiusEnd, Hlong Width, Hlong Height, const char *Interpolation) const;
  // Merge regions from line scan images.
  virtual HRegion MergeRegionsLineScan(const HRegion &PrevRegions, HRegion *PrevMergedRegions, const Halcon::HTuple &ImageHeight, const Halcon::HTuple &MergeBorder, const Halcon::HTuple &MaxImagesRegion) const;
  // Merge regions from line scan images.
  virtual HRegion MergeRegionsLineScan(const HRegion &PrevRegions, HRegion *PrevMergedRegions, Hlong ImageHeight, const char *MergeBorder, Hlong MaxImagesRegion) const;
  // Merge regions from line scan images.
  virtual HRegion MergeRegionsLineScan(const HRegionArray &PrevRegions, HRegion *PrevMergedRegions, const Halcon::HTuple &ImageHeight, const Halcon::HTuple &MergeBorder, const Halcon::HTuple &MaxImagesRegion) const;
  // Merge regions from line scan images.
  virtual HRegion MergeRegionsLineScan(const HRegionArray &PrevRegions, HRegion *PrevMergedRegions, Hlong ImageHeight, const char *MergeBorder, Hlong MaxImagesRegion) const;
  // Partition a region into rectangles of approximately equal size.
  virtual HRegion PartitionRectangle(const Halcon::HTuple &Width, const Halcon::HTuple &Height) const;
  // Partition a region into rectangles of approximately equal size.
  virtual HRegion PartitionRectangle(double Width, double Height) const;
  // Partition a region horizontally at positions of small vertical extent.
  virtual HRegionArray PartitionDynamic(const Halcon::HTuple &Distance, const Halcon::HTuple &Percent) const;
  // Partition a region horizontally at positions of small vertical extent.
  virtual HRegionArray PartitionDynamic(double Distance, double Percent) const;
  // Convert regions to a label image.
  virtual HImage RegionToLabel(const Halcon::HTuple &Type, const Halcon::HTuple &Width, const Halcon::HTuple &Height) const;
  // Convert regions to a label image.
  virtual HImage RegionToLabel(const char *Type, Hlong Width, Hlong Height) const;
  // Convert a region into a binary byte-image.
  virtual HImage RegionToBin(const Halcon::HTuple &ForegroundGray, const Halcon::HTuple &BackgroundGray, const Halcon::HTuple &Width, const Halcon::HTuple &Height) const;
  // Convert a region into a binary byte-image.
  virtual HImage RegionToBin(Hlong ForegroundGray, Hlong BackgroundGray, Hlong Width, Hlong Height) const;
  // Return the union of two regions.
  virtual HRegion Union2(const HRegion &Region2) const;
  // Return the union of two regions.
  virtual HRegion Union2(const HRegionArray &Region2) const;
  // Compute the closest-point transformation of a region.
  virtual HImage ClosestPointTransform(HImage *ClosestPoints, const Halcon::HTuple &Metric, const Halcon::HTuple &Foreground, const Halcon::HTuple &ClosestPointMode, const Halcon::HTuple &Width, const Halcon::HTuple &Height) const;
  // Compute the closest-point transformation of a region.
  virtual HImage ClosestPointTransform(HImage *ClosestPoints, const char *Metric, const char *Foreground, const char *ClosestPointMode, Hlong Width, Hlong Height) const;
  // Compute the distance transformation of a region.
  virtual HImage DistanceTransform(const Halcon::HTuple &Metric, const Halcon::HTuple &Foreground, const Halcon::HTuple &Width, const Halcon::HTuple &Height) const;
  // Compute the distance transformation of a region.
  virtual HImage DistanceTransform(const char *Metric, const char *Foreground, Hlong Width, Hlong Height) const;
  // Compute the skeleton of a region.
  virtual HRegion Skeleton(void) const;
  // Apply a projective transformation to a region.
  virtual HRegion ProjectiveTransRegion(const Halcon::HTuple &HomMat2D, const Halcon::HTuple &Interpolation) const;
  // Apply an arbitrary affine 2D transformation to regions.
  virtual HRegion AffineTransRegion(const Halcon::HTuple &HomMat2D, const Halcon::HTuple &Interpolate) const;
  // Reflect a region about an axis.
  virtual HRegion MirrorRegion(const Halcon::HTuple &Mode, const Halcon::HTuple &WidthHeight) const;
  // Reflect a region about an axis.
  virtual HRegion MirrorRegion(const char *Mode, Hlong WidthHeight) const;
  // Zoom a region.
  virtual HRegion ZoomRegion(const Halcon::HTuple &ScaleWidth, const Halcon::HTuple &ScaleHeight) const;
  // Zoom a region.
  virtual HRegion ZoomRegion(double ScaleWidth, double ScaleHeight) const;
  // Translate a region.
  virtual HRegion MoveRegion(const Halcon::HTuple &Row, const Halcon::HTuple &Column) const;
  // Translate a region.
  virtual HRegion MoveRegion(Hlong Row, Hlong Column) const;
  // Find junctions and end points in a skeleton.
  virtual HRegion JunctionsSkeleton(HRegion *JuncPoints) const;
  // Calculate the intersection of two regions.
  virtual HRegion Intersection(const HRegion &Region2) const;
  // Calculate the intersection of two regions.
  virtual HRegion Intersection(const HRegionArray &Region2) const;
  // Partition the image plane using given regions.
  virtual HRegion Interjacent(const Halcon::HTuple &Mode) const;
  // Partition the image plane using given regions.
  virtual HRegion Interjacent(const char *Mode) const;
  // Fill up holes in regions.
  virtual HRegion FillUp(void) const;
  // Fill up holes in regions having given shape features.
  virtual HRegion FillUpShape(const Halcon::HTuple &Feature, const Halcon::HTuple &Min, const Halcon::HTuple &Max) const;
  // Fill up holes in regions having given shape features.
  virtual HRegion FillUpShape(const char *Feature, double Min, double Max) const;
  // Fill gaps between regions or split overlapping regions.
  virtual HRegion ExpandRegion(const HRegion &ForbiddenArea, const Halcon::HTuple &Iterations, const Halcon::HTuple &Mode) const;
  // Fill gaps between regions or split overlapping regions.
  virtual HRegion ExpandRegion(const HRegion &ForbiddenArea, Hlong Iterations, const char *Mode) const;
  // Clip a region relative to its smallest surrounding rectangle.
  virtual HRegion ClipRegionRel(const Halcon::HTuple &Top, const Halcon::HTuple &Bottom, const Halcon::HTuple &Left, const Halcon::HTuple &Right) const;
  // Clip a region relative to its smallest surrounding rectangle.
  virtual HRegion ClipRegionRel(Hlong Top, Hlong Bottom, Hlong Left, Hlong Right) const;
  // Clip a region to a rectangle.
  virtual HRegion ClipRegion(const Halcon::HTuple &Row1, const Halcon::HTuple &Column1, const Halcon::HTuple &Row2, const Halcon::HTuple &Column2) const;
  // Clip a region to a rectangle.
  virtual HRegion ClipRegion(Hlong Row1, Hlong Column1, Hlong Row2, Hlong Column2) const;
  // Rank operator for regions.
  virtual HRegion RankRegion(const Halcon::HTuple &Width, const Halcon::HTuple &Height, const Halcon::HTuple &Number) const;
  // Rank operator for regions.
  virtual HRegion RankRegion(Hlong Width, Hlong Height, Hlong Number) const;
  // Compute connected components of a region.
  virtual HRegionArray Connection(void) const;
  // Calculate the symmetric difference of two regions.
  virtual HRegion SymmDifference(const HRegion &Region2) const;
  // Calculate the symmetric difference of two regions.
  virtual HRegion SymmDifference(const HRegionArray &Region2) const;
  // Calculate the difference of two regions.
  virtual HRegion Difference(const HRegion &Sub) const;
  // Calculate the difference of two regions.
  virtual HRegion Difference(const HRegionArray &Sub) const;
  // Return the complement of a region.
  virtual HRegion Complement(void) const;
  // Determine the connected components of the background of given regions.
  virtual HRegionArray BackgroundSeg(void) const;
  // Generate a region having a given Hamming distance.
  virtual HRegion HammingChangeRegion(const Halcon::HTuple &Width, const Halcon::HTuple &Height, const Halcon::HTuple &Distance) const;
  // Generate a region having a given Hamming distance.
  virtual HRegion HammingChangeRegion(Hlong Width, Hlong Height, Hlong Distance) const;
  // Remove noise from a region.
  virtual HRegion RemoveNoiseRegion(const Halcon::HTuple &Type) const;
  // Remove noise from a region.
  virtual HRegion RemoveNoiseRegion(const char *Type) const;
  // Transform the shape of a region.
  virtual HRegion ShapeTrans(const Halcon::HTuple &Type) const;
  // Transform the shape of a region.
  virtual HRegion ShapeTrans(const char *Type) const;
  // Fill gaps between regions (depending on gray value or color) or split
  // overlapping regions.
  virtual HRegion ExpandGray(const HImage &Image, const HRegion &ForbiddenArea, const Halcon::HTuple &Iterations, const Halcon::HTuple &Mode, const Halcon::HTuple &Threshold) const;
  // Fill gaps between regions (depending on gray value or color) or split
  // overlapping regions.
  virtual HRegion ExpandGrayRef(const HImage &Image, const HRegion &ForbiddenArea, const Halcon::HTuple &Iterations, const Halcon::HTuple &Mode, const Halcon::HTuple &RefGray, const Halcon::HTuple &Threshold) const;
  // Split lines represented by one pixel wide, non-branching regions.
  virtual HRegionArray SplitSkeletonRegion(const Halcon::HTuple &MaxDistance) const;
  // Split lines represented by one pixel wide, non-branching regions.
  virtual HRegionArray SplitSkeletonRegion(Hlong MaxDistance) const;
  // Convert a histogram into a region.
  static HRegion GenRegionHisto(const Halcon::HTuple &Histogram, const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Scale);
  // Eliminate runs of a given length.
  virtual HRegion EliminateRuns(const Halcon::HTuple &ElimShorter, const Halcon::HTuple &ElimLonger) const;
  // Eliminate runs of a given length.
  virtual HRegion EliminateRuns(Hlong ElimShorter, Hlong ElimLonger) const;
  // Paint regions into an image.
  virtual HImage PaintRegion(const HImage &Image, const Halcon::HTuple &Grayval, const Halcon::HTuple &Type) const;
  // Paint regions into an image.
  virtual HImage PaintRegion(const HImage &Image, double Grayval, const char *Type) const;
  // Test whether a region is contained in another region.
  virtual Hlong TestSubsetRegion(const HRegion &Region2) const;
  // Test whether a region is contained in another region.
  virtual Hlong TestSubsetRegion(const HRegionArray &Region2) const;
  // Test whether the regions of two objects are identical.
  virtual Hlong TestEqualRegion(const HRegion &Regions2) const;
  // Test whether the regions of two objects are identical.
  virtual Hlong TestEqualRegion(const HRegionArray &Regions2) const;
  // Store a polygon as a "filled" region.
  static HRegion GenRegionPolygonFilled(const Halcon::HTuple &Rows, const Halcon::HTuple &Columns);
  // Store a polygon as a region.
  static HRegion GenRegionPolygon(const Halcon::HTuple &Rows, const Halcon::HTuple &Columns);
  // Store individual pixels as image region.
  static HRegion GenRegionPoints(const Halcon::HTuple &Rows, const Halcon::HTuple &Columns);
  // Store individual pixels as image region.
  static HRegion GenRegionPoints(Hlong Rows, Hlong Columns);
  // Create a region from a runlength coding.
  static HRegion GenRegionRuns(const Halcon::HTuple &Row, const Halcon::HTuple &ColumnBegin, const Halcon::HTuple &ColumnEnd);
  // Create a region from a runlength coding.
  static HRegion GenRegionRuns(Hlong Row, Hlong ColumnBegin, Hlong ColumnEnd);
  // Create a rectangle of any orientation.
  static HRegion GenRectangle2(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Phi, const Halcon::HTuple &Length1, const Halcon::HTuple &Length2);
  // Create a rectangle of any orientation.
  static HRegion GenRectangle2(double Row, double Column, double Phi, double Length1, double Length2);
  // Create a rectangle parallel to the coordinate axes.
  static HRegion GenRectangle1(const Halcon::HTuple &Row1, const Halcon::HTuple &Column1, const Halcon::HTuple &Row2, const Halcon::HTuple &Column2);
  // Create a rectangle parallel to the coordinate axes.
  static HRegion GenRectangle1(double Row1, double Column1, double Row2, double Column2);
  // Create a random region.
  static HRegion GenRandomRegion(const Halcon::HTuple &Width, const Halcon::HTuple &Height);
  // Create a random region.
  static HRegion GenRandomRegion(Hlong Width, Hlong Height);
  // Create an ellipse sector.
  static HRegion GenEllipseSector(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Phi, const Halcon::HTuple &Radius1, const Halcon::HTuple &Radius2, const Halcon::HTuple &StartAngle, const Halcon::HTuple &EndAngle);
  // Create an ellipse sector.
  static HRegion GenEllipseSector(double Row, double Column, double Phi, double Radius1, double Radius2, double StartAngle, double EndAngle);
  // Create an ellipse.
  static HRegion GenEllipse(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Phi, const Halcon::HTuple &Radius1, const Halcon::HTuple &Radius2);
  // Create an ellipse.
  static HRegion GenEllipse(double Row, double Column, double Phi, double Radius1, double Radius2);
  // Create a circle sector.
  static HRegion GenCircleSector(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Radius, const Halcon::HTuple &StartAngle, const Halcon::HTuple &EndAngle);
  // Create a circle sector.
  static HRegion GenCircleSector(double Row, double Column, double Radius, double StartAngle, double EndAngle);
  // Create a circle.
  static HRegion GenCircle(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Radius);
  // Create a circle.
  static HRegion GenCircle(double Row, double Column, double Radius);
  // Create a checkered region.
  static HRegion GenCheckerRegion(const Halcon::HTuple &WidthRegion, const Halcon::HTuple &HeightRegion, const Halcon::HTuple &WidthPattern, const Halcon::HTuple &HeightPattern);
  // Create a checkered region.
  static HRegion GenCheckerRegion(Hlong WidthRegion, Hlong HeightRegion, Hlong WidthPattern, Hlong HeightPattern);
  // Create a region from lines or pixels.
  static HRegion GenGridRegion(const Halcon::HTuple &RowSteps, const Halcon::HTuple &ColumnSteps, const Halcon::HTuple &Type, const Halcon::HTuple &Width, const Halcon::HTuple &Height);
  // Create a region from lines or pixels.
  static HRegion GenGridRegion(Hlong RowSteps, Hlong ColumnSteps, const char *Type, Hlong Width, Hlong Height);
  // Store input lines described in Hesse normal form as regions.
  static HRegion GenRegionHline(const Halcon::HTuple &Orientation, const Halcon::HTuple &Distance);
  // Store input lines described in Hesse normal form as regions.
  static HRegion GenRegionHline(double Orientation, double Distance);
  // Store input lines as regions.
  static HRegion GenRegionLine(const Halcon::HTuple &BeginRow, const Halcon::HTuple &BeginCol, const Halcon::HTuple &EndRow, const Halcon::HTuple &EndCol);
  // Store input lines as regions.
  static HRegion GenRegionLine(Hlong BeginRow, Hlong BeginCol, Hlong EndRow, Hlong EndCol);
  // Create an empty region.
  static HRegion GenEmptyRegion();
  // Access the thickness of a region along the main axis.
  virtual HTuple GetRegionThickness(Halcon::HTuple *Histogramm) const;
  // Polygon approximation of a region.
  virtual HTuple GetRegionPolygon(const Halcon::HTuple &Tolerance, Halcon::HTuple *Columns) const;
  // Polygon approximation of a region.
  virtual HTuple GetRegionPolygon(double Tolerance, Halcon::HTuple *Columns) const;
  // Access the pixels of a region.
  virtual HTuple GetRegionPoints(Halcon::HTuple *Columns) const;
  // Access the contour of an object.
  virtual HTuple GetRegionContour(Halcon::HTuple *Columns) const;
  // Access the runlength coding of a region.
  virtual HTuple GetRegionRuns(Halcon::HTuple *ColumnBegin, Halcon::HTuple *ColumnEnd) const;
  // Contour of an object as chain code.
  virtual Hlong GetRegionChain(Halcon::HTuple *Column, Halcon::HTuple *Chain) const;
  // Access convex hull as contour.
  virtual HTuple GetRegionConvex(Halcon::HTuple *Columns) const;
  // Classify a related group of characters with an OCR classifier.
  virtual HTuple DoOcrWordKnn(const HImage &Image, const Halcon::HOCRKnn &OCRHandle, const Halcon::HTuple &Expression, const Halcon::HTuple &NumAlternatives, const Halcon::HTuple &NumCorrections, double *Confidence, char *Word, double *Score) const;
  // Classify a related group of characters with an OCR classifier.
  virtual HTuple DoOcrWordKnn(const HImage &Image, const Halcon::HOCRKnn &OCRHandle, const char *Expression, Hlong NumAlternatives, Hlong NumCorrections, double *Confidence, char *Word, double *Score) const;
  // Classify multiple characters with an k-NN classifier.
  virtual HTuple DoOcrMultiClassKnn(const HImage &Image, const Halcon::HOCRKnn &OCRHandle, double *Confidence) const;
  // Classify a single character with an OCR classifier.
  virtual HTuple DoOcrSingleClassKnn(const HImage &Image, const Halcon::HOCRKnn &OCRHandle, const Halcon::HTuple &NumClasses, const Halcon::HTuple &NumNeighbors, Halcon::HTuple *Confidence) const;
  // Classify a related group of characters with an OCR classifier.
  virtual HTuple DoOcrWordSvm(const HImage &Image, const Halcon::HOCRSvm &OCRHandle, const Halcon::HTuple &Expression, const Halcon::HTuple &NumAlternatives, const Halcon::HTuple &NumCorrections, char *Word, double *Score) const;
  // Classify a related group of characters with an OCR classifier.
  virtual HTuple DoOcrWordSvm(const HImage &Image, const Halcon::HOCRSvm &OCRHandle, const char *Expression, Hlong NumAlternatives, Hlong NumCorrections, char *Word, double *Score) const;
  // Classify multiple characters with an SVM-based OCR classifier.
  virtual HTuple DoOcrMultiClassSvm(const HImage &Image, const Halcon::HOCRSvm &OCRHandle) const;
  // Classify a single character with an SVM-based OCR classifier.
  virtual HTuple DoOcrSingleClassSvm(const HImage &Image, const Halcon::HOCRSvm &OCRHandle, const Halcon::HTuple &Num) const;
  // Classify a related group of characters with an OCR classifier.
  virtual HTuple DoOcrWordMlp(const HImage &Image, const Halcon::HOCRMlp &OCRHandle, const Halcon::HTuple &Expression, const Halcon::HTuple &NumAlternatives, const Halcon::HTuple &NumCorrections, double *Confidence, char *Word, double *Score) const;
  // Classify a related group of characters with an OCR classifier.
  virtual HTuple DoOcrWordMlp(const HImage &Image, const Halcon::HOCRMlp &OCRHandle, const char *Expression, Hlong NumAlternatives, Hlong NumCorrections, double *Confidence, char *Word, double *Score) const;
  // Classify multiple characters with an OCR classifier.
  virtual HTuple DoOcrMultiClassMlp(const HImage &Image, const Halcon::HOCRMlp &OCRHandle, double *Confidence) const;
  // Classify a single character with an OCR classifier.
  virtual HTuple DoOcrSingleClassMlp(const HImage &Image, const Halcon::HOCRMlp &OCRHandle, const Halcon::HTuple &Num, Halcon::HTuple *Confidence) const;
  // Classify one character.
  virtual HTuple DoOcrSingle(const HImage &Image, const Halcon::HOCRBox &OcrHandle, Halcon::HTuple *Confidences) const;
  // Classify characters.
  virtual HTuple DoOcrMulti(const HImage &Image, const Halcon::HOCRBox &OcrHandle, double *Confidence) const;
  // Train an OCR classifier by the input of regions.
  virtual double TraindOcrClassBox(const HImage &Image, const Halcon::HOCRBox &OcrHandle, const Halcon::HTuple &Class) const;
  // Train an OCR classifier by the input of regions.
  virtual double TraindOcrClassBox(const HImage &Image, const Halcon::HOCRBox &OcrHandle, const char *Class) const;
  // Storing of training characters into a file.
  virtual void WriteOcrTrainf(const HImage &Image, const Halcon::HTuple &Class, const Halcon::HTuple &TrainingFile) const;
  // Storing of training characters into a file.
  virtual void WriteOcrTrainf(const HImage &Image, const char *Class, const char *TrainingFile) const;
  // Test an OCR classifier.
  virtual double TestdOcrClassBox(const HImage &Image, const Halcon::HOCRBox &OcrHandle, const Halcon::HTuple &Class) const;
  // Test an OCR classifier.
  virtual double TestdOcrClassBox(const HImage &Image, const Halcon::HOCRBox &OcrHandle, const char *Class) const;
  // Add characters to a training file.
  virtual void AppendOcrTrainf(const HImage &Image, const Halcon::HTuple &Class, const Halcon::HTuple &TrainingFile) const;
  // Add characters to a training file.
  virtual void AppendOcrTrainf(const HImage &Image, const char *Class, const char *TrainingFile) const;
  // Prune the branches of a region.
  virtual HRegion Pruning(const Halcon::HTuple &Length) const;
  // Prune the branches of a region.
  virtual HRegion Pruning(Hlong Length) const;
  // Reduce a region to its boundary.
  virtual HRegion Boundary(const Halcon::HTuple &BoundaryType) const;
  // Reduce a region to its boundary.
  virtual HRegion Boundary(const char *BoundaryType) const;
  // Perform a closing after an opening with multiple structuring elements.
  virtual HRegion Fitting(const HRegion &StructElements) const;
  // Perform a closing after an opening with multiple structuring elements.
  virtual HRegion Fitting(const HRegionArray &StructElements) const;
  // Generate standard structuring elements.
  static HRegion GenStructElements(const Halcon::HTuple &Type, const Halcon::HTuple &Row, const Halcon::HTuple &Column);
  // Generate standard structuring elements.
  static HRegion GenStructElements(const char *Type, Hlong Row, Hlong Column);
  // Reflect a region about a point.
  virtual HRegion TransposeRegion(const Halcon::HTuple &Row, const Halcon::HTuple &Column) const;
  // Reflect a region about a point.
  virtual HRegion TransposeRegion(Hlong Row, Hlong Column) const;
  // Remove the result of a hit-or-miss operation from a region (sequential).
  virtual HRegion ThinningSeq(const Halcon::HTuple &GolayElement, const Halcon::HTuple &Iterations) const;
  // Remove the result of a hit-or-miss operation from a region (sequential).
  virtual HRegion ThinningSeq(const char *GolayElement, Hlong Iterations) const;
  // Remove the result of a hit-or-miss operation from a region (using a
  // Golay structuring element).
  virtual HRegion ThinningGolay(const Halcon::HTuple &GolayElement, const Halcon::HTuple &Rotation) const;
  // Remove the result of a hit-or-miss operation from a region (using a
  // Golay structuring element).
  virtual HRegion ThinningGolay(const char *GolayElement, Hlong Rotation) const;
  // Remove the result of a hit-or-miss operation from a region.
  virtual HRegion Thinning(const HRegion &StructElement1, const HRegion &StructElement2, const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Iterations) const;
  // Remove the result of a hit-or-miss operation from a region.
  virtual HRegion Thinning(const HRegion &StructElement1, const HRegion &StructElement2, Hlong Row, Hlong Column, Hlong Iterations) const;
  // Add the result of a hit-or-miss operation to a region (sequential).
  virtual HRegion ThickeningSeq(const Halcon::HTuple &GolayElement, const Halcon::HTuple &Iterations) const;
  // Add the result of a hit-or-miss operation to a region (sequential).
  virtual HRegion ThickeningSeq(const char *GolayElement, Hlong Iterations) const;
  // Add the result of a hit-or-miss operation to a region (using a Golay
  // structuring element).
  virtual HRegion ThickeningGolay(const Halcon::HTuple &GolayElement, const Halcon::HTuple &Rotation) const;
  // Add the result of a hit-or-miss operation to a region (using a Golay
  // structuring element).
  virtual HRegion ThickeningGolay(const char *GolayElement, Hlong Rotation) const;
  // Add the result of a hit-or-miss operation to a region.
  virtual HRegion Thickening(const HRegion &StructElement1, const HRegion &StructElement2, const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Iterations) const;
  // Add the result of a hit-or-miss operation to a region.
  virtual HRegion Thickening(const HRegion &StructElement1, const HRegion &StructElement2, Hlong Row, Hlong Column, Hlong Iterations) const;
  // Hit-or-miss operation for regions using the Golay alphabet (sequential).
  virtual HRegion HitOrMissSeq(const Halcon::HTuple &GolayElement) const;
  // Hit-or-miss operation for regions using the Golay alphabet (sequential).
  virtual HRegion HitOrMissSeq(const char *GolayElement) const;
  // Hit-or-miss operation for regions using the Golay alphabet.
  virtual HRegion HitOrMissGolay(const Halcon::HTuple &GolayElement, const Halcon::HTuple &Rotation) const;
  // Hit-or-miss operation for regions using the Golay alphabet.
  virtual HRegion HitOrMissGolay(const char *GolayElement, Hlong Rotation) const;
  // Hit-or-miss operation for regions.
  virtual HRegion HitOrMiss(const HRegion &StructElement1, const HRegion &StructElement2, const Halcon::HTuple &Row, const Halcon::HTuple &Column) const;
  // Hit-or-miss operation for regions.
  virtual HRegion HitOrMiss(const HRegion &StructElement1, const HRegion &StructElement2, Hlong Row, Hlong Column) const;
  // Generate the structuring elements of the Golay alphabet.
  static HRegion GolayElements(HRegion *StructElement2, const Halcon::HTuple &GolayElement, const Halcon::HTuple &Rotation, const Halcon::HTuple &Row, const Halcon::HTuple &Column);
  // Generate the structuring elements of the Golay alphabet.
  static HRegion GolayElements(HRegion *StructElement2, const char *GolayElement, Hlong Rotation, Hlong Row, Hlong Column);
  // Thinning of a region.
  virtual HRegion MorphSkiz(const Halcon::HTuple &Iterations1, const Halcon::HTuple &Iterations2) const;
  // Thinning of a region.
  virtual HRegion MorphSkiz(Hlong Iterations1, Hlong Iterations2) const;
  // Compute the morphological skeleton of a region.
  virtual HRegion MorphSkeleton(void) const;
  // Compute the union of bottom_hat and top_hat.
  virtual HRegion MorphHat(const HRegion &StructElement) const;
  // Compute the bottom hat of regions.
  virtual HRegion BottomHat(const HRegion &StructElement) const;
  // Compute the top hat of regions.
  virtual HRegion TopHat(const HRegion &StructElement) const;
  // Erode a region (using a reference point).
  virtual HRegion MinkowskiSub2(const HRegion &StructElement, const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Iterations) const;
  // Erode a region (using a reference point).
  virtual HRegion MinkowskiSub2(const HRegion &StructElement, Hlong Row, Hlong Column, Hlong Iterations) const;
  // Erode a region.
  virtual HRegion MinkowskiSub1(const HRegion &StructElement, const Halcon::HTuple &Iterations) const;
  // Erode a region.
  virtual HRegion MinkowskiSub1(const HRegion &StructElement, Hlong Iterations) const;
  // Dilate a region (using a reference point).
  virtual HRegion MinkowskiAdd2(const HRegion &StructElement, const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Iterations) const;
  // Dilate a region (using a reference point).
  virtual HRegion MinkowskiAdd2(const HRegion &StructElement, Hlong Row, Hlong Column, Hlong Iterations) const;
  // Perform a Minkowski addition on a region.
  virtual HRegion MinkowskiAdd1(const HRegion &StructElement, const Halcon::HTuple &Iterations) const;
  // Perform a Minkowski addition on a region.
  virtual HRegion MinkowskiAdd1(const HRegion &StructElement, Hlong Iterations) const;
  // Close a region with a rectangular structuring element.
  virtual HRegion ClosingRectangle1(const Halcon::HTuple &Width, const Halcon::HTuple &Height) const;
  // Close a region with a rectangular structuring element.
  virtual HRegion ClosingRectangle1(Hlong Width, Hlong Height) const;
  // Close a region with an element from the Golay alphabet.
  virtual HRegion ClosingGolay(const Halcon::HTuple &GolayElement, const Halcon::HTuple &Rotation) const;
  // Close a region with an element from the Golay alphabet.
  virtual HRegion ClosingGolay(const char *GolayElement, Hlong Rotation) const;
  // Close a region with a circular structuring element.
  virtual HRegion ClosingCircle(const Halcon::HTuple &Radius) const;
  // Close a region with a circular structuring element.
  virtual HRegion ClosingCircle(double Radius) const;
  // Close a region.
  virtual HRegion Closing(const HRegion &StructElement) const;
  // Separate overlapping regions.
  virtual HRegionArray OpeningSeg(const HRegion &StructElement) const;
  // Open a region with an element from the Golay alphabet.
  virtual HRegion OpeningGolay(const Halcon::HTuple &GolayElement, const Halcon::HTuple &Rotation) const;
  // Open a region with an element from the Golay alphabet.
  virtual HRegion OpeningGolay(const char *GolayElement, Hlong Rotation) const;
  // Open a region with a rectangular structuring element.
  virtual HRegion OpeningRectangle1(const Halcon::HTuple &Width, const Halcon::HTuple &Height) const;
  // Open a region with a rectangular structuring element.
  virtual HRegion OpeningRectangle1(Hlong Width, Hlong Height) const;
  // Open a region with a circular structuring element.
  virtual HRegion OpeningCircle(const Halcon::HTuple &Radius) const;
  // Open a region with a circular structuring element.
  virtual HRegion OpeningCircle(double Radius) const;
  // Open a region.
  virtual HRegion Opening(const HRegion &StructElement) const;
  // Erode a region sequentially.
  virtual HRegion ErosionSeq(const Halcon::HTuple &GolayElement, const Halcon::HTuple &Iterations) const;
  // Erode a region sequentially.
  virtual HRegion ErosionSeq(const char *GolayElement, Hlong Iterations) const;
  // Erode a region with an element from the Golay alphabet.
  virtual HRegion ErosionGolay(const Halcon::HTuple &GolayElement, const Halcon::HTuple &Iterations, const Halcon::HTuple &Rotation) const;
  // Erode a region with an element from the Golay alphabet.
  virtual HRegion ErosionGolay(const char *GolayElement, Hlong Iterations, Hlong Rotation) const;
  // Erode a region with a rectangular structuring element.
  virtual HRegion ErosionRectangle1(const Halcon::HTuple &Width, const Halcon::HTuple &Height) const;
  // Erode a region with a rectangular structuring element.
  virtual HRegion ErosionRectangle1(Hlong Width, Hlong Height) const;
  // Erode a region with a circular structuring element.
  virtual HRegion ErosionCircle(const Halcon::HTuple &Radius) const;
  // Erode a region with a circular structuring element.
  virtual HRegion ErosionCircle(double Radius) const;
  // Erode a region (using a reference point).
  virtual HRegion Erosion2(const HRegion &StructElement, const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Iterations) const;
  // Erode a region (using a reference point).
  virtual HRegion Erosion2(const HRegion &StructElement, Hlong Row, Hlong Column, Hlong Iterations) const;
  // Erode a region.
  virtual HRegion Erosion1(const HRegion &StructElement, const Halcon::HTuple &Iterations) const;
  // Erode a region.
  virtual HRegion Erosion1(const HRegion &StructElement, Hlong Iterations) const;
  // Dilate a region sequentially.
  virtual HRegion DilationSeq(const Halcon::HTuple &GolayElement, const Halcon::HTuple &Iterations) const;
  // Dilate a region sequentially.
  virtual HRegion DilationSeq(const char *GolayElement, Hlong Iterations) const;
  // Dilate a region with an element from the Golay alphabet.
  virtual HRegion DilationGolay(const Halcon::HTuple &GolayElement, const Halcon::HTuple &Iterations, const Halcon::HTuple &Rotation) const;
  // Dilate a region with an element from the Golay alphabet.
  virtual HRegion DilationGolay(const char *GolayElement, Hlong Iterations, Hlong Rotation) const;
  // Dilate a region with a rectangular structuring element.
  virtual HRegion DilationRectangle1(const Halcon::HTuple &Width, const Halcon::HTuple &Height) const;
  // Dilate a region with a rectangular structuring element.
  virtual HRegion DilationRectangle1(Hlong Width, Hlong Height) const;
  // Dilate a region with a circular structuring element.
  virtual HRegion DilationCircle(const Halcon::HTuple &Radius) const;
  // Dilate a region with a circular structuring element.
  virtual HRegion DilationCircle(double Radius) const;
  // Dilate a region (using a reference point).
  virtual HRegion Dilation2(const HRegion &StructElement, const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Iterations) const;
  // Dilate a region (using a reference point).
  virtual HRegion Dilation2(const HRegion &StructElement, Hlong Row, Hlong Column, Hlong Iterations) const;
  // Dilate a region.
  virtual HRegion Dilation1(const HRegion &StructElement, const Halcon::HTuple &Iterations) const;
  // Dilate a region.
  virtual HRegion Dilation1(const HRegion &StructElement, Hlong Iterations) const;
  // Add gray values to regions.
  virtual HImage AddChannels(const HImage &Image) const;
  // Centres of circles for a specific radius.
  virtual HRegionArray HoughCircles(const Halcon::HTuple &Radius, const Halcon::HTuple &Percent, const Halcon::HTuple &Mode) const;
  // Centres of circles for a specific radius.
  virtual HRegionArray HoughCircles(Hlong Radius, Hlong Percent, Hlong Mode) const;
  // Return the Hough-Transform for circles with a given radius.
  virtual HImageArray HoughCircleTrans(const Halcon::HTuple &Radius) const;
  // Return the Hough-Transform for circles with a given radius.
  virtual HImageArray HoughCircleTrans(Hlong Radius) const;
  // Detect lines in edge images with the help of the Hough transform and
  // returns it in HNF.
  virtual HTuple HoughLines(const Halcon::HTuple &AngleResolution, const Halcon::HTuple &Threshold, const Halcon::HTuple &AngleGap, const Halcon::HTuple &DistGap, Halcon::HTuple *Dist) const;
  // Detect lines in edge images with the help of the Hough transform and
  // returns it in HNF.
  virtual HTuple HoughLines(Hlong AngleResolution, Hlong Threshold, Hlong AngleGap, Hlong DistGap, Halcon::HTuple *Dist) const;
  // Produce the Hough transform for lines within regions.
  virtual HImage HoughLineTrans(const Halcon::HTuple &AngleResolution) const;
  // Produce the Hough transform for lines within regions.
  virtual HImage HoughLineTrans(Hlong AngleResolution) const;
  // Select those lines from a set of lines (in HNF) which
  // fit best into a region.
  virtual HRegionArray SelectMatchingLines(const Halcon::HTuple &AngleIn, const Halcon::HTuple &DistIn, const Halcon::HTuple &LineWidth, const Halcon::HTuple &Thresh, Halcon::HTuple *AngleOut, Halcon::HTuple *DistOut) const;
  // Select those lines from a set of lines (in HNF) which
  // fit best into a region.
  virtual HRegionArray SelectMatchingLines(double AngleIn, double DistIn, Hlong LineWidth, Hlong Thresh, Halcon::HTuple *AngleOut, Halcon::HTuple *DistOut) const;
  // Query the icon for region output
  static HRegion GetIcon(const Halcon::HTuple &WindowHandle);
  // Query the icon for region output
  static HRegion GetIcon(Hlong WindowHandle);
  // Icon definition for region output.
  virtual void SetIcon(const Halcon::HTuple &WindowHandle) const;
  // Icon definition for region output.
  virtual void SetIcon(Hlong WindowHandle) const;
  // Displays regions in a window.
  virtual void DispRegion(const Halcon::HTuple &WindowHandle) const;
  // Displays regions in a window.
  virtual void DispRegion(Hlong WindowHandle) const;
  // Calculate the distance between a line segment and one region.
  virtual HTuple DistanceSr(const Halcon::HTuple &Row1, const Halcon::HTuple &Column1, const Halcon::HTuple &Row2, const Halcon::HTuple &Column2, Halcon::HTuple *DistanceMax) const;
  // Calculate the distance between a line segment and one region.
  virtual HTuple DistanceSr(double Row1, double Column1, double Row2, double Column2, Halcon::HTuple *DistanceMax) const;
  // Calculate the distance between a line and a region.
  virtual HTuple DistanceLr(const Halcon::HTuple &Row1, const Halcon::HTuple &Column1, const Halcon::HTuple &Row2, const Halcon::HTuple &Column2, Halcon::HTuple *DistanceMax) const;
  // Calculate the distance between a line and a region.
  virtual HTuple DistanceLr(double Row1, double Column1, double Row2, double Column2, Halcon::HTuple *DistanceMax) const;
  // Calculate the distance between a point and a region.
  virtual HTuple DistancePr(const Halcon::HTuple &Row, const Halcon::HTuple &Column, Halcon::HTuple *DistanceMax) const;
  // Calculate the distance between a point and a region.
  virtual HTuple DistancePr(double Row, double Column, Halcon::HTuple *DistanceMax) const;
  // Determine the noise distribution of an image.
  virtual HTuple NoiseDistributionMean(const HImage &Image, const Halcon::HTuple &FilterSize) const;
  // Determine the noise distribution of an image.
  virtual HTuple NoiseDistributionMean(const HImage &Image, Hlong FilterSize) const;
  // Determine the fuzzy entropy of regions.
  virtual double FuzzyEntropy(const HImage &Image, const Halcon::HTuple &Apar, const Halcon::HTuple &Cpar) const;
  // Determine the fuzzy entropy of regions.
  virtual double FuzzyEntropy(const HImage &Image, Hlong Apar, Hlong Cpar) const;
  // Calculate the fuzzy perimeter of a region.
  virtual double FuzzyPerimeter(const HImage &Image, const Halcon::HTuple &Apar, const Halcon::HTuple &Cpar) const;
  // Calculate the fuzzy perimeter of a region.
  virtual double FuzzyPerimeter(const HImage &Image, Hlong Apar, Hlong Cpar) const;
  // Paint regions with their average gray value.
  virtual HImage RegionToMean(const HImage &Image) const;
  // Close edge gaps using the edge amplitude image.
  virtual HRegion CloseEdgesLength(const HImage &Gradient, const Halcon::HTuple &MinAmplitude, const Halcon::HTuple &MaxGapLength) const;
  // Close edge gaps using the edge amplitude image.
  virtual HRegion CloseEdgesLength(const HImage &Gradient, Hlong MinAmplitude, Hlong MaxGapLength) const;
  // Close edge gaps using the edge amplitude image.
  virtual HRegion CloseEdges(const HImage &EdgeImage, const Halcon::HTuple &MinAmplitude) const;
  // Close edge gaps using the edge amplitude image.
  virtual HRegion CloseEdges(const HImage &EdgeImage, Hlong MinAmplitude) const;
  // Deserialize a serialized region.
  static HRegion DeserializeRegion(const Halcon::HSerializedItem &SerializedItemHandle);
  // Serialize a region.
  virtual HSerializedItem SerializeRegion(void) const;
  // Write regions to a file.
  virtual void WriteRegion(const Halcon::HTuple &FileName) const;
  // Write regions to a file.
  virtual void WriteRegion(const char *FileName) const;
  // Read binary images or HALCON regions.
  static HRegion ReadRegion(const Halcon::HTuple &FileName);
  // Read binary images or HALCON regions.
  static HRegion ReadRegion(const char *FileName);
  // Geometric moments of regions.
  virtual double MomentsRegionCentralInvar(double *PSI2, double *PSI3, double *PSI4) const;
  // Geometric moments of regions.
  virtual double MomentsRegionCentral(double *I2, double *I3, double *I4) const;
  // Geometric moments of regions.
  virtual double MomentsRegion3rdInvar(double *M12, double *M03, double *M30) const;
  // Geometric moments of regions.
  virtual double MomentsRegion3rd(double *M12, double *M03, double *M30) const;
  // Smallest surrounding rectangle with any orientation.
  virtual double SmallestRectangle2(double *Column, double *Phi, double *Length1, double *Length2) const;
  // Surrounding rectangle parallel to the coordinate axes.
  virtual Hlong SmallestRectangle1(Hlong *Column1, Hlong *Row2, Hlong *Column2) const;
  // Smallest surrounding circle of a region.
  virtual double SmallestCircle(double *Column, double *Radius) const;
  // Choose regions having a certain relation to each other.
  virtual HRegion SelectShapeProto(const HRegion &Pattern, const Halcon::HTuple &Feature, const Halcon::HTuple &Min, const Halcon::HTuple &Max) const;
  // Choose regions having a certain relation to each other.
  virtual HRegion SelectShapeProto(const HRegion &Pattern, const char *Feature, double Min, double Max) const;
  // Choose regions having a certain relation to each other.
  virtual HRegion SelectShapeProto(const HRegionArray &Pattern, const Halcon::HTuple &Feature, const Halcon::HTuple &Min, const Halcon::HTuple &Max) const;
  // Choose regions having a certain relation to each other.
  virtual HRegion SelectShapeProto(const HRegionArray &Pattern, const char *Feature, double Min, double Max) const;
  // Characteristic values for runlength coding of regions.
  virtual Hlong RunlengthFeatures(double *KFactor, double *LFactor, double *MeanLength, Hlong *Bytes) const;
  // Search direct neighbors.
  virtual HTuple FindNeighbors(const HRegion &Regions2, const Halcon::HTuple &MaxDistance, Halcon::HTuple *RegionIndex2) const;
  // Search direct neighbors.
  virtual HTuple FindNeighbors(const HRegion &Regions2, Hlong MaxDistance, Halcon::HTuple *RegionIndex2) const;
  // Search direct neighbors.
  virtual HTuple FindNeighbors(const HRegionArray &Regions2, const Halcon::HTuple &MaxDistance, Halcon::HTuple *RegionIndex2) const;
  // Search direct neighbors.
  virtual HTuple FindNeighbors(const HRegionArray &Regions2, Hlong MaxDistance, Halcon::HTuple *RegionIndex2) const;
  // Geometric moments of regions.
  virtual double MomentsRegion2ndRelInvar(double *PHI2) const;
  // Geometric moments of regions.
  virtual double MomentsRegion2ndInvar(double *M20, double *M02) const;
  // Calculate the geometric moments of regions.
  virtual double MomentsRegion2nd(double *M20, double *M02, double *Ia, double *Ib) const;
  // Minimum distance between the contour pixels of two regions each.
  virtual double DistanceRrMin(const HRegion &Regions2, Hlong *Row1, Hlong *Column1, Hlong *Row2, Hlong *Column2) const;
  // Minimum distance between the contour pixels of two regions each.
  virtual double DistanceRrMin(const HRegionArray &Regions2, Hlong *Row1, Hlong *Column1, Hlong *Row2, Hlong *Column2) const;
  // Minimum distance between two regions with the help of dilation.
  virtual Hlong DistanceRrMinDil(const HRegion &Regions2) const;
  // Minimum distance between two regions with the help of dilation.
  virtual Hlong DistanceRrMinDil(const HRegionArray &Regions2) const;
  // Maximal distance between two boundary points of a region.
  virtual Hlong DiameterRegion(Hlong *Column1, Hlong *Row2, Hlong *Column2, double *Diameter) const;
  // Test if the region contains a given point.
  virtual Hlong TestRegionPoint(const Halcon::HTuple &Row, const Halcon::HTuple &Column) const;
  // Test if the region contains a given point.
  virtual Hlong TestRegionPoint(Hlong Row, Hlong Column) const;
  // Select regions of a given shape.
  virtual HRegion SelectShapeStd(const Halcon::HTuple &Shape, const Halcon::HTuple &Percent) const;
  // Select regions of a given shape.
  virtual HRegion SelectShapeStd(const char *Shape, double Percent) const;
  // Hamming distance between two regions using normalization.
  virtual Hlong HammingDistanceNorm(const HRegion &Regions2, const Halcon::HTuple &Norm, double *Similarity) const;
  // Hamming distance between two regions using normalization.
  virtual Hlong HammingDistanceNorm(const HRegion &Regions2, const char *Norm, double *Similarity) const;
  // Hamming distance between two regions using normalization.
  virtual Hlong HammingDistanceNorm(const HRegionArray &Regions2, const Halcon::HTuple &Norm, double *Similarity) const;
  // Hamming distance between two regions using normalization.
  virtual Hlong HammingDistanceNorm(const HRegionArray &Regions2, const char *Norm, double *Similarity) const;
  // Hamming distance between two regions.
  virtual Hlong HammingDistance(const HRegion &Regions2, double *Similarity) const;
  // Hamming distance between two regions.
  virtual Hlong HammingDistance(const HRegionArray &Regions2, double *Similarity) const;
  // Shape features derived from the ellipse parameters.
  virtual double Eccentricity(double *Bulkiness, double *StructureFactor) const;
  // Calculate the Euler number.
  virtual Hlong EulerNumber(void) const;
  // Orientation of a region.
  virtual double OrientationRegion(void) const;
  // Calculate the parameters of the equivalent ellipse.
  virtual double EllipticAxis(double *Rb, double *Phi) const;
  // Pose relation of regions.
  virtual HTuple SelectRegionSpatial(const HRegion &Regions2, const Halcon::HTuple &Direction, Halcon::HTuple *RegionIndex2) const;
  // Pose relation of regions.
  virtual HTuple SelectRegionSpatial(const HRegion &Regions2, const char *Direction, Halcon::HTuple *RegionIndex2) const;
  // Pose relation of regions.
  virtual HTuple SelectRegionSpatial(const HRegionArray &Regions2, const Halcon::HTuple &Direction, Halcon::HTuple *RegionIndex2) const;
  // Pose relation of regions.
  virtual HTuple SelectRegionSpatial(const HRegionArray &Regions2, const char *Direction, Halcon::HTuple *RegionIndex2) const;
  // Pose relation of regions with regard to  the coordinate axes.
  virtual HTuple SpatialRelation(const HRegion &Regions2, const Halcon::HTuple &Percent, Halcon::HTuple *RegionIndex2, Halcon::HTuple *Relation1, Halcon::HTuple *Relation2) const;
  // Pose relation of regions with regard to  the coordinate axes.
  virtual HTuple SpatialRelation(const HRegion &Regions2, Hlong Percent, Halcon::HTuple *RegionIndex2, Halcon::HTuple *Relation1, Halcon::HTuple *Relation2) const;
  // Pose relation of regions with regard to  the coordinate axes.
  virtual HTuple SpatialRelation(const HRegionArray &Regions2, const Halcon::HTuple &Percent, Halcon::HTuple *RegionIndex2, Halcon::HTuple *Relation1, Halcon::HTuple *Relation2) const;
  // Pose relation of regions with regard to  the coordinate axes.
  virtual HTuple SpatialRelation(const HRegionArray &Regions2, Hlong Percent, Halcon::HTuple *RegionIndex2, Halcon::HTuple *Relation1, Halcon::HTuple *Relation2) const;
  // Shape factor for the convexity of a region.
  virtual double Convexity(void) const;
  // Contour length of a region.
  virtual double Contlength(void) const;
  // Number of connection components and holes
  virtual Hlong ConnectAndHoles(Hlong *NumHoles) const;
  // Shape factor for the rectangularity of a region.
  virtual double Rectangularity(void) const;
  // Shape factor for the compactness of a region.
  virtual double Compactness(void) const;
  // Shape factor for the circularity (similarity to a circle) of a region.
  virtual double Circularity(void) const;
  // Compute the area of holes of regions.
  virtual Hlong AreaHoles(void) const;
  // Area and center of regions.
  virtual Hlong AreaCenter(double *Row, double *Column) const;
  // Distribution of runs needed for runlength encoding of a region.
  virtual HTuple RunlengthDistribution(Halcon::HTuple *Background) const;
  // Shape factors from contour.
  virtual double Roundness(double *Sigma, double *Roundness, double *Sides) const;
  // Largest inner rectangle of a region.
  virtual Hlong InnerRectangle1(Hlong *Column1, Hlong *Row2, Hlong *Column2) const;
  // Largest inner circle of a region.
  virtual double InnerCircle(double *Column, double *Radius) const;
  // Calculate gray value moments and approximation by a first order surface
  // (plane).
  virtual double FitSurfaceFirstOrder(const HImage &Image, const Halcon::HTuple &Algorithm, const Halcon::HTuple &Iterations, const Halcon::HTuple &ClippingFactor, double *Beta, double *Gamma) const;
  // Calculate gray value moments and approximation by a first order surface
  // (plane).
  virtual double FitSurfaceFirstOrder(const HImage &Image, const char *Algorithm, Hlong Iterations, double ClippingFactor, double *Beta, double *Gamma) const;
  // Calculate gray value moments and approximation by a second order surface.
  virtual double FitSurfaceSecondOrder(const HImage &Image, const Halcon::HTuple &Algorithm, const Halcon::HTuple &Iterations, const Halcon::HTuple &ClippingFactor, double *Beta, double *Gamma, double *Delta, double *Epsilon, double *Zeta) const;
  // Calculate gray value moments and approximation by a second order surface.
  virtual double FitSurfaceSecondOrder(const HImage &Image, const char *Algorithm, Hlong Iterations, double ClippingFactor, double *Beta, double *Gamma, double *Delta, double *Epsilon, double *Zeta) const;
  // Determine a histogram of features along all threshold values.
  virtual HTuple ShapeHistoPoint(const HImage &Image, const Halcon::HTuple &Feature, const Halcon::HTuple &Row, const Halcon::HTuple &Column, Halcon::HTuple *RelativeHisto) const;
  // Determine a histogram of features along all threshold values.
  virtual HTuple ShapeHistoPoint(const HImage &Image, const char *Feature, Hlong Row, Hlong Column, Halcon::HTuple *RelativeHisto) const;
  // Determine a histogram of features along all threshold values.
  virtual HTuple ShapeHistoAll(const HImage &Image, const Halcon::HTuple &Feature, Halcon::HTuple *RelativeHisto) const;
  // Determine a histogram of features along all threshold values.
  virtual HTuple ShapeHistoAll(const HImage &Image, const char *Feature, Halcon::HTuple *RelativeHisto) const;
  // Determine the minimum and maximum gray values within regions.
  virtual double MinMaxGray(const HImage &Image, const Halcon::HTuple &Percent, double *Max, double *Range) const;
  // Determine the minimum and maximum gray values within regions.
  virtual double MinMaxGray(const HImage &Image, double Percent, double *Max, double *Range) const;
  // Calculate the mean and deviation of gray values.
  virtual double Intensity(const HImage &Image, double *Deviation) const;
  // Calculate the gray value distribution of a single channel image within a
  // certain gray value range.
  virtual Hlong GrayHistoRange(const HImage &Image, const Halcon::HTuple &Min, const Halcon::HTuple &Max, const Halcon::HTuple &NumBins, double *BinSize) const;
  // Calculate the gray value distribution of a single channel image within a
  // certain gray value range.
  virtual Hlong GrayHistoRange(const HImage &Image, double Min, double Max, Hlong NumBins, double *BinSize) const;
  // Calculate the histogram of two-channel gray value images.
  virtual HImage Histo2dim(const HImage &ImageCol, const HImage &ImageRow) const;
  // Calculate the gray value distribution.
  virtual HTuple GrayHistoAbs(const HImage &Image, const Halcon::HTuple &Quantization) const;
  // Calculate the gray value distribution.
  virtual HTuple GrayHistoAbs(const HImage &Image, double Quantization) const;
  // Calculate the gray value distribution.
  virtual HTuple GrayHisto(const HImage &Image, Halcon::HTuple *RelativeHisto) const;
  // Determine the entropy and anisotropy of images.
  virtual double EntropyGray(const HImage &Image, double *Anisotropy) const;
  // Calculate a co-occurrence matrix and derive gray value features thereof.
  virtual double CoocFeatureImage(const HImage &Image, const Halcon::HTuple &LdGray, const Halcon::HTuple &Direction, double *Correlation, double *Homogeneity, double *Contrast) const;
  // Calculate a co-occurrence matrix and derive gray value features thereof.
  virtual double CoocFeatureImage(const HImage &Image, Hlong LdGray, Hlong Direction, double *Correlation, double *Homogeneity, double *Contrast) const;
  // Calculate the co-occurrence matrix of a region in an image.
  virtual HImage GenCoocMatrix(const HImage &Image, const Halcon::HTuple &LdGray, const Halcon::HTuple &Direction) const;
  // Calculate the co-occurrence matrix of a region in an image.
  virtual HImage GenCoocMatrix(const HImage &Image, Hlong LdGray, Hlong Direction) const;
  // Calculate gray value moments and approximation by a plane.
  virtual double MomentsGrayPlane(const HImage &Image, double *MCol, double *Alpha, double *Beta, double *Mean) const;
  // Calculate the deviation of the gray values from the approximating
  // image plane.
  virtual double PlaneDeviation(const HImage &Image) const;
  // Compute the orientation and major axes of a region in a gray value
  // image.
  virtual double EllipticAxisGray(const HImage &Image, double *Rb, double *Phi) const;
  // Compute the area and center of gravity of a region in a gray value
  // image.
  virtual double AreaCenterGray(const HImage &Image, double *Row, double *Column) const;
  // Calculate horizontal and vertical gray-value projections.
  virtual HTuple GrayProjections(const HImage &Image, const Halcon::HTuple &Mode, Halcon::HTuple *VertProjection) const;
  // Calculate horizontal and vertical gray-value projections.
  virtual HTuple GrayProjections(const HImage &Image, const char *Mode, Halcon::HTuple *VertProjection) const;
  // Extract the data values of the elements (in ECC 200: "modules") inside a
  // bar code region ("Data Matrix symbol") and their positions in the image.
  virtual HTuple Get2dBarCodePos(const HImage &Image, const Halcon::HTuple &BarCodeDescr, const Halcon::HTuple &CodeRegDescr, const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues, Halcon::HTuple *BarCodeData, Halcon::HTuple *DataElementRow, Halcon::HTuple *DataElementCol) const;
  // Extract the values of the data elements (in ECC 200: "modules") inside a
  // bar code region ("Data Matrix symbol").
  virtual HTuple Get2dBarCode(const HImage &Image, const Halcon::HTuple &BarCodeDescr, const Halcon::HTuple &CodeRegDescr, const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues, Halcon::HTuple *BarCodeData) const;
};

}

#endif
