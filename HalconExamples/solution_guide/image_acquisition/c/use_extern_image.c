/*****************************************************************************
 * use_extern_image.c
 ***************************************************************************** 
 *
 * Project:      Application Note on Image Acquisition
 * Description:  Example program showing how to use externally created images
 *
 * (c) 2002-2018 by MVTec Software GmbH
 *               www.mvtec.com
 *****************************************************************************
 * Passing images created by malloc to HALCON using gen_image1_extern
 *****************************************************************************
 */



#include "HalconC.h"
#include <stdio.h>

/* declare auxiliary procedures */
int InitializeBuffer(unsigned char **image_buffer, Hlong *width_ptr, 
                     Hlong *height_ptr);
int MyGrabImage(const unsigned char **image_buffer);
int ButtonPressed(Hlong window_id);



int main(int argc, char *argv[])
{
  unsigned char *image_matrix_ptr;
  Hlong         width, height;

  Hobject       image;
  long          window_id;

  printf("\n--------------------------------------------------------------\n");
  printf("Example program for the Application Note on Image Acquisition:\n");
  printf("--------------------------------------------------------------\n");
  printf("- showing how to pass externally created images to HALCON\n");
  printf("--------------------------------------------------------------\n\n");

  /* simulate the initialization of an image buffer */
  InitializeBuffer(&image_matrix_ptr, &width, &height);

  set_window_attr("window_title", 
                  "Example use_extern_image: Exit via any mouse button");
  open_window (0, 0, width, height, 0, "visible", "", (Hlong*)&window_id);

  printf("Click into window to quit ... \n");

  while (!ButtonPressed(window_id))
  {
    /* simulate the grabbing */
    MyGrabImage((const unsigned char **) &image_matrix_ptr);
    /* pass the "grabbed" image to HALCON */
    gen_image1_extern(&image, "byte", (Hlong)width, (Hlong)height, 
                      (long) image_matrix_ptr, (long) 0);

    disp_obj(image, window_id);
  }

  /* clear up */
  close_window(window_id);
  clear_obj(image);
  free(image_matrix_ptr);

  return 0;
}


/* This procedure simulates the initialization of an image buffer; via malloc,
   it allocates memory corresponding to the images which are later "grabbed"
   via the procedure MyGrabImage. */
int InitializeBuffer(unsigned char **image_buffer, Hlong *width_ptr, 
                     Hlong *height_ptr)
{
  Hobject       image;
  Hlong         pointer;
  char          type[128];

  read_image(&image, "pendulum/pendulum_00");
  get_image_pointer1(image, &pointer, (char *) type, 
                     width_ptr, height_ptr);

  *image_buffer = malloc(*width_ptr * *height_ptr);

  return 0;
}


/* This procedure simulates an external grabbing process; it reads images
   from an image file sequence and copies them into the buffer area 
   specified with the parameter image_buffer. */
int MyGrabImage(const unsigned char **image_buffer)
{
  Hobject       image;
  static int    image_num = 0;
  Hlong         pointer;
  char          type[128];
  Hlong         width, height;
  char          file_name[128];

  sprintf((char *) file_name, "pendulum/pendulum_%.2i", image_num);
  read_image(&image, file_name);

  get_image_pointer1(image, &pointer, (char *) type, &width, &height);
  memcpy((void *) *image_buffer, (const void *) pointer, width*height);

  image_num = (image_num + 1) % 20;
  return 0;
}


int ButtonPressed(Hlong window_id)
{
  Hlong         row, col, button;

  set_check ("~give_error");
  get_mposition(window_id, &row, &col, &button);
  set_check ("give_error");

  return (button > 0);
}


