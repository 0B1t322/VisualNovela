cmake_minimum_required(VERSION 3.13)
project(Eroge)

set(CMAKE_CXX_STANDARD 20)
set(HEADERS 
    Engine/Engine.h Engine/GUI/Textbox.h Engine/GUI/Button.h 
    Engine/Pages/mainPage.h Engine/Pages/playPage.h Engine/GUI/levelBox.h
    characters/character.h Engine/Pages/ABSpageClass.h characters/Ulayna/Ulyana.h)
set(SOURCES 
    main.cpp Engine/Engine.cpp Engine/Draw.cpp Engine/Update.cpp Engine/Input.cpp 
    Engine/GUI/Textbox.cpp Engine/GUI/Button.cpp Engine/Pages/mainPage.cpp 
    Engine/Pages/playPage.cpp Engine/GUI/levelBox.cpp characters/character.cpp)
add_custom_target(copy_target ALL
    ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/Textures ${CMAKE_CURRENT_BINARY_DIR}/Textures
    DEPENDS Eroge
    COMMENT "Copy neded folder to compiling executable"
    COMMENT "Pososi Andrey"
    COMMENT "Pososi Danya"
    )

# SFML
## If you want to link SFML statically

#set(SFML_DIR "<SFML-2.5.1/lib/cmake/SFML")
set(CMAKE_PREFIX_PATH "<SFML-2.5.1/lib/cmake/SFML")

#find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
add_executable(Eroge ${SOURCES} ${HEADERS})
target_link_libraries(Eroge sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
