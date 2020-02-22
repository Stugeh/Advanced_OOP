#ifndef VT5_SYMBOLICSQUAREMATRIX_H
#define VT5_SYMBOLICSQUAREMATRIX_H

#include <vector>
#include <string>
#include <ostream>
#include <sstream>
#include <memory>
#include "Element.h"
#include "IntElement.h"
#include "VariableElement.h"
#include "CompositeElement.h"
#include "ConcreteSquareMatrix.h"



///Symbolic SquareMatrix header.                       
///                                                    
/// Symbolic matrices can have variables that can then 
/// be assigned values by adding them to the map       
/// stored in Valuation. And calling evaluate() to     
/// create Concrete matrices.                          



/**
 * \param n : amount of elements in each row / amount of rows
 * \param elements : stores the elements. Elements can be of type IntElement or VariableElement.
 */
class SymbolicSquareMatrix {
private:
    unsigned int n{0};
    std::vector<std::vector<std::unique_ptr<Element>>> elements{};

public:
    
    ///
    ///default constructor makes an empty matrix.
    SymbolicSquareMatrix();

    /// Builds a matrix from a string if the string is formatted similar to [[1n,2n][3n,4n]]
    /// Turns string into the matrix and calculates how many elements are in each line to set n.
    /// \param m_string string that contains the matrix.
    SymbolicSquareMatrix(const std::string &m_string);
    
    /// Copy constructor.
    /// Loops through existing matrix, copies containers values creates new pointers to them and sets the n.
    ///\param matrix : existing matrix object
    SymbolicSquareMatrix(const SymbolicSquareMatrix &matrix);

    /// move constructor overload for matrices
    /// \param matrix  : existing matrix object
    SymbolicSquareMatrix(SymbolicSquareMatrix &&matrix);

    ///destructor
    ///
    virtual ~SymbolicSquareMatrix();

    /// assignment operator
    /// \param matrix
    /// \return
    SymbolicSquareMatrix &operator=(const SymbolicSquareMatrix &matrix);

    /// move assignment operator
    /// \param matrix
    /// \return
    SymbolicSquareMatrix &operator=(SymbolicSquareMatrix &&matrix);

    /// transposes the matrix and returns a new matrix object.
    /// \return : new SymbolicSquareMatrix object
    SymbolicSquareMatrix transpose() const;

    SymbolicSquareMatrix operator+(const SymbolicSquareMatrix& matrix) const;

    SymbolicSquareMatrix operator-(const SymbolicSquareMatrix& matrix) const;

    SymbolicSquareMatrix operator*(const SymbolicSquareMatrix& matrix) const;

    /// Compares 2 SymbolicSquareMatrix objects by calling their toString methods
    /// \param matrix
    /// \return bool: true if the matrices have the same values
    bool operator==(const SymbolicSquareMatrix &matrix) const;

    /// friend needed to access private attributes of SymbolicSquareMatrix objects
    ///
    friend std::ostream &operator<<(std::ostream &os, const SymbolicSquareMatrix &matrix);

    /// inputs the object into ostream by calling the << operator overload
    /// \param os
    void print(std::ostream &os);

    ///
    /// \return string representation of SymbolicSquareMatrix object
    std::string toString() const;

    ConcreteSquareMatrix evaluate(const Valuation &valuation) const;
};

/// Inputs the matrix into ostream in the format [[1n,2n][3n,4n]]
/// \param os  : The empty ostream
/// \return : The full ostream
std::ostream &operator<<(std::ostream &os, const SymbolicSquareMatrix &matrix);

#endif //VT5_SYMBOLICSQUAREMATRIX_H
