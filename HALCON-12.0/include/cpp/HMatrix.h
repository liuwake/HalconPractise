/*****************************************************************************
 * HMatrix.h
 ***************************************************************************** 
 *
 * Project:     HALCON/C++
 * Description: Class HMatrix
 *
 * (c) 1996-2014 by MVTec Software GmbH
 *                  www.mvtec.com
 * 
 *****************************************************************************
 *
 *
 */

#ifndef H_MATRIX_H
#define H_MATRIX_H

#include "HCPPToolRef.h"

namespace Halcon {

class LIntExport HMatrix: public HToolBase 
{
public:
  
  // Tool-specific functional class constructors
  
  HMatrix(const HTuple &NRows, const HTuple &NCols, const HTuple &Value = 0.0);
  HMatrix(const Hlong NRows, const Hlong NCols, const double Value = 0.0);

  // Tool-specific operator overloads
  
  HMatrix  operator - (void) const;
  
  HMatrix  operator + (const HMatrix &add) const;
  HMatrix  operator - (const HMatrix &sub) const;
  HMatrix  operator * (const HMatrix &mult) const;
  HMatrix  operator / (const HMatrix &div) const;
  
  HMatrix  operator * (double mult) const;
  HMatrix  operator * (int mult) const;
#if !defined(_TMS320C6X)  
  HMatrix  operator * (Hlong mult) const;
#endif

  LIntExport friend HMatrix operator * (double mult, const HMatrix &M);
  LIntExport friend HMatrix operator * (int mult, const HMatrix &M);
#if !defined(_TMS320C6X)    
  LIntExport friend HMatrix operator * (Hlong mult, const HMatrix &M);
#endif

  operator HTuple(void) const;
  

  // Common tool class management functionality

  HMatrix();
  HMatrix(Hlong ID);
  const char *ClassName(void) const;
  void  SetHandle(Hlong ID);

  // Tool-specific member functions

  //   Deserialize a serialized matrix.
  virtual void DeserializeMatrix(const Halcon::HSerializedItem &SerializedItemHandle);
  // Serialize a matrix.
  virtual HSerializedItem SerializeMatrix() const;
  // Read a matrix from a file.
  virtual void ReadMatrix(const Halcon::HTuple &FileName);
  // Read a matrix from a file.
  virtual void ReadMatrix(const char *FileName);
  // Write a matrix to a file.
  virtual void WriteMatrix(const Halcon::HTuple &FileFormat, const Halcon::HTuple &FileName) const;
  // Write a matrix to a file.
  virtual void WriteMatrix(const char *FileFormat, const char *FileName) const;
  // Perform an orthogonal decomposition of a matrix.
  virtual HMatrix OrthogonalDecomposeMatrix(const Halcon::HTuple &DecompositionType, const Halcon::HTuple &OutputMatricesType, const Halcon::HTuple &ComputeOrthogonal, Halcon::HMatrix *MatrixTriangularID) const;
  // Perform an orthogonal decomposition of a matrix.
  virtual HMatrix OrthogonalDecomposeMatrix(const char *DecompositionType, const char *OutputMatricesType, const char *ComputeOrthogonal, Halcon::HMatrix *MatrixTriangularID) const;
  // Decompose a matrix.
  virtual HMatrix DecomposeMatrix(const Halcon::HTuple &MatrixType, Halcon::HMatrix *Matrix2ID) const;
  // Decompose a matrix.
  virtual HMatrix DecomposeMatrix(const char *MatrixType, Halcon::HMatrix *Matrix2ID) const;
  // Compute the singular value decomposition of a matrix.
  virtual HMatrix SvdMatrix(const Halcon::HTuple &SVDType, const Halcon::HTuple &ComputeSingularVectors, Halcon::HMatrix *MatrixSID, Halcon::HMatrix *MatrixVID) const;
  // Compute the singular value decomposition of a matrix.
  virtual HMatrix SvdMatrix(const char *SVDType, const char *ComputeSingularVectors, Halcon::HMatrix *MatrixSID, Halcon::HMatrix *MatrixVID) const;
  // Compute the generalized eigenvalues and optionally the generalized
  // eigenvectors of general matrices.
  virtual HMatrix GeneralizedEigenvaluesGeneralMatrix(const Halcon::HMatrix &MatrixBID, const Halcon::HTuple &ComputeEigenvectors, Halcon::HMatrix *EigenvaluesImagID, Halcon::HMatrix *EigenvectorsRealID, Halcon::HMatrix *EigenvectorsImagID) const;
  // Compute the generalized eigenvalues and optionally the generalized
  // eigenvectors of general matrices.
  virtual HMatrix GeneralizedEigenvaluesGeneralMatrix(const Halcon::HMatrix &MatrixBID, const char *ComputeEigenvectors, Halcon::HMatrix *EigenvaluesImagID, Halcon::HMatrix *EigenvectorsRealID, Halcon::HMatrix *EigenvectorsImagID) const;
  // Compute the generalized eigenvalues and optionally generalized
  // eigenvectors of symmetric input matrices.
  virtual HMatrix GeneralizedEigenvaluesSymmetricMatrix(const Halcon::HMatrix &MatrixBID, const Halcon::HTuple &ComputeEigenvectors, Halcon::HMatrix *EigenvectorsID) const;
  // Compute the generalized eigenvalues and optionally generalized
  // eigenvectors of symmetric input matrices.
  virtual HMatrix GeneralizedEigenvaluesSymmetricMatrix(const Halcon::HMatrix &MatrixBID, const char *ComputeEigenvectors, Halcon::HMatrix *EigenvectorsID) const;
  // Compute the eigenvalues and optionally the eigenvectors of a general
  // matrix.
  virtual HMatrix EigenvaluesGeneralMatrix(const Halcon::HTuple &ComputeEigenvectors, Halcon::HMatrix *EigenvaluesImagID, Halcon::HMatrix *EigenvectorsRealID, Halcon::HMatrix *EigenvectorsImagID) const;
  // Compute the eigenvalues and optionally the eigenvectors of a general
  // matrix.
  virtual HMatrix EigenvaluesGeneralMatrix(const char *ComputeEigenvectors, Halcon::HMatrix *EigenvaluesImagID, Halcon::HMatrix *EigenvectorsRealID, Halcon::HMatrix *EigenvectorsImagID) const;
  // Compute the eigenvalues and optionally eigenvectors of a symmetric
  // matrix.
  virtual HMatrix EigenvaluesSymmetricMatrix(const Halcon::HTuple &ComputeEigenvectors, Halcon::HMatrix *EigenvectorsID) const;
  // Compute the eigenvalues and optionally eigenvectors of a symmetric
  // matrix.
  virtual HMatrix EigenvaluesSymmetricMatrix(const char *ComputeEigenvectors, Halcon::HMatrix *EigenvectorsID) const;
  // Compute the solution of a system of equations.
  virtual HMatrix SolveMatrix(const Halcon::HTuple &MatrixLHSType, const Halcon::HTuple &Epsilon, const Halcon::HMatrix &MatrixRHSID) const;
  // Compute the solution of a system of equations.
  virtual HMatrix SolveMatrix(const char *MatrixLHSType, double Epsilon, const Halcon::HMatrix &MatrixRHSID) const;
  // Compute the determinant of a matrix.
  virtual double DeterminantMatrix(const Halcon::HTuple &MatrixType) const;
  // Compute the determinant of a matrix.
  virtual double DeterminantMatrix(const char *MatrixType) const;
  // Invert a matrix.
  virtual void InvertMatrixMod(const Halcon::HTuple &MatrixType, const Halcon::HTuple &Epsilon) const;
  // Invert a matrix.
  virtual void InvertMatrixMod(const char *MatrixType, double Epsilon) const;
  // Invert a matrix.
  virtual HMatrix InvertMatrix(const Halcon::HTuple &MatrixType, const Halcon::HTuple &Epsilon) const;
  // Invert a matrix.
  virtual HMatrix InvertMatrix(const char *MatrixType, double Epsilon) const;
  // Transpose a matrix.
  virtual void TransposeMatrixMod() const;
  // Transpose a matrix.
  virtual HMatrix TransposeMatrix() const;
  // Returns the elementwise maximum of a matrix.
  virtual HMatrix MaxMatrix(const Halcon::HTuple &MaxType) const;
  // Returns the elementwise maximum of a matrix.
  virtual HMatrix MaxMatrix(const char *MaxType) const;
  // Returns the elementwise minimum of a matrix.
  virtual HMatrix MinMatrix(const Halcon::HTuple &MinType) const;
  // Returns the elementwise minimum of a matrix.
  virtual HMatrix MinMatrix(const char *MinType) const;
  // Compute the power functions of a matrix.
  virtual void PowMatrixMod(const Halcon::HTuple &MatrixType, const Halcon::HTuple &Power) const;
  // Compute the power functions of a matrix.
  virtual void PowMatrixMod(const char *MatrixType, double Power) const;
  // Compute the power functions of a matrix.
  virtual HMatrix PowMatrix(const Halcon::HTuple &MatrixType, const Halcon::HTuple &Power) const;
  // Compute the power functions of a matrix.
  virtual HMatrix PowMatrix(const char *MatrixType, double Power) const;
  // Compute the power functions of the elements of a matrix.
  virtual void PowElementMatrixMod(const Halcon::HMatrix &MatrixExpID) const;
  // Compute the power functions of the elements of a matrix.
  virtual HMatrix PowElementMatrix(const Halcon::HMatrix &MatrixExpID) const;
  // Compute the power functions of the elements of a matrix.
  virtual void PowScalarElementMatrixMod(const Halcon::HTuple &Power) const;
  // Compute the power functions of the elements of a matrix.
  virtual void PowScalarElementMatrixMod(double Power) const;
  // Compute the power functions of the elements of a matrix.
  virtual HMatrix PowScalarElementMatrix(const Halcon::HTuple &Power) const;
  // Compute the power functions of the elements of a matrix.
  virtual HMatrix PowScalarElementMatrix(double Power) const;
  // Compute the square root values of the elements of a matrix.
  virtual void SqrtMatrixMod() const;
  // Compute the square root values of the elements of a matrix.
  virtual HMatrix SqrtMatrix() const;
  // Compute the absolute values of the elements of a matrix.
  virtual void AbsMatrixMod() const;
  // Compute the absolute values of the elements of a matrix.
  virtual HMatrix AbsMatrix() const;
  // Norm of a matrix.
  virtual double NormMatrix(const Halcon::HTuple &NormType) const;
  // Norm of a matrix.
  virtual double NormMatrix(const char *NormType) const;
  // Returns the elementwise mean of a matrix.
  virtual HMatrix MeanMatrix(const Halcon::HTuple &MeanType) const;
  // Returns the elementwise mean of a matrix.
  virtual HMatrix MeanMatrix(const char *MeanType) const;
  // Returns the elementwise sum of a matrix.
  virtual HMatrix SumMatrix(const Halcon::HTuple &SumType) const;
  // Returns the elementwise sum of a matrix.
  virtual HMatrix SumMatrix(const char *SumType) const;
  // Divide matrices element-by-element.
  virtual void DivElementMatrixMod(const Halcon::HMatrix &MatrixBID) const;
  // Divide matrices element-by-element.
  virtual HMatrix DivElementMatrix(const Halcon::HMatrix &MatrixBID) const;
  // Multiply matrices element-by-element.
  virtual void MultElementMatrixMod(const Halcon::HMatrix &MatrixBID) const;
  // Multiply matrices element-by-element.
  virtual HMatrix MultElementMatrix(const Halcon::HMatrix &MatrixBID) const;
  // Scale a matrix.
  virtual void ScaleMatrixMod(const Halcon::HTuple &Factor) const;
  // Scale a matrix.
  virtual void ScaleMatrixMod(double Factor) const;
  // Scale a matrix.
  virtual HMatrix ScaleMatrix(const Halcon::HTuple &Factor) const;
  // Scale a matrix.
  virtual HMatrix ScaleMatrix(double Factor) const;
  // Subtract two matrices.
  virtual void SubMatrixMod(const Halcon::HMatrix &MatrixBID) const;
  // Subtract two matrices.
  virtual HMatrix SubMatrix(const Halcon::HMatrix &MatrixBID) const;
  // Add two matrices.
  virtual void AddMatrixMod(const Halcon::HMatrix &MatrixBID) const;
  // Add two matrices.
  virtual HMatrix AddMatrix(const Halcon::HMatrix &MatrixBID) const;
  // Multiply two matrices.
  virtual void MultMatrixMod(const Halcon::HMatrix &MatrixBID, const Halcon::HTuple &MultType) const;
  // Multiply two matrices.
  virtual void MultMatrixMod(const Halcon::HMatrix &MatrixBID, const char *MultType) const;
  // Multiply two matrices.
  virtual HMatrix MultMatrix(const Halcon::HMatrix &MatrixBID, const Halcon::HTuple &MultType) const;
  // Multiply two matrices.
  virtual HMatrix MultMatrix(const Halcon::HMatrix &MatrixBID, const char *MultType) const;
  // Get the size of a matrix.
  virtual Hlong GetSizeMatrix(Halcon::HTuple *Columns) const;
  // Get the size of a matrix.
  virtual Hlong GetSizeMatrix(Hlong *Columns) const;
  // Repeat a matrix.
  virtual HMatrix RepeatMatrix(const Halcon::HTuple &Rows, const Halcon::HTuple &Columns) const;
  // Repeat a matrix.
  virtual HMatrix RepeatMatrix(Hlong Rows, Hlong Columns) const;
  // Copy a matrix.
  virtual HMatrix CopyMatrix() const;
  // Set the diagonal elements of a matrix.
  virtual void SetDiagonalMatrix(const Halcon::HMatrix &VectorID, const Halcon::HTuple &Diagonal) const;
  // Set the diagonal elements of a matrix.
  virtual void SetDiagonalMatrix(const Halcon::HMatrix &VectorID, Hlong Diagonal) const;
  // Get the diagonal elements of a matrix.
  virtual HMatrix GetDiagonalMatrix(const Halcon::HTuple &Diagonal) const;
  // Get the diagonal elements of a matrix.
  virtual HMatrix GetDiagonalMatrix(Hlong Diagonal) const;
  // Set a sub-matrix of a matrix.
  virtual void SetSubMatrix(const Halcon::HMatrix &MatrixSubID, const Halcon::HTuple &Row, const Halcon::HTuple &Column) const;
  // Set a sub-matrix of a matrix.
  virtual void SetSubMatrix(const Halcon::HMatrix &MatrixSubID, Hlong Row, Hlong Column) const;
  // Get a sub-matrix of a matrix.
  virtual HMatrix GetSubMatrix(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &RowsSub, const Halcon::HTuple &ColumnsSub) const;
  // Get a sub-matrix of a matrix.
  virtual HMatrix GetSubMatrix(Hlong Row, Hlong Column, Hlong RowsSub, Hlong ColumnsSub) const;
  // Set all values of a matrix.
  virtual void SetFullMatrix(const Halcon::HTuple &Values) const;
  // Set all values of a matrix.
  virtual void SetFullMatrix(double Values) const;
  // Return all values of a matrix.
  virtual HTuple GetFullMatrix() const;
  // Set one or more elements of a matrix.
  virtual void SetValueMatrix(const Halcon::HTuple &Row, const Halcon::HTuple &Column, const Halcon::HTuple &Value) const;
  // Set one or more elements of a matrix.
  virtual void SetValueMatrix(Hlong Row, Hlong Column, double Value) const;
  // Return one ore more elements of a matrix.
  virtual HTuple GetValueMatrix(const Halcon::HTuple &Row, const Halcon::HTuple &Column) const;
  // Return one ore more elements of a matrix.
  virtual HTuple GetValueMatrix(Hlong Row, Hlong Column) const;
  // Create a matrix.
  virtual void CreateMatrix(const Halcon::HTuple &Rows, const Halcon::HTuple &Columns, const Halcon::HTuple &Value);
  // Create a matrix.
  virtual void CreateMatrix(Hlong Rows, Hlong Columns, double Value);
};

}

#endif
