//----------------------------------*-C++-*----------------------------------//
/*!
 * \file   GaussSeidel.i.hh
 * \author robertsj
 * \date   Apr 10, 2012
 * \brief  GaussSeidel inline member definitions.
 * \note   Copyright (C) 2012 Jeremy Roberts. 
 */
//---------------------------------------------------------------------------//

#ifndef GAUSSSEIDEL_I_HH_
#define GAUSSSEIDEL_I_HH_

// Utilities
#include "Warning.hh"

// System
#include <algorithm>

namespace detran
{

template <class D>
void GaussSeidel<D>::solve()
{

  std::cout << "  Starting GS." << std::endl;

  // Initial downscatter.
  for (int g = 0; g < d_number_groups; g++)
  {
    d_inner_solver->solve(g);
  }

  // Do upscatter iterations if required.
  if (!d_downscatter)
  {
    // Upscatter iterations.
    int iteration;
    double error;
    for (iteration = 0; iteration < d_max_iters; iteration++)
    {
      // Reset the error.
      error = 0.0;

      // Save current group flux.
      State::group_moments_type phi_old = d_state->all_phi();

      // Loop over just those groups into which upscatter occurs.  I have
      // no idea whether symmetric GS (i.e. loop up and down) is better.
      for (int g = d_material->upscatter_cutoff(); g < d_number_groups; g++)
      {
        d_inner_solver->solve(g);
        // Constructing the L-inf norm piecewise.
        error = std::max(error, norm_residual(d_state->phi(g), phi_old[g], true));
      }

      std::cout << "  GS Iter: " << iteration << " Error: " << error << std::endl;
      if (error < d_tolerance) break;

    } // upscatter loop

    if (error > d_tolerance)
      warning(SOLVER_CONVERGENCE, "Gauss-Seidel did not converge.");

  }

  std::cout << "  GS done." << std::endl;
}

// Explicit instantiations

template class GaussSeidel<_1D>;
template class GaussSeidel<_2D>;
template class GaussSeidel<_3D>;

} // end namespace detran

#endif /* GAUSSSEIDEL_I_HH_ */
