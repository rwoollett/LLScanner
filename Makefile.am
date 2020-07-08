ACLOCAL_AMFLAGS = -I m4

AM_CPPFLAGS = -I$(srcdir)

lib_LTLIBRARIES = libdatemodule.la
libdatemodule_la_SOURCES = DataParse/DateItem.cpp \
                           DataParse/DateItem.h \
                           DataParse/ParseDate.cpp \
                           DataParse/ParseDate.h \
                           DataParse/MonthNames.cpp \
                           DataParse/MonthNames.h \
                           Scanner/scanner.cpp \
                           Scanner/scanner.h

libdatemodule_la_LDFLAGS = -version-info 1:0:1
                    
bin_PROGRAMS = testprog
testprog_SOURCES = cpputest/main.cpp \
                   cpputest/ScannerTest.cpp \
                   cpputest/ParseDateTest.cpp \
                   cpputest/DateItemTest.cpp \
                   Generate/filegenerate.cpp \
                   Generate/filegenerate.h \
                   Utilities/Utilities.cpp \
                   Utilities/Utilities.h

testprog_LDFLAGS = $(CPPUTEST_LIBS)
testprog_LDADD =  libdatemodule.la $(EXPAT_LIBS)

TESTS = testprog

