/*
 * $HEADER$
 */

#include "ompi_config.h"

#include <stdio.h>

#include "mpi.h"
#include "mpi/f77/bindings.h"

#if OMPI_HAVE_WEAK_SYMBOLS && OMPI_PROFILE_LAYER
#pragma weak PMPI_TYPE_GET_EXTENT = mpi_type_get_extent_f
#pragma weak pmpi_type_get_extent = mpi_type_get_extent_f
#pragma weak pmpi_type_get_extent_ = mpi_type_get_extent_f
#pragma weak pmpi_type_get_extent__ = mpi_type_get_extent_f
#elif OMPI_PROFILE_LAYER
OMPI_GENERATE_F77_BINDINGS (PMPI_TYPE_GET_EXTENT,
                           pmpi_type_get_extent,
                           pmpi_type_get_extent_,
                           pmpi_type_get_extent__,
                           pmpi_type_get_extent_f,
                           (MPI_Fint *type, MPI_Fint *lb, MPI_Fint *extent, MPI_Fint *ierr),
                           (type, lb, extent, ierr) )
#endif

#if OMPI_HAVE_WEAK_SYMBOLS
#pragma weak MPI_TYPE_GET_EXTENT = mpi_type_get_extent_f
#pragma weak mpi_type_get_extent = mpi_type_get_extent_f
#pragma weak mpi_type_get_extent_ = mpi_type_get_extent_f
#pragma weak mpi_type_get_extent__ = mpi_type_get_extent_f
#endif

#if ! OMPI_HAVE_WEAK_SYMBOLS && ! OMPI_PROFILE_LAYER
OMPI_GENERATE_F77_BINDINGS (MPI_TYPE_GET_EXTENT,
                           mpi_type_get_extent,
                           mpi_type_get_extent_,
                           mpi_type_get_extent__,
                           mpi_type_get_extent_f,
                           (MPI_Fint *type, MPI_Fint *lb, MPI_Fint *extent, MPI_Fint *ierr),
                           (type, lb, extent, ierr) )
#endif


#if OMPI_PROFILE_LAYER && ! OMPI_HAVE_WEAK_SYMBOLS
#include "mpi/f77/profile/defines.h"
#endif

OMPI_EXPORT
void mpi_type_get_extent_f(MPI_Fint *type, MPI_Fint *lb,
			   MPI_Fint *extent, MPI_Fint *ierr)
{
    MPI_Datatype c_type = MPI_Type_f2c(*type);
    MPI_Aint c_lb;
    MPI_Aint c_extent;

    *ierr = OMPI_INT_2_FINT(MPI_Type_get_extent(c_type, &c_lb, &c_extent));

    if (MPI_SUCCESS == *ierr){
      *lb = (MPI_Fint) c_lb;
      *extent = (MPI_Fint) c_extent;
    }

}
