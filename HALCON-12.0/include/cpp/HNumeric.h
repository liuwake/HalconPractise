/*****************************************************************************
 * HNumeric.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Base types for arithmetic
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */


#ifndef HNUMERIC_H
#define HNUMERIC_H

#include <math.h>

namespace Halcon {


/****************************************************************************/
/*                            HNumeric                                      */
/****************************************************************************/
class LIntExport HNumeric: public HRootObject {
public:
   HNumeric() {};
  ~HNumeric() {};
  virtual const char *ClassName(void) const = 0;
};


#ifdef COORD_IS_CLASS
/****************************************************************************/
/*                            HDCoord                                        */
/****************************************************************************/
class LIntExport HDCoord: public HNumeric {
private:
  short  p;
public:
   HDCoord(int i=0): p(i) {}

  operator int(void)    const { return int(p); }
  operator double(void) const { return double(p); }

  HDCoord operator = (int P) { p = P; return *this; }
  HDCoord operator += (const HDCoord &p1) { p += p1.p; return *this; }
  HDCoord operator -= (const HDCoord &p1) { p -= p1.p; return *this; }
  HDCoord operator += (int i) { p += i; return *this; }
  HDCoord operator -= (int i) { p -= i; return *this; }
  HDCoord operator + (const HDCoord &add) const { return HDCoord(p + add.p); }
  HDCoord operator + (int i) const { return HDCoord(p + i); }
  HDCoord operator - (const HDCoord &sub) const { return HDCoord(p - sub.p); }
  HDCoord operator - (int i) const { return HDCoord(p - i); }
  HDCoord operator - (void) const { return HDCoord(-p); }
  HDCoord operator ++ (void) { ++p; return *this; }
  HDCoord operator -- (void) { --p; return *this; }
  HBool operator == (const HDCoord &c) const { return p == c.p; }
  HBool operator != (const HDCoord &c) const { return p != c.p; }
  HBool operator >= (const HDCoord &c) const { return p >= c.p; }
  HBool operator <= (const HDCoord &c) const { return p <= c.p; }
  HBool operator >  (const HDCoord &c) const { return p > c.p; }
  HBool operator <  (const HDCoord &c) const { return p < c.p; }
 
  const char *ClassName(void) const { return "HDCoord"; }
};

#endif



#ifdef COORD_IS_CLASS
/****************************************************************************/
/*                            HCoord                                        */
/****************************************************************************/
class LIntExport HCoord: public HNumeric {
private:
  float  p;
public:
  HCoord(double i=0.0): p((float)i) {}
  HCoord operator = (double P) { p = (float)P; return *this; }

  operator int(void)    const { return int(p+0.5); }
  operator double(void) const { return p; }
  operator HDCoord(void) const { return HDCoord(int(p+0.5)); }

  HCoord operator += (const HCoord &p1) { p += p1.p; return *this; }
  HCoord operator -= (const HCoord &p1) { p -= p1.p; return *this; }
  HCoord operator += (double i) { p += (float)i; return *this; }
  HCoord operator -= (double i) { p -= (float)i; return *this; }
  HCoord operator + (const HCoord &add) const { return HCoord(p + add.p); }
  HCoord operator + (double i) const { return HCoord(p + i); }
  HCoord operator - (const HCoord &sub) const { return HCoord(p - sub.p); }
  HCoord operator - (double i) const { return HCoord(p - i); }
  HCoord operator - (void) const { return HCoord(-p); }
  HBool operator == (const HCoord &c) const { return p == c.p; }
  HBool operator != (const HCoord &c) const { return p != c.p; }
  HBool operator >= (const HCoord &c) const { return p >= c.p; }
  HBool operator <= (const HCoord &c) const { return p <= c.p; }
  HBool operator >  (const HCoord &c) const { return p > c.p; }
  HBool operator <  (const HCoord &c) const { return p < c.p; }
  
  const char *ClassName(void) const { return "HCoord"; }
};

#endif


/****************************************************************************/
/*                            HAngle                                        */
/****************************************************************************/
class LIntExport HAngle: public HNumeric {
public:  
  HAngle(void): val(0) {}
  HAngle(double Val): val(Val) {}
  
  virtual operator double(void) const = 0;
  virtual void Add(const HAngle &val) = 0;
  virtual void Sub(const HAngle &val) = 0;
  virtual void Mult(const HAngle &val) = 0;
  virtual void Div(const HAngle &val) = 0;
  virtual const char *ClassName(void) const = 0;
  //HAngleRad ToAngleRad(void) const = 0;
  //HAngleDeg ToAngleDeg(void) const = 0;
  //operator HAngleRad(void) const;
  //operator HAngleDeg(void) const;
protected:
  double val;
};



/****************************************************************************/
/*                            HAngleDeg                                     */
/****************************************************************************/
class LIntExport HAngleDeg: public HAngle {
public:
  HAngleDeg(void): HAngle(0.0) {}
  HAngleDeg(double val);
#if !defined(_TMS320C6X)
  HAngleDeg(Hlong val);
#endif
  HAngleDeg(int val);
  HAngleDeg(const HAngleRad &val);
  
  operator double(void) const;
  operator HAngleRad(void) const;
  HAngleDeg operator * (const HAngleDeg &v) const;
  HAngleDeg operator / (const HAngleDeg &v) const;
  HAngleDeg operator + (const HAngleDeg &v) const;
  HAngleDeg operator - (const HAngleDeg &v) const;
  HAngleDeg operator * (double v) const;
  HAngleDeg operator / (double v) const;
  HAngleDeg operator + (double v) const;
  HAngleDeg operator - (double v) const;
  
  void Add(const HAngle &val);
  void Sub(const HAngle &val);
  void Mult(const HAngle &val);
  void Div(const HAngle &val);
  
  const char   * ClassName(void) const { return "HAngleDeg"; }
private:
  void   Normalize(void);
};


/****************************************************************************/
/*                            HAngleRad                                     */
/****************************************************************************/
class LIntExport HAngleRad: public HAngle {
public:
  HAngleRad(void): HAngle(0.0) {}
  HAngleRad(double val);
#if !defined(_TMS320C6X)
  HAngleRad(Hlong val);
#endif
  HAngleRad(int val);
  HAngleRad(const HAngleDeg &val);
  
  operator double(void) const;
  operator HAngleDeg(void) const;
  HAngleRad operator * (const HAngleRad &v) const;
  HAngleRad operator / (const HAngleRad &v) const;
  HAngleRad operator + (const HAngleRad &v) const;
  HAngleRad operator - (const HAngleRad &v) const;
  HAngleRad operator * (double v) const;
  HAngleRad operator / (double v) const;
  HAngleRad operator + (double v) const;
  HAngleRad operator - (double v) const;
  
  void Add(const HAngle &val);
  void Sub(const HAngle &val);
  void Mult(const HAngle &val);
  void Div(const HAngle &val);
  
  const char   * ClassName(void) const { return "HAngleRad"; }
private:
  void   Normalize(void);
};



/****************************************************************************/
/*                            HComplex                                      */
/****************************************************************************/
class LIntExport HComplex: public HNumeric {
public:
  //HComplex(void): re(0.0), im(0.0) {} JC  entfernt doppelt eigentlich wie unten
   HComplex(double Re = 0.0, double Im = 0.0): re(Re), im(Im) {}
  
  operator double(void) const { return HAbs(); }
#if !defined(_TMS320C6X)
  operator Hlong(void) const { return (Hlong)HAbs(); }
#endif
  operator int(void) const { return (int)HAbs(); }  /*JC*/
  operator HByte(void) const { return HClipByte(HAbs()); }
  double & Re(void) { return re; }
  double & Im(void) { return im; }
  const char   * ClassName(void) const { return "HComplex"; }
  double   HAbs(void) const { return sqrt(re * re + im * im); }
private:
  double re, im;
};


}


#endif
