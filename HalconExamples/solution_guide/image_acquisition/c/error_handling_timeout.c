/*****************************************************************************
 * error_handling_timeout.c
 ***************************************************************************** 
 *
 * Project:      Application Note on Image Acquisition
 * Description:  Example program showing how to handle image acquisition errors
 *
 * (c) 2002-2018 by MVTec Software GmbH
 *               www.mvtec.com
 *****************************************************************************
 * Handling timeout errors using set_check
 * NOTE: The example is preconfigured for the HALCON uEye interface.
 *       Please adapt the marked lines for your own image acquisition device.
 *****************************************************************************
 */



#include "HalconC.h"
#include <stdio.h>


int main(int argc, char *argv[])
{
  Herror      error_num;                   
  /* -> please adapt these lines to your own image acquisition device */
  char        *acqname = "uEye";
  char        message[MAX_STRING];
  Hlong       acqhandle, window, width, height, button = 0;
  Hobject     image;
  Htuple      acqhandle_t, params, values;

  printf("\n--------------------------------------------------------------\n");
  printf("Example program for the Application Note on Image Acquisition:\n");
  printf("--------------------------------------------------------------\n");
  printf("- showing how to use the class HFramegrabber\n");
  printf("- using customized exception handling to catch timeout errors \n");
  printf("- timeout provoked by using non-existing external trigger\n");
  printf("--------------------------------------------------------------\n\n");
  /* open the connection including an external trigger */
  printf("Connecting to the image acquisition device ... \n");
  /* -> please adapt this line to your own image acquisition device */
  open_framegrabber(acqname, 1, 1, 0, 0, 0, 0, "default", 8, "gray", -1,
                    "true", "default", "default", -1, -1, &acqhandle);

  /* set the timeout to 2s */
  /* -> please adapt these lines to your own image acquisition device */
  create_tuple(&acqhandle_t, 1); set_i(acqhandle_t, acqhandle, 0);
  create_tuple(&params, 1); set_s(params, "grab_timeout", 0);
  create_tuple(&values, 1); set_i(values, 2000, 0);
  T_set_framegrabber_param (acqhandle_t, params, values);

  /* switch on the manual error handling */
  set_check ("~give_error");

  /* now try to grab an image */
  printf("Trying to grab a first image ... ");
  error_num = grab_image (&image, acqhandle);

  /* switch off  the error handling, then check the return value */ 
  set_check ("give_error");
  switch (error_num)
  {
  case  H_MSG_TRUE:
    printf("successfully.\n\n");
    break;

  case H_ERR_FGTIMEOUT:
    printf("failed!\n");
    printf("Cause: timeout -> disabling the external trigger.\n");
    /* timeout! disable external trigger mode */
    /* -> please adapt these lines to your own image acquisition device */
    close_framegrabber(acqhandle);
    open_framegrabber(acqname, 1, 1, 0, 0, 0, 0, "default", 8, "gray", -1,
                      "false", "default", "default", -1, -1, &acqhandle);
    printf("Trying again to grab an image ... ");
    set_check ("~give_error");
    error_num = grab_image (&image, acqhandle);
    set_check ("give_error");
    
    if (error_num == H_MSG_TRUE)
    {
      printf("successfully.\n\n");
    }
    else
    {
      printf("failed!\n");
      get_error_text(error_num, (char*) &message);
      printf("Cause: %s (HALCON error %i)\n", message, error_num);
      return error_num;
    }
    break;

  default:
    get_error_text(error_num, (char*) &message);
    printf("Cause: %s (HALCON error %i)\n", message, error_num);
    return error_num;
  }

  /* everything okay */
  get_image_pointer1 (image, (Hlong*) NULL, (char*) NULL, &width, &height);
  open_window (0, 0, width/2, height/2, 0, "visible", "", &window);
  disp_obj(image,window);
  
  printf("Click into window to quit ...");
  do
  {
    /* grab and display a new image */
    grab_image_async (&image, acqhandle, -1);
    disp_obj(image,window);
    /* check for mouse click */
    set_check ("~give_error");
    error_num = get_mposition(window, (Hlong*) NULL, (Hlong*) NULL, &button); 
    set_check ("give_error");
    if (error_num != H_MSG_TRUE)
    {
      button = 0;
    }
  } while (button == 0);
  
  printf(" exiting.\n\n");


  /* -------------------  end of the application  ----------------- */
  close_framegrabber (acqhandle);

  /* Clear object-params */
  clear_obj(image);

  return 0;
}
        
        
      


