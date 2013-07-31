##################################################
## CPack configuration
##################################################
if(EXISTS "${CMAKE_ROOT}/Modules/CPack.cmake")
    ##################################################
    ## Options
    ##################################################
    if(LINUX)
        set(OPTION_PACK_GENERATOR "ZIP;TGZ;DEB" CACHE STRING "Package targets")
    else()
        set(OPTION_PACK_GENERATOR "ZIP" CACHE STRING "Package targets")
    endif()

    ##################################################
    ## Initialize
    ##################################################
    # Reset CPack configuration
    if(EXISTS "${CMAKE_ROOT}/Modules/CPack.cmake")
        set(CPACK_IGNORE_FILES "")
        set(CPACK_INSTALLED_DIRECTORIES "")
        set(CPACK_SOURCE_IGNORE_FILES "")
        set(CPACK_SOURCE_INSTALLED_DIRECTORIES "")
        set(CPACK_STRIP_FILES "")
        set(CPACK_SOURCE_TOPLEVEL_TAG "")
        set(CPACK_SOURCE_PACKAGE_FILE_NAME "")
    endif()

    # Find cpack executable
    get_filename_component(CPACK_PATH ${CMAKE_COMMAND} PATH)
    set(CPACK_COMMAND "${CPACK_PATH}/cpack")

    ##################################################
    ## Package project
    ##################################################
    set(project_name "glow")   # Name of package project
    set(project_root "glow")   # Name of root project that is to be installed

    ##################################################
    ## Package information
    ##################################################
    string(TOLOWER ${META_PROJECT_NAME} package_name)                       # Package name
    set(package_description     "OpenGL Objects Wrapper Library")           # Package description
    set(package_vendor          "glow group")                               # Package vendor
    set(package_maintainer      "stefan.buschmann@hpi.uni-potsdam.de")      # Package maintainer

    ##################################################
    ## Package specific options
    ##################################################
    set(CMAKE_MODULE_PATH                   ${GLOW_SOURCE_DIR}/packages/${project_name})

    ##################################################
    ## Package information
    ##################################################
    set(CPACK_PACKAGE_NAME                  "${package_name}")
    set(CPACK_PACKAGE_VENDOR                "${package_vendor}")
    set(CPACK_PACKAGE_DESCRIPTION_SUMMARY   "${package_description}")
    set(CPACK_PACKAGE_VERSION               "${META_VERSION}")
    set(CPACK_PACKAGE_VERSION_MAJOR         "${META_VERSION_MAJOR}")
    set(CPACK_PACKAGE_VERSION_MINOR         "${META_VERSION_MINOR}")
    set(CPACK_PACKAGE_VERSION_PATCH         "${META_VERSION_PATCH}")
    set(CPACK_RESOURCE_FILE_LICENSE         "${GLOW_SOURCE_DIR}/LICENSE")
    set(CPACK_RESOURCE_FILE_README          "${GLOW_SOURCE_DIR}/README.md")
    set(CPACK_RESOURCE_FILE_WELCOME         "${GLOW_SOURCE_DIR}/README.md")
    set(CPACK_PACKAGE_DESCRIPTION_FILE      "${GLOW_SOURCE_DIR}/README.md")
    set(CPACK_PACKAGE_ICON                  "")
    set(CPACK_PACKAGE_RELOCATABLE           OFF)

    ##################################################
    ## Debian package information
    ##################################################
    set(CPACK_DEBIAN_PACKAGE_NAME           "${package_name}")
    set(CPACK_DEBIAN_PACKAGE_VERSION        "${CPACK_PACKAGE_VERSION}")
    set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE   "all")
#   set(CPACK_DEBIAN_PACKAGE_DEPENDS        "libc6 (>= 2.3.1-6), libgcc1 (>= 1:3.4.2-12)")
    set(CPACK_DEBIAN_PACKAGE_MAINTAINER     "${package_maintainer}")
    set(CPACK_DEBIAN_PACKAGE_DESCRIPTION    "${CPACK_PACKAGE_DESCRIPTION_SUMMARY}")
    set(CPACK_DEBIAN_PACKAGE_SECTION        "devel")
    set(CPACK_DEBIAN_PACKAGE_PRIORITY       "optional")
#   set(CPACK_DEBIAN_PACKAGE_RECOMMENDS     "")
#   set(CPACK_DEBIAN_PACKAGE_SUGGESTS       "")
    set(CPACK_DEBIAN_PACKAGE_CONTROL_EXTRA  "")

    ##################################################
    ## RPM package information
    ##################################################
    set(CPACK_RPM_PACKAGE_NAME                           "${package_name}")
    set(CPACK_RPM_PACKAGE_VERSION                        "${CPACK_PACKAGE_VERSION}")
    set(CPACK_RPM_PACKAGE_RELEASE                        1)
    set(CPACK_RPM_PACKAGE_ARCHITECTURE                   "x86_64")
    set(CPACK_RPM_PACKAGE_REQUIRES                       "")
    set(CPACK_RPM_PACKAGE_PROVIDES                       "")
    set(CPACK_RPM_PACKAGE_VENDOR                         "${package_vendor}")
    set(CPACK_RPM_PACKAGE_LICENSE                        "unknown")
    set(CPACK_RPM_PACKAGE_SUMMARY                        "${CPACK_PACKAGE_DESCRIPTION_SUMMARY}")
    set(CPACK_RPM_PACKAGE_DESCRIPTION                    "")
    set(CPACK_RPM_PACKAGE_GROUP                          "unknown")
#   set(CPACK_RPM_SPEC_INSTALL_POST                      "")
#   set(CPACK_RPM_SPEC_MORE_DEFINE                       "")
#   set(CPACK_RPM_USER_BINARY_SPECFILE                   "")
#   set(CPACK_RPM_GENERATE_USER_BINARY_SPECFILE_TEMPLATE "")
#   set(CPACK_RPM_<POST/PRE>_<UN>INSTALL_SCRIPT_FILE     "")
#   set(CPACK_RPM_PACKAGE_DEBUG                          1)
    set(CPACK_RPM_PACKAGE_RELOCATABLE                    OFF)

    ##################################################
    ## Package name
    ##################################################
    set(CPACK_PACKAGE_FILE_NAME "${package_name}-${CPACK_PACKAGE_VERSION}")

    ##################################################
    ## Install files
    ##################################################
    set(CPACK_INSTALL_CMAKE_PROJECTS        "${CMAKE_BINARY_DIR};glow;ALL;/")
    set(CPACK_PACKAGE_INSTALL_DIRECTORY     "${package_name}")
    set(CPACK_PACKAGE_INSTALL_REGISTRY_KEY  "${package_name}")
    if(LINUX)
        set(CPACK_INSTALL_PREFIX            "/usr/")
    endif()

    ##################################################
    ## Set generator
    ##################################################
    set(CPACK_OUTPUT_CONFIG_FILE "${CMAKE_BINARY_DIR}/CPackConfig-${project_name}.cmake")
    set(CPACK_GENERATOR     "ZIP;TGZ;DEB")
    set(CPACK_GENERATOR ${OPTION_PACK_GENERATOR})

    ##################################################
    ## CPack
    ##################################################
    if(NOT WIN32)
        set(CPACK_SET_DESTDIR ON)   # Important: Must be set to install files to absolute path (e.g., /etc) -> CPACK_[RPM_]PACKAGE_RELOCATABLE = OFF
    endif()
    set(CPack_CMake_INCLUDED FALSE)
    include(CPack)
endif()

##################################################
## Package target
##################################################
add_custom_target(
    pack-${project_name}
    COMMAND ${CPACK_COMMAND} --config ${CMAKE_BINARY_DIR}/CPackConfig-${project_name}.cmake
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
set_target_properties(pack-${project_name} PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD 1)

##################################################
## Dependencies
##################################################
add_dependencies(pack-${project_name}   ${project_root})
add_dependencies(pack                   pack-${project_name})
