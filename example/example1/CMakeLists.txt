add_executable(  PomeranianExample1 main.cpp
                )

target_include_directories( PomeranianExample1 PUBLIC 
                            "${PROJECT_SOURCE_DIR}/include"
                            Labrador
                            uuid
                            )

target_link_libraries(  PomeranianExample1 PUBLIC 
                        pthread
                        Labrador
                        JackRussell
                        Pomeranian)
