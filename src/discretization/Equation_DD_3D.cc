//----------------------------------*-C++-*----------------------------------//
/*!
 * \file   Equation_DD_3D.cc
 * \author Jeremy Roberts
 * \date   Mar 31, 2012
 * \brief  Equation_DD_3D member definitions.
 * \note   Copyright (C) 2012 Jeremy Roberts.
 */
//---------------------------------------------------------------------------//

#include "Equation_DD_3D.hh"

namespace detran
{

Equation_DD_3D::Equation_DD_3D(SP_mesh mesh,
                               SP_material material,
                               SP_quadrature quadrature,
                               bool update_psi)
  :  Equation<_3D>(mesh, material, quadrature, update_psi)
  ,  d_coef_x(mesh->number_cells_x())
  ,  d_coef_y(mesh->number_cells_y())
  ,  d_coef_z(mesh->number_cells_z())
{
  /* ... */
}

void Equation_DD_3D::setup_group(const size_t g)
{
  Require(g < d_material->number_groups());
  d_g = g;
}

void Equation_DD_3D::setup_octant(const size_t octant)
{
  Require(octant < 8);
  d_octant = octant;
}

void Equation_DD_3D::setup_angle(const size_t angle)
{
  // Currently, only the 1st octant values should be in use.
  Require(angle < d_quadrature->number_angles_octant());
  double mu  = d_quadrature->mu(0, angle);
  double eta = d_quadrature->eta(0, angle);
  double xi  = d_quadrature->xi(0, angle);
  for (int i = 0; i < d_mesh->number_cells_x(); i++)
  {
    d_coef_x[i] = 2.0 * mu / d_mesh->dx(i);
  }
  for (int j = 0; j < d_mesh->number_cells_y(); j++)
  {
    d_coef_y[j] = 2.0 * eta / d_mesh->dy(j);
  }
  for (int k = 0; k < d_mesh->number_cells_z(); k++)
  {
    d_coef_z[k] = 2.0 * xi / d_mesh->dz(k);
  }
  d_angle = angle;
}

} // end namespace detran

//---------------------------------------------------------------------------//
//              end of Equation_DD_3D.cc
//---------------------------------------------------------------------------//
