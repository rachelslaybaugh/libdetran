//----------------------------------*-C++-*----------------------------------//
/*!
 * \file   InputDB.hh
 * \author Jeremy Roberts
 * \brief  InputDB class definition.
 */
//---------------------------------------------------------------------------//

#ifndef INPUTDB_HH_
#define INPUTDB_HH_

// Utilities headers
#include "DBC.hh"
#include "Definitions.hh"

// System headers
#include <string>
#include <map>

namespace detran_utils
{

//===========================================================================//
/*!
 * \class InputDB
 * \brief Flexible storage for user input.
 *
 * User input for transport codes typically involves several integer and
 * scalar quantities along with meshing, materials data, and materials
 * placement.  For the former quantities, it can be a bonafide pain in the
 * arse to maintain an input structure throughout development.  To avoid that
 * issue, we use C++ maps of type int and double to store anything the user
 * needs to put there for use anywhere in the code.  This is inspired by the
 * way Denovo handles input.  For us, a descendent of Parser will read some
 * form of user input (be it XML or SILO or HDF5) and fill an InputDB along
 * with generating other things (like the data needed to make meshes and
 * materials libraries).  Of course, some parameters need to be there, and
 * that can be checked during a verification.
 *
 * (It's anticipated this will become a serment-wide approach)
 *
 */
//===========================================================================//

class InputDB : public Object
{

public:

  /*!
   *  \brief Constructor.
   */
  InputDB();

  /// \name Accessors
  //\{

  /*!
   *  \brief Return value of key
   *  \param    key     Name of the parameter.
   *  \param    value   Reference to which parameter value is assigned.
   *  \return           Check whether key is found.
   */
  template <class T>
  T get(const std::string &key) const;

//  template <class T>
//  void get(const std::string &key, T &value) const;

  /*!
   *  \brief Put a key and value in the database.
   *  \param    key         Name of the parameter.
   *  \param    value       Reference to which parameter value is assigned.
   *  \param    replace     Can we replace a current value?
   *  \return               Check whether key is found.
   */
  template <class T>
  void put(const std::string &key, const T value);

  //\}

  /*
   *  \brief Validate the input database.
   *
   *  This is probably the only place where upkeep needs to occur.  There
   *  may be an intelligent way to do it, something like a "grammar".
   *
   *  \return Whether or not verification was successful.
   */
  bool is_valid() const {};

private:

  /// \name Data
  //\{

  /// Integer parameters.
  std::map<std::string, int> d_data_int;

  /// Double parameters.
  std::map<std::string, double> d_data_dbl;

  /// Integer vector parameters.
  std::map<std::string, vec_int> d_data_vec_int;

  /// Double vector parameters.
  std::map<std::string, vec_dbl> d_data_vec_dbl;

  /// String parameters.
  std::map<std::string, std::string> d_data_str;

  //\}

  /// \name Implementation
  //\{

  //\}

};


} // end namespace detran_utils

#endif /* INPUTDB_HH_ */

//---------------------------------------------------------------------------//
//              end of InputDB.hh
//---------------------------------------------------------------------------//
