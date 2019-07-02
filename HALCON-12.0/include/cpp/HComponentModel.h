/*****************************************************************************
 * HComponentModel.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HComponentModel
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_COMPONENT_MODEL_H
#define H_COMPONENT_MODEL_H


#include "HCPPToolRef.h"


namespace Halcon {


class LIntExport HComponentModel: public HToolBase 
{
  friend class HComponentTraining;
  friend class HImage;
  
public:

  // Tool-specific functional class constructors

  HComponentModel(
          const HImage &ModelImage, 
          const HRegionArray &ComponentRegions, 
          const HTuple &VariationRow,
          const HTuple &VariationColumn,
          const HTuple &VariationAngle,
          const HTuple &AngleStart,
          const HTuple &AngleExtent, 
          const HTuple &ContrastLowComp,
          const HTuple &ContrastHighComp,
          const HTuple &MinSizeComp,
          const HTuple &MinContrastComp,
          const HTuple &MinScoreComp,
          const HTuple &NumLevelsComp,
          const HTuple &AngleStepComp,
          const HTuple &OptimizationComp,
          const HTuple &MetricComp,
          const HTuple &PregenerationComp,
          HTuple *RootRanking);
          
  HComponentModel(
          const HImage &ModelImage, 
          const HRegionArray &ComponentRegions, 
          const Hlong VariationRow,
          const Hlong VariationColumn,
          const double VariationAngle,
          const double AngleStart,
          const double AngleExtent, 
          const Hlong ContrastLowComp,
          const Hlong ContrastHighComp,
          const Hlong MinSizeComp,
          const Hlong MinContrastComp,
          const double MinScoreComp,
          const Hlong NumLevelsComp,
          const double AngleStepComp,
          const char *OptimizationComp,
          const char *MetricComp,
          const char *PregenerationComp,
          HTuple *RootRanking);
          
  HComponentModel(
          const HComponentTraining &ComponentTrainingID,
          const HTuple &AngleStart,
          const HTuple &AngleExtent,
          const HTuple &MinContrastComp,
          const HTuple &MinScoreComp,
          const HTuple &NumLevelsComp,
          const HTuple &AngleStepComp,
          const HTuple &OptimizationComp,
          const HTuple &MetricComp,
          const HTuple &PregenerationComp,
          HTuple *RootRanking);
          
  HComponentModel(
          const HComponentTraining &ComponentTrainingID,
          const double AngleStart,
          const double AngleExtent,
          const Hlong MinContrastComp,
          const double MinScoreComp,
          const Hlong NumLevelsComp,
          const double AngleStepComp,
          const char *OptimizationComp,
          const char *MetricComp,
          const char *PregenerationComp,
          HTuple *RootRanking);


  // Common tool class management functionality

  HComponentModel();
  HComponentModel(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Return the components of a found instance of a component model.
  virtual HRegionArray GetFoundComponentModel(const Halcon::HTuple &ModelStart, const Halcon::HTuple &ModelEnd, const Halcon::HTuple &RowComp, const Halcon::HTuple &ColumnComp, const Halcon::HTuple &AngleComp, const Halcon::HTuple &ScoreComp, const Halcon::HTuple &ModelComp, const Halcon::HTuple &ModelMatch, const Halcon::HTuple &MarkOrientation, Halcon::HTuple *RowCompInst, Halcon::HTuple *ColumnCompInst, Halcon::HTuple *AngleCompInst, Halcon::HTuple *ScoreCompInst) const;
  // Return the components of a found instance of a component model.
  virtual HRegionArray GetFoundComponentModel(const Halcon::HTuple &ModelStart, const Halcon::HTuple &ModelEnd, const Halcon::HTuple &RowComp, const Halcon::HTuple &ColumnComp, const Halcon::HTuple &AngleComp, const Halcon::HTuple &ScoreComp, const Halcon::HTuple &ModelComp, const Halcon::HTuple &ModelMatch, const Halcon::HTuple &MarkOrientation, double *RowCompInst, double *ColumnCompInst, double *AngleCompInst, double *ScoreCompInst) const;
  // Return the components of a found instance of a component model.
  virtual HRegionArray GetFoundComponentModel(Hlong ModelStart, Hlong ModelEnd, double RowComp, double ColumnComp, double AngleComp, double ScoreComp, Hlong ModelComp, Hlong ModelMatch, const char *MarkOrientation, Halcon::HTuple *RowCompInst, Halcon::HTuple *ColumnCompInst, Halcon::HTuple *AngleCompInst, Halcon::HTuple *ScoreCompInst) const;
  // Return the components of a found instance of a component model.
  virtual HRegionArray GetFoundComponentModel(Hlong ModelStart, Hlong ModelEnd, double RowComp, double ColumnComp, double AngleComp, double ScoreComp, Hlong ModelComp, Hlong ModelMatch, const char *MarkOrientation, double *RowCompInst, double *ColumnCompInst, double *AngleCompInst, double *ScoreCompInst) const;
  // Find the best matches of a component model in an image.
  virtual HTuple FindComponentModel(const HImage &Image, const Halcon::HTuple &RootComponent, const Halcon::HTuple &AngleStartRoot, const Halcon::HTuple &AngleExtentRoot, const Halcon::HTuple &MinScore, const Halcon::HTuple &NumMatches, const Halcon::HTuple &MaxOverlap, const Halcon::HTuple &IfRootNotFound, const Halcon::HTuple &IfComponentNotFound, const Halcon::HTuple &PosePrediction, const Halcon::HTuple &MinScoreComp, const Halcon::HTuple &SubPixelComp, const Halcon::HTuple &NumLevelsComp, const Halcon::HTuple &GreedinessComp, Halcon::HTuple *ModelEnd, Halcon::HTuple *Score, Halcon::HTuple *RowComp, Halcon::HTuple *ColumnComp, Halcon::HTuple *AngleComp, Halcon::HTuple *ScoreComp, Halcon::HTuple *ModelComp) const;
  // Find the best matches of a component model in an image.
  virtual Hlong FindComponentModel(const HImage &Image, const Halcon::HTuple &RootComponent, const Halcon::HTuple &AngleStartRoot, const Halcon::HTuple &AngleExtentRoot, const Halcon::HTuple &MinScore, const Halcon::HTuple &NumMatches, const Halcon::HTuple &MaxOverlap, const Halcon::HTuple &IfRootNotFound, const Halcon::HTuple &IfComponentNotFound, const Halcon::HTuple &PosePrediction, const Halcon::HTuple &MinScoreComp, const Halcon::HTuple &SubPixelComp, const Halcon::HTuple &NumLevelsComp, const Halcon::HTuple &GreedinessComp, Hlong *ModelEnd, double *Score, double *RowComp, double *ColumnComp, double *AngleComp, double *ScoreComp, Hlong *ModelComp) const;
  // Find the best matches of a component model in an image.
  virtual HTuple FindComponentModel(const HImage &Image, Hlong RootComponent, double AngleStartRoot, double AngleExtentRoot, double MinScore, Hlong NumMatches, double MaxOverlap, const char *IfRootNotFound, const char *IfComponentNotFound, const char *PosePrediction, double MinScoreComp, const char *SubPixelComp, Hlong NumLevelsComp, double GreedinessComp, Halcon::HTuple *ModelEnd, Halcon::HTuple *Score, Halcon::HTuple *RowComp, Halcon::HTuple *ColumnComp, Halcon::HTuple *AngleComp, Halcon::HTuple *ScoreComp, Halcon::HTuple *ModelComp) const;
  // Find the best matches of a component model in an image.
  virtual Hlong FindComponentModel(const HImage &Image, Hlong RootComponent, double AngleStartRoot, double AngleExtentRoot, double MinScore, Hlong NumMatches, double MaxOverlap, const char *IfRootNotFound, const char *IfComponentNotFound, const char *PosePrediction, double MinScoreComp, const char *SubPixelComp, Hlong NumLevelsComp, double GreedinessComp, Hlong *ModelEnd, double *Score, double *RowComp, double *ColumnComp, double *AngleComp, double *ScoreComp, Hlong *ModelComp) const;
  // Return the search tree of a component model.
  virtual HRegion GetComponentModelTree(HRegionArray *Relations, const Halcon::HTuple &RootComponent, const Halcon::HTuple &Image, Halcon::HTuple *StartNode, Halcon::HTuple *EndNode, Halcon::HTuple *Row, Halcon::HTuple *Column, Halcon::HTuple *Phi, Halcon::HTuple *Length1, Halcon::HTuple *Length2, Halcon::HTuple *AngleStart, Halcon::HTuple *AngleExtent) const;
  // Return the search tree of a component model.
  virtual HRegion GetComponentModelTree(HRegionArray *Relations, const Halcon::HTuple &RootComponent, const Halcon::HTuple &Image, Hlong *StartNode, Hlong *EndNode, double *Row, double *Column, double *Phi, double *Length1, double *Length2, double *AngleStart, double *AngleExtent) const;
  // Return the parameters of a component model.
  virtual HTuple GetComponentModelParams(Halcon::HTuple *RootRanking, Halcon::HTuple *ShapeModelIDs) const;
  // Return the parameters of a component model.
  virtual double GetComponentModelParams(Hlong *RootRanking, Hlong *ShapeModelIDs) const;
  // Deserialize a serialized component model.
  virtual void DeserializeComponentModel(const Halcon::HSerializedItem &SerializedItemHandle);
  // Serialize a component model.
  virtual HSerializedItem SerializeComponentModel() const;
  // Read a component model from a file.
  virtual void ReadComponentModel(const Halcon::HTuple &FileName);
  // Read a component model from a file.
  virtual void ReadComponentModel(const char *FileName);
  // Write a component model to a file.
  virtual void WriteComponentModel(const Halcon::HTuple &FileName) const;
  // Write a component model to a file.
  virtual void WriteComponentModel(const char *FileName) const;
  // Prepare a component model for matching based on explicitly specified
  // components and relations.
  virtual HTuple CreateComponentModel(const HImage &ModelImage, const HRegionArray &ComponentRegions, const Halcon::HTuple &VariationRow, const Halcon::HTuple &VariationColumn, const Halcon::HTuple &VariationAngle, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &ContrastLowComp, const Halcon::HTuple &ContrastHighComp, const Halcon::HTuple &MinSizeComp, const Halcon::HTuple &MinContrastComp, const Halcon::HTuple &MinScoreComp, const Halcon::HTuple &NumLevelsComp, const Halcon::HTuple &AngleStepComp, const Halcon::HTuple &OptimizationComp, const Halcon::HTuple &MetricComp, const Halcon::HTuple &PregenerationComp);
  // Prepare a component model for matching based on explicitly specified
  // components and relations.
  virtual HTuple CreateComponentModel(const HImage &ModelImage, const HRegionArray &ComponentRegions, Hlong VariationRow, Hlong VariationColumn, double VariationAngle, double AngleStart, double AngleExtent, Hlong ContrastLowComp, Hlong ContrastHighComp, Hlong MinSizeComp, Hlong MinContrastComp, double MinScoreComp, Hlong NumLevelsComp, double AngleStepComp, const char *OptimizationComp, const char *MetricComp, const char *PregenerationComp);
  // Prepare a component model for matching based on trained components.
  virtual HTuple CreateTrainedComponentModel(const Halcon::HComponentTraining &ComponentTrainingID, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &MinContrastComp, const Halcon::HTuple &MinScoreComp, const Halcon::HTuple &NumLevelsComp, const Halcon::HTuple &AngleStepComp, const Halcon::HTuple &OptimizationComp, const Halcon::HTuple &MetricComp, const Halcon::HTuple &PregenerationComp);
  // Prepare a component model for matching based on trained components.
  virtual HTuple CreateTrainedComponentModel(const Halcon::HComponentTraining &ComponentTrainingID, double AngleStart, double AngleExtent, Hlong MinContrastComp, double MinScoreComp, Hlong NumLevelsComp, double AngleStepComp, const char *OptimizationComp, const char *MetricComp, const char *PregenerationComp);
};

}

#endif
