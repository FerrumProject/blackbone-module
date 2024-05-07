if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(ARCH "amd64")
else()
    set(ARCH "")
endif()

set(DIA_PATH "${CMAKE_SOURCE_DIR}/3rd_party/blackbone/src/3rd_party/DIA/lib/${ARCH}")
set(BLACKBONE_PATH "${CMAKE_SOURCE_DIR}/3rd_party/blackbone/src")

target_include_directories(${PROJECT_NAME} PRIVATE ${BLACKBONE_PATH} ${DIA_PATH} ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} BlackBone ${DIA_PATH}/diaguids.lib)

add_subdirectory(${BLACKBONE_PATH})