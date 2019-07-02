/*****************************************************************************
 * HDRegion.h
 ***************************************************************************** 
 *
 * Project:     Halcon/C++
 * Description: Types for regions
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */


#ifndef HDREGION_H
#define HDREGION_H


namespace Halcon {


/****************************************************************************/
/*                          HAbstractRegion                                 */
/****************************************************************************/
class LIntExport HAbstractRegion: public HRootObject {
public:
  virtual HAbstractRegion *CopyAbstractRegion(void) const = 0;      // Erzeuge eine Kopie
  virtual HAbstractRegion *NewEmpty(void) const = 0;  // Erzeuge analoge leere Kopie
  virtual HRectangle1 BoundingBox(void) const = 0;          // Umschl. Rechteck
  virtual HBool In(const HDPoint2D &p) const = 0;         // Punkt enthalten
  //virtual void Insert(const HDPoint2D &p) = 0;           // Punkt einfuegen
  //virtual void Delete(const HDPoint2D &p) = 0;           // Punkt loeschen
  virtual HBool IsEmpty(void) const = 0;
  virtual ~HAbstractRegion(void);
  virtual void Display(const HWindow &w) const = 0;
  virtual const char *ClassName(void) const = 0;
    
  virtual HAbstractRegion *ToRLRegion(void) const = 0;
  //virtual HAbstractRegion *ToBitRegion(void) const = 0;
  //virtual HAbstractRegion *ToByteRegion(void) const = 0;
  //virtual HAbstractRegion *ToQuadRegion(void) const = 0;
  virtual HAbstractRegion *ToHRegion(void) const = 0;
  /*
  virtual HAbstractRegion *difference(const HAbstractRegion *Sub) const;
  virtual HBool equal(const HAbstractRegion *comp) const;
  virtual HBool subseteq(const HAbstractRegion *comp) const;
  virtual HAbstractRegion *move(const HDPoint2D &p) const;
  virtual HAbstractRegion *line_ext(int add) const;
  virtual HAbstractRegion *line_mink_add(HCoord add_row, HCoord add_cb, HCoord add_ce) const;
  */
private:
};






/****************************************************************************/
/*                          HRepRegion                                      */
/****************************************************************************/
class LIntExport HRepRegion: public HRootObject {
  friend class HDRegion;
public:
  HRepRegion(const HAbstractRegion *in);
  HRepRegion(const HRepRegion *in);
  ~HRepRegion(void);
  const char *ClassName(void) const { return "HRepRegion"; }
private:
  const HAbstractRegion  *reg;    // Regionendaten
  int                   count;   // Anzahl Verwendungen
  
  HRepRegion(HRepRegion &in);              // keine Kopien
  HRepRegion operator = (HRepRegion &in);  // keine Kopien  
};





/****************************************************************************/
/*                           HDRegion                                       */
/****************************************************************************/
class LIntExport HDRegion: public HDiscreteObject {
public:
  HDRegion(void): reg(0) {}
  HDRegion(const HAbstractRegion *in);
  HDRegion(const HRLRegion &Reg);
  HDRegion(const HRegion &Reg);
  HDRegion(const HDRegion &Reg);
  ~HDRegion(void);
  HDRegion operator = (const HDRegion &Reg);
  void Modify(void);

  operator HAbstractRegion* (void);
  HDRegion Empty(void) { return HDRegion(Reg()->NewEmpty()); }
  HDRegion Full(void) { HDRegion r(Reg()->NewEmpty()); r.Compl(); return r; }
  HRectangle1 BoundingBox(void) const { return reg->reg->BoundingBox(); }
  HBool In(const HDPoint2D &p) const
  { return IsComplement() ? !reg->reg->In(p) : reg->reg->In(p); }
  //void Insert(const HDPoint2D &p)
  //{ if (IsComplement()) Reg()->Delete(p); else Reg()->Insert(p); }
  //void Delete(const HDPoint2D &p)
  //{ if (IsComplement()) Reg()->Insert(p); else Reg()->Delete(p); }
  void Display(const HWindow &w) const
  { reg->reg->Display(w); }
  void    Transform(const HAffineTrans &transform);
  const char   *ClassName(void) const { return "HDRegion"; }
  Hlong    NumPoints(void) const { return 0; }  // tbs 
  
  /*
  // Vordefiniert
  HDRegion operator ~ (void)
  { HDRegion r = HDRegion(*this); r.Modify(); r.Compl(); return r; }
  HDRegion Difference(const HDRegion &r) const;
  HDRegion operator / (const HDRegion &sub)
  { return Difference(sub); }
  HDRegion operator /= (const HDRegion &reg)
  { return Difference(reg); }
  HBool operator != (const HDRegion &in) const 
    { return reg->reg->equal(in.reg->reg); }
  HBool operator == (const HDRegion &in) const 
    { return !(*this == in); }
  HBool operator >= (const HDRegion &in) const
    { return in.reg->reg->subseteq(reg->reg); }
  HBool operator <= (const HDRegion &in) const
    { return reg->reg->subseteq(in.reg->reg); }
    HDRegion Move(const HDPoint2D &p) const
  { HDRegion r = HDRegion(reg->reg->move(p)); 
    if (IsComplement()) r.Compl(); return r; }
    HDRegion operator + (const HDPoint2D &p) { return Move(p); }
*/  
private:
  // Regionendaten
  HRepRegion  *reg;    // Regionendaten mit Zaehler
  HAbstractRegion *Reg() { return (HAbstractRegion*)reg->reg; }
  // Verwaltung der Negation
  HBool   is_compl;
  HBool   IsComplement(void) const { return is_compl; }
  void   Compl(void) { is_compl = !is_compl; }
  HBinPixVal Access(HBinPixVal v) const { if (is_compl) return(~v); else return(v); }  
};



/****************************************************************************/
/*                            HDRegionArray                                 */
/****************************************************************************/
class LIntExport HDRegionArray: public HBaseArray {
public:
  HDRegionArray(void);
  HDRegionArray(const HDRegion &reg);
  HDRegionArray(const HDRegionArray &arr);

  ~HDRegionArray(void);
  HDRegionArray & operator = (const HDRegionArray &arr);
  HDRegion &operator [] (Hlong index);
  HDRegionArray &Append(HDRegion &reg);
  const char *ClassName(void) const { return "HDRegionArray"; }

private:
   HDRegion  *array;
  void      NewLength(Hlong new_num, Hlong old_num);
  void      CopyRegion2DArray(const HDRegionArray *in,HDRegionArray *out);
};


}


#endif
