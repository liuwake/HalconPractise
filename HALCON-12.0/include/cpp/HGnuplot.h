/*****************************************************************************
 * HGnuplot.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HGnuplot
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_GNUPLOT_H
#define H_GNUPLOT_H


#include "HCPPToolRef.h"



namespace Halcon {


class LIntExport HGnuplot: public HToolBase
{
public:

  // Tool-specific functional class constructors

  HGnuplot(const HTuple &FileName);
  HGnuplot(const char *FileName);

  // Common tool class management functionality

  HGnuplot();
  HGnuplot(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Plot a function using gnuplot.
  virtual void GnuplotPlotFunct1d(const Halcon::HTuple &Function) const;
  // Plot control values using gnuplot.
  virtual void GnuplotPlotCtrl(const Halcon::HTuple &Values) const;
  // Visualize images using gnuplot.
  virtual void GnuplotPlotImage(const HImage &Image, const Halcon::HTuple &SamplesX, const Halcon::HTuple &SamplesY, const Halcon::HTuple &ViewRotX, const Halcon::HTuple &ViewRotZ, const Halcon::HTuple &Hidden3D) const;
  // Visualize images using gnuplot.
  virtual void GnuplotPlotImage(const HImage &Image, Hlong SamplesX, Hlong SamplesY, double ViewRotX, double ViewRotZ, const char *Hidden3D) const;
  // Open a gnuplot file for visualization of images and control values.
  virtual void GnuplotOpenFile(const Halcon::HTuple &FileName);
  // Open a gnuplot file for visualization of images and control values.
  virtual void GnuplotOpenFile(const char *FileName);
  // Open a pipe to a gnuplot process for visualization of images and control
  // values.
  virtual void GnuplotOpenPipe(void);
};

}

#endif
