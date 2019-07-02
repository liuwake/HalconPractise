/*****************************************************************************
 * HXLDModPara.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HXLDModPara
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef XLD_MOD_PARA_H
#define XLD_MOD_PARA_H


namespace Halcon {


/****************************************************************************/
/*                               HXLDModPara                                */
/****************************************************************************/

class HXLDModParaArray;
class LIntExport HXLDModPara: public HXLD {
  friend class HXLDModParaArray;
public:
  HXLDModPara(void): HXLD() {}
  HXLDModPara(Hkey key);
  HXLDModPara(const Hobject &obj);
  HXLDModPara(const HXLDModPara &mod_para);
  HXLDModPara(const HXLDModParaArray &arr);
  HXLDModPara(const HXLD &xld);
  ~HXLDModPara(void) {}

  HXLDModPara &operator= (const HXLDModPara &mod_para);
  HXLDModPara &operator= (const HXLDModParaArray &arr);
  HXLDModPara &operator= (const HXLD &xld);

  // Tools
  virtual const char *HClassName(void) const;
  virtual const char *ClassName(void) const;
  virtual const char *InstClassName(void) const;
  virtual INT4        ClassDBID(void) const;
          HBool       Shared(void) const;

  // Class Functions

public: 
};

}

#endif
