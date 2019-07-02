/*****************************************************************************
 * HLexicon.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HLexicon
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_LEXICON_H
#define H_LEXICON_H


#include "HCPPToolRef.h"


namespace Halcon {


class LIntExport HLexicon: public HToolBase 
{
public:

  // Tool-specific functional class constructors
  
  HLexicon(const HTuple &Name, const HTuple &Words);
  HLexicon(const char   *Name, const HTuple &Words);

  // Common tool class management functionality

  HLexicon();
  HLexicon(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  // Find a similar word in a lexicon.
  virtual HTuple SuggestLexicon(const Halcon::HTuple &Word, Halcon::HTuple *NumCorrections) const;
  // Find a similar word in a lexicon.
  virtual HTuple SuggestLexicon(const Halcon::HTuple &Word, Hlong *NumCorrections) const;
  // Find a similar word in a lexicon.
  virtual HTuple SuggestLexicon(const char *Word, Halcon::HTuple *NumCorrections) const;
  // Find a similar word in a lexicon.
  virtual HTuple SuggestLexicon(const char *Word, Hlong *NumCorrections) const;
  // Check if a word is contained in a lexicon.
  virtual Hlong LookupLexicon(const Halcon::HTuple &Word) const;
  // Check if a word is contained in a lexicon.
  virtual Hlong LookupLexicon(const char *Word) const;
  // Query all words from a lexicon.
  virtual HTuple InspectLexicon() const;
  // Create a lexicon from a text file.
  virtual void ImportLexicon(const Halcon::HTuple &Name, const Halcon::HTuple &FileName);
  // Create a lexicon from a text file.
  virtual void ImportLexicon(const char *Name, const char *FileName);
  // Create a lexicon from a tuple of words.
  virtual void CreateLexicon(const Halcon::HTuple &Name, const Halcon::HTuple &Words);
};

}

#endif
