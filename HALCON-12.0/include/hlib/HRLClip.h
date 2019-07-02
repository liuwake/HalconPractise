/*****************************************************************************
 * HRLClip.h
 *****************************************************************************
 *
 * Project:     HALCON/libhalcon
 * Description: Rectangular clipping of regions (Hrlregion)
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 *
 *****************************************************************************
 *
 *
 */


#ifndef HRLCLIP_H
#define HRLCLIP_H


#if defined(__cplusplus)
extern "C" {
#endif


extern HLibExport Herror HRLClipImsize(Hproc_handle proc_id,
                                       Hrlregion *region);

extern HLibExport Herror HRLClipImsize2(Hproc_handle proc_id,
                                        Hrlregion *region, Hrlregion *clipped);

extern HLibExport Herror HRLClipp2(Hproc_handle proc_id,
                                   Hrlregion *in_out, INT l1, INT c1,
                                   INT l2, INT c2);


extern HLibExport Herror HRLRelClipp(Hproc_handle proc_id,
                                     Hrlregion *region, INT top, INT bottom,
                                     INT left, INT right, Hrlregion *clipped);

extern HLibExport Herror HRLClipp(Hproc_handle proc_id,
                                  const Hrlregion *region_in,
                                  INT l1, INT c1, INT l2, INT c2,
                                  Hrlregion *clipped);

extern HLibExport Herror HRLHdiv(Hproc_handle proc_id,
                                 Hrlregion *Obj_ein, INT horizontale,
                                 Hrlregion *tO_oben, Hrlregion *tO_unten);

extern HLibExport Herror HRLVdiv(Hproc_handle proc_id,
                                 Hrlregion *Obj_ein, INT vertikale,
                                 Hrlregion *tO_links, Hrlregion *tO_rechts);

extern HLibExport Herror HRLDecomp(Hrlregion *image_domain,
                                   INT l1, INT c1, INT l2, INT c2,
                                   Hrlregion *inner, Hrlregion *border);

extern HLibExport Herror HRCDecomp(Hvrlregion *region,
                                   INT l1, INT c1, INT l2, INT c2,
                                   Hvrlregion *inner, Hvrlregion *outer);

extern HLibExport Herror HRLClipBottomRight(Hrlregion * H_RESTRICT region,
                                            HIMGCOOR max_l, HIMGCOOR max_c);

#if defined(__cplusplus)
}
#endif


#endif
