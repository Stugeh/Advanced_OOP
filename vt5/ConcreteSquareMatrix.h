#ifndef VT5_CONCRETESQUAREMATRIX_H
#define VT5_CONCRETESQUAREMATRIX_H

#include <vector>
#include "IntElement.h"
#include <string>
#include <ostream>
#include <memory>


///ConcreteSquareMatrix header.
/// Concrete matrices only contain IntElements and can
/// therefore be used for calculations.



/**
 * \param n : amount of elements in each row / amount of rows
 * \param elements : stores the elements. Elements can be of type IntElement.
 */
class ConcreteSquareMatrix {
private:
    unsigned int n{0};
    std::vector<std::vector<std::unique_ptr<IntElement>>> elements{};

public:
    ///
    ///default constructor makes an empty matrix.
    ConcreteSquareMatrix();

    /// Builds a matrix from a string if the string is formatted similar to [[1n,2n][3n,4n]]
    /// Turns string into the matrix and calculates how many elements are in each line to set n.
    /// \param m_string string that contains the matrix.
    ConcreteSquareMatrix(const std::string &m_string);

    /// utility constructor used to create a matrix object if the matrix is already saved in a 2d vector
    /// and n is known.
    /// \param matrix  : a container of type std::vector<std::vector<std::unique_ptr<IntElement>>>
    /// \param pN  : number of rows
    ConcreteSquareMatrix(std::vector<std::vector<std::unique_ptr<IntElement>>> matrix, unsigned int pN);

    /// Copy constructor.
    /// Loops through existing matrix, copies containers values creates new pointers to them and sets the n.
    ///\param matrix : existing matrix object
    ConcreteSquareMatrix(const ConcreteSquareMatrix &matrix);

    /// move constructor overload for matrices
    /// \param matrix  : existing matrix object
    ConcreteSquareMatrix(ConcreteSquareMatrix &&matrix);

    ///destructor
    ///
    virtual ~ConcreteSquareMatrix();

    /// assignment operator
    /// \param matrix
    /// \return
    ConcreteSquareMatrix &operator=(const ConcreteSquareMatrix &matrix);

    /// move assignment operator
    /// \param matrix
    /// \return
    ConcreteSquareMatrix &operator=(ConcreteSquareMatrix &&matrix);

    /// transposes the matrix it's called on in place.
    /// \return *this
    ConcreteSquareMatrix transpose() const;

    /// overload for += when used in between ConcreteSquareMatrix objects.
    /// \param matrix : existing matrix object
    /// \return : the sum of the 2 objects
    ConcreteSquareMatrix &operator+=(const ConcreteSquareMatrix &matrix);

    /// overload for -= when used in between ConcreteSquareMatrix objects.
    /// \param matrix : existing matrix object
    /// \return : the matrix after successful subtraction
    ConcreteSquareMatrix &operator-=(const ConcreteSquareMatrix &matrix);

    /// overload for *= when used in between ConcreteSquareMatrix objects.
    /// \param matrix : existing matrix object
    /// \return : the matrix after successful multiplication
    ConcreteSquareMatrix &operator*=(const ConcreteSquareMatrix &matrix);

    /// Compares 2 ConcreteSquareMatrix objects by calling their toString methods
    /// \param matrix
    /// \return bool: true if the matrices have the same values
    bool operator==(const ConcreteSquareMatrix &matrix) const;

    /// inputs the object into ostream by calling the << operator overload
    /// \param os
    void print(std::ostream &os);

    ///
    /// \return string representation of ConcreteSquareMatrix object
    std::string toString() const;

    /// friend needed to access private attributes of ConcreteSquareMatrix objects
    ///
    friend std::ostream &operator<<(std::ostream &os, const ConcreteSquareMatrix &matrix);

    /// friend needed to access private attributes of ConcreteSquareMatrix objects
    ///
    friend ConcreteSquareMatrix operator+(ConcreteSquareMatrix const &matrix1, ConcreteSquareMatrix const &matrix2);

    /// friend needed to access private attributes of ConcreteSquareMatrix objects
    ///
    friend ConcreteSquareMatrix operator-(ConcreteSquareMatrix const &matrix1, ConcreteSquareMatrix const &matrix2);

        /// friend needed to access private attributes of ConcreteSquareMatrix objects
        ///
    friend ConcreteSquareMatrix operator*(ConcreteSquareMatrix const &matrix1, ConcreteSquareMatrix const &matrix2);

};

/// Used to input sum of two matrices into a new matrix without altering the original ones
/// \param matrix1  : left side of +
/// \param matrix2 : right side of +
/// \return  : sum
ConcreteSquareMatrix operator+(ConcreteSquareMatrix const &matrix1, ConcreteSquareMatrix const &matrix2);

/// Used to input difference of two matrices into a new matrix without altering the original ones
/// \param matrix1  : left side of -
/// \param matrix2 : right side of -
/// \return : the difference of the matrices
ConcreteSquareMatrix operator-(ConcreteSquareMatrix const &matrix1, ConcreteSquareMatrix const &matrix2);

/// Used to input product of two matrices into a new matrix without altering the original ones
/// \param matrix1 : left side of *
/// \param matrix2 : right side of *
/// \return : product
ConcreteSquareMatrix operator*(ConcreteSquareMatrix const &matrix1, ConcreteSquareMatrix const &matrix2);

/// Inputs the matrix into ostream in the format [[1n,2n][3n,4n]]
/// \param os  : The empty ostream
/// \return : The full ostream
std::ostream &operator<<(std::ostream &os, const ConcreteSquareMatrix &);

#endif //VT5_CONCRETESQUAREMATRIX_H
