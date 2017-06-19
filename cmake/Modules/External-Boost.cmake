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
  URL_HASH SHA512=bdbb6d586fdff8a1ae1f078279e26b1e9194b4856f88f028bb7e9d0a3c91d523195691095ebfdef8499f972ca85ba7dec102fb7ca6acdf4d15b891b3092e0ab1 
  UPDATE_COMMAND ""
  PATCH_COMMAND ""
  BUILD_IN_SOURCE 1
  CONFIGURE_COMMAND ${Boost_Bootstrap_Command}
    --with-libraries=program_options
    --prefix=<INSTALL_DIR>
    --without-icu
  BUILD_COMMAND ${Boost_b2_Command} install
    --threading=single,multi
    --link=shared
    --variant=release
  INSTALL_COMMAND ""
)

ExternalProject_Get_Property(boost INSTALL_DIR)

if(NOT WIN32)
  set(Boost_LIBRARY_DIR ${INSTALL_DIR}/lib/)
  set(Boost_INCLUDE_DIR ${INSTALL_DIR}/include/)
else()
  set(Boost_LIBRARY_DIR ${INSTALL_DIR}/lib/)
  set(Boost_INCLUDE_DIR ${INSTALL_DIR}/include/boost-1_64/)
endif()
