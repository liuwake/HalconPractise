/*****************************************************************************
 * HBaseGP.h
 ***************************************************************************** 
 *
 * Project:     HALCON/libhalcon
 * Description: Basic tools
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 * 
 *
 */


#ifndef HBASEGP_H
#define HBASEGP_H


#if defined(__cplusplus)
extern "C" {
#endif



extern HLibExport Herror HSetImageTime(Hproc_handle proc_handle,Himage *image);

extern HLibExport Herror HImageName2Type(const char *str, INT *kind);

extern HLibExport Herror HPrepNewImage(Hproc_handle proc_handle, HIMGDIM width,
                                       HIMGDIM height);

extern HLibExport double Hatan2(double x, double y);

extern HLibExport Herror HStripQuotes(Hproc_handle proc_handle, char *in,
                                      char **out);

extern HLibExport char* HGetHalconRoot(void);
extern HLibExport char* HGetHalconLibraryPath(void);

extern HLibExport HBOOL HSetEnv(const char *name, const char *value);
extern HLibExport char* HGetEnv(const char *name);
extern HLibExport char* HGetEnvRaw(const char *name);
extern HLibExport void HGetEnvFree(char* name);

extern HLibExport Herror HIncrRL(Hproc_handle proc_handle);

extern HLibExport Herror HIncrRLNum(Hproc_handle proc_handle, size_t num);

extern HLibExport Herror HCopyData(const void *source, void *destination,
                                   size_t size);

extern HLibExport Herror HSetData(void *c, INT val, size_t size);

extern HLibExport Herror HClearData(VOIDP c, size_t size);

extern HLibExport Herror HCopyImage(const Himage *in, Himage *out);

extern HLibExport Herror HClearImage(Himage *image);

extern HLibExport Herror HSetImage(Himage *image, double grayval);

extern HLibExport Herror HAdaptImsize(Hproc_handle proc_handle, HIMGDIM width,
                                      HIMGDIM height);

extern HLibExport Herror HFreeTmpImage(Hproc_handle proc_handle,
                                       Himage *image);

extern HLibExport Herror HTmpImage(Hproc_handle proc_handle, Himage *image,
                                   INT kind, HIMGDIM width, HIMGDIM height,
                                   HBOOL clear);

extern HLibExport Herror HFreeLocalImage(Hproc_handle proc_handle,
                                         Himage *image);

extern HLibExport Herror HLocalImageToGlobal(Hproc_handle proc_handle,
                                             Himage *image);

extern HLibExport Herror HLocalImage(Hproc_handle proc_handle, Himage *image,
                                     INT kind, HIMGDIM width, HIMGDIM height,
                                     HBOOL clear);

extern HLibExport Herror HCrImageCkD(Hproc_handle proc_handle, 
                                     Hrlregion *domain, 
                                     Hkey key_in, INT num, INT type, 
                                     HIMGDIM width, HIMGDIM height,
                                     Hkey *key_out, Himage *image);

extern HLibExport Herror HCrImage(Hproc_handle proc_handle, Hkey key_in,
                                  INT num, INT type, HIMGDIM width,
                                  HIMGDIM height, Hkey *key_out,
                                  Himage *image);

extern HLibExport Herror HCrImageMatrix(Hproc_handle proc_id, Himage *image,
                                        Hkey key);

extern HLibExport Herror HCrImageMKeyCkD(Hproc_handle proc_handle,
                                         Hrlregion *domain[],
                                         Hkey key_in[], INT num_keys,
                                         INT num, INT type, HIMGDIM width,
                                         HIMGDIM height, Hkey *key_out,
                                         Himage *image);

extern HLibExport Herror HCrImageMKey(Hproc_handle proc_handle,
                                      Hkey key_in[], INT num_keys,
                                      INT num, INT type, HIMGDIM width,
                                      HIMGDIM height, Hkey *key_out,
                                      Himage *image);

extern HLibExport Herror HFreeImage(Hproc_handle proc_handle, Himage *image);

extern HLibExport Herror HNewImage(Hproc_handle proc_handle, Himage *image,
                                   INT kind, HIMGDIM width, HIMGDIM height);

extern HLibExport Herror HNewImagePtr(Hproc_handle proc_handle, Himage *image,
                                      INT kind, HIMGDIM width, HIMGDIM height,
                                      VOIDP data, HBOOL initImg);

Herror HSortDouble(Hproc_handle proc_handle, double *array,
                   INT4_8 num, HBOOL ascending);

Herror HSortINT4_8(Hproc_handle proc_handle, INT4_8 *array,
                   INT4_8 num, HBOOL ascending);

Herror HSortString(Hproc_handle proc_handle, char **array,
                   INT4_8 num, HBOOL ascending);

#if defined(__cplusplus)
}
#endif


#endif
