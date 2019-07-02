/*****************************************************************************
 * HInstance.h
 ***************************************************************************** 
 *
 * Project:      HALCON/HLib
 * Description:  handling of HALCON operator instances and HALCON threads; 
 *               provides procedural access to global context variables;
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 * 
 *
 */


#ifndef HINSTANCE_H
#define HINSTANCE_H


#if defined(__cplusplus)
extern "C" {
#endif

/* -------- H_INSTANCE_INFO_EXCLUSIVE - */
#define HGdef_obj_images                 2
#define HGInpObjList                     3
#define HGInpObjNum                      4
#define HGnum_obj                        7 /* for compatibility reasons */
#define HGInpCtrlList                    9
#define HGctrl_inherited                10
#define HGusedOCP                       16
#define HGOutpCtrlList                  17
#define HGStringMem                     19
#define HGLastStringMem                 20
#define HGMem_handle                    21
#define HGDB_handle                     22

/* -------- H_INSTANCE_INFO_SHARED ---- */
#define HGinp_obj                       23
#define HGoutp_obj                      24
#define HGinp_ctrl                      25
#define HGoutp_ctrl                     26
#define HGNewFilter                     27
#define HGnf_inp_key                    28
#define HGnf_index                      29
#define HGnf_img_type                   30
#define HGnf_out                        31
#define HGnf_image1                     32
#define HGnf_image2                     33
#define HGnf_num                        34
#define HGnf_num_alloc                  35
#define HGmutex_NewFil                  36

#define HGCompactObj                    41
#define HGLangIntID                     98

/* -------- H_SYS_INFO_EXCLUSIVE ------ */
#define HGimsize                        37
#define HGWidth                         38
#define HGHeight                        39
#define HGCurrentRL                     40
#define HGcompute_device                158
#define HGcompute_device_id             159
#define HGcompute_device_handle         160

/* -------- H_SYS_INFO_SHARED --------- */
/* CompactObj / 41 moved INSTANCE_INFO_SHARED */ 
#define HGDBInit                        42
#define HGcheck                         43
#define HGNoObjResult                   44
#define HGEmptyObjResult                45
#define HGWindowName                    46
#define HGIconName                      47
#define HGWinBackColor                  48
#define HGWinBorderColor                49
#define HGXPackage                      50
#define HGBackingStore                  51
#define HGGraphicBorderWidth            52
#define HGNumGrey                       53
#define HGNumGraphicColors              54
#define HGNumGreyPercentage             55
#define HGNumGraphicColorsPercentage    56
#define HGUserDefinedColors             57
#define HGDrawMode                      58
#define HGIgnoreColormap                59
#define HGUpdateLUT                     60
#define HGInt2Bits                      61
#define HGStoreEmptyRegion              62
#define HGClipRegion                    63
#define HGInitNewImage                  64
#define HGNeighbour                     65
#define HGFlushGraphic                  66
#define HGFlushFile                     67
#define HGTestRegImaInters              68
#define HGPixelRatio                    69
#define HGWidthMult                     70
#define HGHeightMult                    71
#define HGZoomPixel                     72
#define HGPixelWidth                    73
#define HGPixelHeight                   74
#define HGGrStackSize                   77
#define HGUseWindowThread              100
#define HGHalconDir                    166
#define HGExamplesDir                  165
#define HGImageDir                      75
#define HG3DModelDir                   164
#define HGHelpDir                       76
/* Reference & HTML dir obsolete (77/78) */
#define HGLicenseDir                    79
#define HGLUTDir                        80
#define HGFilterDir                     81
#define HGOCRDir                        82
#define HGCalibDir                      83
#define HGLS_R                          84
#define HGOnlyLines                     85
#define HGDoIntZoom                     86
#define HGUsedModules                   87
#define HGmutex_flexlm                  88
#define HGmutex_ChUsMod                 89
#define HGmutex_boot                    90
#define HGmutex_measure                 91
#define HGmutex_socket                  92
/* HGmutex_strtok, obsolete (93) */
#define HGmutex_ltime                   94
#define HGmutex_graphics                96
#define HGmutex_graphics_call           99
#define HGmutex_fft                     97
/* HGmutex_metrology_model, obsolete (98) */
#define HGmutex_transfer                161
#define HGmutex_text_finder             162
#define HGmutex_opengl                  163
/* LangIntID / 98 added to INSTANCE_INFO_SHARED */ 
/* HGUseWindowThread / 100 added to H_SYS_INFO_SHARED */ 

/* -------- HALCON_PROC_HANDLE -------- */
#define HGproc_index                    101

/*--- H_INSTANCE_INFO_SHARED add on --- */
#define HGnf_rem_inp_keys               110
 
/*--- H_SYS_INFO_SHARED add on --- */
#define HGHProcNum                      140
#define HGmutex_colorlut                150
#define HGmutex_matrix                  151

/*--- HROInfo --- */
#define HGVersion                       152
#define HGLastUpdate                    153
#define HGparallel                      154
#define HGcpu_num                       155
#define HGlocale_filename_encoding      156
#define HGCancelDrawResult              157

/*--- CPU features in HROInfo, for HGVGet_CPUFeature ---*/
#define HCPU_FEATURE_MMX                1
#define HCPU_FEATURE_SSE                2
#define HCPU_FEATURE_SSE2               3
#define HCPU_FEATURE_SSE3               4
#define HCPU_FEATURE_SSSE3              5
#define HCPU_FEATURE_SSE41              6
#define HCPU_FEATURE_SSE42              7
#define HCPU_FEATURE_AVX                8

/*--- CPU caches in HROInfo, for HGVGet_CPUCache ---*/
#define HCPU_CACHE_LEVEL1_DATA          1
#define HCPU_CACHE_LEVEL1_INST          2
#define HCPU_CACHE_LEVEL2               3
#define HCPU_CACHE_LEVEL3               4

/* HALCON library already initialized? */
extern HLibExport HBOOL  IsInitHlib(void);
/* HAccessGlVar - access to global HALCON context variables                  */
extern HLibExport Herror HAccessGlVar(Hproc_handle proc_handle, INT element,
                                      HBYTE to_do, VOIDP r_value, 
                                      double w_value, char *w_string,
                                      Hkey w_key, INT4_8 index);
/* HCheckObjNum - check whether specified object number is in range          */
extern HLibExport HBOOL HCheckObjNum(Hproc_handle proc_handle,INT par_num,
                                     INT4_8 obj_num);
extern HLibExport Hproc_handle HTSProcHandle(void);
extern HLibExport Hproc_handle HTSHProcIndepend(INT op_id);
/* HGetHProc - get a thread specific HALCON operator call instance (no full 
 * use)  */
extern HLibExport Herror HGetHProc(INT4 proc_index, Hproc_handle *ph);
/* HPutHProc - return a thread specific HALCON operator call instance to Core*/
extern HLibExport Herror HPutHProc(Hproc_handle proc_handle);
/* HGetRecHProc - get a thread specific HALCON operator call instance, able 
 * to handle recursive calls  (no full use)  */
extern HLibExport Herror HGetRecHProc(INT4 proc_index, Hproc_handle *ph);
/* HPutRecHProc - return a thread specific (recursiveable) HALCON operator 
 * call instance */
extern HLibExport Herror HPutRecHProc(Hproc_handle proc_handle);
/* HCreateHProc - create a new HALCON operator call instance                 */
extern HLibExport Herror HCreateHProc(INT4 current_idx, 
                                      Hproc_handle *proc_handle);
/* HDeleteHProc - delete a HALCON operator call instance                     */
extern HLibExport Herror HDeleteHProc(Hproc_handle proc_handle,HBOOL last, 
                                      Herror proc_result);

extern HLibExport HBOOL  HOpIdIsValid(INT opid);
extern HLibExport HBOOL  HOpIdIsSystemCall(INT opid);

extern HLibExport INT    HGVGet_NumSysOp( void);/* number of system operators*/
extern HLibExport INT    HGVGet_NumOp(void);    /* total number of operators */
extern HLibExport char const *HGVGet_Language(void);
extern HLibExport INT    HGVGet_locale_filename_encoding(void);
extern HLibExport void   HGVSet_locale_filename_encoding(INT);
extern HLibExport HBOOL  HGVGet_CPUFeature(INT feature);
extern HLibExport INT4_8 HGVGet_CPUCache(INT level);

extern HLibExport char const *HOIGet_InpCtrlParType(INT opid);
extern HLibExport char const *HOIGet_OutpCtrlParType(INT opid);

extern HLibExport INT    HOIGet_NumInpCtrlPar(INT opid);
extern HLibExport INT    HOIGet_NumOutpCtrlPar(INT opid);
extern HLibExport INT    HOIGet_NumInpObjPar(INT opid);
extern HLibExport INT    HOIGet_NumOutpObjPar(INT opid);
extern HLibExport char const *HOIGet_LogicalName(INT opid);

extern HLibExport INT         HPHGet_NumInpCtrlPar(Hproc_handle ph);
extern HLibExport INT         HPHGet_NumOutpCtrlPar(Hproc_handle ph);
extern HLibExport INT         HPHGet_NumInpObjPar(Hproc_handle ph);
extern HLibExport INT         HPHGet_NumOutpObjPar(Hproc_handle ph);
extern HLibExport INT4        HPHGet_proc_index(Hproc_handle ph);
extern HLibExport const char *HPHGet_LogicalName(Hproc_handle ph);
extern HLibExport INT4        HPHGet_check(Hproc_handle ph);
extern HLibExport INT4_8      HPHGet_PreviousMaxAlloc(Hproc_handle ph);

/* HSetAllFreeOCP - set freeing flag of all outp. ctrl.parameters  */
extern HLibExport void HSetAllfreeOCP(Hproc_handle ph, HBOOL flag);

extern HBOOL  HGetInstanceMemCacheMode (void);
extern Herror HSetInstanceMemCacheMode (Hproc_handle ph, HBOOL mode );

/* HProcSetStop sets a stop-flag for all running operator instances 
 * (asynchonously). Opertors supporting this flag will break execution and
 * return (without an error) */
extern HLibExport Herror HProcSetStop(INT mode);

/* HProcBreak sets a beak flag for all running operator instances 
 * (asynchonously) */
extern HLibExport Herror HProcBreak(void);

#if defined(__cplusplus)
}
#endif


#endif
