/*****************************************************************************
 * HCPPToolRef.h
 ***************************************************************************** 
 *
 * Project:     Halcon/C++
 * Description: Smart pointer concept for managing tool class references
 *
 * (c) 2008-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */


#ifndef H_TOOL_REF_H
#define H_TOOL_REF_H

#define TOOL_HANDLE_INVALID -1

namespace Halcon {

/* Manage one tool handle including reference counter */

class LIntExport HToolRef
{
public:
  HToolRef();
  HToolRef(Hlong ID);
  virtual ~HToolRef();

  void         SetHandle(Hlong ID);
  unsigned int GetCount() const;
  virtual void addref() const;
  virtual bool deref() const;


  operator Hlong () const;
    
protected:
  Hlong   id;
  mutable unsigned int mSh_Count;
};


/* Smart pointer to tool reference */

class LIntExport HToolRefPtr
{
 public:

  HToolRefPtr();
  HToolRefPtr(HToolRef* ptr);
  HToolRefPtr(HToolRefPtr const & ptr);
  
  virtual ~HToolRefPtr();
  
  virtual HToolRefPtr& operator=(HToolRefPtr const & ptr);
  virtual HToolRefPtr& operator=(HToolRef* ptr);

  HToolRef* operator->() const;
  HToolRef& operator*() const;  
  HToolRef* Ref() const;  
  operator HToolRef&() const;
  
  bool operator!() const;
  operator bool() const;

  bool operator==(const HToolRefPtr& ptr) const;
  bool operator==(const HToolRef* ptr) const;
  bool operator!=(const HToolRefPtr& ptr) const;
  bool operator!=(const HToolRef* ptr) const;
  
  void Reset();

protected:

  void deref();
  void addref();
  void reset(HToolRef* ptr=0);

  HToolRef* mSp_Ptr;
};

/* Base class for actual tool classes */

class LIntExport HToolBase
{
public:

  // Constructors
  HToolBase();

  // Desctructor
  virtual ~HToolBase();
  
public: 

  virtual const char *ClassName() const = 0;

  // Access and Manipulation 
  Hlong         GetHandle() const;   
  virtual void  SetHandle(Hlong ID) = 0;   // Must create specialized toolref
  void          InvalidateHandle();

  bool  IsHandleValid() const;
  void  Cleanup();

  operator Hlong()  const;
  operator Halcon::HTuple() const;

protected:
  //Handle
  HToolRefPtr id;
};

} // namespace


/* Macro for declaring a reference class for a specific tool */

#define H_TOOL_REF_IMPL(NAME, DESTRUCTOR)                  \
class NAME##Ref : public Halcon::HToolRef {                \
public:                                                    \
  NAME##Ref():Halcon::HToolRef() {}                        \
  NAME##Ref(Hlong ID):Halcon::HToolRef(ID) {}              \
  ~NAME##Ref() {                                           \
    if (id != TOOL_HANDLE_INVALID) {                       \
      (void)Halcon::DESTRUCTOR(id);                        \
      id = TOOL_HANDLE_INVALID;                            \
    }                                                      \
  }                                                        \
};


/* Macro for implementing common tool management functionality */

#define H_TOOL_COMMON_IMPL(NAME)                                   \
  Halcon::NAME::NAME()         {}                                  \
  Halcon::NAME::NAME(Hlong ID) {SetHandle(ID);}                    \
  const char *Halcon::NAME::ClassName(void) const {return #NAME;}  \
  void Halcon::NAME::SetHandle(Hlong ID)                           \
  {                                                                \
    if (ID == TOOL_HANDLE_INVALID)                                 \
      id = 0;                                                      \
    else                                                           \
      HCkNew(id = new NAME##Ref(ID));                              \
  }                                                                \

/* Macro for implementing common tool management functionality
 * defining the default constructor by themselves: */

#define H_TOOL_COMMON_IMPL_NODEFCON(NAME)                          \
  Halcon::NAME::NAME(Hlong ID) {SetHandle(ID);}                    \
  const char *Halcon::NAME::ClassName(void) const {return #NAME;}  \
  void Halcon::NAME::SetHandle(Hlong ID)                           \
  {                                                                \
    if (ID == TOOL_HANDLE_INVALID)                                 \
      id = 0;                                                      \
    else                                                           \
      HCkNew(id = new NAME##Ref(ID));                              \
  }                                                                \

#endif // #ifndef H_TOOL_REF_H

