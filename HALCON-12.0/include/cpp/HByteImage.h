/*****************************************************************************
 * HByteImage.h
 ***************************************************************************** 
 *
 * Project:     Halcon/C++
 * Description: Types for byte-images
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */


#ifndef H_BYTE_IMAGE_H
#define H_BYTE_IMAGE_H


namespace Halcon {


/****************************************************************************/
/*                             HByteImage                                   */
/****************************************************************************/
class LIntExport HByteImage: public HImage {
public:
  HByteImage(void);
  HByteImage(const char *file);
  HByteImage(const HImage &image);
  HByteImage(const HInt1Image &image);
  HByteImage(const HInt2Image &image);
  HByteImage(const HUInt2Image &image);
  HByteImage(const HInt4Image &image);
  HByteImage(const HFloatImage &image);
  HByteImage(const HComplexImage &image);
  HByteImage(const HByteImage &image);
  HByteImage(int width, int height);
  HByteImage(HByte *ptr, int width, int height);
  HByteImage(HByte *loc_ptr, void* loc_ptrfreecall, int loc_width, int loc_height);
  virtual ~HByteImage(void);
  
  // Tools
  const char *ClassName(void) const {return "HByteImage";}
  const char *InstClassName(void) const {return "HByteImage";}
  const char *PixType(void) const {return "byte";}

  // Pixel Access [k]
  HByte &operator[] (Hlong k);
  HByte  operator[] (Hlong k) const;
    // Pixel Access (k)
  HByte &operator() (Hlong k)
  {if (!privat) Private();return ((HByte*)ptr)[k];}
  HByte  operator() (Hlong k) const
  {if (!init) ((HByteImage*)this)->Init();return ((HByte*)ptr)[k];}
  // Pixel Access (x,y)
  HByte &operator()(int x, int y) 
  {if (!privat) Private();
   return ((HByte*)ptr)[HLinearCoord(x,y,width)];}
  HByte  operator()(int x, int y) const
  {if (!init) ((HByteImage*)this)->Init(); 
   return ((HByte*)ptr)[HLinearCoord(x,y,width)];}
  // Pixel Access SetPixVal
  void SetPixVal(Hlong k, const HPixVal &val);
  void SetPixVal(int x, int y, const HPixVal &val);

  // Infix Operations
  HByteImage operator & (const HRegion &reg) const;
  HByteImage operator & (int i);
  HByteImage operator << (int i);
  HByteImage operator >> (int i);
  HByteImage operator ~ (void);
  HByteImage operator & (HByteImage &ima);
  HByteImage operator | (HByteImage &ima);
  HByteImage operator ^ (HByteImage &ima);
#ifdef DEV_VERS  
  HByteImage LUTTrans(const HByteLUT &lut) const;
  HRGBImage   LUTTrans(const HRGBLUT &lut) const;
#endif  
};


}


#endif
