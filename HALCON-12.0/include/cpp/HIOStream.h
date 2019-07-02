/*****************************************************************************
 * HIOStream.h
 *****************************************************************************
 *
 * Project:     HALCON/C++
 * Description: HALCON/C++ iostream operators
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 *
 *****************************************************************************
 *
 *
 */

#ifndef HIOSTREAM_H
#define HIOSTREAM_H


#if !defined(_WIN32_WCE)
#if defined(__sgi) || defined(__hpux)
#define USE_IOSTREAM_H
#endif
#if defined(USE_IOSTREAM_H)
#include <iostream.h>
#include <fstream.h>
#else
#include <iostream>
#include <fstream>
#endif
#include "HalconCpp.h"


#if !defined(USE_IOSTREAM_H)
#define HISTREAM std::istream
#define HOSTREAM std::ostream
#else
#define HISTREAM istream
#define HOSTREAM ostream
#endif

namespace Halcon {
  inline HOSTREAM& operator<<(HOSTREAM &s, const Halcon::HTuple &t);
  inline HISTREAM& operator>>(HISTREAM &s, Halcon::HTuple &t);
}

inline HOSTREAM& Halcon::operator<<(HOSTREAM &s, const Halcon::HTuple &t)
{
  char h[MAX_STRING];

  s << '[';
  for (int i=0; i<t.Num(); i++)
  {
    switch (t[i].ValType()) {
      case Halcon::DoubleVal:
        sprintf(h,"%f,",t[i].D());
        break;
      case Halcon::LongVal:
        sprintf(h,"%"LONG_FORMAT"d,",t[i].L());
        break;
      case Halcon::StringVal:
        sprintf(h,"'%s',",t[i].S());
        break;
      default:
        sprintf(h,"*,");
        break;
    }
    if (i == t.Num()-1)
      h[strlen(h)-1] = 0;
    s << h;
  }
  return s << ']';
}

inline HISTREAM& Halcon::operator>>(HISTREAM &s, Halcon::HTuple &t)
{
  char   buf[MAX_STRING];
  char   c;
  int    i, j, k, n, cont;
  Hlong   l;
  double d;

  t.Reset();
  while (s.get(c))
  {
    if (!isspace(c))
      break;
    if (s.eof())
      return s;
  }
  if (c != '[')
    return s;
  i = 0;
  for (;;)
  {
    j = 0;
    cont = TRUE;
    while (s.get(c))
    {
      if (s.eof())
      {
        t.Reset();
        return s;
      }
      if (c == ',')
      {
        cont = TRUE;
        break;
      }
      else if (c == ']')
      {
        cont = FALSE;
        break;
      }
      if (j < MAX_STRING-1)
        buf[j++] = c;
    }
    buf[j++] = '\0';
    if (j < 1)
    {
      t.Reset();
      return s;
    }
    if (j > 2 && buf[0] == '\'' && buf[j-2] == '\'')
    {
      buf[j-2] = '\0';
      t[i++] = buf+1;
    }
    else
    {
      for (k=0; k<j; k++)
        if (buf[k] == '.')
          break;
      if (k < j)
      {
        n = sscanf(buf,"%lf",&d);
        if (n == 1)
          t[i++] = d;
      }
      else
      {
        n = sscanf(buf,"%"LONG_FORMAT"d",&l);
        if (n == 1)
          t[i++] = l;
      }
    }
    if (!cont)
      break;
  }
  return s;
}

#endif /* !_WIN32_WCE */


#endif
