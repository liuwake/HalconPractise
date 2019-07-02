/*****************************************************************************
 * HTuple.h
 ***************************************************************************** 
 *
 * Project:     Halcon/libhalcon
 * Description: Class HTuple
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 * 
 */

#ifndef HTUPLE_H
#define HTUPLE_H

#include <HBase.h>

namespace Halcon {


/****************************************************************************/
/*                           HCtrlVal                                       */
/****************************************************************************/

/* vvvvvv not used anymore (Hpar/Hcpar used instead) */
union CtrlUnion {
  Hlong         l;          // Parameter of Type Hlong (integer)
  double        d;          // Parameter of Type double (real)
  char          *s;         // Parameter of Type string
};
/* ^^^^^^ not used anymore (Hpar/Hcpar used instead) */

enum HCtrlType {
  LongVal   = LONG_PAR, 
  DoubleVal = DOUBLE_PAR,
  StringVal = STRING_PAR,
  UndefVal  = UNDEF_PAR
};

class LIntExport HCtrlVal  {
  friend class HTuple;
public:
  HCtrlVal(void)      {val.type  = UndefVal;  val.par.l = 0;}
#if !defined(_TMS320C6X)
  HCtrlVal(Hlong l)   {val.type  = LongVal;   val.par.l = l;}
#endif
  HCtrlVal(int l)     {val.type  = LongVal;   val.par.l = l;}
  HCtrlVal(double d)  {val.type  = DoubleVal; val.par.f = d;}
  HCtrlVal(const char *s);
  HCtrlVal(const HCtrlVal &v) {CopyCtrlVal(v);}
  ~HCtrlVal(void)             {ClearCtrlVal();}
  HCtrlVal& operator = (const HCtrlVal &v);
 
  // Type conversion
  int         ValType() const          {return val.type;}
  operator    int(void) const          {return I();}
#if !defined(_TMS320C6X)
  operator    Hlong(void) const        {return L();}
#endif
  operator    double(void) const       {return D();}
  operator    const char*(void) const  {return S();}
  operator    const Hcpar&(void)const  {return HCPAR();}
  // Access contents
  double          D() const;
  Hlong           L() const;
  int             I() const;
  const char *    S() const;
  const Hcpar&    HCPAR()const;
  // Arithmetics
  HCtrlVal     operator + (const HCtrlVal &val) const;
  HTuple       operator + (const HTuple &val) const;
  HCtrlVal     operator - (const HCtrlVal &val) const;
  HTuple       operator - (const HTuple &val) const;
  HCtrlVal     operator * (const HCtrlVal &val) const;
  HTuple       operator * (const HTuple &val) const;
  HCtrlVal     operator / (const HCtrlVal &val) const;
  HTuple       operator / (const HTuple &val) const;
  HCtrlVal     operator % (const HCtrlVal &val) const;
  HTuple       operator % (const HTuple &val) const;
  HBool        operator != (const HCtrlVal &val) const;
  HBool        operator != (const HTuple &val) const;
  HBool        operator == (const HCtrlVal &val) const;
  HBool        operator == (const HTuple &val) const;
  HBool        operator >= (const HCtrlVal &val) const;
  HBool        operator >= (const HTuple &val) const;
  HBool        operator <= (const HCtrlVal &val) const;
  HBool        operator <= (const HTuple &val) const;
  HBool        operator > (const HCtrlVal &val) const;
  HBool        operator > (const HTuple &val) const;
  HBool        operator < (const HCtrlVal &val) const;
  HBool        operator < (const HTuple &val) const;

  const char *ClassName(void) const { return "HCtrlVal"; }
  int Version(void) const;
  int Revision(void) const;
  const char *Creation(void) const;
  
private:
  // Data
  Hcpar       val;        // Value: one of the three types and type specifyer
  // Support operationen
  void ClearCtrlVal();
  void CopyCtrlVal(const HCtrlVal& source);
};



/****************************************************************************/
/*                             Tuple                                        */
/****************************************************************************/

struct SpecialTuple { 
  int val; 
  SpecialTuple(int v = H_IGNORE) {val = v;}
};



class LIntExport HTuple: public HBaseArray {
public:
  HTuple(void);
#if !defined(_TMS320C6X)
  HTuple(Hlong l);
#endif
  HTuple(int l);
  HTuple(float f);
  HTuple(double d);
  HTuple(const char *s);
  HTuple(const HCtrlVal &c);
  HTuple(const HTuple &in):HBaseArray() {CopyTuple(in);}
  HTuple(Hlong length, const HTuple &value);
  HTuple(const HTuple &length, const HTuple &value);
  HTuple(SpecialTuple d);

  ~HTuple()                     {ClearTuple();}
  HTuple &operator = (const HTuple& in);

  // The functions CastFromHctuple() and CastToHctuple() are used
  // for accelerated data transfer between HALCON and HALCON/C++.
  // Designed for internal usage only.
  void CastFromHctuple(Hctuple *ctuple);
  void CastToHctuple(Hctuple &ctuple) const;
  
  HTuple       Sum(void) const;
  HTuple       Mean(void) const;
  HTuple       Deviation(void) const;
  HTuple       Median(void) const;
  HTuple       Getenv(void) const;
  HTuple       Max(void) const;
  HTuple       Min(void) const;
  HTuple       Rad(void) const;
  HTuple       Deg(void) const;
  HTuple       Real(void) const;
  HTuple       Int(void) const;
  HTuple       Round(void) const;
  HTuple       Chr(void) const;
  HTuple       Ord(void) const;
  HTuple       Chrt(void) const;
  HTuple       Ords(void) const;
  HTuple       Number(void) const;
  HTuple       Sqrt(void) const;
  HTuple       IsNumber(void) const;
  HTuple       Strlen(void) const;
  HTuple       Inverse(void) const;
  HTuple       Asin(void) const;
  HTuple       Acos(void) const;
  HTuple       Atan(void) const;
  HTuple       Log(void) const;
  HTuple       Log10(void) const;
  HTuple       Sin(void) const;
  HTuple       Cos(void) const;
  HTuple       Tan(void) const;
  HTuple       Sinh(void) const;
  HTuple       Cosh(void) const;
  HTuple       Tanh(void) const;
  HTuple       Exp(void) const;
  HTuple       Abs(void) const;
  HTuple       Sgn(void) const;
  HTuple       Rand(void) const;
  HTuple       Uniq(void) const;
  HTuple       Floor(void) const;
  HTuple       Ceil(void) const;
  HTuple       Sort(void) const;
  HTuple       SortIndex(void) const;
  HTuple       Cumul(void) const;
  HTuple       Atan2(const HTuple &op) const;
  HTuple       Pow(const HTuple &op) const;
  HTuple       Ldexp(const HTuple &op) const;
  HTuple       Fmod(const HTuple &op) const;
  HTuple       Min2(const HTuple &op) const;
  HTuple       Max2(const HTuple &op) const;
  HTuple       Find(const HTuple &op) const;
  HTuple       RegexpMatch(const HTuple &expression) const;
  HTuple       RegexpMatch(const char *expression) const;
  HTuple       RegexpReplace(const HTuple &expression, const HTuple &replace) const;
  HTuple       RegexpReplace(const char *expression, const char *replace) const;
  Hlong        RegexpTest(const HTuple &expression) const;
  Hlong        RegexpTest(const char *expression) const;
  HTuple       RegexpSelect(const HTuple &expression) const;
  HTuple       RegexpSelect(const char *expression) const;
  HTuple       Strchr(const HTuple &pattern) const;
  HTuple       Strchr(const char *pattern) const;
  HTuple       Strstr(const HTuple &pattern) const;
  HTuple       Strstr(const char *pattern) const;  
  HTuple       Strrchr(const HTuple &pattern) const;
  HTuple       Strrchr(const char *pattern) const;
  HTuple       Strrstr(const HTuple &pattern) const;
  HTuple       Strrstr(const char *pattern) const;
  HTuple       StrBitSelect(Hlong index) const;
  HTuple       StrBitSelect(const HTuple &index) const;
  HTuple       ToString(const char *pattern) const;
  HTuple       ToString(const HTuple &pattern) const;
  HTuple       Split(const char *pattern) const;
  HTuple       Split(const HTuple &pattern) const;
  HTuple       Substring(const HTuple &index1, const HTuple &index2) const;
  HTuple       Substring(Hlong index1, Hlong index2) const;
  HTuple       Substring(const HTuple &index1, Hlong index2) const;
  HTuple       Substring(Hlong index1, const HTuple &index2) const;
  HTuple       Substr(const HTuple &index1, const HTuple &index2) const;
  HTuple       Subset(const HTuple &index) const;
  HTuple       SelectMask(const HTuple &mask) const;
  HTuple       Remove(const HTuple &index) const;
  HTuple       SelectRank(Hlong index) const;
  HTuple       SelectRank(const HTuple &index) const;
  HTuple       Replace(const HTuple &index, const HTuple &replace) const;
  HTuple       Insert(const HTuple &index, const HTuple &insert) const;
  HBool        Xor(const HTuple &pattern) const;
  HTuple       TXor(const HTuple &val) const;
  HTuple       And(const HTuple &val) const;
  HTuple       Or(const HTuple &val) const;
  HTuple       Not(void) const;
  HTuple       Type(void) const;
  HTuple       IsInt(void) const;
  HTuple       IsReal(void) const;
  HTuple       IsString(void) const;
  HTuple       IsMixed(void) const;
  HTuple       TypeElem(void) const;
  HTuple       IsIntElem(void) const;
  HTuple       IsRealElem(void) const;
  HTuple       IsStringElem(void) const;
  HTuple       EqualElem(const HTuple &val) const;
  HTuple       NotEqualElem(const HTuple &val) const;
  HTuple       GreaterElem(const HTuple &val) const;
  HTuple       GreaterEqualElem(const HTuple &val) const;
  HTuple       LessElem(const HTuple &val) const;
  HTuple       LessEqualElem(const HTuple &val) const;
  HTuple       Union(const HTuple& set2) const;
  HTuple       Intersection(const HTuple& set2) const;
  HTuple       Difference(const HTuple& set2) const;
  HTuple       Symmdiff(const HTuple& set2) const;
  HTuple       FindLast(const HTuple& to_find) const;
  HTuple       FindFirst(const HTuple& to_find) const;
  static HTuple GenSequence(const HTuple &start,
                            const HTuple &end,
                            const HTuple &step);
  operator     HCtrlVal(void) const;
  HTuple       operator () (Hlong min, Hlong max) const;
  HTuple       operator () (const HTuple &min, const HTuple &max) const;
  HCtrlVal    &operator [] (Hlong index);
  HCtrlVal     operator [] (Hlong index) const;
  HCtrlVal    &operator [] (const HTuple &index);
  HCtrlVal     operator [] (const HTuple &index) const;
  HTuple      &operator ++ (void); // nur fuer double und Hlong
  HBool        operator !  (void) const;
  HTuple       operator ~  (void) const;
  HTuple       operator << (const HTuple &val) const;
  HTuple       operator << (Hlong val) const;
  HTuple       operator >> (const HTuple &val) const;
  HTuple       operator >> (Hlong val) const;
  HTuple       operator +  (const HTuple &val) const;
  HTuple       operator +  (double val) const;
  HTuple       operator +  (int val) const;
#if !defined(_TMS320C6X)
  HTuple       operator +  (Hlong val) const;
#endif
  HTuple       operator +  (const char *val) const;
  HTuple       operator -  (const HTuple &val) const;
  HTuple       operator -  (double val) const;
  HTuple       operator -  (int val) const;
#if !defined(_TMS320C6X)
  HTuple       operator -  (Hlong val) const;
#endif
  HTuple       operator -  (void) const;
  HTuple       operator *  (const HTuple &val) const;
  HTuple       operator *  (double val) const;
  HTuple       operator *  (int val) const;
#if !defined(_TMS320C6X)
  HTuple       operator *  (Hlong val) const;
#endif
  HTuple       operator /  (const HTuple &val) const;
  HTuple       operator /  (double val) const;
  HTuple       operator /  (int val) const;
#if !defined(_TMS320C6X)
  HTuple       operator /  (Hlong val) const;
#endif
  HTuple       operator %  (const HTuple &val) const;
  HTuple       operator %  (Hlong val) const;
  HTuple      &operator += (const HTuple &val);
  HTuple      &operator += (double val);
  HTuple      &operator += (int val);
#if !defined(_TMS320C6X)
  HTuple      &operator += (Hlong val);
#endif
  HTuple      &operator += (HCtrlVal val);
  HBool        operator != (const HTuple &val) const;
  HBool        operator != (double val) const;
  HBool        operator != (int val) const;
#if !defined(_TMS320C6X)
  HBool        operator != (Hlong val) const;
#endif
  HTuple       operator ^  (const HTuple &val) const;
  HTuple       operator ^  (Hlong val) const;
  HTuple       operator |  (const HTuple &val) const;
  HTuple       operator |  (Hlong val) const;
  HTuple       operator &  (const HTuple &val) const;
  HTuple       operator &  (Hlong val) const;
  HBool        operator && (const HTuple &val) const;
  HBool        operator && (Hlong val) const;
  HBool        operator || (const HTuple &val) const;
  HBool        operator || (Hlong val) const;
  HBool        operator == (const HTuple &val) const;
  HBool        operator == (double val) const;
  HBool        operator == (int val) const;
#if !defined(_TMS320C6X)
  HBool        operator == (Hlong val) const;
#endif
  HBool        operator >= (const HTuple &val) const;
  HBool        operator >= (double val) const;
  HBool        operator >= (int val) const;
#if !defined(_TMS320C6X)
  HBool        operator >= (Hlong val) const;
#endif
  HBool        operator <= (const HTuple &val) const;
  HBool        operator <= (double val) const;
  HBool        operator <= (int val) const;
#if !defined(_TMS320C6X)
  HBool        operator <= (Hlong val) const;
#endif
  HBool        operator >  (const HTuple &val) const;
  HBool        operator >  (double val) const;
  HBool        operator >  (int val) const;
#if !defined(_TMS320C6X)
  HBool        operator >  (Hlong val) const;
#endif
  HBool        operator <  (const HTuple &val) const;
  HBool        operator <  (double val) const;
  HBool        operator <  (int val) const;
#if !defined(_TMS320C6X)
  HBool        operator <  (Hlong val) const;
#endif

  // friend operators
  LIntExport friend HTuple operator << (Hlong val1, const HTuple &val2);
  LIntExport friend HTuple operator >> (Hlong val1, const HTuple &val2);
  LIntExport friend HTuple operator + (double val1, const HTuple &val2);
  LIntExport friend HTuple operator + (int val1, const HTuple &val2);
  LIntExport friend HTuple operator + (Hlong val1, const HTuple &val2);
  LIntExport friend HTuple operator + (const char *val1, const HTuple &val2);
  LIntExport friend HTuple operator - (double val1, const HTuple &val2);
  LIntExport friend HTuple operator - (int val1, const HTuple &val2);
  LIntExport friend HTuple operator - (Hlong val1, const HTuple &val2);
  LIntExport friend HTuple operator * (double val1, const HTuple &val2);
  LIntExport friend HTuple operator * (int val1, const HTuple &val2);
  LIntExport friend HTuple operator * (Hlong val1, const HTuple &val2);
  LIntExport friend HTuple operator / (double val1, const HTuple &val2);
  LIntExport friend HTuple operator / (int val1, const HTuple &val2);
  LIntExport friend HTuple operator / (Hlong val1, const HTuple &val2);
  LIntExport friend HTuple operator % (Hlong val1, const HTuple &val2);
  LIntExport friend HTuple operator ^  (Hlong val1, const HTuple &val2);
  LIntExport friend HTuple operator | (Hlong val1, const HTuple &val2);
  LIntExport friend HTuple operator & (Hlong val1, const HTuple &val2);
  LIntExport friend HBool operator || (Hlong val1, const HTuple &val2);
  LIntExport friend HBool operator && (Hlong val1, const HTuple &val2);
  LIntExport friend HBool operator != (double val1, const HTuple &val2);
  LIntExport friend HBool operator != (int val1, const HTuple &val2);
  LIntExport friend HBool operator != (Hlong val1, const HTuple &val2);
  LIntExport friend HBool operator == (double val1, const HTuple &val2);
  LIntExport friend HBool operator == (int val1, const HTuple &val2);
  LIntExport friend HBool operator == (Hlong val1, const HTuple &val2);
  LIntExport friend HBool operator >= (double val1, const HTuple &val2);
  LIntExport friend HBool operator >= (int val1, const HTuple &val2);
  LIntExport friend HBool operator >= (Hlong val1, const HTuple &val2);
  LIntExport friend HBool operator <= (double val1, const HTuple &val2);
  LIntExport friend HBool operator <= (int val1, const HTuple &val2);
  LIntExport friend HBool operator <= (Hlong val1, const HTuple &val2);
  LIntExport friend HBool operator > (double val1, const HTuple &val2);
  LIntExport friend HBool operator > (int val1, const HTuple &val2);
  LIntExport friend HBool operator > (Hlong val1, const HTuple &val2);
  LIntExport friend HBool operator < (double val1, const HTuple &val2);
  LIntExport friend HBool operator < (int val1, const HTuple &val2);
  LIntExport friend HBool operator < (Hlong val1, const HTuple &val2);

  HBool        Continue(const HTuple &FinalValue, const HTuple &Increment); 
  HTuple      &Append(const HTuple &t);
  HTuple       Concat(const HTuple &t) const;
  int          State(void) const   {return state;}
  void         Reset(void)         {ClearTuple(); tuple = 0; EmptyArray();}
  void         ReplaceElements(const HTuple &Index,
                               const HTuple &ReplaceValue);
  HTuple       Select(const HTuple &Index);
  const char  *ClassName(void) const { return "HTuple"; }
private:
  HCtrlVal    *tuple;       // values (array of Hlong/float/string)
  char        state;
  
  void  NewLength(Hlong new_num, Hlong old_num);
  void  ClearTuple();
  void  CopyTuple(const HTuple& in);

};


}


#endif
