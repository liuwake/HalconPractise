/*****************************************************************************
 * HByteRegion.h
 ***************************************************************************** 
 *
 * Project:     Halcon/C++
 * Description: Display regions as byte-images 
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */


#ifndef BYTE_REGION_H
#define BYTE_REGION_H


namespace Halcon {


/****************************************************************************/
/*                            RegByteImage                                  */
/****************************************************************************/
class LIntExport RegByteImage {
private:
  HDCoord     width,height;    // Ausdehnung in y und x
  HDPoint2D   offs;            // Negierter Ursprung
  HBinPixVal  **rows;          // Bildmatrix
  void AllocMem(RegByteImage *image);
  void Copy(RegByteImage *in, const RegByteImage *out);
  void MoveRows(RegByteImage *image, const HDPoint2D &diff);
  void FreeData(void);
public:
  RegByteImage(int w=0, int h=0);
  RegByteImage(const HRectangle1 &win);
  RegByteImage(RegByteImage *i);
  ~RegByteImage(void) { Destruct(); }
  RegByteImage operator = (const RegByteImage &in);
  HBinPixVal &operator [] (const HDPoint2D &p) { return rows[p.Y()][p.X()]; }
  HDPoint2D UpperLeft(void) const { return offs; }
  HDPoint2D LowerRight(void) const
  { return HDPoint2D(width + offs.X() - 1,height + offs.Y() - 1); }
  HRectangle1 BoundingBox(void) const { return HRectangle1(UpperLeft(),LowerRight()); }
  void Move(const HDPoint2D &p);
  void Expand(const HRectangle1 &new_win);
  HBool Inside(const HDPoint2D &p) const { return UpperLeft().Inside(p,LowerRight()); }
  HRectangle1 MinBoundingBox(void);
  void Shrink(void);
  void Destruct(void);
  HBool IsEmpty(void) const;
}; 


/****************************************************************************/
/*                         HByteRegion                                      */
/****************************************************************************/
class LIntExport HByteRegion: public HAbstractRegion {
private:
  RegByteImage image;
  void InsertBasePoints(const HAbstractRegion *base);
public:
  HByteRegion(int w=0, int h=0): image(w,h) {}
  HByteRegion(const HRectangle1 &win): image(win) {}
  HByteRegion(const HAbstractRegion *base);
  HByteRegion(const HByteRegion &r): HAbstractRegion(r), image(r.image) {}

  // virtuelle Basisoperationen aus HAbstractRegion
  HAbstractRegion *CopyAbstractRegion(void) const { return new HByteRegion(*this); }
  HAbstractRegion *NewEmpty(void) const { return new HByteRegion(image.BoundingBox()); }
  HRectangle1 BoundingBox(void) const
  { return HRectangle1(image.UpperLeft(),image.LowerRight()); }
  HBool In(const HDPoint2D &p) const
  { return (image.Inside(p)) ? ((*(RegByteImage*)&image)[p] == (HBinPixVal)FOREGROUND) : FALSE; }
  void Insert(const HDPoint2D &p)
  { if (image.Inside(p)) image[p] = FOREGROUND; else FALSE; }
  void Delete(const HDPoint2D &p)
  { if (image.Inside(p)) image[p] = BACKGROUND; else FALSE; }
  HBool IsEmpty(void) const;
  const char *ClassName(void) const;
  void    Display(const HWindow &w) const;
  HAbstractRegion *ToRLRegion(void) const;
  HAbstractRegion *ToHRegion(void) const;
};


}


#endif
