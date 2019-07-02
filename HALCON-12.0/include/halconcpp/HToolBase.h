/*****************************************************************************
 * HToolBase.h
 ***************************************************************************** 
 *
 * Project:     Halcon/C++
 * Description: Smart pointer concept for managing tool class references
 *
 * (c) 2010-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 *****************************************************************************/


#ifndef HCPP_TOOL_BASE_H
#define HCPP_TOOL_BASE_H



namespace HalconCpp
{

// Smart pointer to internal data representation

template<class T> class HSmartPtr;

class HToolRef;

typedef HSmartPtr<HToolRef> HToolRefPtr;


// Base class for actual tool class

class LIntExport HToolBase
{
public:

  // Destructor
  virtual ~HToolBase();
  
public: 

  // Access and Manipulation 
  
  Hlong         GetHandle() const;   
  virtual void  SetHandle(Hlong handle) = 0;   // Must create specialized toolref
  void          InvalidateHandle();
  void          Detach();

  void          Clear();
  bool          IsHandleValid() const;

  operator Hlong()  const;
  operator HTuple() const;

  HToolBase& operator=(const HToolBase& tool);
  
protected:

  // Constructor (only for subclass implementation)
  HToolBase();

  // Copy constructor
  HToolBase(const HToolBase& tool);

  //Handle
  HToolRefPtr& mId;
};



// Base class for actual tool array classes

class LIntExport HToolArray
{

public:

  // Destructor
  virtual ~HToolArray();
  
  // Clears array and all tool instances
  virtual void Clear() = 0;

  // Get number of tools  
  virtual Hlong Length() const = 0;

  // Create tool array from tuple of handles
  virtual void SetFromTuple(const HTuple& handles) = 0;

  // Get tuple of handles for tool array
  virtual HTuple ConvertToTuple() const = 0;
  
};

} // namespace


#endif






