/*****************************************************************************
 * HUInt2Image.h
 ***************************************************************************** 
 *
 * Project:     Halcon/C++
 * Description: Types for unsigned short-images
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 */

#ifndef H_UINT2_IMAGE_H
#define H_UINT2_IMAGE_H


namespace Halcon {


class LIntExport HUInt2Image: public HImage {
public:
  HUInt2Image(void);
  HUInt2Image(const char *file);
  HUInt2Image(const HImage &image);
  HUInt2Image(const HUInt2Image &image);
  HUInt2Image(const HInt1Image &image);
  HUInt2Image(const HInt2Image &image);
  HUInt2Image(const HInt4Image &image);
  HUInt2Image(const HFloatImage &image);
  HUInt2Image(const HComplexImage &image);
  HUInt2Image(const HByteImage &image);
  HUInt2Image(int width, int height);
  HUInt2Image(HUInt2 *ptr, int width, int height);
  virtual ~HUInt2Image(void);
  
  // Tools
  const char *ClassName(void) const {return "HUInt2Image";}

  // Pixel Access
  int operator[] (Hlong k) const
  {if (!privat) ((HUInt2Image*)this)->Private();return ((UINT2*)ptr)[k];}
  UINT2 &operator[] (Hlong k)
  {if (!init) Init();return ((UINT2*)ptr)[k];}
  UINT2 &operator()(int x, int y) 
  {if (!init) Init();return ((UINT2*)ptr)[HLinearCoord(x,y,width)];}
  UINT2 &operator()(Hlong k) 
  {if (!init) Init();return ((UINT2*)ptr)[k];}
  void SetPixVal(Hlong k, const HPixVal &val); 
  void SetPixVal(int x, int y, const HPixVal &val); 
};


}


#endif
