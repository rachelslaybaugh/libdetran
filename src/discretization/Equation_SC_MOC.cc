//----------------------------------*-C++-*----------------------------------//
/*!
 * \file   Equation_SC_MOC.cc
 * \brief  Equation_SC_MOC 
 * \author Jeremy Roberts
 * \date   Jun 23, 2012
 */
//---------------------------------------------------------------------------//

// Detran
#include "Equation_SC_MOC.hh"

namespace detran
{

Equation_SC_MOC::Equation_SC_MOC(SP_mesh mesh,
                                 SP_material material,
                                 SP_quadrature quadrature,
                                 const bool update_psi)
  : Equation_MOC(mesh, material, quadrature, update_psi)
  , d_weights(quadrature->number_polar_octant(), 0.0)
  , d_inv_sin(quadrature->number_polar_octant(), 0.0)
{
  for (int p = 0; p < d_quadrature->number_polar_octant(); p++)
  {
    d_inv_sin[p] = 1.0 / d_quadrature->sin_theta(p);
  }
}

void Equation_SC_MOC::setup_group(const size_t g)
{
  Require(g < d_material->number_groups());
  d_g = g;
}

void Equation_SC_MOC::setup_octant(const size_t octant)
{
  Require(octant < 4);
  d_octant = octant;
}

void Equation_SC_MOC::setup_azimuth(const size_t a)
{
  // Currently, only the 1st octant values should be in use.
  Require(a < d_quadrature->number_azimuths_octant());
  d_azimuth = a;
  d_spacing = d_tracks->spacing(d_azimuth);
  for (int p = 0; p < d_quadrature->number_polar_octant(); p++)
  {
    int angle = d_quadrature->angle(a, p);
    d_weights[p] = d_quadrature->weight(angle);
  }
}

void Equation_SC_MOC::setup_polar(const size_t p)
{
  // Currently, only the 1st octant values should be in use.
  Require(p < d_quadrature->number_polar_octant());
  d_polar = p;
  d_angle = d_quadrature->angle(d_azimuth, d_polar);
}

} // end namespace detran

//---------------------------------------------------------------------------//
//              end of file Equation_SC_MOC.cc
//---------------------------------------------------------------------------//
