file(GLOB LIB_SRC *.cpp)

add_library(template_lib
    STATIC
    ${LIB_SRC})