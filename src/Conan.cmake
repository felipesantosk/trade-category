include_guard(GLOBAL)

cmake_minimum_required(VERSION 3.10)

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
  message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
  file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.16.1/conan.cmake"
                "${CMAKE_BINARY_DIR}/conan.cmake"
                EXPECTED_HASH SHA256=396e16d0f5eabdc6a14afddbcfff62a54a7ee75c6da23f32f7a31bc85db23484
                TLS_VERIFY ON)
endif()


include(${CMAKE_BINARY_DIR}/conan.cmake)

set(IGNORE_BOOST_LIBS atomic chrono container context contract coroutine 
   exception fiber filesystem graph graph_parallel iostreams json locale log 
   math mpi nowide program_options python random regex serialization 
   stacktrace system test thread timer type_erasure wave)
      
set(BOOST_LIBS date_time)

list(TRANSFORM IGNORE_BOOST_LIBS PREPEND "boost:without_")
list(TRANSFORM IGNORE_BOOST_LIBS APPEND "=True")

list(TRANSFORM BOOST_LIBS PREPEND "boost:without_")
list(TRANSFORM BOOST_LIBS APPEND "=False")

conan_cmake_run(REQUIRES boost/1.77.0
                BASIC_SETUP CMAKE_TARGETS
                BUILD missing
                OPTIONS boost:shared=True
                        boost:zlib=False
                        boost:bzip2=False
                        ${BOOST_LIBS}
                        ${IGNORE_BOOST_LIBS})
