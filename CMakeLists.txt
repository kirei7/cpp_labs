cmake_minimum_required(VERSION 3.7)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES7 lab7/main.cpp lab7/shops/Shop.cpp lab7/shops/EquipmentShop.cpp lab7/data/Product.h lab7/actors/Wife.cpp lab7/actors/Husband.cpp lab7/shops/ProductsShop.cpp lab7/data/OrderResult.h)
add_executable(lab7 ${SOURCE_FILES7} lab7/main.cpp)

set(SOURCE_FILES8 lab8/main.cpp lab8/data/SortResult.h lab8/Sorter.cpp lab8/BubbleSort.cpp)
add_executable(lab8 ${SOURCE_FILES8} lab8/main.cpp)

set(SOURCE_FILES9 lab9/main.cpp)
add_executable(lab9 ${SOURCE_FILES8} lab9/main.cpp)


