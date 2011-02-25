subdirs( ivy_mike pwosali pars_cluster parser_test test)
include_directories( ivy_mike/src )
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall")

add_subdirectory(fpga_com)
add_subdirectory(pv_compress)
# add_subdirectory(mpi_test)
add_subdirectory(ml_utils)
