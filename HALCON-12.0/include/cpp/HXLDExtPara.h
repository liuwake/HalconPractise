/*****************************************************************************
 * HXLDExtPara.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HXLDExtPara
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef XLD_EXT_PARA_H
#define XLD_EXT_PARA_H


namespace Halcon {


/****************************************************************************/
/*                               HXLDExtPara                                */
/****************************************************************************/

class HXLDExtParaArray;
class LIntExport HXLDExtPara: public HXLD {
  friend class HXLDExtParaArray;
public:
  HXLDExtPara(void): HXLD() {}
  HXLDExtPara(Hkey key);
  HXLDExtPara(const Hobject &obj);
  HXLDExtPara(const HXLDExtPara &ext_para);
  HXLDExtPara(const HXLDExtParaArray &arr);
  HXLDExtPara(const HXLD &xld);
  ~HXLDExtPara(void) {}

  HXLDExtPara &operator= (const HXLDExtPara &ext_para);
  HXLDExtPara &operator= (const HXLDExtParaArray &arr);
  HXLDExtPara &operator= (const HXLD &xld);

  // Tools
  virtual const char *HClassName(void) const;
  virtual const char *ClassName(void)  const;
  virtual const char *InstClassName(void) const;
  virtual INT4        ClassDBID(void) const;
          HBool       Shared(void) const;

  // Class Functions

public:
};

}

#endif
