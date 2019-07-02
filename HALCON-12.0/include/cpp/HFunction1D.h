/*****************************************************************************
 * HFunction1D.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HFunction1D
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_FUNCTION_1D_H
#define H_FUNCTION_1D_H


namespace Halcon {


class LIntExport HFunction1D: public HRootObject {
public:
  HFunction1D(void) {id = -1;}
  HFunction1D(const HTuple &YValues);
  HFunction1D(double YValues);
  HFunction1D(const HTuple &XValues, const HTuple &YValues);
  HFunction1D(double XValues, double YValues);

private:
  // Internal Cleanup
  void Cleanup(void);

public:
  // Tools
  const char *ClassName(void) const {return "HFunction1D";}

  // Cast Operator
  operator HTuple () const {return GetHandle();}

  // Access and Manipulation
  HTuple GetHandle(void) const {return id;}
  void   SetHandle(HTuple ID) {id = ID;}

private:
  HTuple  id;
public:
  // Plot a function using gnuplot.
  virtual void GnuplotPlotFunct1d(const Halcon::HGnuplot &GnuplotFileID) const;
  // Compose two functions.
  virtual HTuple ComposeFunct1d(const Halcon::HTuple &Function2, const Halcon::HTuple &Border) const;
  // Calculate the inverse of a function.
  virtual HTuple InvertFunct1d() const;
  // Calculate the derivatives of a function.
  virtual HTuple DerivateFunct1d(const Halcon::HTuple &Mode) const;
  // Calculate the local minimum and maximum points of a function.
  virtual HTuple LocalMinMaxFunct1d(const Halcon::HTuple &Mode, const Halcon::HTuple &Interpolation, Halcon::HTuple *Max) const;
  // Calculate the zero crossings of a function.
  virtual HTuple ZeroCrossingsFunct1d() const;
  // Multiplication and addition of the y values.
  virtual HTuple ScaleYFunct1d(const Halcon::HTuple &Mult, const Halcon::HTuple &Add) const;
  // Negation of the y values.
  virtual HTuple NegateFunct1d() const;
  // Absolute value of the y values.
  virtual HTuple AbsFunct1d() const;
  // Return the value of a function at an arbitrary position.
  virtual HTuple GetYValueFunct1d(const Halcon::HTuple &X, const Halcon::HTuple &Border) const;
  // Access a function value using the index of the control points.
  virtual HTuple GetPairFunct1d(const Halcon::HTuple &Index, Halcon::HTuple *Y) const;
  // Access a function value using the index of the control points.
  virtual double GetPairFunct1d(const Halcon::HTuple &Index, double *Y) const;
  // Number of control points of the function.
  virtual Hlong NumPointsFunct1d() const;
  // Smallest and largest y value of the function.
  virtual double YRangeFunct1d(Halcon::HTuple *YMax) const;
  // Smallest and largest y value of the function.
  virtual double YRangeFunct1d(double *YMax) const;
  // Smallest and largest x value of the function.
  virtual double XRangeFunct1d(Halcon::HTuple *XMax) const;
  // Smallest and largest x value of the function.
  virtual double XRangeFunct1d(double *XMax) const;
  // Access to the x/y values of a function.
  virtual HTuple Funct1dToPairs(Halcon::HTuple *YValues) const;
  // Sample a function equidistantly in an interval.
  virtual HTuple SampleFunct1d(const Halcon::HTuple &XMin, const Halcon::HTuple &XMax, const Halcon::HTuple &XDist, const Halcon::HTuple &Border) const;
  // Transform a function using given transformation parameters.
  virtual HTuple TransformFunct1d(const Halcon::HTuple &Params) const;
  // Calculate transformation parameters between two functions.
  virtual HTuple MatchFunct1dTrans(const Halcon::HTuple &Function2, const Halcon::HTuple &Border, const Halcon::HTuple &ParamsConst, const Halcon::HTuple &UseParams, Halcon::HTuple *ChiSquare, Halcon::HTuple *Covar) const;
  // Calculate transformation parameters between two functions.
  virtual HTuple MatchFunct1dTrans(const Halcon::HTuple &Function2, const Halcon::HTuple &Border, const Halcon::HTuple &ParamsConst, const Halcon::HTuple &UseParams, double *ChiSquare, Halcon::HTuple *Covar) const;
  // Compute the distance of two functions.
  virtual HTuple DistanceFunct1d(const Halcon::HTuple &Function2, const Halcon::HTuple &Mode, const Halcon::HTuple &Sigma) const;
  // Smooth an equidistant 1D function with a Gaussian function.
  virtual HTuple SmoothFunct1dGauss(const Halcon::HTuple &Sigma) const;
  // Compute the positive and negative areas of a function.
  virtual double IntegrateFunct1d(Halcon::HTuple *Negative) const;
  // Read a function from a file.
  virtual void ReadFunct1d(const Halcon::HTuple &FileName);
  // Read a function from a file.
  virtual void ReadFunct1d(const char *FileName);
  // Write a function to a file.
  virtual void WriteFunct1d(const Halcon::HTuple &FileName) const;
  // Create a function from a sequence of y-values.
  virtual void CreateFunct1dArray(const Halcon::HTuple &YValues);
  // Create a function from a sequence of y-values.
  virtual void CreateFunct1dArray(double YValues);
  // Create a function from a set of (x,y) pairs.
  virtual void CreateFunct1dPairs(const Halcon::HTuple &XValues, const Halcon::HTuple &YValues);
  // Create a function from a set of (x,y) pairs.
  virtual void CreateFunct1dPairs(double XValues, double YValues);
  // Smooth an equidistant 1D function by averaging its values.
  virtual HTuple SmoothFunct1dMean(const Halcon::HTuple &SmoothSize, const Halcon::HTuple &Iterations) const;
};

}

#endif
