cmake_minimum_required(VERSION 3.10)
project(Effects)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

############ Third party
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/Core/ThirdParty")

find_package(OpenGL REQUIRED)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory("${CMAKE_SOURCE_DIR}/Core/ThirdParty/glfw")

add_subdirectory("${CMAKE_SOURCE_DIR}/Core/ThirdParty/glad")

add_subdirectory("${CMAKE_SOURCE_DIR}/Core/ThirdParty/glm")

include_directories("${CMAKE_SOURCE_DIR}/Core/ThirdParty/stb_image")
link_directories("${CMAKE_SOURCE_DIR}/Core/ThirdParty/stb_image")

set(ASSIMP_BUILD_ASSIMP_TOOLS OFF)
add_subdirectory("${CMAKE_SOURCE_DIR}/Core/ThirdParty/assimp")

set(LIBS glfw opengl32 glad glm assimp)

############ Project src
file(GLOB_RECURSE SOURCE_FILES 
	${CMAKE_SOURCE_DIR}/Core/src/*.cpp)
	
file(GLOB_RECURSE HEADER_FILES 
	${CMAKE_SOURCE_DIR}/Core/src/*.h)

############ Define the include DIRs
configure_file(${CMAKE_SOURCE_DIR}/Core/src/Utils/Dirs.h.in ${CMAKE_SOURCE_DIR}/Core/src/Utils/Dirs.h)

include_directories(
	"${CMAKE_SOURCE_DIR}/Core/src"
	"${CMAKE_SOURCE_DIR}/Core/src/Engine"
	"${CMAKE_SOURCE_DIR}/Core/src/Modules"
	"${CMAKE_SOURCE_DIR}/Core/src/Modules/Camera"
	"${CMAKE_SOURCE_DIR}/Core/src/Modules/Render"
	"${CMAKE_SOURCE_DIR}/Core/src/Modules/Render/Mesh"
	"${CMAKE_SOURCE_DIR}/Core/src/Modules/Render/Shader"
	"${CMAKE_SOURCE_DIR}/Core/src/Modules/Render/Texture"
	"${CMAKE_SOURCE_DIR}/Core/src/Modules/Window"
	"${CMAKE_SOURCE_DIR}/Core/src/Utils"
	"${CMAKE_SOURCE_DIR}/Core/src/Utils/Image"
)

############ Add the executable
add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})

############ Define the link libraries
target_link_libraries(${PROJECT_NAME} ${LIBS})


# Create virtual folders to make it look nicer in VS
if(MSVC_IDE)
	# Macro to preserve source files hierarchy in the IDE
	macro(GroupSources curdir)
		file(GLOB children RELATIVE ${PROJECT_SOURCE_DIR}/${curdir} ${PROJECT_SOURCE_DIR}/${curdir}/*)

		foreach(child ${children})
			if(IS_DIRECTORY ${PROJECT_SOURCE_DIR}/${curdir}/${child})
				GroupSources(${curdir}/${child})
			else()
				string(REPLACE "/" "\\" groupname ${curdir})
				string(REPLACE "src" "Sources" groupname ${groupname})
				source_group(${groupname} FILES ${PROJECT_SOURCE_DIR}/${curdir}/${child})
			endif()
		endforeach()
	endmacro()

	# Run macro
	GroupSources(src)
endif()