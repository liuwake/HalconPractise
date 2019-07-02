/*****************************************************************************
 * CIOFrameGrab.h
 *****************************************************************************
 *
 * Project:     HALCON/libhalcon
 * Description: Image acquisition integration interface
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 *
 *****************************************************************************
 *
 *
 *****************************************************************************
 *
 * See also:  "Image Acquisition Integration Programmer's Manual"
 *
 *****************************************************************************
 */


#ifndef CIOFRAMEGRAB_H
#define CIOFRAMEGRAB_H

#ifndef HC_NO_FRAMEGRABBER

#define FG_INTERFACE_VERSION 6

#define FG_NUM_RESERVED      20

#ifndef HE_TI_C6X
#define FG_MAX_NUM  128 /* max. number of different frame grabber (classes) */
#define FG_MAX_INST 256 /* max. number of handles (instances) per class     */
#else
#define FG_MAX_NUM  1
#define FG_MAX_INST 1
#endif

#ifndef FG_PREFIX
#if defined(WIN32) && !defined(H_PARALLEL)
#define FG_PREFIX "seqhAcq"
#else
#define FG_PREFIX "hAcq"
#endif
#endif

#ifndef XL_SUFFIX
#if defined(HC_LARGE_IMAGES)
#define XL_SUFFIX "xl"
#else
#define XL_SUFFIX ""
#endif
#endif

#define FG_QUERY_PORT             0      /* Query: Available port values     */
#define FG_QUERY_CAMERA_TYPE      1      /* Query: Available camera types    */
#define FG_QUERY_GENERAL          2      /* Query: General information       */
#define FG_QUERY_DEFAULTS         3      /* Query: Default values            */
#define FG_QUERY_PARAMETERS       4      /* Query: Additional parameters     */
#define FG_QUERY_INFO_BOARDS      5      /* Query: Actual installed boards   */
#define FG_QUERY_REVISION         6      /* Query: Interface revision        */
#define FG_QUERY_INFO_PARAMETERS  7      /* Query: Info to avail. parameters */
#define FG_QUERY_FIELD            8      /* Query: Available field values    */
#define FG_QUERY_BITS_PER_CHANNEL 9      /* Query: Available bits per channel*/
#define FG_QUERY_COLOR_SPACE      10     /* Query: Available color spaces    */
#define FG_QUERY_EXT_TRIGGER      11     /* Query: Available ext. trigger    */
#define FG_QUERY_DEVICE           12     /* Query: Available device values   */
#define FG_QUERY_PARAMETERS_RO    13     /* Query: Add. read-only parameters */
#define FG_QUERY_PARAMETERS_WO    14     /* Query: Add. write-only parameters*/
#define FG_QUERY_IMAGE_HEIGHT     15     /* Query: Available image_height    */
#define FG_QUERY_IMAGE_WIDTH      16     /* Query: Available image_widht     */
#define FG_QUERY_START_ROW        17     /* Query: Available start_row values*/
#define FG_QUERY_START_COLUMN     18     /* Query: Available start_column    */
#define FG_QUERY_HORIZONTAL_RESOLUTION 19     /* Query: horizontal_resolution*/
#define FG_QUERY_VERTICAL_RESOLUTION   20     /* Query: vertical resolution  */
#define FG_QUERY_LINE_IN          21     /* Query: Available line_in values  */
#define FG_QUERY_PARAMETERS_HIDDEN 22    /* Query: Not for display in        */
                                         /*        generic GUI               */
#define FG_QUERY_GENERIC          23     /* Query: Available generic values  */

#define FG_FIRST_FIELD            0      /* grab first field                 */
#define FG_SECOND_FIELD           1      /* grab second field                */
#define FG_NEXT_FIELD             3      /* grab next field                  */
#define FG_FULL_FRAME             2      /* grab frame / interlaced          */
#define FG_PROGRESSIVE_FRAME      4      /* grab frame / progressive         */
#define FG_FIELD_DEFAULT          5      /* default                          */

/* corresponding text encoding: */
#define FG_FIRST_FIELD_TXT               "first"
#define FG_SECOND_FIELD_TXT              "second"
#define FG_NEXT_FIELD_TXT                "next"
#define FG_FULL_FRAME_TXT                "interlaced"
#define FG_PROGRESSIVE_FRAME_TXT         "progressive"
#define FG_FIELD_DEFAULT_TXT             "default"

#define FG_PARAM_HORIZONTAL_RESOLUTION   "horizontal_resolution"
#define FG_PARAM_VERTICAL_RESOLUTION     "vertical_resolution"
#define FG_PARAM_IMAGE_WIDTH             "image_width"
#define FG_PARAM_IMAGE_HEIGHT            "image_height"
#define FG_PARAM_START_ROW               "start_row"
#define FG_PARAM_START_COL               "start_column"
#define FG_PARAM_FIELD                   "field"
#define FG_PARAM_BITS_PER_CHANNEL        "bits_per_channel"
#define FG_PARAM_COLOR_SPACE             "color_space"
#define FG_PARAM_GAIN                    "gain"        // only for compatibilty
#define FG_PARAM_GENERIC                 "generic"
#define FG_PARAM_EXT_TRIGGER             "external_trigger"
#define FG_PARAM_CAMERA_TYPE             "camera_type"
#define FG_PARAM_DEVICE                  "device"
#define FG_PARAM_PORT                    "port"
#define FG_PARAM_LINE_IN                 "line_in"

#define FG_MAX_CHANNELS 1000 /* max. number of channels that can be grabbed */

#define FG_MAX_LUT_LENGTH          65536  /* max. length of a Lut */

#define FG_INIT_NAME               "FGInit"
#define FG_FLAGS_NAME              "FGFlags"

#define FG_MAX_PARAM               2048

/* defines for encoding which method is used for allocating Hrlregions */
#define FG_RLALLOC_PERMANENT       1
#define FG_RLALLOC_TMP             2
#define FG_RLALLOC_LOCAL           4

/* This Macro checks the syntax of Generic.                                  *
 * Call it within the loop over the tuple of Generic parameters.             *
 * i          index of parameter                                             *
 * pos        char *, that points to the "="                                 *
 * ret_act_t  return action in case of wrong type (H_ERR_FGPART)             *
 * ret_act_v  return action in case of wrong value (H_ERR_FGPARV)            */
#define CHECK_GENERIC(i,pos,ret_act_t,ret_act_v) { \
  if (fginst->generic[(i)].type == STRING_PAR) \
  { \
    if (!strlen(fginst->generic[i].par.s)) \
      continue; \
    if ((pos) = strstr(fginst->generic[(i)].par.s,"=")) \
    { \
      if (strstr((pos) + 1,"=")) \
      { \
        sprintf(errMsg,"Error: More than one '=' found in %s. " \
                       "Please make sure to use a syntax like this " \
                       "for multiple parameters: " \
                       "['par1=arg1','par2=arg2' ...]", \
                fginst->generic[i].par.s); \
        MY_PRINT_ERROR_MESSAGE(errMsg); \
        ret_act_v; \
      } \
    } \
    else \
    { \
      sprintf(errMsg,"Error: No '=' found in %s." \
                     "Please make sure to use a syntax like this: " \
                     "'parameter=argument'", \
              fginst->generic[i].par.s); \
      MY_PRINT_ERROR_MESSAGE(errMsg); \
      ret_act_v; \
    } \
  } \
  else \
  { \
    if (fginst->num_generic == 1 && \
       (fginst->generic[(i)].type == LONG_PAR && \
        fginst->generic[(i)].par.l == -1) || \
       (fginst->generic[(i)].type == FLOAT_PAR && \
        fginst->generic[(i)].par.f == -1.0)) \
      break; \
    else \
    { \
      MY_PRINT_ERROR_MESSAGE("Generic parameter accepts " \
                             "only string values!"); \
      ret_act_t; \
    } \
  } \
}

/* define HALCON acquisition callback */
#ifndef _WIN32
#define __stdcall
#endif
typedef Herror (__stdcall *HAcqCallback)(void *AcqHandle,void *Context,
                                         void *UserContext);


#if defined(__cplusplus)
extern "C" {
#endif

#ifndef HCVERSION_H
#ifndef _WIN32
/* time */
#  if !defined(HE_TI_C6X)
#    if defined(__vxworks)
#      include <sys/times.h>
#    else
#      include <sys/time.h>
#    endif /* __vxworks */
#  else
struct timezone
{
  int tz_minuteswest;   /* minutes W of Greenwich */
  int tz_dsttime;       /* type of dst correction */
};

#    if !defined(_B_TIME_H_)
struct timeval {
    int     tv_sec;         /* seconds */
    int     tv_usec;        /* and microseconds */
};
#    endif
#  endif /* ! HE_TI_C6X */
#endif /* _WIN32 */
#endif /* ifndef HCVERSION_H */

/*****************************************************************************
 *
 * struct FGInstance
 *
 *****************************************************************************/

typedef struct _FGInstance {
  struct _FGClass *fgclass;         /* a pointer to the corresponding class */
  /* ----------------------- regular parameters --------------------------- */
  HIMGDIM  horizontal_resolution,   /* desired resolution delivered         */
           vertical_resolution;     /* by the board                         */
  HIMGDIM  image_width,image_height;/* desired image size                   */
  HIMGDIM  start_row,start_col;     /* upper left corner                    */
  INT      field;                   /* even- or odd-field, full image mode  */
  INT      bits_per_channel;        /* color depth per pixel & channel      */
  char     color_space[MAX_STRING]; /* "gray", "rgb", "yuv", ...            */
  float    gain;                    /* for backwards compatibility only!    */
  HBOOL    external_trigger;        /* trigger mode                         */
  char     camera_type[MAX_STRING]; /* used camera type (fg-specific!)      */
  char     device[MAX_STRING];      /* device name                          */
  INT      port;                    /* port to use                          */
  INT      line_in;                 /* multiplexer input line               */
  Hcpar    *generic;                /* generic parameter                    */
  INT      num_generic;
  /* ---------------------- miscellaneous parameters ---------------------- */
  INT4_8   mode;                    /* current operating mode               */
  HIMGDIM  width_max,height_max;    /* maximum image size                   */
  INT      num_channels;            /* number of image channels             */
  HBOOL    async_grab;              /* TRUE <=> async grabbing engaged      */
  Himage   *image;                  /* image objects to grab into (aux.)    */
  void     *gen_pointer;            /* generic pointer (auxiliary)          */
  /* -------------------- external memory allocation ---------------------- */
  HBOOL    halcon_malloc;           /* TRUE <-> standard memory allocation  */
                                    /* by HNewImage                         */
  HImageFreeProc clear_proc;        /* pointer to specific clear function   */
                                    /* (if halcon_malloc==FALSE)            */
} FGInstance;


/*****************************************************************************
 *
 * struct FGClass
 *
 *****************************************************************************/

typedef struct _FGClass {
  /* -------------------------- internal -------------------------------- */
  char  name[MAX_STRING];        /* frame grabber name (interface module) */
  void  *lib_handle;             /* handle of interface library           */
  INT   interface_version;       /* current HALCON frame grabber          */
                                 /* interface version                     */
  INT4  flags;                   /* interface flags                       */
  /* ------------------- properties / management ------------------------ */
  HBOOL  available;              /* supported for the current platform    */
  INT    instances_num;          /* current number instances (INTERNAL!)  */
  INT    instances_max;          /* maximum number of instances           */
  FGInstance *instance[FG_MAX_INST]; /* list of instances (INTERNAL!)     */
  /* ----------------- interface-specific functions --------------------- */
  FGInstance** (*OpenRequest)(Hproc_handle proc_id,FGInstance *fginst);
  Herror (*Open)             (Hproc_handle proc_id,FGInstance *fginst);
  Herror (*Close)            (Hproc_handle proc_id,FGInstance *fginst);
  Herror (*Grab)             (Hproc_handle proc_id,FGInstance *fginst,
                              Himage *image,INT *num_image);
  Herror (*GrabStartAsync)   (Hproc_handle proc_id,FGInstance *fginst,
                              double maxDelay);
  Herror (*GrabAsync)        (Hproc_handle proc_id,FGInstance *fginst,
                              double maxDelay,Himage *image,
                              INT *num_image);
  Herror (*GrabData)         (Hproc_handle proc_id,FGInstance *fginst,
                              Himage **image,INT **num_channel,INT *num_image,
                              Hrlregion ***region,INT *num_region,
                              Hcont ***cont,INT *num_cont,
                              Hcpar **data,INT *num_data);
  Herror (*GrabDataAsync)    (Hproc_handle proc_id,FGInstance *fginst,
                              double maxDelay,Himage **image,
                              INT **num_channel,INT *num_image,
                              Hrlregion ***region,INT *num_region,
                              Hcont ***cont,INT  *num_cont,
                              Hcpar **data,INT *num_data);
  Herror (*Info)             (Hproc_handle proc_id,INT queryType,
                              char **info,Hcpar **values,INT *numValues);
  Herror (*SetParam)         (Hproc_handle proc_id, FGInstance *fginst,
                              char *param,Hcpar *value,INT num);
  Herror (*GetParam)         (Hproc_handle proc_id, FGInstance *fginst,
                              char *param,Hcpar *value,INT *num);
  Herror (*SetLut)           (Hproc_handle proc_id,FGInstance *fginst,
                              INT4_8 *red,INT4_8 *green,INT4_8 *blue,INT num);
  Herror (*GetLut)           (Hproc_handle proc_id,FGInstance *fginst,
                              INT4_8 *red,INT4_8 *green,INT4_8 *blue,INT *num);
  Herror (*SetCallback)      (Hproc_handle proc_id,FGInstance *fginst,
                              char *callback_type,
                              HAcqCallback callback_function,
                              void* user_context);
  Herror (*GetCallback)      (Hproc_handle proc_id,FGInstance *fginst,
                              char *callback_type,
                              HAcqCallback *callback_function,
                              void** user_context);

  /* -------------------------- default values -------------------------- */
  HIMGDIM  horizontal_resolution,   /* desired resolution delivered         */
           vertical_resolution;     /* by the board                         */
  HIMGDIM  image_width,image_height;/* desired image size                   */
  HIMGDIM  start_row,start_col;     /* upper left corner                    */
  INT      field;                   /* even- or odd-field, full image mode  */
  INT      bits_per_channel;        /* color depth per pixel & channel      */
  char     color_space[MAX_STRING]; /* "gray", "rgb", "yuv", ...            */
  float    gain;                    /* for backwards compatibility only!    */
  HBOOL    external_trigger;        /* trigger mode                         */
  char     camera_type[MAX_STRING]; /* used camera type (fg-specific!)      */
  char     device[MAX_STRING];      /* device name                          */
  INT      port;                    /* port to use                          */
  INT      line_in;                 /* multiplexer input line               */
  Hcpar    *generic;                /* generic parameter                    */
  INT      num_generic;
  /* ------------------------- miscellaneous ---------------------------- */
  void     *reserved[FG_NUM_RESERVED];
} FGClass;

/*
 * Special framegrabber flags. To set the flags, the interface should export
 * the symbol FG_FLAGS_NAME, which must be an INT4. Note that if the interface
 * is openend using the HAddFgClass function, the flags cannot be set.
 *
 * The following flags are defined:
 *
 * FG_FLAG_THREAD_OPEN: if set, the interface is opened and closed from the
 * same thread.
 */
#define FG_FLAG_THREAD_OPEN         (1<<0)

typedef Herror (*FG_INIT_FUNC) (Hproc_handle ,FGClass *);

/* function for integrating image acquisition devices into the system using
   a linked interface (instead of a dynamic object accessed online) */
extern HLibExport Herror HAddFgClass(Hproc_handle proc_id, char *name,
                                     FG_INIT_FUNC init_func);

/* function for writing the interface specific default values into an
   Hcpar array */
extern HLibExport Herror HFgGetDefaults(Hproc_handle proc_id, FGClass *fgClass,
                                        Hcpar **values, INT *numValues);

/* helper function in HALCON library for displaying low-level error messages */
extern HLibExport Herror IOPrintErrorMessage(char *err);

/* prototypes to be included in global startup and shutdown */
Herror HStartupFramegrabberInterface(void);
Herror HShutdownFramegrabberInterface(void);

#if defined(__cplusplus)
}
#endif

#endif /* ifndef HC_NO_FRAMEGRABBER */

#endif /* ifndef CIOFRAMEGRAB_H */
