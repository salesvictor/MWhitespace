cmake_minimum_required( VERSION 3.10 )
project( MWhitespace )

# Compiler Commands
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

# Versioning
set( MWHITESPACES_VERSION_MAJOR 0 )
set( MWHITESPACES_VERSION_MINOR 0 )
set( MWHITESPACES_VERSION_PATCH 0 )
set( MWHITESPACES_VERSION "${MWHITESPACES_VERSION_MAJOR}.${MWHITESPACES_VERSION_MINOR}.${MWHITESPACES_VERSION_PATCH}")

# Adding subdirectories
add_subdirectory( src bin )
add_subdirectory( tests tests )
