add_executable(Day2)
target_sources(Day2
        PRIVATE
        Day2.cpp
)
target_link_libraries(Day2 read_input)
target_include_directories(Day2 PRIVATE ../Libraries/Include)