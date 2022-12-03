add_executable(ess.exe app.cc)
target_link_libraries(ess.exe PUBLIC frontendlib)
target_link_libraries(ess.exe PUBLIC backendlib)

target_include_directories(ess.exe PUBLIC ${CMAKE_SOURCE_DIR})