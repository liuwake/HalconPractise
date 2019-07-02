/*****************************************************************************
 * HOCV.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HOCV
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_OCV_H
#define H_OCV_H


#include "HCPPToolRef.h"


namespace Halcon {


class LIntExport HOCV: public HToolBase
{
public:

  // Tool-specific functional class constructors

  HOCV(const HTuple &PatternName);
  HOCV(const char *PatternName);

  // Common tool class management functionality

  HOCV();
  HOCV(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Verification of a pattern using an OCV tool.
  virtual HTuple DoOcvSimple(const HImageArray &Pattern, const Halcon::HTuple &PatternName, const Halcon::HTuple &AdaptPos, const Halcon::HTuple &AdaptSize, const Halcon::HTuple &AdaptAngle, const Halcon::HTuple &AdaptGray, const Halcon::HTuple &Threshold) const;
  // Verification of a pattern using an OCV tool.
  virtual HTuple DoOcvSimple(const HImageArray &Pattern, const char *PatternName, const char *AdaptPos, const char *AdaptSize, const char *AdaptAngle, const char *AdaptGray, double Threshold) const;
  // Training of an OCV tool.
  virtual void TraindOcvProj(const HImageArray &Pattern, const Halcon::HTuple &Name, const Halcon::HTuple &Mode) const;
  // Training of an OCV tool.
  virtual void TraindOcvProj(const HImageArray &Pattern, const char *Name, const char *Mode) const;
  // Deserialize a serialized OCV tool.
  virtual void DeserializeOcv(const Halcon::HSerializedItem &SerializedItemHandle);
  // Serialize an OCV tool.
  virtual HSerializedItem SerializeOcv() const;
  // Reading an OCV tool from file.
  virtual void ReadOcv(const Halcon::HTuple &FileName);
  // Reading an OCV tool from file.
  virtual void ReadOcv(const char *FileName);
  // Saving an OCV tool to file.
  virtual void WriteOcv(const Halcon::HTuple &FileName) const;
  // Saving an OCV tool to file.
  virtual void WriteOcv(const char *FileName) const;
  // Create a new OCV tool based on gray value projections.
  virtual void CreateOcvProj(const Halcon::HTuple &PatternNames);
  // Create a new OCV tool based on gray value projections.
  virtual void CreateOcvProj(const char *PatternNames);
};

}

#endif
