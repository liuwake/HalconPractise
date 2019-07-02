/*****************************************************************************
 * HXLDModParaArray.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HXLDModParaArray
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 */

#ifndef XLD_MOD_PARA_ARRAY_H
#define XLD_MOD_PARA_ARRAY_H


namespace Halcon {


/****************************************************************************/
/*                               HXLDModParaArray                           */
/****************************************************************************/

class LIntExport HXLDModParaArray: public HXLDArray {
public:
  HXLDModParaArray(void) : HXLDArray() {}
  HXLDModParaArray(Hkey *key, Hlong num);
  HXLDModParaArray(const Hobject &obj);
  HXLDModParaArray(const HXLDModPara &mod_para);
  HXLDModParaArray(const HXLD &xld);
  HXLDModParaArray(const HXLDModParaArray &arr);
  HXLDModParaArray(const HXLDArray &arr);
  ~HXLDModParaArray(void) {}

  HXLDModParaArray &operator= (const HXLDModParaArray &arr);
  HXLDModParaArray &operator= (const HXLDArray &arr);

  // Tools
  virtual const char *HClassName(void) const;
  virtual const char *ClassName(void) const;
  virtual const char *InstClassName(void) const;
  virtual INT4        ClassDBID(void) const {return XLD_MOD_PARALLEL_ID;}
  virtual Hkey        Key(Hlong i) const {return array[i].Key();}
  virtual Hobject     ElemId(Hlong i) const {return array[i].Id();}

  // Access and Manipulation
  HXLDModPara  const &operator[] (Hlong index) const;
  HXLDModPara        &operator[] (Hlong index);
  HXLDModParaArray    operator() (Hlong min, Hlong max) const;
  HXLDModParaArray   &Append(const HXLDModPara &mod_para);
  HXLDModParaArray   &Append(const HXLD &xld);
  HXLDModParaArray   &Append(const HXLDModParaArray &mod_para);
  HXLDModParaArray   &Append(const HXLDArray &xlds);
  virtual void        SetKeys(Hkey *key, Hlong num);
  virtual void        SetKeys(Hkey *key, Hlong num, Herror *err);
  void                CopyHXLDModParaArray(const HXLDModParaArray &in);
  void                CopyHXLDArray(const HXLDArray &in);

private:
  void NewLength(Hlong new_num, Hlong old_num);

  // Class Functions

public:
};

}

#endif
