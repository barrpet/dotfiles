add_executable(main main.cpp)

install(TARGETS main
  RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin)
