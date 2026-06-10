if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(ARMFORGE_WARNINGS
        -Wall
        -Wextra
        -Wpedantic
        -Wconversion
        -Wshadow
        -Wnon-virtual-dtor
        -Wold-style-cast
        -Woverloaded-virtual
        -Wnull-dereference
        -Wdouble-promotion
        -Wformat=2
    )
elseif(MSVC)
    set(ARMFORGE_WARNINGS
        /W4
        /permissive-
    )
else()
    set(ARMFORGE_WARNINGS)
endif()

if(ARMFORGE_WARNINGS_AS_ERRORS)
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        list(APPEND ARMFORGE_WARNINGS -Werror)
    elseif(MSVC)
        list(APPEND ARMFORGE_WARNINGS /WX)
    endif()
endif()

