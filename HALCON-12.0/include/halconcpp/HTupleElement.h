/*****************************************************************************
 * HTupleElement.h
 *****************************************************************************
 *
 * Project:     HALCON/C++
 * Description: Element of tuple used for control parameters
 *
 * (c) 2010-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 *
 *****************************************************************************
 *
 *
 *****************************************************************************/


#ifndef HCPP_TUPLE_ELEMENT_H
#define HCPP_TUPLE_ELEMENT_H

#include "HString.h"
#include "HSmartPtr.h"

#ifndef HCPP_NO_OVERLOAD_TUPLE_OPERATORS
#define HCPP_OVERLOAD_TUPLE_OPERATORS // provide additional overloads for many
                                // operators involving HTuple or HTupleElement
#endif

#if defined(HCPP_OVERLOAD_TUPLE_OPERATORS)
#  if defined(HCPP_INT_OVERLOADS)
#    define H_COMPOUND_OP_INT_OVERLOAD_DECLARATION(RET,OP_COMPOUND) \
    RET& operator OP_COMPOUND (int val);
#  else
#    define H_COMPOUND_OP_INT_OVERLOAD_DECLARATION(RET,OP_COMPOUND)
#  endif
    // shared usage in classes HTuple and HTupleElement
#  define H_COMPOUND_OP_OVERLOAD_DECLARATION(RET,OP_COMPOUND)     \
    H_COMPOUND_OP_INT_OVERLOAD_DECLARATION(RET,OP_COMPOUND)\
    RET& operator OP_COMPOUND (Hlong val);                 \
    RET& operator OP_COMPOUND (float val);                 \
    RET& operator OP_COMPOUND (double val);                \
    RET& operator OP_COMPOUND (const HString& val);        \
    RET& operator OP_COMPOUND (const char* val);           \
    RET& operator OP_COMPOUND (const HTupleElement& val);
#else
#  define H_COMPOUND_OP_OVERLOAD_DECLARATION(RET,OP_COMPOUND)
#endif

namespace HalconCpp
{

enum HTupleElementType
{
  // The element is an integer value
  eElementTypeLong = eTupleTypeLong,

  // The element is a floating point value
  eElementTypeDouble = eTupleTypeDouble,

  // The element is a string
  eElementTypeString = eTupleTypeString,

  // The element is mixed
  eElementTypeMixed = eTupleTypeMixed,

  // The element type is undefined
  eElementTypeUndef = eTupleTypeEmpty
};


// Forward declarations for internal representation

class HTupleData;



/*****************************************************************************/
/* HTupleElementData                                                         */
/*****************************************************************************/

class HTupleElementData : public HSmartPtrRef
{

public:

  HTupleElementData(HTupleData* source, Hlong *index, Hlong length);
  virtual ~HTupleElementData();

  virtual HTupleElementType Type() const;
  virtual HTupleElementType Type(Hlong idx) const;

  Hlong   L() const {return getL(0);}
  Hlong   L(Hlong idx) const {return getL(idx);}
  double  D() const {return getD(0);}
  double  D(Hlong idx) const {return getD(idx);}
  HString S() const {return getS(0);}
  HString S(Hlong idx) const {return getS(idx);}
  const char* C() const {return getC(0);}
  const char* C(Hlong idx) const {return getC(idx);}
  Hcpar   P() const;
  Hcpar   P(Hlong idx) const;

  virtual HTupleElementData& operator=(const HTupleElementData& element);

  HTupleData* GetSource() const {return mSource;}
  Hlong*      GetIndex()  const {return mIndex;}
  Hlong       GetLength() const {return mLength;}

  void UpdateSource(HTupleData* source) {mSource = source;}

  virtual bool SupportsOptimizedTupleConversion() const {return false;}
  virtual HTuple ToTuple() const;

protected:

  virtual double      getD(Hlong idx) const;
  virtual Hlong       getL(Hlong idx) const;
  virtual HString     getS(Hlong idx) const;
  virtual const char* getC(Hlong idx) const;

protected:

  // Refer back to source implementation
  HTupleData* mSource;
  Hlong*      mIndex;
  Hlong       mLength;
};


template<class T> class HSmartPtr;

typedef HSmartPtr<HTupleElementData> HTupleElementDataPtr;

#if defined(_WIN32)
// In C++ an explicit template instantiation should appear at most once in
// a program, so it shouldn't really be in a header file. However, without
// this explicit instantiation, Visual C++ 2005 complains with a warning
// C4251. According to Microsoft
// (see http://support.microsoft.com/kb/168958/en-us), the explicit
// instantiation is required. For many other systems, putting the instantiation
// here is not required, but doesn't hurt either. However, there are some
// systems (ARM, and MacOS when using llvm-gcc 4.2) where putting the explicit
// instantiation here will lead to the linker complaining about multiple
// defined symbols because the compiler does not create weak symbols for the
// template functions, so we only put this in for Windows.
template class LIntExport HSmartPtr<HTupleElementData>;
#endif


class LIntExport HTupleElement
{
public:

  // Element for read access
  HTupleElement(HTuple* parent, Hlong index);
  HTupleElement(HTuple* parent, Hlong index[], Hlong length);

  // Element for write access
  HTupleElement(const HTuple* parent, Hlong index);
  HTupleElement(const HTuple* parent, Hlong index[], Hlong length);

  virtual ~HTupleElement();


  // Return the data type stored in this tuple element
  HTupleElementType Type() const;
  HTupleElementType Type(Hlong idx) const;

  // Return the length of the referenced tuple
  Hlong ParentLength() const;

  bool IndexInBounds() const;

  // Return the index in the referenced tuple
  Hlong* Index() const;
  Hlong  Length() const;

  // Return the integer value stored in this tuple element
  int     I() const;

  // Return the integer value stored in this tuple element
  Hlong   L(Hlong idx) const;
  Hlong   L() const;

  // Return the double value stored in this tuple element
  double  D(Hlong idx) const;
  double  D() const;

  // Return the string value stored in this tuple element
  HString S(Hlong idx) const;
  HString S() const;

  // Return the char* value stored in this tuple element
  const char* C(Hlong idx) const;
  const char* C() const;

  /***************************************************************************/
  /* Type casts                                                              */
  /***************************************************************************/

  HTupleElement(Hlong l);
  HTupleElement(double d);
  HTupleElement(HString s);
  HTupleElement(const char* s);
#if defined(HCPP_INT_OVERLOADS)
  HTupleElement(int i);
#endif
  HTupleElement(const HTuple& tuple);

  operator Hlong(void)       const {return L();}
  operator float(void)       const {return (float)D();}
  operator double(void)      const {return D();}
  operator HString(void)     const {return S();}
  operator const char*(void) const {return C();}
#if defined(HCPP_INT_OVERLOADS)
  operator int(void)     const {return (int) L();}
#endif

  HTupleElement& operator=(const HTupleElement& element);
  H_COMPOUND_OP_OVERLOAD_DECLARATION(HTupleElement,+=);
  H_COMPOUND_OP_OVERLOAD_DECLARATION(HTupleElement,-=);
  H_COMPOUND_OP_OVERLOAD_DECLARATION(HTupleElement,*=);

  HTuple ToTuple() const;


protected:

  void CreateElement(Hlong index[], Hlong length);

protected:

  // Reference back to originating tuple
  HTuple* mParent;

  // Owning temporary parent for conversion purposes
  bool mAttached;

  // Typed element reference implementation
  HTupleElementDataPtr mElement;
};



}


#endif
