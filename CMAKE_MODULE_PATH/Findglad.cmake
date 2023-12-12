# Znajdź źródło i nagłówek bibliteki glad, możesz zmienić ścieżki
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}")
find_path(GLAD_INCLUDE_DIR
        NAMES "glad/glad.h"
        PATHS "/home/mic/CLionProjects/CircleRender/glad/include/glad/glad.h")
find_library(GLAD_LIBRARY
        NAMES glad
        PATHS "/home/mic/CLionProjects/CircleRender/glad/src/glad.c")
# Ustal, czy znaleziono glad
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(glad DEFAULT_MSG GLAD_LIBRARY GLAD_INCLUDE_DIR)
if (GLAD_FOUND)
    set(GLAD_INCLUDE_DIRS ${GLAD_INCLUDE_DIR})
    set(GLAD_LIBRARIES ${GLAD_LIBRARY})
endif()

mark_as_advanced(GLAD_INCLUDE_DIR GLAD_LIBRARY)