/*****************************************************************************
 * HRectangle.h
 ***************************************************************************** 
 *
 * Project:     Halcon/C++
 * Description: Rectangles
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */


#ifndef HRECTANGLE_H
#define HRECTANGLE_H


namespace Halcon {


/****************************************************************************/
/*                            HRectangle1                                   */
/****************************************************************************/
class LIntExport HRectangle1: public HSpatialObject {
private:
  HPoint2D  upper_left;
  HPoint2D  lower_right;
  HBool     empty;         // keine Flaeche und kein Schwerpunkt
public:
  HRectangle1(void);
  HRectangle1(const HPoint2D &upper_left, const HPoint2D &lower_right);
  HRectangle1(const HRectangle1 &rect);
  HRectangle1 & operator = (const HRectangle1 &rect);

  HPoint2D const  & UpperLeft(void) const;
  HPoint2D const  & LowerRight(void) const;
  HPoint2D          Center(void) const;
  HCoord            Width(void) const;
  HCoord            Height(void) const;
  HBool             IsEmpty(void) const;
  double            Area(void) const;

  HRectangle1 HMax(const HRectangle1 &w) const;
  HRectangle1 Intersection(const HRectangle1 &w) const;
  HBool             Overlaps(const HRectangle1 &w) const;
  HBool             Includes(const HPoint2D &point) const;

  HBool             Includes(const HLine2D &line) const;
  double            Distance(const HPoint2D &point) const;
  double            CenterDistance(const HPoint2D &point) const;

  HBool             Intersection(const HLine2D &line, HLine2D &clipping) const;
  double            Distance(const HLine2D &line) const;
  double            CenterDistance(const HLine2D &line) const;

  HRectangle1 operator & (const HRectangle1 &rect) const;
  HBool operator >= (const HRectangle1 &rect) const;
  HBool operator > (const HRectangle1 &rect) const;
  HBool operator <= (const HRectangle1 &rect) const;
  HBool operator < (const HRectangle1 &rect) const;
  HBool operator == (const HRectangle1 &rect) const;
  HBool operator != (const HRectangle1 &rect) const;

  void         Display(const HWindow &w) const;
  void         Transform(const HAffineTrans &transform);
  const char * ClassName(void) const { return "HRectangle1"; }
};


/****************************************************************************/
/*                            HRectangle2                                   */
/****************************************************************************/
class LIntExport HRectangle2: public HSpatialObject {
private:
  HPoint2D  center;
  double   phi;     
  double   ra,rb;
  HBool     empty;
public:
  HRectangle2(void): empty(TRUE) {};
  HRectangle2(const HPoint2D &Center, double Ra, double Rb, 
              double Phi =0.0):
              center(Center), phi(Phi), ra(Ra), rb(Rb), empty(FALSE) {};
  HRectangle2(const HRectangle2 &rect);
  HRectangle2 & operator = (const HRectangle2 &rect);

  HPoint2D Point1(void) const;
  HPoint2D Point2(void) const;
  HPoint2D Point3(void) const;
  HPoint2D Point4(void) const;

  HBool Overlaps(const HRectangle2 &w) const;
  HBool Includes(const HRectangle2 &w) const;
  HBool Includes(const HPoint2D &point) const;
  HBool Includes(const HLine2D &line) const;
  HBool IsEmpty(void) const { return empty; }

  double Distance(const HPoint2D &point) const;
  double CenterDistance(const HPoint2D &point) const;

  HBool Intersection(const HLine2D &line, HLine2D &clipping) const;
  double Distance(const HLine2D &line) const;
  double CenterDistance(const HLine2D &line) const;
  HPoint2D Center(void) const;

  double  Ra(void) const { return ra; }
  double  Rb(void) const { return rb; }
  double  Phi(void) const { return phi; }

  void Display(const HWindow &w) const;
  void Transform(const HAffineTrans &transform);
  const char *ClassName(void) const { return "HRectangle2"; }
};


}


#endif
