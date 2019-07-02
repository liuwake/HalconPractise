/*****************************************************************************
 * HShapeModel.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HShapeModel
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_SHAPE_MODEL_H
#define H_SHAPE_MODEL_H

#include "HCPPToolRef.h"

namespace Halcon {


class LIntExport HShapeModel: public HToolBase
{
  friend class HImage;
  friend class HXLDCont;
  friend class HXLDContArray;  
  
public:
  
  // Tool-specific functional class constructors
  
  HShapeModel(
          const HImage &Template, 
          const HTuple &NumLevels, 
          const HTuple &AngleStart, 
          const HTuple &AngleExtent, 
          const HTuple &AngleStep, 
          const HTuple &Optimization, 
          const HTuple &Metric, 
          const HTuple &Contrast, 
          const HTuple &MinContrast);
          
  HShapeModel(
          const HImage &Template, 
          Hlong         NumLevels, 
          double        AngleStart, 
          double        AngleExtent, 
          double        AngleStep, 
          const char   *Optimization = "none", 
          const char   *Metric = "use_polarity", 
          Hlong         Contrast = 30, 
          Hlong         MinContrast = 10);

  HShapeModel(
          const HImage &Template, 
          const HTuple &NumLevels, 
          const HTuple &AngleStart, 
          const HTuple &AngleExtent, 
          const HTuple &AngleStep, 
          const HTuple &ScaleMin, 
          const HTuple &ScaleMax, 
          const HTuple &ScaleStep, 
          const HTuple &Optimization, 
          const HTuple &Metric, 
          const HTuple &Contrast, 
          const HTuple &MinContrast);

  HShapeModel(
          const HImage &Template, 
          Hlong         NumLevels, 
          double        AngleStart, 
          double        AngleExtent, 
          double        AngleStep, 
          double        ScaleMin, 
          double        ScaleMax, 
          double        ScaleStep, 
          const char   *Optimization = "none", 
          const char   *Metric = "use_polarity", 
          Hlong         Contrast = 30, 
          Hlong         MinContrast = 10);

  HShapeModel(
          const HImage &Template, 
          const HTuple &NumLevels, 
          const HTuple &AngleStart, 
          const HTuple &AngleExtent, 
          const HTuple &AngleStep, 
          const HTuple &ScaleRMin, 
          const HTuple &ScaleRMax, 
          const HTuple &ScaleRStep, 
          const HTuple &ScaleCMin, 
          const HTuple &ScaleCMax, 
          const HTuple &ScaleCStep, 
          const HTuple &Optimization, 
          const HTuple &Metric, 
          const HTuple &Contrast, 
          const HTuple &MinContrast);

  HShapeModel(
          const HImage &Template, 
          Hlong         NumLevels, 
          double        AngleStart, 
          double        AngleExtent, 
          double        AngleStep, 
          double        ScaleRMin, 
          double        ScaleRMax, 
          double        ScaleRStep, 
          double        ScaleCMin, 
          double        ScaleCMax, 
          double        ScaleCStep, 
          const char   *Optimization = "none", 
          const char   *Metric = "use_polarity", 
          Hlong         Contrast = 30, 
          Hlong         MinContrast = 10);

  // Common tool class management functionality

  HShapeModel();
  HShapeModel(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Deserialize a serialized shape model.
  virtual void DeserializeShapeModel(const Halcon::HSerializedItem &SerializedItemHandle);
  // Read a shape model from a file.
  virtual void ReadShapeModel(const Halcon::HTuple &FileName);
  // Read a shape model from a file.
  virtual void ReadShapeModel(const char *FileName);
  // Serialize a shape model.
  virtual HSerializedItem SerializeShapeModel() const;
  // Write a shape model to a file.
  virtual void WriteShapeModel(const Halcon::HTuple &FileName) const;
  // Write a shape model to a file.
  virtual void WriteShapeModel(const char *FileName) const;
  // Return the contour representation of a shape model.
  virtual HXLDContArray GetShapeModelContours(const Halcon::HTuple &Level) const;
  // Return the contour representation of a shape model.
  virtual HXLDContArray GetShapeModelContours(Hlong Level) const;
  // Return the parameters of a shape model.
  virtual Hlong GetShapeModelParams(Halcon::HTuple *AngleStart, Halcon::HTuple *AngleExtent, Halcon::HTuple *AngleStep, Halcon::HTuple *ScaleMin, Halcon::HTuple *ScaleMax, Halcon::HTuple *ScaleStep, Halcon::HTuple *Metric, Halcon::HTuple *MinContrast) const;
  // Return the parameters of a shape model.
  virtual Hlong GetShapeModelParams(double *AngleStart, double *AngleExtent, double *AngleStep, double *ScaleMin, double *ScaleMax, double *ScaleStep, char *Metric, Hlong *MinContrast) const;
  // Return the origin (reference point) of a shape model.
  virtual double GetShapeModelOrigin(Halcon::HTuple *Column) const;
  // Return the origin (reference point) of a shape model.
  virtual double GetShapeModelOrigin(double *Column) const;
  // Set the origin (reference point) of a shape model.
  virtual void SetShapeModelOrigin(const Halcon::HTuple &Row, const Halcon::HTuple &Column) const;
  // Set the origin (reference point) of a shape model.
  virtual void SetShapeModelOrigin(double Row, double Column) const;
  // Find the best matches of multiple anisotropic scale invariant shape
  // models.
  virtual HTuple FindAnisoShapeModels(const HImageArray &Image, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &ScaleRMin, const Halcon::HTuple &ScaleRMax, const Halcon::HTuple &ScaleCMin, const Halcon::HTuple &ScaleCMax, const Halcon::HTuple &MinScore, const Halcon::HTuple &NumMatches, const Halcon::HTuple &MaxOverlap, const Halcon::HTuple &SubPixel, const Halcon::HTuple &NumLevels, const Halcon::HTuple &Greediness, Halcon::HTuple *Column, Halcon::HTuple *Angle, Halcon::HTuple *ScaleR, Halcon::HTuple *ScaleC, Halcon::HTuple *Score, Halcon::HTuple *Model) const;
  // Find the best matches of multiple anisotropic scale invariant shape
  // models.
  virtual HTuple FindAnisoShapeModels(const HImageArray &Image, double AngleStart, double AngleExtent, double ScaleRMin, double ScaleRMax, double ScaleCMin, double ScaleCMax, double MinScore, Hlong NumMatches, double MaxOverlap, const char *SubPixel, Hlong NumLevels, double Greediness, Halcon::HTuple *Column, Halcon::HTuple *Angle, Halcon::HTuple *ScaleR, Halcon::HTuple *ScaleC, Halcon::HTuple *Score, Halcon::HTuple *Model) const;
  // Find the best matches of multiple scale invariant shape models.
  virtual HTuple FindScaledShapeModels(const HImageArray &Image, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &ScaleMin, const Halcon::HTuple &ScaleMax, const Halcon::HTuple &MinScore, const Halcon::HTuple &NumMatches, const Halcon::HTuple &MaxOverlap, const Halcon::HTuple &SubPixel, const Halcon::HTuple &NumLevels, const Halcon::HTuple &Greediness, Halcon::HTuple *Column, Halcon::HTuple *Angle, Halcon::HTuple *Scale, Halcon::HTuple *Score, Halcon::HTuple *Model) const;
  // Find the best matches of multiple scale invariant shape models.
  virtual HTuple FindScaledShapeModels(const HImageArray &Image, double AngleStart, double AngleExtent, double ScaleMin, double ScaleMax, double MinScore, Hlong NumMatches, double MaxOverlap, const char *SubPixel, Hlong NumLevels, double Greediness, Halcon::HTuple *Column, Halcon::HTuple *Angle, Halcon::HTuple *Scale, Halcon::HTuple *Score, Halcon::HTuple *Model) const;
  // Find the best matches of multiple shape models.
  virtual HTuple FindShapeModels(const HImageArray &Image, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &MinScore, const Halcon::HTuple &NumMatches, const Halcon::HTuple &MaxOverlap, const Halcon::HTuple &SubPixel, const Halcon::HTuple &NumLevels, const Halcon::HTuple &Greediness, Halcon::HTuple *Column, Halcon::HTuple *Angle, Halcon::HTuple *Score, Halcon::HTuple *Model) const;
  // Find the best matches of multiple shape models.
  virtual HTuple FindShapeModels(const HImageArray &Image, double AngleStart, double AngleExtent, double MinScore, Hlong NumMatches, double MaxOverlap, const char *SubPixel, Hlong NumLevels, double Greediness, Halcon::HTuple *Column, Halcon::HTuple *Angle, Halcon::HTuple *Score, Halcon::HTuple *Model) const;
  // Find the best matches of an anisotropic scale invariant shape model
  // in an image.
  virtual HTuple FindAnisoShapeModel(const HImage &Image, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &ScaleRMin, const Halcon::HTuple &ScaleRMax, const Halcon::HTuple &ScaleCMin, const Halcon::HTuple &ScaleCMax, const Halcon::HTuple &MinScore, const Halcon::HTuple &NumMatches, const Halcon::HTuple &MaxOverlap, const Halcon::HTuple &SubPixel, const Halcon::HTuple &NumLevels, const Halcon::HTuple &Greediness, Halcon::HTuple *Column, Halcon::HTuple *Angle, Halcon::HTuple *ScaleR, Halcon::HTuple *ScaleC, Halcon::HTuple *Score) const;
  // Find the best matches of an anisotropic scale invariant shape model
  // in an image.
  virtual HTuple FindAnisoShapeModel(const HImage &Image, double AngleStart, double AngleExtent, double ScaleRMin, double ScaleRMax, double ScaleCMin, double ScaleCMax, double MinScore, Hlong NumMatches, double MaxOverlap, const char *SubPixel, Hlong NumLevels, double Greediness, Halcon::HTuple *Column, Halcon::HTuple *Angle, Halcon::HTuple *ScaleR, Halcon::HTuple *ScaleC, Halcon::HTuple *Score) const;
  // Find the best matches of a scale invariant shape model in an image.
  virtual HTuple FindScaledShapeModel(const HImage &Image, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &ScaleMin, const Halcon::HTuple &ScaleMax, const Halcon::HTuple &MinScore, const Halcon::HTuple &NumMatches, const Halcon::HTuple &MaxOverlap, const Halcon::HTuple &SubPixel, const Halcon::HTuple &NumLevels, const Halcon::HTuple &Greediness, Halcon::HTuple *Column, Halcon::HTuple *Angle, Halcon::HTuple *Scale, Halcon::HTuple *Score) const;
  // Find the best matches of a scale invariant shape model in an image.
  virtual HTuple FindScaledShapeModel(const HImage &Image, double AngleStart, double AngleExtent, double ScaleMin, double ScaleMax, double MinScore, Hlong NumMatches, double MaxOverlap, const char *SubPixel, Hlong NumLevels, double Greediness, Halcon::HTuple *Column, Halcon::HTuple *Angle, Halcon::HTuple *Scale, Halcon::HTuple *Score) const;
  // Find the best matches of a shape model in an image.
  virtual HTuple FindShapeModel(const HImage &Image, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &MinScore, const Halcon::HTuple &NumMatches, const Halcon::HTuple &MaxOverlap, const Halcon::HTuple &SubPixel, const Halcon::HTuple &NumLevels, const Halcon::HTuple &Greediness, Halcon::HTuple *Column, Halcon::HTuple *Angle, Halcon::HTuple *Score) const;
  // Find the best matches of a shape model in an image.
  virtual HTuple FindShapeModel(const HImage &Image, double AngleStart, double AngleExtent, double MinScore, Hlong NumMatches, double MaxOverlap, const char *SubPixel, Hlong NumLevels, double Greediness, Halcon::HTuple *Column, Halcon::HTuple *Angle, Halcon::HTuple *Score) const;
  // Set the metric of a shape model that was created from XLD contours.
  virtual void SetShapeModelMetric(const HImage &Image, const Halcon::HTuple &HomMat2D, const Halcon::HTuple &Metric) const;
  // Set selected parameters of the shape model.
  virtual void SetShapeModelParam(const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues) const;
  // Prepare a shape model for anisotropic scale invariant matching
  // from XLD contours.
  virtual void CreateAnisoShapeModelXld(const HXLDContArray &Contours, const Halcon::HTuple &NumLevels, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &AngleStep, const Halcon::HTuple &ScaleRMin, const Halcon::HTuple &ScaleRMax, const Halcon::HTuple &ScaleRStep, const Halcon::HTuple &ScaleCMin, const Halcon::HTuple &ScaleCMax, const Halcon::HTuple &ScaleCStep, const Halcon::HTuple &Optimization, const Halcon::HTuple &Metric, const Halcon::HTuple &MinContrast);
  // Prepare a shape model for anisotropic scale invariant matching
  // from XLD contours.
  virtual void CreateAnisoShapeModelXld(const HXLDContArray &Contours, Hlong NumLevels, double AngleStart, double AngleExtent, double AngleStep, double ScaleRMin, double ScaleRMax, double ScaleRStep, double ScaleCMin, double ScaleCMax, double ScaleCStep, const char *Optimization, const char *Metric, Hlong MinContrast);
  // Prepare a shape model for scale invariant matching from XLD contours.
  virtual void CreateScaledShapeModelXld(const HXLDContArray &Contours, const Halcon::HTuple &NumLevels, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &AngleStep, const Halcon::HTuple &ScaleMin, const Halcon::HTuple &ScaleMax, const Halcon::HTuple &ScaleStep, const Halcon::HTuple &Optimization, const Halcon::HTuple &Metric, const Halcon::HTuple &MinContrast);
  // Prepare a shape model for scale invariant matching from XLD contours.
  virtual void CreateScaledShapeModelXld(const HXLDContArray &Contours, Hlong NumLevels, double AngleStart, double AngleExtent, double AngleStep, double ScaleMin, double ScaleMax, double ScaleStep, const char *Optimization, const char *Metric, Hlong MinContrast);
  // Prepare a shape model for matching from XLD contours.
  virtual void CreateShapeModelXld(const HXLDContArray &Contours, const Halcon::HTuple &NumLevels, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &AngleStep, const Halcon::HTuple &Optimization, const Halcon::HTuple &Metric, const Halcon::HTuple &MinContrast);
  // Prepare a shape model for matching from XLD contours.
  virtual void CreateShapeModelXld(const HXLDContArray &Contours, Hlong NumLevels, double AngleStart, double AngleExtent, double AngleStep, const char *Optimization, const char *Metric, Hlong MinContrast);
  // Prepare a shape model for anisotropic scale invariant matching.
  virtual void CreateAnisoShapeModel(const HImage &Template, const Halcon::HTuple &NumLevels, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &AngleStep, const Halcon::HTuple &ScaleRMin, const Halcon::HTuple &ScaleRMax, const Halcon::HTuple &ScaleRStep, const Halcon::HTuple &ScaleCMin, const Halcon::HTuple &ScaleCMax, const Halcon::HTuple &ScaleCStep, const Halcon::HTuple &Optimization, const Halcon::HTuple &Metric, const Halcon::HTuple &Contrast, const Halcon::HTuple &MinContrast);
  // Prepare a shape model for anisotropic scale invariant matching.
  virtual void CreateAnisoShapeModel(const HImage &Template, Hlong NumLevels, double AngleStart, double AngleExtent, double AngleStep, double ScaleRMin, double ScaleRMax, double ScaleRStep, double ScaleCMin, double ScaleCMax, double ScaleCStep, const char *Optimization, const char *Metric, Hlong Contrast, Hlong MinContrast);
  // Prepare a shape model for scale invariant matching.
  virtual void CreateScaledShapeModel(const HImage &Template, const Halcon::HTuple &NumLevels, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &AngleStep, const Halcon::HTuple &ScaleMin, const Halcon::HTuple &ScaleMax, const Halcon::HTuple &ScaleStep, const Halcon::HTuple &Optimization, const Halcon::HTuple &Metric, const Halcon::HTuple &Contrast, const Halcon::HTuple &MinContrast);
  // Prepare a shape model for scale invariant matching.
  virtual void CreateScaledShapeModel(const HImage &Template, Hlong NumLevels, double AngleStart, double AngleExtent, double AngleStep, double ScaleMin, double ScaleMax, double ScaleStep, const char *Optimization, const char *Metric, Hlong Contrast, Hlong MinContrast);
  // Prepare a shape model for matching.
  virtual void CreateShapeModel(const HImage &Template, const Halcon::HTuple &NumLevels, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &AngleStep, const Halcon::HTuple &Optimization, const Halcon::HTuple &Metric, const Halcon::HTuple &Contrast, const Halcon::HTuple &MinContrast);
  // Prepare a shape model for matching.
  virtual void CreateShapeModel(const HImage &Template, Hlong NumLevels, double AngleStart, double AngleExtent, double AngleStep, const char *Optimization, const char *Metric, Hlong Contrast, Hlong MinContrast);
};

}

#endif
