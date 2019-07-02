/*****************************************************************************
 * HString.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: String class for automatic memory management
 *
 * (c) 2010-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 *****************************************************************************/


#ifndef HCPP_STRING_H
#define HCPP_STRING_H


namespace HalconCpp
{

class Hstring;
class HTupleElement;


class LIntExport HString
{

public:

  // Create an emtpy string
  HString();

  // Create from C string
  HString(const char* text);
  
  // Copy constructor
  HString(const HString& string);

  // Destroy string
  virtual ~HString();
  
  // Assignment operator
  HString& operator=(const HString& string);

  // String equality  
  bool operator==(const HString& string);

  // Concatenation
  HString  operator+(const HString& string);
  HTuple   operator+(const HTuple& tuple);
  HTuple   operator+(const HTupleElement& te);
  HString& operator+=(const HString& string);
  HString& operator+=(const char * c);


  // Cast to C string
  operator const char*(void) const;
  
  
  /* Methods */
  
  // Clear contents of string
  void Clear();
  
  // Test for empty string
  bool IsEmpty() const;
  
  // Length of string 
  size_t Length() const;
  
  // Pointer to string data
  const char* Text() const;
  
 
protected:

  // Internal constructor
  HString(const Hstring& text);
  
  // Data container
  Hstring& mText;
};


}

#endif
