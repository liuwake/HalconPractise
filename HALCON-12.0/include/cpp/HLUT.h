/*****************************************************************************
 * HLUT.h
 ***************************************************************************** 
 *
 * Project:     Halcon/C++
 * Description: Dates for table-operations with images
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */


#ifndef LUT_H
#define LUT_H


namespace Halcon {


/****************************************************************************/
/*                            HLUT                                          */
/****************************************************************************/
class LIntExport HLUT: public HRootObject {
public:
  virtual const char * ClassName(void) const = 0;
  virtual ~HLUT(void);
  
  virtual Hlong   Num(void) const = 0;
  virtual int    Channels(void) const = 0;
  virtual HByte   Grey(Hlong index) const = 0;
  virtual HByte   Red(Hlong index) const = 0;
  virtual HByte   Green(Hlong index) const = 0;
  virtual HByte   Blue(Hlong index) const = 0;
  virtual HByte & Red(Hlong index) = 0;
  virtual HByte & Green(Hlong index) = 0;
  virtual HByte & Blue(Hlong index) = 0;
  virtual void   Display(const HWindow &w) const = 0;
};



enum HByteLutType { 
  MinMaxLut, SelectLut, SqrtLut, SqrLut, LogLut, ExpLut, MxBLut, 
  LinHistoLut, MaxScaleLut
};



/****************************************************************************/
/*                            HByteLUT                                      */
/****************************************************************************/
class LIntExport HByteLUT: public HLUT {
public:
  HByteLUT(void);
  HByteLUT(const char *file);
  HByteLUT(const HByte *values);
  HByteLUT(const int *values);
  HByteLUT(const HByteImage &image, int lut_type);
  HByteLUT(const HByteHistogram &histo, int lut_type);
  HByteLUT(double gamma);
  HByteLUT(int grey_values);
  HByteLUT(double c1, double c2, int lut_type);
  HByteLUT(const HRGBLUT &rgb_lut);
  HByteLUT(const HByteLUT &Lut);
  ~HByteLUT(void);
  HByteLUT &operator = (const HByteLUT &lut);
  
  void Apply(const HByteLUT &lut);
  
  HByte   operator [] (Hlong index) const;
  HByte & operator [] (Hlong index);
  HByte   Grey(Hlong index) const;
  HByte   Red(Hlong index) const;
  HByte   Green(Hlong index) const;
  HByte   Blue(Hlong index) const;
  HByte & Red(Hlong index);
  HByte & Green(Hlong index);
  HByte & Blue(Hlong index);
  const char * ClassName(void) const;
  Hlong   Num(void) const;
  int    Channels(void) const;
  void   Display(const HWindow &w) const;
private:
   HByte  lut[255];
  
  void  CreateLut(double c1, double c2, int lut_type);
  void  CreateLut(double m, double b);
};


/****************************************************************************/
/*                            HRGBLUT                                       */
/****************************************************************************/
class LIntExport HRGBLUT: public HLUT {
public:
  HRGBLUT(void);
  HRGBLUT(const char *file);
  HRGBLUT(const HByte *Red, const HByte *Green, const HByte *Blue);
  HRGBLUT(const int *Red, const int *Green, const int *Blue);
  HRGBLUT(const HByteLUT &Red, const HByteLUT &Green, const HByteLUT &Blue);
  HRGBLUT(const HRGBLUT &lut);
  HRGBLUT & operator = (const HRGBLUT &lut);
  
  HByte    Grey(Hlong index) const;
  HByte    Red(Hlong index) const;
  HByte  & Red(Hlong index);
  HByte    Green(Hlong index) const;
  HByte  & Green(Hlong index);
  HByte    Blue(Hlong index) const;
  HByte  & Blue(Hlong index);
  HByteLUT Red(void) const;
  HByteLUT Green(void) const;
  HByteLUT Blue(void) const;
  
  
  const char  * ClassName(void) const;
  Hlong    Num(void) const;
  int     Channels(void) const;
  void    Display(const HWindow &w) const;
private:
  HByte  red[255];
  HByte  green[255];
  HByte  blue[255];
};


}


#endif
