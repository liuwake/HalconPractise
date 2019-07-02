/*****************************************************************************
 * HXLDParaArray.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HXLDParaArray
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef XLD_PARA_ARRAY_H
#define XLD_PARA_ARRAY_H


namespace Halcon {


/****************************************************************************/
/*                               HXLDParaArray                              */
/****************************************************************************/

class LIntExport HXLDParaArray: public HXLDArray {
public:
  HXLDParaArray(void) : HXLDArray() {}
  HXLDParaArray(Hkey *key, Hlong num);
  HXLDParaArray(const Hobject &obj);
  HXLDParaArray(const HXLDPara &para);
  HXLDParaArray(const HXLD &xld);
  HXLDParaArray(const HXLDParaArray &arr);
  HXLDParaArray(const HXLDArray &arr);
  ~HXLDParaArray(void) {}

  HXLDParaArray &operator= (const HXLDParaArray &arr);
  HXLDParaArray &operator= (const HXLDArray &arr);

  // Tools
  virtual const char *HClassName(void) const;
  virtual const char *ClassName(void) const;
  virtual const char *InstClassName(void) const;
  virtual INT4        ClassDBID(void) const {return XLD_PARALLEL_ID;}
  virtual Hkey        Key(Hlong i) const {return array[i].Key();}
  virtual Hobject     ElemId(Hlong i) const {return array[i].Id();}

  // Access and Manipulation
  HXLDPara  const  &operator[] (Hlong index) const;
  HXLDPara         &operator[] (Hlong index);
  HXLDParaArray     operator() (Hlong min, Hlong max) const;
  HXLDParaArray    &Append(const HXLDPara &para);
  HXLDParaArray    &Append(const HXLD &xld);
  HXLDParaArray    &Append(const HXLDParaArray &paras);
  HXLDParaArray    &Append(const HXLDArray &xlds);
  virtual void      SetKeys(Hkey *key, Hlong num);
  virtual void      SetKeys(Hkey *key, Hlong num, Herror *err);
  void              CopyHXLDParaArray(const HXLDParaArray &in);
  void              CopyHXLDArray(const HXLDArray &in);

private:
  void NewLength(Hlong new_num, Hlong old_num);

  // Class Functions

public:
  // Extract parallel XLD polygons enclosing a homogeneous area.
  virtual HXLDModParaArray ModParallelsXld(const HImage &Image, HXLDExtParaArray *ExtParallels, const Halcon::HTuple &Quality, const Halcon::HTuple &MinGray, const Halcon::HTuple &MaxGray, const Halcon::HTuple &MaxStandard) const;
  // Extract parallel XLD polygons enclosing a homogeneous area.
  virtual HXLDModParaArray ModParallelsXld(const HImage &Image, HXLDExtParaArray *ExtParallels, double Quality, Hlong MinGray, Hlong MaxGray, double MaxStandard) const;
  // Return information about the gray values of the area enclosed by XLD
  // parallels.
  virtual double InfoParallelsXld(const HImage &Image, Halcon::HTuple *QualityMax, Halcon::HTuple *GrayMin, Halcon::HTuple *GrayMax, Halcon::HTuple *StandardMin, Halcon::HTuple *StandardMax) const;
};

}

#endif
