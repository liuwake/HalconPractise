/*****************************************************************************
 * HRegionArray.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Types for region arrays
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */


#ifndef H_REGION_ARRAY_H
#define H_REGION_ARRAY_H

//#include "HConst.h"
//#include "IPType.h"


namespace Halcon {


/****************************************************************************/
/*                            HRegionArray                                  */
/****************************************************************************/
class LIntExport HRegionArray: public HObjectArray {
public:
  HRegionArray(void) : array(NULL) {}
  HRegionArray(Hkey *key, Hlong num);
  HRegionArray(const Hobject &obj);
  HRegionArray(const HRegion &reg);
  HRegionArray(const HRegionArray &arr);
  ~HRegionArray(void);
  HRegionArray &operator = (const HRegionArray &arr);
  
  // Tools
  virtual const char *HClassName(void)    const;
  virtual const char *ClassName(void)     const;
  virtual       INT4  ClassDBID(void)     const {return REGION_ID;}
  virtual       Hkey  Key(Hlong i)         const {return array[i].Key();}
  virtual    Hobject  ElemId(Hlong i)      const {return array[i].Id();}
  
  // Access und Manipulation
  HRegion      const &operator [] (Hlong index) const;
  HRegion            &operator [] (Hlong index);
  HRegionArray        operator () (Hlong min, Hlong max) const;
  HRegionArray       &Append(const HRegion &reg);
  HRegionArray       &Append(const HRegionArray &reg);
  virtual void        SetKeys(Hkey *key, Hlong num);
  virtual void        SetKeys(Hkey *key, Hlong num, Herror *err);
  virtual void        Display(const HWindow &w) const;
  virtual void        DeleteArray(void);
  
  // Infix Operations
  HRegionArray operator >> (double radius) const;
  HRegionArray operator << (double radius) const;
  HRegionArray operator + (const HRegion &reg) const;
  HRegionArray operator - (const HRegion &reg) const;
  HRegionArray operator ~ (void) const;
  HRegionArray operator & (const HRegionArray &reg) const;
  HRegionArray operator | (const HRegionArray &reg) const;
  HRegionArray operator / (const HRegionArray &reg) const;
  
private:
  HRegion  *array;
  void     NewLength(Hlong new_num, Hlong old_num);
  void     CopyHRegionArray(const HRegionArray &in);

public:
  // Generate XLD contours from regions.
  virtual HXLDContArray GenContourRegionXld(const Halcon::HTuple &Mode) const;
  // Generate XLD contours from regions.
  virtual HXLDContArray GenContourRegionXld(const char *Mode) const;
  // Receive regions over a socket connection.
  static HRegionArray ReceiveRegion(const Halcon::HSocket &Socket);
  // Send regions over a socket connection.
  virtual void SendRegion(const Halcon::HSocket &Socket) const;
  // Selects characters from a given region.
  virtual HRegionArray SelectCharacters(const Halcon::HTuple &DotPrint, const Halcon::HTuple &StrokeWidth, const Halcon::HTuple &CharWidth, const Halcon::HTuple &CharHeight, const Halcon::HTuple &Punctuation, const Halcon::HTuple &DiacriticMarks, const Halcon::HTuple &PartitionMethod, const Halcon::HTuple &PartitionLines, const Halcon::HTuple &FragmentDistance, const Halcon::HTuple &ConnectFragments, const Halcon::HTuple &ClutterSizeMax, const Halcon::HTuple &StopAfter) const;
  // Segments characters in a given region of an image.
  virtual HImageArray SegmentCharacters(const HImage &Image, HRegionArray *RegionForeground, const Halcon::HTuple &Method, const Halcon::HTuple &EliminateLines, const Halcon::HTuple &DotPrint, const Halcon::HTuple &StrokeWidth, const Halcon::HTuple &CharWidth, const Halcon::HTuple &CharHeight, const Halcon::HTuple &ThresholdOffset, const Halcon::HTuple &Contrast, Halcon::HTuple *UsedThreshold) const;
  // Determines the slant of characters of a text line or paragraph.
  virtual HTuple TextLineSlant(const HImage &Image, const Halcon::HTuple &CharHeight, const Halcon::HTuple &SlantFrom, const Halcon::HTuple &SlantTo) const;
  // Determines the slant of characters of a text line or paragraph.
  virtual HTuple TextLineSlant(const HImage &Image, Hlong CharHeight, double SlantFrom, double SlantTo) const;
  // Determines the orientation of a text line or paragraph.
  virtual HTuple TextLineOrientation(const HImage &Image, const Halcon::HTuple &CharHeight, const Halcon::HTuple &OrientationFrom, const Halcon::HTuple &OrientationTo) const;
  // Determines the orientation of a text line or paragraph.
  virtual HTuple TextLineOrientation(const HImage &Image, Hlong CharHeight, double OrientationFrom, double OrientationTo) const;
  // Construct classes for class_ndim_norm.
  virtual HTuple LearnNdimNorm(const HRegionArray &Background, const HImageArray &Image, const Halcon::HTuple &Metric, const Halcon::HTuple &Distance, const Halcon::HTuple &MinNumberPercent, Halcon::HTuple *Center, Halcon::HTuple *Quality) const;
  // Construct classes for class_ndim_norm.
  virtual HTuple LearnNdimNorm(const HRegionArray &Background, const HImageArray &Image, const char *Metric, double Distance, double MinNumberPercent, Halcon::HTuple *Center, Halcon::HTuple *Quality) const;
  // Train a classificator using a multi-channel image.
  virtual void LearnNdimBox(const HRegionArray &Background, const HImageArray &MultiChannelImage, const Halcon::HClassBox &ClassifHandle) const;
  // Transform a region in polar coordinates back to cartesian
  // coordinates.
  virtual HRegionArray PolarTransRegionInv(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleEnd, const Halcon::HTuple &RadiusStart, const Halcon::HTuple &RadiusEnd, const Halcon::HTuple &WidthIn, const Halcon::HTuple &HeightIn, const Halcon::HTuple &Width, const Halcon::HTuple &Height, const Halcon::HTuple &Interpolation) const;
  // Transform a region in polar coordinates back to cartesian
  // coordinates.
  virtual HRegionArray PolarTransRegionInv(double Row, double Column, double AngleStart, double AngleEnd, double RadiusStart, double RadiusEnd, Hlong WidthIn, Hlong HeightIn, Hlong Width, Hlong Height, const char *Interpolation) const;
  // Transform a region within an annular arc to polar coordinates.
  virtual HRegionArray PolarTransRegion(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleEnd, const Halcon::HTuple &RadiusStart, const Halcon::HTuple &RadiusEnd, const Halcon::HTuple &Width, const Halcon::HTuple &Height, const Halcon::HTuple &Interpolation) const;
  // Transform a region within an annular arc to polar coordinates.
  virtual HRegionArray PolarTransRegion(double Row, double Column, double AngleStart, double AngleEnd, double RadiusStart, double RadiusEnd, Hlong Width, Hlong Height, const char *Interpolation) const;
  // Merge regions from line scan images.
  virtual HRegionArray MergeRegionsLineScan(const HRegionArray &PrevRegions, HRegionArray *PrevMergedRegions, const Halcon::HTuple &ImageHeight, const Halcon::HTuple &MergeBorder, const Halcon::HTuple &MaxImagesRegion) const;
  // Merge regions from line scan images.
  virtual HRegionArray MergeRegionsLineScan(const HRegionArray &PrevRegions, HRegionArray *PrevMergedRegions, Hlong ImageHeight, const char *MergeBorder, Hlong MaxImagesRegion) const;
  // Partition a region into rectangles of approximately equal size.
  virtual HRegionArray PartitionRectangle(const Halcon::HTuple &Width, const Halcon::HTuple &Height) const;
  // Partition a region into rectangles of approximately equal size.
  virtual HRegionArray PartitionRectangle(double Width, double Height) const;
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
  virtual HRegionArray Union2(const HRegionArray &Region2) const;
  // Return the union of all input regions.
  virtual HRegion Union1(void) const;
  // Compute the closest-point transformation of a region.
  virtual HImage ClosestPointTransform(HImage *ClosestPoints, const Halcon::HTuple &Metric, const Halcon::HTuple &Foreground, const Halcon::HTuple &ClosestPointMode, const Halcon::HTuple &Width, const Halcon::HTuple &Height) const;
  // Compute the closest-point transformation of a region.
  virtual HImage ClosestPointTransform(HImage *ClosestPoints, const char *Metric, const char *Foreground, const char *ClosestPointMode, Hlong Width, Hlong Height) const;
  // Compute the distance transformation of a region.
  virtual HImage DistanceTransform(const Halcon::HTuple &Metric, const Halcon::HTuple &Foreground, const Halcon::HTuple &Width, const Halcon::HTuple &Height) const;
  // Compute the distance transformation of a region.
  virtual HImage DistanceTransform(const char *Metric, const char *Foreground, Hlong Width, Hlong Height) const;
  // Compute the skeleton of a region.
  virtual HRegionArray Skeleton(void) const;
  // Apply a projective transformation to a region.
  virtual HRegionArray ProjectiveTransRegion(const Halcon::HTuple &HomMat2D, const Halcon::HTuple &Interpolation) const;
  // Apply an arbitrary affine 2D transformation to regions.
  virtual HRegionArray AffineTransRegion(const Halcon::HTuple &HomMat2D, const Halcon::HTuple &Interpolate) const;
  // Reflect a region about an axis.
  virtual HRegionArray MirrorRegion(const Halcon::HTuple &Mode, const Halcon::HTuple &WidthHeight) const;
  // Reflect a region about an axis.
  virtual HRegionArray MirrorRegion(const char *Mode, Hlong WidthHeight) const;
  // Zoom a region.
  virtual HRegionArray ZoomRegion(const Halcon::HTuple &ScaleWidth, const Halcon::HTuple &ScaleHeight) const;
  // Zoom a region.
  virtual HRegionArray ZoomRegion(double ScaleWidth, double ScaleHeight) const;
  // Translate a region.
  virtual HRegionArray MoveRegion(const Halcon::HTuple &Row, const Halcon::HTuple &Column) const;
  // Translate a region.
  virtual HRegionArray MoveRegion(Hlong Row, Hlong Column) const;
  // Find junctions and end points in a skeleton.
  virtual HRegionArray JunctionsSkeleton(HRegionArray *JuncPoints) const;
  // Calculate the intersection of two regions.
  virtual HRegionArray Intersection(const HRegionArray &Region2) const;
  // Partition the image plane using given regions.
  virtual HRegion Interjacent(const Halcon::HTuple &Mode) const;
  // Partition the image plane using given regions.
  virtual HRegion Interjacent(const char *Mode) const;
  // Fill up holes in regions.
  virtual HRegionArray FillUp(void) const;
  // Fill up holes in regions having given shape features.
  virtual HRegionArray FillUpShape(const Halcon::HTuple &Feature, const Halcon::HTuple &Min, const Halcon::HTuple &Max) const;
  // Fill up holes in regions having given shape features.
  virtual HRegionArray FillUpShape(const char *Feature, double Min, double Max) const;
  // Fill gaps between regions or split overlapping regions.
  virtual HRegionArray ExpandRegion(const HRegion &ForbiddenArea, const Halcon::HTuple &Iterations, const Halcon::HTuple &Mode) const;
  // Fill gaps between regions or split overlapping regions.
  virtual HRegionArray ExpandRegion(const HRegion &ForbiddenArea, Hlong Iterations, const char *Mode) const;
  // Clip a region relative to its smallest surrounding rectangle.
  virtual HRegionArray ClipRegionRel(const Halcon::HTuple &Top, const Halcon::HTuple &Bottom, const Halcon::HTuple &Left, const Halcon::HTuple &Right) const;
  // Clip a region relative to its smallest surrounding rectangle.
  virtual HRegionArray ClipRegionRel(Hlong Top, Hlong Bottom, Hlong Left, Hlong Right) const;
  // Clip a region to a rectangle.
  virtual HRegionArray ClipRegion(const Halcon::HTuple &Row1, const Halcon::HTuple &Column1, const Halcon::HTuple &Row2, const Halcon::HTuple &Column2) const;
  // Clip a region to a rectangle.
  virtual HRegionArray ClipRegion(Hlong Row1, Hlong Column1, Hlong Row2, Hlong Column2) const;
  // Rank operator for regions.
  virtual HRegionArray RankRegion(const Halcon::HTuple &Width, const Halcon::HTuple &Height, const Halcon::HTuple &Number) const;
  // Rank operator for regions.
  virtual HRegionArray RankRegion(Hlong Width, Hlong Height, Hlong Number) const;
  // Compute connected components of a region.
  virtual HRegionArray Connection(void) const;
  // Calculate the symmetric difference of two regions.
  virtual HRegionArray SymmDifference(const HRegionArray &Region2) const;
  // Calculate the difference of two regions.
  virtual HRegionArray Difference(const HRegionArray &Sub) const;
  // Return the complement of a region.
  virtual HRegionArray Complement(void) const;
  // Determine the connected components of the background of given regions.
  virtual HRegionArray BackgroundSeg(void) const;
  // Generate a region having a given Hamming distance.
  virtual HRegionArray HammingChangeRegion(const Halcon::HTuple &Width, const Halcon::HTuple &Height, const Halcon::HTuple &Distance) const;
  // Generate a region having a given Hamming distance.
  virtual HRegionArray HammingChangeRegion(Hlong Width, Hlong Height, Hlong Distance) const;
  // Remove noise from a region.
  virtual HRegionArray RemoveNoiseRegion(const Halcon::HTuple &Type) const;
  // Remove noise from a region.
  virtual HRegionArray RemoveNoiseRegion(const char *Type) const;
  // Transform the shape of a region.
  virtual HRegionArray ShapeTrans(const Halcon::HTuple &Type) const;
  // Transform the shape of a region.
  virtual HRegionArray ShapeTrans(const char *Type) const;
  // Fill gaps between regions (depending on gray value or color) or split
  // overlapping regions.
  virtual HRegionArray ExpandGray(const HImage &Image, const HRegion &ForbiddenArea, const Halcon::HTuple &Iterations, const Halcon::HTuple &Mode, const Halcon::HTuple &Threshold) const;
  // Fill gaps between regions (depending on gray value or color) or split
  // overlapping regions.
  virtual HRegionArray ExpandGrayRef(const HImage &Image, const HRegion &ForbiddenArea, const Halcon::HTuple &Iterations, const Halcon::HTuple &Mode, const Halcon::HTuple &RefGray, const Halcon::HTuple &Threshold) const;
  // Split lines represented by one pixel wide, non-branching lines.
  virtual HTuple SplitSkeletonLines(const Halcon::HTuple &MaxDistance, Halcon::HTuple *BeginCol, Halcon::HTuple *EndRow, Halcon::HTuple *EndCol) const;
  // Split lines represented by one pixel wide, non-branching lines.
  virtual HTuple SplitSkeletonLines(Hlong MaxDistance, Halcon::HTuple *BeginCol, Halcon::HTuple *EndRow, Halcon::HTuple *EndCol) const;
  // Split lines represented by one pixel wide, non-branching regions.
  virtual HRegionArray SplitSkeletonRegion(const Halcon::HTuple &MaxDistance) const;
  // Split lines represented by one pixel wide, non-branching regions.
  virtual HRegionArray SplitSkeletonRegion(Hlong MaxDistance) const;
  // Eliminate runs of a given length.
  virtual HRegionArray EliminateRuns(const Halcon::HTuple &ElimShorter, const Halcon::HTuple &ElimLonger) const;
  // Eliminate runs of a given length.
  virtual HRegionArray EliminateRuns(Hlong ElimShorter, Hlong ElimLonger) const;
  // Paint regions into an image.
  virtual HImage PaintRegion(const HImage &Image, const Halcon::HTuple &Grayval, const Halcon::HTuple &Type) const;
  // Paint regions into an image.
  virtual HImage PaintRegion(const HImage &Image, double Grayval, const char *Type) const;
  // Test whether a region is contained in another region.
  virtual HTuple TestSubsetRegion(const HRegionArray &Region2) const;
  // Test whether the regions of two objects are identical.
  virtual Hlong TestEqualRegion(const HRegionArray &Regions2) const;
  // Create a rectangle of any orientation.
  static HRegionArray GenRectangle2(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Phi, const Halcon::HTuple &Length1, const Halcon::HTuple &Length2);
  // Create a rectangle of any orientation.
  static HRegionArray GenRectangle2(double Row, double Column, double Phi, double Length1, double Length2);
  // Create a rectangle parallel to the coordinate axes.
  static HRegionArray GenRectangle1(const Halcon::HTuple &Row1, const Halcon::HTuple &Column1, const Halcon::HTuple &Row2, const Halcon::HTuple &Column2);
  // Create a rectangle parallel to the coordinate axes.
  static HRegionArray GenRectangle1(double Row1, double Column1, double Row2, double Column2);
  // Create an ellipse sector.
  static HRegionArray GenEllipseSector(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Phi, const Halcon::HTuple &Radius1, const Halcon::HTuple &Radius2, const Halcon::HTuple &StartAngle, const Halcon::HTuple &EndAngle);
  // Create an ellipse sector.
  static HRegionArray GenEllipseSector(double Row, double Column, double Phi, double Radius1, double Radius2, double StartAngle, double EndAngle);
  // Create an ellipse.
  static HRegionArray GenEllipse(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Phi, const Halcon::HTuple &Radius1, const Halcon::HTuple &Radius2);
  // Create an ellipse.
  static HRegionArray GenEllipse(double Row, double Column, double Phi, double Radius1, double Radius2);
  // Create a circle sector.
  static HRegionArray GenCircleSector(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Radius, const Halcon::HTuple &StartAngle, const Halcon::HTuple &EndAngle);
  // Create a circle sector.
  static HRegionArray GenCircleSector(double Row, double Column, double Radius, double StartAngle, double EndAngle);
  // Create a circle.
  static HRegionArray GenCircle(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Radius);
  // Create a circle.
  static HRegionArray GenCircle(double Row, double Column, double Radius);
  // Create random regions like circles, rectangles and ellipses.
  static HRegionArray GenRandomRegions(const Halcon::HTuple &Type, const Halcon::HTuple &WidthMin, const Halcon::HTuple &WidthMax, const Halcon::HTuple &HeightMin, const Halcon::HTuple &HeightMax, const Halcon::HTuple &PhiMin, const Halcon::HTuple &PhiMax, const Halcon::HTuple &NumRegions, const Halcon::HTuple &Width, const Halcon::HTuple &Height);
  // Create random regions like circles, rectangles and ellipses.
  static HRegionArray GenRandomRegions(const char *Type, double WidthMin, double WidthMax, double HeightMin, double HeightMax, double PhiMin, double PhiMax, Hlong NumRegions, Hlong Width, Hlong Height);
  // Store input lines described in Hesse normal form as regions.
  static HRegionArray GenRegionHline(const Halcon::HTuple &Orientation, const Halcon::HTuple &Distance);
  // Store input lines described in Hesse normal form as regions.
  static HRegionArray GenRegionHline(double Orientation, double Distance);
  // Store input lines as regions.
  static HRegionArray GenRegionLine(const Halcon::HTuple &BeginRow, const Halcon::HTuple &BeginCol, const Halcon::HTuple &EndRow, const Halcon::HTuple &EndCol);
  // Store input lines as regions.
  static HRegionArray GenRegionLine(Hlong BeginRow, Hlong BeginCol, Hlong EndRow, Hlong EndCol);
  // Classify a related group of characters with an OCR classifier.
  virtual HTuple DoOcrWordKnn(const HImage &Image, const Halcon::HOCRKnn &OCRHandle, const Halcon::HTuple &Expression, const Halcon::HTuple &NumAlternatives, const Halcon::HTuple &NumCorrections, Halcon::HTuple *Confidence, Halcon::HTuple *Word, Halcon::HTuple *Score) const;
  // Classify a related group of characters with an OCR classifier.
  virtual HTuple DoOcrWordKnn(const HImage &Image, const Halcon::HOCRKnn &OCRHandle, const char *Expression, Hlong NumAlternatives, Hlong NumCorrections, Halcon::HTuple *Confidence, Halcon::HTuple *Word, Halcon::HTuple *Score) const;
  // Classify multiple characters with an k-NN classifier.
  virtual HTuple DoOcrMultiClassKnn(const HImage &Image, const Halcon::HOCRKnn &OCRHandle, Halcon::HTuple *Confidence) const;
  // Classify a related group of characters with an OCR classifier.
  virtual HTuple DoOcrWordSvm(const HImage &Image, const Halcon::HOCRSvm &OCRHandle, const Halcon::HTuple &Expression, const Halcon::HTuple &NumAlternatives, const Halcon::HTuple &NumCorrections, Halcon::HTuple *Word, Halcon::HTuple *Score) const;
  // Classify a related group of characters with an OCR classifier.
  virtual HTuple DoOcrWordSvm(const HImage &Image, const Halcon::HOCRSvm &OCRHandle, const char *Expression, Hlong NumAlternatives, Hlong NumCorrections, Halcon::HTuple *Word, Halcon::HTuple *Score) const;
  // Classify multiple characters with an SVM-based OCR classifier.
  virtual HTuple DoOcrMultiClassSvm(const HImage &Image, const Halcon::HOCRSvm &OCRHandle) const;
  // Classify a related group of characters with an OCR classifier.
  virtual HTuple DoOcrWordMlp(const HImage &Image, const Halcon::HOCRMlp &OCRHandle, const Halcon::HTuple &Expression, const Halcon::HTuple &NumAlternatives, const Halcon::HTuple &NumCorrections, Halcon::HTuple *Confidence, Halcon::HTuple *Word, Halcon::HTuple *Score) const;
  // Classify a related group of characters with an OCR classifier.
  virtual HTuple DoOcrWordMlp(const HImage &Image, const Halcon::HOCRMlp &OCRHandle, const char *Expression, Hlong NumAlternatives, Hlong NumCorrections, Halcon::HTuple *Confidence, Halcon::HTuple *Word, Halcon::HTuple *Score) const;
  // Classify multiple characters with an OCR classifier.
  virtual HTuple DoOcrMultiClassMlp(const HImage &Image, const Halcon::HOCRMlp &OCRHandle, Halcon::HTuple *Confidence) const;
  // Classify characters.
  virtual HTuple DoOcrMulti(const HImage &Image, const Halcon::HOCRBox &OcrHandle, Halcon::HTuple *Confidence) const;
  // Train an OCR classifier by the input of regions.
  virtual double TraindOcrClassBox(const HImage &Image, const Halcon::HOCRBox &OcrHandle, const Halcon::HTuple &Class) const;
  // Train an OCR classifier by the input of regions.
  virtual double TraindOcrClassBox(const HImage &Image, const Halcon::HOCRBox &OcrHandle, const char *Class) const;
  // Storing of training characters into a file.
  virtual void WriteOcrTrainf(const HImage &Image, const Halcon::HTuple &Class, const Halcon::HTuple &TrainingFile) const;
  // Storing of training characters into a file.
  virtual void WriteOcrTrainf(const HImage &Image, const char *Class, const char *TrainingFile) const;
  // Sorting of regions with respect to their relative position.
  virtual HRegionArray SortRegion(const Halcon::HTuple &SortMode, const Halcon::HTuple &Order, const Halcon::HTuple &RowOrCol) const;
  // Sorting of regions with respect to their relative position.
  virtual HRegionArray SortRegion(const char *SortMode, const char *Order, const char *RowOrCol) const;
  // Test an OCR classifier.
  virtual HTuple TestdOcrClassBox(const HImage &Image, const Halcon::HOCRBox &OcrHandle, const Halcon::HTuple &Class) const;
  // Test an OCR classifier.
  virtual HTuple TestdOcrClassBox(const HImage &Image, const Halcon::HOCRBox &OcrHandle, const char *Class) const;
  // Add characters to a training file.
  virtual void AppendOcrTrainf(const HImage &Image, const Halcon::HTuple &Class, const Halcon::HTuple &TrainingFile) const;
  // Add characters to a training file.
  virtual void AppendOcrTrainf(const HImage &Image, const char *Class, const char *TrainingFile) const;
  // Prune the branches of a region.
  virtual HRegionArray Pruning(const Halcon::HTuple &Length) const;
  // Prune the branches of a region.
  virtual HRegionArray Pruning(Hlong Length) const;
  // Reduce a region to its boundary.
  virtual HRegionArray Boundary(const Halcon::HTuple &BoundaryType) const;
  // Reduce a region to its boundary.
  virtual HRegionArray Boundary(const char *BoundaryType) const;
  // Perform a closing after an opening with multiple structuring elements.
  virtual HRegionArray Fitting(const HRegionArray &StructElements) const;
  // Generate standard structuring elements.
  static HRegionArray GenStructElements(const Halcon::HTuple &Type, const Halcon::HTuple &Row, const Halcon::HTuple &Column);
  // Generate standard structuring elements.
  static HRegionArray GenStructElements(const char *Type, Hlong Row, Hlong Column);
  // Reflect a region about a point.
  virtual HRegionArray TransposeRegion(const Halcon::HTuple &Row, const Halcon::HTuple &Column) const;
  // Reflect a region about a point.
  virtual HRegionArray TransposeRegion(Hlong Row, Hlong Column) const;
  // Remove the result of a hit-or-miss operation from a region (sequential).
  virtual HRegionArray ThinningSeq(const Halcon::HTuple &GolayElement, const Halcon::HTuple &Iterations) const;
  // Remove the result of a hit-or-miss operation from a region (sequential).
  virtual HRegionArray ThinningSeq(const char *GolayElement, Hlong Iterations) const;
  // Remove the result of a hit-or-miss operation from a region (using a
  // Golay structuring element).
  virtual HRegionArray ThinningGolay(const Halcon::HTuple &GolayElement, const Halcon::HTuple &Rotation) const;
  // Remove the result of a hit-or-miss operation from a region (using a
  // Golay structuring element).
  virtual HRegionArray ThinningGolay(const char *GolayElement, Hlong Rotation) const;
  // Remove the result of a hit-or-miss operation from a region.
  virtual HRegionArray Thinning(const HRegion &StructElement1, const HRegion &StructElement2, const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Iterations) const;
  // Remove the result of a hit-or-miss operation from a region.
  virtual HRegionArray Thinning(const HRegion &StructElement1, const HRegion &StructElement2, Hlong Row, Hlong Column, Hlong Iterations) const;
  // Add the result of a hit-or-miss operation to a region (sequential).
  virtual HRegionArray ThickeningSeq(const Halcon::HTuple &GolayElement, const Halcon::HTuple &Iterations) const;
  // Add the result of a hit-or-miss operation to a region (sequential).
  virtual HRegionArray ThickeningSeq(const char *GolayElement, Hlong Iterations) const;
  // Add the result of a hit-or-miss operation to a region (using a Golay
  // structuring element).
  virtual HRegionArray ThickeningGolay(const Halcon::HTuple &GolayElement, const Halcon::HTuple &Rotation) const;
  // Add the result of a hit-or-miss operation to a region (using a Golay
  // structuring element).
  virtual HRegionArray ThickeningGolay(const char *GolayElement, Hlong Rotation) const;
  // Add the result of a hit-or-miss operation to a region.
  virtual HRegionArray Thickening(const HRegion &StructElement1, const HRegion &StructElement2, const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Iterations) const;
  // Add the result of a hit-or-miss operation to a region.
  virtual HRegionArray Thickening(const HRegion &StructElement1, const HRegion &StructElement2, Hlong Row, Hlong Column, Hlong Iterations) const;
  // Hit-or-miss operation for regions using the Golay alphabet (sequential).
  virtual HRegionArray HitOrMissSeq(const Halcon::HTuple &GolayElement) const;
  // Hit-or-miss operation for regions using the Golay alphabet (sequential).
  virtual HRegionArray HitOrMissSeq(const char *GolayElement) const;
  // Hit-or-miss operation for regions using the Golay alphabet.
  virtual HRegionArray HitOrMissGolay(const Halcon::HTuple &GolayElement, const Halcon::HTuple &Rotation) const;
  // Hit-or-miss operation for regions using the Golay alphabet.
  virtual HRegionArray HitOrMissGolay(const char *GolayElement, Hlong Rotation) const;
  // Hit-or-miss operation for regions.
  virtual HRegionArray HitOrMiss(const HRegion &StructElement1, const HRegion &StructElement2, const Halcon::HTuple &Row, const Halcon::HTuple &Column) const;
  // Hit-or-miss operation for regions.
  virtual HRegionArray HitOrMiss(const HRegion &StructElement1, const HRegion &StructElement2, Hlong Row, Hlong Column) const;
  // Thinning of a region.
  virtual HRegionArray MorphSkiz(const Halcon::HTuple &Iterations1, const Halcon::HTuple &Iterations2) const;
  // Thinning of a region.
  virtual HRegionArray MorphSkiz(Hlong Iterations1, Hlong Iterations2) const;
  // Compute the morphological skeleton of a region.
  virtual HRegionArray MorphSkeleton(void) const;
  // Compute the union of bottom_hat and top_hat.
  virtual HRegionArray MorphHat(const HRegion &StructElement) const;
  // Compute the bottom hat of regions.
  virtual HRegionArray BottomHat(const HRegion &StructElement) const;
  // Compute the top hat of regions.
  virtual HRegionArray TopHat(const HRegion &StructElement) const;
  // Erode a region (using a reference point).
  virtual HRegionArray MinkowskiSub2(const HRegion &StructElement, const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Iterations) const;
  // Erode a region (using a reference point).
  virtual HRegionArray MinkowskiSub2(const HRegion &StructElement, Hlong Row, Hlong Column, Hlong Iterations) const;
  // Erode a region.
  virtual HRegionArray MinkowskiSub1(const HRegion &StructElement, const Halcon::HTuple &Iterations) const;
  // Erode a region.
  virtual HRegionArray MinkowskiSub1(const HRegion &StructElement, Hlong Iterations) const;
  // Dilate a region (using a reference point).
  virtual HRegionArray MinkowskiAdd2(const HRegion &StructElement, const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Iterations) const;
  // Dilate a region (using a reference point).
  virtual HRegionArray MinkowskiAdd2(const HRegion &StructElement, Hlong Row, Hlong Column, Hlong Iterations) const;
  // Perform a Minkowski addition on a region.
  virtual HRegionArray MinkowskiAdd1(const HRegion &StructElement, const Halcon::HTuple &Iterations) const;
  // Perform a Minkowski addition on a region.
  virtual HRegionArray MinkowskiAdd1(const HRegion &StructElement, Hlong Iterations) const;
  // Close a region with a rectangular structuring element.
  virtual HRegionArray ClosingRectangle1(const Halcon::HTuple &Width, const Halcon::HTuple &Height) const;
  // Close a region with a rectangular structuring element.
  virtual HRegionArray ClosingRectangle1(Hlong Width, Hlong Height) const;
  // Close a region with an element from the Golay alphabet.
  virtual HRegionArray ClosingGolay(const Halcon::HTuple &GolayElement, const Halcon::HTuple &Rotation) const;
  // Close a region with an element from the Golay alphabet.
  virtual HRegionArray ClosingGolay(const char *GolayElement, Hlong Rotation) const;
  // Close a region with a circular structuring element.
  virtual HRegionArray ClosingCircle(const Halcon::HTuple &Radius) const;
  // Close a region with a circular structuring element.
  virtual HRegionArray ClosingCircle(double Radius) const;
  // Close a region.
  virtual HRegionArray Closing(const HRegion &StructElement) const;
  // Separate overlapping regions.
  virtual HRegionArray OpeningSeg(const HRegion &StructElement) const;
  // Open a region with an element from the Golay alphabet.
  virtual HRegionArray OpeningGolay(const Halcon::HTuple &GolayElement, const Halcon::HTuple &Rotation) const;
  // Open a region with an element from the Golay alphabet.
  virtual HRegionArray OpeningGolay(const char *GolayElement, Hlong Rotation) const;
  // Open a region with a rectangular structuring element.
  virtual HRegionArray OpeningRectangle1(const Halcon::HTuple &Width, const Halcon::HTuple &Height) const;
  // Open a region with a rectangular structuring element.
  virtual HRegionArray OpeningRectangle1(Hlong Width, Hlong Height) const;
  // Open a region with a circular structuring element.
  virtual HRegionArray OpeningCircle(const Halcon::HTuple &Radius) const;
  // Open a region with a circular structuring element.
  virtual HRegionArray OpeningCircle(double Radius) const;
  // Open a region.
  virtual HRegionArray Opening(const HRegion &StructElement) const;
  // Erode a region sequentially.
  virtual HRegionArray ErosionSeq(const Halcon::HTuple &GolayElement, const Halcon::HTuple &Iterations) const;
  // Erode a region sequentially.
  virtual HRegionArray ErosionSeq(const char *GolayElement, Hlong Iterations) const;
  // Erode a region with an element from the Golay alphabet.
  virtual HRegionArray ErosionGolay(const Halcon::HTuple &GolayElement, const Halcon::HTuple &Iterations, const Halcon::HTuple &Rotation) const;
  // Erode a region with an element from the Golay alphabet.
  virtual HRegionArray ErosionGolay(const char *GolayElement, Hlong Iterations, Hlong Rotation) const;
  // Erode a region with a rectangular structuring element.
  virtual HRegionArray ErosionRectangle1(const Halcon::HTuple &Width, const Halcon::HTuple &Height) const;
  // Erode a region with a rectangular structuring element.
  virtual HRegionArray ErosionRectangle1(Hlong Width, Hlong Height) const;
  // Erode a region with a circular structuring element.
  virtual HRegionArray ErosionCircle(const Halcon::HTuple &Radius) const;
  // Erode a region with a circular structuring element.
  virtual HRegionArray ErosionCircle(double Radius) const;
  // Erode a region (using a reference point).
  virtual HRegionArray Erosion2(const HRegion &StructElement, const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Iterations) const;
  // Erode a region (using a reference point).
  virtual HRegionArray Erosion2(const HRegion &StructElement, Hlong Row, Hlong Column, Hlong Iterations) const;
  // Erode a region.
  virtual HRegionArray Erosion1(const HRegion &StructElement, const Halcon::HTuple &Iterations) const;
  // Erode a region.
  virtual HRegionArray Erosion1(const HRegion &StructElement, Hlong Iterations) const;
  // Dilate a region sequentially.
  virtual HRegionArray DilationSeq(const Halcon::HTuple &GolayElement, const Halcon::HTuple &Iterations) const;
  // Dilate a region sequentially.
  virtual HRegionArray DilationSeq(const char *GolayElement, Hlong Iterations) const;
  // Dilate a region with an element from the Golay alphabet.
  virtual HRegionArray DilationGolay(const Halcon::HTuple &GolayElement, const Halcon::HTuple &Iterations, const Halcon::HTuple &Rotation) const;
  // Dilate a region with an element from the Golay alphabet.
  virtual HRegionArray DilationGolay(const char *GolayElement, Hlong Iterations, Hlong Rotation) const;
  // Dilate a region with a rectangular structuring element.
  virtual HRegionArray DilationRectangle1(const Halcon::HTuple &Width, const Halcon::HTuple &Height) const;
  // Dilate a region with a rectangular structuring element.
  virtual HRegionArray DilationRectangle1(Hlong Width, Hlong Height) const;
  // Dilate a region with a circular structuring element.
  virtual HRegionArray DilationCircle(const Halcon::HTuple &Radius) const;
  // Dilate a region with a circular structuring element.
  virtual HRegionArray DilationCircle(double Radius) const;
  // Dilate a region (using a reference point).
  virtual HRegionArray Dilation2(const HRegion &StructElement, const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Iterations) const;
  // Dilate a region (using a reference point).
  virtual HRegionArray Dilation2(const HRegion &StructElement, Hlong Row, Hlong Column, Hlong Iterations) const;
  // Dilate a region.
  virtual HRegionArray Dilation1(const HRegion &StructElement, const Halcon::HTuple &Iterations) const;
  // Dilate a region.
  virtual HRegionArray Dilation1(const HRegion &StructElement, Hlong Iterations) const;
  // Add gray values to regions.
  virtual HImageArray AddChannels(const HImage &Image) const;
  // Displays regions in a window.
  virtual void DispRegion(const Halcon::HTuple &WindowHandle) const;
  // Displays regions in a window.
  virtual void DispRegion(Hlong WindowHandle) const;
  // Interactive movement of a region with restriction of positions.
  virtual HRegionArray DragRegion3(const HRegionArray &MaskRegion, const Halcon::HTuple &WindowHandle, const Halcon::HTuple &Row, const Halcon::HTuple &Column) const;
  // Interactive movement of a region with restriction of positions.
  virtual HRegionArray DragRegion3(const HRegionArray &MaskRegion, Hlong WindowHandle, Hlong Row, Hlong Column) const;
  // Interactive movement of a region with fixpoint specification.
  virtual HRegionArray DragRegion2(const Halcon::HTuple &WindowHandle, const Halcon::HTuple &Row, const Halcon::HTuple &Column) const;
  // Interactive movement of a region with fixpoint specification.
  virtual HRegionArray DragRegion2(Hlong WindowHandle, Hlong Row, Hlong Column) const;
  // Interactive moving of a region.
  virtual HRegionArray DragRegion1(const Halcon::HTuple &WindowHandle) const;
  // Interactive moving of a region.
  virtual HRegionArray DragRegion1(Hlong WindowHandle) const;
  // Determine the noise distribution of an image.
  virtual HTuple NoiseDistributionMean(const HImage &Image, const Halcon::HTuple &FilterSize) const;
  // Determine the noise distribution of an image.
  virtual HTuple NoiseDistributionMean(const HImage &Image, Hlong FilterSize) const;
  // Determine the fuzzy entropy of regions.
  virtual HTuple FuzzyEntropy(const HImage &Image, const Halcon::HTuple &Apar, const Halcon::HTuple &Cpar) const;
  // Determine the fuzzy entropy of regions.
  virtual HTuple FuzzyEntropy(const HImage &Image, Hlong Apar, Hlong Cpar) const;
  // Calculate the fuzzy perimeter of a region.
  virtual HTuple FuzzyPerimeter(const HImage &Image, const Halcon::HTuple &Apar, const Halcon::HTuple &Cpar) const;
  // Calculate the fuzzy perimeter of a region.
  virtual HTuple FuzzyPerimeter(const HImage &Image, Hlong Apar, Hlong Cpar) const;
  // Paint regions with their average gray value.
  virtual HImage RegionToMean(const HImage &Image) const;
  // Close edge gaps using the edge amplitude image.
  virtual HRegionArray CloseEdgesLength(const HImage &Gradient, const Halcon::HTuple &MinAmplitude, const Halcon::HTuple &MaxGapLength) const;
  // Close edge gaps using the edge amplitude image.
  virtual HRegionArray CloseEdgesLength(const HImage &Gradient, Hlong MinAmplitude, Hlong MaxGapLength) const;
  // Close edge gaps using the edge amplitude image.
  virtual HRegionArray CloseEdges(const HImage &EdgeImage, const Halcon::HTuple &MinAmplitude) const;
  // Close edge gaps using the edge amplitude image.
  virtual HRegionArray CloseEdges(const HImage &EdgeImage, Hlong MinAmplitude) const;
  // Deserialize a serialized region.
  static HRegionArray DeserializeRegion(const Halcon::HSerializedItem &SerializedItemHandle);
  // Serialize a region.
  virtual HSerializedItem SerializeRegion(void) const;
  // Write regions to a file.
  virtual void WriteRegion(const Halcon::HTuple &FileName) const;
  // Write regions to a file.
  virtual void WriteRegion(const char *FileName) const;
  // Read binary images or HALCON regions.
  static HRegionArray ReadRegion(const Halcon::HTuple &FileName);
  // Read binary images or HALCON regions.
  static HRegionArray ReadRegion(const char *FileName);
  // Geometric moments of regions.
  virtual HTuple MomentsRegionCentralInvar(Halcon::HTuple *PSI2, Halcon::HTuple *PSI3, Halcon::HTuple *PSI4) const;
  // Geometric moments of regions.
  virtual HTuple MomentsRegionCentral(Halcon::HTuple *I2, Halcon::HTuple *I3, Halcon::HTuple *I4) const;
  // Geometric moments of regions.
  virtual HTuple MomentsRegion3rdInvar(Halcon::HTuple *M12, Halcon::HTuple *M03, Halcon::HTuple *M30) const;
  // Geometric moments of regions.
  virtual HTuple MomentsRegion3rd(Halcon::HTuple *M12, Halcon::HTuple *M03, Halcon::HTuple *M30) const;
  // Smallest surrounding rectangle with any orientation.
  virtual HTuple SmallestRectangle2(Halcon::HTuple *Column, Halcon::HTuple *Phi, Halcon::HTuple *Length1, Halcon::HTuple *Length2) const;
  // Surrounding rectangle parallel to the coordinate axes.
  virtual HTuple SmallestRectangle1(Halcon::HTuple *Column1, Halcon::HTuple *Row2, Halcon::HTuple *Column2) const;
  // Smallest surrounding circle of a region.
  virtual HTuple SmallestCircle(Halcon::HTuple *Column, Halcon::HTuple *Radius) const;
  // Choose regions having a certain relation to each other.
  virtual HRegionArray SelectShapeProto(const HRegionArray &Pattern, const Halcon::HTuple &Feature, const Halcon::HTuple &Min, const Halcon::HTuple &Max) const;
  // Choose regions having a certain relation to each other.
  virtual HRegionArray SelectShapeProto(const HRegionArray &Pattern, const char *Feature, double Min, double Max) const;
  // Calculate shape features of regions.
  virtual HTuple RegionFeatures(const Halcon::HTuple &Features) const;
  // Calculate shape features of regions.
  virtual HTuple RegionFeatures(const char *Features) const;
  // Choose regions with the aid of shape features.
  virtual HRegionArray SelectShape(const Halcon::HTuple &Features, const Halcon::HTuple &Operation, const Halcon::HTuple &Min, const Halcon::HTuple &Max) const;
  // Choose regions with the aid of shape features.
  virtual HRegionArray SelectShape(const char *Features, const char *Operation, double Min, double Max) const;
  // Characteristic values for runlength coding of regions.
  virtual HTuple RunlengthFeatures(Halcon::HTuple *KFactor, Halcon::HTuple *LFactor, Halcon::HTuple *MeanLength, Halcon::HTuple *Bytes) const;
  // Search direct neighbors.
  virtual HTuple FindNeighbors(const HRegionArray &Regions2, const Halcon::HTuple &MaxDistance, Halcon::HTuple *RegionIndex2) const;
  // Search direct neighbors.
  virtual HTuple FindNeighbors(const HRegionArray &Regions2, Hlong MaxDistance, Halcon::HTuple *RegionIndex2) const;
  // Geometric moments of regions.
  virtual HTuple MomentsRegion2ndRelInvar(Halcon::HTuple *PHI2) const;
  // Geometric moments of regions.
  virtual HTuple MomentsRegion2ndInvar(Halcon::HTuple *M20, Halcon::HTuple *M02) const;
  // Calculate the geometric moments of regions.
  virtual HTuple MomentsRegion2nd(Halcon::HTuple *M20, Halcon::HTuple *M02, Halcon::HTuple *Ia, Halcon::HTuple *Ib) const;
  // Minimum distance between the contour pixels of two regions each.
  virtual HTuple DistanceRrMin(const HRegionArray &Regions2, Halcon::HTuple *Row1, Halcon::HTuple *Column1, Halcon::HTuple *Row2, Halcon::HTuple *Column2) const;
  // Minimum distance between two regions with the help of dilation.
  virtual HTuple DistanceRrMinDil(const HRegionArray &Regions2) const;
  // Maximal distance between two boundary points of a region.
  virtual HTuple DiameterRegion(Halcon::HTuple *Column1, Halcon::HTuple *Row2, Halcon::HTuple *Column2, Halcon::HTuple *Diameter) const;
  // Test if the region contains a given point.
  virtual Hlong TestRegionPoint(const Halcon::HTuple &Row, const Halcon::HTuple &Column) const;
  // Test if the region contains a given point.
  virtual Hlong TestRegionPoint(Hlong Row, Hlong Column) const;
  // Index of all regions containing a given pixel.
  virtual HTuple GetRegionIndex(const Halcon::HTuple &Row, const Halcon::HTuple &Column) const;
  // Index of all regions containing a given pixel.
  virtual HTuple GetRegionIndex(Hlong Row, Hlong Column) const;
  // Choose all regions containing a given pixel.
  virtual HRegionArray SelectRegionPoint(const Halcon::HTuple &Row, const Halcon::HTuple &Column) const;
  // Choose all regions containing a given pixel.
  virtual HRegionArray SelectRegionPoint(Hlong Row, Hlong Column) const;
  // Select regions of a given shape.
  virtual HRegionArray SelectShapeStd(const Halcon::HTuple &Shape, const Halcon::HTuple &Percent) const;
  // Select regions of a given shape.
  virtual HRegionArray SelectShapeStd(const char *Shape, double Percent) const;
  // Hamming distance between two regions using normalization.
  virtual HTuple HammingDistanceNorm(const HRegionArray &Regions2, const Halcon::HTuple &Norm, Halcon::HTuple *Similarity) const;
  // Hamming distance between two regions using normalization.
  virtual HTuple HammingDistanceNorm(const HRegionArray &Regions2, const char *Norm, Halcon::HTuple *Similarity) const;
  // Hamming distance between two regions.
  virtual HTuple HammingDistance(const HRegionArray &Regions2, Halcon::HTuple *Similarity) const;
  // Shape features derived from the ellipse parameters.
  virtual HTuple Eccentricity(Halcon::HTuple *Bulkiness, Halcon::HTuple *StructureFactor) const;
  // Calculate the Euler number.
  virtual HTuple EulerNumber(void) const;
  // Orientation of a region.
  virtual HTuple OrientationRegion(void) const;
  // Calculate the parameters of the equivalent ellipse.
  virtual HTuple EllipticAxis(Halcon::HTuple *Rb, Halcon::HTuple *Phi) const;
  // Pose relation of regions.
  virtual HTuple SelectRegionSpatial(const HRegionArray &Regions2, const Halcon::HTuple &Direction, Halcon::HTuple *RegionIndex2) const;
  // Pose relation of regions.
  virtual HTuple SelectRegionSpatial(const HRegionArray &Regions2, const char *Direction, Halcon::HTuple *RegionIndex2) const;
  // Pose relation of regions with regard to  the coordinate axes.
  virtual HTuple SpatialRelation(const HRegionArray &Regions2, const Halcon::HTuple &Percent, Halcon::HTuple *RegionIndex2, Halcon::HTuple *Relation1, Halcon::HTuple *Relation2) const;
  // Pose relation of regions with regard to  the coordinate axes.
  virtual HTuple SpatialRelation(const HRegionArray &Regions2, Hlong Percent, Halcon::HTuple *RegionIndex2, Halcon::HTuple *Relation1, Halcon::HTuple *Relation2) const;
  // Shape factor for the convexity of a region.
  virtual HTuple Convexity(void) const;
  // Contour length of a region.
  virtual HTuple Contlength(void) const;
  // Number of connection components and holes
  virtual HTuple ConnectAndHoles(Halcon::HTuple *NumHoles) const;
  // Shape factor for the rectangularity of a region.
  virtual HTuple Rectangularity(void) const;
  // Shape factor for the compactness of a region.
  virtual HTuple Compactness(void) const;
  // Shape factor for the circularity (similarity to a circle) of a region.
  virtual HTuple Circularity(void) const;
  // Compute the area of holes of regions.
  virtual HTuple AreaHoles(void) const;
  // Area and center of regions.
  virtual HTuple AreaCenter(Halcon::HTuple *Row, Halcon::HTuple *Column) const;
  // Shape factors from contour.
  virtual HTuple Roundness(Halcon::HTuple *Sigma, Halcon::HTuple *Roundness, Halcon::HTuple *Sides) const;
  // Largest inner rectangle of a region.
  virtual HTuple InnerRectangle1(Halcon::HTuple *Column1, Halcon::HTuple *Row2, Halcon::HTuple *Column2) const;
  // Largest inner circle of a region.
  virtual HTuple InnerCircle(Halcon::HTuple *Column, Halcon::HTuple *Radius) const;
  // Calculate gray value moments and approximation by a first order surface
  // (plane).
  virtual HTuple FitSurfaceFirstOrder(const HImage &Image, const Halcon::HTuple &Algorithm, const Halcon::HTuple &Iterations, const Halcon::HTuple &ClippingFactor, Halcon::HTuple *Beta, Halcon::HTuple *Gamma) const;
  // Calculate gray value moments and approximation by a first order surface
  // (plane).
  virtual HTuple FitSurfaceFirstOrder(const HImage &Image, const char *Algorithm, Hlong Iterations, double ClippingFactor, Halcon::HTuple *Beta, Halcon::HTuple *Gamma) const;
  // Calculate gray value moments and approximation by a second order surface.
  virtual HTuple FitSurfaceSecondOrder(const HImage &Image, const Halcon::HTuple &Algorithm, const Halcon::HTuple &Iterations, const Halcon::HTuple &ClippingFactor, Halcon::HTuple *Beta, Halcon::HTuple *Gamma, Halcon::HTuple *Delta, Halcon::HTuple *Epsilon, Halcon::HTuple *Zeta) const;
  // Calculate gray value moments and approximation by a second order surface.
  virtual HTuple FitSurfaceSecondOrder(const HImage &Image, const char *Algorithm, Hlong Iterations, double ClippingFactor, Halcon::HTuple *Beta, Halcon::HTuple *Gamma, Halcon::HTuple *Delta, Halcon::HTuple *Epsilon, Halcon::HTuple *Zeta) const;
  // Calculates gray value features for a set of regions.
  virtual HTuple GrayFeatures(const HImage &Image, const Halcon::HTuple &Features) const;
  // Calculates gray value features for a set of regions.
  virtual HTuple GrayFeatures(const HImage &Image, const char *Features) const;
  // Select regions based on gray value features.
  virtual HRegionArray SelectGray(const HImage &Image, const Halcon::HTuple &Features, const Halcon::HTuple &Operation, const Halcon::HTuple &Min, const Halcon::HTuple &Max) const;
  // Select regions based on gray value features.
  virtual HRegionArray SelectGray(const HImage &Image, const char *Features, const char *Operation, double Min, double Max) const;
  // Determine the minimum and maximum gray values within regions.
  virtual HTuple MinMaxGray(const HImage &Image, const Halcon::HTuple &Percent, Halcon::HTuple *Max, Halcon::HTuple *Range) const;
  // Determine the minimum and maximum gray values within regions.
  virtual HTuple MinMaxGray(const HImage &Image, double Percent, Halcon::HTuple *Max, Halcon::HTuple *Range) const;
  // Calculate the mean and deviation of gray values.
  virtual HTuple Intensity(const HImage &Image, Halcon::HTuple *Deviation) const;
  // Calculate the gray value distribution of a single channel image within a
  // certain gray value range.
  virtual HTuple GrayHistoRange(const HImage &Image, const Halcon::HTuple &Min, const Halcon::HTuple &Max, const Halcon::HTuple &NumBins, Halcon::HTuple *BinSize) const;
  // Calculate the gray value distribution of a single channel image within a
  // certain gray value range.
  virtual HTuple GrayHistoRange(const HImage &Image, double Min, double Max, Hlong NumBins, Halcon::HTuple *BinSize) const;
  // Calculate the histogram of two-channel gray value images.
  virtual HImage Histo2dim(const HImage &ImageCol, const HImage &ImageRow) const;
  // Calculate the gray value distribution.
  virtual HTuple GrayHistoAbs(const HImage &Image, const Halcon::HTuple &Quantization) const;
  // Calculate the gray value distribution.
  virtual HTuple GrayHistoAbs(const HImage &Image, double Quantization) const;
  // Calculate the gray value distribution.
  virtual HTuple GrayHisto(const HImage &Image, Halcon::HTuple *RelativeHisto) const;
  // Determine the entropy and anisotropy of images.
  virtual HTuple EntropyGray(const HImage &Image, Halcon::HTuple *Anisotropy) const;
  // Calculate a co-occurrence matrix and derive gray value features thereof.
  virtual HTuple CoocFeatureImage(const HImage &Image, const Halcon::HTuple &LdGray, const Halcon::HTuple &Direction, Halcon::HTuple *Correlation, Halcon::HTuple *Homogeneity, Halcon::HTuple *Contrast) const;
  // Calculate a co-occurrence matrix and derive gray value features thereof.
  virtual HTuple CoocFeatureImage(const HImage &Image, Hlong LdGray, Hlong Direction, Halcon::HTuple *Correlation, Halcon::HTuple *Homogeneity, Halcon::HTuple *Contrast) const;
  // Calculate the co-occurrence matrix of a region in an image.
  virtual HImageArray GenCoocMatrix(const HImage &Image, const Halcon::HTuple &LdGray, const Halcon::HTuple &Direction) const;
  // Calculate the co-occurrence matrix of a region in an image.
  virtual HImageArray GenCoocMatrix(const HImage &Image, Hlong LdGray, Hlong Direction) const;
  // Calculate gray value moments and approximation by a plane.
  virtual HTuple MomentsGrayPlane(const HImage &Image, Halcon::HTuple *MCol, Halcon::HTuple *Alpha, Halcon::HTuple *Beta, Halcon::HTuple *Mean) const;
  // Calculate the deviation of the gray values from the approximating
  // image plane.
  virtual HTuple PlaneDeviation(const HImage &Image) const;
  // Compute the orientation and major axes of a region in a gray value
  // image.
  virtual HTuple EllipticAxisGray(const HImage &Image, Halcon::HTuple *Rb, Halcon::HTuple *Phi) const;
  // Compute the area and center of gravity of a region in a gray value
  // image.
  virtual HTuple AreaCenterGray(const HImage &Image, Halcon::HTuple *Row, Halcon::HTuple *Column) const;
};

}

#endif
