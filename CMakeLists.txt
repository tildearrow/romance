cmake_minimum_required(VERSION 3.0)
project(romance)

set(TA_AUDIO_SOURCES
  src/audio/abstract.cpp
  src/audio/jack.cpp)

set(TA_AUDIO_LIBS jack)

add_executable(romance ${TA_AUDIO_SOURCES} src/main.cpp)
target_link_libraries(romance ${TA_AUDIO_LIBS})
