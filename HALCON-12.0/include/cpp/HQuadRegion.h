/*****************************************************************************
 * HQuadRegion.h
 ***************************************************************************** 
 *
 * Project:     Halcon/C++
 * Description: Regions as Quad-Trees displayed
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */


#ifndef HQUAD_REGION_H
#define HQUAD_REGION_H


namespace Halcon {


/****************************************************************************/
/*                                QuadNode                                  */
/****************************************************************************/

#define H_NO_SON    4


class LIntExport QuadNode {
protected:
  static unsigned char num_sons[16]; // partial Sons == Anzahl Pointer
  static unsigned char index_sons[16][4];
  static unsigned char index_son[16];  
  unsigned char    mark;    // Art der Nachfolger
  QuadNode         *s0, *s1, *s2, *s3;
public:
  QuadNode(HPixValues m0, HPixValues m1, HPixValues m2, HPixValues m3);
  QuadNode(HPixValues m0, HPixValues m1, HPixValues m2, HPixValues m3,
           QuadNode *n0, QuadNode *n1, QuadNode *n2, QuadNode *n3);
  QuadNode(void): mark(0), s0(0), s1(0), s2(0), s3(0) {}
  HPixValues Mode(int index) const;
  QuadNode* Son(int index) const;
};




/****************************************************************************/
/*                                HQuadTree                                 */
/****************************************************************************/

class LIntExport HQuadTree: public HAbstractRegion {
public:
  virtual HRectangle1 BoundingBox(void) const;
  virtual HAbstractRegion* CopyAbstractRegion(void) const;
  virtual void Display(const HWindow &w) const;
  virtual HBool IsEmpty(void) const;
  virtual HAbstractRegion* NewEmpty(void) const;
  virtual HAbstractRegion* ToHRegion(void) const;
  virtual HAbstractRegion* ToRLRegion(void) const;
  virtual const char* ClassName(void) const;
  HQuadTree(QuadNode *Root, HPixValues Mode, int Width, int Height, int Level):
    root(Root), mode(Mode), width(Width), height(Height), level(Level) {}
    HQuadTree(unsigned char *ip, int width, int height);
    HQuadTree(const HQuadTree &in);
  ~HQuadTree(void);
  HBool In(const HDPoint2D &p) const { return True; }
  void ToImage(unsigned char **image, int *width, int *height);
  HQuadTree Union(const HQuadTree &add);
  HQuadTree Intersection(const HQuadTree &add);
private:
  QuadNode   *root;   // Wurzel des Baumes
   HPixValues  mode;    // Modus der Wurzel
  int        level;   // Anzahl Ebene des Baumes
  int        width;   // Horizontale Ausdehnuung
  int        height;  // Vertikale Ausdehnung

  void     DelQuadTree(QuadNode *in);
  QuadNode *CopyQuadTree(const QuadNode *in);
  QuadNode *QuadTreePart(unsigned char *ip, int width, int height, 
                         int row, int col,
                         int level, HPixValues *mode);
  void ToImagePart(QuadNode *in, HPixValues mode, unsigned char *image,
                   int row, int col, int length, int width, int height);
  HBool InPart(QuadNode *in, HPixValues mode, const HPoint &test,
              int row, int col, int length) const;
  void QuadTreeUnion(QuadNode *root1, HPixValues mode1,
                     QuadNode *root2, HPixValues mode2,
                     QuadNode **root_res, HPixValues *mode_res);
  void QuadTreeInters(QuadNode *root1, HPixValues mode1,
                      QuadNode *root2, HPixValues mode2,
                      QuadNode **root_res, HPixValues *mode_res);  
};


}


#endif
