/*****************************************************************************
 * HPixVal.h
 ***************************************************************************** 
 *
 * Project:     Halcon/C++
 * Description: Pixeltypes for Halcon-images
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */


#ifndef H_PIX_VAL_H
#define H_PIX_VAL_H


namespace Halcon {


/****************************************************************************/
/*                               HBasePixVal                                */
/****************************************************************************/
class LIntExport HBasePixVal: public HRootObject  {
public:
  virtual operator HByte(void) const = 0;
  virtual const char *ClassName(void) const = 0;
};



/****************************************************************************/
/*                               HAbstractPixVal                            */
/****************************************************************************/
class LIntExport HAbstractPixVal: public HBasePixVal  {
public:
  virtual operator HByte(void) const = 0;
  virtual operator int(void) const = 0;
#if !defined(_TMS320C6X)
  virtual operator Hlong(void) const = 0;
#endif
//  virtual operator float(void) const = 0;
  virtual operator double(void) const = 0;
  virtual operator HComplex(void) const = 0;
  virtual const char *ClassName(void) const = 0;
  virtual HAbstractPixVal *Copy(void) const = 0;
  virtual void Delete(void) = 0;
};



/****************************************************************************/
/*                               HIntegerPixVal                             */
/****************************************************************************/
class LIntExport HIntegerPixVal: public HAbstractPixVal {
public:
  HIntegerPixVal(void): val (0) {}
  HIntegerPixVal(HByte Val): val(Val) {}
  HIntegerPixVal(int Val): val(Val) {}
#if !defined(_TMS320C6X)
  HIntegerPixVal(Hlong Val): val(Val) {}
#endif
  HIntegerPixVal(double Val): val((Hlong)Val) {}
  HIntegerPixVal(HComplex Val): val((Hlong)Val) {}
  HIntegerPixVal &operator = (const HIntegerPixVal &grey)
  { val = grey.val; return *this; }
  ~HIntegerPixVal(void) { Delete(); }

  virtual operator HByte(void) const;
  virtual operator int(void) const;
#if !defined(_TMS320C6X)
  virtual operator Hlong(void) const;
#endif
//  virtual operator float(void) const  { return (float)val; }
  virtual operator double(void) const;
  virtual operator HComplex(void) const;
  virtual void ToByte(void);
  virtual void ToInt1(void);
  virtual void ToInt2(void);
  virtual void ToUInt2(void);
  virtual const char *ClassName(void) const;
  virtual HAbstractPixVal *Copy(void) const;
  virtual void Delete(void);
private:
  Hlong  val;  
};




/****************************************************************************/
/*                               HByteVal                                   */
/****************************************************************************/
class LIntExport HBytePixVal: public HIntegerPixVal {
public:
  HBytePixVal(void): HIntegerPixVal(0) {}
  HBytePixVal(HByte Val): HIntegerPixVal(Val) {}
  HBytePixVal(int Val): HIntegerPixVal(HClipByte(Val)) {}
#if !defined(_TMS320C6X)
  HBytePixVal(Hlong Val): HIntegerPixVal(HClipByte(Val)) {}
#endif
//  HBytePixVal(float Val): HIntegerPixVal(HClipByte(Val)) {}
  HBytePixVal(double Val): HIntegerPixVal(HClipByte(Val)) {}
  HBytePixVal(HComplex Val): HIntegerPixVal(HClipByte((Hlong)Val)) {}
  
  const char *ClassName(void) const { return "HByteVal"; }
};



/****************************************************************************/
/*                               HInt1Val                                   */
/****************************************************************************/
class LIntExport HInt1PixVal: public HIntegerPixVal {
public:
  HInt1PixVal(void): HIntegerPixVal(0) {}
  HInt1PixVal(int Val): HIntegerPixVal(HClipInt1(Val)) {}
#if !defined(_TMS320C6X)
  HInt1PixVal(Hlong Val): HIntegerPixVal(HClipInt1(Val)) {}
#endif
//  HInt1PixVal(float Val): HIntegerPixVal(HClipInt1((Hlong)Val)) {}
  HInt1PixVal(double Val): HIntegerPixVal(HClipInt1((Hlong)Val)) {}
  HInt1PixVal(HComplex Val): HIntegerPixVal(HClipInt1((Hlong)Val)) {}
  
  const char *ClassName(void) const { return "HInt1Val"; }
};



/****************************************************************************/
/*                               HInt2Val                                   */
/****************************************************************************/
class LIntExport HInt2PixVal: public HIntegerPixVal  {
public:
  HInt2PixVal(void): HIntegerPixVal(0) {}
  HInt2PixVal(int Val): HIntegerPixVal(HClipInt2((Hlong)Val)) {}
#if !defined(_TMS320C6X)
  HInt2PixVal(Hlong Val): HIntegerPixVal(HClipInt2((Hlong)Val)) {}
#endif
//  HInt2PixVal(float Val): HIntegerPixVal(HClipInt2((Hlong)Val)) {}
  HInt2PixVal(double Val): HIntegerPixVal(HClipInt2(Val)) {}
  HInt2PixVal(HComplex Val): HIntegerPixVal(HClipInt2((Hlong)Val)) {}
  
  const char *ClassName(void) const { return "HInt2Val"; }
};


/****************************************************************************/
/*                               HUInt2Val                                  */
/****************************************************************************/
class LIntExport HUInt2PixVal: public HIntegerPixVal  {
public:
  HUInt2PixVal(void): HIntegerPixVal(0) {}
  HUInt2PixVal(int Val): HIntegerPixVal(HClipUInt2((Hlong)Val)) {}
#if !defined(_TMS320C6X)
  HUInt2PixVal(Hlong Val): HIntegerPixVal(HClipUInt2((Hlong)Val)) {}
#endif
//  HUInt2PixVal(float Val): HIntegerPixVal(HClipUInt2((Hlong)Val)) {}
  HUInt2PixVal(double Val): HIntegerPixVal(HClipUInt2(Val)) {}
  HUInt2PixVal(HComplex Val): HIntegerPixVal(HClipUInt2((Hlong)Val)) {}
  
  const char *ClassName(void) const { return "HUInt2Val"; }
};



/****************************************************************************/
/*                               HInt4Val                                   */
/****************************************************************************/
class LIntExport HInt4PixVal: public HIntegerPixVal  {
public:
  HInt4PixVal(void): HIntegerPixVal(0) {}
#if !defined(_TMS320C6X)
  HInt4PixVal(Hlong Val): HIntegerPixVal(Val) {}
#endif
  HInt4PixVal(int Val): HIntegerPixVal(Val) {}
//  HInt4PixVal(float Val): HIntegerPixVal(Val) {}
  HInt4PixVal(double Val): HIntegerPixVal(Val) {}
  HInt4PixVal(HComplex Val): HIntegerPixVal((Hlong)Val) {}
  
  const char *ClassName(void) const { return "HInt4Val"; }
};



/****************************************************************************/
/*                               HFloatPixVal                               */
/****************************************************************************/
class LIntExport HFloatPixVal: public HAbstractPixVal  {
public:
  HFloatPixVal(void): val(0.0) {}
  HFloatPixVal(int Val): val(Val) {}
//  HFloatPixVal(float Val): val(Val) {}
  HFloatPixVal(double Val): val(Val) {}
  HFloatPixVal(HComplex Val): val(Val) {}
  ~HFloatPixVal(void) { Delete(); }
  
  operator HByte(void) const { return (HByte)val; }
  operator int(void) const { return (int)val; }
#if !defined(_TMS320C6X)
  operator Hlong(void) const { return (Hlong)val; }
#endif
//  operator float(void) const { return (float)val; }
  operator double(void) const { return val; }
  operator HComplex(void) const { return HComplex(val); }
  const char *ClassName(void) const { return "HFloatPixVal"; }
  HAbstractPixVal *Copy(void) const;
  void Delete(void);
private:
  double  val;  
};



/****************************************************************************/
/*                               HComplexVal                                */
/****************************************************************************/
class LIntExport HComplexPixVal: public HAbstractPixVal  {
public:
  HComplexPixVal(void): val(0.0) {}
  HComplexPixVal(HByte Val): val(Val) {}
  HComplexPixVal(int Val): val(Val) {}
//  HComplexPixVal(float Val): val(Val) {}
  HComplexPixVal(double Val): val(Val) {}
  HComplexPixVal(HComplex Val): val(Val) {}
  ~HComplexPixVal(void) { Delete(); }
  
  operator HByte(void) const { return (HByte)val; }
  operator int(void) const { return (int)val; }
#if !defined(_TMS320C6X)
  operator Hlong(void) const { return (Hlong)val; }
#endif
 // operator float(void) const { return (float)val; }
  operator double(void) const { return (double)val; }
  operator HComplex(void) const { return val; }

  const char *ClassName(void) const { return "HComplexPixVal"; }
  HAbstractPixVal *Copy(void) const
  { 
    HComplexPixVal *tmp= 0;
    HCkNew(tmp = new HComplexPixVal((HComplex)val)); 
    return tmp; 
  }
  void Delete(void) { val = 0.0; }
private:
   HComplex  val;
};




/****************************************************************************/
/*                               HPixVal                                    */
/****************************************************************************/
class LIntExport HPixVal: public HBasePixVal  {
public:
  HPixVal(void) { HCkNew(val = new HBytePixVal(0)); }
  HPixVal(const HComplex &Val) { HCkNew(val = new HComplexPixVal((HComplex)Val)); }
  HPixVal(int Val) { HCkNew(val = new HInt4PixVal(Val)); }
#if !defined(_TMS320C6X)
  HPixVal(Hlong Val) { HCkNew(val = new HInt4PixVal(Val)); }
#endif
  HPixVal(HByte Val) { HCkNew(val = new HBytePixVal(Val)); }
//  HPixVal(float Val) { val = new HFloatPixVal(Val); }
  HPixVal(double Val) { HCkNew(val = new HFloatPixVal(Val)); }
  HPixVal(const HPixVal &Val):HBasePixVal() { HCkNew(val = Val.val->Copy()); }
  virtual ~HPixVal(void) { Delete(); };
  // HPixVal(void *ptr, int type);
  HPixVal &operator = (const HPixVal &grey)
  { Delete(); val = grey.val->Copy(); return *this; }
  
  operator HByte(void) const { return (HByte)(*val); }
  operator int(void) const { return (int)(*val); }
#if !defined(_TMS320C6X)
  operator Hlong(void) const { return (Hlong)(*val); }
#endif
//  operator float(void) const { return (float)(*val); }
  operator double(void) const { return (double)(*val); }
  operator HComplex(void) const { return (HComplex)(double)(*val); }

  void ToByte(void);
  void ToInt1(void);
  void ToInt2(void);
  void ToUInt2(void);
  void ToInt4(void);
  void ToComplexD(void);
  void ToFloat(void);

  HPixVal & operator ++ (void);
  HPixVal   operator + (const HPixVal &pix) const;
  HPixVal & operator -- (void);
  HPixVal   operator - (const HPixVal &pix) const;
  HPixVal   operator * (const HPixVal &pix) const;
  HPixVal   operator / (const HPixVal &pix) const;

  const char *ClassName(void) const { return "HPixVal"; }
  void Delete(void) { delete val; }
private:
   HAbstractPixVal   *val;
};


}


#endif
