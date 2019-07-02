/*****************************************************************************
 * HImageArray.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Types for Halcon-images arrays
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_IMAGE_ARRAY_H
#define H_IMAGE_ARRAY_H


namespace Halcon {


/****************************************************************************/
/*                             HImageArray                                  */
/****************************************************************************/
class LIntExport HImageArray: public HObjectArray {
public:
  HImageArray(void) : array(NULL) {}
  HImageArray(Hkey *key, Hlong num);
  HImageArray(const Hobject &obj);
  HImageArray(const HImage &image);
  HImageArray(const HImageArray &arr);
  ~HImageArray(void);
  HImageArray &operator = (const HImageArray &arr);
  
  // Tools
  virtual const char *HClassName(void) const;
  virtual const char *ClassName(void) const;
  virtual       INT4  ClassDBID(void) const {return IMAGE_ID;}
  virtual       Hkey  Key(Hlong i) const {return array[i].Key();}
  virtual    Hobject  ElemId(Hlong i) const {return array[i].Id();}
  virtual       void  CopyHImageArray(const HImageArray &in);
  virtual       void  Display(const HWindow &w) const;

  // Access und Manipulation
  HImage       &operator [] (Hlong index);
  HImage const &operator [] (Hlong index) const;
  HImageArray  operator () (Hlong min, Hlong max);
  HImageArray  &Append(const HImage &image);
  HImageArray  &Append(const HImageArray &images);
  virtual void SetKeys(Hkey *key, Hlong num);
  virtual void SetKeys(Hkey *key, Hlong num, Herror *err);
  virtual void DeleteArray(void);

private:
  HImage  *array;
  void    NewLength(Hlong new_num, Hlong old_num);
public:
  // Simulation of (linearly) motion blur.
  virtual HImage SimulateMotion(const Halcon::HTuple &Blurring, const Halcon::HTuple &Angle, const Halcon::HTuple &Type) const;
  // Simulation of (linearly) motion blur.
  virtual HImage SimulateMotion(double Blurring, Hlong Angle, Hlong Type) const;
  // Simulate an uniform out-of-focus blurring of an image.
  virtual HImageArray SimulateDefocus(const Halcon::HTuple &Blurring) const;
  // Simulate an uniform out-of-focus blurring of an image.
  virtual HImageArray SimulateDefocus(double Blurring) const;
  // Compare an image to a variation model.
  virtual HRegionArray CompareExtVariationModel(const Halcon::HVariationModel &ModelID, const Halcon::HTuple &Mode) const;
  // Compare an image to a variation model.
  virtual HRegionArray CompareExtVariationModel(const Halcon::HVariationModel &ModelID, const char *Mode) const;
  // Compare an image to a variation model.
  virtual HRegionArray CompareVariationModel(const Halcon::HVariationModel &ModelID) const;
  // Train a variation model.
  virtual void TrainVariationModel(const Halcon::HVariationModel &ModelID) const;
  // Receive an image over a socket connection.
  static HImageArray ReceiveImage(const Halcon::HSocket &Socket);
  // Send an image over a socket connection.
  virtual void SendImage(const Halcon::HSocket &Socket) const;
  // Compute the distance values for a rectified stereo image pair using
  // multigrid methods.
  virtual HImageArray BinocularDistanceMg(const HImageArray &ImageRect2, HImageArray *Score, const Halcon::HTuple &CamParamRect1, const Halcon::HTuple &CamParamRect2, const Halcon::HTuple &RelPoseRect, const Halcon::HTuple &GrayConstancy, const Halcon::HTuple &GradientConstancy, const Halcon::HTuple &Smoothness, const Halcon::HTuple &InitialGuess, const Halcon::HTuple &CalculateScore, const Halcon::HTuple &MGParamName, const Halcon::HTuple &MGParamValue) const;
  // Compute the disparities of a rectified stereo image pair using multigrid
  // methods.
  virtual HImageArray BinocularDisparityMg(const HImageArray &ImageRect2, HImageArray *Score, const Halcon::HTuple &GrayConstancy, const Halcon::HTuple &GradientConstancy, const Halcon::HTuple &Smoothness, const Halcon::HTuple &InitialGuess, const Halcon::HTuple &CalculateScore, const Halcon::HTuple &MGParamName, const Halcon::HTuple &MGParamValue) const;
  // Compute the projective rectification of weakly calibrated binocular
  // stereo images.
  static HImageArray GenBinocularProjRectification(HImageArray *Map2, const Halcon::HTuple &FMatrix, const Halcon::HTuple &CovFMat, const Halcon::HTuple &Width1, const Halcon::HTuple &Height1, const Halcon::HTuple &Width2, const Halcon::HTuple &Height2, const Halcon::HTuple &SubSampling, const Halcon::HTuple &Mapping, Halcon::HTuple *CovFMatRect, Halcon::HTuple *H1, Halcon::HTuple *H2);
  // Shade a height field.
  virtual HImageArray ShadeHeightField(const Halcon::HTuple &Slant, const Halcon::HTuple &Tilt, const Halcon::HTuple &Albedo, const Halcon::HTuple &Ambient, const Halcon::HTuple &Shadows) const;
  // Shade a height field.
  virtual HImageArray ShadeHeightField(double Slant, double Tilt, double Albedo, double Ambient, const char *Shadows) const;
  // Estimate the albedo of a surface and the amount of ambient light.
  virtual HTuple EstimateAlAm(Halcon::HTuple *Ambient) const;
  // Estimate the slant of a light source and the albedo of a surface.
  virtual HTuple EstimateSlAlZc(Halcon::HTuple *Albedo) const;
  // Estimate the slant of a light source and the albedo of a surface.
  virtual HTuple EstimateSlAlLr(Halcon::HTuple *Albedo) const;
  // Estimate the tilt of a light source.
  virtual HTuple EstimateTiltZc(void) const;
  // Estimate the tilt of a light source.
  virtual HTuple EstimateTiltLr(void) const;
  // Reconstruct a surface according to the photometric stereo technique.
  virtual HImage PhotometricStereo(HImage *Gradient, HImage *Albedo, const Halcon::HTuple &Slants, const Halcon::HTuple &Tilts, const Halcon::HTuple &ResultType, const Halcon::HTuple &ReconstructionMethod, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue) const;
  // Reconstruct a surface from a gray value image.
  virtual HImageArray SfsPentland(const Halcon::HTuple &Slant, const Halcon::HTuple &Tilt, const Halcon::HTuple &Albedo, const Halcon::HTuple &Ambient) const;
  // Reconstruct a surface from a gray value image.
  virtual HImageArray SfsPentland(double Slant, double Tilt, double Albedo, double Ambient) const;
  // Reconstruct a surface from a gray value image.
  virtual HImageArray SfsOrigLr(const Halcon::HTuple &Slant, const Halcon::HTuple &Tilt, const Halcon::HTuple &Albedo, const Halcon::HTuple &Ambient) const;
  // Reconstruct a surface from a gray value image.
  virtual HImageArray SfsOrigLr(double Slant, double Tilt, double Albedo, double Ambient) const;
  // Reconstruct a surface from a gray value image.
  virtual HImageArray SfsModLr(const Halcon::HTuple &Slant, const Halcon::HTuple &Tilt, const Halcon::HTuple &Albedo, const Halcon::HTuple &Ambient) const;
  // Reconstruct a surface from a gray value image.
  virtual HImageArray SfsModLr(double Slant, double Tilt, double Albedo, double Ambient) const;
  // Classify pixels using hyper-cuboids.
  virtual HRegionArray ClassNdimBox(const Halcon::HClassBox &ClassifHandle) const;
  // Classify pixels using hyper-spheres or hyper-cubes.
  virtual HRegionArray ClassNdimNorm(const Halcon::HTuple &Metric, const Halcon::HTuple &SingleMultiple, const Halcon::HTuple &Radius, const Halcon::HTuple &Center) const;
  // Classify pixels using hyper-spheres or hyper-cubes.
  virtual HRegionArray ClassNdimNorm(const char *Metric, const char *SingleMultiple, double Radius, double Center) const;
  // Segment an image using two-dimensional pixel classification.
  virtual HRegionArray Class2dimSup(const HImageArray &ImageRow, const HRegionArray &FeatureSpace) const;
  // Compare two images pixel by pixel.
  virtual HRegionArray CheckDifference(const HImageArray &Pattern, const Halcon::HTuple &Mode, const Halcon::HTuple &DiffLowerBound, const Halcon::HTuple &DiffUpperBound, const Halcon::HTuple &GrayOffset, const Halcon::HTuple &AddRow, const Halcon::HTuple &AddCol) const;
  // Compare two images pixel by pixel.
  virtual HRegionArray CheckDifference(const HImageArray &Pattern, const char *Mode, Hlong DiffLowerBound, Hlong DiffUpperBound, Hlong GrayOffset, Hlong AddRow, Hlong AddCol) const;
  // Perform a threshold segmentation for extracting characters.
  virtual HRegionArray CharThreshold(const HRegion &HistoRegion, const Halcon::HTuple &Sigma, const Halcon::HTuple &Percent, Halcon::HTuple *Threshold) const;
  // Perform a threshold segmentation for extracting characters.
  virtual HRegionArray CharThreshold(const HRegion &HistoRegion, double Sigma, double Percent, Halcon::HTuple *Threshold) const;
  // Extract regions with equal gray values from an image.
  virtual HRegionArray LabelToRegion(void) const;
  // Suppress non-maximum points on an edge.
  virtual HImageArray NonmaxSuppressionAmp(const Halcon::HTuple &Mode) const;
  // Suppress non-maximum points on an edge.
  virtual HImageArray NonmaxSuppressionAmp(const char *Mode) const;
  // Suppress non-maximum points on an edge using a direction image.
  virtual HImageArray NonmaxSuppressionDir(const HImageArray &ImgDir, const Halcon::HTuple &Mode) const;
  // Suppress non-maximum points on an edge using a direction image.
  virtual HImageArray NonmaxSuppressionDir(const HImageArray &ImgDir, const char *Mode) const;
  // Perform a hysteresis threshold operation on an image.
  virtual HRegionArray HysteresisThreshold(const Halcon::HTuple &Low, const Halcon::HTuple &High, const Halcon::HTuple &MaxLength) const;
  // Perform a hysteresis threshold operation on an image.
  virtual HRegionArray HysteresisThreshold(Hlong Low, Hlong High, Hlong MaxLength) const;
  // Segment an image using binary thresholding.
  virtual HRegionArray BinaryThreshold(const Halcon::HTuple &Method, const Halcon::HTuple &LightDark, Halcon::HTuple *UsedThreshold) const;
  // Segment an image using binary thresholding.
  virtual HRegionArray BinaryThreshold(const char *Method, const char *LightDark, Halcon::HTuple *UsedThreshold) const;
  // Segment an image using local thresholding.
  virtual HRegionArray LocalThreshold(const Halcon::HTuple &Method, const Halcon::HTuple &LightDark, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue) const;
  // Segment an image using local thresholding.
  virtual HRegionArray LocalThreshold(const char *Method, const char *LightDark, const char *GenParamName, Hlong GenParamValue) const;
  // Threshold an image by local mean and standard deviation analysis.
  virtual HRegionArray VarThreshold(const Halcon::HTuple &MaskWidth, const Halcon::HTuple &MaskHeight, const Halcon::HTuple &StdDevScale, const Halcon::HTuple &AbsThreshold, const Halcon::HTuple &LightDark) const;
  // Threshold an image by local mean and standard deviation analysis.
  virtual HRegionArray VarThreshold(Hlong MaskWidth, Hlong MaskHeight, double StdDevScale, double AbsThreshold, const char *LightDark) const;
  // Segment an image using a local threshold.
  virtual HRegionArray DynThreshold(const HImageArray &ThresholdImage, const Halcon::HTuple &Offset, const Halcon::HTuple &LightDark) const;
  // Segment an image using a local threshold.
  virtual HRegionArray DynThreshold(const HImageArray &ThresholdImage, double Offset, const char *LightDark) const;
  // Segment an image using global threshold.
  virtual HRegionArray Threshold(const Halcon::HTuple &MinGray, const Halcon::HTuple &MaxGray) const;
  // Segment an image using global threshold.
  virtual HRegionArray Threshold(double MinGray, double MaxGray) const;
  // Segment an image using regiongrowing for multi-channel images.
  virtual HRegionArray RegiongrowingN(const Halcon::HTuple &Metric, const Halcon::HTuple &MinTolerance, const Halcon::HTuple &MaxTolerance, const Halcon::HTuple &MinSize) const;
  // Segment an image using regiongrowing for multi-channel images.
  virtual HRegionArray RegiongrowingN(const char *Metric, double MinTolerance, double MaxTolerance, Hlong MinSize) const;
  // Segment an image using regiongrowing.
  virtual HRegionArray Regiongrowing(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Tolerance, const Halcon::HTuple &MinSize) const;
  // Segment an image using regiongrowing.
  virtual HRegionArray Regiongrowing(Hlong Row, Hlong Column, double Tolerance, Hlong MinSize) const;
  // Perform a regiongrowing using mean gray values.
  virtual HRegionArray RegiongrowingMean(const Halcon::HTuple &StartRows, const Halcon::HTuple &StartColumns, const Halcon::HTuple &Tolerance, const Halcon::HTuple &MinSize) const;
  // Perform a regiongrowing using mean gray values.
  virtual HRegionArray RegiongrowingMean(Hlong StartRows, Hlong StartColumns, double Tolerance, Hlong MinSize) const;
  // Extract watersheds and basins from an image.
  virtual HRegionArray Watersheds(HRegionArray *Watersheds) const;
  // Extract zero crossings from an image.
  virtual HRegionArray ZeroCrossing(void) const;
  // Threshold operator for signed images.
  virtual HRegionArray DualThreshold(const Halcon::HTuple &MinSize, const Halcon::HTuple &MinGray, const Halcon::HTuple &Threshold) const;
  // Threshold operator for signed images.
  virtual HRegionArray DualThreshold(Hlong MinSize, double MinGray, double Threshold) const;
  // Expand a region starting at a given line.
  virtual HRegionArray ExpandLine(const Halcon::HTuple &Coordinate, const Halcon::HTuple &ExpandType, const Halcon::HTuple &RowColumn, const Halcon::HTuple &Threshold) const;
  // Expand a region starting at a given line.
  virtual HRegionArray ExpandLine(Hlong Coordinate, const char *ExpandType, const char *RowColumn, double Threshold) const;
  // Detect all local minima in an image.
  virtual HRegionArray LocalMin(void) const;
  // Detect all gray value lowlands.
  virtual HRegionArray Lowlands(void) const;
  // Detect the centers of all gray value lowlands.
  virtual HRegionArray LowlandsCenter(void) const;
  // Detect all local maxima in an image.
  virtual HRegionArray LocalMax(void) const;
  // Detect all gray value plateaus.
  virtual HRegionArray Plateaus(void) const;
  // Detect the centers of all gray value plateaus.
  virtual HRegionArray PlateausCenter(void) const;
  // Segment an image using thresholds determined from its histogram.
  virtual HRegionArray AutoThreshold(const Halcon::HTuple &Sigma) const;
  // Segment an image using thresholds determined from its histogram.
  virtual HRegionArray AutoThreshold(double Sigma) const;
  // Segment an image using an automatically determined
  // threshold.
  virtual HRegionArray BinThreshold(void) const;
  // Fast thresholding of images using global thresholds.
  virtual HRegionArray FastThreshold(const Halcon::HTuple &MinGray, const Halcon::HTuple &MaxGray, const Halcon::HTuple &MinSize) const;
  // Fast thresholding of images using global thresholds.
  virtual HRegionArray FastThreshold(double MinGray, double MaxGray, Hlong MinSize) const;
  // Copy an image and allocate new memory for it.
  virtual HImageArray CopyImage(void) const;
  // Access the pointers of a colored image.
  virtual HTuple GetImagePointer3(Halcon::HTuple *PointerGreen, Halcon::HTuple *PointerBlue, Halcon::HTuple *Type, Halcon::HTuple *Width, Halcon::HTuple *Height) const;
  // Access the pointer of a channel.
  virtual HTuple GetImagePointer1(Halcon::HTuple *Type, Halcon::HTuple *Width, Halcon::HTuple *Height) const;
  // Return the type of an image.
  virtual HTuple GetImageType(void) const;
  // Return the size of an image.
  virtual HTuple GetImageSize(Halcon::HTuple *Height) const;
  // Verification of a pattern using an OCV tool.
  virtual HTuple DoOcvSimple(const Halcon::HOCV &OCVHandle, const Halcon::HTuple &PatternName, const Halcon::HTuple &AdaptPos, const Halcon::HTuple &AdaptSize, const Halcon::HTuple &AdaptAngle, const Halcon::HTuple &AdaptGray, const Halcon::HTuple &Threshold) const;
  // Verification of a pattern using an OCV tool.
  virtual HTuple DoOcvSimple(const Halcon::HOCV &OCVHandle, const char *PatternName, const char *AdaptPos, const char *AdaptSize, const char *AdaptAngle, const char *AdaptGray, double Threshold) const;
  // Training of an OCV tool.
  virtual void TraindOcvProj(const Halcon::HOCV &OCVHandle, const Halcon::HTuple &Name, const Halcon::HTuple &Mode) const;
  // Training of an OCV tool.
  virtual void TraindOcvProj(const Halcon::HOCV &OCVHandle, const char *Name, const char *Mode) const;
  // Cut out an image area relative to the domain.
  virtual HImageArray CropDomainRel(const Halcon::HTuple &Top, const Halcon::HTuple &Left, const Halcon::HTuple &Bottom, const Halcon::HTuple &Right) const;
  // Cut out an image area relative to the domain.
  virtual HImageArray CropDomainRel(Hlong Top, Hlong Left, Hlong Bottom, Hlong Right) const;
  // Write characters into a training file.
  virtual void WriteOcrTrainfImage(const Halcon::HTuple &Class, const Halcon::HTuple &TrainingFile) const;
  // Write characters into a training file.
  virtual void WriteOcrTrainfImage(const char *Class, const char *TrainingFile) const;
  // Read training specific characters from files and convert to images.
  static HImageArray ReadOcrTrainfSelect(const Halcon::HTuple &TrainingFile, const Halcon::HTuple &SearchNames, Halcon::HTuple *FoundNames);
  // Read training specific characters from files and convert to images.
  static HImageArray ReadOcrTrainfSelect(const char *TrainingFile, const char *SearchNames, Halcon::HTuple *FoundNames);
  // Read training characters from files and convert to images.
  static HImageArray ReadOcrTrainf(const Halcon::HTuple &TrainingFile, Halcon::HTuple *CharacterNames);
  // Read training characters from files and convert to images.
  static HImageArray ReadOcrTrainf(const char *TrainingFile, Halcon::HTuple *CharacterNames);
  // Perform a gray value bottom hat transformation on an image.
  virtual HImageArray GrayBothat(const HImage &SE) const;
  // Perform a gray value top hat transformation on an image.
  virtual HImageArray GrayTophat(const HImage &SE) const;
  // Perform a gray value closing on an image.
  virtual HImageArray GrayClosing(const HImage &SE) const;
  // Perform a gray value opening on an image.
  virtual HImageArray GrayOpening(const HImage &SE) const;
  // Perform a gray value dilation on an image.
  virtual HImageArray GrayDilation(const HImage &SE) const;
  // Perform a gray value erosion on an image.
  virtual HImageArray GrayErosion(const HImage &SE) const;
  // Find the best matches of multiple anisotropic scale invariant shape
  // models.
  virtual HTuple FindAnisoShapeModels(const Halcon::HTuple &ModelIDs, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &ScaleRMin, const Halcon::HTuple &ScaleRMax, const Halcon::HTuple &ScaleCMin, const Halcon::HTuple &ScaleCMax, const Halcon::HTuple &MinScore, const Halcon::HTuple &NumMatches, const Halcon::HTuple &MaxOverlap, const Halcon::HTuple &SubPixel, const Halcon::HTuple &NumLevels, const Halcon::HTuple &Greediness, Halcon::HTuple *Column, Halcon::HTuple *Angle, Halcon::HTuple *ScaleR, Halcon::HTuple *ScaleC, Halcon::HTuple *Score, Halcon::HTuple *Model) const;
  // Find the best matches of multiple anisotropic scale invariant shape
  // models.
  virtual HTuple FindAnisoShapeModels(Hlong ModelIDs, double AngleStart, double AngleExtent, double ScaleRMin, double ScaleRMax, double ScaleCMin, double ScaleCMax, double MinScore, Hlong NumMatches, double MaxOverlap, const char *SubPixel, Hlong NumLevels, double Greediness, Halcon::HTuple *Column, Halcon::HTuple *Angle, Halcon::HTuple *ScaleR, Halcon::HTuple *ScaleC, Halcon::HTuple *Score, Halcon::HTuple *Model) const;
  // Find the best matches of multiple scale invariant shape models.
  virtual HTuple FindScaledShapeModels(const Halcon::HTuple &ModelIDs, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &ScaleMin, const Halcon::HTuple &ScaleMax, const Halcon::HTuple &MinScore, const Halcon::HTuple &NumMatches, const Halcon::HTuple &MaxOverlap, const Halcon::HTuple &SubPixel, const Halcon::HTuple &NumLevels, const Halcon::HTuple &Greediness, Halcon::HTuple *Column, Halcon::HTuple *Angle, Halcon::HTuple *Scale, Halcon::HTuple *Score, Halcon::HTuple *Model) const;
  // Find the best matches of multiple scale invariant shape models.
  virtual HTuple FindScaledShapeModels(Hlong ModelIDs, double AngleStart, double AngleExtent, double ScaleMin, double ScaleMax, double MinScore, Hlong NumMatches, double MaxOverlap, const char *SubPixel, Hlong NumLevels, double Greediness, Halcon::HTuple *Column, Halcon::HTuple *Angle, Halcon::HTuple *Scale, Halcon::HTuple *Score, Halcon::HTuple *Model) const;
  // Find the best matches of multiple shape models.
  virtual HTuple FindShapeModels(const Halcon::HTuple &ModelIDs, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &MinScore, const Halcon::HTuple &NumMatches, const Halcon::HTuple &MaxOverlap, const Halcon::HTuple &SubPixel, const Halcon::HTuple &NumLevels, const Halcon::HTuple &Greediness, Halcon::HTuple *Column, Halcon::HTuple *Angle, Halcon::HTuple *Score, Halcon::HTuple *Model) const;
  // Find the best matches of multiple shape models.
  virtual HTuple FindShapeModels(Hlong ModelIDs, double AngleStart, double AngleExtent, double MinScore, Hlong NumMatches, double MaxOverlap, const char *SubPixel, Hlong NumLevels, double Greediness, Halcon::HTuple *Column, Halcon::HTuple *Angle, Halcon::HTuple *Score, Halcon::HTuple *Model) const;
  // Adopt new parameters that are used to create the model components into the
  // training result.
  virtual HRegionArray ClusterModelComponents(const Halcon::HComponentTraining &ComponentTrainingID, const Halcon::HTuple &AmbiguityCriterion, const Halcon::HTuple &MaxContourOverlap, const Halcon::HTuple &ClusterThreshold) const;
  // Adopt new parameters that are used to create the model components into the
  // training result.
  virtual HRegionArray ClusterModelComponents(const Halcon::HComponentTraining &ComponentTrainingID, const char *AmbiguityCriterion, double MaxContourOverlap, double ClusterThreshold) const;
  // Extract the initial components of a component model.
  virtual HRegionArray GenInitialComponents(const Halcon::HTuple &ContrastLow, const Halcon::HTuple &ContrastHigh, const Halcon::HTuple &MinSize, const Halcon::HTuple &Mode, const Halcon::HTuple &GenericName, const Halcon::HTuple &GenericValue) const;
  // Extract the initial components of a component model.
  virtual HRegionArray GenInitialComponents(Hlong ContrastLow, Hlong ContrastHigh, Hlong MinSize, const char *Mode, const char *GenericName, double GenericValue) const;
  // Convert one-channel images into a multichannel image
  virtual HImage ChannelsToImage(void) const;
  // Convert 7 images into a seven-channel image.
  virtual HImageArray Compose7(const HImageArray &Image2, const HImageArray &Image3, const HImageArray &Image4, const HImageArray &Image5, const HImageArray &Image6, const HImageArray &Image7) const;
  // Convert 6 images into a six-channel image.
  virtual HImageArray Compose6(const HImageArray &Image2, const HImageArray &Image3, const HImageArray &Image4, const HImageArray &Image5, const HImageArray &Image6) const;
  // Convert 5 images into a five-channel image.
  virtual HImageArray Compose5(const HImageArray &Image2, const HImageArray &Image3, const HImageArray &Image4, const HImageArray &Image5) const;
  // Convert 4 images into a four-channel image.
  virtual HImageArray Compose4(const HImageArray &Image2, const HImageArray &Image3, const HImageArray &Image4) const;
  // Convert 3 images into a three-channel image.
  virtual HImageArray Compose3(const HImageArray &Image2, const HImageArray &Image3) const;
  // Convert two images into a two-channel image.
  virtual HImageArray Compose2(const HImageArray &Image2) const;
  // Convert a seven-channel image into seven images.
  virtual HImageArray Decompose7(HImageArray *Image2, HImageArray *Image3, HImageArray *Image4, HImageArray *Image5, HImageArray *Image6, HImageArray *Image7) const;
  // Convert a six-channel image into six images.
  virtual HImageArray Decompose6(HImageArray *Image2, HImageArray *Image3, HImageArray *Image4, HImageArray *Image5, HImageArray *Image6) const;
  // Convert a five-channel image into five images.
  virtual HImageArray Decompose5(HImageArray *Image2, HImageArray *Image3, HImageArray *Image4, HImageArray *Image5) const;
  // Convert a four-channel image into four images.
  virtual HImageArray Decompose4(HImageArray *Image2, HImageArray *Image3, HImageArray *Image4) const;
  // Convert a three-channel image into three images.
  virtual HImageArray Decompose3(HImageArray *Image2, HImageArray *Image3) const;
  // Convert a two-channel image into two images.
  virtual HImageArray Decompose2(HImageArray *Image2) const;
  // Count channels of image.
  virtual HTuple CountChannels(void) const;
  // Tile multiple image objects into a large image with explicit
  // positioning information.
  virtual HImage TileImagesOffset(const Halcon::HTuple &OffsetRow, const Halcon::HTuple &OffsetCol, const Halcon::HTuple &Row1, const Halcon::HTuple &Col1, const Halcon::HTuple &Row2, const Halcon::HTuple &Col2, const Halcon::HTuple &Width, const Halcon::HTuple &Height) const;
  // Tile multiple image objects into a large image with explicit
  // positioning information.
  virtual HImage TileImagesOffset(Hlong OffsetRow, Hlong OffsetCol, Hlong Row1, Hlong Col1, Hlong Row2, Hlong Col2, Hlong Width, Hlong Height) const;
  // Tile multiple image objects into a large image.
  virtual HImage TileImages(const Halcon::HTuple &NumColumns, const Halcon::HTuple &TileOrder) const;
  // Tile multiple image objects into a large image.
  virtual HImage TileImages(Hlong NumColumns, const char *TileOrder) const;
  // Tile multiple images into a large image.
  virtual HImageArray TileChannels(const Halcon::HTuple &NumColumns, const Halcon::HTuple &TileOrder) const;
  // Tile multiple images into a large image.
  virtual HImageArray TileChannels(Hlong NumColumns, const char *TileOrder) const;
  // Cut out of defined gray values.
  virtual HImageArray CropDomain(void) const;
  // Cut out one or more rectangular image areas.
  virtual HImageArray CropRectangle1(const Halcon::HTuple &Row1, const Halcon::HTuple &Column1, const Halcon::HTuple &Row2, const Halcon::HTuple &Column2) const;
  // Cut out one or more rectangular image areas.
  virtual HImageArray CropRectangle1(Hlong Row1, Hlong Column1, Hlong Row2, Hlong Column2) const;
  // Cut out one or more rectangular image areas.
  virtual HImageArray CropPart(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Width, const Halcon::HTuple &Height) const;
  // Cut out one or more rectangular image areas.
  virtual HImageArray CropPart(Hlong Row, Hlong Column, Hlong Width, Hlong Height) const;
  // Change image size.
  virtual HImageArray ChangeFormat(const Halcon::HTuple &Width, const Halcon::HTuple &Height) const;
  // Change image size.
  virtual HImageArray ChangeFormat(Hlong Width, Hlong Height) const;
  // Change definition domain of an image.
  virtual HImageArray ChangeDomain(const HRegion &NewDomain) const;
  // Reduce the domain of an image to a rectangle.
  virtual HImageArray Rectangle1Domain(const Halcon::HTuple &Row1, const Halcon::HTuple &Column1, const Halcon::HTuple &Row2, const Halcon::HTuple &Column2) const;
  // Reduce the domain of an image to a rectangle.
  virtual HImageArray Rectangle1Domain(Hlong Row1, Hlong Column1, Hlong Row2, Hlong Column2) const;
  // Reduce the domain of an image.
  virtual HImageArray ReduceDomain(const HRegion &Region) const;
  // Expand the domain of an image to maximum.
  virtual HImageArray FullDomain(void) const;
  // Get the domain of an image.
  virtual HRegionArray GetDomain(void) const;
  // Displays images with several channels.
  virtual void DispChannel(const Halcon::HTuple &WindowHandle, const Halcon::HTuple &Channel) const;
  // Displays images with several channels.
  virtual void DispChannel(Hlong WindowHandle, Hlong Channel) const;
  // Filter an image using a Laws texture filter.
  virtual HImageArray TextureLaws(const Halcon::HTuple &FilterTypes, const Halcon::HTuple &Shift, const Halcon::HTuple &FilterSize) const;
  // Filter an image using a Laws texture filter.
  virtual HImageArray TextureLaws(const char *FilterTypes, Hlong Shift, Hlong FilterSize) const;
  // Calculate the standard deviation of gray values within rectangular windows.
  virtual HImageArray DeviationImage(const Halcon::HTuple &Width, const Halcon::HTuple &Height) const;
  // Calculate the standard deviation of gray values within rectangular windows.
  virtual HImageArray DeviationImage(Hlong Width, Hlong Height) const;
  // Calculate the entropy of gray values within a rectangular window.
  virtual HImageArray EntropyImage(const Halcon::HTuple &Width, const Halcon::HTuple &Height) const;
  // Calculate the entropy of gray values within a rectangular window.
  virtual HImageArray EntropyImage(Hlong Width, Hlong Height) const;
  // Perform an isotropic diffusion of an image.
  virtual HImageArray IsotropicDiffusion(const Halcon::HTuple &Sigma, const Halcon::HTuple &Iterations) const;
  // Perform an isotropic diffusion of an image.
  virtual HImageArray IsotropicDiffusion(double Sigma, Hlong Iterations) const;
  // Perform an anisotropic diffusion of an image.
  virtual HImageArray AnisotropicDiffusion(const Halcon::HTuple &Mode, const Halcon::HTuple &Contrast, const Halcon::HTuple &Theta, const Halcon::HTuple &Iterations) const;
  // Perform an anisotropic diffusion of an image.
  virtual HImageArray AnisotropicDiffusion(const char *Mode, double Contrast, double Theta, Hlong Iterations) const;
  // Smooth an image using various filters.
  virtual HImageArray SmoothImage(const Halcon::HTuple &Filter, const Halcon::HTuple &Alpha) const;
  // Smooth an image using various filters.
  virtual HImageArray SmoothImage(const char *Filter, double Alpha) const;
  // Non-linear smoothing with the sigma filter.
  virtual HImageArray SigmaImage(const Halcon::HTuple &MaskHeight, const Halcon::HTuple &MaskWidth, const Halcon::HTuple &Sigma) const;
  // Non-linear smoothing with the sigma filter.
  virtual HImageArray SigmaImage(Hlong MaskHeight, Hlong MaskWidth, Hlong Sigma) const;
  // Calculate the average of maximum and minimum inside any mask.
  virtual HImageArray MidrangeImage(const HRegion &Mask, const Halcon::HTuple &Margin) const;
  // Smooth an image with an arbitrary rank mask.
  virtual HImageArray TrimmedMean(const HRegion &Mask, const Halcon::HTuple &Number, const Halcon::HTuple &Margin) const;
  // Separated median filtering with rectangle masks.
  virtual HImageArray MedianSeparate(const Halcon::HTuple &MaskWidth, const Halcon::HTuple &MaskHeight, const Halcon::HTuple &Margin) const;
  // Compute a median filter with rectangular masks.
  virtual HImageArray MedianRect(const Halcon::HTuple &MaskWidth, const Halcon::HTuple &MaskHeight) const;
  // Compute a median filter with rectangular masks.
  virtual HImageArray MedianRect(Hlong MaskWidth, Hlong MaskHeight) const;
  // Compute a median filter with various masks.
  virtual HImageArray MedianImage(const Halcon::HTuple &MaskType, const Halcon::HTuple &Radius, const Halcon::HTuple &Margin) const;
  // Weighted median filtering with different rank masks.
  virtual HImageArray MedianWeighted(const Halcon::HTuple &MaskType, const Halcon::HTuple &MaskSize) const;
  // Weighted median filtering with different rank masks.
  virtual HImageArray MedianWeighted(const char *MaskType, Hlong MaskSize) const;
  // Compute a rank filter with rectangular masks.
  virtual HImageArray RankRect(const Halcon::HTuple &MaskWidth, const Halcon::HTuple &MaskHeight, const Halcon::HTuple &Rank) const;
  // Compute a rank filter with rectangular masks.
  virtual HImageArray RankRect(Hlong MaskWidth, Hlong MaskHeight, Hlong Rank) const;
  // Compute a rank filter with arbitrary masks.
  virtual HImageArray RankImage(const HRegion &Mask, const Halcon::HTuple &Rank, const Halcon::HTuple &Margin) const;
  // Opening, Median and Closing with circle or rectangle mask.
  virtual HImageArray DualRank(const Halcon::HTuple &MaskType, const Halcon::HTuple &Radius, const Halcon::HTuple &ModePercent, const Halcon::HTuple &Margin) const;
  // Smooth by averaging.
  virtual HImageArray MeanImage(const Halcon::HTuple &MaskWidth, const Halcon::HTuple &MaskHeight) const;
  // Smooth by averaging.
  virtual HImageArray MeanImage(Hlong MaskWidth, Hlong MaskHeight) const;
  // Smooth an image using the binomial filter.
  virtual HImageArray BinomialFilter(const Halcon::HTuple &MaskWidth, const Halcon::HTuple &MaskHeight) const;
  // Smooth an image using the binomial filter.
  virtual HImageArray BinomialFilter(Hlong MaskWidth, Hlong MaskHeight) const;
  // Smooth an image using discrete Gaussian functions.
  virtual HImageArray GaussImage(const Halcon::HTuple &Size) const;
  // Smooth an image using discrete Gaussian functions.
  virtual HImageArray GaussImage(Hlong Size) const;
  // Smooth using discrete gauss functions.
  virtual HImageArray GaussFilter(const Halcon::HTuple &Size) const;
  // Smooth using discrete gauss functions.
  virtual HImageArray GaussFilter(Hlong Size) const;
  // Smooth an image in the spatial domain to suppress noise.
  virtual HImageArray EliminateMinMax(const Halcon::HTuple &MaskWidth, const Halcon::HTuple &MaskHeight, const Halcon::HTuple &Gap, const Halcon::HTuple &Mode) const;
  // Smooth an image in the spatial domain to suppress noise.
  virtual HImageArray EliminateMinMax(Hlong MaskWidth, Hlong MaskHeight, double Gap, Hlong Mode) const;
  // Smooth an image by edge-preserving anisotropic diffusion.
  virtual HImageArray AnisotropeDiff(const Halcon::HTuple &Percent, const Halcon::HTuple &Mode, const Halcon::HTuple &Iteration, const Halcon::HTuple &NeighborhoodType) const;
  // Smooth an image by edge-preserving anisotropic diffusion.
  virtual HImageArray AnisotropeDiff(Hlong Percent, Hlong Mode, Hlong Iteration, Hlong NeighborhoodType) const;
  // Interpolate 2 video half images.
  virtual HImageArray FillInterlace(const Halcon::HTuple &Mode) const;
  // Interpolate 2 video half images.
  virtual HImageArray FillInterlace(const char *Mode) const;
  // Return gray values with given rank from multiple channels.
  virtual HImageArray RankN(const Halcon::HTuple &RankIndex) const;
  // Return gray values with given rank from multiple channels.
  virtual HImageArray RankN(Hlong RankIndex) const;
  // Average gray values over several channels.
  virtual HImageArray MeanN(void) const;
  // Replace values outside of thresholds with average value.
  virtual HImageArray EliminateSp(const Halcon::HTuple &MaskWidth, const Halcon::HTuple &MaskHeight, const Halcon::HTuple &MinThresh, const Halcon::HTuple &MaxThresh) const;
  // Replace values outside of thresholds with average value.
  virtual HImageArray EliminateSp(Hlong MaskWidth, Hlong MaskHeight, Hlong MinThresh, Hlong MaxThresh) const;
  // Suppress salt and pepper noise.
  virtual HImageArray MeanSp(const Halcon::HTuple &MaskWidth, const Halcon::HTuple &MaskHeight, const Halcon::HTuple &MinThresh, const Halcon::HTuple &MaxThresh) const;
  // Suppress salt and pepper noise.
  virtual HImageArray MeanSp(Hlong MaskWidth, Hlong MaskHeight, Hlong MinThresh, Hlong MaxThresh) const;
  // Enhance circular dots in an image.
  virtual HImageArray DotsImage(const Halcon::HTuple &Diameter, const Halcon::HTuple &FilterType, const Halcon::HTuple &PixelShift) const;
  // Enhance circular dots in an image.
  virtual HImageArray DotsImage(Hlong Diameter, const char *FilterType, Hlong PixelShift) const;
  // Estimate the image noise from a single image.
  virtual HTuple EstimateNoise(const Halcon::HTuple &Method, const Halcon::HTuple &Percent) const;
  // Estimate the image noise from a single image.
  virtual HTuple EstimateNoise(const char *Method, double Percent) const;
  // Add noise to an image.
  virtual HImageArray AddNoiseWhite(const Halcon::HTuple &Amp) const;
  // Add noise to an image.
  virtual HImageArray AddNoiseWhite(double Amp) const;
  // Add noise to an image.
  virtual HImageArray AddNoiseDistribution(const Halcon::HTuple &Distribution) const;
  // Calculate standard deviation over several channels.
  virtual HImageArray DeviationN(void) const;
  // Perform an inpainting by texture propagation.
  virtual HImageArray InpaintingTexture(const HRegion &Region, const Halcon::HTuple &MaskSize, const Halcon::HTuple &SearchSize, const Halcon::HTuple &Anisotropy, const Halcon::HTuple &PostIteration, const Halcon::HTuple &Smoothness) const;
  // Perform an inpainting by texture propagation.
  virtual HImageArray InpaintingTexture(const HRegion &Region, Hlong MaskSize, Hlong SearchSize, double Anisotropy, const char *PostIteration, double Smoothness) const;
  // Perform an inpainting by coherence transport.
  virtual HImageArray InpaintingCt(const HRegion &Region, const Halcon::HTuple &Epsilon, const Halcon::HTuple &Kappa, const Halcon::HTuple &Sigma, const Halcon::HTuple &Rho, const Halcon::HTuple &ChannelCoefficients) const;
  // Perform an inpainting by coherence transport.
  virtual HImageArray InpaintingCt(const HRegion &Region, double Epsilon, double Kappa, double Sigma, double Rho, double ChannelCoefficients) const;
  // Perform an inpainting by smoothing of level lines.
  virtual HImageArray InpaintingMcf(const HRegion &Region, const Halcon::HTuple &Sigma, const Halcon::HTuple &Theta, const Halcon::HTuple &Iterations) const;
  // Perform an inpainting by smoothing of level lines.
  virtual HImageArray InpaintingMcf(const HRegion &Region, double Sigma, double Theta, Hlong Iterations) const;
  // Perform an inpainting by coherence enhancing diffusion.
  virtual HImageArray InpaintingCed(const HRegion &Region, const Halcon::HTuple &Sigma, const Halcon::HTuple &Rho, const Halcon::HTuple &Theta, const Halcon::HTuple &Iterations) const;
  // Perform an inpainting by coherence enhancing diffusion.
  virtual HImageArray InpaintingCed(const HRegion &Region, double Sigma, double Rho, double Theta, Hlong Iterations) const;
  // Perform an inpainting by anisotropic diffusion.
  virtual HImageArray InpaintingAniso(const HRegion &Region, const Halcon::HTuple &Mode, const Halcon::HTuple &Contrast, const Halcon::HTuple &Theta, const Halcon::HTuple &Iterations, const Halcon::HTuple &Rho) const;
  // Perform an inpainting by anisotropic diffusion.
  virtual HImageArray InpaintingAniso(const HRegion &Region, const char *Mode, double Contrast, double Theta, Hlong Iterations, double Rho) const;
  // Perform a harmonic interpolation on an image region.
  virtual HImageArray HarmonicInterpolation(const HRegion &Region, const Halcon::HTuple &Precision) const;
  // Perform a harmonic interpolation on an image region.
  virtual HImageArray HarmonicInterpolation(const HRegion &Region, double Precision) const;
  // Expand the domain of an image and set the gray values in the
  // expanded domain.
  virtual HImageArray ExpandDomainGray(const Halcon::HTuple &ExpansionRange) const;
  // Expand the domain of an image and set the gray values in the
  // expanded domain.
  virtual HImageArray ExpandDomainGray(Hlong ExpansionRange) const;
  // Compute the topographic primal sketch of an image.
  virtual HImageArray TopographicSketch(void) const;
  // Compute an affine transformation of the color values of a
  // multichannel image.
  virtual HImageArray LinearTransColor(const Halcon::HTuple &TransMat) const;
  // Compute the transformation matrix of the principal component
  // analysis of multichannel images.
  virtual HTuple GenPrincipalCompTrans(Halcon::HTuple *TransInv, Halcon::HTuple *Mean, Halcon::HTuple *Cov, Halcon::HTuple *InfoPerComp) const;
  // Perform a grayvalue closing with a selected mask.
  virtual HImageArray GrayClosingShape(const Halcon::HTuple &MaskHeight, const Halcon::HTuple &MaskWidth, const Halcon::HTuple &MaskShape) const;
  // Perform a grayvalue closing with a selected mask.
  virtual HImageArray GrayClosingShape(double MaskHeight, double MaskWidth, const char *MaskShape) const;
  // Perform a gray value opening with a selected mask.
  virtual HImageArray GrayOpeningShape(const Halcon::HTuple &MaskHeight, const Halcon::HTuple &MaskWidth, const Halcon::HTuple &MaskShape) const;
  // Perform a gray value opening with a selected mask.
  virtual HImageArray GrayOpeningShape(double MaskHeight, double MaskWidth, const char *MaskShape) const;
  // Determine the minimum gray value within a selected mask.
  virtual HImageArray GrayErosionShape(const Halcon::HTuple &MaskHeight, const Halcon::HTuple &MaskWidth, const Halcon::HTuple &MaskShape) const;
  // Determine the minimum gray value within a selected mask.
  virtual HImageArray GrayErosionShape(double MaskHeight, double MaskWidth, const char *MaskShape) const;
  // Determine the maximum gray value within a selected mask.
  virtual HImageArray GrayDilationShape(const Halcon::HTuple &MaskHeight, const Halcon::HTuple &MaskWidth, const Halcon::HTuple &MaskShape) const;
  // Determine the maximum gray value within a selected mask.
  virtual HImageArray GrayDilationShape(double MaskHeight, double MaskWidth, const char *MaskShape) const;
  // Determine the gray value range within a rectangle.
  virtual HImageArray GrayRangeRect(const Halcon::HTuple &MaskHeight, const Halcon::HTuple &MaskWidth) const;
  // Determine the gray value range within a rectangle.
  virtual HImageArray GrayRangeRect(Hlong MaskHeight, Hlong MaskWidth) const;
  // Perform a gray value closing with a rectangular mask.
  virtual HImageArray GrayClosingRect(const Halcon::HTuple &MaskHeight, const Halcon::HTuple &MaskWidth) const;
  // Perform a gray value closing with a rectangular mask.
  virtual HImageArray GrayClosingRect(Hlong MaskHeight, Hlong MaskWidth) const;
  // Perform a gray value opening with a rectangular mask.
  virtual HImageArray GrayOpeningRect(const Halcon::HTuple &MaskHeight, const Halcon::HTuple &MaskWidth) const;
  // Perform a gray value opening with a rectangular mask.
  virtual HImageArray GrayOpeningRect(Hlong MaskHeight, Hlong MaskWidth) const;
  // Determine the minimum gray value within a rectangle.
  virtual HImageArray GrayErosionRect(const Halcon::HTuple &MaskHeight, const Halcon::HTuple &MaskWidth) const;
  // Determine the minimum gray value within a rectangle.
  virtual HImageArray GrayErosionRect(Hlong MaskHeight, Hlong MaskWidth) const;
  // Determine the maximum gray value within a rectangle.
  virtual HImageArray GrayDilationRect(const Halcon::HTuple &MaskHeight, const Halcon::HTuple &MaskWidth) const;
  // Determine the maximum gray value within a rectangle.
  virtual HImageArray GrayDilationRect(Hlong MaskHeight, Hlong MaskWidth) const;
  // Thinning of gray value images.
  virtual HImageArray GraySkeleton(void) const;
  // Transform an image with a gray-value look-up-table
  virtual HImageArray LutTrans(const Halcon::HTuple &Lut) const;
  // Calculate the correlation between an image and an arbitrary filter mask
  virtual HImageArray ConvolImage(const Halcon::HTuple &FilterMask, const Halcon::HTuple &Margin) const;
  // Convert the type of an image.
  virtual HImageArray ConvertImageType(const Halcon::HTuple &NewType) const;
  // Convert the type of an image.
  virtual HImageArray ConvertImageType(const char *NewType) const;
  // Convert two real-valued images into a vector field image.
  virtual HImageArray RealToVectorField(const HImageArray &Col, const Halcon::HTuple &Type) const;
  // Convert two real-valued images into a vector field image.
  virtual HImageArray RealToVectorField(const HImageArray &Col, const char *Type) const;
  // Convert a vector field image into two real-valued images.
  virtual HImageArray VectorFieldToReal(HImageArray *Col) const;
  // Convert two real images into a complex image.
  virtual HImageArray RealToComplex(const HImageArray &ImageImaginary) const;
  // Convert a complex image into two real images.
  virtual HImageArray ComplexToReal(HImageArray *ImageImaginary) const;
  // Calculate the lowest possible gray value on an arbitrary path to the
  // image border for each point in the image.
  virtual HImageArray GrayInside(void) const;
  // Symmetry of gray values along a row.
  virtual HImageArray Symmetry(const Halcon::HTuple &MaskSize, const Halcon::HTuple &Direction, const Halcon::HTuple &Exponent) const;
  // Symmetry of gray values along a row.
  virtual HImageArray Symmetry(Hlong MaskSize, double Direction, double Exponent) const;
  // Selection of gray values of a multi-channel image using an index image.
  virtual HImageArray SelectGrayvaluesFromChannels(const HImageArray &IndexImage) const;
  // Extract depth using mutiple focus levels.
  virtual HImageArray DepthFromFocus(HImageArray *Confidence, const Halcon::HTuple &Filter, const Halcon::HTuple &Selection) const;
  // Compute the uncalibrated scene flow between two stereo image pairs.
  virtual HImageArray SceneFlowUncalib(const HImageArray &ImageRect2T1, const HImageArray &ImageRect1T2, const HImageArray &ImageRect2T2, const HImageArray &Disparity, HImageArray *DisparityChange, const Halcon::HTuple &SmoothingFlow, const Halcon::HTuple &SmoothingDisparity, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue) const;
  // Unwarp an image using a vector field.
  virtual HImageArray UnwarpImageVectorField(const HImageArray &VectorField) const;
  // Convolve a vector field with derivatives of the Gaussian.
  virtual HImageArray DerivateVectorField(const Halcon::HTuple &Sigma, const Halcon::HTuple &Component) const;
  // Convolve a vector field with derivatives of the Gaussian.
  virtual HImageArray DerivateVectorField(double Sigma, const char *Component) const;
  // Compute the length of the vectors of a vector field.
  virtual HImageArray VectorFieldLength(const Halcon::HTuple &Mode) const;
  // Compute the length of the vectors of a vector field.
  virtual HImageArray VectorFieldLength(const char *Mode) const;
  // Compute the optical flow between two images.
  virtual HImageArray OpticalFlowMg(const HImageArray &ImageT2, const Halcon::HTuple &Algorithm, const Halcon::HTuple &SmoothingSigma, const Halcon::HTuple &IntegrationSigma, const Halcon::HTuple &FlowSmoothness, const Halcon::HTuple &GradientConstancy, const Halcon::HTuple &MGParamName, const Halcon::HTuple &MGParamValue) const;
  // Matching a template and an image in a resolution pyramid.
  virtual HImageArray ExhaustiveMatchMg(const HImage &ImageTemplate, const Halcon::HTuple &Mode, const Halcon::HTuple &Level, const Halcon::HTuple &Threshold) const;
  // Matching a template and an image in a resolution pyramid.
  virtual HImageArray ExhaustiveMatchMg(const HImage &ImageTemplate, const char *Mode, Hlong Level, Hlong Threshold) const;
  // Adapting a template to the size of an image.
  virtual void AdaptTemplate(const Halcon::HTemplate &TemplateID) const;
  // Searching all good grayvalue matches in a pyramid.
  virtual HRegionArray FastMatchMg(const Halcon::HTemplate &TemplateID, const Halcon::HTuple &MaxError, const Halcon::HTuple &NumLevel) const;
  // Searching all good grayvalue matches in a pyramid.
  virtual HRegionArray FastMatchMg(const Halcon::HTemplate &TemplateID, double MaxError, Hlong NumLevel) const;
  // Searching the best grayvalue matches in a pre generated pyramid.
  virtual double BestMatchPreMg(const Halcon::HTemplate &TemplateID, const Halcon::HTuple &MaxError, const Halcon::HTuple &SubPixel, const Halcon::HTuple &NumLevels, const Halcon::HTuple &WhichLevels, Halcon::HTuple *Column, Halcon::HTuple *Error) const;
  // Searching the best grayvalue matches in a pre generated pyramid.
  virtual double BestMatchPreMg(const Halcon::HTemplate &TemplateID, double MaxError, const char *SubPixel, Hlong NumLevels, Hlong WhichLevels, Halcon::HTuple *Column, Halcon::HTuple *Error) const;
  // Searching the best grayvalue matches in a pyramid.
  virtual double BestMatchMg(const Halcon::HTemplate &TemplateID, const Halcon::HTuple &MaxError, const Halcon::HTuple &SubPixel, const Halcon::HTuple &NumLevels, const Halcon::HTuple &WhichLevels, Halcon::HTuple *Column, Halcon::HTuple *Error) const;
  // Searching the best grayvalue matches in a pyramid.
  virtual double BestMatchMg(const Halcon::HTemplate &TemplateID, double MaxError, const char *SubPixel, Hlong NumLevels, Hlong WhichLevels, Halcon::HTuple *Column, Halcon::HTuple *Error) const;
  // Searching all good matches of a template and an image.
  virtual HRegionArray FastMatch(const Halcon::HTemplate &TemplateID, const Halcon::HTuple &MaxError) const;
  // Searching all good matches of a template and an image.
  virtual HRegionArray FastMatch(const Halcon::HTemplate &TemplateID, double MaxError) const;
  // Searching the best matching of a template and a pyramid with rotation.
  virtual HTuple BestMatchRotMg(const Halcon::HTemplate &TemplateID, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtend, const Halcon::HTuple &MaxError, const Halcon::HTuple &SubPixel, const Halcon::HTuple &NumLevels, Halcon::HTuple *Column, Halcon::HTuple *Angle, Halcon::HTuple *Error) const;
  // Searching the best matching of a template and a pyramid with rotation.
  virtual HTuple BestMatchRotMg(const Halcon::HTemplate &TemplateID, double AngleStart, double AngleExtend, double MaxError, const char *SubPixel, Hlong NumLevels, Halcon::HTuple *Column, Halcon::HTuple *Angle, Halcon::HTuple *Error) const;
  // Searching the best matching of a template and an image with rotation.
  virtual HTuple BestMatchRot(const Halcon::HTemplate &TemplateID, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtend, const Halcon::HTuple &MaxError, const Halcon::HTuple &SubPixel, Halcon::HTuple *Column, Halcon::HTuple *Angle, Halcon::HTuple *Error) const;
  // Searching the best matching of a template and an image with rotation.
  virtual HTuple BestMatchRot(const Halcon::HTemplate &TemplateID, double AngleStart, double AngleExtend, double MaxError, const char *SubPixel, Halcon::HTuple *Column, Halcon::HTuple *Angle, Halcon::HTuple *Error) const;
  // Searching the best matching of a template and an image.
  virtual HTuple BestMatch(const Halcon::HTemplate &TemplateID, const Halcon::HTuple &MaxError, const Halcon::HTuple &SubPixel, Halcon::HTuple *Column, Halcon::HTuple *Error) const;
  // Searching the best matching of a template and an image.
  virtual HTuple BestMatch(const Halcon::HTemplate &TemplateID, double MaxError, const char *SubPixel, Halcon::HTuple *Column, Halcon::HTuple *Error) const;
  // Matching of a template and an image.
  virtual HImageArray ExhaustiveMatch(const HRegion &RegionOfInterest, const HImage &ImageTemplate, const Halcon::HTuple &Mode) const;
  // Matching of a template and an image.
  virtual HImageArray ExhaustiveMatch(const HRegion &RegionOfInterest, const HImage &ImageTemplate, const char *Mode) const;
  // Searching corners in images.
  virtual HImageArray CornerResponse(const Halcon::HTuple &Size, const Halcon::HTuple &Weight) const;
  // Searching corners in images.
  virtual HImageArray CornerResponse(Hlong Size, double Weight) const;
  // Calculating the monotony operation.
  virtual HImageArray Monotony(void) const;
  // Edge extraction using bandpass filters.
  virtual HImageArray BandpassImage(const Halcon::HTuple &FilterType) const;
  // Edge extraction using bandpass filters.
  virtual HImageArray BandpassImage(const char *FilterType) const;
  // Return the power spectrum of a complex image.
  virtual HImageArray PowerLn(void) const;
  // Return the power spectrum of a complex image.
  virtual HImageArray PowerReal(void) const;
  // Return the power spectrum of a complex image.
  virtual HImageArray PowerByte(void) const;
  // Return the phase of a complex image in degrees.
  virtual HImageArray PhaseDeg(void) const;
  // Return the phase of a complex image in radians.
  virtual HImageArray PhaseRad(void) const;
  // Calculate the energy of a two-channel image.
  virtual HImageArray EnergyGabor(const HImageArray &ImageHilbert) const;
  // Convolve an image with a Gabor filter in the frequency domain.
  virtual HImageArray ConvolGabor(const HImage &GaborFilter, HImageArray *ImageResultHilbert) const;
  // Compute the phase correlation of two images in the frequency domain.
  virtual HImageArray PhaseCorrelationFft(const HImageArray &ImageFFT2) const;
  // Compute the correlation of two images in the frequency domain.
  virtual HImageArray CorrelationFft(const HImageArray &ImageFFT2) const;
  // Convolve an image with a filter in the frequency domain.
  virtual HImageArray ConvolFft(const HImage &ImageFilter) const;
  // Compute the real-valued fast Fourier transform of an image.
  virtual HImageArray RftGeneric(const Halcon::HTuple &Direction, const Halcon::HTuple &Norm, const Halcon::HTuple &ResultType, const Halcon::HTuple &Width) const;
  // Compute the real-valued fast Fourier transform of an image.
  virtual HImageArray RftGeneric(const char *Direction, const char *Norm, const char *ResultType, Hlong Width) const;
  // Compute the inverse fast Fourier transform of an image.
  virtual HImageArray FftImageInv(void) const;
  // Compute the fast Fourier transform of an image.
  virtual HImageArray FftImage(void) const;
  // Compute the fast Fourier transform of an image.
  virtual HImageArray FftGeneric(const Halcon::HTuple &Direction, const Halcon::HTuple &Exponent, const Halcon::HTuple &Norm, const Halcon::HTuple &Mode, const Halcon::HTuple &ResultType) const;
  // Compute the fast Fourier transform of an image.
  virtual HImageArray FftGeneric(const char *Direction, Hlong Exponent, const char *Norm, const char *Mode, const char *ResultType) const;
  // Apply a shock filter to an image.
  virtual HImageArray ShockFilter(const Halcon::HTuple &Theta, const Halcon::HTuple &Iterations, const Halcon::HTuple &Mode, const Halcon::HTuple &Sigma) const;
  // Apply a shock filter to an image.
  virtual HImageArray ShockFilter(double Theta, Hlong Iterations, const char *Mode, double Sigma) const;
  // Apply the mean curvature flow to an image.
  virtual HImageArray MeanCurvatureFlow(const Halcon::HTuple &Sigma, const Halcon::HTuple &Theta, const Halcon::HTuple &Iterations) const;
  // Apply the mean curvature flow to an image.
  virtual HImageArray MeanCurvatureFlow(double Sigma, double Theta, Hlong Iterations) const;
  // Perform a coherence enhancing diffusion of an image.
  virtual HImageArray CoherenceEnhancingDiff(const Halcon::HTuple &Sigma, const Halcon::HTuple &Rho, const Halcon::HTuple &Theta, const Halcon::HTuple &Iterations) const;
  // Perform a coherence enhancing diffusion of an image.
  virtual HImageArray CoherenceEnhancingDiff(double Sigma, double Rho, double Theta, Hlong Iterations) const;
  // Histogram linearisation of images
  virtual HImageArray EquHistoImage(void) const;
  // Illuminate image.
  virtual HImageArray Illuminate(const Halcon::HTuple &MaskWidth, const Halcon::HTuple &MaskHeight, const Halcon::HTuple &Factor) const;
  // Illuminate image.
  virtual HImageArray Illuminate(Hlong MaskWidth, Hlong MaskHeight, double Factor) const;
  // Enhance contrast of the image.
  virtual HImageArray Emphasize(const Halcon::HTuple &MaskWidth, const Halcon::HTuple &MaskHeight, const Halcon::HTuple &Factor) const;
  // Enhance contrast of the image.
  virtual HImageArray Emphasize(Hlong MaskWidth, Hlong MaskHeight, double Factor) const;
  // Maximum gray value spreading in the value range
  // 0 to 255.
  virtual HImageArray ScaleImageMax(void) const;
  // Detect edges (amplitude and direction) using the Robinson operator.
  virtual HImageArray RobinsonDir(HImageArray *ImageEdgeDir) const;
  // Detect edges (amplitude) using the Robinson operator.
  virtual HImageArray RobinsonAmp(void) const;
  // Detect edges (amplitude and direction) using the Kirsch operator.
  virtual HImageArray KirschDir(HImageArray *ImageEdgeDir) const;
  // Detect edges (amplitude) using the Kirsch operator.
  virtual HImageArray KirschAmp(void) const;
  // Detect edges (amplitude and direction) using the Frei-Chen operator.
  virtual HImageArray FreiDir(HImageArray *ImageEdgeDir) const;
  // Detect edges (amplitude) using the Frei-Chen operator.
  virtual HImageArray FreiAmp(void) const;
  // Detect edges (amplitude and direction) using the Prewitt operator.
  virtual HImageArray PrewittDir(HImageArray *ImageEdgeDir) const;
  // Detect edges (amplitude) using the Prewitt operator.
  virtual HImageArray PrewittAmp(void) const;
  // Detect edges (amplitude) using the Sobel operator.
  virtual HImageArray SobelAmp(const Halcon::HTuple &FilterType, const Halcon::HTuple &Size) const;
  // Detect edges (amplitude) using the Sobel operator.
  virtual HImageArray SobelAmp(const char *FilterType, Hlong Size) const;
  // Detect edges (amplitude and direction) using the Sobel operator.
  virtual HImageArray SobelDir(HImageArray *EdgeDirection, const Halcon::HTuple &FilterType, const Halcon::HTuple &Size) const;
  // Detect edges (amplitude and direction) using the Sobel operator.
  virtual HImageArray SobelDir(HImageArray *EdgeDirection, const char *FilterType, Hlong Size) const;
  // Detect edges using the Roberts filter.
  virtual HImageArray Roberts(const Halcon::HTuple &FilterType) const;
  // Detect edges using the Roberts filter.
  virtual HImageArray Roberts(const char *FilterType) const;
  // Calculate the Laplace operator by using finite differences.
  virtual HImageArray Laplace(const Halcon::HTuple &ResultType, const Halcon::HTuple &MaskSize, const Halcon::HTuple &FilterMask) const;
  // Calculate the Laplace operator by using finite differences.
  virtual HImageArray Laplace(const char *ResultType, Hlong MaskSize, const char *FilterMask) const;
  // Extract high frequency components from an image.
  virtual HImageArray HighpassImage(const Halcon::HTuple &Width, const Halcon::HTuple &Height) const;
  // Extract high frequency components from an image.
  virtual HImageArray HighpassImage(Hlong Width, Hlong Height) const;
  // Extract color edges using Canny, Deriche, or Shen filters.
  virtual HImageArray EdgesColor(HImageArray *ImaDir, const Halcon::HTuple &Filter, const Halcon::HTuple &Alpha, const Halcon::HTuple &NMS, const Halcon::HTuple &Low, const Halcon::HTuple &High) const;
  // Extract color edges using Canny, Deriche, or Shen filters.
  virtual HImageArray EdgesColor(HImageArray *ImaDir, const char *Filter, double Alpha, const char *NMS, Hlong Low, Hlong High) const;
  // Extract edges using Deriche, Lanser, Shen, or Canny filters.
  virtual HImageArray EdgesImage(HImageArray *ImaDir, const Halcon::HTuple &Filter, const Halcon::HTuple &Alpha, const Halcon::HTuple &NMS, const Halcon::HTuple &Low, const Halcon::HTuple &High) const;
  // Extract edges using Deriche, Lanser, Shen, or Canny filters.
  virtual HImageArray EdgesImage(HImageArray *ImaDir, const char *Filter, double Alpha, const char *NMS, Hlong Low, Hlong High) const;
  // Convolve an image with derivatives of the Gaussian.
  virtual HImageArray DerivateGauss(const Halcon::HTuple &Sigma, const Halcon::HTuple &Component) const;
  // Convolve an image with derivatives of the Gaussian.
  virtual HImageArray DerivateGauss(double Sigma, const char *Component) const;
  // LoG-Operator (Laplace of Gaussian).
  virtual HImageArray LaplaceOfGauss(const Halcon::HTuple &Sigma) const;
  // LoG-Operator (Laplace of Gaussian).
  virtual HImageArray LaplaceOfGauss(double Sigma) const;
  // Approximate the LoG operator (Laplace of Gaussian).
  virtual HImageArray DiffOfGauss(const Halcon::HTuple &Sigma, const Halcon::HTuple &SigFactor) const;
  // Approximate the LoG operator (Laplace of Gaussian).
  virtual HImageArray DiffOfGauss(double Sigma, double SigFactor) const;
  // Detect straight edge segments.
  virtual HTuple DetectEdgeSegments(const Halcon::HTuple &SobelSize, const Halcon::HTuple &MinAmplitude, const Halcon::HTuple &MaxDistance, const Halcon::HTuple &MinLength, Halcon::HTuple *BeginCol, Halcon::HTuple *EndRow, Halcon::HTuple *EndCol) const;
  // Detect straight edge segments.
  virtual HTuple DetectEdgeSegments(Hlong SobelSize, Hlong MinAmplitude, Hlong MaxDistance, Hlong MinLength, Halcon::HTuple *BeginCol, Halcon::HTuple *EndRow, Halcon::HTuple *EndCol) const;
  // Color space transformation using pre-generated look-up-table.
  virtual HImageArray ApplyColorTransLut(const HImageArray &Image2, const HImageArray &Image3, HImageArray *ImageResult2, HImageArray *ImageResult3, const Halcon::HColorTransLUT &ColorTransLUTHandle) const;
  // Convert a single-channel color filter array image into an RGB image.
  virtual HImageArray CfaToRgb(const Halcon::HTuple &CFAType, const Halcon::HTuple &Interpolation) const;
  // Convert a single-channel color filter array image into an RGB image.
  virtual HImageArray CfaToRgb(const char *CFAType, const char *Interpolation) const;
  // Transform an RGB image into a gray scale image.
  virtual HImageArray Rgb1ToGray(void) const;
  // Transform an RGB image to a gray scale image.
  virtual HImageArray Rgb3ToGray(const HImageArray &ImageGreen, const HImageArray &ImageBlue) const;
  // Transform an image from the RGB color space to an arbitrary color space.
  virtual HImageArray TransFromRgb(const HImageArray &ImageGreen, const HImageArray &ImageBlue, HImageArray *ImageResult2, HImageArray *ImageResult3, const Halcon::HTuple &ColorSpace) const;
  // Transform an image from the RGB color space to an arbitrary color space.
  virtual HImageArray TransFromRgb(const HImageArray &ImageGreen, const HImageArray &ImageBlue, HImageArray *ImageResult2, HImageArray *ImageResult3, const char *ColorSpace) const;
  // Transform an image from an arbitrary color space to the RGB color space.
  virtual HImageArray TransToRgb(const HImageArray &ImageInput2, const HImageArray &ImageInput3, HImageArray *ImageGreen, HImageArray *ImageBlue, const Halcon::HTuple &ColorSpace) const;
  // Transform an image from an arbitrary color space to the RGB color space.
  virtual HImageArray TransToRgb(const HImageArray &ImageInput2, const HImageArray &ImageInput3, HImageArray *ImageGreen, HImageArray *ImageBlue, const char *ColorSpace) const;
  // Logical "AND" of each pixel using a bit mask.
  virtual HImageArray BitMask(const Halcon::HTuple &BitMask) const;
  // Logical "AND" of each pixel using a bit mask.
  virtual HImageArray BitMask(Hlong BitMask) const;
  // Extract a bit from the pixels.
  virtual HImageArray BitSlice(const Halcon::HTuple &Bit) const;
  // Extract a bit from the pixels.
  virtual HImageArray BitSlice(Hlong Bit) const;
  // Right shift of all pixels of the image.
  virtual HImageArray BitRshift(const Halcon::HTuple &Shift) const;
  // Right shift of all pixels of the image.
  virtual HImageArray BitRshift(Hlong Shift) const;
  // Left shift of all pixels of the image.
  virtual HImageArray BitLshift(const Halcon::HTuple &Shift) const;
  // Left shift of all pixels of the image.
  virtual HImageArray BitLshift(Hlong Shift) const;
  // Complement all bits of the pixels.
  virtual HImageArray BitNot(void) const;
  // Bit-by-bit XOR of all pixels of the input images.
  virtual HImageArray BitXor(const HImageArray &Image2) const;
  // Bit-by-bit OR of all pixels of the input images.
  virtual HImageArray BitOr(const HImageArray &Image2) const;
  // Bit-by-bit AND of all pixels of the input images.
  virtual HImageArray BitAnd(const HImageArray &Image2) const;
  // Perform a gamma encoding or decoding of an image.
  virtual HImageArray GammaImage(const Halcon::HTuple &Gamma, const Halcon::HTuple &Offset, const Halcon::HTuple &Threshold, const Halcon::HTuple &MaxGray, const Halcon::HTuple &Encode) const;
  // Perform a gamma encoding or decoding of an image.
  virtual HImageArray GammaImage(double Gamma, double Offset, double Threshold, double MaxGray, const char *Encode) const;
  // Raise an image to a power.
  virtual HImageArray PowImage(const Halcon::HTuple &Exponent) const;
  // Raise an image to a power.
  virtual HImageArray PowImage(double Exponent) const;
  // Calculate the exponentiation of an image.
  virtual HImageArray ExpImage(const Halcon::HTuple &Base) const;
  // Calculate the logarithm of an image.
  virtual HImageArray LogImage(const Halcon::HTuple &Base) const;
  // Calculate the arctangent of two images.
  virtual HImageArray Atan2Image(const HImageArray &ImageX) const;
  // Calculate the arctangent of an image.
  virtual HImageArray AtanImage(void) const;
  // Calculate the arccosine of an image.
  virtual HImageArray AcosImage(void) const;
  // Calculate the arcsine of an image.
  virtual HImageArray AsinImage(void) const;
  // Calculate the tangent of an image.
  virtual HImageArray TanImage(void) const;
  // Calculate the cosine of an image.
  virtual HImageArray CosImage(void) const;
  // Calculate the sine of an image.
  virtual HImageArray SinImage(void) const;
  // Calculate the absolute difference of two images.
  virtual HImageArray AbsDiffImage(const HImageArray &Image2, const Halcon::HTuple &Mult) const;
  // Calculate the absolute difference of two images.
  virtual HImageArray AbsDiffImage(const HImageArray &Image2, double Mult) const;
  // Calculate the square root of an image.
  virtual HImageArray SqrtImage(void) const;
  // Subtract two images.
  virtual HImageArray SubImage(const HImageArray &ImageSubtrahend, const Halcon::HTuple &Mult, const Halcon::HTuple &Add) const;
  // Subtract two images.
  virtual HImageArray SubImage(const HImageArray &ImageSubtrahend, double Mult, double Add) const;
  // Scale the gray values of an image.
  virtual HImageArray ScaleImage(const Halcon::HTuple &Mult, const Halcon::HTuple &Add) const;
  // Scale the gray values of an image.
  virtual HImageArray ScaleImage(double Mult, double Add) const;
  // Divide two images.
  virtual HImageArray DivImage(const HImageArray &Image2, const Halcon::HTuple &Mult, const Halcon::HTuple &Add) const;
  // Divide two images.
  virtual HImageArray DivImage(const HImageArray &Image2, double Mult, double Add) const;
  // Multiply two images.
  virtual HImageArray MultImage(const HImageArray &Image2, const Halcon::HTuple &Mult, const Halcon::HTuple &Add) const;
  // Multiply two images.
  virtual HImageArray MultImage(const HImageArray &Image2, double Mult, double Add) const;
  // Add two images.
  virtual HImageArray AddImage(const HImageArray &Image2, const Halcon::HTuple &Mult, const Halcon::HTuple &Add) const;
  // Add two images.
  virtual HImageArray AddImage(const HImageArray &Image2, double Mult, double Add) const;
  // Calculate the absolute value (modulus) of an image.
  virtual HImageArray AbsImage(void) const;
  // Calculate the minimum of two images pixel by pixel.
  virtual HImageArray MinImage(const HImageArray &Image2) const;
  // Calculate the maximum of two images pixel by pixel.
  virtual HImageArray MaxImage(const HImageArray &Image2) const;
  // Invert an image.
  virtual HImageArray InvertImage(void) const;
  // Apply an automatic color correction to panorama images.
  virtual HImageArray AdjustMosaicImages(const Halcon::HTuple &From, const Halcon::HTuple &To, const Halcon::HTuple &ReferenceImage, const Halcon::HTuple &HomMatrices2D, const Halcon::HTuple &EstimationMethod, const Halcon::HTuple &EstimateParameters, const Halcon::HTuple &OECFModel) const;
  // Create 6 cube map images of a spherical mosaic.
  virtual HImage GenCubeMapMosaic(HImage *Rear, HImage *Left, HImage *Right, HImage *Top, HImage *Bottom, const Halcon::HTuple &CameraMatrices, const Halcon::HTuple &RotationMatrices, const Halcon::HTuple &CubeMapDimension, const Halcon::HTuple &StackingOrder, const Halcon::HTuple &Interpolation) const;
  // Create a spherical mosaic image.
  virtual HImage GenSphericalMosaic(const Halcon::HTuple &CameraMatrices, const Halcon::HTuple &RotationMatrices, const Halcon::HTuple &LatMin, const Halcon::HTuple &LatMax, const Halcon::HTuple &LongMin, const Halcon::HTuple &LongMax, const Halcon::HTuple &LatLongStep, const Halcon::HTuple &StackingOrder, const Halcon::HTuple &Interpolation) const;
  // Combine multiple images into a mosaic image.
  virtual HImage GenBundleAdjustedMosaic(const Halcon::HTuple &HomMatrices2D, const Halcon::HTuple &StackingOrder, const Halcon::HTuple &TransformDomain, Halcon::HTuple *TransMat2D) const;
  // Combine multiple images into a mosaic image.
  virtual HImage GenProjectiveMosaic(const Halcon::HTuple &StartImage, const Halcon::HTuple &MappingSource, const Halcon::HTuple &MappingDest, const Halcon::HTuple &HomMatrices2D, const Halcon::HTuple &StackingOrder, const Halcon::HTuple &TransformDomain, Halcon::HTuple *MosaicMatrices2D) const;
  // Apply a projective transformation to an image and specify the output
  // image size.
  virtual HImageArray ProjectiveTransImageSize(const Halcon::HTuple &HomMat2D, const Halcon::HTuple &Interpolation, const Halcon::HTuple &Width, const Halcon::HTuple &Height, const Halcon::HTuple &TransformDomain) const;
  // Apply a projective transformation to an image.
  virtual HImageArray ProjectiveTransImage(const Halcon::HTuple &HomMat2D, const Halcon::HTuple &Interpolation, const Halcon::HTuple &AdaptImageSize, const Halcon::HTuple &TransformDomain) const;
  // Apply an arbitrary affine 2D transformation to an image and specify
  // the output image size.
  virtual HImageArray AffineTransImageSize(const Halcon::HTuple &HomMat2D, const Halcon::HTuple &Interpolation, const Halcon::HTuple &Width, const Halcon::HTuple &Height) const;
  // Apply an arbitrary affine 2D transformation to images.
  virtual HImageArray AffineTransImage(const Halcon::HTuple &HomMat2D, const Halcon::HTuple &Interpolation, const Halcon::HTuple &AdaptImageSize) const;
  // Zoom an image by a given factor.
  virtual HImageArray ZoomImageFactor(const Halcon::HTuple &ScaleWidth, const Halcon::HTuple &ScaleHeight, const Halcon::HTuple &Interpolation) const;
  // Zoom an image by a given factor.
  virtual HImageArray ZoomImageFactor(double ScaleWidth, double ScaleHeight, const char *Interpolation) const;
  // Zoom an image to a given size.
  virtual HImageArray ZoomImageSize(const Halcon::HTuple &Width, const Halcon::HTuple &Height, const Halcon::HTuple &Interpolation) const;
  // Zoom an image to a given size.
  virtual HImageArray ZoomImageSize(Hlong Width, Hlong Height, const char *Interpolation) const;
  // Mirror an image.
  virtual HImageArray MirrorImage(const Halcon::HTuple &Mode) const;
  // Mirror an image.
  virtual HImageArray MirrorImage(const char *Mode) const;
  // Rotate an image about its center.
  virtual HImageArray RotateImage(const Halcon::HTuple &Phi, const Halcon::HTuple &Interpolation) const;
  // Rotate an image about its center.
  virtual HImageArray RotateImage(double Phi, const char *Interpolation) const;
  // Transform an image in polar coordinates back to cartesian coordinates
  virtual HImageArray PolarTransImageInv(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleEnd, const Halcon::HTuple &RadiusStart, const Halcon::HTuple &RadiusEnd, const Halcon::HTuple &Width, const Halcon::HTuple &Height, const Halcon::HTuple &Interpolation) const;
  // Transform an image in polar coordinates back to cartesian coordinates
  virtual HImageArray PolarTransImageInv(double Row, double Column, double AngleStart, double AngleEnd, double RadiusStart, double RadiusEnd, Hlong Width, Hlong Height, const char *Interpolation) const;
  // Transform an annular arc in an image to polar coordinates.
  virtual HImageArray PolarTransImageExt(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleEnd, const Halcon::HTuple &RadiusStart, const Halcon::HTuple &RadiusEnd, const Halcon::HTuple &Width, const Halcon::HTuple &Height, const Halcon::HTuple &Interpolation) const;
  // Transform an annular arc in an image to polar coordinates.
  virtual HImageArray PolarTransImageExt(double Row, double Column, double AngleStart, double AngleEnd, double RadiusStart, double RadiusEnd, Hlong Width, Hlong Height, const char *Interpolation) const;
  // Transform an image to polar coordinates
  virtual HImageArray PolarTransImage(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Width, const Halcon::HTuple &Height) const;
  // Transform an image to polar coordinates
  virtual HImageArray PolarTransImage(Hlong Row, Hlong Column, Hlong Width, Hlong Height) const;
  // Deserialize a serialized image object.
  static HImageArray DeserializeImage(const Halcon::HSerializedItem &SerializedItemHandle);
  // Serialize an image object.
  virtual HSerializedItem SerializeImage(void) const;
  // Write images in graphic formats.
  virtual void WriteImage(const Halcon::HTuple &Format, const Halcon::HTuple &FillColor, const Halcon::HTuple &FileName) const;
  // Write images in graphic formats.
  virtual void WriteImage(const char *Format, Hlong FillColor, const char *FileName) const;
  // Read an image with different file formats.
  static HImageArray ReadImage(const Halcon::HTuple &FileName);
  // Read an image with different file formats.
  static HImageArray ReadImage(const char *FileName);
  // Calculate gray value features from a co-occurrence matrix.
  virtual double CoocFeatureMatrix(Halcon::HTuple *Correlation, Halcon::HTuple *Homogeneity, Halcon::HTuple *Contrast) const;
  // Perform a radiometric self-calibration of a camera.
  virtual HTuple RadiometricSelfCalibration(const Halcon::HTuple &ExposureRatios, const Halcon::HTuple &Features, const Halcon::HTuple &FunctionType, const Halcon::HTuple &Smoothness, const Halcon::HTuple &PolynomialDegree) const;
  // Perform a radiometric self-calibration of a camera.
  virtual HTuple RadiometricSelfCalibration(double ExposureRatios, const char *Features, const char *FunctionType, double Smoothness, Hlong PolynomialDegree) const;
  // Apply a general transformation to an image.
  virtual HImageArray MapImage(const HImage &Map) const;
  // Rectify an image by transforming it into the plane z=0 of a world 
  // coordinate system.
  virtual HImageArray ImageToWorldPlane(const Halcon::HTuple &CameraParam, const Halcon::HTuple &WorldPose, const Halcon::HTuple &Width, const Halcon::HTuple &Height, const Halcon::HTuple &Scale, const Halcon::HTuple &Interpolation) const;
  // Change the radial distortion of an image.
  virtual HImageArray ChangeRadialDistortionImage(const HRegion &Region, const Halcon::HTuple &CamParamIn, const Halcon::HTuple &CamParamOut) const;
  // Segment the region of a standard calibration plate with rectangularly
  // arranged marks in the image.
  virtual HRegion FindCaltab(const Halcon::HTuple &CalPlateDescr, const Halcon::HTuple &SizeGauss, const Halcon::HTuple &MarkThresh, const Halcon::HTuple &MinDiamMarks) const;
  // Segment the region of a standard calibration plate with rectangularly
  // arranged marks in the image.
  virtual HRegion FindCaltab(const char *CalPlateDescr, Hlong SizeGauss, Hlong MarkThresh, Hlong MinDiamMarks) const;
  // Asynchronous grab of images and preprocessed image data from the specified
  // image acquisition device.
  static HImageArray GrabDataAsync(HRegionArray *Region, HXLDContArray *Contours, const Halcon::HFramegrabber &AcqHandle, const Halcon::HTuple &MaxDelay, Halcon::HTuple *Data);
  // Asynchronous grab of images and preprocessed image data from the specified
  // image acquisition device.
  static HImageArray GrabDataAsync(HRegionArray *Region, HXLDContArray *Contours, const Halcon::HFramegrabber &AcqHandle, double MaxDelay, Halcon::HTuple *Data);
  // Synchronous grab of images and preprocessed image data from the specified
  // image acquisition device.
  static HImageArray GrabData(HRegionArray *Region, HXLDContArray *Contours, const Halcon::HFramegrabber &AcqHandle, Halcon::HTuple *Data);
};

}

#endif
