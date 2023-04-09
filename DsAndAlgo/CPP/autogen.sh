rm -rf install-sh
rm -rf missing
rm -rf config.status
rm -rf config.log
rm -rf aclocal.m4
rm Makefile.in
rm configure
rm -rf autoMake


aclocal
autoconf
automake --add-missing 

#rm -rf bld
mkdir -p bld
