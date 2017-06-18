# Thanks to https://github.com/arnaudgelas/ExternalProject

set(Boost_Bootstrap_Command)
if(UNIX)
  set(Boost_Bootstrap_Command ./bootstrap.sh)
  set(Boost_b2_Command ./b2)
else()
  if(WIN32)
    set(Boost_Bootstrap_Command bootstrap.bat)
    set(Boost_b2_Command b2.exe)
  endif()
endif()

ExternalProject_Add(boost
  PREFIX boost_external
  URL ${PROJECT_SOURCE_DIR}/boost_1_64_0.tar.gz
  UPDATE_COMMAND ""
  PATCH_COMMAND ""
  BUILD_IN_SOURCE 1
  CONFIGURE_COMMAND ${Boost_Bootstrap_Command}
  BUILD_COMMAND ${Boost_b2_Command} install
    --disable-icu
    --prefix=<INSTALL_DIR>
    --threading=single,multi
    --link=shared
    --variant=release
  INSTALL_COMMAND ""
)

ExternalProject_Get_Property(boost INSTALL_DIR)

if(NOT WIN32)
  set(Boost_LIBRARY_DIR ${INSTALL_DIR}/lib/boost/)
  set(Boost_INCLUDE_DIR ${INSTALL_DIR}/include/)
else()
  set(Boost_LIBRARY_DIR ${INSTALL_DIR}/lib/)
  set(Boost_INCLUDE_DIR ${INSTALL_DIR}/include/boost-1_64/)
endif()
