/*****************************************************************************
 * HMultiImage.h
 ***************************************************************************** 
 *
 * Project:     Halcon/C++
 * Description: Types for multichannels images
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */


#ifndef HMULTI_IMAGE_H
#define HMULTI_IMAGE_H


namespace Halcon {


/****************************************************************************/
/*                             HSemAbstractMultiImage                       */
/****************************************************************************/
class LIntExport HSemAbstractMultiImage: public HBaseImage {
public:
  HSemAbstractMultiImage(void);
  virtual ~HSemAbstractMultiImage(void);
 
  // Tools
  virtual int         NumChannels(void) = 0;
  virtual HSemImage   GetChannel(int index) = 0;
  virtual HSemAbstractMultiImage *CopyAbstractMultiSImage(void) const = 0;
  virtual const char *ClassName(void) const = 0; 
  virtual void        Transform(const HAffineTrans &transform, int mode) = 0;
  virtual void        Display(const HWindow &w) const;
  
  // Class Methods
  static Hlong NumData(void);
};


/****************************************************************************/
/*                               HSemMultiImage                             */
/****************************************************************************/
class LIntExport HSemMultiImage: public HBaseImage {
public:
  HSemMultiImage(void);
  HSemMultiImage(const HSemMultiImage &r);
  ~HSemMultiImage(void);
  HSemMultiImage &operator = (const HSemMultiImage &arr);
  
  // Tools
  virtual int       NumChannels(void);
  virtual HSemImage GetChannel(int index);
  const char       *ClassName(void) const;
  void              Transform(const HAffineTrans &transform, int mode);
  void              Display(const HWindow &w) const;
  
private:
  HSemAbstractMultiImage  *image;
};


/****************************************************************************/
/*                               HSemMultiImageArray                        */
/****************************************************************************/
class LIntExport HSemMultiImageArray: public HBaseImage, public HBaseArray {
public:
  HSemMultiImageArray(void);
  HSemMultiImageArray(const HSemMultiImageArray &r);
  ~HSemMultiImageArray(void);
  HSemMultiImageArray &operator = (const HSemMultiImageArray &arr);
  
  // Tools
  virtual int             NumChannels(void);
  virtual HSemMultiImage  GetChannel(int index);
  
  // Access and Manipulation
  HSemMultiImage &operator [] (Hlong index);
  MultiSImageArray operator () (Hlong min, Hlong max);
  HSemMultiImageArray &Append(const HSemMultiImage &reg);
  HSemMultiImageArray &Append(const HSemMultiImageArray &reg);
  const char   *ClassName(void) const {return "HSemMultiImageArray";}
  void          Transform(const HAffineTrans &transform, int mode);
  void          Display(const HWindow &w) const;
  
private:
  HSemMultiImage  *images;
};


/****************************************************************************/
/*                           HSemMultiImageSequence                         */
/****************************************************************************/
class LIntExport HSemMultiImageSequence: public HSemMultiImageArray {
};


/****************************************************************************/
/*                               HPyramid                                   */
/****************************************************************************/
class LIntExport HPyramid: public HSemAbstractMultiImage {
public:
  HPyramid(void);
  HPyramid(const HSemImage &image, double zoom_factor = 0.5, int zoom_mode = 1,
           int min_size = 1);
  virtual ~HPyramid(void);
  
  virtual HSemAbstractMultiImage *CopyAbstractMultiSImage(void) const;
  virtual void            Display(const HWindow &w) const;
  virtual int             NumChannels(void);
  virtual HSemImage       GetChannel(int index);
  virtual void            Transform(const HAffineTrans &transform, int mode);
  virtual const char     *ClassName(void) const;

private:
  int     depth;
  HSemImage  *images;
};


/****************************************************************************/
/*                               HGaussPyramid                              */
/****************************************************************************/
class LIntExport HGaussPyramid: public HPyramid {
public:
  HGaussPyramid(void) {}
  HGaussPyramid(const HSemImage &image, double zoom);
  ~HGaussPyramid(void);
  const char* ClassName(void) const {return "HGaussPyramid";}
};


/****************************************************************************/
/*                               HLaplacePyramid                            */
/****************************************************************************/
class LIntExport HLaplacePyramid: public HPyramid {
public:
  HLaplacePyramid(void) {}
  HLaplacePyramid(const HSemImage &image, double zoom);
  ~HLaplacePyramid(void);
  const char* ClassName(void) const {return "HLaplacePyramid";}
};


/****************************************************************************/
/*                               HStereoImage                               */
/****************************************************************************/
class LIntExport HStereoImage: public HSemAbstractMultiImage {
public:
  HStereoImage(void);
  HStereoImage(const HSemImage &left, const HSemImage &right);
  
  HSemAbstractMultiImage* CopyAbstractMultiSImage(void) const;
  const char   *ClassName(void) const {return "HStereoImage";}
  int           NumChannels(void) {return 2;}
  HSemImage     GetChannel(int index)
  {if (index == 0) return left;else return right;}
  void          Transform(const HAffineTrans &transform, int mode);
  void          Display(const HWindow &w) const {left.Display(w);}

private:
  HSemImage  left, right;
};


/****************************************************************************/
/*                               HNChannelImage                             */
/****************************************************************************/
class LIntExport HNChannelImage: public HSemAbstractMultiImage {
public:
  virtual HSemAbstractMultiImage* CopyAbstractMultiSImage(void) const = 0;
  int          Width(void) const {return images[0].Width();}
  int          Height(void) const {return images[0].Height();}
  const char  *ClassName(void) const {return "HNChannelImage";}
  int          NumChannels(void) {return num;}
  HSemImage    GetChannel(int index) {return images[index];}
  void         Transform(const HAffineTrans &transform, int mode);
  void         Display(const HWindow &w) const {images[0].Display(w);}

private:
  HSemImage  *images;
  int         num;
};


/****************************************************************************/
/*                               H3DImage                                   */
/****************************************************************************/
class LIntExport H3DImage: public HSemAbstractMultiImage {
public:
  virtual HSemAbstractMultiImage* CopyAbstractMultiSImage(void) const = 0;
  int         Width(void) const { return images[0].Width(); }
  int         Height(void) const { return images[0].Height(); }
  const char *ClassName(void) const { return "HNChannelImage"; }
  int         NumChannels(void) { return num; }
  HSemImage   GetChannel(int index) { return images[index]; }
  void        Transform(const HAffineTrans &transform, int mode);
  void        Display(const HWindow &w) const { images[0].Display(w); }

private:
  HSemImage  *images;
  int         num;
};


/****************************************************************************/
/*                               HSemImageArray                             */
/****************************************************************************/
class LIntExport HSemImageArray: public HSemAbstractMultiImage, 
                                 public HBaseArray {
public:
  HSemImageArray(void);
  HSemImageArray(HSemImage *arr, int num);
  HSemImageArray(const HSemImageArray &arr);
  ~HSemImageArray(void);
  HSemImageArray &operator = (const HSemImageArray &arr);
  
  Hobject     Id(Hlong i) const;
  void        NewLength(Hlong new_num, Hlong old_num);
  const char *ClassName(void) const;
  int         NumChannels(void);
  HSemImage   GetChannel(int index);
  HSemAbstractMultiImage *CopyAbstractMultiSImage(void) const;
  void        Transform(const HAffineTrans &transform, int mode);

protected:
  HSemImage  *array;
};


/****************************************************************************/
/*                               HSemImageSequence                          */
/****************************************************************************/
class LIntExport HSemImageSequence: public HSemImageArray {
};


}


#endif
