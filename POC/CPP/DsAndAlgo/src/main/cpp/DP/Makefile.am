# We don't want to follow GNU file setup (no README, no AUTHORS, etc)
AUTOMAKE_OPTIONS = foreign
# We have two dirs with code and (Makefile.am's) in them
#SUBDIRS = DsAndAlgo

AM_CXXFLAGS = -I$(top_srcdir)/DsAndAlgo/src/main/headers/ -std=gnu++11 @AM_CXXFLAGS@

bin_PROGRAMS = main
main_SOURCES = ../main.cpp



bin_PROGRAMS = MaxSubSequenceSumNonAdjacent
MaxSubSequenceSumNonAdjacent_SOURCES = MaxSubSequenceNonAdjacentTest.cpp \
                                       ../main.cpp


