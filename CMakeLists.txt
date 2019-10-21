cmake_minimum_required(VERSION 3.14)
project(untitled C)

set(CMAKE_C_STANDARD 99)

add_executable(test test.c)

add_executable(broker LiMP/broker.c)
add_executable(point_the_corner LiMP/point_the_corner.c)
add_executable(bada LiMP/bada.c)
add_executable(mushroom LiMP/mushroom_editor.c)
add_executable(fence LiMP/fence.c )
add_executable(finding "LiMP/ finding_vasya.c")
add_executable(ideas LiMP/ideas.c)
add_executable(grep LiMP/GREP.c)


add_executable(summa algoritm/summa.c)
add_executable(povtor algoritm/povtor.c)
add_executable(tree algoritm/tree.c)
add_executable(documents algoritm/documents.c)
add_executable(progressia algoritm/progressia.c)
add_executable(chess algoritm/chess.c)
add_executable(tricky_numbers algoritm/Tricky_number.c)
add_executable(prosto_podchet algoritm/prosto_podchet.c)
add_executable(hod algoritm/HOD.c)
add_executable(eggs algoritm/eggs.c)

add_executable(long_int Long_int/convert.c Long_int/long_int.c Long_int/long_int.h)
add_executable(convert Long_int/main.c)