project(bamboo)

cmake_minimum_required(VERSION 2.6)

set(CMAKE_INSTALL_PREFIX "/opt/bamboo")

if (NOT DEFINED LIB_INSTALL_DIR)
	set(LIB_INSTALL_DIR "/usr/lib")
endif(NOT DEFINED LIB_INSTALL_DIR)

if (NOT DEFINED INC_INSTALL_DIR)
	set(INC_INSTALL_DIR "/usr/include/bamboo")
endif(NOT DEFINED INC_INSTALL_DIR)

set(BIN_INSTALL_DIR "bin")
set(ETC_INSTALL_DIR "etc")
set(PROCESSOR_INSTALL_DIR "processor")
set(TRAINING_INSTALL_DIR "template")
set(EXT_INSTALL_DIR "exts")

set(CMAKE_CXX_FLAGS "-fPIC -Wall -D_GNU_SOURCE")
set(CMAKE_CXX_FLAGS_DEBUG "-g ")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-g -O2 -DNDEBUG")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules/")

foreach(subdir cmake source etc template exts)

	if ( EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${subdir} )
		add_subdirectory( ${subdir} )
	endif ( EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${subdir} )

endforeach(subdir)
