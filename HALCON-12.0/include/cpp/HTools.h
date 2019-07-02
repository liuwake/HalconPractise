/*****************************************************************************
 * HTools.h
 ***************************************************************************** 
 *
 * Project:     Halcon/C++
 * Description: Misc toolls
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef HTOOLS_H
#define HTOOLS_H


namespace Halcon {


#if 0
/****************************************************************************/
/*                            HThresholds                                   */
/****************************************************************************/
class LIntExport HThresholds: public HRootObject {
public:
  HThresholds(void): num(0), min_thresh(NULL), max_thresh(NULL) {}
  HThresholds(double min, double max);
  HThresholds(int *min, int *max, int num);
  HThresholds(Hlong *min, Hlong *max, int num);
  HThresholds(double *min, double *max, int num);
  HThresholds(const HThresholds& thr);
  HThresholds &operator = (const HThresholds &thr);
  ~HThresholds(void);
  
  int     Num() { return num; };
  double  HMin(Hlong index) const { return min_thresh[index]; }
  double  HMax(Hlong index) const { return max_thresh[index]; }
  
  const char *ClassName(void) const { return "HThresholds"; }
private:
  int     num;
  double  *min_thresh;
  double  *max_thresh;
};

#endif


/****************************************************************************/
/*                            PixVal                                        */
/****************************************************************************/

enum HPixValues { FOREGROUND=1, BACKGROUND=0, PARTIAL=2 };

class LIntExport HBinPixVal: public HBasePixVal {
public:
  HBinPixVal(): val(BACKGROUND) {}
  HBinPixVal(int i)   { if (i) val = FOREGROUND; else val = BACKGROUND; }
  HBinPixVal(HByte i) { if (i) val = FOREGROUND; else val = BACKGROUND; }
  HBinPixVal(HPixValues v): val(v) {}
  operator HByte(void) const
    { if (val == FOREGROUND) return 1; else return 0; }
  operator HPixValues(void)
    { if (val == FOREGROUND) return FOREGROUND; else return BACKGROUND; }
   HBinPixVal operator ~ (void)
  { return (val == FOREGROUND) ? BACKGROUND : FOREGROUND; }
  HBool operator == (const HBinPixVal &comp) const
  { return val == comp.val; }
  HBool operator != (const HBinPixVal &comp) const
  { return val != comp.val; }
  HBinPixVal operator | (const HBinPixVal &v) const
  { return ((val == FOREGROUND) || (v.val == FOREGROUND)) ?
    FOREGROUND : BACKGROUND; }
  HBinPixVal operator ^ (const HBinPixVal &v) const
  { return (val != v.val) ? FOREGROUND : BACKGROUND; }
  HBinPixVal operator / (const HBinPixVal &v) const
  { return (v.val == FOREGROUND) ? HBinPixVal(BACKGROUND) : HBinPixVal(val); }
  HBinPixVal operator & (const HBinPixVal &v) const
  { return ((val == FOREGROUND) && (v.val == FOREGROUND)) ?
    FOREGROUND : BACKGROUND; }
  HBinPixVal operator |= (const HBinPixVal &v)
  { if (v.val == FOREGROUND) val = FOREGROUND; return *this; }
  HBinPixVal operator &= (const HBinPixVal &v)
  { if (v.val == BACKGROUND) val = BACKGROUND; return *this; }
  HBinPixVal operator ^= (const HBinPixVal &v)
  { if (v.val != val)
    val = FOREGROUND; else val = BACKGROUND; return *this; }
  HBinPixVal operator /= (const HBinPixVal &v)
  { if (v.val == FOREGROUND) val = BACKGROUND; return *this; }
  const char *ClassName(void) const { return "HBinPixVal"; } 
private:
   HPixValues val;  
};


}


#endif
