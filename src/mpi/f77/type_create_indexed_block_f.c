/*
 * $HEADER$
 */

#include "ompi_config.h"

#include <stdio.h>

#include "mpi.h"
#include "mpi/f77/bindings.h"

#if OMPI_HAVE_WEAK_SYMBOLS && OMPI_PROFILE_LAYER
#pragma weak PMPI_TYPE_CREATE_INDEXED_BLOCK = mpi_type_create_indexed_block_f
#pragma weak pmpi_type_create_indexed_block = mpi_type_create_indexed_block_f
#pragma weak pmpi_type_create_indexed_block_ = mpi_type_create_indexed_block_f
#pragma weak pmpi_type_create_indexed_block__ = mpi_type_create_indexed_block_f
#elif OMPI_PROFILE_LAYER
OMPI_GENERATE_F77_BINDINGS (PMPI_TYPE_CREATE_INDEXED_BLOCK,
                           pmpi_type_create_indexed_block,
                           pmpi_type_create_indexed_block_,
                           pmpi_type_create_indexed_block__,
                           pmpi_type_create_indexed_block_f,
                           (MPI_Fint *count, MPI_Fint *blocklength, MPI_Fint *array_of_displacements, MPI_Fint *oldtype, MPI_Fint *newtype, MPI_Fint *ierr),
                           (count, blocklength, array_of_displacements, oldtype, newtype, ierr) )
#endif

#if OMPI_HAVE_WEAK_SYMBOLS
#pragma weak MPI_TYPE_CREATE_INDEXED_BLOCK = mpi_type_create_indexed_block_f
#pragma weak mpi_type_create_indexed_block = mpi_type_create_indexed_block_f
#pragma weak mpi_type_create_indexed_block_ = mpi_type_create_indexed_block_f
#pragma weak mpi_type_create_indexed_block__ = mpi_type_create_indexed_block_f
#endif

#if ! OMPI_HAVE_WEAK_SYMBOLS && ! OMPI_PROFILE_LAYER
OMPI_GENERATE_F77_BINDINGS (MPI_TYPE_CREATE_INDEXED_BLOCK,
                           mpi_type_create_indexed_block,
                           mpi_type_create_indexed_block_,
                           mpi_type_create_indexed_block__,
                           mpi_type_create_indexed_block_f,
                           (MPI_Fint *count, MPI_Fint *blocklength, MPI_Fint *array_of_displacements, MPI_Fint *oldtype, MPI_Fint *newtype, MPI_Fint *ierr),
                           (count, blocklength, array_of_displacements, oldtype, newtype, ierr) )
#endif


#if OMPI_PROFILE_LAYER && ! OMPI_HAVE_WEAK_SYMBOLS
#include "mpi/f77/profile/defines.h"
#endif

OMPI_EXPORT
void mpi_type_create_indexed_block_f(MPI_Fint *count, MPI_Fint *blocklength,
				     MPI_Fint *array_of_displacements, 
				     MPI_Fint *oldtype, MPI_Fint *newtype,
				     MPI_Fint *ierr)
{
    MPI_Datatype c_old = MPI_Type_f2c(*oldtype);
    MPI_Datatype c_new;
    OMPI_ARRAY_NAME_DECL(array_of_displacements);

    OMPI_ARRAY_FINT_2_INT(array_of_displacements, *count);

    *ierr = OMPI_INT_2_FINT(
		    MPI_Type_create_indexed_block(OMPI_FINT_2_INT(*count),
			OMPI_FINT_2_INT(*blocklength),
			OMPI_ARRAY_NAME_CONVERT(array_of_displacements),
                        c_old, &c_new));
    
    if (MPI_SUCCESS == *ierr) {
      *newtype = MPI_Type_c2f(c_new);
    }

    OMPI_ARRAY_FINT_2_INT_CLEANUP(array_of_displacements);
}

