/**************************************************************/
/*                     pyMPI_Externals.h                      */
/*              Machine generated... Do not edit              */
/**************************************************************/

#ifndef PYMPI_EXTERNALS_H
#define PYMPI_EXTERNALS_H

#ifdef __cplusplus
  extern "C" {
#endif

#ifndef __THROW
#define __THROW
#endif

/**************************************************************/
/*                       pyMPI_Types.h                        */
/**************************************************************/

/**************************************************************/
/*                       pyMPI_banner.c                       */
/**************************************************************/
extern DL_IMPORT(void) pyMPI_banner(char* buffer, int n) ;

/**************************************************************/
/*                        pyMPI_cart.c                        */
/**************************************************************/
#define PYMPI_CART_GET_DIMS_DOC "Dims object used to build communicator\n\ndims -> (integer, ...)\n\n>>> print dir()\n>>> torus = cartesian_communicator()\n>>> dim = torus.dims   # returns (WORLD.size,) the default\n\n>>> assert WORLD.size%2 == 0, \"have an even number of processors\"\n>>> grid = cartesian_communicator(dims=[WORLD.size/2,2])\n>>> dim2 = grid.dims   # returns (WORLD.size/2,2)\n\n"
#define PYMPI_CART_GET_NDIMS_DOC "Dimensionality of the torus, grid, cube, hypercube, etc...\n\nndims -> integer\n\n>>> torus = cartesian_communicator()\n>>> n = torus.ndims       # returns 1 because this is a 1D torus\n\n"
#define PYMPI_CART_GET_PERIODS_DOC "Period object used to build communicator\n\nperiods -> (integer, ...)\n\n>>> torus = cartesian_communicator()\n>>> periods = torus.periods  # returns (1,) the default\n\n>>> one_D = cartesian_communicator(periods=[0])  # No wrap around\n>>> periods1 = one_D.periods  # returns (0,) in this case\n\n>>> assert WORLD.size %2 == 0, \"have an even processor count...\"\n>>> grid = cartesian_communicator(dims=[WORLD.size/2,2])\n>>> periods2 = one_D.periods  # returns (1,1) here\n\n"
#define PYMPI_CART_COORDS_DOC "Get local or remote grid coordinate\n\ncoords(rank=local_rank)\n--> (integer,...)\n\nReturns an n-dimensional tuple with the coordiantes of the requested\nrank on this communicator.  The rank can be a negative integer where\n-1, for instance, is the last rank\n\n>>> torus = cartesian_communicator()\n>>> x = torus.coords()      # returns torus.rank (local 1D position)\n\n>>> assert WORLD.size%2 == 0, \"have an even processor count\"\n>>> grid = cartesian_communicator(dims=[WORLD.size/2,2])\n>>> x0,y0 = grid.coords(0)   # Rank 0\\'s x,y position\n>>> xn,yn = grid.coords(-1)  # Last rank\\'s x,y position\n\n"
#define PYMPI_CART_SHIFT_DOC "Get source/destination with specified shift\n\ncart_shift(direction=0,         # 0 <= Dimension to move < ndims\n           displacement=1,      # steps to take in that dimension\n--> integer,integer\n\nThe direction refers to a grid dimension, not a cardinal direction\n\n>>> torus = cartesian_communicator()\n>>> left,right = torus.shift()\n\n>>> assert WORLD.size%2 == 0, \"have an even processor count\"\n>>> grid = cartesian_communicator(dims=[WORLD.size/2,2])\n>>> left,right = grid.shift(0)\n>>> up,down = grid.shift(1)\n\n"
#define PYMPI_CART_INIT_DOC "Create cartesian communicator from another communicator\n\ncartesian_communicator(old_comm=WORLD,       # Communicator to clone\n                       dims=[old_comm.size], # default to 1D\n                       periods=[1,...]       # default to torus\n                       reorder=1)            # can reorder ranks\n--> new cartesisan communicator\n\nInterface to MPI cartesian communicators which act identically to\nnormal communicators, but also embody the idea of a grid or torus on\ntop of that normal interface.  For instance, to set up a 1D torus and\nthen figure out each of your neighbors in forward direction\n(forward is positive, backwards is negative) on dimension 0:\n\n>>> torus = cartesian_communicator(WORLD, [WORLD.size], [1])\n>>> torus1 = cartesian_communicator(WORLD, [WORLD.size])\n>>> torus2 = cartesian_communicator(WORLD)\n\n>>> assert WORLD.size%2 == 2,\"even processor count\"\n>>> grid = cartesian_communicator(dims=[WORLD.size/2,2])\n\n>>> torus = cartesian_communicator(WORLD, [WORLD.size], [1])\n>>> src,dest = torus.shift(0,1)\n>>> msg,stat = torus.sendrecv(\\'I am rank %d\\'%torus.rank,dest,src)\n\nYou can find your n-dimensional coordinates too:\n>>> assert WORLD.size%2 == 2,\"even processor count\"\n>>> grid = mpi.cartesian_communicator(mpi.WORLD,[mpi.size/2,2],[1,1])\n>>> x,y = grid.coords()\n\nYou can also build a cartesian communicator by invoking a method\ndirectly on any communicator.\n>>> torus2 = WORLD.cart_create([WORLD.size])\n\n"
extern PyTypeObject pyMPI_cart_comm_type;
extern DL_IMPORT(void) pyMPI_cart_init(PyObject** docstringP) ;
extern DL_IMPORT(void) pyMPI_cart_fini(void) ;

/**************************************************************/
/*                        pyMPI_comm.c                        */
/**************************************************************/
extern PyObject* pyMPI_COMM_NULL;
extern PyObject* pyMPI_world;
#define PYMPI_COMM_INIT_DOC "Create communicator object from communicator or handle\n\ncommunicator(communicator=COMM_NULL,  # Communicator to wrap\n             persistent=1)            # If false, release MPI comm\n --> <communicator instance>\n\nBuild instance of a communicator interface.  The persistent flag (by\ndefault on) means that Python WILL NOT release the MPI communicator on\ndelete.\n\n>>> null = communicator()      # returns a (not the) NULL communicator\n>>> c = communicator(WORLD)    # a new interface to WORLD communicator\n>>> my_world = communicator(handle,0) # Python version of handle\n                                      # MPI_Comm_free() will be called\n\n"
#define PYMPI_COMM_FREE_DOC "Release the MPI communicator\n\nrelease() --> None\n\nThis tells MPI that the communicator is no longer in use.  The WORLD\nand NULL communicators are not freed and the method returns silently.\n\n>>> comm.comm_free()\n\n"
#define PYMPI_COMM_STOPWATCH_DOC "Returns time in seconds since last call (or communicator creation)\n\nstopwatch() --> float    # Double precision time\n\n>>> mpi.stopwatch() # Start the timer\n>>> deep_thought()\n>>> print \'Deep thought took\',mpi.stopwatch(),\'seconds\'\n\nA separate timer is maintained for every Python communicator.\n>>> comm.stopwatch()\n\n"
#define PYMPI_COMM_TICK_DOC "Return the ticksize of the high-resolution timer (Python Float)\n\ntick() --> float\n\nThe smallest tick for the MPI high resolution timer.  See time() to\nget time in seconds since the epoch.\n\n>>> tick = mpi.tick()\n\n"
#define PYMPI_COMM_TIME_DOC "Returns the time in seconds (as Python Float) since epoch.\n\ntime() --> float\n\nUses the MPI high resolution timer, not system clock.  See tick()\nfor clock resolution\n\n>>> mpi.time()\n\n"
#define PYMPI_COMM_GET_RANK_DOC "Return the local rank of a communicator.  See also mpi.get_rank()\n\nrank --> int\n\n>>> rank = mpi.rank          # returns mpi.WORLD.get_rank()\n>>> rank2 = comm.rank         # returns comm.get_rank()\n\n"
#define PYMPI_COMM_GET_SIZE_DOC "Return the size of a communicator.  See also get_size()\n\nsize --> int\n\n>>> nprocs = mpi.size    # returns mpi.WORLD.size in reality\n>>> cprocs = comm.size   # returns comm.get_size() as an attribute\n\n"
#define PYMPI_COMM_GET_PERSISTENT_DOC "Persistence controls the MPI release of a communicator on destruction\n\npersistent --> int\n\n>>> flag = comm.persistent  # returns 1 by default\n>>> comm.persistent = 0     # can also be cleared in c\'tor\n\n"
extern PyTypeObject pyMPI_comm_type;
extern DL_IMPORT(PyObject*) pyMPI_comm(MPI_Comm communicator) ;
extern DL_IMPORT(void) pyMPI_comm_init(PyObject** docStringP) ;
extern DL_IMPORT(void) pyMPI_comm_fini(void) ;

/**************************************************************/
/*                 pyMPI_comm_asynchronous.c                  */
/**************************************************************/
extern DL_IMPORT(PyObject*) pyMPI_asynchronous_isend(PyObject* pySelf, PyObject* args, PyObject* kw) ;
#define PYMPI_ASYNCHRONOUS_ISEND_DOC "Send a message, but do not block while it is inflight\n\nisend(message,           # serializable Python object\n      destination,       # rank of receiving process\n      tag=0)             # integer message tag\n--> request\n\nJust like send(), but guarantees that the sender will not block.\n\n>>> right = (WORLD.rank+1)%WORLD.size\n>>> request = isend(\"hello\",right)\n\nThe request object can be tested to see if it has been received\nSee request.test() and request.wait() for information.\n\n"
extern DL_IMPORT(PyObject*) pyMPI_asynchronous_irecv(PyObject* pySelf, PyObject* args, PyObject* kw) ;
#define PYMPI_ASYNCHRONOUS_IRECV_DOC "Nonblocking request for a message\n\n>>> left = (WORLD.size+WORLD.rank-1)%WORLD.size\n>>> request = irecv(left)\n\nWith the default arguments, you can request any message\n>>> request = irecv()\n\nOr you can request any message with a particular tag\n>>> request = irecv(tag=33)\n\nThe request object can be tested to see if it has been received\nSee request.test() and request.wait() for information.\n\n"
extern DL_IMPORT(PyObject*) pyMPI_asynchronous_test(PyObject* pySelf, PyObject* args, PyObject* kw) ;
#define PYMPI_ASYNCHRONOUS_TEST_DOC "Test if a request has been fulfilled.\n\ntest(request) --> boolean\n\nNote that this is really just a convenience since the function will\nactually invokes a property of the request.  That is,\nmpi.test(R) is the same as R.test\n\nThis call does not block.                                              *\n\n>>> is_done = mpi.test(request)\n>>> if request:  print \'done\'     # Another way to invoke a test\n>>> if request.test: print \'done\' # Using request\'s built in method\n\n"
extern DL_IMPORT(PyObject*) pyMPI_asynchronous_test_cancelled(PyObject* pySelf, PyObject* args, PyObject* kw) ;
#define PYMPI_ASYNCHRONOUS_TEST_CANCELLED_DOC "Test if a request has been cancelled.\n\ntest_cancelled(request) --> boolean\n\nNote that this is really just a convenience since the function\nactually invokes a property of the request.\n\nCall does not block.                                                   *\n\n>>> request = mpi.irecv(somewhere)\n>>> is_done = mpi.test_cancelled(request)  # or request.test_cancelled\n\n"
extern DL_IMPORT(PyObject*) pyMPI_asynchronous_testall(PyObject* pySelf, PyObject* args) ;
#define PYMPI_ASYNCHRONOUS_TESTALL_DOC "True if all requests are completed.\n\ntestall(request,request,...) --> boolean\ntestall([request,request,...]) --> boolean\ntestall((request,request,...)) --> boolean\n\nIf some requests are pending, then an empty list is returned.\nCall does not block.\n\n>>> statuses = testall(request0,request1,...)\n\nor you may pass a list/tuple of requests, e.g.\n\n>>> statuses = testall([request0,request1,...])\n>>> statuses = testall((request0,request1,...))\n\n"
extern DL_IMPORT(PyObject*) pyMPI_asynchronous_testany(PyObject* pySelf, PyObject* args) ;
#define PYMPI_ASYNCHRONOUS_TESTANY_DOC "Get index of a fulfilled request\n\ntestany(request,request,...) --> int,status | None,None\ntestany([request,request,...]) --> int,status | None,None\ntestany((request,request,...)) --> int,status | None,None\n\nThis returns the index of a request that is complete and its status.\nIf no request has completed, None,None is returned.\nYou can either use multiple arguments or a list of requests.\n\n>>> index,status = mpi.testany(request0,request1,...)\n>>> index,status = mpi.testany([request0,request1,...])\n>>> index,status = mpi.testany((request0,request1,...))\n\n"
extern DL_IMPORT(PyObject*) pyMPI_asynchronous_testsome(PyObject* pySelf, PyObject* args) ;
#define PYMPI_ASYNCHRONOUS_TESTSOME_DOC "Find all requests that are ready.\n\ntestsome(request,request,...) --> [indices],[statuses]\ntestsome([request,request,...]) --> [indices],[statuses]\ntestsome((request,request,...)) --> [indices],[statuses]\n\nThis returns the indices of requests that are complete and those\nstatues.  If no request has completed, mpi.testsome returns two empty\nlists. You can either use multiple arguments or a list of requests.\n\n>>> indices,statuses = mpi.testsome(request0,request1,...)\n>>> for i in indices:\n...     print \'index\',i,\'is done\'\n\n"
extern DL_IMPORT(PyObject*) pyMPI_asynchronous_wait(PyObject* pySelf, PyObject* args, PyObject* kw) ;
#define PYMPI_ASYNCHRONOUS_WAIT_DOC "Wait for nonblocking operation to complete.\n\nwait(request) --> status\n\nThis function really just invokes the wait method on the request, so\n>>> status = mpi.wait(request)\n\nis really the same as\n>>> status = request.wait()\n\n"
extern DL_IMPORT(PyObject*) pyMPI_asynchronous_waitall(PyObject* pySelf, PyObject* args) ;
#define PYMPI_ASYNCHRONOUS_WAITALL_DOC "Wait for all requests to complete.\n\nwaitall(request,request,...) --> [statuses]\nwaitall([request,request,...]) --> [statuses]\nwaitall((request,request,...)) --> [statuses]\n\nReturns a tuple of the associated status values.  You can either enter\na list of requests or multiple request arguments.  The length of the\nstatuses list is the same as the number of requests (even if the\nnumber of requests is zero).\n\nThis call blocks until all requests are fulfilled\n\n>>> statuses=waitall(request0,request1,...)\n>>> statuses=waitall([request0,request1,...])\n>>> statuses=waitall((request0,request1,...))\n\n"
extern DL_IMPORT(PyObject*) pyMPI_asynchronous_waitany(PyObject* pySelf, PyObject* args) ;
#define PYMPI_ASYNCHRONOUS_WAITANY_DOC "Wait for one of a set of requests to complete.\n\nwaitany(request,request,...) --> integer,status\nwaitany([request,request,...]) --> integer,status\nwaitany((request,request,...)) --> integer,status\n\nWait for one request to complete. Returns index of the request and\nassociated status.  Requests can be either multiple arguments or a\nlist of request objects.  Will block (or spin) if none are done.\nThe routine will throw ValueError if there are no requests.\n\nThis call blocks until all requests are fulfilled\n\n>>> index,status = waitany(request0,request1,...)\n>>> index,status = waitany([request0,request1,...])\n>>> index,status = waitany((request0,request1,...))\n\n"
extern DL_IMPORT(PyObject*) pyMPI_asynchronous_waitsome(PyObject* pySelf, PyObject* args) ;
#define PYMPI_ASYNCHRONOUS_WAITSOME_DOC "Wait until some of a set of requests are complete.\n\nwaitsome(request,request,...) --> [integer],[status]\nwaitsome([request,request,...]) --> [integer],[status]\nwaitsome((request,request,...)) --> [integer],[status]\n\nWaits for some communications to complete. Accepts a tuple of request\nhandles.  Will return a non-zero array of indices and statuses unless\nno requests are entered.\n\n>>> indices,statuses = waitsome(request0,request1,...)\n>>> indices,statuses = waitsome([request0,request1,...])\n>>> indices,statuses = waitsome((request0,request1,...))\n>>> empty,empty = waitsome()\n\n"
extern DL_IMPORT(PyObject*) pyMPI_asynchronous_cancel(PyObject* pySelf, PyObject* args, PyObject* kw) ;
#define PYMPI_ASYNCHRONOUS_CANCEL_DOC "Cancel a communication request.\n\ncancel() --> None\n\nThe standard indicates that this may have no effect for isends().\n\n>>> mpi.cancel(request)\n\nNote that this is the same as:\n>>> request.cancel()\n\n"

/**************************************************************/
/*                  pyMPI_comm_collective.c                   */
/**************************************************************/
extern DL_IMPORT(PyObject*) pyMPI_collective( PyMPI_Comm *self, int root, PyObject* localValue, int includeRank) ;
extern DL_IMPORT(PyObject*) pyMPI_collective_barrier(PyObject* pySelf, PyObject* args, PyObject* kw) ;
#define PYMPI_COLLECTIVE_BARRIER_DOC "Barrier\n\nbarrier() --> None\n\n>>> mpi.barrier()  # Block the WORLD communicator\n>>> comm.barrier()  # Block an arbitrary communicator\n\nBlocks processing for this processor until all cooperative tasks on\nthe communicator have called MPI_Barrier().  Note that the barrier()\ncalls can be in different locations in the code:\n\n>>> if WORLD.size%2:\n...    mpi.barrier()  # odd processors block here\n... else:\n...    mpi.barrier()  # even processors block here\n\nANY invocation on a particular communicator (even in C or FORTRAN)\nwill release the barrier.\n\n"
extern DL_IMPORT(PyObject*) pyMPI_collective_bcast(PyObject* pySelf, PyObject* args, PyObject* kw) ;
#define PYMPI_COLLECTIVE_BCAST_DOC "Broadcast value to all processors.\n\nbcast(value,root=0) --> value\n\nThis method messages a value from one process (the root) to all others\nThe value is ignored on the non-root ranks.\n\n>>> message = \"I am from rank %d\"%mpi.rank\n>>> value = bcast(message)\n>>> print value\nI am from rank 0\nI am from rank 0\nI am from rank 0\nI am from rank 0\n\n>>> assert WORLD.size > 1,\"running in parallel\"\n>>> message = \"I am from rank %d\"%mpi.rank\n>>> value = bcast(message,root=1)\n>>> print value\nI am from rank 1\nI am from rank 1\nI am from rank 1\nI am from rank 1\n\n"
extern DL_IMPORT(PyObject*) pyMPI_collective_scatter(PyObject* pySelf, PyObject* args, PyObject* kw) ;
#define PYMPI_COLLECTIVE_SCATTER_DOC "Scatter slices of list or sequence across processes.\n\nscatter(message,root=0) --> list or None\n\nOn the root process (rank 0 by default), evenly scatter elements of a\nlist or sequence message to all processes on the communicator.\n\n>>> global_data = None\n>>> if rank == 0:\n...    global_data = [11,22,33,44,...]\n>>> local_data = scatter(global_data)\n\n"
extern DL_IMPORT(PyObject*) pyMPI_collective_reduce(PyObject* pySelf, PyObject* args, PyObject* kw) ;
#define PYMPI_COLLECTIVE_REDUCE_DOC "Reduces values on all processes to a single value on root process\n\nreduce(message,        # Local value to reduce\n       operator,       # MPI_Op or a Python function to apply\n       root=0,         # Rank that gets reduced value\n       ground=None,    # Optional initial value for reduction\n       type=None)      # Optional guaranteed type\n--> reduced value | None\n\nMPI defines operators for BAND BOR BXOR LAND LOR LXOR MAX MAXLOC\nMIN MINLOC PROD and SUM.\n\nThe operator or function is applied across the values from each rank\'s\nprocess.  The result is:\n  op(op(...op(rank0_value,rank1_value),...),rankn-1_value)\n\nor if the optional ground value is specified,\n  op(op(op(...op(ground,rank0_value),rank1_value)...),rankn-1_value)\n\nThe MPI implementation may have fast implementations for commutative\nbuiltin ops. Python functions are assumed non-commutative\n\n>>> sum = reduce(mpi.rank, mpi.SUM)\n>>> print sum    # (((0+1)+2)+3) on 4 processes\n6\nNone\nNone\nNone\n\nIf you guarantee the type to be a basic type (int,float) through the\noptional type argument, Python will guarantee using the MPI built in\nreductions to minimize precision issues.\n>>> dt = reduce(local_dt,mpi.MIN,type=float)\n\nYou can use a class or callable object of two arguments as a operator\n(within the limits imposed by pickling)\n>>> print reduce(str(mpi.rank), os.path.join)\n0/1/2/3\nNone\nNone\nNone\n\n"
extern DL_IMPORT(PyObject*) pyMPI_collective_allreduce(PyObject* pySelf, PyObject* args, PyObject* kw) ;
#define PYMPI_COLLECTIVE_ALLREDUCE_DOC "Reduces values on all processes to the same value across all processes\nallreduce(message,        # Local value to reduce\n       operator,       # MPI_Op or a Python function to apply\n       root=0,         # Not applicable in allreduce\n       ground=None,    # Optional initial value for reduction\n       type=None)      # Optional guaranteed type\n--> reduced value\n\nMPI defines operators for BAND BOR BXOR LAND LOR LXOR MAX MAXLOC\nMIN MINLOC PROD and SUM.\n\nSee reduce() for more information.  Allreduce is like reduce(), but\nthe result is broadcast to all ranks across a communicator.\n\n>>> dt = allreduce(local_dt,mpi.MIN)\n>>> print dt\n1.125\n1.125\n1.125\n1.125\n\n"
extern DL_IMPORT(PyObject*) pyMPI_collective_scan(PyObject* pySelf, PyObject* args, PyObject* kw) ;
#define PYMPI_COLLECTIVE_SCAN_DOC "Return a running sum, product, etc... across multiple processes\n\nscan(message,operation) --> varies by message and operation\n\nScan is similar to allreduce, except it returns the partial results as\nwell as the local value.  A process of rank i, will receive a list of\ni values representing the sub-values on ranks 0, 1, 2, ... i\n\n>>> assert 0,\"TODO: Not implemented yet\"\n>>> print scan(rank,mpi.SUM)\n[0]\n[0,1]\n[0,1,3]\n[0,1,3,6]\n\nThat is (0,0+1,0+1+2,0+1+2+3) on 4 processors\n\n"
extern DL_IMPORT(PyObject*) pyMPI_collective_gather(PyObject* pySelf, PyObject* args, PyObject* kw) ;
#define PYMPI_COLLECTIVE_GATHER_DOC "Gather items from across the communicator\n\ngather(message,             # Some sequence object\n       count=len(message),  # Number of objects to send\n       root=0)              # Rank that gets the list\n--> [ list ] | None\n\nGather sub-lists to the root process.  The result is a concatenation\nof the sub-lists on the root process and None on the others.\n\n>>> print mpi.gather([WORLD.rank])\n[0,1,2,3]\nNone\nNone\nNone\n\n"
extern DL_IMPORT(PyObject*) pyMPI_collective_allgather(PyObject* pySelf, PyObject* args, PyObject* kw) ;
#define PYMPI_COLLECTIVE_ALLGATHER_DOC "Gather items from across the communicator\n\nallgather(message,             # Some sequence object\n          count=len(message),  # Number of objects to send\n          root=0)              # Rank that gets the list\n--> [ list ] | None\n\nGather sub-lists to the root process.  The result is a concatenation\nof the sub-lists on all processes (unlike gather which only gathers to\nthe root).\n\n>>> print mpi.allgather([WORLD.rank])\n[0,1,2,3]\n[0,1,2,3]\n[0,1,2,3]\n[0,1,2,3]\n\n"

/**************************************************************/
/*                      pyMPI_comm_io.c                       */
/**************************************************************/
extern DL_IMPORT(PyObject*) pyMPI_io_synchronizeQueuedOutput(PyObject* pySelf, PyObject* args, PyObject* kw) ;
#define PYMPI_IO_SYNCHRONIZEQUEUEDOUTPUT_DOC "Control output/errput on various ranks on a communicator. Synchronous\n\nsynchronizeQueuedOutput()\nsynchronizeQueuedOutput(stdout=string | None, stderr = string or None)\n\nUse this to change output methodology. All variants will flush any\npreviously queued output on stdout or stderr through root\'s outputs.\nThis sync is done by messaging the contents of the data queue (a file\non disk) to the master (rank 0) process which will output to its\nsys.stdout or sys.stderr.   The initial mechanism queues no data\n\nThere a number of variants that allow the user to change where output\nwill go for output operations that follow.\n\nTo queue stdout on slave processes to foo.out.1, foo.out.2, ...\n>>> synchronizeQueuedOutput(\'foo\')\nIf you never call sQO again, then all output is diverted to the files\nIf you DO call sQO again..\n>>> synchronizeQueuedOutput(\'foo\')\nor\n>>> synchronizeQueuedOutput()\nthen the contents of foo.out.1, foo.out.2, etc... are messaged to\nrank0 which will output them, and the files are opened as empty files\n\nIf you only want to do that to stderr,\n>>> synchronizeQueuedOutput(stderr=\'foo\')\n\nIf you want to throw away output on the slaves...\n>>> synchronizeQueuedOutput(\'/dev/null\')\n\nIf you want to turn on unrestricted output again\n>>> synchronizeQueuedOutput(stdout=None,stderr=None)\n\nIf you simply want to sync any output that may be queued, then call\nwith no arguments.\n\nEven though calls are synchronous, each rank can have its own output\nmodel (e.g. rank 1 can divert to /dev/null, rank 7 queues to a file,\nrank 93 just prints without queuing\n\nExamples:\n>>> synchronizeQueuedOutput() #Just synchronize however it was done\n                              # last time.\n>>> synchronizeQueuedOutput(\'/dev/null\',\'/dev/null\') # Slave proc pipe\n                              # subsequent output to /dev/null\nsynchronizeQueuedOutput(\'foo\',None) # Slave processors route\n                              # subsequent output on stdout to file\n                              # foo.out.<procid> and subsequent output\n                              # on sterr to original stderr\nsynchronizeQueuedOutput(\'std\',\'std\') # Slave processors route output\n                              # to temporary holding files of the form\n                              # std.out.<procid> and std.err.<procid>.\n                              # These files are deleted and reopened\n                              # on synchronization.\n"
extern DL_IMPORT(PyObject*) pyMPI_io_synchronizedWriteln(PyObject* pySelf, PyObject* args, PyObject* kw) ;
#define PYMPI_IO_SYNCHRONIZEDWRITELN_DOC "See synchronizedWrite().  This is identical, but adds a newline\n"
extern DL_IMPORT(PyObject*) pyMPI_io_synchronizedWrite(PyObject* pySelf, PyObject* args, PyObject* kw) ;
#define PYMPI_IO_SYNCHRONIZEDWRITE_DOC "Write strings to a file (stdout) in rank order\n\nsynchronizedWrite(...,file=sys.stdout) --> None\n\nFor arbitrary arguments, prepare a space separated representation of\nthe inputs and message to the master.  Messages are guaranteed to be\nprinted in rank order.  All processors must call.  The file argument\nmay be any file or file-like object such as an instance with a\n.write(s) member or pipe. Only the master rank actually uses the file\nargument.  The file argument is ignored elsewhere.\n\nBeware of the race condition inherent if you try to invoke something\nlike mpi.sychronizedWrite(file=open(\'foo\',\'w\')) -- all processes try\nto create \'foo\', but only one wins.  The winner may NOT be the root\nrank, so you unexpectedly get an empty file.\n\n>>> synchronizedWrite(\'Rank\',mpi.rank,\'is alive\\n\')\nRank 0 is alive\nRank 1 is alive\n\n>>> synchronizedWrite(\'Rank\',mpi.rank,\'is alive\\n\',file=sys.stderr)\n\n>>> if WORLD.rank == 0:\n...    debug = open(\'debug\',\'w\')\n... else:\n...    debug = None\n>>> synchronizedWrite(\'Rank\',mpi.rank,\'is alive\\n\',file=debug)\n\n"

/**************************************************************/
/*                      pyMPI_comm_map.c                      */
/**************************************************************/
extern DL_IMPORT(PyObject*) pyMPI_map_map(PyObject* pySelf, PyObject* args, PyObject* kw) ;
#define PYMPI_MAP_MAP_DOC "SIMD style parallel map. Other processors must be running mapserver\nThe idea all the user code is run on the root.  When a map is invoked\nthen the function and part of the argument list is sent to each slave\nwhich does its work which is regathered back to the master.\n\n>>> assert NotImplementedError,\"TODO: implement parallel map\"\n>>> mpi.mapserver()\n>>> answers = mpi.map(F,list)\n"
extern DL_IMPORT(PyObject*) pyMPI_map_mapserver(PyObject* pySelf, PyObject* args, PyObject* kw) ;
#define PYMPI_MAP_MAPSERVER_DOC "SIMD style parallel map server routine. Does not return on slave (non-\nzero) processors.  Any errors it gets are sent back to the master when\nmpi.map calls are made.\n\n>>> assert NotImplementedError,\"TODO: implement mapserver\"\n>>> mpi.mapserver()\n"
extern DL_IMPORT(PyObject*) pyMPI_map_mapstats(PyObject* pySelf, PyObject* args, PyObject* kw) ;
#define PYMPI_MAP_MAPSTATS_DOC "This is used to get load balance information.  Each slave sends back a\nrun-time/idle-time pair.   Assumes slaves are running mapserver()\n\n>>> assert NotImplementedError,\"TODO: implement mapstats\"\n>>> stats = mpi.mapstats()\n"

/**************************************************************/
/*                    pyMPI_comm_message.c                    */
/**************************************************************/
extern DL_IMPORT(PyObject*) pyMPI_message_send(PyObject* pySelf, PyObject* args, PyObject* kw) ;
#define PYMPI_MESSAGE_SEND_DOC "Send a message to another process on a communicator.\n\nsend(message,            # Serializable Python object\n     destination,        # Rank to send object to\n     tag=0)              # Integer message tag\n--> None\n\nThe message is serialized with the pickle module and sent to the\nspecified process.  This routine may block.\n\n>>> assert WORLD.size >= 2,\"running in parallel\"\n>>> if mpi.rank == 0:\n...    send(\"a message from zero\",1,33)\n... elif mpi.rank == 1:\n...    msg,status = recv()\n...    print \\'Got\\',msg,\\'from\\',status.source,\\'tag\\',status.tag\n\n"
extern DL_IMPORT(PyObject*) pyMPI_message_recv(PyObject* pySelf, PyObject* args, PyObject* kw) ;
#define PYMPI_MESSAGE_RECV_DOC "Receive a message.  Returns a list consisting of (data, status)\n\nrecv(source=ANY_SOURCE,         # expected rank of sender\n     tag=ANY_TAG)               # expected tag associated with message\n--> message,status\n\nGet a message from another process on communicator.  The result is in\ntwo parts: the message and the status object.  Use the status object\nto find out the actual sender and tag value.\n\n>>> assert WORLD.size >=2,\"running in parallel\"\n>>> if mpi.rank == 0:\n...    msg,status = recv(1,tag=0)\n... elif mpi.rank == 1:\n...    send(\"hello from rank 1\",0)\n\n>>> assert WORLD.size >=2,\"running in parallel\"\n>>> if mpi.rank == 0:\n...    msg,status = recv() # defaults to ANY_SOURCE, ANY_TAG\n...    print msg,\\'from\\',status.source,\\'tag\\',status.tag\n... elif mpi.rank == 1:\n...    send(\"hello from rank 1\",0)\n\n"
extern DL_IMPORT(PyObject*) pyMPI_message_sendrecv(PyObject* pySelf, PyObject* args, PyObject* kw) ;
#define PYMPI_MESSAGE_SENDRECV_DOC "Send message and receieve a value.\n\nsendrecv(message,            # Any serializable Python object\n         destination,        # Rank of destination process\n         source=ANY_SOURCE,  # Rank of sending process\n         sendtag=0,          # Message tag\n         recvtag=ANY_TAG)    # Expected tag from sender\n--> message, status\n\nExchange messages with another process.  Actual sender and tag\ninformation can be recovered from the status object returned with the\nmessage (status.source, status.tag)\n\nExample:  A big left shift (wrapped on the end)\n>>> left = (WORLD.size + WORLD.rank - 1)%WORLD.size\n>>> right = (WORLD.rank + 1)%WORLD.size\n>>> msg,status = sendrecv(\"Hello\",left,right)\n\n"

/**************************************************************/
/*                     pyMPI_comm_misc.c                      */
/**************************************************************/
extern DL_IMPORT(PyObject*) pyMPI_misc_create(PyObject* pySelf, PyObject* args, PyObject* kw) ;
#define PYMPI_MISC_CREATE_DOC "Create sub-communicators from a communicator\n\ncomm_create(group) --> communicator\n\nWe create new communicators from a list or range of ranks to include.\nThis is a bit different from MPI which uses a GROUP object.  When we\ncombine this functionality with the slice ability of communicators, it\nmakes more sense.\n\nUsing the default communicator...\n>>> even = mpi.comm_create( mpi.WORLD[0::2] )\n>>> assert mpi.size > 1,\"running in parallel\"\n>>> odd = mpi.comm_create( mpi.WORLD[1::2] )\n\nYou can use a list or range object as the argument too...\n>>> first = mpi.comm_create( range(0,mpi.size/2) )\n>>> last  = mpi.comm_create( range(mpi.size/2,mpi.size) )\n>>> assert mpi.size > 1,\"running in parallel\"\n>>> two = mpi.comm_create([0,1])\n\nCan be a communicator if you want a bad version of comm_dup...\nThis works because communicators are sequences [of their ranks]\n>>> clone = mpi.comm_create(WORLD)\n\nYou can use either a list or a single integer\n>>> comm2 = comm.comm_create([0])\n>>> comm3 = comm.comm_create(0)\n\n\nNote that the operation is synchronous requiring all processes on the\ncommunicator to call it.\n\n"
extern DL_IMPORT(PyObject*) pyMPI_misc_dup(PyObject* pySelf) ;
#define PYMPI_MISC_DUP_DOC "Create a communicator the same size as the original\n\ncomm_dup() --> communicator\nThis creates a new MPI communicator handle that is the same size as\nthe original one.\n\n>>> another_world = mpi.WORLD.comm_dup()\n\n>>> another_world = mpi.comm_dup()\n\n"
extern DL_IMPORT(PyObject*) pyMPI_misc_cart_create(PyObject* pySelf, PyObject* args, PyObject* kw) ;
#define PYMPI_MISC_CART_CREATE_DOC "Create a cartesian grid or torus\n\ncartesian_communicator(dims=[old_comm.size], # default to 1D\n                       periods=[1,...]       # default to torus\n                       reorder=1)            # can reorder ranks\n--> new cartesisan communicator\n\nThis creates a cartesian communicator that may yeild optimized\nmessaging for some architectures.  It also activates methods to\ncompute neighbor ranks on a grid.  See also the cartesian_communicator\ntype.\n\n>>> torus = mpi.WORLD.cart_create()\n\n"
extern DL_IMPORT(PyObject*) pyMPI_misc_rank(PyObject* pySelf) ;
#define PYMPI_MISC_RANK_DOC "Even though one would typically access a communicator\'s rank via its\nrank attribute, you can also use the comm_rank() member function. This\nis here mostly for textual compatibility with MPI programs.\n\n>>> mpi.WORLD.comm_rank() == mpi.WORLD.rank\n\n"
extern DL_IMPORT(PyObject*) pyMPI_misc_size(PyObject* pySelf) ;
#define PYMPI_MISC_SIZE_DOC "Even though one would typically access a communicator\'s size via its\nrank attribute, you can also use the comm_size() member function. This\nis here mostly for textual compatibility with MPI programs.\n\n>>> mpi.WORLD.comm_size() == mpi.WORLD.size\n"
extern DL_IMPORT(PyObject*) pyMPI_misc_free(PyObject* pySelf) ;
#define PYMPI_MISC_FREE_DOC "Explicitly release an MPI communicator.  Does not destroy the object\n\ncomm_free() --> None\n\nThis function will release the MPI communicator handle associated with\nthe Python skeleton.  Python can lose track of handles and delete one\nmore than once (if, for example, you created two Python handles with\nthe same MPI handle).\n\nUsers likely do not need to call this.  Python will free communicators\nthat it created when they are destroyed.  Communicators made from user\nhandles are not MPI_Comm_free()\'d by Python unless their `persistent\'\nattribute is set to false.  You can, of course, explicitly release it\nusing this method.\n\n>>> comm.comm_free()\n\n"
extern DL_IMPORT(PyObject*) pyMPI_misc_abort(PyObject* pySelf, PyObject* args, PyObject* kw) ;
#define PYMPI_MISC_ABORT_DOC "Emergency kill of MPI and Python\n\nabort(errorcode=1) --> None\n\nUse this to cleanly abort Python and MPI.  You can provide a status\n(default value is 1), but the MPI implementation may ignore it.\n\n>>> mpi.abort()\n\n>>> mpi.abort(77)\n\n"

/**************************************************************/
/*                   pyMPI_configuration.c                    */
/**************************************************************/
extern DL_IMPORT(void) pyMPI_configuration_fini(void) ;
extern DL_IMPORT(void) pyMPI_configuration_init(PyObject** docStringP) ;

/**************************************************************/
/*                     pyMPI_distutils.c                      */
/**************************************************************/
extern DL_IMPORT(void) pyMPI_distutils_init(PyObject** docStringP) ;
extern DL_IMPORT(void) pyMPI_distutils_fini(void) ;

/**************************************************************/
/*                        pyMPI_file.c                        */
/**************************************************************/

/**************************************************************/
/*                        pyMPI_init.c                        */
/**************************************************************/
extern PyObject* pyMPI_module;
extern PyObject* pyMPI_dictionary;
extern PyObject* pyMPI_MPIError;
extern int pyMPI_rank;
extern int pyMPI_size;
extern int pyMPI_packedIntSize;
extern int pyMPI_packedCharSize;
extern MPI_Comm pyMPI_COMM_WORLD;
extern DL_IMPORT(void) pyMPI_add_occasional_work(pyMPI_void_function F) ;
extern DL_IMPORT(void) pyMPI_add_intensive_work(pyMPI_void_function F) ;
extern DL_IMPORT(void) pyMPI_init(void) ;

/**************************************************************/
/*                     pyMPI_initialize.c                     */
/**************************************************************/
extern MPI_Comm pyMPI_world_communicator;
extern int pyMPI_color;
extern int pyMPI_owns_MPI;
extern DL_IMPORT(void) pyMPI_initialize(int Python_owns_MPI,MPI_Comm world_communicator,int color) ;

/**************************************************************/
/*                       pyMPI_isatty.c                       */
/**************************************************************/
/* extern DL_IMPORT(int) isatty(int filedes) __THROW ; */
/* extern DL_IMPORT(int) isatty(int filedes)  ; */

/**************************************************************/
/*                        pyMPI_main.c                        */
/**************************************************************/
extern DL_IMPORT(int) pyMPI_Main_with_communicator(int Python_owns_MPI, int *argc, char ***argv,MPI_Comm comm) ;
extern DL_IMPORT(int) pyMPI_Main(int Python_owns_MPI, int *argc, char ***argv) ;

/**************************************************************/
/*                       pyMPI_pickle.c                       */
/**************************************************************/
extern PyObject* pyMPI_pickle;
extern PyObject* pyMPI_pickle_loads;
extern PyObject* pyMPI_pickle_dumps;
extern DL_IMPORT(void) pyMPI_pickle_init(PyObject** docStringP) ;
extern DL_IMPORT(void) pyMPI_pickle_fini(void) ;

/**************************************************************/
/*                       pyMPI_pipes.c                        */
/**************************************************************/
extern DL_IMPORT(void) pyMPI_pipes_init(PyObject** docStringP) ;
extern DL_IMPORT(void) pyMPI_pipes_fini(void) ;

/**************************************************************/
/*                        pyMPI_rco.c                         */
/**************************************************************/
#define PYMPI_REMOTEPARTIAL_CTOR_DOC "First step in RPC, from here we gather the destinations\n"
#define PYMPI_REMOTE_INIT_DOC "RemoteObject(comm=mpi.WORLD,tag=99,receive=true)\n\nMix-in class for remote procedure invocation\n\n>>> class foop(mpi.RemoteObject):\n...    def __init__(self):\n...       mpi.RemoteObject.__init__(self)\n...    def method(self,x):\n...       print \'Got\',x,\'on rank\',mpi.rank\n>>> obj = foop()\n>>> if mpi.rank == 1: obj.__remote__[0].method(\'hello\')\n\nIf you want all messages to flow to only one rank, use\n>>> class goop(mpi.RemoteObject):\n...    def __init__(self):\n...      mpi.RemoteObject.__init__(self,receive=(mpi.rank == 0))\n>>> obj = goop()\n\n"
#define PYMPI_REMOTE_GET_REMOTE_DOC "Access RPC (remote procedure call) path to remote methods\n"
#define PYMPI_REMOTE_GET_REMOTE_ID_DOC "Unique remote identifier (for this comm)\n"
#define PYMPI_REMOTE_GET_REMOTE_COMM_DOC "Unique remote identifier (for this comm)\n"
#define PYMPI_REMOTE_GET_REMOTE_TAG_DOC "Tag used by isend() to post messages\n"
#define PYMPI_REMOTE_IRECV_DOC "obj.__remote__irecv__() --> request\n\nFor internal use in creating a request for pending messagesss\n"
extern DL_IMPORT(void) pyMPI_rco_init(PyObject** docstringP) ;
extern DL_IMPORT(void) pyMPI_rco_fini(void) ;

/**************************************************************/
/*                      pyMPI_readline.c                      */
/**************************************************************/
extern MPI_Comm pyMPI_COMM_INPUT;
extern DL_IMPORT(void) pyMPI_readline_init(PyObject** docStringP) ;
extern DL_IMPORT(void) pyMPI_readline_fini(void) ;

/**************************************************************/
/*                        pyMPI_recv.c                        */
/**************************************************************/
extern DL_IMPORT(PyObject*) pyMPI_recv(PyMPI_Comm* self, int source, int tag) ;

/**************************************************************/
/*                     pyMPI_reductions.c                     */
/**************************************************************/
extern DL_IMPORT(PyObject*) pyMPI_reductions_python(MPI_Op op) ;
extern DL_IMPORT(void) pyMPI_reductions_init(PyObject** docStringP) ;
extern DL_IMPORT(void) pyMPI_reductions_fini(void) ;

/**************************************************************/
/*                      pyMPI_request.c                       */
/**************************************************************/
#define PYMPI_REQUEST_INIT_DOC "Fill in the request object\n"
#define PYMPI_REQUEST_WAIT_DOC "wait()\n\nWait for a request to complete\n\n>>> req = mpi.isend(\'hello\',0)\n>>> req.wait()\n>>> print \'send completed\'\n\n"
#define PYMPI_REQUEST_CANCEL_DOC "Cancel a receive request.\n\ncancel()\n\nNote: From MPICH man page:\n\n\"Cancel has only been implemented for receive requests; it is a no-op\n for send requests.  The primary expected use of MPI_Cancel is in multi\n buffering schemes, where speculative MPI_Irecvs are made.  When the\n computation completes, some of these receive requests may remain;\n using MPI_Cancel allows the user to cancel these unsatisfied requests.\n\n>>> req = mpi.irecv(0)\n>>> req.cancel()\n\n"
#define PYMPI_REQUEST_GET_READY_DOC ".ready\n\nAttribute is true iff the message is ready.  Does not block\n\n>>> req = mpi.irecv()\n>>> if req.ready: print \'ready\'\n\n"
#define PYMPI_REQUEST_GET_MESSAGE_DOC ".message\n\nAttribute holding message (for recv).  Will block if not ready.\n\n>>> req = mpi.irecv()\n>>> if req.ready: print req.message\n\n"
#define PYMPI_REQUEST_GET_STATUS_DOC ".status\n\nReceive the status object related to message.  Will block if not ready\n\n>>> req = mpi.irecv()\n>>> if req.ready: print req.status\n\n"
#define PYMPI_REQUEST_GET_TEST_DOC ".test\n\nReturns a boolean indicating if a message is the action is complete\nThis test does not block.\n"
#define PYMPI_REQUEST_GET_TEST_CANCELLED_DOC ".canceled\n\nTrue if this message was cancelled.  Does not block.\n"
extern PyTypeObject pyMPI_request_type;
extern DL_IMPORT(PyMPI_Request*) pyMPI_request(MPI_Comm comm) ;
extern DL_IMPORT(void) pyMPI_request_init(PyObject** docStringP) ;
extern DL_IMPORT(void) pyMPI_request_fini(void) ;

/**************************************************************/
/*                        pyMPI_send.c                        */
/**************************************************************/
extern DL_IMPORT(PyObject*) pyMPI_send(PyMPI_Comm* self,PyObject* message,int destination,int tag) ;

/**************************************************************/
/*                    pyMPI_shared_file.c                     */
/**************************************************************/

/**************************************************************/
/*                      pyMPI_signals.c                       */
/**************************************************************/
extern DL_IMPORT(void) pyMPI_signals_init(PyObject** docStringP) ;
extern DL_IMPORT(void) pyMPI_signals_fini(void) ;

/**************************************************************/
/*                        pyMPI_site.c                        */
/**************************************************************/
extern DL_IMPORT(void) pyMPI_site(void) ;

/**************************************************************/
/*                       pyMPI_status.c                       */
/**************************************************************/
extern DL_IMPORT(PyObject*) pyMPI_status(MPI_Status status) ;

/**************************************************************/
/*                      pyMPI_sysmods.c                       */
/**************************************************************/
/* extern DL_IMPORT(const char*) Py_GetVersion(void) ; */
extern int pyMPI_exit_status;
extern DL_IMPORT(void) pyMPI_sysmods_init(PyObject** docstring_pointer) ;
extern DL_IMPORT(void) pyMPI_sysmods_fini(void) ;

/**************************************************************/
/*                    pyMPI_user_banner.c                     */
/**************************************************************/
extern DL_IMPORT(void) pyMPI_user_banner(char* buffer, int n) ;

/**************************************************************/
/*                   pyMPI_user_directory.c                   */
/**************************************************************/
extern DL_IMPORT(char*) pyMPI_user_directory(void) ;

/**************************************************************/
/*                     pyMPI_user_fini.c                      */
/**************************************************************/
extern DL_IMPORT(void) pyMPI_user_fini(void) ;

/**************************************************************/
/*                     pyMPI_user_init.c                      */
/**************************************************************/
extern DL_IMPORT(void) pyMPI_user_init(PyObject** docstring_pointer) ;

/**************************************************************/
/*                    pyMPI_user_startup.c                    */
/**************************************************************/
extern DL_IMPORT(void) pyMPI_user_startup(void) ;

/**************************************************************/
/*                        pyMPI_util.c                        */
/**************************************************************/
extern MPI_Datatype pyMPI_header_datatype;
extern MPI_Datatype pyMPI_message_datatype;
extern DL_IMPORT(int) pyMPI_util_ready(void) ;
extern DL_IMPORT(PyObject*) pyMPI_util_varargs(PyObject* args) ;
extern DL_IMPORT(PyObject*) pyMPI_util_tuple_to_spaced_string(PyObject* args) ;
extern DL_IMPORT(void) pyMPI_message_free(PyMPI_Message* part1, char** part2) ;
extern DL_IMPORT(PyObject*) pyMPI_unpack(PyMPI_Message* part1, char** part2) ;
extern DL_IMPORT(void) pyMPI_pack(PyObject* object,PyMPI_Comm* comm, PyMPI_Message* buffer1, char** buffer2) ;
extern DL_IMPORT(PyObject*) pyMPI_resultstatus(PyObject* result, MPI_Status status) ;
extern DL_IMPORT(PyObject*) pyMPI_util_integer_array(int n, int* array) ;
extern DL_IMPORT(int*) pyMPI_util_sequence_to_int_array(PyObject* sequence,char* message) ;
extern DL_IMPORT(void) pyMPI_util_init(PyObject** docStringP) ;
extern DL_IMPORT(void) pyMPI_util_fini(void) ;

#ifdef __cplusplus
  }
#endif

#endif
