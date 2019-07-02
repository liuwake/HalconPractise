/*****************************************************************************
 * HPrimitives.h
 ***************************************************************************** 
 *
 * Project:     Halcon/libhalcon
 * Description: Geometric primitives (points, lines, contours, etc.)
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */


#ifndef HPRIMITIVES_H
#define HPRIMITIVES_H


namespace Halcon {


/****************************************************************************/
/*                            HDiscreteObject                               */
/****************************************************************************/
class LIntExport HDiscreteObject: public HRootObject {
public:
  virtual Hlong        NumPoints(void) const = 0;
  virtual void         Display(const HWindow &w) const = 0;
  virtual const char * ClassName(void) const = 0;
  virtual void         Transform(const HAffineTrans &transform) = 0;
};




/****************************************************************************/
/*                            HDPoint                                       */
/****************************************************************************/
class LIntExport HDPoint: public HDiscreteObject {
public:
  virtual HDCoord &X(void) = 0;
  virtual HDCoord &Y(void) = 0;
  virtual HDCoord &Z(void) = 0;
  virtual HDCoord X(void) const = 0;
  virtual HDCoord Y(void) const = 0;
  virtual HDCoord Z(void) const = 0;
  virtual HDCoord operator [] (int i) const = 0;
  virtual HBool operator == (const HDPoint &p) const;
  virtual HBool operator != (const HDPoint &p) const;
  virtual HDPoint & operator += (const HDPoint &p) = 0;
  virtual HDPoint & operator -= (const HDPoint &p) = 0;

  virtual double Distance(const HDPoint &point) const = 0;
  Hlong NumPoints(void) const { return 1; }
  virtual const char *ClassName(void) const = 0;
  virtual void Display(const HWindow &w) const = 0;
  virtual void Transform(const HAffineTrans &transform) = 0;
};


/****************************************************************************/
/*                            HDPoint2D                                     */
/****************************************************************************/
class LIntExport HDPoint2D: public HDPoint {
private:
  HDCoord    x, y;
public:
  HDPoint2D(HDCoord X=0, HDCoord Y=0): x(X), y(Y) {}
  HDPoint2D(const HDPoint2D &p): HDPoint(), x(p.x), y(p.y) {}
  HDPoint2D(const HDPoint &p): x(p.X()), y(p.Y()) {}
  HDPoint2D & operator = (const HDPoint2D &point)
    { x = point.x; y = point.y; return *this; }
  ~HDPoint2D(void) { x = 0; y = 0; }

  HDCoord &Y(void) { return y; }
  HDCoord &X(void) { return x; }
  HDCoord &Z(void) { H_EXCEPTION("HDCoord &Z(void)","illegal access");
                     return x; }
  HDCoord Y(void) const { return y; }
  HDCoord X(void) const { return x; }
  HDCoord Z(void) const { return 0; }
  HDCoord operator [] (int i) const;

  HBool operator == (const HDPoint2D &p) const
   { return ((x == p.x) && (y == p.y)); }
  HBool operator == (const HDPoint &p) const
   { return ((x == p.X()) && (y == p.Y())); }
  HBool operator != (const HDPoint2D &p) const
   { return ((y != p.y) || (x != p.x)); }
  HBool operator != (const HDPoint &p) const
   { return ((x != p.X()) || (y != p.Y())); }

  HDPoint2D operator - (void) const { return HDPoint2D(-x,-y); }
  HDPoint2D operator + (const HDPoint2D &add) const
   { return HDPoint2D(x+add.x, y+add.y); }
  HDPoint2D operator - (const HDPoint2D &sub) const
   { return HDPoint2D(x-sub.x, y-sub.y); }
  HDPoint2D operator ++ (void) { ++x; return *this; }

  HDPoint2D & operator += (const HDPoint2D &p)
   { x += p.x; y += p.y; return *this; }
  HDPoint2D & operator -= (const HDPoint2D &p)
   { x -= p.x; y -= p.y; return *this; }
  HDPoint & operator += (const HDPoint &p)
   { x += p.X(); y += p.Y(); return *this; }
  HDPoint & operator -= (const HDPoint &p)
   { x -= p.X(); y -= p.Y(); return *this; }

   HBool Inside(const HDPoint2D &pp, const HDPoint2D &lr) const
   { return (x <=  pp.x) && (y <= pp.y) &&
            (pp.x >= lr.x) && (pp.y >= lr.y); }
   HBool operator <= (const HDPoint2D &p) const
   { return (y < p.y) || ((y == p.y) && (x <= p.x)); }

  double Distance(const HDPoint &point) const;
  void Display(const HWindow &w) const;
  void Transform(const HAffineTrans &transform)
   { transform.Transform(*this); }
  const char *ClassName(void) const { return "HDPoint2D"; }
};


/****************************************************************************/
/*                            HDPoint3D                                      */
/****************************************************************************/
class LIntExport HDPoint3D: public HDPoint {
private:
  HDCoord    x, y, z;
public:
  HDPoint3D(HDCoord X=0, HDCoord Y=0, HDCoord Z=0): x(X), y(Y), z(Z) {}
  HDPoint3D(const HDPoint3D &p): HDPoint(), x(p.x), y(p.y), z(p.z) {}
  HDPoint3D(const HDPoint2D &p): x(p.X()), y(p.Y()), z(0) {}
  HDPoint3D(const HDPoint &p): x(p.X()), y(p.Y()), z(p.Z()) {}
  HDPoint3D & operator = (const HDPoint3D &point)
    { x = point.x; y = point.y; z = point.z; return *this; }
  ~HDPoint3D(void) { x = 0; y = 0; z = 0; }

  HDCoord &X(void) { return x; }
  HDCoord &Y(void) { return y; }
  HDCoord &Z(void) { return z; }
  HDCoord X(void) const { return x; }
  HDCoord Y(void) const { return y; }
  HDCoord Z(void) const { return z; }
  HDCoord operator [] (int i) const;
  
  HBool operator == (const HDPoint3D &p) const
   { return ((x == p.x) && (y == p.y) && (z == p.z)); }
  HBool operator == (const HDPoint &p) const
   { return ((x == p.X()) && (y == p.Y()) && (z == p.Z())); } 
  HBool operator != (const HDPoint3D &p) const
   { return ((x != p.x) || (y != p.y) || (z != p.z)); }
  HBool operator != (const HDPoint &p) const
   { return ((x != p.X()) || (y != p.Y()) || (z != p.Z())); } 

  HDPoint3D operator - (void) const { return HDPoint3D(-x,-y,-z); }
  HDPoint3D operator + (const HDPoint3D &add) const
   { return HDPoint3D(x+add.x,y+add.y,z+add.z); }
  HDPoint3D operator - (const HDPoint3D &sub) const
   { return HDPoint3D(x-sub.x,y-sub.y,z-sub.z); }
  
  HDPoint3D & operator += (const HDPoint3D &p)
   { x += p.x; y += p.y; z += p.z; return *this; }
  HDPoint & operator += (const HDPoint &p)
   { x += p.X(); y += p.Y(); z += p.Z(); return *this; }
  HDPoint3D & operator -= (const HDPoint3D &p)
   { x -= p.x; y -= p.y; z -= p.z; return *this; }
  HDPoint & operator -= (const HDPoint &p)
   { x -= p.X(); y -= p.Y(); z -= p.Z(); return *this; }

  double Distance(const HDPoint &point) const;
  void Display(const HWindow &w) const;
  void Transform(const HAffineTrans &transform)
   { transform.Transform(*this); }
  const char *ClassName(void) const { return "HDPoint3D"; }
};



/****************************************************************************/
/*                            HDVector                                      */
/****************************************************************************/
class LIntExport HDVector: public HDiscreteObject {
public:
  virtual HDCoord &X(void) = 0;
  virtual HDCoord &Y(void) = 0;
  virtual HDCoord &Z(void) = 0;
  virtual HDCoord X(void) const = 0;
  virtual HDCoord Y(void) const = 0;
  virtual HDCoord Z(void) const = 0;
  virtual HDCoord operator [] (int i) const = 0;
  virtual HBool operator == (const HDVector &p) const;
  virtual HBool operator != (const HDVector &p) const;
  virtual HDVector & operator += (const HDVector &p) = 0;
  virtual HDVector & operator -= (const HDVector &p) = 0;
  virtual Hlong operator * (const HDVector &mult) const;
  Hlong NumPoints(void) const { return 1; }
  virtual double Length(void) const = 0;
  virtual const char *ClassName(void) const = 0;
  virtual void Display(const HWindow &w) const = 0;
  virtual void Transform(const HAffineTrans &transform) = 0;
};


/****************************************************************************/
/*                            HDVector2D                                    */
/****************************************************************************/
class LIntExport HDVector2D: public HDVector {
private:
  HDCoord    x, y;
public:
  HDVector2D(HDCoord X=0, HDCoord Y=0): x(X), y(Y) {}
  HDVector2D(const HDVector2D &p): HDVector(), x(p.x), y(p.y) {}
  HDVector2D(const HDVector &p): x(p.X()), y(p.Y()) {}
  HDVector2D(const HDPoint &p): x(p.X()), y(p.Y()) {}
  HDVector2D & operator = (const HDVector2D &vector)
   { x = vector.x; y = vector.y; return *this; }
  ~HDVector2D(void) { x = 0; y = 0; }

  operator HDPoint2D(void) const { return HDPoint2D(x,y); }

  HDCoord &X(void) { return x; }
  HDCoord &Y(void) { return y; }
  HDCoord &Z(void) { H_EXCEPTION("HDCoord &Z(void)","illegal access");
                     return x; }
  HDCoord X(void) const { return x; }
  HDCoord Y(void) const { return y; }
  HDCoord Z(void) const { return 0; }
  HDCoord operator [] (int i) const
   { if (i==0) return x; else if (i==1) return y; else return 0; }

  HBool operator == (const HDVector2D &p) const
   { return ((x == p.x) && (y == p.y)); }
  HBool operator == (const HDVector &p) const
   { return ((x == p.X()) && (y == p.Y())); }
  HBool operator != (const HDVector2D &p) const
   { return ((y != p.y) || (x != p.x)); }
  HBool operator != (const HDVector &p) const
   { return ((x != p.X()) || (y != p.Y())); }

  HDVector2D operator - (void) const { return HDVector2D(-x,-y); }
  HDVector2D operator + (const HDVector2D &add) const
   { return HDVector2D(x+add.x, y+add.y); }
  HDVector2D operator - (const HDVector2D &sub)
   { return HDVector2D(x-sub.x, y-sub.y); }

  HDVector2D & operator += (const HDVector2D &p)
   { x += p.x; y += p.y; return *this; }
  HDVector2D & operator -= (const HDVector2D &p)
   { x -= p.x; y -= p.y; return *this; }
  HDVector & operator += (const HDVector &p)
   { x += p.X(); y += p.Y(); return *this; }
  HDVector & operator -= (const HDVector &p)
   { x -= p.X(); y -= p.Y(); return *this; }

  double Length(void) const
   { return sqrt(double(x)*double(x)+double(y)*double(y)); }
  void Display(const HWindow &w) const;
  void Transform(const HAffineTrans &transform)
   { transform.Transform(*this); }
  const char *ClassName(void) const { return "HDVector2D"; }
};


/****************************************************************************/
/*                            HDVector3D                                    */
/****************************************************************************/
class LIntExport HDVector3D: public HDVector {
private:
  HDCoord    x, y, z;
public:
  HDVector3D(HDCoord X=0, HDCoord Y=0, HDCoord Z=0): x(X), y(Y), z(Z) {}
  HDVector3D(const HDVector3D &p): HDVector(), x(p.x), y(p.y), z(p.z) {}
  HDVector3D(const HDVector &p): x(p.X()), y(p.Y()), z(p.Z()) {}
  HDVector3D(const HDVector2D &p): x(p.X()), y(p.Y()), z(0) {}
  HDVector3D(const HDPoint &p): x(p.X()), y(p.Y()), z(p.Z()) {}
  HDVector3D & operator = (const HDVector3D &vector)
   { x = vector.x; y = vector.y; z = vector.z; return *this; }
  ~HDVector3D(void) { x = 0; y = 0; z = 0; }

  operator HDPoint3D(void) const { return HDPoint3D(x,y); }

  HDCoord &X(void) { return x; }
  HDCoord &Y(void) { return y; }
  HDCoord &Z(void) { return z; }
  HDCoord X(void) const { return x; }
  HDCoord Y(void) const { return y; }
  HDCoord Z(void) const { return z; }
  HDCoord operator [] (int i) const
   { if (i==0) return x; else if (i==1) return y;
     else if (i==2) return z; else return 0; }
  
  HBool operator == (const HDVector3D &p) const
   { return ((x == p.x) && (y == p.y) && (z == p.z)); }
  HBool operator == (const HDVector &p) const
   { return ((x == p.X()) && (y == p.Y()) && (z == p.Z())); } 
  HBool operator != (const HDVector3D &p) const
   { return ((x != p.x) || (y != p.y) || (z != p.z)); }
  HBool operator != (const HDVector &p) const
   { return ((x != p.X()) || (y != p.Y()) || (z != p.Z())); } 

  HDVector3D operator - (void) const { return HDVector3D(-x,-y,-z); }
  HDVector3D operator + (const HDVector3D &add) const
   { return HDVector3D(x+add.x,y+add.y,z+add.z); }
  HDVector3D operator - (const HDVector3D &sub)
   { return HDVector3D(x-sub.x,y-sub.y,z-sub.z); }
  
  HDVector3D & operator += (const HDVector3D &p)
   { x += p.x; y += p.y; z += p.z; return *this; }
  HDVector & operator += (const HDVector &p)
   { x += p.X(); y += p.Y(); z += p.Z(); return *this; }
  HDVector3D & operator -= (const HDVector3D &p)
   { x -= p.x; y -= p.y; z -= p.z; return *this; }
   HDVector & operator -= (const HDVector &p)
   { x -= p.X(); y -= p.Y(); z -= p.Z(); return *this; }

  double Length(void) const
   { return sqrt(double(x)*double(x)+double(y)*double(y)+double(z)*double(z)); }
  void Display(const HWindow &w) const;
  void Transform(const HAffineTrans &transform)
   { transform.Transform(*this); }
  const char *ClassName(void) const { return "HDVector3D"; }
};


/****************************************************************************/
/*                            HPoint                                        */
/****************************************************************************/
class LIntExport HPoint: public HSpatialObject {
public:
  virtual HCoord &Y(void) = 0;
  virtual HCoord &X(void) = 0;
  virtual HCoord &Z(void) = 0;
  virtual HCoord Y(void) const = 0;
  virtual HCoord X(void) const = 0;
  virtual HCoord Z(void) const = 0;
  virtual HCoord operator [] (int i) = 0;
  virtual HBool operator == (const HPoint &p) const;
  virtual HBool operator != (const HPoint &p) const;
  virtual HPoint & operator += (const HPoint &p) = 0;
  virtual HPoint & operator -= (const HPoint &p) = 0;
  virtual double Distance(const HPoint &point) const = 0;
  virtual const char *ClassName(void) const = 0;
  virtual void Display(const HWindow &w) const = 0;
  virtual void Transform(const HAffineTrans &transform) = 0;
};


/****************************************************************************/
/*                            HPoint2D                                      */
/****************************************************************************/
class LIntExport HPoint2D: public HPoint {
private:
   HCoord    x, y;
public:
#ifdef COORD_IS_CLASS
   HPoint2D(HCoord X, HCoord Y): x((float)X), y((float)Y) {}
#endif
  HPoint2D(double X=0.0, double Y=0.0): x((float)X), y((float)Y) {}
  HPoint2D(const HPoint2D &p): HPoint(), x(p.x), y(p.y) {}
  HPoint2D(const HDPoint2D &p): x(p.X()), y(p.Y()) {}
  HPoint2D(const HPoint &p): x(p.X()), y(p.Y()) {}
  HPoint2D & operator = (const HPoint2D &point)
   { x = point.x; y = point.y; return *this; }
  ~HPoint2D(void) { x = 0.0f; y = 0.0f; }

  operator HDPoint2D(void) const
   { return HDPoint2D(HDCoord(x),HDCoord(y)); }
  operator HDVector2D(void) const
   { return HDVector2D(HDCoord(x),HDCoord(y)); }

  HCoord &Y(void) { return y; }
  HCoord &X(void) { return x; }
  HCoord &Z(void) { H_EXCEPTION("HCoord &Z(void)","illegal access");
                    return x; }
  HCoord Y(void) const { return y; }
  HCoord X(void) const { return x; }
  HCoord Z(void) const { return 0.0f; }
  HCoord operator [] (int i) 
   { if (i==0) return x; else if (i==1) return y; else return 0.0f; }

  HBool operator == (const HPoint2D &p) const
   { return ((x == p.x) && (y == p.y)); }
  HBool operator == (const HPoint &p) const
   { return ((x == p.X()) && (y == p.Y())); }
  HBool operator != (const HPoint2D &p) const
   { return ((y != p.y) || (x != p.x)); }
  HBool operator != (const HPoint &p) const
   { return ((x != p.X()) || (y != p.Y())); }

  HPoint2D operator - (void) const { return HPoint2D(-x,-y); }
  HPoint2D operator + (const HPoint2D &add) const
   { return HPoint2D(x+add.x, y+add.y); }
  HPoint2D operator - (const HPoint2D &sub)
   { return HPoint2D(x-sub.x, y-sub.y); }

  HPoint2D & operator += (const HPoint2D &p)
   { x += p.x; y += p.y; return *this; }
  HPoint2D & operator -= (const HPoint2D &p)
   { x -= p.x; y -= p.y; return *this; }
  HPoint & operator += (const HPoint &p)
   { x += p.X(); y += p.Y(); return *this; }
  HPoint & operator -= (const HPoint &p)
   { x -= p.X(); y -= p.Y(); return *this; }

  HBool Inside(const HPoint2D &pp, const HPoint2D &lr) const
   { return (x <=  pp.x) && (y <= pp.y) &&
            (pp.x >= lr.x) && (pp.y >= lr.y); }
  HBool operator <= (const HPoint2D &p) const
   { return (y < p.y) || ((y == p.y) && (x <= p.x)); }

  double Distance(const HPoint &point) const;
  void Display(const HWindow &w) const;
  void Transform(const HAffineTrans &transform)
   { transform.Transform(*this); }
  const char *ClassName(void) const { return "HPoint2D"; }
};


/****************************************************************************/
/*                            HPoint3D                                      */
/****************************************************************************/
class LIntExport HPoint3D: public HPoint {
private:
  HCoord    x, y, z;
public:
#ifdef COORD_IS_CLASS
  HPoint3D(HCoord X, HCoord Y, HCoord Z): x(X), y(Y), z(Z) {}
#endif
  HPoint3D(double X=0.0, double Y=0.0, double Z=0): x((float)X), y((float)Y), z((float)Z) {}
  HPoint3D(const HPoint3D &p): HPoint(), x(p.x), y(p.y), z(p.z) {}
  HPoint3D(const HPoint &p): x(p.X()), y(p.Y()), z(p.Z()) {}
  HPoint3D(const HPoint2D &p): x(p.X()), y(p.Y()), z(0.0f) {}
  HPoint3D(const HDPoint3D &p): x(p.X()), y(p.Y()), z(p.Z())  {}
  HPoint3D & operator = (const HPoint3D &point)
    { x = point.x; y = point.y; z = point.z; return *this;}
  ~HPoint3D(void) { x = 0.0f; y = 0.0f; z = 0.0f; }

  operator HDPoint3D(void) const 
   { return HDPoint3D(HDCoord(x),HDCoord(y),HDCoord(z)); }
  operator HDVector3D(void) const 
   { return HDVector3D(HDCoord(x),HDCoord(y),HDCoord(z)); }

  HCoord &Y(void) { return y; }
  HCoord &X(void) { return x; }
  HCoord &Z(void) { return z; }
  HCoord Y(void) const { return y; }
  HCoord X(void) const { return x; }
  HCoord Z(void) const { return z; }
  HCoord operator [] (int i)
   { if (i==0) return x; else if (i==1) return y; 
     else if (i==2) return z; else return 0.0f; }

  HBool operator == (const HPoint3D &p) const
   { return ((x == p.x) && (y == p.y) && (z == p.z)); }
  HBool operator == (const HPoint &p) const
   { return ((x == p.X()) && (y == p.Y()) && (z == p.Z())); } 
  HBool operator != (const HPoint3D &p) const
   { return ((x != p.x) || (y != p.y) || (z != p.z)); }
  HBool operator != (const HPoint &p) const
   { return ((x != p.X()) || (y != p.Y()) || (z != p.Z())); } 

  HPoint3D operator - (void) const { return HPoint3D(-x,-y,-z); }
  HPoint3D operator + (const HPoint3D &add) const
   { return HPoint3D(x+add.x,y+add.y,z+add.z); }
  HPoint3D operator - (const HPoint3D &sub)
   { return HPoint3D(x-sub.x,y-sub.y,z-sub.z); }

  HPoint3D & operator += (const HPoint3D &p)
   { x += p.x; y += p.y; z += p.z; return *this; }
   HPoint & operator += (const HPoint &p)
   { x += p.X(); y += p.Y(); z += p.Z(); return *this; }
  HPoint3D & operator -= (const HPoint3D &p)
   { x -= p.x; y -= p.y; z -= p.z; return *this; }
  HPoint & operator -= (const HPoint &p)
   { x -= p.X(); y -= p.Y(); z -= p.Z(); return *this; }
   
  double Distance(const HPoint &point) const;
  void Display(const HWindow &w) const; 
  void Transform(const HAffineTrans &transform)
   { transform.Transform(*this); }
  const char *ClassName(void) const { return "HPoint3D"; }
};


/****************************************************************************/
/*                            HVector                                       */
/****************************************************************************/
class LIntExport HVector: public HSpatialObject {
public:
  virtual HCoord &Y(void) = 0;
  virtual HCoord &X(void) = 0;
  virtual HCoord &Z(void) = 0;
  virtual HCoord Y(void) const = 0;
  virtual HCoord X(void) const = 0;
  virtual HCoord Z(void) const = 0;
  virtual HCoord operator [] (int i) = 0;
  virtual HBool operator == (const HVector &p) const;
  virtual HBool operator != (const HVector &p) const;
  virtual HVector & operator += (const HVector &p) = 0;
  virtual HVector & operator -= (const HVector &p) = 0;
  virtual double operator * (const HVector &mult) const;
  virtual double Length(void) const = 0;
  virtual const char *ClassName(void) const = 0;
  virtual void Display(const HWindow &w) const = 0;
  virtual void Transform(const HAffineTrans &transform) = 0;
};


/****************************************************************************/
/*                            HVector2D                                     */
/****************************************************************************/
class LIntExport HVector2D: public HVector {
private:
  HCoord    x, y;
public:
#ifdef COORD_IS_CLASS
  HVector2D(HCoord X, HCoord Y): x(X), y(Y) {}
#endif
  HVector2D(double X=0.0, double Y=0.0): x((float)X), y((float)Y) {}
  HVector2D(const HVector2D &p): HVector(), x(p.x), y(p.y) {}
  HVector2D(const HDVector2D &p): x(p.X()), y(p.Y()) {}
  HVector2D(const HVector &p): x(p.X()), y(p.Y()) {}
  HVector2D(const HDVector &p): x(p.X()), y(p.Y()) {}
  HVector2D(const HPoint &p): x(p.X()), y(p.Y()) {}
  HVector2D & operator = (const HVector2D &vector)
   { x = vector.x; y = vector.y; return *this; }
  ~HVector2D(void) { x = 0.0f; y = 0.0f; }

  operator HDVector2D(void) const { return HDVector2D(HDCoord(x),HDCoord(y)); }

  HCoord &Y(void) { return y; }
  HCoord &X(void) { return x; }
  HCoord &Z(void) { H_EXCEPTION("HCoord &Z(void)","illegal access");
                    return x; }
  HCoord Y(void) const { return y; }
  HCoord X(void) const { return x; }
  HCoord Z(void) const { return 0.0f; }
  HCoord operator [] (int i) 
   { if (i==0) return x; else if (i==1) return y; else return 0.0f; }

  HBool operator == (const HVector2D &p) const
   { return ((x == p.x) && (y == p.y)); }
  HBool operator == (const HVector &p) const
   { return ((x == p.X()) && (y == p.Y())); }
  HBool operator != (const HVector2D &p) const
   { return ((y != p.y) || (x != p.x)); }
  HBool operator != (const HVector &p) const
   { return ((x != p.X()) || (y != p.Y())); }

  HVector2D operator - (void) const { return HVector2D(-x,-y); }
  HVector2D operator + (const HVector2D &add) const
   { return HVector2D(x+add.x, y+add.y); }
  HVector2D operator - (const HVector2D &sub)
   { return HVector2D(x-sub.x, y-sub.y); }

  HVector2D & operator += (const HVector2D &p)
   { x += p.x; y += p.y; return *this; }
  HVector2D & operator -= (const HVector2D &p)
   { x -= p.x; y -= p.y; return *this; }
  HVector & operator += (const HVector &p)
   { x += p.X(); y += p.Y(); return *this; }
  HVector & operator -= (const HVector &p)
   { x -= p.X(); y -= p.Y(); return *this; }

  double operator * (const HVector &mult) const
   { return double(X()) * double(mult.X()) + double(Y()) * double(mult.Y()); } 

  double Length(void) const
   { return sqrt(double(x) * double(x) + double(y) * double(y)); }
  void Display(const HWindow &w) const;
  void Transform(const HAffineTrans &transform)
   { transform.Transform(*this); }
  const char *ClassName(void) const { return "HVector2D"; }
};


/****************************************************************************/
/*                            HVector3D                                     */
/****************************************************************************/
class LIntExport HVector3D: public HVector {
private:
  HCoord    x, y, z;
public:
#ifdef COORD_IS_CLASS
  HVector3D(HCoord X, HCoord Y, HCoord Z): x(X), y(Y), z(Z) {}
#endif
  HVector3D(double X=0.0, double Y=0.0, double Z=0): x((float)X), y((float)Y), z((float)Z) {}
  HVector3D(const HVector3D &p): HVector(), x(p.x), y(p.y), z(p.z) {}
  HVector3D(const HVector &p): x(p.X()), y(p.Y()), z(p.Z()) {}
  HVector3D(const HVector2D &p): x(p.X()), y(p.Y()), z(0.0f) {}
  HVector3D(const HDVector &p): x(p.X()), y(p.Y()), z(p.Z())  {}
  HVector3D(const HPoint &p): x(p.X()), y(p.Y()), z(p.Z()) {}
  HVector3D & operator = (const HVector3D &point)
    { x = point.x; y = point.y; z = point.z; return *this;}
  ~HVector3D(void) { x = 0.0f; y = 0.0f; z = 0.0f; }

  operator HDVector3D(void) const 
    { return HDVector3D(HDCoord(x),HDCoord(y),HDCoord(z)); }

  HCoord &Y(void) { return y; }
  HCoord &X(void) { return x; }
  HCoord &Z(void) { return z; }
  HCoord Y(void) const { return y; }
  HCoord X(void) const { return x; }
  HCoord Z(void) const { return z; }
  HCoord operator [] (int i)
   { if (i==0) return x; else if (i==1) return y; 
     else if (i==2) return z; else return 0.0f; }

  HBool operator == (const HVector3D &p) const
   { return ((x == p.x) && (y == p.y) && (z == p.z)); }
  HBool operator == (const HVector &p) const
   { return ((x == p.X()) && (y == p.Y()) && (z == p.Z())); } 
  HBool operator != (const HVector3D &p) const
   { return ((x != p.x) || (y != p.y) || (z != p.z)); }
  HBool operator != (const HVector &p) const
   { return ((x != p.X()) || (y != p.Y()) || (z != p.Z())); } 

  HVector3D operator - (void) const { return HVector3D(-x,-y,-z); }
  HVector3D operator + (const HVector3D &add) const
   { return HVector3D(x+add.x,y+add.y,z+add.z); }
  HVector3D operator - (const HVector3D &sub)
   { return HVector3D(x-sub.x,y-sub.y,z-sub.z); }

  HVector3D & operator += (const HVector3D &p)
   { x += p.x; y += p.y; z += p.z; return *this; }
  HVector & operator += (const HVector &p)
   { x += p.X(); y += p.Y(); z += p.Z(); return *this; }
  HVector3D & operator -= (const HVector3D &p)
   { x -= p.x; y -= p.y; z -= p.z; return *this; }
  HVector & operator -= (const HVector &p)
   { x -= p.X(); y -= p.Y(); z -= p.Z(); return *this; }
   
  HVector3D CrossProduct(const HVector &mult) const; 
  
  double Length(void) const 
   { return sqrt(double(x) * double(x) + 
     double(y) * double(y) + 
     double(z) * double(z)); }
  void Display(const HWindow &w) const; 
  void Transform(const HAffineTrans &transform)
   { transform.Transform(*this); }
  const char *ClassName(void) const { return "HVector3D"; }
};


/****************************************************************************/
/*                            HDChord                                       */
/****************************************************************************/
class LIntExport HDChord: public HDiscreteObject {
private:
  HDCoord  y;     // row
  HDCoord  xb;    // column begin
  HDCoord  xe;    // column end
public:
  HDChord(): y(0), xb(0), xe(0) {} 

  HDChord(int y_, int xb_, int xe_)
  {
    y = y_;
    xb = xb_;
    xe = xe_;
  }

  HDChord(const HDChord& chord):HDiscreteObject()
    { y = chord.y; xb = chord.xb; xe = chord.xe; }

  HDChord & operator = (const HDChord& chord)
    { y = chord.y; xb = chord.xb; xe = chord.xe;  
      return *this; }
    //~HDChord(void) {}

  HDCoord &Y(void) { return y; }
  HDCoord &Xb(void) { return xb; }
  HDCoord &Xe(void) { return xe; }
  HDCoord Y(void) const { return y; }
  HDCoord Xb(void) const { return xb; }
  HDCoord Xe(void) const { return xe; }
  HDPoint2D Begin(void) const { return HDPoint2D(xb,y); }
  HDPoint2D End(void) const { return HDPoint2D(xe,y); }
  int Length(void) const { return xe - xb + 1; }
  HBool RightOverlaped(const HDChord &chord) const
   { return ((y == chord.y) && (xb <= chord.xb) && (xe+1 >= chord.xb)); }
  HBool LeftOf(const HDChord &chord) const
   { return ((y < chord.y) || ((y == chord.y) && (xb < chord.Xb()))); }
  HBool operator < (const HDChord &chord) const
   { return (y < chord.Y()) || ((y == chord.Y()) && (xe < chord.Xb())); }
  HBool operator <= (const HDChord &chord) const
   { return (y < chord.Y()) || ((y == chord.Y()) && (xe <= chord.Xb())); }
  HBool operator > (const HDChord &chord) const
   { return chord < *this; }
  HBool In(const HDPoint2D &p) const
   { return ((p.Y() == y) && (p.X() >= xb) && (p.X() <= xe)); }
   
  Hlong NumPoints(void) const { return Length(); }
  void Display(const HWindow &w) const;
  const char *ClassName(void) const { return "HDChord"; }
  void Transform(const HAffineTrans &transform);
};




/****************************************************************************/
/*                            HLine                                         */
/****************************************************************************/
class LIntExport HLine: public HSpatialObject {
public:
  virtual double Length(void) const = 0;
  virtual double Distance(const HPoint &point) const = 0;
  virtual void Transform(const HAffineTrans &transform) = 0;
  virtual void Display(const HWindow &w) const = 0;
  virtual const char *ClassName(void) const = 0;
};



/****************************************************************************/
/*                            HLine2D                                       */
/****************************************************************************/
class LIntExport HLine2D: public HLine {
public:
  HLine2D(const HPoint2D &Start, const HPoint2D &End): start(Start), end(End) {}
  HLine2D(const HPoint &start, const HPoint &end);
  HLine2D(const HLine2D &line): HLine(), start(line.start), end(line.end) {}
  HLine2D & operator = (const HLine2D &line)
   { start = line.start; end = line.end; return *this; }
  ~HLine2D(void) {}
  
  HPoint2D Start(void) const { return start; }
  HPoint2D End(void) const { return end; }
  HPoint2D & Start(void) { return start; }
  HPoint2D & End(void) { return end; }
  
  HPoint & operator [] (Hlong i)
   { if (i==0) return start; else return end; }
  HPoint const & operator [] (Hlong i) const
   { if (i==0) return start; else return end; }
  double Length(void) const;
  double Distance(const HPoint &p) const;
  double Distance(const HLine2D &line) const; 
  double Direction(void) const;

  HPoint2D PerpLinePoint(const HPoint2D &p) const;
  double Parameter(const HPoint2D &p) const;
  HPoint2D ClosestPoint(const HPoint &p) const;
  HPoint2D Intersection(const HLine2D &line) const;
     
  void Transform(const HAffineTrans &transform)
   { transform.Transform(start); transform.Transform(end); }
  void Display(const HWindow &w) const;
  virtual const char *ClassName(void) const;
private:
  HPoint2D  start,end;
};


/****************************************************************************/
/*                            HLine3D                                       */
/****************************************************************************/
class LIntExport HLine3D: public HLine {
public:
  HLine3D(const HPoint3D &Start, const HPoint3D &End): start(Start), end(End) {}
  HLine3D(const HPoint &start, const HPoint &end);
  HLine3D(const HLine3D &line): HLine(), start(line.start), end(line.end) {}
  HLine3D & operator = (const HLine3D &line)
   { start = line.start; end = line.end; return *this; }
  ~HLine3D(void) {}
  
  HPoint3D Start(void) const { return start; }
  HPoint3D End(void) const { return end; }
  HPoint3D & Start(void) { return start; }
  HPoint3D & End(void) { return end; }
  
  HPoint & operator [] (Hlong i)
   { if (i==0) return start; else return end; }
  HPoint const & operator [] (Hlong i) const
   { if (i==0) return start; else return end; }
   
  double Length(void) const;
  double Distance(const HPoint &p) const;
  double Distance(const HLine3D &line) const;

  HPoint3D ClosestPoint(const HPoint &p) const;
  
  void Transform(const HAffineTrans &transform)
   { transform.Transform(start); transform.Transform(end); }
  void Display(const HWindow &w) const;
  virtual const char *ClassName(void) const;
private:
  HPoint3D  start,end;
};


/****************************************************************************/
/*                            HContour                                       */
/****************************************************************************/
class LIntExport HContour: public HSpatialObject, public HBaseArray {
public:
   HContour(void) { EmptyArray(); }
  virtual ~HContour(void);

  virtual HBool       IsClosed(void) = 0;
  virtual const char *ClassName(void) const = 0;
  virtual void        Display(const HWindow &w) const = 0;
  virtual void        Transform(const HAffineTrans &transform) = 0;

  // Merkmale
  virtual double      Length(void) const = 0;
  virtual double      Distance(const HPoint &p, Hlong &index) const = 0;

#ifdef WIN32EXTRA
  void*      operator new(size_t nSize);
  void       operator delete(void* p);
#endif

private:
  virtual void  NewLength(Hlong new_num, Hlong old_num) = 0;
};


/****************************************************************************/
/*                            HContour2D                                     */
/****************************************************************************/
class LIntExport HContour2D: public HContour {
public:
  HContour2D(void);
  HContour2D(const HContour2D &cont);
  HContour2D(const HXLDCont &cont);
  HContour2D(const HTuple &row, const HTuple &col);
  HContour2D(HPoint2D *points, Hlong num);
  ~HContour2D(void);

  HContour2D &operator= (const HContour2D &cont);

  // Tools
  const char *ClassName(void) const { return "HContour2D"; }
  HBool       IsClosed(void);
  void        Display(const HWindow &w) const;
  void        Transform(const HAffineTrans &transform);

  // Zugriff und Manipulation
  HPoint2D   const &operator[] (Hlong index) const;
  HPoint2D         &operator[] (Hlong index);
  HContour2D        operator() (Hlong min, Hlong max) const;
  HContour2D       &Append(const HPoint2D &point);
  HContour2D       &Append(const HContour2D &cont);

  // Merkmale
  double      Length(void) const;
  double      Distance(const HPoint &p, Hlong &index) const;
  HPoint2D    ClosestPoint(const HPoint &p, Hlong &index) const;

private:
  void        NewLength(Hlong new_num, Hlong old_num);
  HPoint2D    *array;
};


/****************************************************************************/
/*                            HContour3D                                     */
/****************************************************************************/
class LIntExport HContour3D: public HContour {
public:
  HContour3D(void);
  HContour3D(HContour3D &cont);
  HContour3D(HPoint3D *points, Hlong num);
  ~HContour3D(void);

  HContour3D &operator= (const HContour3D &cont);

  // Tools
  const char *ClassName(void) const { return "HContour3D"; }
  HBool       IsClosed(void);
  void        Display(const HWindow &w) const;
  void        Transform(const HAffineTrans &transform);

  // Zugriff und Manipulation
  HPoint3D   const &operator[] (Hlong index) const;
  HPoint3D         &operator[] (Hlong index);
  HContour3D        operator() (Hlong min, Hlong max) const;
  HContour3D       &Append(const HPoint3D &point);
  HContour3D       &Append(const HContour3D &cont);

  // Merkmale
  double      Length(void) const;
  double      Distance(const HPoint &p, Hlong &index) const;
  HPoint3D    ClosestPoint(const HPoint &p, Hlong &index) const;

private:
  void        NewLength(Hlong new_num, Hlong old_num);
  HPoint3D    *array;
};


/****************************************************************************/
/*                            HContourArray                                  */
/****************************************************************************/
class LIntExport HContourArray: public HSpatialObject, public HBaseArray {
public:
           HContourArray(void) { EmptyArray(); }
  virtual ~HContourArray(void);

  virtual const char *ClassName(void) const = 0;
  virtual void        Display(const HWindow &w) const = 0;
  virtual void        Transform(const HAffineTrans &transform) = 0;

#ifdef WIN32EXTRA
  void*      operator new(size_t nSize);
  void       operator delete(void* p);
#endif

private:
  virtual void  NewLength(Hlong new_num, Hlong old_num) = 0;
};


/****************************************************************************/
/*                            HContourArray2D                                */
/****************************************************************************/
class LIntExport HContourArray2D: public HContourArray {
public:
  HContourArray2D(void);
  HContourArray2D(HContourArray2D &contours);
  HContourArray2D(const HXLDContArray &contours);
  HContourArray2D(HContour2D *contours, Hlong num);
  ~HContourArray2D(void);

  HContourArray2D &operator= (const HContourArray2D &contours);

  // Tools
  const char *ClassName(void) const { return "HContourArray2D"; }
  void        Display(const HWindow &w) const;
  void        Transform(const HAffineTrans &transform);

  // Zugriff und Manipulation
  HContour2D      const &operator[] (Hlong index) const;
  HContour2D            &operator[] (Hlong index);
  HContourArray2D        operator() (Hlong min, Hlong max) const;
  HContourArray2D       &Append(const HContour2D &cont);
  HContourArray2D       &Append(const HContourArray2D &contours);

private:
  void          NewLength(Hlong new_num, Hlong old_num);
  HContour2D    *array;
};


/****************************************************************************/
/*                            HContourArray3D                                */
/****************************************************************************/
class LIntExport HContourArray3D: public HContourArray {
public:
  HContourArray3D(void);
  HContourArray3D(HContourArray3D &cont);
  HContourArray3D(HContour3D *contours, Hlong num);
  ~HContourArray3D(void);

  HContourArray3D &operator= (const HContourArray3D &contours);

  // Tools
  const char *ClassName(void) const { return "HContourArray3D"; }
  void        Display(const HWindow &w) const;
  void        Transform(const HAffineTrans &transform);

  // Zugriff und Manipulation
  HContour3D      const &operator[] (Hlong index) const;
  HContour3D            &operator[] (Hlong index);
  HContourArray3D        operator() (Hlong min, Hlong max) const;
  HContourArray3D       &Append(const HContour3D &cont);
  HContourArray3D       &Append(const HContourArray3D &contours);

private:
  void          NewLength(Hlong new_num, Hlong old_num);
   HContour3D    *array;
};


/****************************************************************************/
/*                            HPolygon                                      */
/****************************************************************************/
class LIntExport HPolygon: public HSpatialObject, public HBaseArray {
public:
         HPolygon(void) { EmptyArray(); }
  virtual ~HPolygon(void);

  virtual HBool       IsClosed(void) = 0;
  virtual const char *ClassName(void) const = 0;
  virtual void        Display(const HWindow &w) const = 0;
  virtual void        Transform(const HAffineTrans &transform) = 0;

  // Merkmale
  virtual double      Length(void) const = 0;
  virtual double      Distance(const HPoint &p, Hlong &index) const = 0;

#ifdef WIN32EXTRA
  void*      operator new(size_t nSize);
  void       operator delete(void* p);
#endif

private:
  virtual void  NewLength(Hlong new_num, Hlong old_num) = 0;
};



/****************************************************************************/
/*                            HPolygon2D                                    */
/****************************************************************************/
class LIntExport HPolygon2D: public HPolygon {
public:
  HPolygon2D(void);
  HPolygon2D(const HPolygon2D &poly);
  HPolygon2D(const HContour2D &contour);
  HPolygon2D(const HXLDPoly &poly);
  HPolygon2D(const HTuple &row, const HTuple &col);
  HPolygon2D(HPoint2D *points, Hlong num);
  ~HPolygon2D(void);

  HPolygon2D &operator= (const HPolygon2D &poly);

  // Tools
  const char *ClassName(void) const { return "HPolygon2D"; }
  HBool       IsClosed(void);
  void        Display(const HWindow &w) const;
  void        Transform(const HAffineTrans &transform);

  // Zugriff und Manipulation
  HPoint2D   const &operator[] (Hlong index) const;
  HPoint2D         &operator[] (Hlong index);
  HPolygon2D        operator() (Hlong min, Hlong max) const;
  HPolygon2D       &Append(const HPoint2D &point);
  HPolygon2D       &Append(const HPolygon2D &poly);

  // Merkmale
  double      Length(void) const;
  double      Distance(const HPoint &p, Hlong &index) const;
  HPoint2D    ClosestPoint(const HPoint &p, Hlong &index) const;
  HBool       Intersects(const HLine2D &line2D) const;
  
private:
  void        NewLength(Hlong new_num, Hlong old_num);
  HPoint2D    *array;
};



/****************************************************************************/
/*                            HPolygon3D                                    */
/****************************************************************************/
class LIntExport HPolygon3D: public HPolygon {
public:
  HPolygon3D(void);
  HPolygon3D(HPolygon3D &poly);
  HPolygon3D(HPoint3D *points, Hlong num);
  ~HPolygon3D(void);

  HPolygon3D &operator= (const HPolygon3D &poly);

  // Tools
  const char *ClassName(void) const { return "HPolygon3D"; }
  HBool       IsClosed(void);
  void        Display(const HWindow &w) const;
  void        Transform(const HAffineTrans &transform);

  // Zugriff und Manipulation
  HPoint3D   const &operator[] (Hlong index) const;
  HPoint3D         &operator[] (Hlong index);
  HPolygon3D        operator() (Hlong min, Hlong max) const;
  HPolygon3D       &Append(const HPoint3D &point);
  HPolygon3D       &Append(const HPolygon3D &poly);

  // Merkmale
  double      Length(void) const;
  double      Distance(const HPoint &p, Hlong &index) const;
  HPoint3D    ClosestPoint(const HPoint &p, Hlong &index) const;

private:
  void        NewLength(Hlong new_num, Hlong old_num);
  HPoint3D    *array;
};



/****************************************************************************/
/*                            HPolygonArray                                 */
/****************************************************************************/
class LIntExport HPolygonArray: public HSpatialObject, public HBaseArray {
public:
          HPolygonArray(void) { EmptyArray(); }
  virtual ~HPolygonArray(void);

  virtual const char *ClassName(void) const = 0;
  virtual void        Display(const HWindow &w) const = 0;
  virtual void        Transform(const HAffineTrans &transform) = 0;

#ifdef WIN32EXTRA
  void*      operator new(size_t nSize);
  void       operator delete(void* p);
#endif

private:
  virtual void  NewLength(Hlong new_num, Hlong old_num) = 0;
};


/****************************************************************************/
/*                            HPolygonArray2D                               */
/****************************************************************************/
class LIntExport HPolygonArray2D: public HPolygonArray {
public:
  HPolygonArray2D(void);
  HPolygonArray2D(const HPolygonArray2D &polygons);
  HPolygonArray2D(const HContourArray2D &contours);
  HPolygonArray2D(const HXLDPolyArray &polygons);
  HPolygonArray2D(const HXLDParaArray &parapolys);
  HPolygonArray2D(const HXLDModParaArray &parapolys);
  HPolygonArray2D(const HXLDExtParaArray &parapolys);
  HPolygonArray2D(HPolygon2D *polygons, Hlong num);
  ~HPolygonArray2D(void);

  HPolygonArray2D &operator= (const HPolygonArray2D &polygons);

  // Tools
  const char *ClassName(void) const { return "HPolygonArray2D"; }
  void        Display(const HWindow &w) const;
  void        Transform(const HAffineTrans &transform);

  // Zugriff und Manipulation
  HPolygon2D      const &operator[] (Hlong index) const;
  HPolygon2D            &operator[] (Hlong index);
  HPolygonArray2D        operator() (Hlong min, Hlong max) const;
  HPolygonArray2D       &Append(const HPolygon2D &poly);
  HPolygonArray2D       &Append(const HPolygonArray2D &polygons);

  HBool   Intersects(const HLine2D &line2D) const;

private:
  void          NewLength(Hlong new_num, Hlong old_num);
  HPolygon2D    *array;
};


/****************************************************************************/
/*                            HPolygonArray3D                               */
/****************************************************************************/
class LIntExport HPolygonArray3D: public HPolygonArray {
public:
  HPolygonArray3D(void);
  HPolygonArray3D(HPolygonArray3D &polygons);
  HPolygonArray3D(HPolygon3D *polygons, Hlong num);
  ~HPolygonArray3D(void);

  HPolygonArray3D &operator= (const HPolygonArray3D &polygons);

  // Tools
  const char *ClassName(void) const { return "HPolygonArray3D"; }
  void        Display(const HWindow &w) const;
  void        Transform(const HAffineTrans &transform);

  // Zugriff und Manipulation
  HPolygon3D      const &operator[] (Hlong index) const;
  HPolygon3D            &operator[] (Hlong index);
  HPolygonArray3D        operator() (Hlong min, Hlong max) const;
  HPolygonArray3D       &Append(const HPolygon3D &poly);
  HPolygonArray3D       &Append(const HPolygonArray3D &polygons);

private:
  void          NewLength(Hlong new_num, Hlong old_num);
  HPolygon3D    *array;
};


/****************************************************************************/
/*                            HEllipse                                      */
/****************************************************************************/
class LIntExport HEllipse: public HSpatialObject {
public:
  HEllipse(): r1(0), r2(0) {}
  HEllipse(const HPoint2D &Center, double R1, double R2, double Phi = 0.0): 
    center(Center), r1(R1), r2(R2), phi(Phi) {}
  HEllipse(const HEllipse &c):HSpatialObject()
    {center = c.center; r1 = c.r1; r2 = c.r2; phi = c.phi;}
  virtual ~HEllipse(void);
    
  virtual  HPoint2D  Center(void) const;
  double   Ra(void) const { return r1; }
  double   Rb(void) const { return r2; }
  double   Phi(void) const { return phi; }
  
  virtual void Transform(const HAffineTrans &transform); 
  virtual void Display(const HWindow &w) const;
  virtual const char *ClassName(void) const;
  
protected:
  HPoint2D center;
  double   r1,r2;
  double   phi;
};


/****************************************************************************/
/*                            HCircle                                       */
/****************************************************************************/
class LIntExport HCircle: public HEllipse {
public:
  HCircle(void);
  HCircle(const HPoint2D &center, double radius);
  HCircle(const HCircle &c);
  ~HCircle(void);
    
  HPoint2D    Center(void) const { return center; }
  double      Radius(void) const { return r1; }
  
  void        Transform(const HAffineTrans &transform);  
  void        Display(const HWindow &w) const;
  const char *ClassName(void) const { return "HCircle"; }

private:
};


}


#endif
