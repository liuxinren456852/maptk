/*ckwg +29
 * Copyright 2011-2014 by Kitware, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 *  * Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 *  * Neither name of Kitware, Inc. nor the names of any contributors may be used
 *    to endorse or promote products derived from this software without specific
 *    prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * \file
 * \brief test support functions involving generic math
 */

#ifndef MAPTK_TEST_MATH_H_
#define MAPTK_TEST_MATH_H_

#include <cmath>

#include <maptk/core/matrix.h>
#include <maptk/core/vector.h>


namespace maptk
{

namespace testing
{


/// Near comparison function for vectors
/**
 * Drop-in compatible with TEST_NEAR. Just need to include this header.
 */
template <unsigned N, typename T>
bool is_almost(vector_<N,T> const& a, vector_<N,T> const& b,
               double const& epsilon)
{
  for (unsigned i=0; i<N; ++i)
  {
    if (fabs(a[i] - b[i]) > epsilon)
    {
      return false;
    }
  }
  return true;
}


/// Near comparison function for vectors
/**
 * Drop-in compatible with TEST_NEAR. Just need to include this header.
 */
template <unsigned M, unsigned N, typename T>
bool is_almost(matrix_<M,N,T> const& a, matrix_<M,N,T> const& b,
               double const& epsilon)
{
  for (unsigned i=0; i<M; ++i)
  {
    for (unsigned j=0; j<N; ++j)
    {
      if (fabs(a(i,j) - b(i,j)) > epsilon)
      {
        return false;
      }
    }
  }
  return true;
}


}

}


#endif // MAPTK_TEST_MATH_H_
