/*****************************************************************************
 * HalconCpp.h
 *****************************************************************************
 *
 * Project:     HALCON/C++
 * Description: Defines / types / extern declarations for HALCON/C++ interface
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 *
 *****************************************************************************
 *
 *
 */

#ifndef H_CPP_H
#define H_CPP_H

// basic HALCON include files
#include <stdlib.h>
#include <string.h>
#include "HIntDef.h"
#include "HDeclSpec.h"
#include "HErrorDef.h"
#include "HConst.h"
#include "HBase.h"
#include "IPType.h"
#include "HCtype.h"
#include "HMacro.h"
#include "hlib/IOSpy.h"
#include "HExtern.h"
#include "hlib/HError.h"

// interface version
// do not define a number because it can be loaded in parallel to version 11
#define HCPP_INTERFACE_VERSION_10

#if defined(_WIN32)
/* FindText, CreateMutex, and CreateEvent are also functions of the
 * Windows API. There are defines on FindTextW, CreateMutexW, and
 * CreateEventW if UNICODE is defined, otherwise there are defines on
 * FindTextA, CreateMutexA, and CreateMutexA.
 * These defines are undefined here. If you want to use the corresponding
 * Windows API calls, you must use FindTextA, FindTextW, CreateMutexA,
 * CreateMutexW, CreateEventA, or CreateEventW directly. */
#undef FindText
#undef CreateMutex
#undef CreateEvent
#endif

namespace Halcon {
#define     H_VERSION     12
#define     H_REVISION    0
#define     H_CREATION    "13.11.2014"

#define     H_STD       1       // status normal HTuple
#define     H_IGNORE    2       // status ignore values
#define     H_DEFAULT   3       // status default value
#define     H_UNDEF_TYPE  (-1)  // current value in CParType not defined;
                                // instead of STRING_PAR, LONG_PAR, etc
#define     H_GLOBAL_ID 0       // global variable for "PROC_ID"


#define H_EMPTY_REGION      (Hkey)(1)   // empty region


typedef int   HBool;

typedef UINT1 HByte;
typedef INT2  HInt2;
typedef UINT2 HUInt2;


#define H_TRUE  (Halcon::HBool)1
#define H_FALSE (Halcon::HBool)0



class Hobject;
class HAbstractRegion;
class HBaseArray;
class HRegionArray;
class HXLD;
class HXLDArray;
class HXLDCont;
class HXLDContArray;
class HXLDPoly;
class HXLDPolyArray;
class HXLDPara;
class HXLDParaArray;
class HXLDModPara;
class HXLDModParaArray;
class HXLDExtPara;
class HXLDExtParaArray;
class HRegion;
class HImageArray;
class HImage;
class HByteImage;
class HInt1Image;
class HInt2Image;
class HUInt2Image;
class HInt4Image;
class HFloatImage;
class HComplexImage;
class HSemImage;
class HSemMultiImage;
class HSemAbstractMultiImage;
class HRGBImage;
class HWindow;
class HPixVal;
class HNumeric;
class HComplex;
class HAngleRad;
class HAngleDeg;
#ifndef COORD_IS_CLASS
typedef int    HDCoord;
typedef double HCoord;
#else
class HDCoord;
class HCoord;
#endif
class HDPoint;
class HDPoint2D;
class HDPoint3D;
class HDVector;
class HDVector2D;
class HDVector3D;
class HPoint;
class HPoint2D;
class HPoint3D;
class HVector;
class HVector2D;
class HVector3D;
class HPolygon;
class HLine;
class HLine2D;
class HLine3D;
class HCircle;
class HEllipse;
class HRectangle1;
class HRectangle2;
class HTuple;
class HRLRegion;
class HRGBLUT;
class HFramegrabber;
class HIODevice;
class HIOChannel;
class HNCCModel;
class HShapeModel;
class HComponentModel;
class HComponentTraining;
class HObjectModel3D;
class HScene3D;
class HSurfaceModel;
class HSurfaceMatchingResult;
class HDeformableSurfaceModel;
class HDeformableSurfaceMatchingResult;
class HDeformableModel;
class HDescriptorModel;
class HShapeModel3D;
class HTemplate;
class HMeasure;
class HMatrix;
class HVariationModel;
class HCalibData;
class HCameraSetupModel;
class HStereoModel;
class HFile;
class HSerial;
class HSocket;
class HBgEsti;
class HOCRBox;
class HOCRMlp;
class HOCRSvm;
class HOCRKnn;
class HLexicon;
class HOCV;
class HClassBox;
class HClassMlp;
class HClassSvm;
class HClassGmm;
class HClassKnn;
class HClassTrainData;
class HClassLUT;
class HColorTransLUT;
class HFunction1D;
class HGnuplot;
class HBarCode;
class HBarCode1D;
class HBarCode2D;
class HDataCode2D;
class HSheetOfLightModel;
class HComputeDevice;
class HMutex;
class HEvent;
class HCondition;
class HBarrier;
class HMessage;
class HMessageQueue;
class HTextModel;
class HTextResult;
class HMetrologyModel;
class HSerializedItem;
class HScatteredDataInterpolator;
class HSampleIdentifier;
class HDrawingObject;


// For HCPP.cxx: Passing of iconic data
#define H_REGION_ARRAY        1
#define H_REGION_SINGLE       2
#define H_IMAGE_ARRAY         3
#define H_IMAGE_SINGLE        4
#define H_XLD_CONT_ARRAY      5
#define H_XLD_CONT_SINGLE     6
#define H_XLD_POLY_ARRAY      7
#define H_XLD_POLY_SINGLE     8
#define H_XLD_PARA_ARRAY      9
#define H_XLD_PARA_SINGLE     10
#define H_XLD_MOD_PARA_ARRAY  11
#define H_XLD_MOD_PARA_SINGLE 12
#define H_XLD_EXT_PARA_ARRAY  13
#define H_XLD_EXT_PARA_SINGLE 14

extern LIntExport HTuple* _;      // ignore result values
extern LIntExport HTuple* __;     // use default values

}


#include "HException.h"
#include "HCPPUtil.h"
#include "HTuple.h"
#include "HOperator.h"
#include "HNumeric.h"
#include "HPixVal.h"
#include "HTools.h"
#include "HPrimitives.h"
#include "HRectangle.h"
#include "HDRegion.h"
#include "HCPPGlobal.h"
#include "HWindow.h"
#include "HDevWindowStack.h"
#include "HImage.h"
#include "HByteImage.h"
#include "HImageArray.h"
#include "HRLRegion.h"
#include "HFloatImage.h"
#include "HComplexImage.h"
#include "HInt1Image.h"
#include "HInt2Image.h"
#include "HUInt2Image.h"
#include "HInt4Image.h"
#include "HConvol.h"
#include "HIterator.h"
#include "HRegion.h"
#include "HRegionArray.h"
#include "HXLD.h"
#include "HXLDArray.h"
#include "HXLDCont.h"
#include "HXLDContArray.h"
#include "HXLDPoly.h"
#include "HXLDPolyArray.h"
#include "HXLDPara.h"
#include "HXLDParaArray.h"
#include "HXLDModPara.h"
#include "HXLDModParaArray.h"
#include "HXLDExtPara.h"
#include "HXLDExtParaArray.h"
#include "HFramegrabber.h"
#include "HIODevice.h"
#include "HIOChannel.h"
#include "HNCCModel.h"
#include "HShapeModel.h"
#include "HComponentModel.h"
#include "HComponentTraining.h"
#include "HObjectModel3D.h"
#include "HScene3D.h"
#include "HSurfaceModel.h"
#include "HSurfaceMatchingResult.h"
#include "HDeformableSurfaceModel.h"
#include "HDeformableSurfaceMatchingResult.h"
#include "HShapeModel3D.h"
#include "HDeformableModel.h"
#include "HDescriptorModel.h"
#include "HVariationModel.h"
#include "HCalibData.h"
#include "HCameraSetupModel.h"
#include "HStereoModel.h"
#include "HTemplate.h"
#include "HMeasure.h"
#include "HMatrix.h"
#include "HFile.h"
#include "HSerial.h"
#include "HSocket.h"
#include "HBgEsti.h"
#include "HOCRBox.h"
#include "HOCRMlp.h"
#include "HOCRSvm.h"
#include "HOCRKnn.h"
#include "HLexicon.h"
#include "HOCV.h"
#include "HClassBox.h"
#include "HClassMlp.h"
#include "HClassSvm.h"
#include "HClassGmm.h"
#include "HClassKnn.h"
#include "HClassTrainData.h"
#include "HClassLUT.h"
#include "HColorTransLUT.h"
#include "HFunction1D.h"
#include "HGnuplot.h"
#include "HBarCode.h"
#include "HBarCode1D.h"
#include "HBarCode2D.h"
#include "HDataCode2D.h"
#include "HSheetOfLightModel.h"
#include "HComputeDevice.h"
#include "HMutex.h"
#include "HEvent.h"
#include "HCondition.h"
#include "HBarrier.h"
#include "HMessage.h"
#include "HMessageQueue.h"
#include "HTextModel.h"
#include "HTextResult.h"
#include "HMetrologyModel.h"
#include "HSerializedItem.h"
#include "HScatteredDataInterpolator.h"
#include "HSampleIdentifier.h"
#include "HDrawingObject.h"

#include "HInterfaceCPP.h"

#endif
