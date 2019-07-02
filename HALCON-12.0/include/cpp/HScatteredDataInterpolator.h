/*****************************************************************************
 * HScatteredDataInterpolator.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HScatteredDataInterpolator
 *
 * (c) 2011-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 * $
 * $
 *
 */

#ifndef H_SCATTERED_DATA_INTERPOLATOR_H
#define H_SCATTERED_DATA_INTERPOLATOR_H


#include "HCPPToolRef.h"


namespace Halcon {


class LIntExport HScatteredDataInterpolator: public HToolBase 
{
public:

  // Tool-specific functional class constructors
  
  HScatteredDataInterpolator(
      const HTuple &Method, 
      const HTuple &Row, const HTuple &Column, const HTuple &Value, 
      const HTuple &GenParamNames, const HTuple &GenParamValues); 

  HScatteredDataInterpolator(
      const char *Method, 
      const HTuple &Row, const HTuple &Column, const HTuple &Value, 
      const HTuple &GenParamNames, const HTuple &GenParamValues); 

  // Common tool class management functionality

  HScatteredDataInterpolator();
  HScatteredDataInterpolator(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Interpolation of scattered data using a scattered data interpolator.
  virtual HTuple InterpolateScatteredData(const Halcon::HTuple &Row, const Halcon::HTuple &Column) const;
  // Interpolation of scattered data using a scattered data interpolator.
  virtual HTuple InterpolateScatteredData(double Row, double Column) const;
  // Creates an interpolator for the interpolation of scattered data.
  virtual void CreateScatteredDataInterpolator(const Halcon::HTuple &Method, const Halcon::HTuple &Rows, const Halcon::HTuple &Columns, const Halcon::HTuple &Values, const Halcon::HTuple &GenParamNames, const Halcon::HTuple &GenParamValues);
};

}

#endif
