/*****************************************************************************
 * HXLDPolyArray.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HXLDPolyArray
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef XLD_POLY_ARRAY_H
#define XLD_POLY_ARRAY_H


namespace Halcon {


/****************************************************************************/
/*                               HXLDPolyArray                              */
/****************************************************************************/

class LIntExport HXLDPolyArray: public HXLDArray {
public:
  HXLDPolyArray(void) : HXLDArray() {}
  HXLDPolyArray(Hkey *key, Hlong num);
  HXLDPolyArray(const Hobject &obj);
  HXLDPolyArray(const HXLDPoly &poly);
  HXLDPolyArray(const HXLD &xld);
  HXLDPolyArray(const HXLDPolyArray &arr);
  HXLDPolyArray(const HXLDArray &arr);
  ~HXLDPolyArray(void) {}

  HXLDPolyArray &operator= (const HXLDPolyArray &arr);
  HXLDPolyArray &operator= (const HXLDArray &arr);

  // Tools
  virtual const char *HClassName(void) const;
  virtual const char *ClassName(void) const;
  virtual const char *InstClassName(void) const;
  virtual INT4        ClassDBID(void) const {return XLD_POLYGON_ID;}
  virtual Hkey        Key(Hlong i) const {return array[i].Key();}
  virtual Hobject     ElemId(Hlong i) const {return array[i].Id();}

  // Access and Manipulation
  HXLDPoly  const  &operator[] (Hlong index) const;
  HXLDPoly         &operator[] (Hlong index);
  HXLDPolyArray     operator() (Hlong min, Hlong max) const;
  HXLDPolyArray    &Append(const HXLDPoly &poly);
  HXLDPolyArray    &Append(const HXLD &xld);
  HXLDPolyArray    &Append(const HXLDPolyArray &polys);
  HXLDPolyArray    &Append(const HXLDArray &xlds);
  virtual void      SetKeys(Hkey *key, Hlong num);
  virtual void      SetKeys(Hkey *key, Hlong num, Herror *err);
  void              CopyHXLDPolyArray(const HXLDPolyArray &in);
  void              CopyHXLDArray(const HXLDArray &in);

private:
  void NewLength(Hlong new_num, Hlong old_num);

  // Class Functions

public:
  // Compute the union of closed polygons.
  virtual HXLDPolyArray Union2ClosedPolygonsXld(const HXLDPolyArray &Polygons2) const;
  // Compute the symmetric difference of closed polygons.
  virtual HXLDPolyArray SymmDifferenceClosedPolygonsXld(const HXLDPolyArray &Polygons2) const;
  // Compute the difference of closed polygons.
  virtual HXLDPolyArray DifferenceClosedPolygonsXld(const HXLDPolyArray &Sub) const;
  // Intersect closed polygons.
  virtual HXLDPolyArray IntersectionClosedPolygonsXld(const HXLDPolyArray &Polygons2) const;
  // Read XLD polygons from a file in ARC/INFO generate format.
  static HXLDPolyArray ReadPolygonXldArcInfo(const Halcon::HTuple &FileName);
  // Read XLD polygons from a file in ARC/INFO generate format.
  static HXLDPolyArray ReadPolygonXldArcInfo(const char *FileName);
  // Write XLD polygons to a file in ARC/INFO generate format.
  virtual void WritePolygonXldArcInfo(const Halcon::HTuple &FileName) const;
  // Write XLD polygons to a file in ARC/INFO generate format.
  virtual void WritePolygonXldArcInfo(const char *FileName) const;
  // Combine road hypotheses from two resolution levels.
  virtual HXLDPolyArray CombineRoadsXld(const HXLDModParaArray &ModParallels, const HXLDExtParaArray &ExtParallels, const HXLDPolyArray &CenterLines, const Halcon::HTuple &MaxAngleParallel, const Halcon::HTuple &MaxAngleColinear, const Halcon::HTuple &MaxDistanceParallel, const Halcon::HTuple &MaxDistanceColinear) const;
  // Combine road hypotheses from two resolution levels.
  virtual HXLDPolyArray CombineRoadsXld(const HXLDModParaArray &ModParallels, const HXLDExtParaArray &ExtParallels, const HXLDPolyArray &CenterLines, double MaxAngleParallel, double MaxAngleColinear, double MaxDistanceParallel, double MaxDistanceColinear) const;
  // Extract parallel XLD polygons.
  virtual HXLDParaArray GenParallelsXld(const Halcon::HTuple &Len, const Halcon::HTuple &Dist, const Halcon::HTuple &Alpha, const Halcon::HTuple &Merge) const;
  // Extract parallel XLD polygons.
  virtual HXLDParaArray GenParallelsXld(double Len, double Dist, double Alpha, const char *Merge) const;
  // Return an XLD polygon's data (as lines).
  virtual HTuple GetLinesXld(Halcon::HTuple *BeginCol, Halcon::HTuple *EndRow, Halcon::HTuple *EndCol, Halcon::HTuple *Length, Halcon::HTuple *Phi) const;
  // Split XLD contours at dominant points.
  virtual HXLDContArray SplitContoursXld(const Halcon::HTuple &Mode, const Halcon::HTuple &Weight, const Halcon::HTuple &Smooth) const;
  // Split XLD contours at dominant points.
  virtual HXLDContArray SplitContoursXld(const char *Mode, Hlong Weight, Hlong Smooth) const;
  // Apply an arbitrary affine transformation to XLD polygons.
  virtual HXLDPolyArray AffineTransPolygonXld(const Halcon::HTuple &HomMat2D) const;
  // Create a region from an XLD polygon.
  virtual HRegionArray GenRegionPolygonXld(const Halcon::HTuple &Mode) const;
  // Create a region from an XLD polygon.
  virtual HRegionArray GenRegionPolygonXld(const char *Mode) const;
  // Read XLD polygons from a DXF file.
  static HXLDPolyArray ReadPolygonXldDxf(const Halcon::HTuple &FileName, const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues, Halcon::HTuple *DxfStatus);
  // Read XLD polygons from a DXF file.
  static HXLDPolyArray ReadPolygonXldDxf(const char *FileName, const char *GenParamNames, double GenParamValues, Halcon::HTuple *DxfStatus);
  // Write XLD polygons to a file in DXF format.
  virtual void WritePolygonXldDxf(const Halcon::HTuple &FileName) const;
  // Write XLD polygons to a file in DXF format.
  virtual void WritePolygonXldDxf(const char *FileName) const;
};

}

#endif
