/*****************************************************************************
 * error_handling_timeout.cpp
 ***************************************************************************** 
 *
 * Project:      Application Note on Image Acquisition
 * Description:  Example program showing how to handle image acquisition errors
 *
 * (c) 2002-2018 by MVTec Software GmbH
 *               www.mvtec.com
 *****************************************************************************
 * Handling timeout errors using HException and try/catch
 * NOTE: The example is preconfigured for the HALCON uEye interface
 *       Please adapt the marked lines for your own image acquisition device.
 *****************************************************************************
 */

#ifndef __APPLE__
#  include "HalconCpp.h"
#  include "HIOStream.h"
#else
#  ifndef HC_LARGE_IMAGES
#    include <HALCONCpp/HalconCpp.h>
#    include <HALCONCpp/HIOStream.h>
#  else
#    include <HALCONCppxl/HalconCpp.h>
#    include <HALCONCppxl/HIOStream.h>
#  endif
#endif

#if !defined(USE_IOSTREAM_H)
using namespace std;
#endif


int main(int argc, char *argv[])
{
  using namespace HalconCpp;
  HFramegrabber   acqdevice;
  // -> please adapt the following lines to your own image acquisition device
  const char     *acqname = "uEye";
  HImage          image;
  HTuple          width, height;

  cout << "\n--------------------------------------------------------------\n";
  cout << "Example program for the Application Note on Image Acquisition:\n";
  cout << "--------------------------------------------------------------\n";
  cout << "- showing how to use the class HFramegrabber\n";
  cout << "- using customized exception handling to catch timeout errors \n";
  cout << "- timeout provoked by using non-existing external trigger\n";
  cout << "--------------------------------------------------------------\n\n";

  // open the connection including an external trigger
  cout << "Connecting to the image acquisition device ... \n";
  // -> please adapt this line to your own image acquisition device
  acqdevice.OpenFramegrabber(acqname, 1, 1, 0, 0, 0, 0, "default", -1,
                             "gray", -1, "true", "default", "default", -1, -1);

  // set the timeout to 2s 
  // -> please adapt this line to your own image acquisition device
  acqdevice.SetFramegrabberParam("grab_timeout", 2000);

  try
  {
    cout << "Trying to grab a first image ... ";
    image = acqdevice.GrabImage();
    cout << "successfully.\n\n";
  }
  catch (HException &except)
  {
    cout << "failed!\n";
    if (except.ErrorCode() == H_ERR_FGTIMEOUT)
    {
      cout << "Cause: timeout -> disabling the external trigger.\n";
      // disabling the external trigger 
      // -> please adapt this line to your own image acquisition device
      acqdevice.SetFramegrabberParam("external_trigger", "false");
      // try again
      try
      {
        cout << "Trying again to grab an image ... ";
        image = acqdevice.GrabImage();
        cout << "successfully.\n\n";
      }
      catch (HException except)
      {
        cout << "failed!\n";
        cout << "Cause: " << except.ErrorMessage() << "(HALCON error "
             << except.ErrorCode() << ")\n";
        return except.ErrorCode();
      }
    }
    else
    {
      cout << "Cause: " << except.ErrorMessage() << "(HALCON error "
           << except.ErrorCode() << ")\n";
      return except.ErrorCode();
    }
  }
    
  // everything okay now
  width = image.Width();
  height = image.Height();

  HWindow           window(0, 0, *width.LArr()/2, *height.LArr()/2);
  Hlong             button = 0;

  image.DispImage(window);

  cout << "Click into window to quit ..." << flush;
  do
  {
    // grab and display a new image
    image = acqdevice.GrabImageAsync(-1);
    image.DispImage(window);
    // check for mouse click
    try { window.GetMposition(NULL, NULL, &button); }
    catch (HException except) { button = 0; }
  } while (button == 0);

  cout << "exiting.\n\n";

  /* -------------------  end of the application  ----------------- */

  return 0;
}
