link_libraries(${JSONCPP_LIBRARIES})
add_executable (testjson
                test_json.cc)
target_link_libraries(testjson ${JSONCPP_LIBRARIES})