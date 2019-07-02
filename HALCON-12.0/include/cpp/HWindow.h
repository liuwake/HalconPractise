/*****************************************************************************
 * HWindow.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Windows management
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_WINDOW_H
#define H_WINDOW_H


namespace Halcon {


class LIntExport HWindow: public HRootObject 
{

public:

  HWindow(int Row, int Column, int Width, int Height,
          const HWindow &Father, const char *Mode = "", 
          const char *Host = "");

  HWindow(int Row=0, int Column=0, int Width=-1, int Height=-1,
          Hlong Father = 0, const char *Mode = "", const char *Host = "",
          HBool bOpen = TRUE);

  HWindow(const char *mode);

  // Destructor
  ~HWindow(void);

  const char *ClassName(void) const {
    return "HBaseWindow";
  }
  // wait for a click with the mouse into the window
  void        Click(void) const;
  // return the HALCON internal handle of the HWindow
  Hlong        WindowHandle(void) const {
    return id;
  }
  // display an arbitrary HObject in the window
  void        Display(const HObject &hObj) {
    hObj.Display(*this);
  }
  // display an arbitrary HObjectArray in the window
  void        Display(const HObjectArray &hObj) {
    hObj.Display(*this);
  }
  HDPoint2D   GetMbutton(int *button) const;
  HDPoint2D   GetMbutton(void) const;
  HDPoint2D   GetMposition(int *button) const;
  HDPoint2D   GetMposition(void) const;
  int         GetButton(void) const;
  HCircle     DrawCircle(void) const;
  HEllipse    DrawEllipse(void) const;
  HRectangle1 DrawRectangle1(void) const;
  HRectangle2 DrawRectangle2(void) const;

private:
  HWindow(const HWindow &w);
  HWindow operator = (const HWindow &w);
  Hlong  id;

public:
  // Fenster oeffnen
  void OpenWindow(int Row=0, int Column=0, int Width=-1, int Height=-1,
                  Hlong Father = 0, const char *Mode = "",
                  const char *Host = "");
  // "externes" Fenster
  void NewExternWindow(Hlong HWnd, int Row, 
                       int Column, int Width, int Height);
  // set dc of extern Window
  void SetDC(Hlong HDC);
  
  void CloseWindow();
  // Gets a copy of the background image of the HALCON window.
  virtual HImage GetWindowBackgroundImage() const;
  // Detach the background image from a HALCON window.
  virtual void DetachBackgroundFromWindow() const;
  // Attach a background image to a HALCON window.
  virtual void AttachBackgroundToWindow(const HImage &Image) const;
  // Detach an existing drawing object from a HALCON window.
  virtual void DetachDrawingObjectFromWindow(const Halcon::HDrawingObject &DrawID) const;
  // Attach an existing drawing object to a HALCON window.
  virtual void AttachDrawingObjectToWindow(const Halcon::HDrawingObject &DrawID) const;
  // Modify the pose of a 3D plot.
  virtual void UpdateWindowPose(const Halcon::HTuple &LastRow, const Halcon::HTuple &LastCol, const Halcon::HTuple &CurrentRow, const Halcon::HTuple &CurrentCol, const Halcon::HTuple &Mode) const;
  // Modify the pose of a 3D plot.
  virtual void UpdateWindowPose(double LastRow, double LastCol, double CurrentRow, double CurrentCol, const char *Mode) const;
  // Calculates image coordinates for a point in a 3D plot window.
  virtual Hlong UnprojectCoordinates(const HImage &Image, const Halcon::HTuple &Row, const Halcon::HTuple &Column, Halcon::HTuple *ImageColumn, Halcon::HTuple *Height) const;
  // Calculates image coordinates for a point in a 3D plot window.
  virtual Hlong UnprojectCoordinates(const HImage &Image, double Row, double Column, Halcon::HTuple *ImageColumn, Halcon::HTuple *Height) const;
  // Get the operating system window handle.
  virtual Hlong GetOsWindowHandle(Halcon::HTuple *OSDisplayHandle) const;
  // Set the device context of a virtual graphics window (Windows NT).
  virtual void SetWindowDc(const Halcon::HTuple &WINHDC) const;
  // Set the device context of a virtual graphics window (Windows NT).
  virtual void SetWindowDc(Hlong WINHDC) const;
  // Create a virtual graphics window under Windows.
  virtual Hlong NewExternWindow(const Halcon::HTuple &WINHWnd, const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Width, const Halcon::HTuple &Height) const;
  // Create a virtual graphics window under Windows.
  virtual Hlong NewExternWindow(Hlong WINHWnd, Hlong Row, Hlong Column, Hlong Width, Hlong Height) const;
  // Interactive output from two window buffers.
  virtual void SlideImage(const Halcon::HTuple &WindowHandleSource2, const Halcon::HTuple &WindowHandle) const;
  // Modify position and size of a window.
  virtual void SetWindowExtents(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Width, const Halcon::HTuple &Height) const;
  // Modify position and size of a window.
  virtual void SetWindowExtents(Hlong Row, Hlong Column, Hlong Width, Hlong Height) const;
  // Open a graphics window.
  virtual Hlong OpenWindow(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Width, const Halcon::HTuple &Height, const Halcon::HTuple &FatherWindow, const Halcon::HTuple &Mode, const Halcon::HTuple &Machine) const;
  // Open a graphics window.
  virtual Hlong OpenWindow(Hlong Row, Hlong Column, Hlong Width, Hlong Height, Hlong FatherWindow, const char *Mode, const char *Machine) const;
  // Open a textual window.
  virtual Hlong OpenTextwindow(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Width, const Halcon::HTuple &Height, const Halcon::HTuple &BorderWidth, const Halcon::HTuple &BorderColor, const Halcon::HTuple &BackgroundColor, const Halcon::HTuple &FatherWindow, const Halcon::HTuple &Mode, const Halcon::HTuple &Machine) const;
  // Open a textual window.
  virtual Hlong OpenTextwindow(Hlong Row, Hlong Column, Hlong Width, Hlong Height, Hlong BorderWidth, const char *BorderColor, const char *BackgroundColor, Hlong FatherWindow, const char *Mode, const char *Machine) const;
  // Copy inside an output window.
  virtual void MoveRectangle(const Halcon::HTuple &Row1, const Halcon::HTuple &Column1, const Halcon::HTuple &Row2, const Halcon::HTuple &Column2, const Halcon::HTuple &DestRow, const Halcon::HTuple &DestColumn) const;
  // Copy inside an output window.
  virtual void MoveRectangle(Hlong Row1, Hlong Column1, Hlong Row2, Hlong Column2, Hlong DestRow, Hlong DestColumn) const;
  // Get the window type.
  virtual HTuple GetWindowType() const;
  // Access to a window's pixel data.
  virtual Hlong GetWindowPointer3(Halcon::HTuple *ImageGreen, Halcon::HTuple *ImageBlue, Halcon::HTuple *Width, Halcon::HTuple *Height) const;
  // Information about a window's size and position.
  virtual Hlong GetWindowExtents(Halcon::HTuple *Column, Halcon::HTuple *Width, Halcon::HTuple *Height) const;
  // Write the window content in an image object.
  virtual HImage DumpWindowImage() const;
  // Write the window content to a file.
  virtual void DumpWindow(const Halcon::HTuple &Device, const Halcon::HTuple &FileName) const;
  // Copy all pixels within rectangles between output windows.
  virtual void CopyRectangle(const Halcon::HTuple &WindowHandleDestination, const Halcon::HTuple &Row1, const Halcon::HTuple &Column1, const Halcon::HTuple &Row2, const Halcon::HTuple &Column2, const Halcon::HTuple &DestRow, const Halcon::HTuple &DestColumn) const;
  // Copy all pixels within rectangles between output windows.
  virtual void CopyRectangle(Hlong WindowHandleDestination, Hlong Row1, Hlong Column1, Hlong Row2, Hlong Column2, Hlong DestRow, Hlong DestColumn) const;
  // Delete the contents of an output window.
  virtual void ClearWindow() const;
  // Delete a rectangle on the output window.
  virtual void ClearRectangle(const Halcon::HTuple &Row1, const Halcon::HTuple &Column1, const Halcon::HTuple &Row2, const Halcon::HTuple &Column2) const;
  // Delete a rectangle on the output window.
  virtual void ClearRectangle(Hlong Row1, Hlong Column1, Hlong Row2, Hlong Column2) const;
  // Print text in a window.
  virtual void WriteString(const Halcon::HTuple &String) const;
  // Set the shape of the text cursor.
  virtual void SetTshape(const Halcon::HTuple &TextCursor) const;
  // Set the shape of the text cursor.
  virtual void SetTshape(const char *TextCursor) const;
  // Set the position of the text cursor.
  virtual void SetTposition(const Halcon::HTuple &Row, const Halcon::HTuple &Column) const;
  // Set the position of the text cursor.
  virtual void SetTposition(Hlong Row, Hlong Column) const;
  // Read a string in a text window.
  virtual HTuple ReadString(const Halcon::HTuple &InString, const Halcon::HTuple &Length) const;
  // Read a string in a text window.
  virtual HTuple ReadString(const char *InString, Hlong Length) const;
  // Read a character from a text window.
  virtual HTuple ReadChar(Halcon::HTuple *Code) const;
  // Set the position of the text cursor to the beginning of the next line.
  virtual void NewLine() const;
  // Get the shape of the text cursor.
  virtual HTuple GetTshape() const;
  // Get cursor position.
  virtual Hlong GetTposition(Halcon::HTuple *Column) const;
  // Get the maximum size of all characters of a font.
  virtual Hlong GetFontExtents(Halcon::HTuple *MaxDescent, Halcon::HTuple *MaxWidth, Halcon::HTuple *MaxHeight) const;
  // Get the spatial size of a string.
  virtual Hlong GetStringExtents(const Halcon::HTuple &Values, Halcon::HTuple *Descent, Halcon::HTuple *Width, Halcon::HTuple *Height) const;
  // Query the available fonts.
  virtual HTuple QueryFont() const;
  // Query all shapes available for text cursors.
  virtual HTuple QueryTshape() const;
  // Set the font used for text output.
  virtual void SetFont(const Halcon::HTuple &Font) const;
  // Set the font used for text output.
  virtual void SetFont(const char *Font) const;
  // Get the current font.
  virtual HTuple GetFont() const;
  // Get window parameters.
  virtual HTuple GetWindowParam(const Halcon::HTuple &Param) const;
  // Get window parameters.
  virtual HTuple GetWindowParam(const char *Param) const;
  // Set window parameters.
  virtual void SetWindowParam(const Halcon::HTuple &Param, const Halcon::HTuple &Value) const;
  // Define the region output shape.
  virtual void SetShape(const Halcon::HTuple &Shape) const;
  // Define the region output shape.
  virtual void SetShape(const char *Shape) const;
  // Set the color definition via RGB values.
  virtual void SetRgb(const Halcon::HTuple &Red, const Halcon::HTuple &Green, const Halcon::HTuple &Blue) const;
  // Set the color definition via RGB values.
  virtual void SetRgb(Hlong Red, Hlong Green, Hlong Blue) const;
  // Define a color lookup table index.
  virtual void SetPixel(const Halcon::HTuple &Pixel) const;
  // Define a color lookup table index.
  virtual void SetPixel(Hlong Pixel) const;
  // Define an interpolation method for gray value output.
  // 
  virtual void SetPartStyle(const Halcon::HTuple &Style) const;
  // Define an interpolation method for gray value output.
  // 
  virtual void SetPartStyle(Hlong Style) const;
  // Modify the displayed image part.
  virtual void SetPart(const Halcon::HTuple &Row1, const Halcon::HTuple &Column1, const Halcon::HTuple &Row2, const Halcon::HTuple &Column2) const;
  // Modify the displayed image part.
  virtual void SetPart(Hlong Row1, Hlong Column1, Hlong Row2, Hlong Column2) const;
  // Define the gray value output mode.
  virtual void SetPaint(const Halcon::HTuple &Mode) const;
  // Define the line width for region contour output.
  virtual void SetLineWidth(const Halcon::HTuple &Width) const;
  // Define the line width for region contour output.
  virtual void SetLineWidth(Hlong Width) const;
  // Define a contour output pattern.
  virtual void SetLineStyle(const Halcon::HTuple &Style) const;
  // Define the approximation error for contour display.
  virtual void SetLineApprox(const Halcon::HTuple &Approximation) const;
  // Define the approximation error for contour display.
  virtual void SetLineApprox(Hlong Approximation) const;
  // Define the pixel output function.
  virtual void SetInsert(const Halcon::HTuple &Mode) const;
  // Define the pixel output function.
  virtual void SetInsert(const char *Mode) const;
  // Define output colors (HSI-coded).
  virtual void SetHsi(const Halcon::HTuple &Hue, const Halcon::HTuple &Saturation, const Halcon::HTuple &Intensity) const;
  // Define output colors (HSI-coded).
  virtual void SetHsi(Hlong Hue, Hlong Saturation, Hlong Intensity) const;
  // Define gray values for region output.
  virtual void SetGray(const Halcon::HTuple &GrayValues) const;
  // Define gray values for region output.
  virtual void SetGray(Hlong GrayValues) const;
  // Define the region fill mode.
  virtual void SetDraw(const Halcon::HTuple &Mode) const;
  // Define the region fill mode.
  virtual void SetDraw(const char *Mode) const;
  // Define the image matrix output clipping.
  virtual void SetComprise(const Halcon::HTuple &Mode) const;
  // Define the image matrix output clipping.
  virtual void SetComprise(const char *Mode) const;
  // Set multiple output colors.
  virtual void SetColored(const Halcon::HTuple &NumberOfColors) const;
  // Set multiple output colors.
  virtual void SetColored(Hlong NumberOfColors) const;
  // Set output color.
  virtual void SetColor(const Halcon::HTuple &Color) const;
  // Set output color.
  virtual void SetColor(const char *Color) const;
  // Get the current region output shape.
  virtual HTuple GetShape() const;
  // Get the current color in RGB-coding.
  virtual HTuple GetRgb(Halcon::HTuple *Green, Halcon::HTuple *Blue) const;
  // Get the current color lookup table index.
  virtual HTuple GetPixel() const;
  // Get the current interpolation mode for gray value display.
  virtual Hlong GetPartStyle() const;
  // Get the image part.
  virtual Hlong GetPart(Halcon::HTuple *Column1, Halcon::HTuple *Row2, Halcon::HTuple *Column2) const;
  // Get the current display mode for gray values.
  virtual HTuple GetPaint() const;
  // Get the current line width for contour display.
  virtual Hlong GetLineWidth() const;
  // Get the current graphic mode for contours.
  virtual HTuple GetLineStyle() const;
  // Get the current approximation error for contour display.
  virtual Hlong GetLineApprox() const;
  // Get the current display mode.
  virtual HTuple GetInsert() const;
  // Get the HSI coding of the current color.
  virtual HTuple GetHsi(Halcon::HTuple *Saturation, Halcon::HTuple *Intensity) const;
  // Get the current region fill mode.
  virtual HTuple GetDraw() const;
  // Query the gray value display modes.
  virtual HTuple QueryPaint() const;
  // Query the possible graphic modes.
  virtual HTuple QueryInsert() const;
  // Query the displayable gray values.
  virtual HTuple QueryGray() const;
  // Query all color names.
  virtual HTuple QueryAllColors() const;
  // Query all color names displayable in the window.
  virtual HTuple QueryColor() const;
  // Displays arbitrarily oriented rectangles.
  virtual void DispRectangle2(const Halcon::HTuple &CenterRow, const Halcon::HTuple &CenterCol, const Halcon::HTuple &Phi, const Halcon::HTuple &Length1, const Halcon::HTuple &Length2) const;
  // Displays arbitrarily oriented rectangles.
  virtual void DispRectangle2(double CenterRow, double CenterCol, double Phi, double Length1, double Length2) const;
  // Display of rectangles aligned to the coordinate axes.
  virtual void DispRectangle1(const Halcon::HTuple &Row1, const Halcon::HTuple &Column1, const Halcon::HTuple &Row2, const Halcon::HTuple &Column2) const;
  // Display of rectangles aligned to the coordinate axes.
  virtual void DispRectangle1(double Row1, double Column1, double Row2, double Column2) const;
  // Displays a polyline.
  virtual void DispPolygon(const Halcon::HTuple &Row, const Halcon::HTuple &Column) const;
  // Draws lines in a window.
  virtual void DispLine(const Halcon::HTuple &Row1, const Halcon::HTuple &Column1, const Halcon::HTuple &Row2, const Halcon::HTuple &Column2) const;
  // Draws lines in a window.
  virtual void DispLine(double Row1, double Column1, double Row2, double Column2) const;
  // Displays crosses in a window.
  virtual void DispCross(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Size, const Halcon::HTuple &Angle) const;
  // Displays crosses in a window.
  virtual void DispCross(double Row, double Column, double Size, double Angle) const;
  // Displays ellipses.
  virtual void DispEllipse(const Halcon::HTuple &CenterRow, const Halcon::HTuple &CenterCol, const Halcon::HTuple &Phi, const Halcon::HTuple &Radius1, const Halcon::HTuple &Radius2) const;
  // Displays ellipses.
  virtual void DispEllipse(Hlong CenterRow, Hlong CenterCol, double Phi, double Radius1, double Radius2) const;
  // Displays a noise distribution.
  virtual void DispDistribution(const Halcon::HTuple &Distribution, const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Scale) const;
  // Displays circles in a window.
  virtual void DispCircle(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Radius) const;
  // Displays circles in a window.
  virtual void DispCircle(double Row, double Column, double Radius) const;
  // Displays arrows in a window.
  virtual void DispArrow(const Halcon::HTuple &Row1, const Halcon::HTuple &Column1, const Halcon::HTuple &Row2, const Halcon::HTuple &Column2, const Halcon::HTuple &Size) const;
  // Displays arrows in a window.
  virtual void DispArrow(double Row1, double Column1, double Row2, double Column2, double Size) const;
  // Displays circular arcs in a window.
  virtual void DispArc(const Halcon::HTuple &CenterRow, const Halcon::HTuple &CenterCol, const Halcon::HTuple &Angle, const Halcon::HTuple &BeginRow, const Halcon::HTuple &BeginCol) const;
  // Displays circular arcs in a window.
  virtual void DispArc(double CenterRow, double CenterCol, double Angle, Hlong BeginRow, Hlong BeginCol) const;
  // Set the current mouse pointer shape.
  virtual void SetMshape(const Halcon::HTuple &Cursor) const;
  // Set the current mouse pointer shape.
  virtual void SetMshape(const char *Cursor) const;
  // Query the current mouse pointer shape.
  virtual HTuple GetMshape() const;
  // Query all available mouse pointer shapes.
  virtual HTuple QueryMshape() const;
  // Query the subpixel mouse position.
  virtual double GetMpositionSubPix(Halcon::HTuple *Column, Halcon::HTuple *Button) const;
  // Query the mouse position.
  virtual Hlong GetMposition(Halcon::HTuple *Column, Halcon::HTuple *Button) const;
  // Wait until a mouse button is pressed and get the subpixel mouse position.
  virtual double GetMbuttonSubPix(Halcon::HTuple *Column, Halcon::HTuple *Button) const;
  // Wait until a mouse button is pressed.
  virtual Hlong GetMbutton(Halcon::HTuple *Column, Halcon::HTuple *Button) const;
  // Write look-up-table (lut) as file.
  virtual void WriteLut(const Halcon::HTuple &FileName) const;
  // Write look-up-table (lut) as file.
  virtual void WriteLut(const char *FileName) const;
  // Graphical view of the look-up-table (lut).
  virtual void DispLut(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Scale) const;
  // Graphical view of the look-up-table (lut).
  virtual void DispLut(Hlong Row, Hlong Column, Hlong Scale) const;
  // Query all available look-up-tables (lut).
  virtual HTuple QueryLut() const;
  // Manipulate look-up-table (lut) interactively.
  virtual void DrawLut() const;
  // Get modification parameters of look-up-table (lut).
  virtual double GetLutStyle(Halcon::HTuple *Saturation, Halcon::HTuple *Intensity) const;
  // Changing the look-up-table (lut).
  virtual void SetLutStyle(const Halcon::HTuple &Hue, const Halcon::HTuple &Saturation, const Halcon::HTuple &Intensity) const;
  // Changing the look-up-table (lut).
  virtual void SetLutStyle(double Hue, double Saturation, double Intensity) const;
  // Get current look-up-table (lut).
  virtual HTuple GetLut() const;
  // Set "look-up-table" (lut).
  virtual void SetLut(const Halcon::HTuple &LookUpTable) const;
  // Get mode of fixing of current look-up-table (lut).
  virtual HTuple GetFix() const;
  // Set fixing of "look-up-table" (lut)
  virtual void SetFix(const Halcon::HTuple &Mode) const;
  // Set fixing of "look-up-table" (lut)
  virtual void SetFix(const char *Mode) const;
  // Get fixing of "look-up-table" (lut) for "real color images"
  virtual HTuple GetFixedLut() const;
  // Fix "look-up-table" (lut) for "real color images".
  virtual void SetFixedLut(const Halcon::HTuple &Mode) const;
  // Fix "look-up-table" (lut) for "real color images".
  virtual void SetFixedLut(const char *Mode) const;
  // Interactive drawing of any orientated rectangle.
  virtual double DrawRectangle2Mod(const Halcon::HTuple &RowIn, const Halcon::HTuple &ColumnIn, const Halcon::HTuple &PhiIn, const Halcon::HTuple &Length1In, const Halcon::HTuple &Length2In, Halcon::HTuple *Column, Halcon::HTuple *Phi, Halcon::HTuple *Length1, Halcon::HTuple *Length2) const;
  // Interactive drawing of any orientated rectangle.
  virtual double DrawRectangle2Mod(double RowIn, double ColumnIn, double PhiIn, double Length1In, double Length2In, Halcon::HTuple *Column, Halcon::HTuple *Phi, Halcon::HTuple *Length1, Halcon::HTuple *Length2) const;
  // Interactive drawing of any orientated rectangle.
  virtual double DrawRectangle2(Halcon::HTuple *Column, Halcon::HTuple *Phi, Halcon::HTuple *Length1, Halcon::HTuple *Length2) const;
  // Draw a rectangle parallel to the coordinate axis.
  virtual double DrawRectangle1Mod(const Halcon::HTuple &Row1In, const Halcon::HTuple &Column1In, const Halcon::HTuple &Row2In, const Halcon::HTuple &Column2In, Halcon::HTuple *Column1, Halcon::HTuple *Row2, Halcon::HTuple *Column2) const;
  // Draw a rectangle parallel to the coordinate axis.
  virtual double DrawRectangle1Mod(double Row1In, double Column1In, double Row2In, double Column2In, Halcon::HTuple *Column1, Halcon::HTuple *Row2, Halcon::HTuple *Column2) const;
  // Draw a rectangle parallel to the coordinate axis.
  virtual double DrawRectangle1(Halcon::HTuple *Column1, Halcon::HTuple *Row2, Halcon::HTuple *Column2) const;
  // Draw a point.
  virtual double DrawPointMod(const Halcon::HTuple &RowIn, const Halcon::HTuple &ColumnIn, Halcon::HTuple *Column) const;
  // Draw a point.
  virtual double DrawPointMod(double RowIn, double ColumnIn, Halcon::HTuple *Column) const;
  // Draw a point.
  virtual double DrawPoint(Halcon::HTuple *Column) const;
  // Draw a line.
  virtual double DrawLineMod(const Halcon::HTuple &Row1In, const Halcon::HTuple &Column1In, const Halcon::HTuple &Row2In, const Halcon::HTuple &Column2In, Halcon::HTuple *Column1, Halcon::HTuple *Row2, Halcon::HTuple *Column2) const;
  // Draw a line.
  virtual double DrawLineMod(double Row1In, double Column1In, double Row2In, double Column2In, Halcon::HTuple *Column1, Halcon::HTuple *Row2, Halcon::HTuple *Column2) const;
  // Draw a line.
  virtual double DrawLine(Halcon::HTuple *Column1, Halcon::HTuple *Row2, Halcon::HTuple *Column2) const;
  // Interactive drawing of an ellipse.
  virtual double DrawEllipseMod(const Halcon::HTuple &RowIn, const Halcon::HTuple &ColumnIn, const Halcon::HTuple &PhiIn, const Halcon::HTuple &Radius1In, const Halcon::HTuple &Radius2In, Halcon::HTuple *Column, Halcon::HTuple *Phi, Halcon::HTuple *Radius1, Halcon::HTuple *Radius2) const;
  // Interactive drawing of an ellipse.
  virtual double DrawEllipseMod(double RowIn, double ColumnIn, double PhiIn, double Radius1In, double Radius2In, Halcon::HTuple *Column, Halcon::HTuple *Phi, Halcon::HTuple *Radius1, Halcon::HTuple *Radius2) const;
  // Interactive drawing of an ellipse.
  virtual double DrawEllipse(Halcon::HTuple *Column, Halcon::HTuple *Phi, Halcon::HTuple *Radius1, Halcon::HTuple *Radius2) const;
  // Interactive drawing of a circle.
  virtual double DrawCircleMod(const Halcon::HTuple &RowIn, const Halcon::HTuple &ColumnIn, const Halcon::HTuple &RadiusIn, Halcon::HTuple *Column, Halcon::HTuple *Radius) const;
  // Interactive drawing of a circle.
  virtual double DrawCircleMod(double RowIn, double ColumnIn, double RadiusIn, Halcon::HTuple *Column, Halcon::HTuple *Radius) const;
  // Interactive drawing of a circle.
  virtual double DrawCircle(Halcon::HTuple *Column, Halcon::HTuple *Radius) const;
  // Interactive drawing of a closed region.
  virtual HRegion DrawRegion() const;
  // Interactive drawing of a polygon row.
  virtual HRegion DrawPolygon() const;
  // Project and visualize the 3D model of the calibration plate in the image.
  virtual void DispCaltab(const Halcon::HTuple &CalPlateDescr, const Halcon::HTuple &CameraParam, const Halcon::HTuple &CalPlatePose, const Halcon::HTuple &ScaleFac) const;
};

}

#endif
