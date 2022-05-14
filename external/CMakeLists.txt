# set and add SDL2 Module
set(SDL_DIR ${EXTERNAL_DIR}/SDL)
add_subdirectory(${SDL_DIR})
# # set and add SDL_Image Module
# set(SDL_IMAGE_DIR ${EXTERNAL_DIR}/SDL_image)
# add_subdirectory(${SDL_IMAGE_DIR})
#
#--------------------------------------------------------------------
add_library(SDL_GENERAL INTERFACE)
target_include_directories(
    SDL_GENERAL INTERFACE 
    ${SDL2_INCLUDE_DIRS}
    ${SDL_DIR}/include
    # ${SDL_IMAGE_DIR}   
)               
target_link_directories(
    SDL_GENERAL INTERFACE
    ${SDL_DIR}
    # ${SDL_IMAGE_DIR}
)
target_link_libraries(
    SDL_GENERAL INTERFACE #linker
    SDL2main
    SDL2 
    SDL2-static
    # SDL2_image
)