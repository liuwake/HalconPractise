/*****************************************************************************
 * HConvol.h
 ***************************************************************************** 
 *
 * Project:     Halcon/C++
 * Description: Dates for convolution of images
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */


#ifndef CONVOL_H
#define CONVOL_H


namespace Halcon {


/****************************************************************************/
/*                            HConvolMask                                   */
/****************************************************************************/
class LIntExport HConvolMask: public HRootObject {
public:
  virtual ~HConvolMask(void);
  virtual const char *ClassName(void) const = 0;
};


/****************************************************************************/
/*                            HConvolFourier                                */
/****************************************************************************/
class LIntExport HConvolFourier: public HConvolMask {
public:
  virtual const char *ClassName(void) const = 0;
};


/****************************************************************************/
/*                            HConvolSFourier                               */
/****************************************************************************/
class LIntExport HConvolSFourier: public HConvolFourier {
public:
  const char *ClassName(void) const { return "HConvolSFourier"; };
};


/****************************************************************************/
/*                            HConvolGabor                                  */
/****************************************************************************/
class LIntExport HConvolGabor: public HConvolFourier {
public:
  const char *ClassName(void) const { return "HConvolGabor"; };
};


/****************************************************************************/
/*                            HConvolSimple                                 */
/****************************************************************************/
class LIntExport HConvolSimple: public HConvolMask {
public:
  virtual ~HConvolSimple(void);
  virtual int Width(void) const = 0;
  virtual int Height(void) const = 0;
  virtual void SetValueRel(int x, int y, double value) = 0;
  virtual void SetValueAbs(int x, int y, double value) = 0;
  virtual double GetValueRel(int x, int y) const = 0;
  virtual double GetValueAbs(int x, int y) const = 0;
  virtual const char *ClassName(void) const = 0;
protected:
  void TestCoordRel(int x, int y) const;
  void TestCoordAbs(int x, int y) const;
  void TestWH(int width, int height) const;
};


/****************************************************************************/
/*                            HConvolInt                                    */
/****************************************************************************/
class LIntExport HConvolInt: public HConvolSimple {
public:
  HConvolInt(void);
  HConvolInt(int width, int height);
  HConvolInt(int width, int height, int div, const char *values);
  HConvolInt(int width, int height, const char *values);
  HConvolInt(int width, int height, int div, int *values);
  HConvolInt(int width, int height, int *values);
  HConvolInt(const HConvolInt &mask);
  virtual ~HConvolInt(void);
  HConvolInt &operator = (const HConvolInt &mask);
  
  HConvolInt Resize(int width, int height);
  HConvolInt SubMask(int x, int y, int width, int height, int div);
  HConvolInt operator * (const HConvolInt &mask);
  HConvolInt operator * (int mult);

  int Width(void) const;
  int Height(void) const;
  Hlong Div(void) const;
  Hlong &Div(void);
  
  double GetValueAbs(int x, int y) const;
  // Ursprung: linker oberer Punkt der Maske
  double GetValueRel(int x, int y) const;
  // Ursprung: Mittelpunkt der Maske 
  
  void SetValueRel(int x, int y, double value);
  void SetValueAbs(int x, int y, double value);
  int &operator()(int x, int y);
  
  const char *ClassName(void) const { return "HConvolInt"; };
private:
  int   width, height;
  Hlong  div;
  int  *values;
};


/****************************************************************************/
/*                            HConvolFloat                                  */
/****************************************************************************/
class LIntExport HConvolFloat: public HConvolSimple {
public:
  HConvolFloat(int width, int height, const char *values);
  HConvolFloat(int width, int height, double *values);
  const char *ClassName(void) const { return "HConvolFloat"; };
};


}


#endif
