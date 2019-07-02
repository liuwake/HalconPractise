/*****************************************************************************
 * HInt2Image.h
 ***************************************************************************** 
 *
 * Project:     Halcon/C++
 * Description: Types for short-images
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */


#ifndef H_INT2_IMAGE_H
#define H_INT2_IMAGE_H


namespace Halcon {


class LIntExport HInt2Image: public HImage {
public:
  HInt2Image(void);
  HInt2Image(const char *file);
  HInt2Image(const HImage &image);
  HInt2Image(const HInt2Image &image);
  HInt2Image(const HInt1Image &image);
  HInt2Image(const HUInt2Image &image);
  HInt2Image(const HInt4Image &image);
  HInt2Image(const HFloatImage &image);
  HInt2Image(const HComplexImage &image);
  HInt2Image(const HByteImage &image);
  HInt2Image(int width, int height);
  HInt2Image(HInt2 *ptr, int width, int height);
  virtual ~HInt2Image(void);
  
  // Tools
  const char *ClassName(void) const {return "HInt2Image";}

  // Pixel Access
  int operator[] (Hlong k) const
  {if (!privat) ((HInt2Image*)this)->Private();return ((INT2*)ptr)[k];}
  INT2 &operator[] (Hlong k)
  {if (!init) Init();return ((INT2*)ptr)[k];}
  INT2 &operator()(int x, int y) 
  {if (!init) Init();return ((INT2*)ptr)[HLinearCoord(x,y,width)];}
  INT2 &operator()(Hlong k) 
  {if (!init) Init();return ((INT2*)ptr)[k];}
  void SetPixVal(Hlong k, const HPixVal &val); 
  void SetPixVal(int x, int y, const HPixVal &val); 
};


}


#endif
