# CMakeList.txt: проект CMake для EngineWrapper; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)             # Стандарт C++
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# project ("EngineWrapper")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (EngineWrapper "EngineWrapper.cpp" "EngineWrapper.h" "wrapper/wrapper.h" "engine/engine.h" "tests/tests.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
