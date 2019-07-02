/*****************************************************************************
 * HInterfaceC.h
 ***************************************************************************** 
 *
 * Project:      HALCON/HLib
 * Description:  Prototypes for HALCON/C interface
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************/

#ifndef HINTERFACE_C_H
#define HINTERFACE_C_H

/*===========================================================================*/
/*                             Defines                                      */
/*===========================================================================*/



/*===========================================================================*/
/*                             Prototypes                                    */
/*===========================================================================*/
extern LIntExport Herror
HcErrorHandling(Hproc_handle ph, Herror err );

extern LIntExport Herror
HcException(INT op_id, Herror err );

extern LIntExport Herror 
HcPreCall(INT proc_index, Hproc_handle *ph);

extern LIntExport Herror
HcCall(Hproc_handle ph);

extern LIntExport Herror 
HcPostCall(Hproc_handle ph, Herror err);

extern LIntExport Herror 
HcStoreIO(Hproc_handle ph, INT par, Hobject inObjVar);

extern LIntExport Herror 
HcStoreICL(Hproc_handle ph, INT par, Hlong value);

extern LIntExport Herror 
HcStoreICD(Hproc_handle ph, INT par, double value);

extern LIntExport Herror 
HcStoreICS(Hproc_handle ph, INT par, char const *value);






#if 0
#define HcStoreICT(PH, PARNR, HTUPLE)                     \
do {                                                      \
  HGetGV_InpCtrlStack_p(PH, PARNR) = (Hctuple*)(HTUPLE);  \
} while(0)

#else
extern LIntExport Herror 
HcStoreICT(Hproc_handle proc_handle, INT par, Htuple const *value);
#endif

#define HcInitOCL( PH, PAR,  PLONG)                                     \
do{                                                                     \
  HWriteGV_OutpCtrlStack_p(PH, PARNR, &HGetGV_OutpCtrlNested(PH, PAR);  \
} while(0)

#define HcInitOCD( PH, PAR,  PLONG)                                     \
do{                                                                     \
  HWriteGV_OutpCtrlStack_p(PH, PARNR, &HGetGV_OutpCtrlNested(PH, PAR);  \
} while(0)

#define HcInitOCS( PH, PAR,  PLONG)                                     \
do{                                                                     \
  HWriteGV_OutpCtrlStack_p(PH, PARNR, &HGetGV_OutpCtrlNested(PH, PAR);  \
} while(0)


#define HcInitOCT( PH, PAR,  PHTUPLE)           \
do{                                             \
  HCT_INIT( (Hctuple*)(PHTUPLE));               \
  HWriteGV_OutpCtrlList_p(PH,PAR,PHTUPLE);      \
} while(0)





extern LIntExport Herror 
HcStoreOO(Hproc_handle proc_handle, INT par, Hobject *outObjVar, Herror err);


extern LIntExport Herror 
HcStoreOCL(Hproc_handle proc_handle, INT par, Hlong *outCtrlVar, Herror err);

extern LIntExport Herror 
HcStoreOCD(Hproc_handle proc_handle, INT par, double *outCtrlVar, Herror err);

extern LIntExport Herror 
HcStoreOCS(Hproc_handle proc_handle, INT par, char *outCtrlVar, Herror err);

extern LIntExport Herror 
HcStoreOCT(Hproc_handle proc_handle, INT par, Htuple *outCtrlVar, Herror err);


#endif
