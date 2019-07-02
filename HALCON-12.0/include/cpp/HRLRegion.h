/*****************************************************************************
 * HRLRegion.h
 ***************************************************************************** 
 *
 * Project:     Halcon/C++
 * Description: Regions as run length encoding displayed  
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */


#ifndef HRL_REGION_H
#define HRL_REGION_H


namespace Halcon {


/****************************************************************************/
/*                           RunLength                                      */
/****************************************************************************/
class LIntExport RunLength {

private: // vorne wegen inline
  void  Incr(Hlong add);
  void  PrepInsert(void) { if (num >= num_max) Incr(1); }
  void  Sort(void);
  void  Pack(void);
  void  Merge(const RunLength &in);
  HBool  InclPoint(const HDPoint2D &p, Hlong *index) const;    

public:
  RunLength(void): num(0), num_max(0), rl(0), sorted(TRUE) {}
  RunLength(const HDChord &line);
  RunLength(const RunLength &reg);
  RunLength(const HRegion &reg);
  RunLength(Hlong num);
  ~RunLength(void);
  RunLength &operator = (const RunLength &in);
  
  void Difference(const RunLength &subtrahend);
  void Union(const RunLength &in);
  void Intersection(const RunLength &in);
  void Insert(const HDChord &line);
  void Append(const HDChord &chord) 
  { PrepInsert(); 
    rl[num++] = chord; 
  }
  void Insert(const HDPoint2D &p);
  void Insert(const RunLength &r);
  HBool In(const HDPoint2D &p) const;
  void Delete(const HDPoint2D &p);
  HRectangle1 BoundingBox(void) const;
  HBool Equal(const RunLength &comp) const;
  HBool IsEmpty(void) const { return num == 0; }
  Hlong Num(void) const { return num; }
  HDChord & operator [] (Hlong i);
  HDChord const & operator [] (Hlong i) const
  { if ((i < 0) || (i >= num))
    H_EXCEPTION("HDChord const & operator [] (Hlong i) const",
                "index out of range")
    return rl[i]; }
  void Empty(void);
private:
  Hlong  num;           // Anzahl Sehnen
  Hlong  num_max;       // vorhandener Speicherplatz fuer Sehnen
  HDChord *rl;          // Feld von Sehnen
  HBool  sorted;        // Ist rl sortiert ?
private:
  static float incr;   // Increment von max_num falls Ueberlauf
  static Hlong num_def; // Mindestanzahl von Linien einer Region  
};


/****************************************************************************/
/*                               HRLRegion                                  */
/****************************************************************************/
class LIntExport HRLRegion: public HAbstractRegion {
public:
  HRLRegion(void) {}
  HRLRegion(Hlong n): rl(n) {}
  HRLRegion(const HDChord &line): rl(line) {}
  HRLRegion(const HAbstractRegion *base);
  HRLRegion(const HRegion &reg) : rl(reg) {}
  HRLRegion(const HRLRegion &r): HAbstractRegion(r), rl(r.rl) {}
  HRLRegion &operator = (const HRLRegion &in);
  
  // Tools
  void      Append(const HDChord &line);
  void      Display(const HWindow &w) const;
  HDChord   &operator [] (Hlong i) { return rl[i]; }
  HDChord    operator [] (Hlong i) const { return rl[i]; }
  Hlong      Num(void) const { return rl.Num(); }
  const char     *ClassName(void) const;
  void      Empty(void) { rl.Empty(); }
  HRLRegion &operator /= (const HRLRegion &reg);
  HRLRegion &operator &= (const HRLRegion &reg);
  HRLRegion &operator |= (const HRLRegion &reg);
  HBool      operator == (const HRLRegion &reg);
  
  // virtuelle Basisoperationen aus HAbstractRegion
  HAbstractRegion *CopyAbstractRegion(void) const {
    return new HRLRegion(*this); }
  HAbstractRegion *NewEmpty(void) const { return new HRLRegion(); }
  HRectangle1     BoundingBox(void) const { return rl.BoundingBox(); }
  HBool           In(const HDPoint2D &p) const { return rl.In(p); }
  void           Insert(const HDPoint2D &p) { rl.Insert(p); }
  void           Delete(const HDPoint2D &p) { rl.Delete(p); }
  HBool           IsEmpty(void) const { return rl.IsEmpty(); }
  HAbstractRegion *ToRLRegion(void) const;
  HAbstractRegion *ToHRegion(void) const;
private:
  HRegion GenHRegion(void) const;
  RunLength  rl;  
};


}


#endif
