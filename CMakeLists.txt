cmake_minimum_required(VERSION 3.16)
project(EonEngine)

# Configurer le standard C++ 17
set(CMAKE_CXX_STANDARD 17)

# Spécifie le chemin pour les fichiers d'entête
include_directories(${CMAKE_SOURCE_DIR}/src)

# Trouver tous les fichiers source (.cpp) et d'en-tête (.h) dans src et sous-dossiers
file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)

# Ajouter tous les fichiers trouvés à l'exécutable
add_executable(EonEngine ${SOURCES})
if(CMAKE_BUILD_TYPE STREQUAL "Release")
set_target_properties(EonEngine PROPERTIES
    WIN32_EXECUTABLE TRUE
)
endif()