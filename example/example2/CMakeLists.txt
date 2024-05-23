add_executable(  PomeranianExample2 main.cpp
                )

target_include_directories( PomeranianExample2 PUBLIC 
                            "${PROJECT_SOURCE_DIR}/include"
                            Labrador
                            )

target_link_libraries(  PomeranianExample2 PUBLIC 
                        pthread
                        Labrador
                        JackRussell)
