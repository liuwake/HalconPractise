/*****************************************************************************
 * HDistribution.h
 ***************************************************************************** 
 *
 * Project:     Halcon/C++
 * Description: Dates for distribution of gray tones
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */


#ifndef DISTRIBUTION_H
#define DISTRIBUTION_H


namespace Halcon {


/****************************************************************************/
/*                            HDistribution                                 */
/****************************************************************************/
class LIntExport HDistribution: public HRootObject {
public:
  virtual ~HDistribution(void);
  virtual const char   * ClassName(void) const = 0;
  virtual void     Display(void) const = 0;
  virtual int      MinIndex(void) const = 0;
  virtual int      MaxIndex(void) const = 0;
  virtual int      HMin(void) const = 0;   // minimaler Index mit Wert != 0
  //virtual int      HMax(void) const = 0;   // maximaler Index mit Wert != 0
  virtual double   GetVal(int index) const = 0;
  virtual void     SetVal(int index, double val) const = 0;
  virtual double   Sum(void) const = 0; // Summer ueber alle Werte
  virtual void     Gauss(double sigma);
};



/****************************************************************************/
/*                            HNoiseDistribution                            */
/****************************************************************************/
class LIntExport HNoiseDistribution: public HDistribution {
public:
  virtual const char    * ClassName(void) const = 0;
  virtual void      Display(void) const = 0;
  virtual int       HMin(void) const = 0;   // minimaler Index mit Wert != 0
  virtual int       HMax(void) const = 0;   // maximaler Index mit Wert != 0
  virtual double    GetVal(int index) const = 0;
  virtual void      SetVal(int index, double val) const = 0;
  virtual double    Sum(void) const = 0; // Summer ueber alle Werte
  virtual void      Gauss(double sigma);
  
  virtual int MinIndex(void) const;
  virtual int MaxIndex(void) const;
};



/****************************************************************************/
/*                            HAbsDistribution                              */
/****************************************************************************/
class LIntExport HAbsDistribution: public HNoiseDistribution {
public:
  HAbsDistribution(void);
  HAbsDistribution(Hlong *values);
  HAbsDistribution(const HAbsDistribution &lut);
  HAbsDistribution &operator = (const HAbsDistribution &lut);
  
  Hlong  const & operator [] (int index) const  { return distr[index]; } 
  Hlong        & operator [] (int index)  { return distr[index]; } 
  
  int    HMin(void) const;
  int    HMax(void) const;
  void   Display(void) const { };
  double Sum(void) const;
  const char  *ClassName(void) const {return "HAbsDistribution"; }
  double GetVal(int index) const { return (double)distr[index]; }
  void   SetVal(int index, double val) const { distr[index] = (Hlong)val; }
private:
  Hlong  distr_[256*2+1];
  Hlong  *distr;
};



/****************************************************************************/
/*                            HRelDistribution                              */
/****************************************************************************/
class LIntExport HRelDistribution: public HNoiseDistribution {
public:
  HRelDistribution(void);
  HRelDistribution(double *values);
  HRelDistribution(const HRelDistribution &lut);
  HRelDistribution(const HAbsDistribution &lut);
  HRelDistribution &operator = (const HRelDistribution &lut);
  
  double  const & operator [] (int index) const  { return distr[index]; } 
  double        & operator [] (int index)  { return distr[index]; } 
  
  int    HMin(void) const;
  int    HMax(void) const;
  void   Display(void) const;
  double Sum(void) const;
  const char  *ClassName(void) const {return "HRelDistribution"; }
  double GetVal(int index) const { return distr[index]; }
  void   SetVal(int index, double val) const { distr[index] = val; }
private:
  double  distr_[256*2+1];
  double  *distr;
};





/****************************************************************************/
/*                            HByteHistogram                                */
/****************************************************************************/
class LIntExport HByteHistogram: public HDistribution {
public:
  virtual const char       *ClassName(void) const = 0;
  virtual void        Display(void) const = 0;
  virtual int         HMin(void) const = 0;   // minimaler Index mit Wert != 0
  virtual int         HMax(void) const = 0;   // maximaler Index mit Wert != 0
  virtual double      GetVal(int index) const = 0;
  virtual void        SetVal(int index, double val) const = 0;
  virtual double      Sum(void) const = 0; // Summer ueber alle Werte
  virtual void        Gauss(double sigma);
  virtual HThresholds Minima(double sigma);
          int         MinIndex(void) const { return 0; }
          int         MaxIndex(void) const { return 255; }
};




/****************************************************************************/
/*                            HAbsHistogram                                 */
/****************************************************************************/
class LIntExport HAbsHistogram: public HByteHistogram {
public:
  virtual void Display(void) const = 0;
  virtual double GetVal(int index) const = 0;
  virtual int HMax(void) const = 0;
  virtual int HMin(void) const = 0;
  virtual void SetVal(int index, double val) const = 0;
  virtual double Sum(void) const = 0;
  Hlong  const & operator [] (int index) const  { return histo[index]; } 
  Hlong        & operator [] (int index)  { return histo[index]; } 
  const char *ClassName(void) const;
private:
  Hlong   histo[256];
};


/****************************************************************************/
/*                            HRelHistogram                                 */
/****************************************************************************/
class LIntExport HRelHistogram: public HByteHistogram {
public:
  virtual void Display(void) const = 0;
  virtual double GetVal(int index) const = 0;
  virtual int HMax(void) const = 0;
  virtual int HMin(void) const = 0;
  virtual void SetVal(int index, double val) const = 0;
  virtual double Sum(void) const = 0;
  const char *ClassName(void) const { return "HRelHistogram"; }
  double  const & operator [] (int index) const  { return histo[index]; } 
  double        & operator [] (int index)  { return histo[index]; } 
private:
  double   histo[256];
};


}


#endif
