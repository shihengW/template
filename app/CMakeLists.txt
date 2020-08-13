file(GLOB APP_SRC ./*.cpp)

foreach (src ${APP_SRC})
    get_filename_component(executable ${src} NAME_WLE)
    add_executable(${executable} ${src})
    target_link_libraries(${executable} template_lib)
endforeach (src)