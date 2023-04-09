# Initialize AC: ACINIT( package_name, version, bug_report_address)
AC_INIT([DsAndAlgo], [0.1])
# Initialize Automake
AM_INIT_AUTOMAKE
# AM stands for Automake commands, AC stands for Autoconf commands
# We use libraries
AC_PROG_RANLIB
# Let's check for a C++ compiler
AC_LANG(C++)
# Let's set a C++ compiler
AC_PROG_CXX
AC_PROG_CC

#AX_CXX_COMPILE_STDCXX_11([noext],[optional])

# FLag std=c++14
CXXFLAGS="-Werror -std=c++14"
AC_MSG_CHECKING([whether CXX supports -std=c++14])
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([])], [AC_MSG_RESULT([yes]); CPPUTEST_CPP14FLAG="-std=c++14" ], [AC_MSG_RESULT([no])])
CXXFLAGS="$saved_cxxflags"

# Flag -Wno-c++14-compat
CXXFLAGS="-Werror -Wno-c++14-compat"
AC_MSG_CHECKING([whether CXX supports -Wno-c++14-compat])
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([])], [AC_MSG_RESULT([yes]); CPPUTEST_CXXWARNINGFLAGS="${CPPUTEST_CXXWARNINGFLAGS} -Wno-c++11-compat" ], [AC_MSG_RESULT([no])])
CXXFLAGS="$saved_cxxflags"


# This suppresses the error we get for also having the cc version of helper library.
AC_SUBST([CC])
AC_SUBST([AM_CXXFLAGS])



# Let's specify where the Makefiles should be produced.
# These are the same locations as your Makefile.in's, but named as Makefile only
# We need to do this because both Autoconf and Automake read this file and
# produce Makefiles from this list.
#AC_CONFIG_FILES([Makefile src/Makefile src/DP/Makefile])
AC_CONFIG_FILES([
                Makefile 
                src/Makefile
                src/DP/Makefile
                src/Tree/Makefile
                ])
# Finally produce "configure" script
AC_OUTPUT


# Configuring Clang 
#export CC=clang
#export CXX=clang++