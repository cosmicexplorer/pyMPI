
/**************************************************************************/
/* FILE ****************  pyMPI_configuration.c ***************************/
/**************************************************************************/
/* Author: Machine generated                                              */
/**************************************************************************/

#include "mpi.h"
#undef _POSIX_C_SOURCE
#include "Python.h"
#include "pyMPI.h"
#include "pyMPI_Macros.h"

START_CPLUSPLUS

/**************************************************************************/
/* GLOBAL **************  pyMPI_configuration_fini ************************/
/**************************************************************************/
/* No global state to clean up here.  Just used to fulfill the contract   */
/* with the PLUGIN macro.                                                 */
/**************************************************************************/
void pyMPI_configuration_fini(void) {
}

/**************************************************************************/
/* LOCAL  **************     increment_refcount    ************************/
/**************************************************************************/
/* This simply is used to adapt to the model of the PARAMETER macro which */
/* expects its "converter" argument to return an owned reference to the   */
/* first argument.  When that argument is a borrowed reference (as here   */
/* where the Py_None singleton is passed in as the parameter), we need to */
/* INCREF it.                                                             */
/**************************************************************************/
static PyObject* increment_refcount(PyObject* x) {
  Py_XINCREF(x);
  return x;
}

/**************************************************************************/
/* GLOBAL **************  pyMPI_configuration_init ************************/
/**************************************************************************/
/* This builds a submodule (mpi.configuration) which is populated with    */
/* the values set in pyMPI_Config.h.  This includes useful information    */
/* like the flags and compilers used to build pyMPI.  This is more direct */
/* and more complete than what we can patch into distutils.               */
/**************************************************************************/
void pyMPI_configuration_init(PyObject** docStringP) {
   PyObject* configuration = 0;
   PyObject* configuration_dictionary = 0;
   PyObject* doc_string = 0;
   static PyMethodDef configuration_methods[] = {{0,0}};

   PYCHECK( configuration /*owned*/ = Py_InitModule("mpi.configuration",
                                                     configuration_methods) );
   PYCHECK( configuration_dictionary /*borrowed*/ = PyModule_GetDict(configuration) );
   PYCHECK( doc_string /*owned*/ = PyString_FromString("pyMPI configuration information\n\nConfiguration information\n\n") );

   PARAMETER(HAVE_INTTYPES_H,"HAVE_INTTYPES_H","Define to 1 if you have the <inttypes.h> header file.",PyInt_FromLong,configuration_dictionary,&doc_string);
   PARAMETER(HAVE_LIBM,"HAVE_LIBM","Define to 1 if you have the `m\' library (-lm).",PyInt_FromLong,configuration_dictionary,&doc_string);
   PARAMETER(HAVE_MEMORY_H,"HAVE_MEMORY_H","Define to 1 if you have the <memory.h> header file.",PyInt_FromLong,configuration_dictionary,&doc_string);
   PARAMETER(Py_None,"HAVE_MPI_FILE_OPERATIONS","Is MPI_File_close defined by the MPI implementation?",increment_refcount,configuration_dictionary,&doc_string);
   PARAMETER(Py_None,"HAVE_MPI_FINALIZED","Is MPI_Finalized defined by the MPI implementation?",increment_refcount,configuration_dictionary,&doc_string);
   PARAMETER(Py_None,"HAVE_MPI_INITIALIZED","Is MPI_Initialized defined by the MPI implementation?",increment_refcount,configuration_dictionary,&doc_string);
   PARAMETER(HAVE_PYOS_STDIOREADLINE,"HAVE_PYOS_STDIOREADLINE","Define to 1 if you have the `PyOS_StdioReadline\' function.",PyInt_FromLong,configuration_dictionary,&doc_string);
   PARAMETER(Py_None,"HAVE_PY_SSIZE_T","Does Python use int or Py_ssize_t",increment_refcount,configuration_dictionary,&doc_string);
   PARAMETER(HAVE_SETLINEBUF,"HAVE_SETLINEBUF","Define to 1 if you have the `setlinebuf\' function.",PyInt_FromLong,configuration_dictionary,&doc_string);
   PARAMETER(HAVE_STDINT_H,"HAVE_STDINT_H","Define to 1 if you have the <stdint.h> header file.",PyInt_FromLong,configuration_dictionary,&doc_string);
   PARAMETER(HAVE_STDLIB_H,"HAVE_STDLIB_H","Define to 1 if you have the <stdlib.h> header file.",PyInt_FromLong,configuration_dictionary,&doc_string);
   PARAMETER(HAVE_STRINGS_H,"HAVE_STRINGS_H","Define to 1 if you have the <strings.h> header file.",PyInt_FromLong,configuration_dictionary,&doc_string);
   PARAMETER(HAVE_STRING_H,"HAVE_STRING_H","Define to 1 if you have the <string.h> header file.",PyInt_FromLong,configuration_dictionary,&doc_string);
   PARAMETER(HAVE_SYS_PARAM_H,"HAVE_SYS_PARAM_H","Define to 1 if you have the <sys/param.h> header file.",PyInt_FromLong,configuration_dictionary,&doc_string);
   PARAMETER(HAVE_SYS_STAT_H,"HAVE_SYS_STAT_H","Define to 1 if you have the <sys/stat.h> header file.",PyInt_FromLong,configuration_dictionary,&doc_string);
   PARAMETER(HAVE_SYS_TYPES_H,"HAVE_SYS_TYPES_H","Define to 1 if you have the <sys/types.h> header file.",PyInt_FromLong,configuration_dictionary,&doc_string);
   PARAMETER(HAVE_UNISTD_H,"HAVE_UNISTD_H","Define to 1 if you have the <unistd.h> header file.",PyInt_FromLong,configuration_dictionary,&doc_string);
   PARAMETER(PACKAGE,"PACKAGE","Name of package",PyString_FromString,configuration_dictionary,&doc_string);
   PARAMETER(PACKAGE_BUGREPORT,"PACKAGE_BUGREPORT","Define to the address where bug reports for this package should be sent.",PyString_FromString,configuration_dictionary,&doc_string);
   PARAMETER(PACKAGE_NAME,"PACKAGE_NAME","Define to the full name of this package.",PyString_FromString,configuration_dictionary,&doc_string);
   PARAMETER(PACKAGE_STRING,"PACKAGE_STRING","Define to the full name and version of this package.",PyString_FromString,configuration_dictionary,&doc_string);
   PARAMETER(PACKAGE_TARNAME,"PACKAGE_TARNAME","Define to the one symbol short name of this package.",PyString_FromString,configuration_dictionary,&doc_string);
   PARAMETER(PACKAGE_VERSION,"PACKAGE_VERSION","Define to the version of this package.",PyString_FromString,configuration_dictionary,&doc_string);
   PARAMETER(PYMPI_BADCANCEL,"PYMPI_BADCANCEL","Do not allow MPI_Cancel() on isend requests",PyInt_FromLong,configuration_dictionary,&doc_string);
   PARAMETER(PYMPI_COMPILER,"PYMPI_COMPILER","Name of MPI enabled C compiler",PyString_FromString,configuration_dictionary,&doc_string);
   PARAMETER(PYMPI_COMPILER_FLAGS,"PYMPI_COMPILER_FLAGS","Modified compiler flags",PyString_FromString,configuration_dictionary,&doc_string);
   PARAMETER(PYMPI_GET_MAKEFILE_FILENAME_DEF,"PYMPI_GET_MAKEFILE_FILENAME_DEF","Replacement function for get_makefile_filename",PyString_FromString,configuration_dictionary,&doc_string);
   PARAMETER(Py_None,"PYMPI_HAS_NUMPY","Does this Python include Numpy?",increment_refcount,configuration_dictionary,&doc_string);
   PARAMETER(Py_None,"PYMPI_HAVE_SYSCONF_NPROCESSORS","Can we get local NPROCESSORS?",increment_refcount,configuration_dictionary,&doc_string);
   PARAMETER(PYMPI_INCLUDEDIR,"PYMPI_INCLUDEDIR","Installation prefix",PyString_FromString,configuration_dictionary,&doc_string);
   PARAMETER(PYMPI_ISATTY,"PYMPI_ISATTY","Use simplified isatty()",PyInt_FromLong,configuration_dictionary,&doc_string);
   PARAMETER(PYMPI_LIBDIR,"PYMPI_LIBDIR","Library location",PyString_FromString,configuration_dictionary,&doc_string);
   PARAMETER(PYMPI_LINKER,"PYMPI_LINKER","Name of the MPI enabled C compiler for linking",PyString_FromString,configuration_dictionary,&doc_string);
   PARAMETER(PYMPI_LINKER_FLAGS,"PYMPI_LINKER_FLAGS","Extra link flags needed to build",PyString_FromString,configuration_dictionary,&doc_string);
   PARAMETER(PYMPI_MAJOR,"PYMPI_MAJOR","Major release",PyString_FromString,configuration_dictionary,&doc_string);
   PARAMETER(PYMPI_MINOR,"PYMPI_MINOR","Minor release",PyString_FromString,configuration_dictionary,&doc_string);
   PARAMETER(PYMPI_PREFIX,"PYMPI_PREFIX","Installation prefix",PyString_FromString,configuration_dictionary,&doc_string);
   PARAMETER(PYMPI_PROMPT_NL,"PYMPI_PROMPT_NL","Issue a newline after prompt",PyInt_FromLong,configuration_dictionary,&doc_string);
   PARAMETER(PYMPI_PYTHON_CONFIGDIR,"PYMPI_PYTHON_CONFIGDIR","Directory where python library files live",PyString_FromString,configuration_dictionary,&doc_string);
   PARAMETER(PYMPI_PYTHON_LIBRARY,"PYMPI_PYTHON_LIBRARY","the \"-l\" name of python library",PyString_FromString,configuration_dictionary,&doc_string);
   PARAMETER(PYMPI_RELEASE,"PYMPI_RELEASE","Sub versioning a=alpha, b=beta, .x=release",PyString_FromString,configuration_dictionary,&doc_string);
   PARAMETER(PYMPI_SITEDIR,"PYMPI_SITEDIR","Installation directory",PyString_FromString,configuration_dictionary,&doc_string);
   PARAMETER(PYMPI_VERSION_NAME,"PYMPI_VERSION_NAME","PACKAGE Short version",PyString_FromString,configuration_dictionary,&doc_string);
   PARAMETER(PYMPI_VERSION_SHORT,"PYMPI_VERSION_SHORT","Short version",PyString_FromString,configuration_dictionary,&doc_string);
   PARAMETER(STDC_HEADERS,"STDC_HEADERS","Define to 1 if you have the ANSI C header files.",PyInt_FromLong,configuration_dictionary,&doc_string);
   PARAMETER(VERSION,"VERSION","Version number of package",PyString_FromString,configuration_dictionary,&doc_string);

   PYCHECK( PyDict_SetItemString(configuration_dictionary,"__doc__",doc_string) );
   PYCHECK( PyDict_SetItemString(pyMPI_dictionary,"configuration",configuration) );
   return;

 pythonError:
   Py_XDECREF(configuration);
   Py_XDECREF(doc_string);
   return;
}

END_CPLUSPLUS
