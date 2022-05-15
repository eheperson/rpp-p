option(USE_MODULE_1 "Build module 1" ON)
#
if(USE_MODULE_1)
    # To make use  of the new library we will add an add_subdirectory() call
    # add_subdirectory(${MODULE_1})
    message(STATUS "Module 1 Found")
    add_definitions(-DUSE_MODULE_1)

    set(MODULE_1 TestLib)
    set(EXECUTABLE_FILE_1 TestLib/greetings.cxx)

    add_library(${MODULE_1} ${EXECUTABLE_FILE_1})

    list(APPEND EXTRA_LIB_DIRS "TestLib")
    list(APPEND EXTRA_INCLUDE_DIRS "TestLib") # or : "${PROJECT_SOURCE_DIR}/Adder"
    list(APPEND EXTRA_LINKS MODULE_1)

    install(TARGETS ${MODULE_1} DESTINATION lib)
    install(FILES ${MODULES_DIR}/${MODULE_1}/${MODULE_1}.h DESTINATION include)
    
endif()