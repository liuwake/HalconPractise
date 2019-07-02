/*****************************************************************************
 * HMeasure.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HMeasure
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_MEASURE_H
#define H_MEASURE_H


#include "HCPPToolRef.h"


namespace Halcon {


class LIntExport HMeasure: public HToolBase 
{
public:

  // Tool-specific functional class constructors

  HMeasure(
      const HTuple &CenterRow, const HTuple &CenterCol, 
      const HTuple &Radius, 
      const HTuple &AngleStart, const HTuple &AngleExtent, 
      const HTuple &AnnulusRadius, 
      const HTuple &Width, const HTuple &Height, 
      const HTuple &Interpolation);
      
  HMeasure(
      double CenterRow, double CenterCol, 
      double Radius, 
      double AngleStart, double AngleExtent, 
      double AnnulusRadius, 
      Hlong Width, Hlong Height, 
      const char *Interpolation);
      
  HMeasure(
      const HTuple &Row, const HTuple &Column, 
      const HTuple &Phi, 
      const HTuple &Length1, const HTuple &Length2, 
      const HTuple &Width, const HTuple &Height, 
      const HTuple &Interpolation);
      
  HMeasure(
      double Row, double Column, 
      double Phi, 
      double Length1, double Length2, 
      Hlong Width, Hlong Height, 
      const char *Interpolation);

  // Common tool class management functionality

  HMeasure();
  HMeasure(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Serialize a measure object.
  virtual HSerializedItem SerializeMeasure() const;
  // Deserialize a serialized measure object.
  virtual void DeserializeMeasure(const Halcon::HSerializedItem &SerializedItemHandle);
  // Write a measure object to a file.
  virtual void WriteMeasure(const Halcon::HTuple &FileName) const;
  // Write a measure object to a file.
  virtual void WriteMeasure(const char *FileName) const;
  // Read a measure object from a file.
  virtual void ReadMeasure(const Halcon::HTuple &FileName);
  // Read a measure object from a file.
  virtual void ReadMeasure(const char *FileName);
  // Extracting points with a particular gray value along a rectangle or an
  // annular arc.
  virtual HTuple MeasureThresh(const HImage &Image, const Halcon::HTuple &Sigma, const Halcon::HTuple &Threshold, const Halcon::HTuple &Select, Halcon::HTuple *ColumnThresh, Halcon::HTuple *Distance) const;
  // Extracting points with a particular gray value along a rectangle or an
  // annular arc.
  virtual HTuple MeasureThresh(const HImage &Image, double Sigma, double Threshold, const char *Select, Halcon::HTuple *ColumnThresh, Halcon::HTuple *Distance) const;
  // Extract a gray value profile perpendicular to a rectangle or annular arc.
  virtual HTuple MeasureProjection(const HImage &Image) const;
  // Reset a fuzzy function.
  virtual void ResetFuzzyMeasure(const Halcon::HTuple &SetType) const;
  // Reset a fuzzy function.
  virtual void ResetFuzzyMeasure(const char *SetType) const;
  // Specify a normalized fuzzy function for edge pairs.
  virtual void SetFuzzyMeasureNormPair(const Halcon::HTuple &PairSize, const Halcon::HTuple &SetType, const Halcon::HTuple &Function) const;
  // Specify a fuzzy function.
  virtual void SetFuzzyMeasure(const Halcon::HTuple &SetType, const Halcon::HTuple &Function) const;
  // Extract straight edge pairs perpendicular to a rectangle or an
  // annular arc.
  virtual HTuple FuzzyMeasurePairing(const HImage &Image, const Halcon::HTuple &Sigma, const Halcon::HTuple &AmpThresh, const Halcon::HTuple &FuzzyThresh, const Halcon::HTuple &Transition, const Halcon::HTuple &Pairing, const Halcon::HTuple &NumPairs, Halcon::HTuple *ColumnEdgeFirst, Halcon::HTuple *AmplitudeFirst, Halcon::HTuple *RowEdgeSecond, Halcon::HTuple *ColumnEdgeSecond, Halcon::HTuple *AmplitudeSecond, Halcon::HTuple *RowPairCenter, Halcon::HTuple *ColumnPairCenter, Halcon::HTuple *FuzzyScore, Halcon::HTuple *IntraDistance) const;
  // Extract straight edge pairs perpendicular to a rectangle or an
  // annular arc.
  virtual HTuple FuzzyMeasurePairing(const HImage &Image, double Sigma, double AmpThresh, double FuzzyThresh, const char *Transition, const char *Pairing, Hlong NumPairs, Halcon::HTuple *ColumnEdgeFirst, Halcon::HTuple *AmplitudeFirst, Halcon::HTuple *RowEdgeSecond, Halcon::HTuple *ColumnEdgeSecond, Halcon::HTuple *AmplitudeSecond, Halcon::HTuple *RowPairCenter, Halcon::HTuple *ColumnPairCenter, Halcon::HTuple *FuzzyScore, Halcon::HTuple *IntraDistance) const;
  // Extract straight edge pairs perpendicular to a rectangle or an annular arc.
  virtual HTuple FuzzyMeasurePairs(const HImage &Image, const Halcon::HTuple &Sigma, const Halcon::HTuple &AmpThresh, const Halcon::HTuple &FuzzyThresh, const Halcon::HTuple &Transition, Halcon::HTuple *ColumnEdgeFirst, Halcon::HTuple *AmplitudeFirst, Halcon::HTuple *RowEdgeSecond, Halcon::HTuple *ColumnEdgeSecond, Halcon::HTuple *AmplitudeSecond, Halcon::HTuple *RowEdgeCenter, Halcon::HTuple *ColumnEdgeCenter, Halcon::HTuple *FuzzyScore, Halcon::HTuple *IntraDistance, Halcon::HTuple *InterDistance) const;
  // Extract straight edge pairs perpendicular to a rectangle or an annular arc.
  virtual HTuple FuzzyMeasurePairs(const HImage &Image, double Sigma, double AmpThresh, double FuzzyThresh, const char *Transition, Halcon::HTuple *ColumnEdgeFirst, Halcon::HTuple *AmplitudeFirst, Halcon::HTuple *RowEdgeSecond, Halcon::HTuple *ColumnEdgeSecond, Halcon::HTuple *AmplitudeSecond, Halcon::HTuple *RowEdgeCenter, Halcon::HTuple *ColumnEdgeCenter, Halcon::HTuple *FuzzyScore, Halcon::HTuple *IntraDistance, Halcon::HTuple *InterDistance) const;
  // Extract straight edges perpendicular to a rectangle or an annular arc.
  virtual HTuple FuzzyMeasurePos(const HImage &Image, const Halcon::HTuple &Sigma, const Halcon::HTuple &AmpThresh, const Halcon::HTuple &FuzzyThresh, const Halcon::HTuple &Transition, Halcon::HTuple *ColumnEdge, Halcon::HTuple *Amplitude, Halcon::HTuple *FuzzyScore, Halcon::HTuple *Distance) const;
  // Extract straight edges perpendicular to a rectangle or an annular arc.
  virtual HTuple FuzzyMeasurePos(const HImage &Image, double Sigma, double AmpThresh, double FuzzyThresh, const char *Transition, Halcon::HTuple *ColumnEdge, Halcon::HTuple *Amplitude, Halcon::HTuple *FuzzyScore, Halcon::HTuple *Distance) const;
  // Extract straight edge pairs perpendicular to a rectangle or annular arc.
  virtual HTuple MeasurePairs(const HImage &Image, const Halcon::HTuple &Sigma, const Halcon::HTuple &Threshold, const Halcon::HTuple &Transition, const Halcon::HTuple &Select, Halcon::HTuple *ColumnEdgeFirst, Halcon::HTuple *AmplitudeFirst, Halcon::HTuple *RowEdgeSecond, Halcon::HTuple *ColumnEdgeSecond, Halcon::HTuple *AmplitudeSecond, Halcon::HTuple *IntraDistance, Halcon::HTuple *InterDistance) const;
  // Extract straight edge pairs perpendicular to a rectangle or annular arc.
  virtual HTuple MeasurePairs(const HImage &Image, double Sigma, double Threshold, const char *Transition, const char *Select, Halcon::HTuple *ColumnEdgeFirst, Halcon::HTuple *AmplitudeFirst, Halcon::HTuple *RowEdgeSecond, Halcon::HTuple *ColumnEdgeSecond, Halcon::HTuple *AmplitudeSecond, Halcon::HTuple *IntraDistance, Halcon::HTuple *InterDistance) const;
  // Extract straight edges perpendicular to a rectangle or annular arc.
  virtual HTuple MeasurePos(const HImage &Image, const Halcon::HTuple &Sigma, const Halcon::HTuple &Threshold, const Halcon::HTuple &Transition, const Halcon::HTuple &Select, Halcon::HTuple *ColumnEdge, Halcon::HTuple *Amplitude, Halcon::HTuple *Distance) const;
  // Extract straight edges perpendicular to a rectangle or annular arc.
  virtual HTuple MeasurePos(const HImage &Image, double Sigma, double Threshold, const char *Transition, const char *Select, Halcon::HTuple *ColumnEdge, Halcon::HTuple *Amplitude, Halcon::HTuple *Distance) const;
  // Translate a measure object.
  virtual void TranslateMeasure(const Halcon::HTuple &Row, const Halcon::HTuple &Column) const;
  // Translate a measure object.
  virtual void TranslateMeasure(double Row, double Column) const;
  // Prepare the extraction of straight edges perpendicular to an annular arc.
  virtual void GenMeasureArc(const Halcon::HTuple &CenterRow, const Halcon::HTuple &CenterCol, const Halcon::HTuple &Radius, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &AnnulusRadius, const Halcon::HTuple &Width, const Halcon::HTuple &Height, const Halcon::HTuple &Interpolation);
  // Prepare the extraction of straight edges perpendicular to an annular arc.
  virtual void GenMeasureArc(double CenterRow, double CenterCol, double Radius, double AngleStart, double AngleExtent, double AnnulusRadius, Hlong Width, Hlong Height, const char *Interpolation);
  // Prepare the extraction of straight edges perpendicular to a rectangle.
  virtual void GenMeasureRectangle2(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Phi, const Halcon::HTuple &Length1, const Halcon::HTuple &Length2, const Halcon::HTuple &Width, const Halcon::HTuple &Height, const Halcon::HTuple &Interpolation);
  // Prepare the extraction of straight edges perpendicular to a rectangle.
  virtual void GenMeasureRectangle2(double Row, double Column, double Phi, double Length1, double Length2, Hlong Width, Hlong Height, const char *Interpolation);
};

}

#endif
