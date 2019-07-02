/*****************************************************************************
 * HIterator.h
 ***************************************************************************** 
 *
 * Project:     Halcon/C++
 * Description: Iterators for images, regions etc.
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */


#ifndef ITERATOR_H
#define ITERATOR_H


namespace Halcon {


/****************************************************************************/
/*                          HBorderTreatment                                */
/****************************************************************************/
// Art der Randbehandlung
enum HBorderTreatment { MirrorVal, ContinueVal, ConstVal };



/****************************************************************************/
/*                               HIterator                                  */
/****************************************************************************/
class LIntExport HIterator: public HRootObject {
public:
  virtual ~HIterator(void);
  
  virtual const char *ClassName(void) const = 0;
};


/****************************************************************************/
/*                              HAbstractImageIterator                      */
/****************************************************************************/
class LIntExport HAbstractImageIterator: public HIterator {
public:
  virtual ~HAbstractImageIterator(void);
  
  virtual const char *ClassName(void) const = 0;
};


/****************************************************************************/
/*                              HAbstractRegionIterator                     */
/****************************************************************************/
class LIntExport HAbstractRegionIterator: public HIterator {
public:
  virtual ~HAbstractRegionIterator(void);
  
  virtual const char *ClassName(void) const = 0;
};


/****************************************************************************/
/*                              HRegionIterator                             */
/****************************************************************************/
class LIntExport HRegionIterator: public HAbstractRegionIterator {
public:
  virtual ~HRegionIterator(void);
  
  virtual const char *ClassName(void) const;
};



/****************************************************************************/
/*                              HImageIterator                              */
/****************************************************************************/
class LIntExport HImageIterator: public HAbstractImageIterator {
public:
  HImageIterator(void);
  HImageIterator(const HImage &image, const HRegion &reg, 
                 int x1, int y1, int x2, int y2,
                 int border_treatment = MirrorVal, double val = 0.0);
  HImageIterator(const HImage &image,  const HRegion &reg, 
                 int width = 0, int height = 0,
                 int border_treatment = MirrorVal, double val = 0.0);
  HImageIterator(const HImage &image, 
                 int x1, int y1, int x2, int y2,
                 int border_treatment = MirrorVal, double val = 0.0);
  HImageIterator(const HImage &image, 
                 int width = 0, int height = 0,
                 int border_treatment = MirrorVal, double val = 0.0);
  HImageIterator(const HImageIterator &it);
  ~HImageIterator(void);
  HImageIterator &operator = (const HImageIterator &it);
  
  Hlong operator () (int RelX, int RelY) const
  { if (is_inner) return coord + Halcon::HLinearCoord(RelX,RelY,width);
    else return BorderOffset(RelX,RelY); }
  Hlong LinCoor(void) const { return coord; }
  Hlong X(void) const { return x; }
  Hlong Y(void) const { return y; }
  operator Hlong(void) const { return coord; }
  
  HImageIterator & operator ++ (void)
  { x++; if (++coord >= last_coord) PrepNextChord(); return *this; }
  HBool Continue(void) const { return more_points; }
  HBool IsInner(void) const { return is_inner; }
  HRLRegion InnerDomain(void) const { return inner; }
  HRLRegion BorderDomain(void) const { return border; }
  
  virtual const char *ClassName(void) const;
private:
  int       width,height;   // Bildgroesse 
  int       x1,y1,x2,y2;    // Randbereich
  HRLRegion  inner;          // Region voll innerhalb
  HRLRegion  border;         // Region mit Randbehandlung
  HBool      is_inner;       // es wird gerade der 'inner' abgearbeitet
  Hlong      chord_index;    // Sehnenindex in 'inner' oder 'border'
  HDChord    chord;          // aktuelle Sehne
  Hlong      last_coord;     // letzte lineare Koordinate in aktuelle Sehne
  Hlong      coord;          // lineare Koordinate im Bild
  int       x,y;            // aktuelle Koordinate in (x,y)
  HBool      more_points;    // noch Punkt zu bearbeiten
  int       b_treatment;    // Art der Randbehandlung
  double    val;            // bei konstanter Fortsetzung
  
  void NextChord(void);
  void PrepNextChord(void);
  Hlong BorderOffset(int RelX, int RelY) const;
  void Copy(const HImageIterator *in, HImageIterator *out) const;
  void Reset(void);
  
  void Create(const HImage &image, const HRegion &reg,
              int x1, int y1, int x2, int y2,
              int border_treatment, double Val);
  void InitChord(void);
};


}


#endif
