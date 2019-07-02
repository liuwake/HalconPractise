/*****************************************************************************
 * HBgEsti.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HBgEsti
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_BG_ESTI_H
#define H_BG_ESTI_H

#include "HCPPToolRef.h"

namespace Halcon {


class LIntExport HBgEsti: public HToolBase 
{
  friend class HImage;
  
public:

  // Tool-specific functional class constructors

  HBgEsti(const HImage &InitializeImage, 
          const HTuple &Syspar1 = 0.7, const HTuple &Syspar2 = 0.7, 
          const HTuple &GainMode = "fixed", 
          const HTuple &Gain1 = 0.002, const HTuple &Gain2 = 0.002, 
          const HTuple &AdaptMode = "on", 
          const HTuple &MinDiff = 7, 
          const HTuple &StatNum = 10, 
          const HTuple &ConfidenceC = 3.25, 
          const HTuple &TimeC = 15);
          
  HBgEsti(const HImage &InitializeImage, 
          double        Syspar1 = 0.7, double Syspar2 = 0.7, 
          const char   *GainMode = "fixed", 
          double        Gain1 = 0.002, double Gain2 = 0.002, 
          const char   *AdaptMode = "on", 
          double        MinDiff = 7, 
          Hlong          StatNum = 10, 
          double        ConfidenceC = 3.25, 
          double        TimeC = 15);
          
          

  // Common tool class management functionality

  HBgEsti();
  HBgEsti(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Return the estimated background image.
  virtual HImage GiveBgEsti() const;
  // Change the estimated background image.
  virtual void UpdateBgEsti(const HImage &PresentImage, const HRegion &UpDateRegion) const;
  // Estimate the background and return the foreground region.
  virtual HRegion RunBgEsti(const HImage &PresentImage) const;
  // Return the parameters of the data set.
  virtual double GetBgEstiParams(Halcon::HTuple *Syspar2, Halcon::HTuple *GainMode, Halcon::HTuple *Gain1, Halcon::HTuple *Gain2, Halcon::HTuple *AdaptMode, Halcon::HTuple *MinDiff, Halcon::HTuple *StatNum, Halcon::HTuple *ConfidenceC, Halcon::HTuple *TimeC) const;
  // Return the parameters of the data set.
  virtual double GetBgEstiParams(double *Syspar2, char *GainMode, double *Gain1, double *Gain2, char *AdaptMode, double *MinDiff, Hlong *StatNum, double *ConfidenceC, double *TimeC) const;
  // Change the parameters of the data set.
  virtual void SetBgEstiParams(const Halcon::HTuple &Syspar1, const Halcon::HTuple &Syspar2, const Halcon::HTuple &GainMode, const Halcon::HTuple &Gain1, const Halcon::HTuple &Gain2, const Halcon::HTuple &AdaptMode, const Halcon::HTuple &MinDiff, const Halcon::HTuple &StatNum, const Halcon::HTuple &ConfidenceC, const Halcon::HTuple &TimeC) const;
  // Change the parameters of the data set.
  virtual void SetBgEstiParams(double Syspar1, double Syspar2, const char *GainMode, double Gain1, double Gain2, const char *AdaptMode, double MinDiff, Hlong StatNum, double ConfidenceC, double TimeC) const;
  // Generate and initialize a data set for the background estimation.
  virtual void CreateBgEsti(const HImage &InitializeImage, const Halcon::HTuple &Syspar1, const Halcon::HTuple &Syspar2, const Halcon::HTuple &GainMode, const Halcon::HTuple &Gain1, const Halcon::HTuple &Gain2, const Halcon::HTuple &AdaptMode, const Halcon::HTuple &MinDiff, const Halcon::HTuple &StatNum, const Halcon::HTuple &ConfidenceC, const Halcon::HTuple &TimeC);
  // Generate and initialize a data set for the background estimation.
  virtual void CreateBgEsti(const HImage &InitializeImage, double Syspar1, double Syspar2, const char *GainMode, double Gain1, double Gain2, const char *AdaptMode, double MinDiff, Hlong StatNum, double ConfidenceC, double TimeC);
};

}

#endif
