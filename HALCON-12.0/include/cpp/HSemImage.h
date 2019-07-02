/*****************************************************************************
 * HSemImage.h
 ***************************************************************************** 
 *
 * Project:     Halcon/C++
 * Description: Types for semantic images
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */


#ifndef S_IMAGE_H
#define S_IMAGE_H


namespace Halcon {


/****************************************************************************/
/*                               HSemAbstractPixVal                         */
/****************************************************************************/
class LIntExport HSemAbstractPixVal: public HBasePixVal {
public:
  virtual operator HByte(void) const = 0;
  virtual operator int(void) const = 0;
  virtual operator Hlong(void) const = 0;
  virtual operator double(void) const = 0;
  virtual operator HPixVal(void) const = 0;
  virtual int      Num(void) const = 0;
  virtual HPixVal  GetPixVal(int index) const = 0;
  virtual HSemAbstractPixVal *Copy(void) const = 0;
  virtual const char *ClassName(void) const = 0;
};



/****************************************************************************/
/*                               HSemPixVal                                 */
/****************************************************************************/
class LIntExport HSemPixVal: public HBasePixVal {
public:
  HSemPixVal(void);
  HSemPixVal(HSemAbstractPixVal *Val);
  HSemPixVal(const HSemAbstractPixVal &Val);
  
  operator HByte(void) const;
  operator int(void) const;
  operator Hlong(void) const;
  operator double(void) const;
  operator HPixVal(void) const;
  int      Num(void) const;
  HPixVal  GetPixVal(int index) const;
  const char *ClassName(void) const;
private:
  HSemAbstractPixVal  *val;
};


/****************************************************************************/
/*                               HLUTVal                                    */
/****************************************************************************/
class LIntExport HLUTPixVal: public HSemAbstractPixVal {
public:
  HLUTVal(void);
  HLUTVal(HByte val);
  
  operator HByte(void) const;
  operator int(void) const;
  operator Hlong(void) const;
  operator double(void) const;
  operator HComplex(void) const;
  const char *ClassName(void) const {return "HLUTPixVal";}
  HSemAbstractPixVal *Copy(void) const;
  void Delete(void);
private:
   HByte  val;
};




/****************************************************************************/
/*                               HColorPixVal                               */
/****************************************************************************/
class LIntExport HColorPixVal: public HSemAbstractPixVal  {
public:
  virtual HPixVal Red(void) const = 0;
  virtual HPixVal Green(void) const = 0;
  virtual HPixVal Blue(void) const = 0;
  
  virtual operator HByte(void) const = 0;
  virtual operator int(void) const = 0;
  virtual operator Hlong(void) const = 0;
  virtual operator double(void) const = 0;
  virtual operator HPixVal(void) const = 0;
  virtual int      Num(void) const = 0;
  virtual HPixVal  GetPixVal(int index) const = 0;
  virtual HSemAbstractPixVal *Copy(void) const = 0;
  virtual const char *ClassName(void) const = 0;
};


/****************************************************************************/
/*                               HRGBPixVal                                 */
/****************************************************************************/
class LIntExport HRGBPixVal: public HColorPixVal  {
public:
  HRGBPixVal(void): red(0), green(0), blue(0) {}
  HRGBPixVal(HPixVal red, HPixVal green, HPixVal blue):
    red(red), green(green), blue(blue) {}
  HPixVal Red(void) const {return red;}
  HPixVal Green(void) const {return green;}
  HPixVal Blue(void) const {return blue;}
  
  operator int(void) const;
  operator HByte(void) const;
  operator Hlong(void) const;
  operator double(void) const;
  operator HPixVal(void) const;
  int      Num(void) const {return 3;}
  HPixVal  GetPixVal(int index) const;
  const char    *ClassName(void) const {return "HRGBPixVal";}
  HSemAbstractPixVal *Copy(void) const;
private:
  HPixVal  red, green, blue;
};


/****************************************************************************/
/*                               HCIELabPixVal                              */
/****************************************************************************/
class LIntExport HCIELabPixVal: public HColorPixVal  {
public:
  HCIELabPixVal(void);
  HCIELabPixVal(HPixVal c, HPixVal i, HPixVal e);
  HPixVal Red(void) const;
  HPixVal Green(void) const;
  HPixVal Blue(void) const;
  HPixVal C(void) const {return c;}
  HPixVal I(void) const {return i;}
  HPixVal E(void) const {return e;}
  
  operator int(void) const;
  operator HByte(void) const;
  operator Hlong(void) const;
  operator double(void) const;
  operator HPixVal(void) const;
  int      Num(void) const;
  HPixVal  GetPixVal(int index) const;
  const char    *ClassName(void) const {return "HCIELabPixVal";}
  HSemAbstractPixVal *Copy(void) const;
private:
  HPixVal  c,i,e;
};


/****************************************************************************/
/*                               HHSIPixVal                                 */
/****************************************************************************/
class LIntExport HHSIPixVal: public HColorPixVal {
public:
  HHSIPixVal(void);
  HHSIPixVal(HPixVal h, HPixVal s, HPixVal i);
  HPixVal Red(void) const;
  HPixVal Green(void) const;
  HPixVal Blue(void) const;
  HPixVal H(void) const {return h;}
  HPixVal S(void) const {return s;}
  HPixVal I(void) const {return i;}
  
  operator int(void) const;
  operator Hlong(void) const;
  operator HByte(void) const;
  operator double(void) const;
  operator HPixVal(void) const;
  int      Num(void) const;
  HPixVal  GetPixVal(int index) const;
  const char    *ClassName(void) const {return "HHSIPixVal";}
  HSemAbstractPixVal *Copy(void) const;
private:
  HPixVal  h,s,i;
};


/****************************************************************************/
/*                               HHSVPixVal                                 */
/****************************************************************************/
class LIntExport HHSVPixVal: public HColorPixVal  {
public:
  HHSVPixVal(void);
  HHSVPixVal(HPixVal h, HPixVal s, HPixVal v);
  HPixVal Red(void) const;
  HPixVal Green(void) const;
  HPixVal Blue(void) const;
  HPixVal H(void) const {return h;}
  HPixVal S(void) const {return s;}
  HPixVal V(void) const {return v;}
  
  operator int(void) const;
  operator Hlong(void) const;
  operator HByte(void) const;
  operator double(void) const;
  operator HPixVal(void) const;
  int      Num(void) const;
  HPixVal  GetPixVal(int index) const;
  const char    *ClassName(void) const {return "HHSVPixVal";}
  HSemAbstractPixVal *Copy(void) const;
private:
  HPixVal  h,s,v;
};




/****************************************************************************/
/*                               HEdgePixVal                                */
/****************************************************************************/
class LIntExport HEdgePixVal: public HSemAbstractPixVal  {
public:
  HEdgePixVal(void): amp(0), dir(0) {}
  HEdgePixVal(HPixVal amp, HPixVal dir): amp(amp), dir(dir) {}

  operator int(void) const;
  operator Hlong(void) const;
  operator double(void) const;
  operator HPixVal(void) const;
  operator HAngleDeg(void) const;
  operator HAngleRad(void) const;
  HAngleDeg DirGrd(void) const;
  HAngleRad DirRad(void) const;
  HPixVal Amp(void) const;
  
  int      Num(void) const {return 2;}
  HPixVal  GetPixVal(int index) const {return HPixVal(0);}
  const char *ClassName(void) const {return "HEdgePixVal";}
  HSemAbstractPixVal *Copy(void) const;
private:
  HPixVal  amp, dir;
};



/****************************************************************************/
/*                               HDVFPixVal                                 */
/****************************************************************************/
class LIntExport HDVFPixVal: public HSemAbstractPixVal  {
public:
  HDVFPixVal(void);
  HDVFPixVal(HPixVal x, HPixVal y);
  HPixVal X(void) const {return x;}
  HPixVal Y(void) const {return y;}
  
  operator int(void) const;
  operator HByte(void) const;
  operator Hlong(void) const;
  operator double(void) const;
  operator HPixVal(void) const;
  HAngleDeg DirGrd(void) const;
  HAngleRad DirRad(void) const;
  double   Length(void) const;
  
  int      Num(void) const;
  HPixVal  GetPixVal(int index) const;
  const char *ClassName(void) const {return "HDVFPixVal";}
  HSemAbstractPixVal *Copy(void) const;
private:
  HPixVal  x, y;
};


/****************************************************************************/
/*                               HSemSimplePixVal                           */
/****************************************************************************/
class LIntExport HSemSimplePixVal: public HSemAbstractPixVal  {
public:
  HSemSimplePixVal(void): val(0) {}
  HSemSimplePixVal(HPixVal val): val(val) {}
  HSemSimplePixVal &operator = (const HSemSimplePixVal &Val)
  { val = Val.val; return *this;}
  virtual ~HSemSimplePixVal(void);

  virtual operator HByte(void) const;
  virtual operator int(void) const;
  virtual operator Hlong(void) const;
  virtual operator double(void) const;
  virtual operator HPixVal(void) const;
  virtual const char *ClassName(void) const;
  
  int      Num(void) const {return 1;}
  HPixVal  GetPixVal(int index) const 
    {if (index != 1) H_EXCEPTION("HPixVal GetPixVal(int index) const","index != 1");
     return val;}
  HSemAbstractPixVal *Copy(void) const;
protected:
  HPixVal  val;
};

/****************************************************************************/
/*                               HCoocMatrixPixVal                          */
/****************************************************************************/
class LIntExport HCoocMatrixPixVal: public HSemSimplePixVal  {
public:
  HCoocMatrixPixVal(void): HSemSimplePixVal() {}
  HCoocMatrixPixVal(HPixVal val): HSemSimplePixVal(val) {}

  const char *ClassName(void) const {return "HCoocMatrixPixVal";}
};


/****************************************************************************/
/*                               HDepthPixVal                               */
/****************************************************************************/
class LIntExport HDepthPixVal: public HSemSimplePixVal  {
public:
  HDepthPixVal(void): HSemSimplePixVal(0) {}
  HDepthPixVal(HPixVal val): HSemSimplePixVal(val) {}
  
  const char *ClassName(void) const {return "CoocPixVal";}
};


/****************************************************************************/
/*                               HEdgeAmpPixVal                             */
/****************************************************************************/
class LIntExport HEdgeAmpPixVal: public HSemSimplePixVal  {
public:
  HEdgeAmpPixVal(void): HSemSimplePixVal(0) {}
  HEdgeAmpPixVal(HPixVal val): HSemSimplePixVal(val) {}

  HPixVal Amp(void) const;
  const char *ClassName(void) const {return "HEdgeAmpPixVal";}
};


/****************************************************************************/
/*                               HEdgeDirPixVal                             */
/****************************************************************************/
class LIntExport HEdgeDirPixVal: public HSemSimplePixVal  {
public:
  HEdgeDirPixVal(void): HSemSimplePixVal(0) {}
  HEdgeDirPixVal(HPixVal val): HSemSimplePixVal(val) {}
  
  operator HAngleDeg(void) const;
  operator HAngleRad(void) const;
  HAngleDeg DirGrd(void) const;
  HAngleRad DirRad(void) const;
  
  const char *ClassName(void) const {return "HEdgeDirPixVal";}
};



/****************************************************************************/
/*                               HFFTPixVal                                 */
/****************************************************************************/
class LIntExport HFFTPixVal: public HSemSimplePixVal  {
public:
  HFFTPixVal(void): HSemSimplePixVal(0) {}
  HFFTPixVal(HPixVal val): HSemSimplePixVal(val) {}
  
  operator HComplex(void) const{return HComplex(val);}
  const char *ClassName(void) const {return "HFFTPixVal";}
};



/****************************************************************************/
/*                               HGreyPixVal                                */
/****************************************************************************/
class LIntExport HGreyPixVal: public HSemSimplePixVal  {
public:
  HGreyPixVal(void): HSemSimplePixVal(0) {}
  HGreyPixVal(HPixVal val): HSemSimplePixVal(val) {}
  
  operator HByte(void) const {return HClipByte((Hlong)val);}
  operator int(void) const {return (int)val;}
  const char *ClassName(void) const {return "HGreyPixVal";}
};



/****************************************************************************/
/*                               HHist2DimPixVal                            */
/****************************************************************************/
class LIntExport HHist2DimPixVal: public HSemSimplePixVal  {
public:
  HHist2DimPixVal(void): HSemSimplePixVal(0) {}
  HHist2DimPixVal(HPixVal val): HSemSimplePixVal(val) {}
  
  operator Hlong(void) const {return (Hlong)val;}
  const char *ClassName(void) const {return "HHist2DimPixVal";}
};


/****************************************************************************/
/*                               HLabelPixVal                               */
/****************************************************************************/
class LIntExport HLabelPixVal: public HSemSimplePixVal  {
public:
  HLabelPixVal(void): HSemSimplePixVal(0) {}
  HLabelPixVal(HPixVal val): HSemSimplePixVal(val) {}
  
  operator Hlong(void) const {return (Hlong)val;}
  const char *ClassName(void) const {return "HLabelPixVal";}
};


/****************************************************************************/
/*                              HLaplacePixVal                              */
/****************************************************************************/
class LIntExport HLaplacePixVal: public HSemSimplePixVal  {
public:
  HLaplacePixVal(void): HSemSimplePixVal(0) {}
  HLaplacePixVal(HPixVal val): HSemSimplePixVal(val) {}
  
  operator Hlong(void) const {return (Hlong)val;}
  const char *ClassName(void) const {return "HLaplacePixVal";}
};


/****************************************************************************/
/*                              HStrElGreyPixVal                            */
/****************************************************************************/
class LIntExport HStrElGreyPixVal: public HSemSimplePixVal  {
public:
  HStrElGreyPixVal(void): HSemSimplePixVal(0) {}
  HStrElGreyPixVal(HPixVal val): HSemSimplePixVal(val) {}
  
  operator HByte(void) const {return (HByte)val;}
  const char *ClassName(void) const {return "HStrElGreyPixVal";}
};






/****************************************************************************/
/*                               HSemAbstractImage                            */
/****************************************************************************/
class LIntExport HSemAbstractImage: public HBaseImage {
public:
  HSemAbstractImage(void);
  virtual ~HSemAbstractImage(void);

  // Pixel Access
  virtual HSemPixVal GetPixVal(int x, int y) = 0;
  virtual HSemPixVal GetPixVal(Hlong k) = 0;
  virtual void     SetPixVal(int x, int y, const HSemPixVal &val) = 0;
  virtual void     SetPixVal(Hlong k, const HSemPixVal &val) = 0;
 
  virtual const char    *ClassName(void) const = 0;
  virtual int      Width(void) const = 0;
  virtual int      Height(void) const = 0;
  virtual void     Transform(const HAffineTrans &transform, int mode) = 0;
  virtual void     Display(const HWindow &w) const = 0;
  virtual HSemAbstractImage *CopyAbstractSImage(void) const = 0;
};




/****************************************************************************/
/*                               HSemImage                                    */
/****************************************************************************/
class LIntExport HSemImage: public HBaseImage {
public:
  HSemImage(void);
  HSemImage(const HSemImage &r);
  ~HSemImage(void);
  HSemImage &operator = (const HSemImage &arr);
  
  
  // Tools
  int     NumChannels(void) {return 1;}
  HSemImage  GetChannel(int index) 
    { if (index > 0) H_EXCEPTION("HSemImage  GetChannel(int index)","index > 0");
      return *this;}
  
  // Pixel Access
  HSemPixVal  GetPixVal(int x, int y);
  HSemPixVal  GetPixVal(Hlong k);
  void     SetPixVal(int x, int y, const HSemPixVal &val);
  void     SetPixVal(Hlong k, const HSemPixVal &val);
 
  const char    *ClassName(void) const;
  int      Width(void) const;
  int      Height(void) const;  
  void     Transform(const HAffineTrans &transform, int mode);
  void     Display(const HWindow &w) const;
  
  // Class Operations
protected:
   HSemAbstractImage  *image;
};


/****************************************************************************/
/*                               HStrElGrey                                 */
/****************************************************************************/
class LIntExport HStrElGrey: public HSemAbstractImage {
public:
   HSemAbstractImage* CopyAbstractSImage(void) const;
  void Display(const HWindow &w) const {}
  HSemPixVal GetPixVal(int x, int y);
  HSemPixVal GetPixVal(Hlong k);
  void SetPixVal(int x, int y, const HSemPixVal &val) {}
  void SetPixVal(Hlong k, const HSemPixVal &val) {}
  void Transform(const HAffineTrans &transform, int mode);
  const char* ClassName(void) const {return "HStrElGrey";}
  int Width(void) const {return image.Width();}
  int Height(void) const {return image.Height();}
private:
  HImage  image;
};


/****************************************************************************/
/*                               HGreyImage                                 */
/****************************************************************************/
class LIntExport HGreyImage: public HSemAbstractImage {
public:
  HSemAbstractImage* CopyAbstractSImage(void) const;
  void Display(const HWindow &w) const;
  HSemPixVal GetPixVal(int x, int y);
  HSemPixVal GetPixVal(Hlong k);
  void SetPixVal(int x, int y, const HSemPixVal &val);
  void SetPixVal(Hlong k, const HSemPixVal &val);
  void Transform(const HAffineTrans &transform, int mode);
  const char* ClassName(void) const {return "HGreyImage";}
  int Width(void) const {return image.Width();}
  int Height(void) const {return image.Height();}
private:
  HImage  image;
};


/****************************************************************************/
/*                               HDVFImage                                  */
/****************************************************************************/
class LIntExport HDVFImage: public HSemAbstractImage {
public:
  HSemAbstractImage* CopyAbstractSImage(void) const;
  void Display(const HWindow &w) const;
  HSemPixVal GetPixVal(int x, int y);
  HSemPixVal GetPixVal(Hlong k);
  void SetPixVal(int x, int y, const HSemPixVal &val);
  void SetPixVal(Hlong k, const HSemPixVal &val);
  void Transform(const HAffineTrans &transform, int mode);
  const char* ClassName(void) const {return "HDVFImage";}
  int Width(void) const {return image_x.Width();}
  int Height(void) const {return image_x.Height();}
private:
  HImage  image_x;
  HImage  image_y;
};



/****************************************************************************/
/*                               HEdgeDirImage                              */
/****************************************************************************/
class LIntExport HEdgeDirImage: public HSemAbstractImage {
public:
  HSemAbstractImage* CopyAbstractSImage(void) const;
  void Display(const HWindow &w) const;
  HSemPixVal GetPixVal(int x, int y);
  HSemPixVal GetPixVal(Hlong k);
  void SetPixVal(int x, int y, const HSemPixVal &val);
  void SetPixVal(Hlong k, const HSemPixVal &val);
  void Transform(const HAffineTrans &transform, int mode);
  const char* ClassName(void) const {return "HEdgeDirImage";}
  int Width(void) const {return image_dir.Width();}
  int Height(void) const {return image_dir.Height();}
protected:
  HImage  image_dir;  
};

/****************************************************************************/
/*                               HEdgeAmpImage                              */
/****************************************************************************/
class LIntExport HEdgeAmpImage: public HSemAbstractImage {
public:
  HSemAbstractImage* CopyAbstractSImage(void) const;
  void Display(const HWindow &w) const;
  HSemPixVal GetPixVal(int x, int y);
  HSemPixVal GetPixVal(Hlong k);
  void SetPixVal(int x, int y, const HSemPixVal &val);
  void SetPixVal(Hlong k, const HSemPixVal &val);
  void Transform(const HAffineTrans &transform, int mode);
  const char* ClassName(void) const {return "HEdgeAmpImage";}
  int Width(void) const {return image_amp.Width();}
  int Height(void) const {return image_amp.Height();}
protected:
  HImage  image_amp;
};


/****************************************************************************/
/*                               HEdgeImage                                 */
/****************************************************************************/
class LIntExport HEdgeImage: public HEdgeAmpImage, public HEdgeDirImage {
};


/****************************************************************************/
/*                               HLaplaceImage                              */
/****************************************************************************/
class LIntExport HLaplaceImage: public HSemAbstractImage {
public:
  HSemAbstractImage* CopyAbstractSImage(void) const;
  void Display(const HWindow &w) const;
  HSemPixVal GetPixVal(int x, int y);
  HSemPixVal GetPixVal(Hlong k);
  void SetPixVal(int x, int y, const HSemPixVal &val) {}
  void SetPixVal(Hlong k, const HSemPixVal &val) {}
  void Transform(const HAffineTrans &transform, int mode);
  const char* ClassName(void) const {return "HLaplaceImage";}
  int Width(void) const {return image.Width();}
  int Height(void) const {return image.Height();}
private:
  HImage  image;
};


/****************************************************************************/
/*                               HHisto2Dim                                 */
/****************************************************************************/
class LIntExport HHisto2Dim: public HSemAbstractImage {
public:
  HSemAbstractImage* CopyAbstractSImage(void) const;
  void Display(const HWindow &w) const;
  HSemPixVal GetPixVal(int x, int y);
  HSemPixVal GetPixVal(Hlong k);
  void SetPixVal(int x, int y, const HSemPixVal &val) {}
  void SetPixVal(Hlong k, const HSemPixVal &val) {}
  void Transform(const HAffineTrans &transform, int mode);
  const char* ClassName(void) const {return "HHisto2Dim";}
  int Width(void) const {return image.Width();}
  int Height(void) const {return image.Height();}
private:
  HImage  image;
};


/****************************************************************************/
/*                               HFourierImage                              */
/****************************************************************************/
class LIntExport HFourierImage: public HSemAbstractImage {
public:
  HSemAbstractImage* CopyAbstractSImage(void) const;
  void Display(const HWindow &w) const {}
  HSemPixVal GetPixVal(int x, int y);
  HSemPixVal GetPixVal(Hlong k);
  void SetPixVal(int x, int y, const HSemPixVal &val);
  void SetPixVal(Hlong k, const HSemPixVal &val);
  void Transform(const HAffineTrans &transform, int mode);
  const char* ClassName(void) const {return "HFourierImage";}
  int Width(void) const {return image.Width();}
  int Height(void) const {return image.Height();}
private:
  HImage  image;
};


/****************************************************************************/
/*                               HDepthImage                                */
/****************************************************************************/
class LIntExport HDepthImage: public HSemAbstractImage {
public:
  HSemAbstractImage* CopyAbstractSImage(void) const;
  void Display(const HWindow &w) const;
  HSemPixVal GetPixVal(int x, int y) {return HSemPixVal(0);}
  HSemPixVal GetPixVal(Hlong k) {return HSemPixVal(0);}
  void SetPixVal(int x, int y, const HSemPixVal &val);
  void SetPixVal(Hlong k, const HSemPixVal &val);
  void Transform(const HAffineTrans &transform, int mode);
  const char* ClassName(void) const {return "HDepthImage";}
  int Width(void) const {return image.Width();}
  int Height(void) const {return image.Height();}
private:
  HImage  image;
};




/****************************************************************************/
/*                               HColourImage                               */
/****************************************************************************/
class LIntExport HColourImage: public HSemAbstractImage {
public:
  virtual HSemAbstractImage* CopyAbstractSImage(void) const = 0;
  virtual void Display(const HWindow &w) const = 0;
  virtual HSemPixVal GetPixVal(int x, int y) = 0;
  virtual HSemPixVal GetPixVal(Hlong k) = 0;
  virtual void SetPixVal(int x, int y, const HSemPixVal &val) = 0;
  virtual void SetPixVal(Hlong k, const HSemPixVal &val) = 0;
  virtual void Transform(const HAffineTrans &transform, int mode) = 0;
  virtual const char* ClassName(void) const = 0;
  virtual int Width(void) const = 0;
  virtual int Height(void) const = 0;
};



/****************************************************************************/
/*                               HRGBImage                                  */
/****************************************************************************/
class LIntExport HRGBImage: public HColourImage {
public:
  HRGBImage(const HByteImage &image);
  HRGBImage(const HRGBImage &image);
  HRGBImage(const HByteImage &image, const HRGBLUT &lut);
  HRGBImage(const HByteImage &red, const HByteImage &green, const HByteImage &blue);

  HSemAbstractImage* CopyAbstractSImage(void) const;
  void       Display(const HWindow &w) const;
  HSemPixVal GetPixVal(int x, int y);
  HSemPixVal GetPixVal(Hlong k);
  void       SetPixVal(int x, int y, const HSemPixVal &val);
  void       SetPixVal(Hlong k, const HSemPixVal &val);
  void       Transform(const HAffineTrans &transform, int mode);
  const char*      ClassName(void) const {return "HRGBImage";}
  HByteImage Red(void) const;
  HByteImage Green(void) const;
  HByteImage Blue(void) const;
  int Width(void) const {return red.Width();}
  int Height(void) const {return red.Height();}
private:
  HByteImage red;
  HByteImage green;
  HByteImage blue;
};






/****************************************************************************/
/*                               HHSIImage                                  */
/****************************************************************************/
class LIntExport HHSIImage: public HColourImage {
};


/****************************************************************************/
/*                               HHSVImage                                  */
/****************************************************************************/
class LIntExport HHSVImage: public HColourImage {
};


/****************************************************************************/
/*                               HCIELabImage                               */
/****************************************************************************/
class LIntExport HCIELabImage: public HColourImage {
};




enum HCoocDirections { Dir0 = 0, Dir45 = 45, Dir90 = 90, Dir135 = 135 };

/****************************************************************************/
/*                               HCoocMatrix                                */
/****************************************************************************/
class LIntExport HCoocMatrix: public HSemAbstractImage {
public:
  HCoocMatrix(void);
  HCoocMatrix(const HRegion &reg, const HByteImage &grey,
             int num_bits = 8, int Direction = Dir0);
  HCoocMatrix(const HByteImage &grey,
             int num_bits = 8, int Direction = Dir0);
  HCoocMatrix(const char *file);
  HCoocMatrix(const HCoocMatrix &cooc);
  ~HCoocMatrix(void);
  HCoocMatrix &operator = (const HCoocMatrix &cooc);

  // Special Operations
  int             Direction(void) const {return direction;}
  int             NumBits(void) const {return bits;}
  Hlong            NumPoints(void) const {return num_points;}
  void            Write(const char *file) const;
  Hlong   operator () (int x, int y) const {return (Hlong)image.GetPixVal(x,y);}

  HSemAbstractImage *CopyAbstractSImage(void) const;
  void            Display(const HWindow &w) const;
  HSemPixVal      GetPixVal(int x, int y);
  HSemPixVal      GetPixVal(Hlong k);
  void            SetPixVal(int x, int y, const HSemPixVal &val);
  void            SetPixVal(Hlong k, const HSemPixVal &val);
  void            Transform(const HAffineTrans &transform, int mode);
  const char     *ClassName(void) const {return "HCoocMatrix";}
  int             Width(void) const {return image.Width();}
  int             Height(void) const {return image.Height();}
private:
  HImage    image;
  int       bits;
  int       direction;
  Hlong     num_points;
};




/****************************************************************************/
/*                               HLabelImage                                */
/****************************************************************************/
class LIntExport HLabelImage: public HSemAbstractImage {
public:
  HLabelImage(void);
  HLabelImage(const HRegion &reg);
  HLabelImage(const HRegionArray &regs);
  HLabelImage(const HLabelImage &Image);
  ~HLabelImage(void);
  HLabelImage &operator = (const HLabelImage &Image);

  HSemAbstractImage *CopyAbstractSImage(void) const;
  void               Display(const HWindow &w) const;

  // Tools
  const char *ClassName(void) const {return "HLabelImage";}
  int         Width(void) const {return image.Width();}
  int         Height(void) const {return image.Height();}

  // Access and Manipulation
  HSemPixVal  GetPixVal(int x, int y);
  HSemPixVal  GetPixVal(Hlong k);
  void        SetPixVal(int x, int y, const HSemPixVal &val);
  void        SetPixVal(Hlong k, const HSemPixVal &val);
  Hlong operator () (int x, int y) {return (Hlong)image.GetPixVal(x,y);}
  Hlong operator [] (Hlong k) {return (Hlong)image.GetPixVal(k);}
  void        Transform(const HAffineTrans &transform, int mode);

private:
  HImage  image;
};


}


#endif
