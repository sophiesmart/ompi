/*
 * $HEADER$
 */

#include "ompi_config.h"

#include <stdio.h>

#include "mpi.h"
#include "mpi/f77/bindings.h"

#if OMPI_HAVE_WEAK_SYMBOLS && OMPI_PROFILE_LAYER
#pragma weak PMPI_SCATTER = mpi_scatter_f
#pragma weak pmpi_scatter = mpi_scatter_f
#pragma weak pmpi_scatter_ = mpi_scatter_f
#pragma weak pmpi_scatter__ = mpi_scatter_f
#elif OMPI_PROFILE_LAYER
OMPI_GENERATE_F77_BINDINGS (PMPI_SCATTER,
                           pmpi_scatter,
                           pmpi_scatter_,
                           pmpi_scatter__,
                           pmpi_scatter_f,
                           (char *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, char *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr),
                           (sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr) )
#endif

#if OMPI_HAVE_WEAK_SYMBOLS
#pragma weak MPI_SCATTER = mpi_scatter_f
#pragma weak mpi_scatter = mpi_scatter_f
#pragma weak mpi_scatter_ = mpi_scatter_f
#pragma weak mpi_scatter__ = mpi_scatter_f
#endif

#if ! OMPI_HAVE_WEAK_SYMBOLS && ! OMPI_PROFILE_LAYER
OMPI_GENERATE_F77_BINDINGS (MPI_SCATTER,
                           mpi_scatter,
                           mpi_scatter_,
                           mpi_scatter__,
                           mpi_scatter_f,
                           (char *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, char *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr),
                           (sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr) )
#endif


#if OMPI_PROFILE_LAYER && ! OMPI_HAVE_WEAK_SYMBOLS
#include "mpi/f77/profile/defines.h"
#endif

OMPI_EXPORT
void mpi_scatter_f(char *sendbuf, MPI_Fint *sendcount, 
		   MPI_Fint *sendtype, char *recvbuf,
		   MPI_Fint *recvcount, MPI_Fint *recvtype,
		   MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr)
{
    MPI_Datatype c_sendtype, c_recvtype;
    MPI_Comm c_comm = MPI_Comm_f2c(*comm);
    
    c_sendtype = MPI_Type_f2c(*sendtype);
    c_recvtype = MPI_Type_f2c(*recvtype);

    *ierr = OMPI_INT_2_FINT(MPI_Scatter(sendbuf,OMPI_FINT_2_INT(*sendcount),
					c_sendtype, recvbuf, 
					OMPI_FINT_2_INT(*recvcount),
					c_recvtype, 
					OMPI_FINT_2_INT(*root), c_comm));
}
