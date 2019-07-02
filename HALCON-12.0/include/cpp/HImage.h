/*****************************************************************************
 * HImage.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Types for Halcon-images
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_IMAGE_H
#define H_IMAGE_H


namespace Halcon {


/****************************************************************************/
/*                               HImage                                     */
/****************************************************************************/
class HImageArray;
class LIntExport HImage: public HObject {
  friend class HImageArray;
public:
  HImage(void) :     HObject(),init(FALSE),privat(FALSE),
    width(0),height(0),type(0),ptr(0) {}
  HImage(Hkey key) : HObject(key),init(FALSE),privat(FALSE),
    width(0),height(0),type(0),ptr(0) {}
  HImage(const Hobject &obj);
  HImage(const char *file);
  HImage(const HImage &r);
  HImage(const HImageArray &arr);
  HImage(int width, int height, const char *type);
  HImage(void *ptr, int width, int height, const char *type);
  HImage(void *ptr, void *ptrfreecall, int loc_width, int loc_height,
         const char *type);
  virtual ~HImage(void) {}
  HImage &operator = (const HImage &image);
  HImage &operator = (const HImageArray &arr);
  
  // Tools
  virtual const char   *Creator(void) const;
                Hlong   NumImageRefs(void) const;
                HBool   Shared(void) const {return NumImageRefs() != 1;}
  virtual const char   *HClassName(void) const;
  virtual const char   *InstClassName(void) const;
  virtual const char   *ClassName(void) const;
  virtual       INT4    ClassDBID(void) const {return IMAGE_ID;}

  virtual       void    CheckMyObjClass(void) const;
  virtual const char   *PixType(void) const;
          int           Width(void) const;
          int           Height(void) const;

  // Pixel Access
          HPixVal GetPixVal(int x, int y) const;
          HPixVal GetPixVal(Hlong k) const;
  virtual void    SetPixVal(int x, int y, const HPixVal &val);
  virtual void    SetPixVal(Hlong k, const HPixVal &val);
  
  virtual void  Transform(const HAffineTrans &transform, int mode);
  virtual void  Display(const HWindow &w) const;
  
  // Infix Operations
  HImage  operator & (const HRegion &reg) const;
  HImage  operator + (const HImage &add) const;
  HImage  operator - (const HImage &sub) const;
  HImage  operator * (const HImage &mult) const;
  HImage  operator - (void) const;
  HImage  operator + (double add) const;
  HImage  operator - (double sub) const;
  HImage  operator * (double mult) const;
  HImage  operator / (double div) const;
  HRegion operator >= (const HImage &image) const;
  HRegion operator <= (const HImage &image) const;
  HRegion operator >= (double thresh) const;
  HRegion operator <= (double thresh) const;
  HRegion operator == (double thresh) const;
  HRegion operator != (double thresh) const;
 
  // Class Methods
  static Hlong NumData(void);

protected:
  void   CopyConvertedImage(const HImage &in,const char *newType);
  void   Init(void);
  void   Private(void);
  HBool  init;
  HBool  privat;
  int    word_length;
  int    width, height;
  int    type;
  char   type_str[20];
  void   *ptr;
  void   SetInitial(void);

public:
  
  // Image restoration by Wiener filtering.
  virtual HImage WienerFilterNi(const HImage &Psf, const HRegionArray &NoiseRegion, const Halcon::HTuple &MaskWidth, const Halcon::HTuple &MaskHeight) const;
  // Image restoration by Wiener filtering.
  virtual HImage WienerFilterNi(const HImage &Psf, const HRegionArray &NoiseRegion, Hlong MaskWidth, Hlong MaskHeight) const;
  // Image restoration by Wiener filtering.
  virtual HImage WienerFilter(const HImage &Psf, const HImage &FilteredImage) const;
  // Generate an impulse response of a (linearly) motion blurring.
  static HImage GenPsfMotion(const Halcon::HTuple &PSFwidth, const Halcon::HTuple &PSFheight, const Halcon::HTuple &Blurring, const Halcon::HTuple &Angle, const Halcon::HTuple &Type);
  // Generate an impulse response of a (linearly) motion blurring.
  static HImage GenPsfMotion(Hlong PSFwidth, Hlong PSFheight, double Blurring, Hlong Angle, Hlong Type);
  // Simulation of (linearly) motion blur.
  virtual HImage SimulateMotion(const Halcon::HTuple &Blurring, const Halcon::HTuple &Angle, const Halcon::HTuple &Type) const;
  // Simulation of (linearly) motion blur.
  virtual HImage SimulateMotion(double Blurring, Hlong Angle, Hlong Type) const;
  // Generate an impulse response of an uniform out-of-focus blurring.
  static HImage GenPsfDefocus(const Halcon::HTuple &PSFwidth, const Halcon::HTuple &PSFheight, const Halcon::HTuple &Blurring);
  // Generate an impulse response of an uniform out-of-focus blurring.
  static HImage GenPsfDefocus(Hlong PSFwidth, Hlong PSFheight, double Blurring);
  // Simulate an uniform out-of-focus blurring of an image.
  virtual HImage SimulateDefocus(const Halcon::HTuple &Blurring) const;
  // Simulate an uniform out-of-focus blurring of an image.
  virtual HImage SimulateDefocus(double Blurring) const;
  // Compare an image to a variation model.
  virtual HRegion CompareExtVariationModel(const Halcon::HVariationModel &ModelID, const Halcon::HTuple &Mode) const;
  // Compare an image to a variation model.
  virtual HRegion CompareExtVariationModel(const Halcon::HVariationModel &ModelID, const char *Mode) const;
  // Compare an image to a variation model.
  virtual HRegion CompareVariationModel(const Halcon::HVariationModel &ModelID) const;
  // Train a variation model.
  virtual void TrainVariationModel(const Halcon::HVariationModel &ModelID) const;
  // Compute a projective transformation matrix and the radial distortion
  // coefficient between two images by finding correspondences between
  // points based on known approximations of the projective
  // transformation matrix and the radial distortion coefficient.
  virtual HTuple ProjMatchPointsDistortionRansacGuided(const HImage &Image2, const Halcon::HTuple &Rows1, const Halcon::HTuple &Cols1, const Halcon::HTuple &Rows2, const Halcon::HTuple &Cols2, const Halcon::HTuple &GrayMatchMethod, const Halcon::HTuple &MaskSize, const Halcon::HTuple &HomMat2DGuide, const Halcon::HTuple &KappaGuide, const Halcon::HTuple &DistanceTolerance, const Halcon::HTuple &MatchThreshold, const Halcon::HTuple &EstimationMethod, const Halcon::HTuple &DistanceThreshold, const Halcon::HTuple &RandSeed, Halcon::HTuple *Kappa, Halcon::HTuple *Error, Halcon::HTuple *Points1, Halcon::HTuple *Points2) const;
  // Compute a projective transformation matrix between two images and
  // the radial distortion coefficient by automatically finding
  // correspondences between points.
  virtual HTuple ProjMatchPointsDistortionRansac(const HImage &Image2, const Halcon::HTuple &Rows1, const Halcon::HTuple &Cols1, const Halcon::HTuple &Rows2, const Halcon::HTuple &Cols2, const Halcon::HTuple &GrayMatchMethod, const Halcon::HTuple &MaskSize, const Halcon::HTuple &RowMove, const Halcon::HTuple &ColMove, const Halcon::HTuple &RowTolerance, const Halcon::HTuple &ColTolerance, const Halcon::HTuple &Rotation, const Halcon::HTuple &MatchThreshold, const Halcon::HTuple &EstimationMethod, const Halcon::HTuple &DistanceThreshold, const Halcon::HTuple &RandSeed, Halcon::HTuple *Kappa, Halcon::HTuple *Error, Halcon::HTuple *Points1, Halcon::HTuple *Points2) const;
  // Compute a projective transformation matrix between two images by
  // finding correspondences between points based on a known
  // approximation of the projective transformation matrix.
  virtual HTuple ProjMatchPointsRansacGuided(const HImage &Image2, const Halcon::HTuple &Rows1, const Halcon::HTuple &Cols1, const Halcon::HTuple &Rows2, const Halcon::HTuple &Cols2, const Halcon::HTuple &GrayMatchMethod, const Halcon::HTuple &MaskSize, const Halcon::HTuple &HomMat2DGuide, const Halcon::HTuple &DistanceTolerance, const Halcon::HTuple &MatchThreshold, const Halcon::HTuple &EstimationMethod, const Halcon::HTuple &DistanceThreshold, const Halcon::HTuple &RandSeed, Halcon::HTuple *Points1, Halcon::HTuple *Points2) const;
  // Compute a projective transformation matrix between two images by
  // finding correspondences between points.
  virtual HTuple ProjMatchPointsRansac(const HImage &Image2, const Halcon::HTuple &Rows1, const Halcon::HTuple &Cols1, const Halcon::HTuple &Rows2, const Halcon::HTuple &Cols2, const Halcon::HTuple &GrayMatchMethod, const Halcon::HTuple &MaskSize, const Halcon::HTuple &RowMove, const Halcon::HTuple &ColMove, const Halcon::HTuple &RowTolerance, const Halcon::HTuple &ColTolerance, const Halcon::HTuple &Rotation, const Halcon::HTuple &MatchThreshold, const Halcon::HTuple &EstimationMethod, const Halcon::HTuple &DistanceThreshold, const Halcon::HTuple &RandSeed, Halcon::HTuple *Points1, Halcon::HTuple *Points2) const;
  // Receive an image over a socket connection.
  static HImage ReceiveImage(const Halcon::HSocket &Socket);
  // Send an image over a socket connection.
  virtual void SendImage(const Halcon::HSocket &Socket) const;
  // Compute the distance values for a rectified stereo image pair using
  // multi-scanline optimization.
  virtual HImage BinocularDistanceMs(const HImage &ImageRect2, HImage *Score, const Halcon::HTuple &CamParamRect1, const Halcon::HTuple &CamParamRect2, const Halcon::HTuple &RelPoseRect, const Halcon::HTuple &MinDisparity, const Halcon::HTuple &MaxDisparity, const Halcon::HTuple &SurfaceSmoothing, const Halcon::HTuple &EdgeSmoothing, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue) const;
  // Compute the disparities of a rectified stereo image pair using
  // multi-scanline optimization.
  virtual HImage BinocularDisparityMs(const HImage &ImageRect2, HImage *Score, const Halcon::HTuple &MinDisparity, const Halcon::HTuple &MaxDisparity, const Halcon::HTuple &SurfaceSmoothing, const Halcon::HTuple &EdgeSmoothing, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue) const;
  // Compute the disparities of a rectified stereo image pair using
  // multi-scanline optimization.
  virtual HImage BinocularDisparityMs(const HImage &ImageRect2, HImage *Score, Hlong MinDisparity, Hlong MaxDisparity, Hlong SurfaceSmoothing, Hlong EdgeSmoothing, const char *GenParamName, const char *GenParamValue) const;
  // Compute the distance values for a rectified stereo image pair using
  // multigrid methods.
  virtual HImage BinocularDistanceMg(const HImage &ImageRect2, HImage *Score, const Halcon::HTuple &CamParamRect1, const Halcon::HTuple &CamParamRect2, const Halcon::HTuple &RelPoseRect, const Halcon::HTuple &GrayConstancy, const Halcon::HTuple &GradientConstancy, const Halcon::HTuple &Smoothness, const Halcon::HTuple &InitialGuess, const Halcon::HTuple &CalculateScore, const Halcon::HTuple &MGParamName, const Halcon::HTuple &MGParamValue) const;
  // Compute the distance values for a rectified stereo image pair using
  // multigrid methods.
  virtual HImage BinocularDistanceMg(const HImageArray &ImageRect2, HImage *Score, const Halcon::HTuple &CamParamRect1, const Halcon::HTuple &CamParamRect2, const Halcon::HTuple &RelPoseRect, const Halcon::HTuple &GrayConstancy, const Halcon::HTuple &GradientConstancy, const Halcon::HTuple &Smoothness, const Halcon::HTuple &InitialGuess, const Halcon::HTuple &CalculateScore, const Halcon::HTuple &MGParamName, const Halcon::HTuple &MGParamValue) const;
  // Compute the disparities of a rectified stereo image pair using multigrid
  // methods.
  virtual HImage BinocularDisparityMg(const HImage &ImageRect2, HImage *Score, const Halcon::HTuple &GrayConstancy, const Halcon::HTuple &GradientConstancy, const Halcon::HTuple &Smoothness, const Halcon::HTuple &InitialGuess, const Halcon::HTuple &CalculateScore, const Halcon::HTuple &MGParamName, const Halcon::HTuple &MGParamValue) const;
  // Compute the disparities of a rectified stereo image pair using multigrid
  // methods.
  virtual HImage BinocularDisparityMg(const HImageArray &ImageRect2, HImage *Score, const Halcon::HTuple &GrayConstancy, const Halcon::HTuple &GradientConstancy, const Halcon::HTuple &Smoothness, const Halcon::HTuple &InitialGuess, const Halcon::HTuple &CalculateScore, const Halcon::HTuple &MGParamName, const Halcon::HTuple &MGParamValue) const;
  // Compute the projective rectification of weakly calibrated binocular
  // stereo images.
  static HImage GenBinocularProjRectification(HImage *Map2, const Halcon::HTuple &FMatrix, const Halcon::HTuple &CovFMat, const Halcon::HTuple &Width1, const Halcon::HTuple &Height1, const Halcon::HTuple &Width2, const Halcon::HTuple &Height2, const Halcon::HTuple &SubSampling, const Halcon::HTuple &Mapping, Halcon::HTuple *CovFMatRect, Halcon::HTuple *H1, Halcon::HTuple *H2);
  // Compute the fundamental matrix and the radial distortion coefficient
  // for a pair of stereo images by automatically finding correspondences
  // between image points.
  virtual HTuple MatchFundamentalMatrixDistortionRansac(const HImage &Image2, const Halcon::HTuple &Rows1, const Halcon::HTuple &Cols1, const Halcon::HTuple &Rows2, const Halcon::HTuple &Cols2, const Halcon::HTuple &GrayMatchMethod, const Halcon::HTuple &MaskSize, const Halcon::HTuple &RowMove, const Halcon::HTuple &ColMove, const Halcon::HTuple &RowTolerance, const Halcon::HTuple &ColTolerance, const Halcon::HTuple &Rotation, const Halcon::HTuple &MatchThreshold, const Halcon::HTuple &EstimationMethod, const Halcon::HTuple &DistanceThreshold, const Halcon::HTuple &RandSeed, Halcon::HTuple *Kappa, Halcon::HTuple *Error, Halcon::HTuple *Points1, Halcon::HTuple *Points2) const;
  // Compute the relative orientation between two cameras by automatically
  // finding correspondences between image points.
  virtual HTuple MatchRelPoseRansac(const HImage &Image2, const Halcon::HTuple &Rows1, const Halcon::HTuple &Cols1, const Halcon::HTuple &Rows2, const Halcon::HTuple &Cols2, const Halcon::HTuple &CamPar1, const Halcon::HTuple &CamPar2, const Halcon::HTuple &GrayMatchMethod, const Halcon::HTuple &MaskSize, const Halcon::HTuple &RowMove, const Halcon::HTuple &ColMove, const Halcon::HTuple &RowTolerance, const Halcon::HTuple &ColTolerance, const Halcon::HTuple &Rotation, const Halcon::HTuple &MatchThreshold, const Halcon::HTuple &EstimationMethod, const Halcon::HTuple &DistanceThreshold, const Halcon::HTuple &RandSeed, Halcon::HTuple *CovRelPose, Halcon::HTuple *Error, Halcon::HTuple *Points1, Halcon::HTuple *Points2) const;
  // Compute the essential matrix for a pair of stereo images by automatically
  // finding correspondences between image points.
  virtual HTuple MatchEssentialMatrixRansac(const HImage &Image2, const Halcon::HTuple &Rows1, const Halcon::HTuple &Cols1, const Halcon::HTuple &Rows2, const Halcon::HTuple &Cols2, const Halcon::HTuple &CamMat1, const Halcon::HTuple &CamMat2, const Halcon::HTuple &GrayMatchMethod, const Halcon::HTuple &MaskSize, const Halcon::HTuple &RowMove, const Halcon::HTuple &ColMove, const Halcon::HTuple &RowTolerance, const Halcon::HTuple &ColTolerance, const Halcon::HTuple &Rotation, const Halcon::HTuple &MatchThreshold, const Halcon::HTuple &EstimationMethod, const Halcon::HTuple &DistanceThreshold, const Halcon::HTuple &RandSeed, Halcon::HTuple *CovEMat, Halcon::HTuple *Error, Halcon::HTuple *Points1, Halcon::HTuple *Points2) const;
  // Compute the fundamental matrix for a pair of stereo images by
  // automatically finding correspondences between image
  // points.
  virtual HTuple MatchFundamentalMatrixRansac(const HImage &Image2, const Halcon::HTuple &Rows1, const Halcon::HTuple &Cols1, const Halcon::HTuple &Rows2, const Halcon::HTuple &Cols2, const Halcon::HTuple &GrayMatchMethod, const Halcon::HTuple &MaskSize, const Halcon::HTuple &RowMove, const Halcon::HTuple &ColMove, const Halcon::HTuple &RowTolerance, const Halcon::HTuple &ColTolerance, const Halcon::HTuple &Rotation, const Halcon::HTuple &MatchThreshold, const Halcon::HTuple &EstimationMethod, const Halcon::HTuple &DistanceThreshold, const Halcon::HTuple &RandSeed, Halcon::HTuple *CovFMat, Halcon::HTuple *Error, Halcon::HTuple *Points1, Halcon::HTuple *Points2) const;
  // Compute the distance values for a rectified stereo image pair using correlation
  // techniques.
  virtual HImage BinocularDistance(const HImage &ImageRect2, HImage *Score, const Halcon::HTuple &CamParamRect1, const Halcon::HTuple &CamParamRect2, const Halcon::HTuple &RelPoseRect, const Halcon::HTuple &Method, const Halcon::HTuple &MaskWidth, const Halcon::HTuple &MaskHeight, const Halcon::HTuple &TextureThresh, const Halcon::HTuple &MinDisparity, const Halcon::HTuple &MaxDisparity, const Halcon::HTuple &NumLevels, const Halcon::HTuple &ScoreThresh, const Halcon::HTuple &Filter, const Halcon::HTuple &SubDistance) const;
  // Compute the disparities of a rectified image pair using correlation
  // techniques.
  virtual HImage BinocularDisparity(const HImage &ImageRect2, HImage *Score, const Halcon::HTuple &Method, const Halcon::HTuple &MaskWidth, const Halcon::HTuple &MaskHeight, const Halcon::HTuple &TextureThresh, const Halcon::HTuple &MinDisparity, const Halcon::HTuple &MaxDisparity, const Halcon::HTuple &NumLevels, const Halcon::HTuple &ScoreThresh, const Halcon::HTuple &Filter, const Halcon::HTuple &SubDisparity) const;
  // Compute the disparities of a rectified image pair using correlation
  // techniques.
  virtual HImage BinocularDisparity(const HImage &ImageRect2, HImage *Score, const char *Method, Hlong MaskWidth, Hlong MaskHeight, double TextureThresh, Hlong MinDisparity, Hlong MaxDisparity, Hlong NumLevels, double ScoreThresh, const char *Filter, const char *SubDisparity) const;
  // Generate transformation maps that describe the mapping of the images of a
  // binocular camera pair to a common rectified image plane.
  static HImage GenBinocularRectificationMap(HImage *Map2, const Halcon::HTuple &CamParam1, const Halcon::HTuple &CamParam2, const Halcon::HTuple &RelPose, const Halcon::HTuple &SubSampling, const Halcon::HTuple &Method, const Halcon::HTuple &MapType, Halcon::HTuple *CamParamRect1, Halcon::HTuple *CamParamRect2, Halcon::HTuple *CamPoseRect1, Halcon::HTuple *CamPoseRect2, Halcon::HTuple *RelPoseRect);
  // Get the iconic results of a measurement performed with the sheet-of light
  // technique.
  static HImage GetSheetOfLightResult(const Halcon::HSheetOfLightModel &SheetOfLightModelID, const Halcon::HTuple &ResultName);
  // Get the iconic results of a measurement performed with the sheet-of light
  // technique.
  static HImage GetSheetOfLightResult(const Halcon::HSheetOfLightModel &SheetOfLightModelID, const char *ResultName);
  // Apply the calibration transformations to the input disparity image.
  virtual void ApplySheetOfLightCalibration(const Halcon::HSheetOfLightModel &SheetOfLightModelID) const;
  // Set sheet of light profiles by measured disparities.
  virtual void SetProfileSheetOfLight(const Halcon::HSheetOfLightModel &SheetOfLightModelID, const Halcon::HTuple &MovementPoses) const;
  // Process the profile image provided as input and store the resulting
  // disparity to the sheet-of-light model.
  virtual void MeasureProfileSheetOfLight(const Halcon::HSheetOfLightModel &SheetOfLightModelID, const Halcon::HTuple &MovementPose) const;
  // Shade a height field.
  virtual HImage ShadeHeightField(const Halcon::HTuple &Slant, const Halcon::HTuple &Tilt, const Halcon::HTuple &Albedo, const Halcon::HTuple &Ambient, const Halcon::HTuple &Shadows) const;
  // Shade a height field.
  virtual HImage ShadeHeightField(double Slant, double Tilt, double Albedo, double Ambient, const char *Shadows) const;
  // Estimate the albedo of a surface and the amount of ambient light.
  virtual double EstimateAlAm(double *Ambient) const;
  // Estimate the slant of a light source and the albedo of a surface.
  virtual double EstimateSlAlZc(double *Albedo) const;
  // Estimate the slant of a light source and the albedo of a surface.
  virtual double EstimateSlAlLr(double *Albedo) const;
  // Estimate the tilt of a light source.
  virtual double EstimateTiltZc(void) const;
  // Estimate the tilt of a light source.
  virtual double EstimateTiltLr(void) const;
  // Reconstruct a surface from at least three gray value images.
  virtual HImage PhotStereo(const Halcon::HTuple &Slants, const Halcon::HTuple &Tilts) const;
  // Reconstruct a surface from surface gradients.
  virtual HImage ReconstructHeightFieldFromGradient(const Halcon::HTuple &ReconstructionMethod, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue) const;
  // Reconstruct a surface according to the photometric stereo technique.
  virtual HImage PhotometricStereo(HImage *Gradient, HImage *Albedo, const Halcon::HTuple &Slants, const Halcon::HTuple &Tilts, const Halcon::HTuple &ResultType, const Halcon::HTuple &ReconstructionMethod, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue) const;
  // Reconstruct a surface from a gray value image.
  virtual HImage SfsPentland(const Halcon::HTuple &Slant, const Halcon::HTuple &Tilt, const Halcon::HTuple &Albedo, const Halcon::HTuple &Ambient) const;
  // Reconstruct a surface from a gray value image.
  virtual HImage SfsPentland(double Slant, double Tilt, double Albedo, double Ambient) const;
  // Reconstruct a surface from a gray value image.
  virtual HImage SfsOrigLr(const Halcon::HTuple &Slant, const Halcon::HTuple &Tilt, const Halcon::HTuple &Albedo, const Halcon::HTuple &Ambient) const;
  // Reconstruct a surface from a gray value image.
  virtual HImage SfsOrigLr(double Slant, double Tilt, double Albedo, double Ambient) const;
  // Reconstruct a surface from a gray value image.
  virtual HImage SfsModLr(const Halcon::HTuple &Slant, const Halcon::HTuple &Tilt, const Halcon::HTuple &Albedo, const Halcon::HTuple &Ambient) const;
  // Reconstruct a surface from a gray value image.
  virtual HImage SfsModLr(double Slant, double Tilt, double Albedo, double Ambient) const;
  // Find text in an image.
  virtual HTextResult FindText(const Halcon::HTextModel &TextModel) const;
  // Classify an image with a k-Nearest-Neighbor classifier.
  virtual HRegionArray ClassifyImageClassKnn(HImage *DistanceImage, const Halcon::HClassKnn &KNNHandle, const Halcon::HTuple &RejectionThreshold) const;
  // Classify an image with a k-Nearest-Neighbor classifier.
  virtual HRegionArray ClassifyImageClassKnn(HImage *DistanceImage, const Halcon::HClassKnn &KNNHandle, double RejectionThreshold) const;
  // Classify an image with a Gaussian Mixture Model.
  virtual HRegionArray ClassifyImageClassGmm(const Halcon::HClassGmm &GMMHandle, const Halcon::HTuple &RejectionThreshold) const;
  // Classify an image with a Gaussian Mixture Model.
  virtual HRegionArray ClassifyImageClassGmm(const Halcon::HClassGmm &GMMHandle, double RejectionThreshold) const;
  // Classify an image with a support vector machine.
  virtual HRegionArray ClassifyImageClassSvm(const Halcon::HClassSvm &SVMHandle) const;
  // Classify an image with a multilayer perceptron.
  virtual HRegionArray ClassifyImageClassMlp(const Halcon::HClassMlp &MLPHandle, const Halcon::HTuple &RejectionThreshold) const;
  // Classify an image with a multilayer perceptron.
  virtual HRegionArray ClassifyImageClassMlp(const Halcon::HClassMlp &MLPHandle, double RejectionThreshold) const;
  // Classify pixels using hyper-cuboids.
  virtual HRegionArray ClassNdimBox(const Halcon::HClassBox &ClassifHandle) const;
  // Classify pixels using hyper-spheres or hyper-cubes.
  virtual HRegionArray ClassNdimNorm(const Halcon::HTuple &Metric, const Halcon::HTuple &SingleMultiple, const Halcon::HTuple &Radius, const Halcon::HTuple &Center) const;
  // Classify pixels using hyper-spheres or hyper-cubes.
  virtual HRegionArray ClassNdimNorm(const char *Metric, const char *SingleMultiple, double Radius, double Center) const;
  // Segment an image using two-dimensional pixel classification.
  virtual HRegion Class2dimSup(const HImage &ImageRow, const HRegion &FeatureSpace) const;
  // Segment an image using two-dimensional pixel classification.
  virtual HRegion Class2dimSup(const HImageArray &ImageRow, const HRegionArray &FeatureSpace) const;
  // Segment two images by clustering.
  virtual HRegionArray Class2dimUnsup(const HImage &Image2, const Halcon::HTuple &Threshold, const Halcon::HTuple &NumClasses) const;
  // Segment two images by clustering.
  virtual HRegionArray Class2dimUnsup(const HImage &Image2, Hlong Threshold, Hlong NumClasses) const;
  // Compare two images pixel by pixel.
  virtual HRegion CheckDifference(const HImage &Pattern, const Halcon::HTuple &Mode, const Halcon::HTuple &DiffLowerBound, const Halcon::HTuple &DiffUpperBound, const Halcon::HTuple &GrayOffset, const Halcon::HTuple &AddRow, const Halcon::HTuple &AddCol) const;
  // Compare two images pixel by pixel.
  virtual HRegion CheckDifference(const HImage &Pattern, const char *Mode, Hlong DiffLowerBound, Hlong DiffUpperBound, Hlong GrayOffset, Hlong AddRow, Hlong AddCol) const;
  // Compare two images pixel by pixel.
  virtual HRegion CheckDifference(const HImageArray &Pattern, const Halcon::HTuple &Mode, const Halcon::HTuple &DiffLowerBound, const Halcon::HTuple &DiffUpperBound, const Halcon::HTuple &GrayOffset, const Halcon::HTuple &AddRow, const Halcon::HTuple &AddCol) const;
  // Compare two images pixel by pixel.
  virtual HRegion CheckDifference(const HImageArray &Pattern, const char *Mode, Hlong DiffLowerBound, Hlong DiffUpperBound, Hlong GrayOffset, Hlong AddRow, Hlong AddCol) const;
  // Perform a threshold segmentation for extracting characters.
  virtual HRegion CharThreshold(const HRegion &HistoRegion, const Halcon::HTuple &Sigma, const Halcon::HTuple &Percent, Hlong *Threshold) const;
  // Perform a threshold segmentation for extracting characters.
  virtual HRegion CharThreshold(const HRegion &HistoRegion, double Sigma, double Percent, Hlong *Threshold) const;
  // Extract regions with equal gray values from an image.
  virtual HRegionArray LabelToRegion(void) const;
  // Suppress non-maximum points on an edge.
  virtual HImage NonmaxSuppressionAmp(const Halcon::HTuple &Mode) const;
  // Suppress non-maximum points on an edge.
  virtual HImage NonmaxSuppressionAmp(const char *Mode) const;
  // Suppress non-maximum points on an edge using a direction image.
  virtual HImage NonmaxSuppressionDir(const HImage &ImgDir, const Halcon::HTuple &Mode) const;
  // Suppress non-maximum points on an edge using a direction image.
  virtual HImage NonmaxSuppressionDir(const HImage &ImgDir, const char *Mode) const;
  // Suppress non-maximum points on an edge using a direction image.
  virtual HImage NonmaxSuppressionDir(const HImageArray &ImgDir, const Halcon::HTuple &Mode) const;
  // Suppress non-maximum points on an edge using a direction image.
  virtual HImage NonmaxSuppressionDir(const HImageArray &ImgDir, const char *Mode) const;
  // Perform a hysteresis threshold operation on an image.
  virtual HRegion HysteresisThreshold(const Halcon::HTuple &Low, const Halcon::HTuple &High, const Halcon::HTuple &MaxLength) const;
  // Perform a hysteresis threshold operation on an image.
  virtual HRegion HysteresisThreshold(Hlong Low, Hlong High, Hlong MaxLength) const;
  // Segment an image using binary thresholding.
  virtual HRegion BinaryThreshold(const Halcon::HTuple &Method, const Halcon::HTuple &LightDark, Hlong *UsedThreshold) const;
  // Segment an image using binary thresholding.
  virtual HRegion BinaryThreshold(const char *Method, const char *LightDark, Hlong *UsedThreshold) const;
  // Segment an image using local thresholding.
  virtual HRegion LocalThreshold(const Halcon::HTuple &Method, const Halcon::HTuple &LightDark, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue) const;
  // Segment an image using local thresholding.
  virtual HRegion LocalThreshold(const char *Method, const char *LightDark, const char *GenParamName, Hlong GenParamValue) const;
  // Threshold an image by local mean and standard deviation analysis.
  virtual HRegion VarThreshold(const Halcon::HTuple &MaskWidth, const Halcon::HTuple &MaskHeight, const Halcon::HTuple &StdDevScale, const Halcon::HTuple &AbsThreshold, const Halcon::HTuple &LightDark) const;
  // Threshold an image by local mean and standard deviation analysis.
  virtual HRegion VarThreshold(Hlong MaskWidth, Hlong MaskHeight, double StdDevScale, double AbsThreshold, const char *LightDark) const;
  // Segment an image using a local threshold.
  virtual HRegion DynThreshold(const HImage &ThresholdImage, const Halcon::HTuple &Offset, const Halcon::HTuple &LightDark) const;
  // Segment an image using a local threshold.
  virtual HRegion DynThreshold(const HImage &ThresholdImage, double Offset, const char *LightDark) const;
  // Segment an image using a local threshold.
  virtual HRegion DynThreshold(const HImageArray &ThresholdImage, const Halcon::HTuple &Offset, const Halcon::HTuple &LightDark) const;
  // Segment an image using a local threshold.
  virtual HRegion DynThreshold(const HImageArray &ThresholdImage, double Offset, const char *LightDark) const;
  // Segment an image using global threshold.
  virtual HRegion Threshold(const Halcon::HTuple &MinGray, const Halcon::HTuple &MaxGray) const;
  // Segment an image using global threshold.
  virtual HRegion Threshold(double MinGray, double MaxGray) const;
  // Extract level crossings from an image with subpixel accuracy.
  virtual HXLDContArray ThresholdSubPix(const Halcon::HTuple &Threshold) const;
  // Extract level crossings from an image with subpixel accuracy.
  virtual HXLDContArray ThresholdSubPix(double Threshold) const;
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
  // Segment an image by "pouring water" over it.
  virtual HRegionArray Pouring(const Halcon::HTuple &Mode, const Halcon::HTuple &MinGray, const Halcon::HTuple &MaxGray) const;
  // Segment an image by "pouring water" over it.
  virtual HRegionArray Pouring(const char *Mode, Hlong MinGray, Hlong MaxGray) const;
  // Extract watershed basins from an image using a threshold.
  virtual HRegionArray WatershedsThreshold(const Halcon::HTuple &Threshold) const;
  // Extract watershed basins from an image using a threshold.
  virtual HRegionArray WatershedsThreshold(Hlong Threshold) const;
  // Extract watersheds and basins from an image.
  virtual HRegionArray Watersheds(HRegion *Watersheds) const;
  // Extract zero crossings from an image.
  virtual HRegion ZeroCrossing(void) const;
  // Extract zero crossings from an image with subpixel accuracy.
  virtual HXLDContArray ZeroCrossingSubPix(void) const;
  // Threshold operator for signed images.
  virtual HRegionArray DualThreshold(const Halcon::HTuple &MinSize, const Halcon::HTuple &MinGray, const Halcon::HTuple &Threshold) const;
  // Threshold operator for signed images.
  virtual HRegionArray DualThreshold(Hlong MinSize, double MinGray, double Threshold) const;
  // Expand a region starting at a given line.
  virtual HRegion ExpandLine(const Halcon::HTuple &Coordinate, const Halcon::HTuple &ExpandType, const Halcon::HTuple &RowColumn, const Halcon::HTuple &Threshold) const;
  // Expand a region starting at a given line.
  virtual HRegion ExpandLine(Hlong Coordinate, const char *ExpandType, const char *RowColumn, double Threshold) const;
  // Detect all local minima in an image.
  virtual HRegion LocalMin(void) const;
  // Detect all gray value lowlands.
  virtual HRegionArray Lowlands(void) const;
  // Detect the centers of all gray value lowlands.
  virtual HRegionArray LowlandsCenter(void) const;
  // Detect all local maxima in an image.
  virtual HRegion LocalMax(void) const;
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
  virtual HRegion BinThreshold(void) const;
  // Fast thresholding of images using global thresholds.
  virtual HRegion FastThreshold(const Halcon::HTuple &MinGray, const Halcon::HTuple &MaxGray, const Halcon::HTuple &MinSize) const;
  // Fast thresholding of images using global thresholds.
  virtual HRegion FastThreshold(double MinGray, double MaxGray, Hlong MinSize) const;
  // Set single gray values in an image.
  virtual void SetGrayval(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Grayval) const;
  // Set single gray values in an image.
  virtual void SetGrayval(Hlong Row, Hlong Column, double Grayval) const;
  // Overpaint regions in an image.
  virtual void OverpaintRegion(const HRegion &Region, const Halcon::HTuple &Grayval, const Halcon::HTuple &Type) const;
  // Overpaint regions in an image.
  virtual void OverpaintRegion(const HRegion &Region, double Grayval, const char *Type) const;
  // Overpaint regions in an image.
  virtual void OverpaintRegion(const HRegionArray &Region, const Halcon::HTuple &Grayval, const Halcon::HTuple &Type) const;
  // Overpaint regions in an image.
  virtual void OverpaintRegion(const HRegionArray &Region, double Grayval, const char *Type) const;
  // Create an image with a specified constant gray value.
  virtual HImage GenImageProto(const Halcon::HTuple &Grayval) const;
  // Create an image with a specified constant gray value.
  virtual HImage GenImageProto(double Grayval) const;
  // Paint the gray values of an image into another image.
  virtual HImage PaintGray(const HImage &ImageDestination) const;
  // Overpaint the gray values of an image.
  virtual void OverpaintGray(const HImage &ImageSource) const;
  // Copy an image and allocate new memory for it.
  virtual HImage CopyImage(void) const;
  // Create a three-channel image from a pointer to the interleaved pixels.
  static HImage GenImageInterleaved(const Halcon::HTuple &PixelPointer, const Halcon::HTuple &ColorFormat, const Halcon::HTuple &OriginalWidth, const Halcon::HTuple &OriginalHeight, const Halcon::HTuple &Alignment, const Halcon::HTuple &Type, const Halcon::HTuple &ImageWidth, const Halcon::HTuple &ImageHeight, const Halcon::HTuple &StartRow, const Halcon::HTuple &StartColumn, const Halcon::HTuple &BitsPerChannel, const Halcon::HTuple &BitShift);
  // Create a three-channel image from a pointer to the interleaved pixels.
  static HImage GenImageInterleaved(Hlong PixelPointer, const char *ColorFormat, Hlong OriginalWidth, Hlong OriginalHeight, Hlong Alignment, const char *Type, Hlong ImageWidth, Hlong ImageHeight, Hlong StartRow, Hlong StartColumn, Hlong BitsPerChannel, Hlong BitShift);
  // Create an image from three pointers to the pixels (red/green/blue).
  static HImage GenImage3(const Halcon::HTuple &Type, const Halcon::HTuple &Width, const Halcon::HTuple &Height, const Halcon::HTuple &PixelPointerRed, const Halcon::HTuple &PixelPointerGreen, const Halcon::HTuple &PixelPointerBlue);
  // Create an image from three pointers to the pixels (red/green/blue).
  static HImage GenImage3(const char *Type, Hlong Width, Hlong Height, Hlong PixelPointerRed, Hlong PixelPointerGreen, Hlong PixelPointerBlue);
  // Create an image from a pointer to the pixels.
  static HImage GenImage1(const Halcon::HTuple &Type, const Halcon::HTuple &Width, const Halcon::HTuple &Height, const Halcon::HTuple &PixelPointer);
  // Create an image from a pointer to the pixels.
  static HImage GenImage1(const char *Type, Hlong Width, Hlong Height, Hlong PixelPointer);
  // Create an image with constant gray value.
  static HImage GenImageConst(const Halcon::HTuple &Type, const Halcon::HTuple &Width, const Halcon::HTuple &Height);
  // Create an image with constant gray value.
  static HImage GenImageConst(const char *Type, Hlong Width, Hlong Height);
  // Create a gray value ramp.
  static HImage GenImageGrayRamp(const Halcon::HTuple &Alpha, const Halcon::HTuple &Beta, const Halcon::HTuple &Mean, const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Width, const Halcon::HTuple &Height);
  // Create a gray value ramp.
  static HImage GenImageGrayRamp(double Alpha, double Beta, double Mean, Hlong Row, Hlong Column, Hlong Width, Hlong Height);
  // Create a three-channel image from three pointers on the pixels with storage
  // management.
  static HImage GenImage3Extern(const Halcon::HTuple &Type, const Halcon::HTuple &Width, const Halcon::HTuple &Height, const Halcon::HTuple &PointerRed, const Halcon::HTuple &PointerGreen, const Halcon::HTuple &PointerBlue, const Halcon::HTuple &ClearProc);
  // Create a three-channel image from three pointers on the pixels with storage
  // management.
  static HImage GenImage3Extern(const char *Type, Hlong Width, Hlong Height, Hlong PointerRed, Hlong PointerGreen, Hlong PointerBlue, Hlong ClearProc);
  // Create an image from a pointer on the pixels with storage management.
  static HImage GenImage1Extern(const Halcon::HTuple &Type, const Halcon::HTuple &Width, const Halcon::HTuple &Height, const Halcon::HTuple &PixelPointer, const Halcon::HTuple &ClearProc);
  // Create an image from a pointer on the pixels with storage management.
  static HImage GenImage1Extern(const char *Type, Hlong Width, Hlong Height, Hlong PixelPointer, Hlong ClearProc);
  // Create an image with a rectangular domain from a pointer on the pixels
  // (with storage management).
  static HImage GenImage1Rect(const Halcon::HTuple &PixelPointer, const Halcon::HTuple &Width, const Halcon::HTuple &Height, const Halcon::HTuple &VerticalPitch, const Halcon::HTuple &HorizontalBitPitch, const Halcon::HTuple &BitsPerPixel, const Halcon::HTuple &DoCopy, const Halcon::HTuple &ClearProc);
  // Create an image with a rectangular domain from a pointer on the pixels
  // (with storage management).
  static HImage GenImage1Rect(Hlong PixelPointer, Hlong Width, Hlong Height, Hlong VerticalPitch, Hlong HorizontalBitPitch, Hlong BitsPerPixel, const char *DoCopy, Hlong ClearProc);
  // Access to the image data pointer and the image data inside
  // the smallest rectangle of the domain of the input image.
  virtual Hlong GetImagePointer1Rect(Halcon::HTuple *Width, Halcon::HTuple *Height, Halcon::HTuple *VerticalPitch, Halcon::HTuple *HorizontalBitPitch, Halcon::HTuple *BitsPerPixel) const;
  // Access the pointers of a colored image.
  virtual Hlong GetImagePointer3(Hlong *PointerGreen, Hlong *PointerBlue, char *Type, Hlong *Width, Hlong *Height) const;
  // Access the pointer of a channel.
  virtual Hlong GetImagePointer1(char *Type, Hlong *Width, Hlong *Height) const;
  // Return the type of an image.
  virtual HTuple GetImageType(void) const;
  // Return the size of an image.
  virtual Hlong GetImageSize(Hlong *Height) const;
  // Request time at which the image was created.
  virtual Hlong GetImageTime(Halcon::HTuple *Second, Halcon::HTuple *Minute, Halcon::HTuple *Hour, Halcon::HTuple *Day, Halcon::HTuple *YDay, Halcon::HTuple *Month, Halcon::HTuple *Year) const;
  // Return gray values of an image at the positions given by tuples of
  // rows and columns.
  virtual HTuple GetGrayvalInterpolated(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Interpolation) const;
  // Return gray values of an image at the positions given by tuples of
  // rows and columns.
  virtual HTuple GetGrayvalInterpolated(double Row, double Column, const char *Interpolation) const;
  // Access the gray values of an image object.
  virtual HTuple GetGrayval(const Halcon::HTuple &Row, const Halcon::HTuple &Column) const;
  // Access the gray values of an image object.
  virtual HTuple GetGrayval(Hlong Row, Hlong Column) const;
  // Verification of a pattern using an OCV tool.
  virtual double DoOcvSimple(const Halcon::HOCV &OCVHandle, const Halcon::HTuple &PatternName, const Halcon::HTuple &AdaptPos, const Halcon::HTuple &AdaptSize, const Halcon::HTuple &AdaptAngle, const Halcon::HTuple &AdaptGray, const Halcon::HTuple &Threshold) const;
  // Verification of a pattern using an OCV tool.
  virtual double DoOcvSimple(const Halcon::HOCV &OCVHandle, const char *PatternName, const char *AdaptPos, const char *AdaptSize, const char *AdaptAngle, const char *AdaptGray, double Threshold) const;
  // Training of an OCV tool.
  virtual void TraindOcvProj(const Halcon::HOCV &OCVHandle, const Halcon::HTuple &Name, const Halcon::HTuple &Mode) const;
  // Training of an OCV tool.
  virtual void TraindOcvProj(const Halcon::HOCV &OCVHandle, const char *Name, const char *Mode) const;
  // Compute the features of a character.
  virtual HTuple GetFeaturesOcrClassKnn(const Halcon::HOCRKnn &OCRHandle, const Halcon::HTuple &Transform) const;
  // Compute the features of a character.
  virtual HTuple GetFeaturesOcrClassKnn(const Halcon::HOCRKnn &OCRHandle, const char *Transform) const;
  // Compute the features of a character.
  virtual HTuple GetFeaturesOcrClassSvm(const Halcon::HOCRSvm &OCRHandle, const Halcon::HTuple &Transform) const;
  // Compute the features of a character.
  virtual HTuple GetFeaturesOcrClassSvm(const Halcon::HOCRSvm &OCRHandle, const char *Transform) const;
  // Compute the features of a character.
  virtual HTuple GetFeaturesOcrClassMlp(const Halcon::HOCRMlp &OCRHandle, const Halcon::HTuple &Transform) const;
  // Compute the features of a character.
  virtual HTuple GetFeaturesOcrClassMlp(const Halcon::HOCRMlp &OCRHandle, const char *Transform) const;
  // Cut out an image area relative to the domain.
  virtual HImage CropDomainRel(const Halcon::HTuple &Top, const Halcon::HTuple &Left, const Halcon::HTuple &Bottom, const Halcon::HTuple &Right) const;
  // Cut out an image area relative to the domain.
  virtual HImage CropDomainRel(Hlong Top, Hlong Left, Hlong Bottom, Hlong Right) const;
  // Access the features which correspond to a character.
  virtual HTuple OcrGetFeatures(const Halcon::HOCRBox &OcrHandle) const;
  // Write characters into a training file.
  virtual void WriteOcrTrainfImage(const Halcon::HTuple &Class, const Halcon::HTuple &TrainingFile) const;
  // Write characters into a training file.
  virtual void WriteOcrTrainfImage(const char *Class, const char *TrainingFile) const;
  // Perform a gray value bottom hat transformation on an image.
  virtual HImage GrayBothat(const HImage &SE) const;
  // Perform a gray value top hat transformation on an image.
  virtual HImage GrayTophat(const HImage &SE) const;
  // Perform a gray value closing on an image.
  virtual HImage GrayClosing(const HImage &SE) const;
  // Perform a gray value opening on an image.
  virtual HImage GrayOpening(const HImage &SE) const;
  // Perform a gray value dilation on an image.
  virtual HImage GrayDilation(const HImage &SE) const;
  // Perform a gray value erosion on an image.
  virtual HImage GrayErosion(const HImage &SE) const;
  // Load a structuring element for gray morphology.
  static HImage ReadGraySe(const Halcon::HTuple &FileName);
  // Load a structuring element for gray morphology.
  static HImage ReadGraySe(const char *FileName);
  // Generate ellipsoidal structuring elements for gray morphology.
  static HImage GenDiscSe(const Halcon::HTuple &Type, const Halcon::HTuple &Width, const Halcon::HTuple &Height, const Halcon::HTuple &Smax);
  // Generate ellipsoidal structuring elements for gray morphology.
  static HImage GenDiscSe(const char *Type, Hlong Width, Hlong Height, double Smax);
  // Extracting points with a particular gray value along a rectangle or an
  // annular arc.
  virtual HTuple MeasureThresh(const Halcon::HMeasure &MeasureHandle, const Halcon::HTuple &Sigma, const Halcon::HTuple &Threshold, const Halcon::HTuple &Select, Halcon::HTuple *ColumnThresh, Halcon::HTuple *Distance) const;
  // Extracting points with a particular gray value along a rectangle or an
  // annular arc.
  virtual HTuple MeasureThresh(const Halcon::HMeasure &MeasureHandle, double Sigma, double Threshold, const char *Select, Halcon::HTuple *ColumnThresh, Halcon::HTuple *Distance) const;
  // Extract a gray value profile perpendicular to a rectangle or annular arc.
  virtual HTuple MeasureProjection(const Halcon::HMeasure &MeasureHandle) const;
  // Extract straight edge pairs perpendicular to a rectangle or an
  // annular arc.
  virtual HTuple FuzzyMeasurePairing(const Halcon::HMeasure &MeasureHandle, const Halcon::HTuple &Sigma, const Halcon::HTuple &AmpThresh, const Halcon::HTuple &FuzzyThresh, const Halcon::HTuple &Transition, const Halcon::HTuple &Pairing, const Halcon::HTuple &NumPairs, Halcon::HTuple *ColumnEdgeFirst, Halcon::HTuple *AmplitudeFirst, Halcon::HTuple *RowEdgeSecond, Halcon::HTuple *ColumnEdgeSecond, Halcon::HTuple *AmplitudeSecond, Halcon::HTuple *RowPairCenter, Halcon::HTuple *ColumnPairCenter, Halcon::HTuple *FuzzyScore, Halcon::HTuple *IntraDistance) const;
  // Extract straight edge pairs perpendicular to a rectangle or an
  // annular arc.
  virtual HTuple FuzzyMeasurePairing(const Halcon::HMeasure &MeasureHandle, double Sigma, double AmpThresh, double FuzzyThresh, const char *Transition, const char *Pairing, Hlong NumPairs, Halcon::HTuple *ColumnEdgeFirst, Halcon::HTuple *AmplitudeFirst, Halcon::HTuple *RowEdgeSecond, Halcon::HTuple *ColumnEdgeSecond, Halcon::HTuple *AmplitudeSecond, Halcon::HTuple *RowPairCenter, Halcon::HTuple *ColumnPairCenter, Halcon::HTuple *FuzzyScore, Halcon::HTuple *IntraDistance) const;
  // Extract straight edge pairs perpendicular to a rectangle or an annular arc.
  virtual HTuple FuzzyMeasurePairs(const Halcon::HMeasure &MeasureHandle, const Halcon::HTuple &Sigma, const Halcon::HTuple &AmpThresh, const Halcon::HTuple &FuzzyThresh, const Halcon::HTuple &Transition, Halcon::HTuple *ColumnEdgeFirst, Halcon::HTuple *AmplitudeFirst, Halcon::HTuple *RowEdgeSecond, Halcon::HTuple *ColumnEdgeSecond, Halcon::HTuple *AmplitudeSecond, Halcon::HTuple *RowEdgeCenter, Halcon::HTuple *ColumnEdgeCenter, Halcon::HTuple *FuzzyScore, Halcon::HTuple *IntraDistance, Halcon::HTuple *InterDistance) const;
  // Extract straight edge pairs perpendicular to a rectangle or an annular arc.
  virtual HTuple FuzzyMeasurePairs(const Halcon::HMeasure &MeasureHandle, double Sigma, double AmpThresh, double FuzzyThresh, const char *Transition, Halcon::HTuple *ColumnEdgeFirst, Halcon::HTuple *AmplitudeFirst, Halcon::HTuple *RowEdgeSecond, Halcon::HTuple *ColumnEdgeSecond, Halcon::HTuple *AmplitudeSecond, Halcon::HTuple *RowEdgeCenter, Halcon::HTuple *ColumnEdgeCenter, Halcon::HTuple *FuzzyScore, Halcon::HTuple *IntraDistance, Halcon::HTuple *InterDistance) const;
  // Extract straight edges perpendicular to a rectangle or an annular arc.
  virtual HTuple FuzzyMeasurePos(const Halcon::HMeasure &MeasureHandle, const Halcon::HTuple &Sigma, const Halcon::HTuple &AmpThresh, const Halcon::HTuple &FuzzyThresh, const Halcon::HTuple &Transition, Halcon::HTuple *ColumnEdge, Halcon::HTuple *Amplitude, Halcon::HTuple *FuzzyScore, Halcon::HTuple *Distance) const;
  // Extract straight edges perpendicular to a rectangle or an annular arc.
  virtual HTuple FuzzyMeasurePos(const Halcon::HMeasure &MeasureHandle, double Sigma, double AmpThresh, double FuzzyThresh, const char *Transition, Halcon::HTuple *ColumnEdge, Halcon::HTuple *Amplitude, Halcon::HTuple *FuzzyScore, Halcon::HTuple *Distance) const;
  // Extract straight edge pairs perpendicular to a rectangle or annular arc.
  virtual HTuple MeasurePairs(const Halcon::HMeasure &MeasureHandle, const Halcon::HTuple &Sigma, const Halcon::HTuple &Threshold, const Halcon::HTuple &Transition, const Halcon::HTuple &Select, Halcon::HTuple *ColumnEdgeFirst, Halcon::HTuple *AmplitudeFirst, Halcon::HTuple *RowEdgeSecond, Halcon::HTuple *ColumnEdgeSecond, Halcon::HTuple *AmplitudeSecond, Halcon::HTuple *IntraDistance, Halcon::HTuple *InterDistance) const;
  // Extract straight edge pairs perpendicular to a rectangle or annular arc.
  virtual HTuple MeasurePairs(const Halcon::HMeasure &MeasureHandle, double Sigma, double Threshold, const char *Transition, const char *Select, Halcon::HTuple *ColumnEdgeFirst, Halcon::HTuple *AmplitudeFirst, Halcon::HTuple *RowEdgeSecond, Halcon::HTuple *ColumnEdgeSecond, Halcon::HTuple *AmplitudeSecond, Halcon::HTuple *IntraDistance, Halcon::HTuple *InterDistance) const;
  // Extract straight edges perpendicular to a rectangle or annular arc.
  virtual HTuple MeasurePos(const Halcon::HMeasure &MeasureHandle, const Halcon::HTuple &Sigma, const Halcon::HTuple &Threshold, const Halcon::HTuple &Transition, const Halcon::HTuple &Select, Halcon::HTuple *ColumnEdge, Halcon::HTuple *Amplitude, Halcon::HTuple *Distance) const;
  // Extract straight edges perpendicular to a rectangle or annular arc.
  virtual HTuple MeasurePos(const Halcon::HMeasure &MeasureHandle, double Sigma, double Threshold, const char *Transition, const char *Select, Halcon::HTuple *ColumnEdge, Halcon::HTuple *Amplitude, Halcon::HTuple *Distance) const;
  // Identify objects with a sample identifier.
  // 
  virtual HTuple ApplySampleIdentifier(const Halcon::HSampleIdentifier &SampleIdentifier, const Halcon::HTuple &NumResults, const Halcon::HTuple &RatingThreshold, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue, Halcon::HTuple *Rating) const;
  // Add training data to an existing sample identifier.
  // 
  virtual Hlong AddSampleIdentifierTrainingData(const Halcon::HSampleIdentifier &SampleIdentifier, const Halcon::HTuple &ObjectIdx, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue) const;
  // Add preparation data to an existing sample identifier.
  // 
  virtual Hlong AddSampleIdentifierPreparationData(const Halcon::HSampleIdentifier &SampleIdentifier, const Halcon::HTuple &ObjectIdx, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue) const;
  // Determine the parameters of a shape model.
  virtual HTuple DetermineShapeModelParams(const Halcon::HTuple &NumLevels, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &ScaleMin, const Halcon::HTuple &ScaleMax, const Halcon::HTuple &Optimization, const Halcon::HTuple &Metric, const Halcon::HTuple &Contrast, const Halcon::HTuple &MinContrast, const Halcon::HTuple &Parameters, Halcon::HTuple *ParameterValue) const;
  // Determine the parameters of a shape model.
  virtual HTuple DetermineShapeModelParams(Hlong NumLevels, double AngleStart, double AngleExtent, double ScaleMin, double ScaleMax, const char *Optimization, const char *Metric, Hlong Contrast, Hlong MinContrast, const char *Parameters, Halcon::HTuple *ParameterValue) const;
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
  // Find the best matches of an anisotropic scale invariant shape model
  // in an image.
  virtual HTuple FindAnisoShapeModel(const Halcon::HShapeModel &ModelID, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &ScaleRMin, const Halcon::HTuple &ScaleRMax, const Halcon::HTuple &ScaleCMin, const Halcon::HTuple &ScaleCMax, const Halcon::HTuple &MinScore, const Halcon::HTuple &NumMatches, const Halcon::HTuple &MaxOverlap, const Halcon::HTuple &SubPixel, const Halcon::HTuple &NumLevels, const Halcon::HTuple &Greediness, Halcon::HTuple *Column, Halcon::HTuple *Angle, Halcon::HTuple *ScaleR, Halcon::HTuple *ScaleC, Halcon::HTuple *Score) const;
  // Find the best matches of an anisotropic scale invariant shape model
  // in an image.
  virtual HTuple FindAnisoShapeModel(const Halcon::HShapeModel &ModelID, double AngleStart, double AngleExtent, double ScaleRMin, double ScaleRMax, double ScaleCMin, double ScaleCMax, double MinScore, Hlong NumMatches, double MaxOverlap, const char *SubPixel, Hlong NumLevels, double Greediness, Halcon::HTuple *Column, Halcon::HTuple *Angle, Halcon::HTuple *ScaleR, Halcon::HTuple *ScaleC, Halcon::HTuple *Score) const;
  // Find the best matches of a scale invariant shape model in an image.
  virtual HTuple FindScaledShapeModel(const Halcon::HShapeModel &ModelID, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &ScaleMin, const Halcon::HTuple &ScaleMax, const Halcon::HTuple &MinScore, const Halcon::HTuple &NumMatches, const Halcon::HTuple &MaxOverlap, const Halcon::HTuple &SubPixel, const Halcon::HTuple &NumLevels, const Halcon::HTuple &Greediness, Halcon::HTuple *Column, Halcon::HTuple *Angle, Halcon::HTuple *Scale, Halcon::HTuple *Score) const;
  // Find the best matches of a scale invariant shape model in an image.
  virtual HTuple FindScaledShapeModel(const Halcon::HShapeModel &ModelID, double AngleStart, double AngleExtent, double ScaleMin, double ScaleMax, double MinScore, Hlong NumMatches, double MaxOverlap, const char *SubPixel, Hlong NumLevels, double Greediness, Halcon::HTuple *Column, Halcon::HTuple *Angle, Halcon::HTuple *Scale, Halcon::HTuple *Score) const;
  // Find the best matches of a shape model in an image.
  virtual HTuple FindShapeModel(const Halcon::HShapeModel &ModelID, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &MinScore, const Halcon::HTuple &NumMatches, const Halcon::HTuple &MaxOverlap, const Halcon::HTuple &SubPixel, const Halcon::HTuple &NumLevels, const Halcon::HTuple &Greediness, Halcon::HTuple *Column, Halcon::HTuple *Angle, Halcon::HTuple *Score) const;
  // Find the best matches of a shape model in an image.
  virtual HTuple FindShapeModel(const Halcon::HShapeModel &ModelID, double AngleStart, double AngleExtent, double MinScore, Hlong NumMatches, double MaxOverlap, const char *SubPixel, Hlong NumLevels, double Greediness, Halcon::HTuple *Column, Halcon::HTuple *Angle, Halcon::HTuple *Score) const;
  // Set the metric of a shape model that was created from XLD contours.
  virtual void SetShapeModelMetric(const Halcon::HShapeModel &ModelID, const Halcon::HTuple &HomMat2D, const Halcon::HTuple &Metric) const;
  // Prepare a shape model for anisotropic scale invariant matching.
  virtual HShapeModel CreateAnisoShapeModel(const Halcon::HTuple &NumLevels, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &AngleStep, const Halcon::HTuple &ScaleRMin, const Halcon::HTuple &ScaleRMax, const Halcon::HTuple &ScaleRStep, const Halcon::HTuple &ScaleCMin, const Halcon::HTuple &ScaleCMax, const Halcon::HTuple &ScaleCStep, const Halcon::HTuple &Optimization, const Halcon::HTuple &Metric, const Halcon::HTuple &Contrast, const Halcon::HTuple &MinContrast) const;
  // Prepare a shape model for anisotropic scale invariant matching.
  virtual HShapeModel CreateAnisoShapeModel(Hlong NumLevels, double AngleStart, double AngleExtent, double AngleStep, double ScaleRMin, double ScaleRMax, double ScaleRStep, double ScaleCMin, double ScaleCMax, double ScaleCStep, const char *Optimization, const char *Metric, Hlong Contrast, Hlong MinContrast) const;
  // Prepare a shape model for scale invariant matching.
  virtual HShapeModel CreateScaledShapeModel(const Halcon::HTuple &NumLevels, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &AngleStep, const Halcon::HTuple &ScaleMin, const Halcon::HTuple &ScaleMax, const Halcon::HTuple &ScaleStep, const Halcon::HTuple &Optimization, const Halcon::HTuple &Metric, const Halcon::HTuple &Contrast, const Halcon::HTuple &MinContrast) const;
  // Prepare a shape model for scale invariant matching.
  virtual HShapeModel CreateScaledShapeModel(Hlong NumLevels, double AngleStart, double AngleExtent, double AngleStep, double ScaleMin, double ScaleMax, double ScaleStep, const char *Optimization, const char *Metric, Hlong Contrast, Hlong MinContrast) const;
  // Prepare a shape model for matching.
  virtual HShapeModel CreateShapeModel(const Halcon::HTuple &NumLevels, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &AngleStep, const Halcon::HTuple &Optimization, const Halcon::HTuple &Metric, const Halcon::HTuple &Contrast, const Halcon::HTuple &MinContrast) const;
  // Prepare a shape model for matching.
  virtual HShapeModel CreateShapeModel(Hlong NumLevels, double AngleStart, double AngleExtent, double AngleStep, const char *Optimization, const char *Metric, Hlong Contrast, Hlong MinContrast) const;
  // Create the representation of a shape model.
  virtual HImageArray InspectShapeModel(HRegionArray *ModelRegions, const Halcon::HTuple &NumLevels, const Halcon::HTuple &Contrast) const;
  // Create the representation of a shape model.
  virtual HImageArray InspectShapeModel(HRegionArray *ModelRegions, Hlong NumLevels, Hlong Contrast) const;
  // Find the best matches of a calibrated descriptor model in an image and
  // return their 3D pose.
  virtual HTuple FindCalibDescriptorModel(const Halcon::HDescriptorModel &ModelID, const Halcon::HTuple &DetectorParamName, const Halcon::HTuple &DetectorParamValue, const Halcon::HTuple &DescriptorParamName, const Halcon::HTuple &DescriptorParamValue, const Halcon::HTuple &MinScore, const Halcon::HTuple &NumMatches, const Halcon::HTuple &CamParam, const Halcon::HTuple &ScoreType, Halcon::HTuple *Score) const;
  // Find the best matches of a descriptor model in an image.
  virtual HTuple FindUncalibDescriptorModel(const Halcon::HDescriptorModel &ModelID, const Halcon::HTuple &DetectorParamName, const Halcon::HTuple &DetectorParamValue, const Halcon::HTuple &DescriptorParamName, const Halcon::HTuple &DescriptorParamValue, const Halcon::HTuple &MinScore, const Halcon::HTuple &NumMatches, const Halcon::HTuple &ScoreType, Halcon::HTuple *Score) const;
  // Create a descriptor model for calibrated perspective matching.
  virtual HDescriptorModel CreateCalibDescriptorModel(const Halcon::HTuple &CamParam, const Halcon::HTuple &ReferencePose, const Halcon::HTuple &DetectorType, const Halcon::HTuple &DetectorParamName, const Halcon::HTuple &DetectorParamValue, const Halcon::HTuple &DescriptorParamName, const Halcon::HTuple &DescriptorParamValue, const Halcon::HTuple &Seed) const;
  // Prepare a descriptor model for interest point matching.
  virtual HDescriptorModel CreateUncalibDescriptorModel(const Halcon::HTuple &DetectorType, const Halcon::HTuple &DetectorParamName, const Halcon::HTuple &DetectorParamValue, const Halcon::HTuple &DescriptorParamName, const Halcon::HTuple &DescriptorParamValue, const Halcon::HTuple &Seed) const;
  // Determine the parameters of a deformable model.
  virtual HTuple DetermineDeformableModelParams(const Halcon::HTuple &NumLevels, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &ScaleMin, const Halcon::HTuple &ScaleMax, const Halcon::HTuple &Optimization, const Halcon::HTuple &Metric, const Halcon::HTuple &Contrast, const Halcon::HTuple &MinContrast, const Halcon::HTuple &ParamName, const Halcon::HTuple &ParamValue, const Halcon::HTuple &Parameters, Halcon::HTuple *ParameterValue) const;
  // Find the best matches of a local deformable model in an image.
  virtual HImageArray FindLocalDeformableModel(HImageArray *VectorField, HXLDContArray *DeformedContours, const Halcon::HDeformableModel &ModelID, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &ScaleRMin, const Halcon::HTuple &ScaleRMax, const Halcon::HTuple &ScaleCMin, const Halcon::HTuple &ScaleCMax, const Halcon::HTuple &MinScore, const Halcon::HTuple &NumMatches, const Halcon::HTuple &MaxOverlap, const Halcon::HTuple &NumLevels, const Halcon::HTuple &Greediness, const Halcon::HTuple &ResultType, const Halcon::HTuple &ParamName, const Halcon::HTuple &ParamValue, Halcon::HTuple *Score, Halcon::HTuple *Row, Halcon::HTuple *Column) const;
  // Find the best matches of a calibrated deformable model in an image and return
  // their 3D pose.
  virtual HTuple FindPlanarCalibDeformableModel(const Halcon::HDeformableModel &ModelID, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &ScaleRMin, const Halcon::HTuple &ScaleRMax, const Halcon::HTuple &ScaleCMin, const Halcon::HTuple &ScaleCMax, const Halcon::HTuple &MinScore, const Halcon::HTuple &NumMatches, const Halcon::HTuple &MaxOverlap, const Halcon::HTuple &NumLevels, const Halcon::HTuple &Greediness, const Halcon::HTuple &ParamName, const Halcon::HTuple &ParamValue, Halcon::HTuple *CovPose, Halcon::HTuple *Score) const;
  // Find the best matches of a planar projective invariant deformable model
  // in an image.
  virtual HTuple FindPlanarUncalibDeformableModel(const Halcon::HDeformableModel &ModelID, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &ScaleRMin, const Halcon::HTuple &ScaleRMax, const Halcon::HTuple &ScaleCMin, const Halcon::HTuple &ScaleCMax, const Halcon::HTuple &MinScore, const Halcon::HTuple &NumMatches, const Halcon::HTuple &MaxOverlap, const Halcon::HTuple &NumLevels, const Halcon::HTuple &Greediness, const Halcon::HTuple &ParamName, const Halcon::HTuple &ParamValue, Halcon::HTuple *Score) const;
  // Set the metric of a local deformable model that was created from XLD
  // contours.
  virtual void SetLocalDeformableModelMetric(const HImage &VectorField, const Halcon::HDeformableModel &ModelID, const Halcon::HTuple &Metric) const;
  // Set the metric of a local deformable model that was created from XLD
  // contours.
  virtual void SetLocalDeformableModelMetric(const HImage &VectorField, const Halcon::HDeformableModel &ModelID, const char *Metric) const;
  // Set the metric of a planar calibrated deformable model that was created
  // from XLD contours.
  virtual void SetPlanarCalibDeformableModelMetric(const Halcon::HDeformableModel &ModelID, const Halcon::HTuple &Pose, const Halcon::HTuple &Metric) const;
  // Set the metric of a planar uncalibrated deformable model that was created
  // from XLD contours.
  virtual void SetPlanarUncalibDeformableModelMetric(const Halcon::HDeformableModel &ModelID, const Halcon::HTuple &HomMat2D, const Halcon::HTuple &Metric) const;
  // Creates a deformable model for local, deformable matching.
  virtual HDeformableModel CreateLocalDeformableModel(const Halcon::HTuple &NumLevels, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &AngleStep, const Halcon::HTuple &ScaleRMin, const Halcon::HTuple &ScaleRMax, const Halcon::HTuple &ScaleRStep, const Halcon::HTuple &ScaleCMin, const Halcon::HTuple &ScaleCMax, const Halcon::HTuple &ScaleCStep, const Halcon::HTuple &Optimization, const Halcon::HTuple &Metric, const Halcon::HTuple &Contrast, const Halcon::HTuple &MinContrast, const Halcon::HTuple &ParamName, const Halcon::HTuple &ParamValue) const;
  // Create a deformable model for calibrated perspective matching.
  virtual HDeformableModel CreatePlanarCalibDeformableModel(const Halcon::HTuple &CamParam, const Halcon::HTuple &ReferencePose, const Halcon::HTuple &NumLevels, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &AngleStep, const Halcon::HTuple &ScaleRMin, const Halcon::HTuple &ScaleRMax, const Halcon::HTuple &ScaleRStep, const Halcon::HTuple &ScaleCMin, const Halcon::HTuple &ScaleCMax, const Halcon::HTuple &ScaleCStep, const Halcon::HTuple &Optimization, const Halcon::HTuple &Metric, const Halcon::HTuple &Contrast, const Halcon::HTuple &MinContrast, const Halcon::HTuple &ParamName, const Halcon::HTuple &ParamValue) const;
  // Creates a deformable model for uncalibrated, perspective matching.
  virtual HDeformableModel CreatePlanarUncalibDeformableModel(const Halcon::HTuple &NumLevels, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &AngleStep, const Halcon::HTuple &ScaleRMin, const Halcon::HTuple &ScaleRMax, const Halcon::HTuple &ScaleRStep, const Halcon::HTuple &ScaleCMin, const Halcon::HTuple &ScaleCMax, const Halcon::HTuple &ScaleCStep, const Halcon::HTuple &Optimization, const Halcon::HTuple &Metric, const Halcon::HTuple &Contrast, const Halcon::HTuple &MinContrast, const Halcon::HTuple &ParamName, const Halcon::HTuple &ParamValue) const;
  // Find the best matches of an NCC model in an image.
  virtual HTuple FindNccModel(const Halcon::HNCCModel &ModelID, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &MinScore, const Halcon::HTuple &NumMatches, const Halcon::HTuple &MaxOverlap, const Halcon::HTuple &SubPixel, const Halcon::HTuple &NumLevels, Halcon::HTuple *Column, Halcon::HTuple *Angle, Halcon::HTuple *Score) const;
  // Find the best matches of an NCC model in an image.
  virtual HTuple FindNccModel(const Halcon::HNCCModel &ModelID, double AngleStart, double AngleExtent, double MinScore, Hlong NumMatches, double MaxOverlap, const char *SubPixel, Hlong NumLevels, Halcon::HTuple *Column, Halcon::HTuple *Angle, Halcon::HTuple *Score) const;
  // Prepare an NCC model for matching.
  virtual HNCCModel CreateNccModel(const Halcon::HTuple &NumLevels, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &AngleStep, const Halcon::HTuple &Metric) const;
  // Prepare an NCC model for matching.
  virtual HNCCModel CreateNccModel(Hlong NumLevels, double AngleStart, double AngleExtent, double AngleStep, const char *Metric) const;
  // Find the best matches of a component model in an image.
  virtual HTuple FindComponentModel(const Halcon::HComponentModel &ComponentModelID, const Halcon::HTuple &RootComponent, const Halcon::HTuple &AngleStartRoot, const Halcon::HTuple &AngleExtentRoot, const Halcon::HTuple &MinScore, const Halcon::HTuple &NumMatches, const Halcon::HTuple &MaxOverlap, const Halcon::HTuple &IfRootNotFound, const Halcon::HTuple &IfComponentNotFound, const Halcon::HTuple &PosePrediction, const Halcon::HTuple &MinScoreComp, const Halcon::HTuple &SubPixelComp, const Halcon::HTuple &NumLevelsComp, const Halcon::HTuple &GreedinessComp, Halcon::HTuple *ModelEnd, Halcon::HTuple *Score, Halcon::HTuple *RowComp, Halcon::HTuple *ColumnComp, Halcon::HTuple *AngleComp, Halcon::HTuple *ScoreComp, Halcon::HTuple *ModelComp) const;
  // Find the best matches of a component model in an image.
  virtual HTuple FindComponentModel(const Halcon::HComponentModel &ComponentModelID, Hlong RootComponent, double AngleStartRoot, double AngleExtentRoot, double MinScore, Hlong NumMatches, double MaxOverlap, const char *IfRootNotFound, const char *IfComponentNotFound, const char *PosePrediction, double MinScoreComp, const char *SubPixelComp, Hlong NumLevelsComp, double GreedinessComp, Halcon::HTuple *ModelEnd, Halcon::HTuple *Score, Halcon::HTuple *RowComp, Halcon::HTuple *ColumnComp, Halcon::HTuple *AngleComp, Halcon::HTuple *ScoreComp, Halcon::HTuple *ModelComp) const;
  // Prepare a component model for matching based on explicitly specified
  // components and relations.
  virtual HComponentModel CreateComponentModel(const HRegionArray &ComponentRegions, const Halcon::HTuple &VariationRow, const Halcon::HTuple &VariationColumn, const Halcon::HTuple &VariationAngle, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &ContrastLowComp, const Halcon::HTuple &ContrastHighComp, const Halcon::HTuple &MinSizeComp, const Halcon::HTuple &MinContrastComp, const Halcon::HTuple &MinScoreComp, const Halcon::HTuple &NumLevelsComp, const Halcon::HTuple &AngleStepComp, const Halcon::HTuple &OptimizationComp, const Halcon::HTuple &MetricComp, const Halcon::HTuple &PregenerationComp, Hlong *RootRanking) const;
  // Prepare a component model for matching based on explicitly specified
  // components and relations.
  virtual HComponentModel CreateComponentModel(const HRegionArray &ComponentRegions, Hlong VariationRow, Hlong VariationColumn, double VariationAngle, double AngleStart, double AngleExtent, Hlong ContrastLowComp, Hlong ContrastHighComp, Hlong MinSizeComp, Hlong MinContrastComp, double MinScoreComp, Hlong NumLevelsComp, double AngleStepComp, const char *OptimizationComp, const char *MetricComp, const char *PregenerationComp, Hlong *RootRanking) const;
  // Prepare a component model for matching based on explicitly specified
  // components and relations.
  virtual HComponentModel CreateComponentModel(const HRegionArray &ComponentRegions, const Halcon::HTuple &VariationRow, const Halcon::HTuple &VariationColumn, const Halcon::HTuple &VariationAngle, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtent, const Halcon::HTuple &ContrastLowComp, const Halcon::HTuple &ContrastHighComp, const Halcon::HTuple &MinSizeComp, const Halcon::HTuple &MinContrastComp, const Halcon::HTuple &MinScoreComp, const Halcon::HTuple &NumLevelsComp, const Halcon::HTuple &AngleStepComp, const Halcon::HTuple &OptimizationComp, const Halcon::HTuple &MetricComp, const Halcon::HTuple &PregenerationComp, Halcon::HTuple *RootRanking) const;
  // Prepare a component model for matching based on explicitly specified
  // components and relations.
  virtual HComponentModel CreateComponentModel(const HRegionArray &ComponentRegions, Hlong VariationRow, Hlong VariationColumn, double VariationAngle, double AngleStart, double AngleExtent, Hlong ContrastLowComp, Hlong ContrastHighComp, Hlong MinSizeComp, Hlong MinContrastComp, double MinScoreComp, Hlong NumLevelsComp, double AngleStepComp, const char *OptimizationComp, const char *MetricComp, const char *PregenerationComp, Halcon::HTuple *RootRanking) const;
  // Adopt new parameters that are used to create the model components into the
  // training result.
  virtual HRegion ClusterModelComponents(const Halcon::HComponentTraining &ComponentTrainingID, const Halcon::HTuple &AmbiguityCriterion, const Halcon::HTuple &MaxContourOverlap, const Halcon::HTuple &ClusterThreshold) const;
  // Adopt new parameters that are used to create the model components into the
  // training result.
  virtual HRegion ClusterModelComponents(const Halcon::HComponentTraining &ComponentTrainingID, const char *AmbiguityCriterion, double MaxContourOverlap, double ClusterThreshold) const;
  // Train components and relations for the component-based matching.
  virtual HRegion TrainModelComponents(const HRegionArray &InitialComponents, const HImage &TrainingImages, const Halcon::HTuple &ContrastLow, const Halcon::HTuple &ContrastHigh, const Halcon::HTuple &MinSize, const Halcon::HTuple &MinScore, const Halcon::HTuple &SearchRowTol, const Halcon::HTuple &SearchColumnTol, const Halcon::HTuple &SearchAngleTol, const Halcon::HTuple &TrainingEmphasis, const Halcon::HTuple &AmbiguityCriterion, const Halcon::HTuple &MaxContourOverlap, const Halcon::HTuple &ClusterThreshold, Halcon::HComponentTraining *ComponentTrainingID) const;
  // Train components and relations for the component-based matching.
  virtual HRegion TrainModelComponents(const HRegionArray &InitialComponents, const HImage &TrainingImages, Hlong ContrastLow, Hlong ContrastHigh, Hlong MinSize, double MinScore, Hlong SearchRowTol, Hlong SearchColumnTol, double SearchAngleTol, const char *TrainingEmphasis, const char *AmbiguityCriterion, double MaxContourOverlap, double ClusterThreshold, Halcon::HComponentTraining *ComponentTrainingID) const;
  // Train components and relations for the component-based matching.
  virtual HRegionArray TrainModelComponents(const HRegionArray &InitialComponents, const HImageArray &TrainingImages, const Halcon::HTuple &ContrastLow, const Halcon::HTuple &ContrastHigh, const Halcon::HTuple &MinSize, const Halcon::HTuple &MinScore, const Halcon::HTuple &SearchRowTol, const Halcon::HTuple &SearchColumnTol, const Halcon::HTuple &SearchAngleTol, const Halcon::HTuple &TrainingEmphasis, const Halcon::HTuple &AmbiguityCriterion, const Halcon::HTuple &MaxContourOverlap, const Halcon::HTuple &ClusterThreshold, Halcon::HComponentTraining *ComponentTrainingID) const;
  // Train components and relations for the component-based matching.
  virtual HRegionArray TrainModelComponents(const HRegionArray &InitialComponents, const HImageArray &TrainingImages, Hlong ContrastLow, Hlong ContrastHigh, Hlong MinSize, double MinScore, Hlong SearchRowTol, Hlong SearchColumnTol, double SearchAngleTol, const char *TrainingEmphasis, const char *AmbiguityCriterion, double MaxContourOverlap, double ClusterThreshold, Halcon::HComponentTraining *ComponentTrainingID) const;
  // Extract the initial components of a component model.
  virtual HRegionArray GenInitialComponents(const Halcon::HTuple &ContrastLow, const Halcon::HTuple &ContrastHigh, const Halcon::HTuple &MinSize, const Halcon::HTuple &Mode, const Halcon::HTuple &GenericName, const Halcon::HTuple &GenericValue) const;
  // Extract the initial components of a component model.
  virtual HRegionArray GenInitialComponents(Hlong ContrastLow, Hlong ContrastHigh, Hlong MinSize, const char *Mode, const char *GenericName, double GenericValue) const;
  // Find the best matches of a 3D shape model in an image.
  virtual HTuple FindShapeModel3d(const Halcon::HShapeModel3D &ShapeModel3DID, const Halcon::HTuple &MinScore, const Halcon::HTuple &Greediness, const Halcon::HTuple &NumLevels, const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues, Halcon::HTuple *CovPose, Halcon::HTuple *Score) const;
  // Convert a multichannel image into One-channel images
  virtual HImageArray ImageToChannels(void) const;
  // Convert 7 images into a seven-channel image.
  virtual HImage Compose7(const HImage &Image2, const HImage &Image3, const HImage &Image4, const HImage &Image5, const HImage &Image6, const HImage &Image7) const;
  // Convert 7 images into a seven-channel image.
  virtual HImage Compose7(const HImageArray &Image2, const HImageArray &Image3, const HImageArray &Image4, const HImageArray &Image5, const HImageArray &Image6, const HImageArray &Image7) const;
  // Convert 6 images into a six-channel image.
  virtual HImage Compose6(const HImage &Image2, const HImage &Image3, const HImage &Image4, const HImage &Image5, const HImage &Image6) const;
  // Convert 6 images into a six-channel image.
  virtual HImage Compose6(const HImageArray &Image2, const HImageArray &Image3, const HImageArray &Image4, const HImageArray &Image5, const HImageArray &Image6) const;
  // Convert 5 images into a five-channel image.
  virtual HImage Compose5(const HImage &Image2, const HImage &Image3, const HImage &Image4, const HImage &Image5) const;
  // Convert 5 images into a five-channel image.
  virtual HImage Compose5(const HImageArray &Image2, const HImageArray &Image3, const HImageArray &Image4, const HImageArray &Image5) const;
  // Convert 4 images into a four-channel image.
  virtual HImage Compose4(const HImage &Image2, const HImage &Image3, const HImage &Image4) const;
  // Convert 4 images into a four-channel image.
  virtual HImage Compose4(const HImageArray &Image2, const HImageArray &Image3, const HImageArray &Image4) const;
  // Convert 3 images into a three-channel image.
  virtual HImage Compose3(const HImage &Image2, const HImage &Image3) const;
  // Convert 3 images into a three-channel image.
  virtual HImage Compose3(const HImageArray &Image2, const HImageArray &Image3) const;
  // Convert two images into a two-channel image.
  virtual HImage Compose2(const HImage &Image2) const;
  // Convert two images into a two-channel image.
  virtual HImage Compose2(const HImageArray &Image2) const;
  // Convert a seven-channel image into seven images.
  virtual HImage Decompose7(HImage *Image2, HImage *Image3, HImage *Image4, HImage *Image5, HImage *Image6, HImage *Image7) const;
  // Convert a six-channel image into six images.
  virtual HImage Decompose6(HImage *Image2, HImage *Image3, HImage *Image4, HImage *Image5, HImage *Image6) const;
  // Convert a five-channel image into five images.
  virtual HImage Decompose5(HImage *Image2, HImage *Image3, HImage *Image4, HImage *Image5) const;
  // Convert a four-channel image into four images.
  virtual HImage Decompose4(HImage *Image2, HImage *Image3, HImage *Image4) const;
  // Convert a three-channel image into three images.
  virtual HImage Decompose3(HImage *Image2, HImage *Image3) const;
  // Convert a two-channel image into two images.
  virtual HImage Decompose2(HImage *Image2) const;
  // Count channels of image.
  virtual Hlong CountChannels(void) const;
  // Append additional matrices (channels) to the image.
  virtual HImage AppendChannel(const HImage &Image) const;
  // Access a channel of a multichannel image.
  virtual HImage AccessChannel(const Halcon::HTuple &Channel) const;
  // Access a channel of a multichannel image.
  virtual HImage AccessChannel(Hlong Channel) const;
  // Tile multiple image objects into a large image with explicit
  // positioning information.
  virtual HImage TileImagesOffset(const Halcon::HTuple &OffsetRow, const Halcon::HTuple &OffsetCol, const Halcon::HTuple &Row1, const Halcon::HTuple &Col1, const Halcon::HTuple &Row2, const Halcon::HTuple &Col2, const Halcon::HTuple &Width, const Halcon::HTuple &Height) const;
  // Tile multiple image objects into a large image with explicit
  // positioning information.
  virtual HImage TileImagesOffset(Hlong OffsetRow, Hlong OffsetCol, Hlong Row1, Hlong Col1, Hlong Row2, Hlong Col2, Hlong Width, Hlong Height) const;
  // Tile multiple images into a large image.
  virtual HImage TileChannels(const Halcon::HTuple &NumColumns, const Halcon::HTuple &TileOrder) const;
  // Tile multiple images into a large image.
  virtual HImage TileChannels(Hlong NumColumns, const char *TileOrder) const;
  // Cut out of defined gray values.
  virtual HImage CropDomain(void) const;
  // Cut out one or more rectangular image areas.
  virtual HImage CropRectangle1(const Halcon::HTuple &Row1, const Halcon::HTuple &Column1, const Halcon::HTuple &Row2, const Halcon::HTuple &Column2) const;
  // Cut out one or more rectangular image areas.
  virtual HImage CropRectangle1(Hlong Row1, Hlong Column1, Hlong Row2, Hlong Column2) const;
  // Cut out one or more rectangular image areas.
  virtual HImage CropPart(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Width, const Halcon::HTuple &Height) const;
  // Cut out one or more rectangular image areas.
  virtual HImage CropPart(Hlong Row, Hlong Column, Hlong Width, Hlong Height) const;
  // Change image size.
  virtual HImage ChangeFormat(const Halcon::HTuple &Width, const Halcon::HTuple &Height) const;
  // Change image size.
  virtual HImage ChangeFormat(Hlong Width, Hlong Height) const;
  // Change definition domain of an image.
  virtual HImage ChangeDomain(const HRegion &NewDomain) const;
  // Reduce the domain of an image to a rectangle.
  virtual HImage Rectangle1Domain(const Halcon::HTuple &Row1, const Halcon::HTuple &Column1, const Halcon::HTuple &Row2, const Halcon::HTuple &Column2) const;
  // Reduce the domain of an image to a rectangle.
  virtual HImage Rectangle1Domain(Hlong Row1, Hlong Column1, Hlong Row2, Hlong Column2) const;
  // Reduce the domain of an image.
  virtual HImage ReduceDomain(const HRegion &Region) const;
  // Expand the domain of an image to maximum.
  virtual HImage FullDomain(void) const;
  // Get the domain of an image.
  virtual HRegion GetDomain(void) const;
  // Detect lines in edge images with the help of the Hough transform
  // using local gradient direction and return them in normal form.
  virtual HImage HoughLinesDir(HRegionArray *Lines, const Halcon::HTuple &DirectionUncertainty, const Halcon::HTuple &AngleResolution, const Halcon::HTuple &Smoothing, const Halcon::HTuple &FilterSize, const Halcon::HTuple &Threshold, const Halcon::HTuple &AngleGap, const Halcon::HTuple &DistGap, const Halcon::HTuple &GenLines, Halcon::HTuple *Angle, Halcon::HTuple *Dist) const;
  // Detect lines in edge images with the help of the Hough transform
  // using local gradient direction and return them in normal form.
  virtual HImage HoughLinesDir(HRegionArray *Lines, Hlong DirectionUncertainty, Hlong AngleResolution, const char *Smoothing, Hlong FilterSize, Hlong Threshold, Hlong AngleGap, Hlong DistGap, const char *GenLines, Halcon::HTuple *Angle, Halcon::HTuple *Dist) const;
  // Compute the Hough transform for lines using local gradient direction.
  virtual HImage HoughLineTransDir(const Halcon::HTuple &DirectionUncertainty, const Halcon::HTuple &AngleResolution) const;
  // Compute the Hough transform for lines using local gradient direction.
  virtual HImage HoughLineTransDir(Hlong DirectionUncertainty, Hlong AngleResolution) const;
  // Segment the rectification grid region in the image.
  virtual HRegion FindRectificationGrid(const Halcon::HTuple &MinContrast, const Halcon::HTuple &Radius) const;
  // Segment the rectification grid region in the image.
  virtual HRegion FindRectificationGrid(double MinContrast, double Radius) const;
  // Establish connections between the grid points of the rectification grid.
  virtual HXLDArray ConnectGridPoints(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Sigma, const Halcon::HTuple &MaxDist) const;
  // Compute the mapping between the distorted image and the rectified image
  // based upon the points of a regular grid.
  virtual HImage GenGridRectificationMap(const HXLDArray &ConnectingLines, HXLDArray *Meshes, const Halcon::HTuple &GridSpacing, const Halcon::HTuple &Rotation, const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &MapType) const;
  // Displays gray value images.
  virtual void DispImage(const Halcon::HTuple &WindowHandle) const;
  // Displays gray value images.
  virtual void DispImage(Hlong WindowHandle) const;
  // Displays images with several channels.
  virtual void DispChannel(const Halcon::HTuple &WindowHandle, const Halcon::HTuple &Channel) const;
  // Displays images with several channels.
  virtual void DispChannel(Hlong WindowHandle, Hlong Channel) const;
  // Displays a color (RGB) image
  virtual void DispColor(const Halcon::HTuple &WindowHandle) const;
  // Displays a color (RGB) image
  virtual void DispColor(Hlong WindowHandle) const;
  // Visualize images using gnuplot.
  virtual void GnuplotPlotImage(const Halcon::HGnuplot &GnuplotFileID, const Halcon::HTuple &SamplesX, const Halcon::HTuple &SamplesY, const Halcon::HTuple &ViewRotX, const Halcon::HTuple &ViewRotZ, const Halcon::HTuple &Hidden3D) const;
  // Visualize images using gnuplot.
  virtual void GnuplotPlotImage(const Halcon::HGnuplot &GnuplotFileID, Hlong SamplesX, Hlong SamplesY, double ViewRotX, double ViewRotZ, const char *Hidden3D) const;
  // Filter an image using a Laws texture filter.
  virtual HImage TextureLaws(const Halcon::HTuple &FilterTypes, const Halcon::HTuple &Shift, const Halcon::HTuple &FilterSize) const;
  // Filter an image using a Laws texture filter.
  virtual HImage TextureLaws(const char *FilterTypes, Hlong Shift, Hlong FilterSize) const;
  // Calculate the standard deviation of gray values within rectangular windows.
  virtual HImage DeviationImage(const Halcon::HTuple &Width, const Halcon::HTuple &Height) const;
  // Calculate the standard deviation of gray values within rectangular windows.
  virtual HImage DeviationImage(Hlong Width, Hlong Height) const;
  // Calculate the entropy of gray values within a rectangular window.
  virtual HImage EntropyImage(const Halcon::HTuple &Width, const Halcon::HTuple &Height) const;
  // Calculate the entropy of gray values within a rectangular window.
  virtual HImage EntropyImage(Hlong Width, Hlong Height) const;
  // Perform an isotropic diffusion of an image.
  virtual HImage IsotropicDiffusion(const Halcon::HTuple &Sigma, const Halcon::HTuple &Iterations) const;
  // Perform an isotropic diffusion of an image.
  virtual HImage IsotropicDiffusion(double Sigma, Hlong Iterations) const;
  // Perform an anisotropic diffusion of an image.
  virtual HImage AnisotropicDiffusion(const Halcon::HTuple &Mode, const Halcon::HTuple &Contrast, const Halcon::HTuple &Theta, const Halcon::HTuple &Iterations) const;
  // Perform an anisotropic diffusion of an image.
  virtual HImage AnisotropicDiffusion(const char *Mode, double Contrast, double Theta, Hlong Iterations) const;
  // Smooth an image using various filters.
  virtual HImage SmoothImage(const Halcon::HTuple &Filter, const Halcon::HTuple &Alpha) const;
  // Smooth an image using various filters.
  virtual HImage SmoothImage(const char *Filter, double Alpha) const;
  // Non-linear smoothing with the sigma filter.
  virtual HImage SigmaImage(const Halcon::HTuple &MaskHeight, const Halcon::HTuple &MaskWidth, const Halcon::HTuple &Sigma) const;
  // Non-linear smoothing with the sigma filter.
  virtual HImage SigmaImage(Hlong MaskHeight, Hlong MaskWidth, Hlong Sigma) const;
  // Calculate the average of maximum and minimum inside any mask.
  virtual HImage MidrangeImage(const HRegion &Mask, const Halcon::HTuple &Margin) const;
  // Smooth an image with an arbitrary rank mask.
  virtual HImage TrimmedMean(const HRegion &Mask, const Halcon::HTuple &Number, const Halcon::HTuple &Margin) const;
  // Separated median filtering with rectangle masks.
  virtual HImage MedianSeparate(const Halcon::HTuple &MaskWidth, const Halcon::HTuple &MaskHeight, const Halcon::HTuple &Margin) const;
  // Compute a median filter with rectangular masks.
  virtual HImage MedianRect(const Halcon::HTuple &MaskWidth, const Halcon::HTuple &MaskHeight) const;
  // Compute a median filter with rectangular masks.
  virtual HImage MedianRect(Hlong MaskWidth, Hlong MaskHeight) const;
  // Compute a median filter with various masks.
  virtual HImage MedianImage(const Halcon::HTuple &MaskType, const Halcon::HTuple &Radius, const Halcon::HTuple &Margin) const;
  // Weighted median filtering with different rank masks.
  virtual HImage MedianWeighted(const Halcon::HTuple &MaskType, const Halcon::HTuple &MaskSize) const;
  // Weighted median filtering with different rank masks.
  virtual HImage MedianWeighted(const char *MaskType, Hlong MaskSize) const;
  // Compute a rank filter with rectangular masks.
  virtual HImage RankRect(const Halcon::HTuple &MaskWidth, const Halcon::HTuple &MaskHeight, const Halcon::HTuple &Rank) const;
  // Compute a rank filter with rectangular masks.
  virtual HImage RankRect(Hlong MaskWidth, Hlong MaskHeight, Hlong Rank) const;
  // Compute a rank filter with arbitrary masks.
  virtual HImage RankImage(const HRegion &Mask, const Halcon::HTuple &Rank, const Halcon::HTuple &Margin) const;
  // Opening, Median and Closing with circle or rectangle mask.
  virtual HImage DualRank(const Halcon::HTuple &MaskType, const Halcon::HTuple &Radius, const Halcon::HTuple &ModePercent, const Halcon::HTuple &Margin) const;
  // Smooth by averaging.
  virtual HImage MeanImage(const Halcon::HTuple &MaskWidth, const Halcon::HTuple &MaskHeight) const;
  // Smooth by averaging.
  virtual HImage MeanImage(Hlong MaskWidth, Hlong MaskHeight) const;
  // Smooth an image using the binomial filter.
  virtual HImage BinomialFilter(const Halcon::HTuple &MaskWidth, const Halcon::HTuple &MaskHeight) const;
  // Smooth an image using the binomial filter.
  virtual HImage BinomialFilter(Hlong MaskWidth, Hlong MaskHeight) const;
  // Smooth an image using discrete Gaussian functions.
  virtual HImage GaussImage(const Halcon::HTuple &Size) const;
  // Smooth an image using discrete Gaussian functions.
  virtual HImage GaussImage(Hlong Size) const;
  // Smooth using discrete gauss functions.
  virtual HImage GaussFilter(const Halcon::HTuple &Size) const;
  // Smooth using discrete gauss functions.
  virtual HImage GaussFilter(Hlong Size) const;
  // Smooth an image in the spatial domain to suppress noise.
  virtual HImage EliminateMinMax(const Halcon::HTuple &MaskWidth, const Halcon::HTuple &MaskHeight, const Halcon::HTuple &Gap, const Halcon::HTuple &Mode) const;
  // Smooth an image in the spatial domain to suppress noise.
  virtual HImage EliminateMinMax(Hlong MaskWidth, Hlong MaskHeight, double Gap, Hlong Mode) const;
  // Smooth an image by edge-preserving anisotropic diffusion.
  virtual HImage AnisotropeDiff(const Halcon::HTuple &Percent, const Halcon::HTuple &Mode, const Halcon::HTuple &Iteration, const Halcon::HTuple &NeighborhoodType) const;
  // Smooth an image by edge-preserving anisotropic diffusion.
  virtual HImage AnisotropeDiff(Hlong Percent, Hlong Mode, Hlong Iteration, Hlong NeighborhoodType) const;
  // Interpolate 2 video half images.
  virtual HImage FillInterlace(const Halcon::HTuple &Mode) const;
  // Interpolate 2 video half images.
  virtual HImage FillInterlace(const char *Mode) const;
  // Return gray values with given rank from multiple channels.
  virtual HImage RankN(const Halcon::HTuple &RankIndex) const;
  // Return gray values with given rank from multiple channels.
  virtual HImage RankN(Hlong RankIndex) const;
  // Average gray values over several channels.
  virtual HImage MeanN(void) const;
  // Replace values outside of thresholds with average value.
  virtual HImage EliminateSp(const Halcon::HTuple &MaskWidth, const Halcon::HTuple &MaskHeight, const Halcon::HTuple &MinThresh, const Halcon::HTuple &MaxThresh) const;
  // Replace values outside of thresholds with average value.
  virtual HImage EliminateSp(Hlong MaskWidth, Hlong MaskHeight, Hlong MinThresh, Hlong MaxThresh) const;
  // Suppress salt and pepper noise.
  virtual HImage MeanSp(const Halcon::HTuple &MaskWidth, const Halcon::HTuple &MaskHeight, const Halcon::HTuple &MinThresh, const Halcon::HTuple &MaxThresh) const;
  // Suppress salt and pepper noise.
  virtual HImage MeanSp(Hlong MaskWidth, Hlong MaskHeight, Hlong MinThresh, Hlong MaxThresh) const;
  // Find corners using the Sojka operator.
  virtual HTuple PointsSojka(const Halcon::HTuple &MaskSize, const Halcon::HTuple &SigmaW, const Halcon::HTuple &SigmaD, const Halcon::HTuple &MinGrad, const Halcon::HTuple &MinApparentness, const Halcon::HTuple &MinAngle, const Halcon::HTuple &Subpix, Halcon::HTuple *Column) const;
  // Find corners using the Sojka operator.
  virtual HTuple PointsSojka(Hlong MaskSize, double SigmaW, double SigmaD, double MinGrad, double MinApparentness, double MinAngle, const char *Subpix, Halcon::HTuple *Column) const;
  // Enhance circular dots in an image.
  virtual HImage DotsImage(const Halcon::HTuple &Diameter, const Halcon::HTuple &FilterType, const Halcon::HTuple &PixelShift) const;
  // Enhance circular dots in an image.
  virtual HImage DotsImage(Hlong Diameter, const char *FilterType, Hlong PixelShift) const;
  // Subpixel precise detection of local minima in an image.
  virtual HTuple LocalMinSubPix(const Halcon::HTuple &Filter, const Halcon::HTuple &Sigma, const Halcon::HTuple &Threshold, Halcon::HTuple *Column) const;
  // Subpixel precise detection of local minima in an image.
  virtual HTuple LocalMinSubPix(const char *Filter, double Sigma, double Threshold, Halcon::HTuple *Column) const;
  // Subpixel precise detection of local maxima in an image.
  virtual HTuple LocalMaxSubPix(const Halcon::HTuple &Filter, const Halcon::HTuple &Sigma, const Halcon::HTuple &Threshold, Halcon::HTuple *Column) const;
  // Subpixel precise detection of local maxima in an image.
  virtual HTuple LocalMaxSubPix(const char *Filter, double Sigma, double Threshold, Halcon::HTuple *Column) const;
  // Subpixel precise detection of saddle points in an image.
  virtual HTuple SaddlePointsSubPix(const Halcon::HTuple &Filter, const Halcon::HTuple &Sigma, const Halcon::HTuple &Threshold, Halcon::HTuple *Column) const;
  // Subpixel precise detection of saddle points in an image.
  virtual HTuple SaddlePointsSubPix(const char *Filter, double Sigma, double Threshold, Halcon::HTuple *Column) const;
  // Subpixel precise detection of critical points in an image.
  virtual HTuple CriticalPointsSubPix(const Halcon::HTuple &Filter, const Halcon::HTuple &Sigma, const Halcon::HTuple &Threshold, Halcon::HTuple *ColumnMin, Halcon::HTuple *RowMax, Halcon::HTuple *ColumnMax, Halcon::HTuple *RowSaddle, Halcon::HTuple *ColumnSaddle) const;
  // Subpixel precise detection of critical points in an image.
  virtual HTuple CriticalPointsSubPix(const char *Filter, double Sigma, double Threshold, Halcon::HTuple *ColumnMin, Halcon::HTuple *RowMax, Halcon::HTuple *ColumnMax, Halcon::HTuple *RowSaddle, Halcon::HTuple *ColumnSaddle) const;
  // Detect points of interest using the Harris operator.
  virtual HTuple PointsHarris(const Halcon::HTuple &SigmaGrad, const Halcon::HTuple &SigmaSmooth, const Halcon::HTuple &Alpha, const Halcon::HTuple &Threshold, Halcon::HTuple *Column) const;
  // Detect points of interest using the Harris operator.
  virtual HTuple PointsHarris(double SigmaGrad, double SigmaSmooth, double Alpha, double Threshold, Halcon::HTuple *Column) const;
  // Detect points of interest using the binomial approximation of the Harris
  // operator.
  virtual HTuple PointsHarrisBinomial(const Halcon::HTuple &MaskSizeGrad, const Halcon::HTuple &MaskSizeSmooth, const Halcon::HTuple &Alpha, const Halcon::HTuple &Threshold, const Halcon::HTuple &Subpix, Halcon::HTuple *Column) const;
  // Detect points of interest using the binomial approximation of the Harris
  // operator.
  virtual HTuple PointsHarrisBinomial(Hlong MaskSizeGrad, Hlong MaskSizeSmooth, double Alpha, double Threshold, const char *Subpix, Halcon::HTuple *Column) const;
  // Detect points of interest using the Lepetit operator.
  virtual HTuple PointsLepetit(const Halcon::HTuple &Radius, const Halcon::HTuple &CheckNeighbor, const Halcon::HTuple &MinCheckNeighborDiff, const Halcon::HTuple &MinScore, const Halcon::HTuple &Subpix, Halcon::HTuple *Column) const;
  // Detect points of interest using the Lepetit operator.
  virtual HTuple PointsLepetit(Hlong Radius, Hlong CheckNeighbor, Hlong MinCheckNeighborDiff, Hlong MinScore, const char *Subpix, Halcon::HTuple *Column) const;
  // Detect points of interest using the Förstner operator.
  virtual HTuple PointsFoerstner(const Halcon::HTuple &SigmaGrad, const Halcon::HTuple &SigmaInt, const Halcon::HTuple &SigmaPoints, const Halcon::HTuple &ThreshInhom, const Halcon::HTuple &ThreshShape, const Halcon::HTuple &Smoothing, const Halcon::HTuple &EliminateDoublets, Halcon::HTuple *ColumnJunctions, Halcon::HTuple *CoRRJunctions, Halcon::HTuple *CoRCJunctions, Halcon::HTuple *CoCCJunctions, Halcon::HTuple *RowArea, Halcon::HTuple *ColumnArea, Halcon::HTuple *CoRRArea, Halcon::HTuple *CoRCArea, Halcon::HTuple *CoCCArea) const;
  // Detect points of interest using the Förstner operator.
  virtual HTuple PointsFoerstner(double SigmaGrad, double SigmaInt, double SigmaPoints, double ThreshInhom, double ThreshShape, const char *Smoothing, const char *EliminateDoublets, Halcon::HTuple *ColumnJunctions, Halcon::HTuple *CoRRJunctions, Halcon::HTuple *CoRCJunctions, Halcon::HTuple *CoCCJunctions, Halcon::HTuple *RowArea, Halcon::HTuple *ColumnArea, Halcon::HTuple *CoRRArea, Halcon::HTuple *CoRCArea, Halcon::HTuple *CoCCArea) const;
  // Estimate the image noise from a single image.
  virtual double EstimateNoise(const Halcon::HTuple &Method, const Halcon::HTuple &Percent) const;
  // Estimate the image noise from a single image.
  virtual double EstimateNoise(const char *Method, double Percent) const;
  // Add noise to an image.
  virtual HImage AddNoiseWhite(const Halcon::HTuple &Amp) const;
  // Add noise to an image.
  virtual HImage AddNoiseWhite(double Amp) const;
  // Add noise to an image.
  virtual HImage AddNoiseDistribution(const Halcon::HTuple &Distribution) const;
  // Calculate standard deviation over several channels.
  virtual HImage DeviationN(void) const;
  // Perform an inpainting by texture propagation.
  virtual HImage InpaintingTexture(const HRegion &Region, const Halcon::HTuple &MaskSize, const Halcon::HTuple &SearchSize, const Halcon::HTuple &Anisotropy, const Halcon::HTuple &PostIteration, const Halcon::HTuple &Smoothness) const;
  // Perform an inpainting by texture propagation.
  virtual HImage InpaintingTexture(const HRegion &Region, Hlong MaskSize, Hlong SearchSize, double Anisotropy, const char *PostIteration, double Smoothness) const;
  // Perform an inpainting by coherence transport.
  virtual HImage InpaintingCt(const HRegion &Region, const Halcon::HTuple &Epsilon, const Halcon::HTuple &Kappa, const Halcon::HTuple &Sigma, const Halcon::HTuple &Rho, const Halcon::HTuple &ChannelCoefficients) const;
  // Perform an inpainting by coherence transport.
  virtual HImage InpaintingCt(const HRegion &Region, double Epsilon, double Kappa, double Sigma, double Rho, double ChannelCoefficients) const;
  // Perform an inpainting by smoothing of level lines.
  virtual HImage InpaintingMcf(const HRegion &Region, const Halcon::HTuple &Sigma, const Halcon::HTuple &Theta, const Halcon::HTuple &Iterations) const;
  // Perform an inpainting by smoothing of level lines.
  virtual HImage InpaintingMcf(const HRegion &Region, double Sigma, double Theta, Hlong Iterations) const;
  // Perform an inpainting by coherence enhancing diffusion.
  virtual HImage InpaintingCed(const HRegion &Region, const Halcon::HTuple &Sigma, const Halcon::HTuple &Rho, const Halcon::HTuple &Theta, const Halcon::HTuple &Iterations) const;
  // Perform an inpainting by coherence enhancing diffusion.
  virtual HImage InpaintingCed(const HRegion &Region, double Sigma, double Rho, double Theta, Hlong Iterations) const;
  // Perform an inpainting by anisotropic diffusion.
  virtual HImage InpaintingAniso(const HRegion &Region, const Halcon::HTuple &Mode, const Halcon::HTuple &Contrast, const Halcon::HTuple &Theta, const Halcon::HTuple &Iterations, const Halcon::HTuple &Rho) const;
  // Perform an inpainting by anisotropic diffusion.
  virtual HImage InpaintingAniso(const HRegion &Region, const char *Mode, double Contrast, double Theta, Hlong Iterations, double Rho) const;
  // Perform a harmonic interpolation on an image region.
  virtual HImage HarmonicInterpolation(const HRegion &Region, const Halcon::HTuple &Precision) const;
  // Perform a harmonic interpolation on an image region.
  virtual HImage HarmonicInterpolation(const HRegion &Region, double Precision) const;
  // Expand the domain of an image and set the gray values in the
  // expanded domain.
  virtual HImage ExpandDomainGray(const Halcon::HTuple &ExpansionRange) const;
  // Expand the domain of an image and set the gray values in the
  // expanded domain.
  virtual HImage ExpandDomainGray(Hlong ExpansionRange) const;
  // Compute the topographic primal sketch of an image.
  virtual HImage TopographicSketch(void) const;
  // Compute an affine transformation of the color values of a
  // multichannel image.
  virtual HImage LinearTransColor(const Halcon::HTuple &TransMat) const;
  // Compute the transformation matrix of the principal component
  // analysis of multichannel images.
  virtual HTuple GenPrincipalCompTrans(Halcon::HTuple *TransInv, Halcon::HTuple *Mean, Halcon::HTuple *Cov, Halcon::HTuple *InfoPerComp) const;
  // Compute the principal components of multichannel images.
  virtual HImage PrincipalComp(Halcon::HTuple *InfoPerComp) const;
  // Perform a grayvalue closing with a selected mask.
  virtual HImage GrayClosingShape(const Halcon::HTuple &MaskHeight, const Halcon::HTuple &MaskWidth, const Halcon::HTuple &MaskShape) const;
  // Perform a grayvalue closing with a selected mask.
  virtual HImage GrayClosingShape(double MaskHeight, double MaskWidth, const char *MaskShape) const;
  // Perform a gray value opening with a selected mask.
  virtual HImage GrayOpeningShape(const Halcon::HTuple &MaskHeight, const Halcon::HTuple &MaskWidth, const Halcon::HTuple &MaskShape) const;
  // Perform a gray value opening with a selected mask.
  virtual HImage GrayOpeningShape(double MaskHeight, double MaskWidth, const char *MaskShape) const;
  // Determine the minimum gray value within a selected mask.
  virtual HImage GrayErosionShape(const Halcon::HTuple &MaskHeight, const Halcon::HTuple &MaskWidth, const Halcon::HTuple &MaskShape) const;
  // Determine the minimum gray value within a selected mask.
  virtual HImage GrayErosionShape(double MaskHeight, double MaskWidth, const char *MaskShape) const;
  // Determine the maximum gray value within a selected mask.
  virtual HImage GrayDilationShape(const Halcon::HTuple &MaskHeight, const Halcon::HTuple &MaskWidth, const Halcon::HTuple &MaskShape) const;
  // Determine the maximum gray value within a selected mask.
  virtual HImage GrayDilationShape(double MaskHeight, double MaskWidth, const char *MaskShape) const;
  // Determine the gray value range within a rectangle.
  virtual HImage GrayRangeRect(const Halcon::HTuple &MaskHeight, const Halcon::HTuple &MaskWidth) const;
  // Determine the gray value range within a rectangle.
  virtual HImage GrayRangeRect(Hlong MaskHeight, Hlong MaskWidth) const;
  // Perform a gray value closing with a rectangular mask.
  virtual HImage GrayClosingRect(const Halcon::HTuple &MaskHeight, const Halcon::HTuple &MaskWidth) const;
  // Perform a gray value closing with a rectangular mask.
  virtual HImage GrayClosingRect(Hlong MaskHeight, Hlong MaskWidth) const;
  // Perform a gray value opening with a rectangular mask.
  virtual HImage GrayOpeningRect(const Halcon::HTuple &MaskHeight, const Halcon::HTuple &MaskWidth) const;
  // Perform a gray value opening with a rectangular mask.
  virtual HImage GrayOpeningRect(Hlong MaskHeight, Hlong MaskWidth) const;
  // Determine the minimum gray value within a rectangle.
  virtual HImage GrayErosionRect(const Halcon::HTuple &MaskHeight, const Halcon::HTuple &MaskWidth) const;
  // Determine the minimum gray value within a rectangle.
  virtual HImage GrayErosionRect(Hlong MaskHeight, Hlong MaskWidth) const;
  // Determine the maximum gray value within a rectangle.
  virtual HImage GrayDilationRect(const Halcon::HTuple &MaskHeight, const Halcon::HTuple &MaskWidth) const;
  // Determine the maximum gray value within a rectangle.
  virtual HImage GrayDilationRect(Hlong MaskHeight, Hlong MaskWidth) const;
  // Thinning of gray value images.
  virtual HImage GraySkeleton(void) const;
  // Transform an image with a gray-value look-up-table
  virtual HImage LutTrans(const Halcon::HTuple &Lut) const;
  // Calculate the correlation between an image and an arbitrary filter mask
  virtual HImage ConvolImage(const Halcon::HTuple &FilterMask, const Halcon::HTuple &Margin) const;
  // Convert the type of an image.
  virtual HImage ConvertImageType(const Halcon::HTuple &NewType) const;
  // Convert the type of an image.
  virtual HImage ConvertImageType(const char *NewType) const;
  // Convert two real-valued images into a vector field image.
  virtual HImage RealToVectorField(const HImage &Col, const Halcon::HTuple &Type) const;
  // Convert two real-valued images into a vector field image.
  virtual HImage RealToVectorField(const HImage &Col, const char *Type) const;
  // Convert two real-valued images into a vector field image.
  virtual HImage RealToVectorField(const HImageArray &Col, const Halcon::HTuple &Type) const;
  // Convert two real-valued images into a vector field image.
  virtual HImage RealToVectorField(const HImageArray &Col, const char *Type) const;
  // Convert a vector field image into two real-valued images.
  virtual HImage VectorFieldToReal(HImage *Col) const;
  // Convert two real images into a complex image.
  virtual HImage RealToComplex(const HImage &ImageImaginary) const;
  // Convert two real images into a complex image.
  virtual HImage RealToComplex(const HImageArray &ImageImaginary) const;
  // Convert a complex image into two real images.
  virtual HImage ComplexToReal(HImage *ImageImaginary) const;
  // Calculate the lowest possible gray value on an arbitrary path to the
  // image border for each point in the image.
  virtual HImage GrayInside(void) const;
  // Symmetry of gray values along a row.
  virtual HImage Symmetry(const Halcon::HTuple &MaskSize, const Halcon::HTuple &Direction, const Halcon::HTuple &Exponent) const;
  // Symmetry of gray values along a row.
  virtual HImage Symmetry(Hlong MaskSize, double Direction, double Exponent) const;
  // Selection of gray values of a multi-channel image using an index image.
  virtual HImage SelectGrayvaluesFromChannels(const HImage &IndexImage) const;
  // Selection of gray values of a multi-channel image using an index image.
  virtual HImage SelectGrayvaluesFromChannels(const HImageArray &IndexImage) const;
  // Extract depth using mutiple focus levels.
  virtual HImage DepthFromFocus(HImage *Confidence, const Halcon::HTuple &Filter, const Halcon::HTuple &Selection) const;
  // Compute the uncalibrated scene flow between two stereo image pairs.
  virtual HImage SceneFlowUncalib(const HImage &ImageRect2T1, const HImage &ImageRect1T2, const HImage &ImageRect2T2, const HImage &Disparity, HImage *DisparityChange, const Halcon::HTuple &SmoothingFlow, const Halcon::HTuple &SmoothingDisparity, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue) const;
  // Compute the uncalibrated scene flow between two stereo image pairs.
  virtual HImage SceneFlowUncalib(const HImageArray &ImageRect2T1, const HImageArray &ImageRect1T2, const HImageArray &ImageRect2T2, const HImageArray &Disparity, HImage *DisparityChange, const Halcon::HTuple &SmoothingFlow, const Halcon::HTuple &SmoothingDisparity, const Halcon::HTuple &GenParamName, const Halcon::HTuple &GenParamValue) const;
  // Unwarp an image using a vector field.
  virtual HImage UnwarpImageVectorField(const HImage &VectorField) const;
  // Unwarp an image using a vector field.
  virtual HImage UnwarpImageVectorField(const HImageArray &VectorField) const;
  // Convolve a vector field with derivatives of the Gaussian.
  virtual HImage DerivateVectorField(const Halcon::HTuple &Sigma, const Halcon::HTuple &Component) const;
  // Convolve a vector field with derivatives of the Gaussian.
  virtual HImage DerivateVectorField(double Sigma, const char *Component) const;
  // Compute the length of the vectors of a vector field.
  virtual HImage VectorFieldLength(const Halcon::HTuple &Mode) const;
  // Compute the length of the vectors of a vector field.
  virtual HImage VectorFieldLength(const char *Mode) const;
  // Compute the optical flow between two images.
  virtual HImage OpticalFlowMg(const HImage &ImageT2, const Halcon::HTuple &Algorithm, const Halcon::HTuple &SmoothingSigma, const Halcon::HTuple &IntegrationSigma, const Halcon::HTuple &FlowSmoothness, const Halcon::HTuple &GradientConstancy, const Halcon::HTuple &MGParamName, const Halcon::HTuple &MGParamValue) const;
  // Compute the optical flow between two images.
  virtual HImage OpticalFlowMg(const HImageArray &ImageT2, const Halcon::HTuple &Algorithm, const Halcon::HTuple &SmoothingSigma, const Halcon::HTuple &IntegrationSigma, const Halcon::HTuple &FlowSmoothness, const Halcon::HTuple &GradientConstancy, const Halcon::HTuple &MGParamName, const Halcon::HTuple &MGParamValue) const;
  // Matching a template and an image in a resolution pyramid.
  virtual HImage ExhaustiveMatchMg(const HImage &ImageTemplate, const Halcon::HTuple &Mode, const Halcon::HTuple &Level, const Halcon::HTuple &Threshold) const;
  // Matching a template and an image in a resolution pyramid.
  virtual HImage ExhaustiveMatchMg(const HImage &ImageTemplate, const char *Mode, Hlong Level, Hlong Threshold) const;
  // Preparing a pattern for template matching with rotation.
  virtual HTemplate CreateTemplateRot(const Halcon::HTuple &NumLevel, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtend, const Halcon::HTuple &AngleStep, const Halcon::HTuple &Optimize, const Halcon::HTuple &GrayValues) const;
  // Preparing a pattern for template matching with rotation.
  virtual HTemplate CreateTemplateRot(Hlong NumLevel, double AngleStart, double AngleExtend, double AngleStep, const char *Optimize, const char *GrayValues) const;
  // Preparing a pattern for template matching.
  virtual HTemplate CreateTemplate(const Halcon::HTuple &FirstError, const Halcon::HTuple &NumLevel, const Halcon::HTuple &Optimize, const Halcon::HTuple &GrayValues) const;
  // Preparing a pattern for template matching.
  virtual HTemplate CreateTemplate(Hlong FirstError, Hlong NumLevel, const char *Optimize, const char *GrayValues) const;
  // Adapting a template to the size of an image.
  virtual void AdaptTemplate(const Halcon::HTemplate &TemplateID) const;
  // Searching all good grayvalue matches in a pyramid.
  virtual HRegion FastMatchMg(const Halcon::HTemplate &TemplateID, const Halcon::HTuple &MaxError, const Halcon::HTuple &NumLevel) const;
  // Searching all good grayvalue matches in a pyramid.
  virtual HRegion FastMatchMg(const Halcon::HTemplate &TemplateID, double MaxError, Hlong NumLevel) const;
  // Searching the best grayvalue matches in a pyramid.
  virtual double BestMatchMg(const Halcon::HTemplate &TemplateID, const Halcon::HTuple &MaxError, const Halcon::HTuple &SubPixel, const Halcon::HTuple &NumLevels, const Halcon::HTuple &WhichLevels, double *Column, double *Error) const;
  // Searching the best grayvalue matches in a pyramid.
  virtual double BestMatchMg(const Halcon::HTemplate &TemplateID, double MaxError, const char *SubPixel, Hlong NumLevels, Hlong WhichLevels, double *Column, double *Error) const;
  // Searching all good matches of a template and an image.
  virtual HRegion FastMatch(const Halcon::HTemplate &TemplateID, const Halcon::HTuple &MaxError) const;
  // Searching all good matches of a template and an image.
  virtual HRegion FastMatch(const Halcon::HTemplate &TemplateID, double MaxError) const;
  // Searching the best matching of a template and a pyramid with rotation.
  virtual double BestMatchRotMg(const Halcon::HTemplate &TemplateID, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtend, const Halcon::HTuple &MaxError, const Halcon::HTuple &SubPixel, const Halcon::HTuple &NumLevels, double *Column, double *Angle, double *Error) const;
  // Searching the best matching of a template and a pyramid with rotation.
  virtual double BestMatchRotMg(const Halcon::HTemplate &TemplateID, double AngleStart, double AngleExtend, double MaxError, const char *SubPixel, Hlong NumLevels, double *Column, double *Angle, double *Error) const;
  // Searching the best matching of a template and an image with rotation.
  virtual double BestMatchRot(const Halcon::HTemplate &TemplateID, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleExtend, const Halcon::HTuple &MaxError, const Halcon::HTuple &SubPixel, double *Column, double *Angle, double *Error) const;
  // Searching the best matching of a template and an image with rotation.
  virtual double BestMatchRot(const Halcon::HTemplate &TemplateID, double AngleStart, double AngleExtend, double MaxError, const char *SubPixel, double *Column, double *Angle, double *Error) const;
  // Searching the best matching of a template and an image.
  virtual double BestMatch(const Halcon::HTemplate &TemplateID, const Halcon::HTuple &MaxError, const Halcon::HTuple &SubPixel, double *Column, double *Error) const;
  // Searching the best matching of a template and an image.
  virtual double BestMatch(const Halcon::HTemplate &TemplateID, double MaxError, const char *SubPixel, double *Column, double *Error) const;
  // Matching of a template and an image.
  virtual HImage ExhaustiveMatch(const HRegion &RegionOfInterest, const HImage &ImageTemplate, const Halcon::HTuple &Mode) const;
  // Matching of a template and an image.
  virtual HImage ExhaustiveMatch(const HRegion &RegionOfInterest, const HImage &ImageTemplate, const char *Mode) const;
  // Searching corners in images.
  virtual HImage CornerResponse(const Halcon::HTuple &Size, const Halcon::HTuple &Weight) const;
  // Searching corners in images.
  virtual HImage CornerResponse(Hlong Size, double Weight) const;
  // Calculating a Gauss pyramid.
  virtual HImageArray GenGaussPyramid(const Halcon::HTuple &Mode, const Halcon::HTuple &Scale) const;
  // Calculating a Gauss pyramid.
  virtual HImageArray GenGaussPyramid(const char *Mode, double Scale) const;
  // Calculating the monotony operation.
  virtual HImage Monotony(void) const;
  // Edge extraction using bandpass filters.
  virtual HImage BandpassImage(const Halcon::HTuple &FilterType) const;
  // Edge extraction using bandpass filters.
  virtual HImage BandpassImage(const char *FilterType) const;
  // Detect color lines and their width.
  virtual HXLDContArray LinesColor(const Halcon::HTuple &Sigma, const Halcon::HTuple &Low, const Halcon::HTuple &High, const Halcon::HTuple &ExtractWidth, const Halcon::HTuple &CompleteJunctions) const;
  // Detect color lines and their width.
  virtual HXLDContArray LinesColor(double Sigma, double Low, double High, const char *ExtractWidth, const char *CompleteJunctions) const;
  // Detect lines and their width.
  virtual HXLDContArray LinesGauss(const Halcon::HTuple &Sigma, const Halcon::HTuple &Low, const Halcon::HTuple &High, const Halcon::HTuple &LightDark, const Halcon::HTuple &ExtractWidth, const Halcon::HTuple &LineModel, const Halcon::HTuple &CompleteJunctions) const;
  // Detect lines and their width.
  virtual HXLDContArray LinesGauss(double Sigma, double Low, double High, const char *LightDark, const char *ExtractWidth, const char *LineModel, const char *CompleteJunctions) const;
  // Detection of lines using the facet model.
  virtual HXLDContArray LinesFacet(const Halcon::HTuple &MaskSize, const Halcon::HTuple &Low, const Halcon::HTuple &High, const Halcon::HTuple &LightDark) const;
  // Detection of lines using the facet model.
  virtual HXLDContArray LinesFacet(Hlong MaskSize, double Low, double High, const char *LightDark) const;
  // Store a filter mask in the spatial domain as a real-image.
  static HImage GenFilterMask(const Halcon::HTuple &FilterMask, const Halcon::HTuple &Scale, const Halcon::HTuple &Width, const Halcon::HTuple &Height);
  // Generate a mean filter in the frequency domain.
  static HImage GenMeanFilter(const Halcon::HTuple &MaskShape, const Halcon::HTuple &Diameter1, const Halcon::HTuple &Diameter2, const Halcon::HTuple &Phi, const Halcon::HTuple &Norm, const Halcon::HTuple &Mode, const Halcon::HTuple &Width, const Halcon::HTuple &Height);
  // Generate a mean filter in the frequency domain.
  static HImage GenMeanFilter(const char *MaskShape, double Diameter1, double Diameter2, double Phi, const char *Norm, const char *Mode, Hlong Width, Hlong Height);
  // Generate a Gaussian filter in the frequency domain.
  static HImage GenGaussFilter(const Halcon::HTuple &Sigma1, const Halcon::HTuple &Sigma2, const Halcon::HTuple &Phi, const Halcon::HTuple &Norm, const Halcon::HTuple &Mode, const Halcon::HTuple &Width, const Halcon::HTuple &Height);
  // Generate a Gaussian filter in the frequency domain.
  static HImage GenGaussFilter(double Sigma1, double Sigma2, double Phi, const char *Norm, const char *Mode, Hlong Width, Hlong Height);
  // Generate a derivative filter in the frequency domain.
  static HImage GenDerivativeFilter(const Halcon::HTuple &Derivative, const Halcon::HTuple &Exponent, const Halcon::HTuple &Norm, const Halcon::HTuple &Mode, const Halcon::HTuple &Width, const Halcon::HTuple &Height);
  // Generate a derivative filter in the frequency domain.
  static HImage GenDerivativeFilter(const char *Derivative, Hlong Exponent, const char *Norm, const char *Mode, Hlong Width, Hlong Height);
  // Generate a bandpass filter with Gaussian or sinusoidal shape.
  static HImage GenStdBandpass(const Halcon::HTuple &Frequency, const Halcon::HTuple &Sigma, const Halcon::HTuple &Type, const Halcon::HTuple &Norm, const Halcon::HTuple &Mode, const Halcon::HTuple &Width, const Halcon::HTuple &Height);
  // Generate a bandpass filter with Gaussian or sinusoidal shape.
  static HImage GenStdBandpass(double Frequency, double Sigma, const char *Type, const char *Norm, const char *Mode, Hlong Width, Hlong Height);
  // Generate a bandpass filter with sinusoidal shape.
  static HImage GenSinBandpass(const Halcon::HTuple &Frequency, const Halcon::HTuple &Norm, const Halcon::HTuple &Mode, const Halcon::HTuple &Width, const Halcon::HTuple &Height);
  // Generate a bandpass filter with sinusoidal shape.
  static HImage GenSinBandpass(double Frequency, const char *Norm, const char *Mode, Hlong Width, Hlong Height);
  // Generate an ideal band filter.
  static HImage GenBandfilter(const Halcon::HTuple &MinFrequency, const Halcon::HTuple &MaxFrequency, const Halcon::HTuple &Norm, const Halcon::HTuple &Mode, const Halcon::HTuple &Width, const Halcon::HTuple &Height);
  // Generate an ideal band filter.
  static HImage GenBandfilter(double MinFrequency, double MaxFrequency, const char *Norm, const char *Mode, Hlong Width, Hlong Height);
  // Generate an ideal bandpass filter.
  static HImage GenBandpass(const Halcon::HTuple &MinFrequency, const Halcon::HTuple &MaxFrequency, const Halcon::HTuple &Norm, const Halcon::HTuple &Mode, const Halcon::HTuple &Width, const Halcon::HTuple &Height);
  // Generate an ideal bandpass filter.
  static HImage GenBandpass(double MinFrequency, double MaxFrequency, const char *Norm, const char *Mode, Hlong Width, Hlong Height);
  // Generate an ideal lowpass filter.
  static HImage GenLowpass(const Halcon::HTuple &Frequency, const Halcon::HTuple &Norm, const Halcon::HTuple &Mode, const Halcon::HTuple &Width, const Halcon::HTuple &Height);
  // Generate an ideal lowpass filter.
  static HImage GenLowpass(double Frequency, const char *Norm, const char *Mode, Hlong Width, Hlong Height);
  // Generate an ideal highpass filter.
  static HImage GenHighpass(const Halcon::HTuple &Frequency, const Halcon::HTuple &Norm, const Halcon::HTuple &Mode, const Halcon::HTuple &Width, const Halcon::HTuple &Height);
  // Generate an ideal highpass filter.
  static HImage GenHighpass(double Frequency, const char *Norm, const char *Mode, Hlong Width, Hlong Height);
  // Return the power spectrum of a complex image.
  virtual HImage PowerLn(void) const;
  // Return the power spectrum of a complex image.
  virtual HImage PowerReal(void) const;
  // Return the power spectrum of a complex image.
  virtual HImage PowerByte(void) const;
  // Return the phase of a complex image in degrees.
  virtual HImage PhaseDeg(void) const;
  // Return the phase of a complex image in radians.
  virtual HImage PhaseRad(void) const;
  // Calculate the energy of a two-channel image.
  virtual HImage EnergyGabor(const HImage &ImageHilbert) const;
  // Calculate the energy of a two-channel image.
  virtual HImage EnergyGabor(const HImageArray &ImageHilbert) const;
  // Convolve an image with a Gabor filter in the frequency domain.
  virtual HImage ConvolGabor(const HImage &GaborFilter, HImage *ImageResultHilbert) const;
  // Generate a Gabor filter.
  static HImage GenGabor(const Halcon::HTuple &Angle, const Halcon::HTuple &Frequency, const Halcon::HTuple &Bandwidth, const Halcon::HTuple &Orientation, const Halcon::HTuple &Norm, const Halcon::HTuple &Mode, const Halcon::HTuple &Width, const Halcon::HTuple &Height);
  // Generate a Gabor filter.
  static HImage GenGabor(double Angle, double Frequency, double Bandwidth, double Orientation, const char *Norm, const char *Mode, Hlong Width, Hlong Height);
  // Compute the phase correlation of two images in the frequency domain.
  virtual HImage PhaseCorrelationFft(const HImage &ImageFFT2) const;
  // Compute the phase correlation of two images in the frequency domain.
  virtual HImage PhaseCorrelationFft(const HImageArray &ImageFFT2) const;
  // Compute the correlation of two images in the frequency domain.
  virtual HImage CorrelationFft(const HImage &ImageFFT2) const;
  // Compute the correlation of two images in the frequency domain.
  virtual HImage CorrelationFft(const HImageArray &ImageFFT2) const;
  // Convolve an image with a filter in the frequency domain.
  virtual HImage ConvolFft(const HImage &ImageFilter) const;
  // Compute the real-valued fast Fourier transform of an image.
  virtual HImage RftGeneric(const Halcon::HTuple &Direction, const Halcon::HTuple &Norm, const Halcon::HTuple &ResultType, const Halcon::HTuple &Width) const;
  // Compute the real-valued fast Fourier transform of an image.
  virtual HImage RftGeneric(const char *Direction, const char *Norm, const char *ResultType, Hlong Width) const;
  // Compute the inverse fast Fourier transform of an image.
  virtual HImage FftImageInv(void) const;
  // Compute the fast Fourier transform of an image.
  virtual HImage FftImage(void) const;
  // Compute the fast Fourier transform of an image.
  virtual HImage FftGeneric(const Halcon::HTuple &Direction, const Halcon::HTuple &Exponent, const Halcon::HTuple &Norm, const Halcon::HTuple &Mode, const Halcon::HTuple &ResultType) const;
  // Compute the fast Fourier transform of an image.
  virtual HImage FftGeneric(const char *Direction, Hlong Exponent, const char *Norm, const char *Mode, const char *ResultType) const;
  // Apply a shock filter to an image.
  virtual HImage ShockFilter(const Halcon::HTuple &Theta, const Halcon::HTuple &Iterations, const Halcon::HTuple &Mode, const Halcon::HTuple &Sigma) const;
  // Apply a shock filter to an image.
  virtual HImage ShockFilter(double Theta, Hlong Iterations, const char *Mode, double Sigma) const;
  // Apply the mean curvature flow to an image.
  virtual HImage MeanCurvatureFlow(const Halcon::HTuple &Sigma, const Halcon::HTuple &Theta, const Halcon::HTuple &Iterations) const;
  // Apply the mean curvature flow to an image.
  virtual HImage MeanCurvatureFlow(double Sigma, double Theta, Hlong Iterations) const;
  // Perform a coherence enhancing diffusion of an image.
  virtual HImage CoherenceEnhancingDiff(const Halcon::HTuple &Sigma, const Halcon::HTuple &Rho, const Halcon::HTuple &Theta, const Halcon::HTuple &Iterations) const;
  // Perform a coherence enhancing diffusion of an image.
  virtual HImage CoherenceEnhancingDiff(double Sigma, double Rho, double Theta, Hlong Iterations) const;
  // Histogram linearisation of images
  virtual HImage EquHistoImage(void) const;
  // Illuminate image.
  virtual HImage Illuminate(const Halcon::HTuple &MaskWidth, const Halcon::HTuple &MaskHeight, const Halcon::HTuple &Factor) const;
  // Illuminate image.
  virtual HImage Illuminate(Hlong MaskWidth, Hlong MaskHeight, double Factor) const;
  // Enhance contrast of the image.
  virtual HImage Emphasize(const Halcon::HTuple &MaskWidth, const Halcon::HTuple &MaskHeight, const Halcon::HTuple &Factor) const;
  // Enhance contrast of the image.
  virtual HImage Emphasize(Hlong MaskWidth, Hlong MaskHeight, double Factor) const;
  // Maximum gray value spreading in the value range
  // 0 to 255.
  virtual HImage ScaleImageMax(void) const;
  // Detect edges (amplitude and direction) using the Robinson operator.
  virtual HImage RobinsonDir(HImage *ImageEdgeDir) const;
  // Detect edges (amplitude) using the Robinson operator.
  virtual HImage RobinsonAmp(void) const;
  // Detect edges (amplitude and direction) using the Kirsch operator.
  virtual HImage KirschDir(HImage *ImageEdgeDir) const;
  // Detect edges (amplitude) using the Kirsch operator.
  virtual HImage KirschAmp(void) const;
  // Detect edges (amplitude and direction) using the Frei-Chen operator.
  virtual HImage FreiDir(HImage *ImageEdgeDir) const;
  // Detect edges (amplitude) using the Frei-Chen operator.
  virtual HImage FreiAmp(void) const;
  // Detect edges (amplitude and direction) using the Prewitt operator.
  virtual HImage PrewittDir(HImage *ImageEdgeDir) const;
  // Detect edges (amplitude) using the Prewitt operator.
  virtual HImage PrewittAmp(void) const;
  // Detect edges (amplitude) using the Sobel operator.
  virtual HImage SobelAmp(const Halcon::HTuple &FilterType, const Halcon::HTuple &Size) const;
  // Detect edges (amplitude) using the Sobel operator.
  virtual HImage SobelAmp(const char *FilterType, Hlong Size) const;
  // Detect edges (amplitude and direction) using the Sobel operator.
  virtual HImage SobelDir(HImage *EdgeDirection, const Halcon::HTuple &FilterType, const Halcon::HTuple &Size) const;
  // Detect edges (amplitude and direction) using the Sobel operator.
  virtual HImage SobelDir(HImage *EdgeDirection, const char *FilterType, Hlong Size) const;
  // Detect edges using the Roberts filter.
  virtual HImage Roberts(const Halcon::HTuple &FilterType) const;
  // Detect edges using the Roberts filter.
  virtual HImage Roberts(const char *FilterType) const;
  // Calculate the Laplace operator by using finite differences.
  virtual HImage Laplace(const Halcon::HTuple &ResultType, const Halcon::HTuple &MaskSize, const Halcon::HTuple &FilterMask) const;
  // Calculate the Laplace operator by using finite differences.
  virtual HImage Laplace(const char *ResultType, Hlong MaskSize, const char *FilterMask) const;
  // Extract high frequency components from an image.
  virtual HImage HighpassImage(const Halcon::HTuple &Width, const Halcon::HTuple &Height) const;
  // Extract high frequency components from an image.
  virtual HImage HighpassImage(Hlong Width, Hlong Height) const;
  // Extract subpixel precise color edges using Deriche, Shen, or Canny filters.
  virtual HXLDContArray EdgesColorSubPix(const Halcon::HTuple &Filter, const Halcon::HTuple &Alpha, const Halcon::HTuple &Low, const Halcon::HTuple &High) const;
  // Extract subpixel precise color edges using Deriche, Shen, or Canny filters.
  virtual HXLDContArray EdgesColorSubPix(const char *Filter, double Alpha, double Low, double High) const;
  // Extract color edges using Canny, Deriche, or Shen filters.
  virtual HImage EdgesColor(HImage *ImaDir, const Halcon::HTuple &Filter, const Halcon::HTuple &Alpha, const Halcon::HTuple &NMS, const Halcon::HTuple &Low, const Halcon::HTuple &High) const;
  // Extract color edges using Canny, Deriche, or Shen filters.
  virtual HImage EdgesColor(HImage *ImaDir, const char *Filter, double Alpha, const char *NMS, Hlong Low, Hlong High) const;
  // Extract sub-pixel precise edges using Deriche, Lanser, Shen, or Canny
  // filters.
  virtual HXLDContArray EdgesSubPix(const Halcon::HTuple &Filter, const Halcon::HTuple &Alpha, const Halcon::HTuple &Low, const Halcon::HTuple &High) const;
  // Extract sub-pixel precise edges using Deriche, Lanser, Shen, or Canny
  // filters.
  virtual HXLDContArray EdgesSubPix(const char *Filter, double Alpha, Hlong Low, Hlong High) const;
  // Extract edges using Deriche, Lanser, Shen, or Canny filters.
  virtual HImage EdgesImage(HImage *ImaDir, const Halcon::HTuple &Filter, const Halcon::HTuple &Alpha, const Halcon::HTuple &NMS, const Halcon::HTuple &Low, const Halcon::HTuple &High) const;
  // Extract edges using Deriche, Lanser, Shen, or Canny filters.
  virtual HImage EdgesImage(HImage *ImaDir, const char *Filter, double Alpha, const char *NMS, Hlong Low, Hlong High) const;
  // Convolve an image with derivatives of the Gaussian.
  virtual HImage DerivateGauss(const Halcon::HTuple &Sigma, const Halcon::HTuple &Component) const;
  // Convolve an image with derivatives of the Gaussian.
  virtual HImage DerivateGauss(double Sigma, const char *Component) const;
  // LoG-Operator (Laplace of Gaussian).
  virtual HImage LaplaceOfGauss(const Halcon::HTuple &Sigma) const;
  // LoG-Operator (Laplace of Gaussian).
  virtual HImage LaplaceOfGauss(double Sigma) const;
  // Approximate the LoG operator (Laplace of Gaussian).
  virtual HImage DiffOfGauss(const Halcon::HTuple &Sigma, const Halcon::HTuple &SigFactor) const;
  // Approximate the LoG operator (Laplace of Gaussian).
  virtual HImage DiffOfGauss(double Sigma, double SigFactor) const;
  // Detect straight edge segments.
  virtual HTuple DetectEdgeSegments(const Halcon::HTuple &SobelSize, const Halcon::HTuple &MinAmplitude, const Halcon::HTuple &MaxDistance, const Halcon::HTuple &MinLength, Halcon::HTuple *BeginCol, Halcon::HTuple *EndRow, Halcon::HTuple *EndCol) const;
  // Detect straight edge segments.
  virtual HTuple DetectEdgeSegments(Hlong SobelSize, Hlong MinAmplitude, Hlong MaxDistance, Hlong MinLength, Halcon::HTuple *BeginCol, Halcon::HTuple *EndRow, Halcon::HTuple *EndCol) const;
  // Color space transformation using pre-generated look-up-table.
  virtual HImage ApplyColorTransLut(const HImage &Image2, const HImage &Image3, HImage *ImageResult2, HImage *ImageResult3, const Halcon::HColorTransLUT &ColorTransLUTHandle) const;
  // Color space transformation using pre-generated look-up-table.
  virtual HImage ApplyColorTransLut(const HImageArray &Image2, const HImageArray &Image3, HImage *ImageResult2, HImage *ImageResult3, const Halcon::HColorTransLUT &ColorTransLUTHandle) const;
  // Convert a single-channel color filter array image into an RGB image.
  virtual HImage CfaToRgb(const Halcon::HTuple &CFAType, const Halcon::HTuple &Interpolation) const;
  // Convert a single-channel color filter array image into an RGB image.
  virtual HImage CfaToRgb(const char *CFAType, const char *Interpolation) const;
  // Transform an RGB image into a gray scale image.
  virtual HImage Rgb1ToGray(void) const;
  // Transform an RGB image to a gray scale image.
  virtual HImage Rgb3ToGray(const HImage &ImageGreen, const HImage &ImageBlue) const;
  // Transform an RGB image to a gray scale image.
  virtual HImage Rgb3ToGray(const HImageArray &ImageGreen, const HImageArray &ImageBlue) const;
  // Transform an image from the RGB color space to an arbitrary color space.
  virtual HImage TransFromRgb(const HImage &ImageGreen, const HImage &ImageBlue, HImage *ImageResult2, HImage *ImageResult3, const Halcon::HTuple &ColorSpace) const;
  // Transform an image from the RGB color space to an arbitrary color space.
  virtual HImage TransFromRgb(const HImage &ImageGreen, const HImage &ImageBlue, HImage *ImageResult2, HImage *ImageResult3, const char *ColorSpace) const;
  // Transform an image from the RGB color space to an arbitrary color space.
  virtual HImage TransFromRgb(const HImageArray &ImageGreen, const HImageArray &ImageBlue, HImage *ImageResult2, HImage *ImageResult3, const Halcon::HTuple &ColorSpace) const;
  // Transform an image from the RGB color space to an arbitrary color space.
  virtual HImage TransFromRgb(const HImageArray &ImageGreen, const HImageArray &ImageBlue, HImage *ImageResult2, HImage *ImageResult3, const char *ColorSpace) const;
  // Transform an image from an arbitrary color space to the RGB color space.
  virtual HImage TransToRgb(const HImage &ImageInput2, const HImage &ImageInput3, HImage *ImageGreen, HImage *ImageBlue, const Halcon::HTuple &ColorSpace) const;
  // Transform an image from an arbitrary color space to the RGB color space.
  virtual HImage TransToRgb(const HImage &ImageInput2, const HImage &ImageInput3, HImage *ImageGreen, HImage *ImageBlue, const char *ColorSpace) const;
  // Transform an image from an arbitrary color space to the RGB color space.
  virtual HImage TransToRgb(const HImageArray &ImageInput2, const HImageArray &ImageInput3, HImage *ImageGreen, HImage *ImageBlue, const Halcon::HTuple &ColorSpace) const;
  // Transform an image from an arbitrary color space to the RGB color space.
  virtual HImage TransToRgb(const HImageArray &ImageInput2, const HImageArray &ImageInput3, HImage *ImageGreen, HImage *ImageBlue, const char *ColorSpace) const;
  // Logical "AND" of each pixel using a bit mask.
  virtual HImage BitMask(const Halcon::HTuple &BitMask) const;
  // Logical "AND" of each pixel using a bit mask.
  virtual HImage BitMask(Hlong BitMask) const;
  // Extract a bit from the pixels.
  virtual HImage BitSlice(const Halcon::HTuple &Bit) const;
  // Extract a bit from the pixels.
  virtual HImage BitSlice(Hlong Bit) const;
  // Right shift of all pixels of the image.
  virtual HImage BitRshift(const Halcon::HTuple &Shift) const;
  // Right shift of all pixels of the image.
  virtual HImage BitRshift(Hlong Shift) const;
  // Left shift of all pixels of the image.
  virtual HImage BitLshift(const Halcon::HTuple &Shift) const;
  // Left shift of all pixels of the image.
  virtual HImage BitLshift(Hlong Shift) const;
  // Complement all bits of the pixels.
  virtual HImage BitNot(void) const;
  // Bit-by-bit XOR of all pixels of the input images.
  virtual HImage BitXor(const HImage &Image2) const;
  // Bit-by-bit XOR of all pixels of the input images.
  virtual HImage BitXor(const HImageArray &Image2) const;
  // Bit-by-bit OR of all pixels of the input images.
  virtual HImage BitOr(const HImage &Image2) const;
  // Bit-by-bit OR of all pixels of the input images.
  virtual HImage BitOr(const HImageArray &Image2) const;
  // Bit-by-bit AND of all pixels of the input images.
  virtual HImage BitAnd(const HImage &Image2) const;
  // Bit-by-bit AND of all pixels of the input images.
  virtual HImage BitAnd(const HImageArray &Image2) const;
  // Perform a gamma encoding or decoding of an image.
  virtual HImage GammaImage(const Halcon::HTuple &Gamma, const Halcon::HTuple &Offset, const Halcon::HTuple &Threshold, const Halcon::HTuple &MaxGray, const Halcon::HTuple &Encode) const;
  // Perform a gamma encoding or decoding of an image.
  virtual HImage GammaImage(double Gamma, double Offset, double Threshold, double MaxGray, const char *Encode) const;
  // Raise an image to a power.
  virtual HImage PowImage(const Halcon::HTuple &Exponent) const;
  // Raise an image to a power.
  virtual HImage PowImage(double Exponent) const;
  // Calculate the exponentiation of an image.
  virtual HImage ExpImage(const Halcon::HTuple &Base) const;
  // Calculate the logarithm of an image.
  virtual HImage LogImage(const Halcon::HTuple &Base) const;
  // Calculate the arctangent of two images.
  virtual HImage Atan2Image(const HImage &ImageX) const;
  // Calculate the arctangent of two images.
  virtual HImage Atan2Image(const HImageArray &ImageX) const;
  // Calculate the arctangent of an image.
  virtual HImage AtanImage(void) const;
  // Calculate the arccosine of an image.
  virtual HImage AcosImage(void) const;
  // Calculate the arcsine of an image.
  virtual HImage AsinImage(void) const;
  // Calculate the tangent of an image.
  virtual HImage TanImage(void) const;
  // Calculate the cosine of an image.
  virtual HImage CosImage(void) const;
  // Calculate the sine of an image.
  virtual HImage SinImage(void) const;
  // Calculate the absolute difference of two images.
  virtual HImage AbsDiffImage(const HImage &Image2, const Halcon::HTuple &Mult) const;
  // Calculate the absolute difference of two images.
  virtual HImage AbsDiffImage(const HImage &Image2, double Mult) const;
  // Calculate the absolute difference of two images.
  virtual HImage AbsDiffImage(const HImageArray &Image2, const Halcon::HTuple &Mult) const;
  // Calculate the absolute difference of two images.
  virtual HImage AbsDiffImage(const HImageArray &Image2, double Mult) const;
  // Calculate the square root of an image.
  virtual HImage SqrtImage(void) const;
  // Subtract two images.
  virtual HImage SubImage(const HImage &ImageSubtrahend, const Halcon::HTuple &Mult, const Halcon::HTuple &Add) const;
  // Subtract two images.
  virtual HImage SubImage(const HImage &ImageSubtrahend, double Mult, double Add) const;
  // Subtract two images.
  virtual HImage SubImage(const HImageArray &ImageSubtrahend, const Halcon::HTuple &Mult, const Halcon::HTuple &Add) const;
  // Subtract two images.
  virtual HImage SubImage(const HImageArray &ImageSubtrahend, double Mult, double Add) const;
  // Scale the gray values of an image.
  virtual HImage ScaleImage(const Halcon::HTuple &Mult, const Halcon::HTuple &Add) const;
  // Scale the gray values of an image.
  virtual HImage ScaleImage(double Mult, double Add) const;
  // Divide two images.
  virtual HImage DivImage(const HImage &Image2, const Halcon::HTuple &Mult, const Halcon::HTuple &Add) const;
  // Divide two images.
  virtual HImage DivImage(const HImage &Image2, double Mult, double Add) const;
  // Divide two images.
  virtual HImage DivImage(const HImageArray &Image2, const Halcon::HTuple &Mult, const Halcon::HTuple &Add) const;
  // Divide two images.
  virtual HImage DivImage(const HImageArray &Image2, double Mult, double Add) const;
  // Multiply two images.
  virtual HImage MultImage(const HImage &Image2, const Halcon::HTuple &Mult, const Halcon::HTuple &Add) const;
  // Multiply two images.
  virtual HImage MultImage(const HImage &Image2, double Mult, double Add) const;
  // Multiply two images.
  virtual HImage MultImage(const HImageArray &Image2, const Halcon::HTuple &Mult, const Halcon::HTuple &Add) const;
  // Multiply two images.
  virtual HImage MultImage(const HImageArray &Image2, double Mult, double Add) const;
  // Add two images.
  virtual HImage AddImage(const HImage &Image2, const Halcon::HTuple &Mult, const Halcon::HTuple &Add) const;
  // Add two images.
  virtual HImage AddImage(const HImage &Image2, double Mult, double Add) const;
  // Add two images.
  virtual HImage AddImage(const HImageArray &Image2, const Halcon::HTuple &Mult, const Halcon::HTuple &Add) const;
  // Add two images.
  virtual HImage AddImage(const HImageArray &Image2, double Mult, double Add) const;
  // Calculate the absolute value (modulus) of an image.
  virtual HImage AbsImage(void) const;
  // Calculate the minimum of two images pixel by pixel.
  virtual HImage MinImage(const HImage &Image2) const;
  // Calculate the minimum of two images pixel by pixel.
  virtual HImage MinImage(const HImageArray &Image2) const;
  // Calculate the maximum of two images pixel by pixel.
  virtual HImage MaxImage(const HImage &Image2) const;
  // Calculate the maximum of two images pixel by pixel.
  virtual HImage MaxImage(const HImageArray &Image2) const;
  // Invert an image.
  virtual HImage InvertImage(void) const;
  // Apply a projective transformation to an image and specify the output
  // image size.
  virtual HImage ProjectiveTransImageSize(const Halcon::HTuple &HomMat2D, const Halcon::HTuple &Interpolation, const Halcon::HTuple &Width, const Halcon::HTuple &Height, const Halcon::HTuple &TransformDomain) const;
  // Apply a projective transformation to an image.
  virtual HImage ProjectiveTransImage(const Halcon::HTuple &HomMat2D, const Halcon::HTuple &Interpolation, const Halcon::HTuple &AdaptImageSize, const Halcon::HTuple &TransformDomain) const;
  // Apply an arbitrary affine 2D transformation to an image and specify
  // the output image size.
  virtual HImage AffineTransImageSize(const Halcon::HTuple &HomMat2D, const Halcon::HTuple &Interpolation, const Halcon::HTuple &Width, const Halcon::HTuple &Height) const;
  // Apply an arbitrary affine 2D transformation to images.
  virtual HImage AffineTransImage(const Halcon::HTuple &HomMat2D, const Halcon::HTuple &Interpolation, const Halcon::HTuple &AdaptImageSize) const;
  // Zoom an image by a given factor.
  virtual HImage ZoomImageFactor(const Halcon::HTuple &ScaleWidth, const Halcon::HTuple &ScaleHeight, const Halcon::HTuple &Interpolation) const;
  // Zoom an image by a given factor.
  virtual HImage ZoomImageFactor(double ScaleWidth, double ScaleHeight, const char *Interpolation) const;
  // Zoom an image to a given size.
  virtual HImage ZoomImageSize(const Halcon::HTuple &Width, const Halcon::HTuple &Height, const Halcon::HTuple &Interpolation) const;
  // Zoom an image to a given size.
  virtual HImage ZoomImageSize(Hlong Width, Hlong Height, const char *Interpolation) const;
  // Mirror an image.
  virtual HImage MirrorImage(const Halcon::HTuple &Mode) const;
  // Mirror an image.
  virtual HImage MirrorImage(const char *Mode) const;
  // Rotate an image about its center.
  virtual HImage RotateImage(const Halcon::HTuple &Phi, const Halcon::HTuple &Interpolation) const;
  // Rotate an image about its center.
  virtual HImage RotateImage(double Phi, const char *Interpolation) const;
  // Transform an image in polar coordinates back to cartesian coordinates
  virtual HImage PolarTransImageInv(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleEnd, const Halcon::HTuple &RadiusStart, const Halcon::HTuple &RadiusEnd, const Halcon::HTuple &Width, const Halcon::HTuple &Height, const Halcon::HTuple &Interpolation) const;
  // Transform an image in polar coordinates back to cartesian coordinates
  virtual HImage PolarTransImageInv(double Row, double Column, double AngleStart, double AngleEnd, double RadiusStart, double RadiusEnd, Hlong Width, Hlong Height, const char *Interpolation) const;
  // Transform an annular arc in an image to polar coordinates.
  virtual HImage PolarTransImageExt(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &AngleStart, const Halcon::HTuple &AngleEnd, const Halcon::HTuple &RadiusStart, const Halcon::HTuple &RadiusEnd, const Halcon::HTuple &Width, const Halcon::HTuple &Height, const Halcon::HTuple &Interpolation) const;
  // Transform an annular arc in an image to polar coordinates.
  virtual HImage PolarTransImageExt(double Row, double Column, double AngleStart, double AngleEnd, double RadiusStart, double RadiusEnd, Hlong Width, Hlong Height, const char *Interpolation) const;
  // Transform an image to polar coordinates
  virtual HImage PolarTransImage(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Width, const Halcon::HTuple &Height) const;
  // Transform an image to polar coordinates
  virtual HImage PolarTransImage(Hlong Row, Hlong Column, Hlong Width, Hlong Height) const;
  // Approximate an affine map from a displacement vector field.
  virtual HTuple VectorFieldToHomMat2d(void) const;
  // Deserialize a serialized image object.
  static HImage DeserializeImage(const Halcon::HSerializedItem &SerializedItemHandle);
  // Serialize an image object.
  virtual HSerializedItem SerializeImage(void) const;
  // Write images in graphic formats.
  virtual void WriteImage(const Halcon::HTuple &Format, const Halcon::HTuple &FillColor, const Halcon::HTuple &FileName) const;
  // Write images in graphic formats.
  virtual void WriteImage(const char *Format, Hlong FillColor, const char *FileName) const;
  // Read images.
  static HImage ReadSequence(const Halcon::HTuple &HeaderSize, const Halcon::HTuple &SourceWidth, const Halcon::HTuple &SourceHeight, const Halcon::HTuple &StartRow, const Halcon::HTuple &StartColumn, const Halcon::HTuple &DestWidth, const Halcon::HTuple &DestHeight, const Halcon::HTuple &PixelType, const Halcon::HTuple &BitOrder, const Halcon::HTuple &ByteOrder, const Halcon::HTuple &Pad, const Halcon::HTuple &Index, const Halcon::HTuple &FileName);
  // Read images.
  static HImage ReadSequence(Hlong HeaderSize, Hlong SourceWidth, Hlong SourceHeight, Hlong StartRow, Hlong StartColumn, Hlong DestWidth, Hlong DestHeight, const char *PixelType, const char *BitOrder, const char *ByteOrder, const char *Pad, Hlong Index, const char *FileName);
  // Read an image with different file formats.
  static HImage ReadImage(const Halcon::HTuple &FileName);
  // Read an image with different file formats.
  static HImage ReadImage(const char *FileName);
  // Return gray values of an image at the positions of an XLD contour.
  virtual HTuple GetGrayvalContourXld(const HXLDCont &Contour, const Halcon::HTuple &Interpolation) const;
  // Return gray values of an image at the positions of an XLD contour.
  virtual HTuple GetGrayvalContourXld(const HXLDCont &Contour, const char *Interpolation) const;
  // Create a curved gray surface with second order polynomial.
  static HImage GenImageSurfaceSecondOrder(const Halcon::HTuple &Type, const Halcon::HTuple &Alpha, const Halcon::HTuple &Beta, const Halcon::HTuple &Gamma, const Halcon::HTuple &Delta, const Halcon::HTuple &Epsilon, const Halcon::HTuple &Zeta, const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Width, const Halcon::HTuple &Height);
  // Create a curved gray surface with second order polynomial.
  static HImage GenImageSurfaceSecondOrder(const char *Type, double Alpha, double Beta, double Gamma, double Delta, double Epsilon, double Zeta, double Row, double Column, Hlong Width, Hlong Height);
  // Create a tilted gray surface with first order polynomial.
  static HImage GenImageSurfaceFirstOrder(const Halcon::HTuple &Type, const Halcon::HTuple &Alpha, const Halcon::HTuple &Beta, const Halcon::HTuple &Gamma, const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Width, const Halcon::HTuple &Height);
  // Create a tilted gray surface with first order polynomial.
  static HImage GenImageSurfaceFirstOrder(const char *Type, double Alpha, double Beta, double Gamma, double Row, double Column, Hlong Width, Hlong Height);
  // Calculate gray value features from a co-occurrence matrix.
  virtual double CoocFeatureMatrix(double *Correlation, double *Homogeneity, double *Contrast) const;
  // Detect and read 2D data code symbols in an image or
  // train the 2D data code model.
  virtual HXLDContArray FindDataCode2d(const Halcon::HDataCode2D &DataCodeHandle, const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues, Halcon::HTuple *ResultHandles, Halcon::HTuple *DecodedDataStrings) const;
  // Detect and read 2D data code symbols in an image or
  // train the 2D data code model.
  virtual HXLDContArray FindDataCode2d(const Halcon::HDataCode2D &DataCodeHandle, const char *GenParamNames, Hlong GenParamValues, Halcon::HTuple *ResultHandles, Halcon::HTuple *DecodedDataStrings) const;
  // Convert image maps into other map types.
  virtual HImage ConvertMapType(const Halcon::HTuple &NewType, const Halcon::HTuple &ImageWidth) const;
  // Convert image maps into other map types.
  virtual HImage ConvertMapType(const char *NewType, Hlong ImageWidth) const;
  // Apply a general transformation to an image.
  virtual HImage MapImage(const HImage &Map) const;
  // Generate a projection map that describes the mapping of images corresponding
  // to a changing radial distortion.
  static HImage GenRadialDistortionMap(const Halcon::HTuple &CamParamIn, const Halcon::HTuple &CamParamOut, const Halcon::HTuple &MapType);
  // Generate a projection map that describes the mapping between the image
  // plane and a the plane z=0 of a world coordinate system.
  static HImage GenImageToWorldPlaneMap(const Halcon::HTuple &CameraParam, const Halcon::HTuple &WorldPose, const Halcon::HTuple &WidthIn, const Halcon::HTuple &HeightIn, const Halcon::HTuple &WidthMapped, const Halcon::HTuple &HeightMapped, const Halcon::HTuple &Scale, const Halcon::HTuple &MapType);
  // Rectify an image by transforming it into the plane z=0 of a world 
  // coordinate system.
  virtual HImage ImageToWorldPlane(const Halcon::HTuple &CameraParam, const Halcon::HTuple &WorldPose, const Halcon::HTuple &Width, const Halcon::HTuple &Height, const Halcon::HTuple &Scale, const Halcon::HTuple &Interpolation) const;
  // Change the radial distortion of an image.
  virtual HImage ChangeRadialDistortionImage(const HRegion &Region, const Halcon::HTuple &CamParamIn, const Halcon::HTuple &CamParamOut) const;
  // Simulate an image with calibration plate.
  static HImage SimCaltab(const Halcon::HTuple &CalPlateDescr, const Halcon::HTuple &CameraParam, const Halcon::HTuple &CalPlatePose, const Halcon::HTuple &GrayBackground, const Halcon::HTuple &GrayPlate, const Halcon::HTuple &GrayMarks, const Halcon::HTuple &ScaleFac);
  // Extract rectangularly arranged 2D calibration marks from the image and
  // calculate initial values for the external camera parameters.
  virtual HTuple FindMarksAndPose(const HRegion &CalPlateRegion, const Halcon::HTuple &CalPlateDescr, const Halcon::HTuple &StartCamParam, const Halcon::HTuple &StartThresh, const Halcon::HTuple &DeltaThresh, const Halcon::HTuple &MinThresh, const Halcon::HTuple &Alpha, const Halcon::HTuple &MinContLength, const Halcon::HTuple &MaxDiamMarks, Halcon::HTuple *CCoord, Halcon::HTuple *StartPose) const;
  // Segment the region of a standard calibration plate with rectangularly
  // arranged marks in the image.
  virtual HRegion FindCaltab(const Halcon::HTuple &CalPlateDescr, const Halcon::HTuple &SizeGauss, const Halcon::HTuple &MarkThresh, const Halcon::HTuple &MinDiamMarks) const;
  // Segment the region of a standard calibration plate with rectangularly
  // arranged marks in the image.
  virtual HRegion FindCaltab(const char *CalPlateDescr, Hlong SizeGauss, Hlong MarkThresh, Hlong MinDiamMarks) const;
  // Decode bar code symbols within a rectangle.
  virtual HTuple DecodeBarCodeRectangle2(const Halcon::HBarCode &BarCodeHandle, const Halcon::HTuple &CodeType, const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Phi, const Halcon::HTuple &Length1, const Halcon::HTuple &Length2) const;
  // Decode bar code symbols within a rectangle.
  virtual HTuple DecodeBarCodeRectangle2(const Halcon::HBarCode &BarCodeHandle, const char *CodeType, double Row, double Column, double Phi, double Length1, double Length2) const;
  // Detect and read bar code symbols in an image.
  virtual HRegionArray FindBarCode(const Halcon::HBarCode &BarCodeHandle, const Halcon::HTuple &CodeType, Halcon::HTuple *DecodedDataStrings) const;
  // Detect and read bar code symbols in an image.
  virtual HRegionArray FindBarCode(const Halcon::HBarCode &BarCodeHandle, const char *CodeType, Halcon::HTuple *DecodedDataStrings) const;
  // Find regions that might contain a 2D bar code.
  virtual HRegionArray Find2dBarCode(const Halcon::HTuple &BarCodeDescr, const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues, Halcon::HTuple *CodeRegDescr) const;
  // Extract the widths of the elements inside a bar code region.
  virtual HTuple Get1dBarCodeScanline(const Halcon::HTuple &BarCodeDescr, const Halcon::HTuple &GenericName, const Halcon::HTuple &GenericValue, const Halcon::HTuple &Orientation, const Halcon::HTuple &StopIfFound, Halcon::HTuple *ScanlineNumPoints, Halcon::HTuple *ScanlineDecoded, Halcon::HTuple *ScanlinePointsRow, Halcon::HTuple *ScanlinePointsColumn) const;
  // Extract the widths of the elements inside a bar code region.
  virtual HTuple Get1dBarCode(const Halcon::HTuple &BarCodeDescr, const Halcon::HTuple &GenericName, const Halcon::HTuple &GenericValue, const Halcon::HTuple &Orientation) const;
  // Look for multiple bar code regions in an image.
  virtual HRegionArray Find1dBarCodeRegion(const Halcon::HTuple &BarCodeDescr, const Halcon::HTuple &GenericName, const Halcon::HTuple &GenericValue, Halcon::HTuple *Orientation) const;
  // Look for one bar code in an image.
  virtual HRegion Find1dBarCodeScanline(const Halcon::HTuple &BarCodeDescr, const Halcon::HTuple &GenericName, const Halcon::HTuple &GenericValue, const Halcon::HTuple &StopIfFound, Halcon::HTuple *BarcodeFound, Halcon::HTuple *BarCodeElements, Halcon::HTuple *Orientation, Halcon::HTuple *ScanlineNumPoints, Halcon::HTuple *ScanlineDecoded, Halcon::HTuple *ScanlinePointsRow, Halcon::HTuple *ScanlinePointsColumn) const;
  // Look for one bar code in an image.
  virtual HRegion Find1dBarCode(const Halcon::HTuple &BarCodeDescr, const Halcon::HTuple &GenericName, const Halcon::HTuple &GenericValue, Halcon::HTuple *BarcodeFound, Halcon::HTuple *BarCodeElements, Halcon::HTuple *Orientation) const;
  // Return the estimated background image.
  static HImage GiveBgEsti(const Halcon::HBgEsti &BgEstiHandle);
  // Change the estimated background image.
  virtual void UpdateBgEsti(const HRegion &UpDateRegion, const Halcon::HBgEsti &BgEstiHandle) const;
  // Estimate the background and return the foreground region.
  virtual HRegion RunBgEsti(const Halcon::HBgEsti &BgEstiHandle) const;
  // Generate and initialize a data set for the background estimation.
  virtual HBgEsti CreateBgEsti(const Halcon::HTuple &Syspar1, const Halcon::HTuple &Syspar2, const Halcon::HTuple &GainMode, const Halcon::HTuple &Gain1, const Halcon::HTuple &Gain2, const Halcon::HTuple &AdaptMode, const Halcon::HTuple &MinDiff, const Halcon::HTuple &StatNum, const Halcon::HTuple &ConfidenceC, const Halcon::HTuple &TimeC) const;
  // Generate and initialize a data set for the background estimation.
  virtual HBgEsti CreateBgEsti(double Syspar1, double Syspar2, const char *GainMode, double Gain1, double Gain2, const char *AdaptMode, double MinDiff, Hlong StatNum, double ConfidenceC, double TimeC) const;
  // Asynchronous grab of images and preprocessed image data from the specified
  // image acquisition device.
  static HImage GrabDataAsync(HRegion *Region, HXLDCont *Contours, const Halcon::HFramegrabber &AcqHandle, const Halcon::HTuple &MaxDelay, char *Data);
  // Asynchronous grab of images and preprocessed image data from the specified
  // image acquisition device.
  static HImage GrabDataAsync(HRegion *Region, HXLDCont *Contours, const Halcon::HFramegrabber &AcqHandle, double MaxDelay, char *Data);
  // Synchronous grab of images and preprocessed image data from the specified
  // image acquisition device.
  static HImage GrabData(HRegion *Region, HXLDCont *Contours, const Halcon::HFramegrabber &AcqHandle, char *Data);
  // Asynchronous grab of an image from the specified image acquisition device.
  static HImage GrabImageAsync(const Halcon::HFramegrabber &AcqHandle, const Halcon::HTuple &MaxDelay);
  // Asynchronous grab of an image from the specified image acquisition device.
  static HImage GrabImageAsync(const Halcon::HFramegrabber &AcqHandle, double MaxDelay);
  // Synchronous grab of an image from the specified image acquisition device.
  static HImage GrabImage(const Halcon::HFramegrabber &AcqHandle);
};

}

#endif
