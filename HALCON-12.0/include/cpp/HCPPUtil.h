/*****************************************************************************
 * HCPPUtil.h
 ***************************************************************************** 
 *
 * Project:     Halcon/libhalcon
 * Description: Types for HCPPUtil.cxx
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_CPPUTIL_H
#define H_CPPUTIL_H

#include <stdio.h>

namespace Halcon {


/****************************************************************************/
/*                            HRootObject                                   */
/****************************************************************************/
class LIntExport HRootObject {
public:
  virtual const char *ClassName(void) const = 0;
  int Version(void) const;
  int Revision(void) const;
  const char *Creation(void) const;

  // This destructor must be declared for avoiding strange errors in 
  // optimized Windows programms!!!
  virtual ~HRootObject(void) {}

#ifdef WIN32EXTRA
  void* operator new(size_t nSize);
  void  operator delete(void* p);
#endif

};


/****************************************************************************/
/*                           HBaseArray                                     */
/****************************************************************************/

class LIntExport HBaseArray: public HRootObject {
public:
  HBaseArray() : num(0), num_max(0) {} // Empty array
  HBaseArray(Hlong n, HBOOL single = FALSE);

  // virtual ~HBaseArray(void);

  virtual const char *ClassName(void) const = 0;
  Hlong Num(void) const {return num;}

protected:
  void Extend(Hlong last_index);
  virtual void NewLength(Hlong new_num, Hlong old_num) = 0;
  void EmptyArray() {num = num_max = 0;}
  void SingleArray();
  void NormalArray(Hlong n) {num = num_max = n;}
  void SetArray(Hlong n,Hlong nm) {num = n; num_max = nm;}
  Hlong AllocNum() const {return num_max;}
private:
  Hlong num;
  Hlong num_max;
  static  float incr;
  static  Hlong num_def;  
};





/****************************************************************************/
/*                            HAffineTrans                                  */
/****************************************************************************/
class LIntExport HAffineTrans: public HRootObject {
public:
  virtual void Identity(void) = 0;
  virtual void Translate(const HVector &vector) = 0;
  virtual void Scale(const HVector &vector) = 0;
  virtual void Rotate(const double phi) = 0;
  virtual void Transform(HVector &vector) const = 0;
  virtual void Transform(HDVector &vector) const = 0;
  virtual void Transform(HPoint &point) const = 0;
  virtual void Transform(HDPoint &point) const = 0;
  virtual const char *ClassName(void) const = 0;
};



/****************************************************************************/
/*                            HAffineTrans2D                                */
/****************************************************************************/
class LIntExport HAffineTrans2D: public HAffineTrans {
public:
  HAffineTrans2D(void);
  void Identity(void);
  void Translate(const HVector &vector);
  void Scale(const HVector &vector);
  void Rotate(const double phi);
  void Transform(HVector &vector) const;
  void Transform(HDVector &vector) const;
  void Transform(HPoint &point) const;
  void Transform(HDPoint &point) const;
  const char *ClassName(void) const { return "HAffineTrans2D"; };
private:
  double m[2][3];
};



/****************************************************************************/
/*                            HAffineTrans3D                                */
/****************************************************************************/
class LIntExport HAffineTrans3D: public HAffineTrans {
public:
  HAffineTrans3D(void);
  void Identity(void);
  void Translate(const HVector &vector);
  void Scale(const HVector &vector);
  void Rotate(const double phi) { RotateZ(phi); }
  void RotateX(const double phi);
  void RotateY(const double phi);
  void RotateZ(const double phi);
  void Transform(HVector &vector) const;
  void Transform(HDVector &vector) const;
  void Transform(HPoint &point) const;
  void Transform(HDPoint &point) const;
  const char *ClassName(void) const { return "HAffineTrans3D"; };
private:
  double m[3][4];
};



/****************************************************************************/
/*                            HSpatialObject                                */
/****************************************************************************/
class LIntExport HSpatialObject: public HRootObject {
public:
  virtual void Transform(const HAffineTrans &transform) = 0;
  virtual void Display(const HWindow &w) const = 0;
  virtual const char *ClassName(void) const = 0;
  // virtual double Area(void) const = 0;
  // virtual HRectangle1 SmallestRectangle1(void) const = 0;
  // virtual int Dimensionality(void) const = 0; // Punkt = 0, Linie = 1, ..
  // virtual int Dimensions(void) const = 0; // 2D oder 3D, gibt es z-Koord
};




/****************************************************************************/
/*                              HObject                                     */
/****************************************************************************/
class LIntExport HObject: public HRootObject {
public:
  HObject(void): used(TRUE), id(H_EMPTY_REGION) {}
  HObject(Hkey key): used(TRUE) {id = key ? key : H_EMPTY_REGION;}
  HObject(const Hobject &obj);
  // Copy-Konstruktor
  HObject(const HObject &r):HRootObject() {CopyHObject(r);}
  virtual ~HObject(void);
  
  virtual HBool Shared(void) const = 0;
  HBool IsCleared(void) const {return !used;}
  virtual Hobject Id(void) const;
  virtual Hkey Key(void) const {TestUsed("Key"); return id;}
  virtual const char *HClassName(void) const;
  virtual const char *Creator(void) const;
  virtual const char *InstClassName(void) const = 0;
  virtual const char *ClassName(void) const = 0;
  virtual INT4 ClassDBID(void) const {return OBJECT_ID;}
  virtual void Display(const HWindow &w) const;
  void Clear(void) {FreeData();}
  virtual void Reset(void) {SetKey(H_EMPTY_REGION);}
  virtual void SetKey(Hkey key);
  virtual void InitKey(Hkey key);

protected:
  HBool used;
  Hkey id;
  void TestUsed(const char *proc) const
    {if (IsCleared()) ClearedException(proc);}
  void ClearedException(const char *proc) const;
  virtual void FreeData(void);
  virtual void CopyHObject(const HObject &in);
  virtual void CheckMyObjClass(void) const {CheckMyObjClass(ClassDBID());}
  void CheckMyObjClass(INT4 reqdbid) const;
};


/****************************************************************************/
/*                              Hobject                                     */
/****************************************************************************/

class LIntExport Hobject : public HRootObject {
public:
  Hobject(HBool cl=TRUE)
    : id(H_EMPTY_REGION), delObj(cl)
  {}
  // HObject.id (=Hkey) -> Hobject => defaultmaessig wird nicht geloescht
  Hobject(Hkey key, HBool cl=FALSE)
    : id(key ? key : H_EMPTY_REGION), delObj(cl)
  {}
  // HObject.Id() (=Hobject) -> Hobject => defaultmaessig wird geloescht
  Hobject(const Hobject &obj);

  ~Hobject(void)
  {
    Delete();
  }
  Hobject& operator=(const Hobject& obj);

  void AdaptId(Hkey obj)
  {
    Delete();
    id = obj ? obj : H_EMPTY_REGION;
  }
  void Reset(void)
  {
    Delete();
    id = H_EMPTY_REGION;
  }
  Hkey Id() const
  {
    return id;
  }
  virtual const char *ClassName(void) const;

private:
  Hkey  id;
  HBool delObj;
  void Delete(void)
  {
    if (delObj && id != H_EMPTY_REGION)
      freeData();
  }
  void freeData(void);
};





/****************************************************************************/
/*                              HBaseImage                                  */
/****************************************************************************/

class LIntExport HBaseImage: public HRootObject {
public:
  virtual const char *ClassName(void) const = 0;
protected:
};




/****************************************************************************/
/*                           HObjectArray                                   */
/****************************************************************************/

class LIntExport HObjectArray: public HBaseArray {
public:
  HObjectArray(void) : HBaseArray()  {}
  HObjectArray(Hlong n, HBOOL single = false) : HBaseArray(n,single) {}

  virtual const char *ClassName(void) const = 0;
  Hobject Id(Hlong i) const {return ElemId(i);}
  Hobject Id(void) const;
  virtual Hkey Key(Hlong i)     const = 0;
  virtual Hobject ElemId(Hlong i)  const = 0;
  virtual void Display(const HWindow &w) const = 0;
  virtual void NewLength(Hlong new_num, Hlong old_num) = 0;
  virtual void SetKeys(Hkey *key, Hlong num) = 0;
  virtual void SetKeys(Hkey *key, Hlong num, Herror *err) = 0;
  virtual void Reset(void) {SetKeys(NULL,0);}
};



//
// Some often used basic operations
//

inline Hlong HLinearCoord(int x, int y, int width)
{
  return y * width + x;
}


inline HByte HClipByte(int val)
{
  if (val < 0) return 0;
  else if (val > 255) return 255;
  else return (HByte)val;
}

inline HByte HClipByte(unsigned int val)
{
  if (val > 255) return 255;
  else return (HByte)val;
}

#if !defined(_TMS320C6X)
inline HByte HClipByte(Hlong val)
{
  if (val < 0) return 0;
  else if (val > 255) return 255;
  else return (HByte)val;
}
#endif

inline HByte HClipByte(double val)
{
  if (val < -0.5) return 0;
  else if (val > 255.5) return 255;
  else return (HByte)(val + 0.5);
}


inline INT1 HClipInt1(Hlong val)
{
  if (val < INT1_MIN) return INT1_MIN;
  else if (val > INT1_MAX) return INT1_MAX;
  else return (INT1)val;/* JC return (INT2)val;*/
}

inline INT2 HClipInt2(Hlong val)
{
  if (val < INT2_MIN) return INT2_MIN;
  else if (val > INT2_MAX) return INT2_MAX;
  else return (INT2)val;
}

inline INT2 HClipInt2(double val)
{
  if (val < INT2_MIN) return INT2_MIN;
  else if (val > INT2_MAX) return INT2_MAX;
  else return (INT2)val;
}


inline UINT2 HClipUInt2(Hlong val)
{
  if (val < UINT2_MIN) return UINT2_MIN;
  else if (val > UINT2_MAX) return UINT2_MAX;
  else return (UINT2)val;
}

inline UINT2 HClipUInt2(double val)
{
  if (val < UINT2_MIN) return UINT2_MIN;
  else if (val > UINT2_MAX) return UINT2_MAX;
  else return (UINT2)val;
}


inline INT4 HClipInt4(Hlong val)
{
  return (INT4)val;  // !! noch verbessern
}

inline INT4 HClipInt4(double val)
{
  return (INT4)val;  // !! noch verbessern
}


inline int HClipInt(Hlong val)
{
  return (int)val;  // !! noch verbessern
}

inline int HClipInt(double val)
{
  return (int)val;  // !! noch verbessern
}


inline HByte HRgbToGrey(HByte r, HByte g, HByte b)
{
  return HClipByte(r * 0.299 + g * 0.587 + b * 0.114);
}


#if !defined(_TMS320C6X)
inline HBool HIsEven(Hlong val)
{
  if ((val % 2) == 0) return TRUE; else return FALSE;
}
#endif

inline HBool HIsEven(int val)
{
  if ((val % 2) == 0) return TRUE; else return FALSE;
}


inline HBool HIsOdd(int val)
{
  if ((val % 2) == 0) return FALSE; else return TRUE;
}

#if !defined(_TMS320C6X)
inline HBool HIsOdd(Hlong val)
{
  if ((val % 2) == 0) return FALSE; else return TRUE;
}
#endif

inline double HMin(double a, double b)
{
  if (a < b) return a; else return b;
}

inline int HMin(int a, int b)
{
  if (a < b) return a; else return b;
}

#if !defined(_TMS320C6X)
inline Hlong HMin(Hlong a, Hlong b)
{
  if (a < b) return a; else return b;
}
#endif


inline double HMax(double a, double b)
{
  if (a < b) return b; else return a;
}

inline int HMax(int a, int b)
{
  if (a < b) return b; else return a;
}

#if !defined(_TMS320C6X)
inline Hlong HMax(Hlong a, Hlong b)
{
  if (a < b) return b; else return a;
}
#endif


inline double HAbs(double val)
{
  if (val < 0) return -val; else return val;
}

#if !defined(_TMS320C6X)
inline Hlong HAbs(Hlong val)
{
  if (val < 0) return -val; else return val;
}
#endif

inline int HAbs(int val)
{
  if (val < 0) return -val; else return val;
}


inline Hlong HRound(double val)
{
  if (val < 0) return (Hlong)(val-0.5); else return (Hlong)(val+0.5);
}


}


#endif
