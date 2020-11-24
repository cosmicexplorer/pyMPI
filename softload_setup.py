#-*-python-*-**************************************************************#
#* FILE   **************        setup.py.in        ************************#
#**************************************************************************#
#* Author: Patrick Miller February 25 2004                                *#
#* Copyright (C) Patrick J. Miller                                        *#
#**************************************************************************#

import os
import distutils.unixccompiler
from distutils.core import setup, Extension

# These come from the ./configure phase
pyCC="gcc -pthread"
CC="/proj/desres/root/Linux/x86_64/openmpi/1.3a1r17814-16/mbin/mpicc"
CFLAGS="-g -O2"


##################################################################
#                    CLASS MPI_UNIXCCOMPILER                     #
##################################################################
class MPI_UnixCCompiler(distutils.unixccompiler.UnixCCompiler):
    """MPI_UnixCCompiler

    We override the UnixCCompiler class so that we can replace
    the original Python CC with the MPI CC (and hope for the best)
    """

    def __fix(self, old):
        if type(old) != str: return old
        values = old.split(' ')
        updated = []
        for x in values:
            if x == pyCC: x = CC
            updated.append(x)
        return ' '.join(updated)

    __set_executable = distutils.unixccompiler.UnixCCompiler.set_executable
    def set_executable(self,key,value):
        "We replace every cc reference with the MPI cc"
        if type(value) == type([]):
            value = [self.__fix(x) for x in value]
        else:
            value = self.__fix(value)
        return self.__set_executable(key,value)
    
distutils.unixccompiler.UnixCCompiler = MPI_UnixCCompiler

os.system('make')

setup(ext_modules=[
    Extension('mpi',
              ['pyMPI_softload.c'],
              library_dirs=[os.getcwd()],
              libraries=['pyMPI'],
              ),
    ],
      )

