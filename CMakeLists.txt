# Required for Preset Schema v3: https://cmake.org/cmake/help/latest/manual/cmake-presets.7.html#schema
cmake_minimum_required (VERSION 3.21.0 FATAL_ERROR)

project(postgis
	VERSION 3.4.2
	DESCRIPTION "PostGIS Extensions for PostgreSQL"
	HOMEPAGE_URL "https://postgis.net/"	
	LANGUAGES C)

add_subdirectory(geos)

#set(CGAL_DIR ${PROJECT_SOURCE_DIR}/cgal)
#add_subdirectory(sfcgal)

file(GLOB LWGEOM_SRC ${PROJECT_SOURCE_DIR}/liblwgeom/*.c)
add_library(lwgeom SHARED ${LWGEOM_SRC})
target_include_directories(lwgeom PRIVATE
	${PROJECT_SOURCE_DIR}/liblwgeom
	${PROJECT_SOURCE_DIR}/proj/src
	${PROJECT_BINARY_DIR}/geos/capi
	${PROJECT_SOURCE_DIR}/geos/include
	${PROJECT_SOURCE_DIR} # Hack - had to copy sfcgal/capi folder from sfcgal project
)

file(GLOB POSTGIS-3_SRC ${PROJECT_SOURCE_DIR}/postgis/*.c)
add_library(postgis-3 SHARED ${POSTGIS-3_SRC})
set_property(TARGET postgis-3 PROPERTY C_STANDARD 17)

set(PGDIR "C:/Program Files/PostgreSQL/16")
target_include_directories(postgis-3 PRIVATE 
	${PROJECT_SOURCE_DIR}/postgis
	${PROJECT_SOURCE_DIR}/liblwgeom
	${PROJECT_SOURCE_DIR}/libpgcommon
	${PROJECT_SOURCE_DIR}/deps/flatgeobuf
	${PGDIR}/include
	${PGDIR}/include/server
	${PGDIR}/include/server/port/win32
	${PGDIR}/include/server/port/win32_msvc
	# Submodules
	${PROJECT_SOURCE_DIR}/proj/src
	# Geos generated header file
	${PROJECT_BINARY_DIR}/geos/capi
	${PROJECT_SOURCE_DIR}/geos/include
)

execute_process(COMMAND git describe --always WORKING_DIRECTORY ${CMAKE_SOURCE_DIR} OUTPUT_VARIABLE POSTGIS_REVISION)
configure_file(${PROJECT_SOURCE_DIR}/postgis_revision.h.in ${PROJECT_SOURCE_DIR}/postgis_revision.h)

# kinda just hardcoding all this now as a hack
set(POSTGIS_VERSION "\"${postgis_VERSION}\"")
set(POSTGIS_GEOS_VERSION 31200)
set(POSTGIS_PROJ_VERSION 60300)
set(POSTGIS_PGSQL_VERSION 160)
set(POSTGIS_LIBXML2_VERSION "\"2.11.5\"")
configure_file(${PROJECT_SOURCE_DIR}/postgis_config.h.in ${PROJECT_SOURCE_DIR}/postgis_config.h)

target_link_directories(postgis-3 PRIVATE ${PGDIR}/lib)
target_link_libraries(postgis-3 postgres geos_c)

# everything below this point is todo

#add_library(postgis_standardizer-3 SHARED)
#add_library(postgis_raster-3 SHARED)
#add_library(postgis_sfcgal-3 SHARED)
#add_library(postgis_topology-3 SHARED)
#add_executable(pgsql2shp)
#add_executable(raster2pgsql)
#add_executable(shp2pgsql)*/
