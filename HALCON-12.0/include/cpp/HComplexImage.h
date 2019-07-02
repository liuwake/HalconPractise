/*****************************************************************************
 * HComplexImage.h
 ***************************************************************************** 
 *
 * Project:     Halcon/C++
 * Description: Types for Complex-images
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */


#ifndef H_COMPLEX_IMAGE_H
#define H_COMPLEX_IMAGE_H


namespace Halcon {


class LIntExport HComplexImage: public HImage {
public:
  HComplexImage(void);
  HComplexImage(const HImage &image);
  HComplexImage(const HComplexImage &image);
  HComplexImage(int width, int height);
  HComplexImage(const float *real, const float *ima, int width, int height);
  HComplexImage(const HFloatImage &real, const HFloatImage &ima,
                int width, int height);
  virtual ~HComplexImage(void);
  
  // Tools
  const char *ClassName(void) const {return "HComplexImage";}
  const char *InstClassName(void) const {return "HComplexImage";}
  
  // Pixel Access
  HComplex operator[] (Hlong k) const
  {if (!privat) ((HComplexImage*)this)->Private(); return ((HComplex*)ptr)[k];}
  HComplex &operator[] (Hlong k)
  {if (!init) Init(); return ((HComplex*)ptr)[k];}
  HComplex &operator()(int x, int y) 
  {if (!init) Init(); return ((HComplex*)ptr)[HLinearCoord(x,y,width)];}
  HComplex &operator()(Hlong k) 
  {if (!init) Init(); return ((HComplex*)ptr)[k];}
  void SetPixVal(Hlong k, const HPixVal &val);
  void SetPixVal(int x, int y, const HPixVal &val); 
};


}


#endif
