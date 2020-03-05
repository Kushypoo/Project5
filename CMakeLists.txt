cmake_minimum_required(VERSION 2.8.9)

project(project5)

include_directories(include)

set(VEHICLE_SOURCE Source/Vehicle_Class/Vehicle.cpp)
add_library(my_vehicle ${VEHICLE_SOURCE})

set(CAR_SOURCE Source/Car_Class/Car.cpp)
add_library(my_car ${CAR_SOURCE})

add_executable(project5 Source/main.cpp)

target_link_libraries(project5 CAR_SOURCE VEHICLE_SOURCE)

install(TARGETS project5 my_car my_vehicle
	RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/devel/bin
	LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib
	ARCHIVE DESTINATION ${PORJECT_SOURCE_DIR}/devel/lib/static)
	
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
	DESTINATION ${PROJECT_SOURCE_DIR}/devel/include
	FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")
