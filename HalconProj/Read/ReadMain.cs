//
// File generated by HDevelop for HALCON/.NET (C#) Version 18.11.1.1
// Non-ASCII strings in this file are encoded in UTF-8.
// 
// Please note that non-ASCII characters in string constants are exported
// as octal codes in order to guarantee that the strings are correctly
// created on all systems, independent on any compiler settings.
// 
// Source files with different encoding should not be mixed in one project.
//
//  This file is intended to be used with the HDevelopTemplate or
//  HDevelopTemplateWPF projects located under %HALCONEXAMPLES%\c#

using System;
using HalconDotNet;

public partial class HDevelopExport
{
  public HTuple hv_ExpDefaultWinHandle;

  // Main procedure 
  private void action()
  {


    // Local iconic variables 

    HObject ho_Image;

    // Local control variables 

    HTuple hv_Width = new HTuple(), hv_Height = new HTuple();
    // Initialize local and output iconic variables 
    HOperatorSet.GenEmptyObj(out ho_Image);
    ho_Image.Dispose();
    HOperatorSet.ReadImage(out ho_Image, "printer_chip/printer_chip_01");
    HOperatorSet.DispObj(ho_Image, hv_ExpDefaultWinHandle);
    hv_Width.Dispose();hv_Height.Dispose();
    HOperatorSet.GetImageSize(ho_Image, out hv_Width, out hv_Height);


    ho_Image.Dispose();

    hv_Width.Dispose();
    hv_Height.Dispose();

  }

  public void InitHalcon()
  {
    // Default settings used in HDevelop
    HOperatorSet.SetSystem("width", 512);
    HOperatorSet.SetSystem("height", 512);
  }

  public void RunHalcon(HTuple Window)
  {
    hv_ExpDefaultWinHandle = Window;
    action();
  }

}

