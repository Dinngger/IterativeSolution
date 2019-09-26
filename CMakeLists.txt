project(IterativeSolution)

cmake_minimum_required(VERSION 3.10)

aux_source_directory(. DIR_SRCS)

add_executable(IterativeSolutionTest ${DIR_SRCS})
