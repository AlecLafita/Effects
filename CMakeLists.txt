cmake_minimum_required(VERSION 3.10)
project(Effects)

############ Third party
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/Core/ThirdParty")

find_package(OpenGL REQUIRED)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory("${CMAKE_SOURCE_DIR}/Core/ThirdParty/glfw")

add_subdirectory("${CMAKE_SOURCE_DIR}/Core/ThirdParty/glad")

set(LIBS glfw opengl32 glad)

############ Project src
file(GLOB_RECURSE SOURCE_FILES 
	${CMAKE_SOURCE_DIR}/Core/src/*.cpp)
	
file(GLOB_RECURSE HEADER_FILES 
	${CMAKE_SOURCE_DIR}/Core/src/*.h)


############ Define the include DIRs
include_directories(
	"${CMAKE_SOURCE_DIR}/Core/src"
	"${CMAKE_SOURCE_DIR}/Core/src/Modules"
	"${CMAKE_SOURCE_DIR}/Core/src/Modules/Render"
	"${CMAKE_SOURCE_DIR}/Core/src/Modules/Render/Shader"
	"${CMAKE_SOURCE_DIR}/Core/src/Modules/Window"
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