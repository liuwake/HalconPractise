/*****************************************************************************
 * HFramegrabber.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HFramegrabber
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_FRAMEGRABBER_H
#define H_FRAMEGRABBER_H


#include "HCPPToolRef.h"


namespace Halcon {


class LIntExport HFramegrabber: public HToolBase 
{
public:

  // Tool-specific functional class constructors

  HFramegrabber(
      const HTuple &Name, 
      const HTuple &HorizontalResolution = 1, const HTuple &VerticalResolution = 1,
      const HTuple &ImageWidth = 0,           const HTuple &ImageHeight = 0,
      const HTuple &StartRow = 0,             const HTuple &StartColumn = 0,
      const HTuple &Field = "default",
      const HTuple &BitsPerChannel = -1, 
      const HTuple &ColorSpace = "default",
      const HTuple &Gain = -1,
      const HTuple &ExternalTrigger = "default", 
      const HTuple &CameraType = "default",
      const HTuple &Device = "default",
      const HTuple &Port = -1,
      const HTuple &LineIn = -1);
      
  HFramegrabber(
      const char *Name, 
      Hlong HorizontalResolution = 1, Hlong VerticalResolution = 1,
      Hlong ImageWidth = 0,           Hlong ImageHeight = 0,
      Hlong StartRow = 0,             Hlong StartColumn = 0,
      const char *Field = "default",
      Hlong BitsPerChannel = -1, 
      const char *ColorSpace = "default",
      double Gain = -1,
      const char *ExternalTrigger = "default", 
      const char *CameraType = "default",
      const char *Device = "default",
      Hlong Port = -1,
      Hlong LineIn = -1);


  // Common tool class management functionality

  HFramegrabber();
  HFramegrabber(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Query specific parameters of an image acquisition device.
  virtual HTuple GetFramegrabberParam(const Halcon::HTuple &Param) const;
  // Query specific parameters of an image acquisition device.
  virtual HTuple GetFramegrabberParam(const char *Param) const;
  // Set specific parameters of an image acquistion device.
  virtual void SetFramegrabberParam(const Halcon::HTuple &Param, const Halcon::HTuple &Value) const;
  // Query callback function of an image acquisition device.
  virtual Hlong GetFramegrabberCallback(const Halcon::HTuple &CallbackType, Halcon::HTuple *UserContext) const;
  // Query callback function of an image acquisition device.
  virtual Hlong GetFramegrabberCallback(const Halcon::HTuple &CallbackType, Hlong *UserContext) const;
  // Query callback function of an image acquisition device.
  virtual Hlong GetFramegrabberCallback(const char *CallbackType, Halcon::HTuple *UserContext) const;
  // Query callback function of an image acquisition device.
  virtual Hlong GetFramegrabberCallback(const char *CallbackType, Hlong *UserContext) const;
  // Register a callback function for an image acquisition device.
  virtual void SetFramegrabberCallback(const Halcon::HTuple &CallbackType, const Halcon::HTuple &CallbackFunction, const Halcon::HTuple &UserContext) const;
  // Register a callback function for an image acquisition device.
  virtual void SetFramegrabberCallback(const char *CallbackType, Hlong CallbackFunction, Hlong UserContext) const;
  // Asynchronous grab of images and preprocessed image data from the specified
  // image acquisition device.
  virtual HImageArray GrabDataAsync(HRegion *Region, HXLDCont *Contours, const Halcon::HTuple &MaxDelay, Halcon::HTuple *Data) const;
  // Asynchronous grab of images and preprocessed image data from the specified
  // image acquisition device.
  virtual HImageArray GrabDataAsync(HRegion *Region, HXLDCont *Contours, const Halcon::HTuple &MaxDelay, char *Data) const;
  // Asynchronous grab of images and preprocessed image data from the specified
  // image acquisition device.
  virtual HImageArray GrabDataAsync(HRegion *Region, HXLDCont *Contours, double MaxDelay, Halcon::HTuple *Data) const;
  // Asynchronous grab of images and preprocessed image data from the specified
  // image acquisition device.
  virtual HImageArray GrabDataAsync(HRegion *Region, HXLDCont *Contours, double MaxDelay, char *Data) const;
  // Synchronous grab of images and preprocessed image data from the specified
  // image acquisition device.
  virtual HImageArray GrabData(HRegion *Region, HXLDCont *Contours, Halcon::HTuple *Data) const;
  // Synchronous grab of images and preprocessed image data from the specified
  // image acquisition device.
  virtual HImageArray GrabData(HRegion *Region, HXLDCont *Contours, char *Data) const;
  // Asynchronous grab of an image from the specified image acquisition device.
  virtual HImage GrabImageAsync(const Halcon::HTuple &MaxDelay) const;
  // Asynchronous grab of an image from the specified image acquisition device.
  virtual HImage GrabImageAsync(double MaxDelay) const;
  // Start an asynchronous grab from the specified image acquisition device.
  virtual void GrabImageStart(const Halcon::HTuple &MaxDelay) const;
  // Start an asynchronous grab from the specified image acquisition device.
  virtual void GrabImageStart(double MaxDelay) const;
  // Synchronous grab of an image from the specified image acquisition device.
  virtual HImage GrabImage() const;
  // Open and configure an image acquisition device.
  virtual void OpenFramegrabber(const Halcon::HTuple &Name, const Halcon::HTuple &HorizontalResolution, const Halcon::HTuple &VerticalResolution, const Halcon::HTuple &ImageWidth, const Halcon::HTuple &ImageHeight, const Halcon::HTuple &StartRow, const Halcon::HTuple &StartColumn, const Halcon::HTuple &Field, const Halcon::HTuple &BitsPerChannel, const Halcon::HTuple &ColorSpace, const Halcon::HTuple &Generic, const Halcon::HTuple &ExternalTrigger, const Halcon::HTuple &CameraType, const Halcon::HTuple &Device, const Halcon::HTuple &Port, const Halcon::HTuple &LineIn);
  // Open and configure an image acquisition device.
  virtual void OpenFramegrabber(const char *Name, Hlong HorizontalResolution, Hlong VerticalResolution, Hlong ImageWidth, Hlong ImageHeight, Hlong StartRow, Hlong StartColumn, const char *Field, Hlong BitsPerChannel, const char *ColorSpace, double Generic, const char *ExternalTrigger, const char *CameraType, const char *Device, Hlong Port, Hlong LineIn);
  // Query look-up table of the image acquisition device.
  virtual HTuple GetFramegrabberLut(Halcon::HTuple *ImageGreen, Halcon::HTuple *ImageBlue) const;
  // Set look-up table of the image acquisition device.
  virtual void SetFramegrabberLut(const Halcon::HTuple &ImageRed, const Halcon::HTuple &ImageGreen, const Halcon::HTuple &ImageBlue) const;
};

}

#endif
