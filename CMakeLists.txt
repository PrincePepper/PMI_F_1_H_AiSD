cmake_minimum_required(VERSION 3.14)
project(untitled C)

set(CMAKE_C_STANDARD 99)
#   здесь тестовый код
add_executable(test test.c)
add_executable(test_cpp test.cpp)

#   это все проги по ЯиМП
add_executable(broker LiMP/broker.c)
add_executable(point_the_corner LiMP/point_the_corner.c)
add_executable(bada LiMP/bada.c)
add_executable(mushroom LiMP/mushroom_editor.c)
add_executable(fence LiMP/fence.c)
add_executable(finding "LiMP/ finding_vasya.c")
add_executable(ideas LiMP/ideas.c)
add_executable(lanterns LiMP/lanterns.c)
add_executable(Lin_log_sort_2 LiMP/Lin_log_sort_2.c)
#   доп задания
add_executable(count_string "LiMP/ count_string.c")
add_executable(grep LiMP/GREP.c)
add_executable(max_int LiMP/max_int.c)
#   библиотека списков
add_executable(linear_lib LiMP/Linear_sequence/linear_sequence.cpp LiMP/Linear_sequence/linear_sequence.h)
add_executable(linear_sequence LiMP/Linear_sequence/main.c LiMP/Linear_sequence/linear.cpp)

#   это все проги по АиСД
add_executable(eggs algoritm/eggs.c)
add_executable(summa algoritm/summa.c)
add_executable(povtor algoritm/povtor.c)
add_executable(tree algoritm/tree.c)
add_executable(documents algoritm/documents.c)
add_executable(progressia algoritm/progressia.c)
add_executable(factorial algoritm/factorial.c)
add_executable(labyrinth_2 algoritm/labyrinth_2.c)
add_executable(labyrinth_1 algoritm/labyrinth_1.c)
add_executable(glushchenko_pawns algoritm/glushchenko_pawns.c)
add_executable(newyear algoritm/NewYear.c)
add_executable(knitting_cude algoritm/knitting_cube.c)
add_executable(guess_word algoritm/guess_word.c)
add_executable(cap algoritm/cap.c)
add_executable(rally algoritm/rally.c)

#   доп задания
add_executable(tricky_numbers algoritm/TrickyNumber/Tricky_number.c)
add_executable(prosto_podchet algoritm/prosto_podchet.c)
#   библиотека длинных чисел
add_executable(Long_int algoritm/Long_int/convert.c algoritm/Long_int/long_int.c algoritm/Long_int/long_int.h)
add_executable(convert algoritm/Long_int/main.c)


#   хитрый член на С++
cmake_minimum_required(VERSION 3.15)
project(test)
set(CMAKE_CXX_STANDARD 98)
add_executable(test2 algoritm/TrickyNumber/tricky.cpp algoritm/TrickyNumber/run_tricky.cpp)
#   нод и числа фибоначи
add_executable(hod algoritm/HOD.cpp)

#   экзамен по яимпу
add_executable(three_numbers LiMP/BB/three_numbers.c)
add_executable(distance LiMP/BB/distance.c)
add_executable(random_substance LiMP/BB/random_substance.c)
add_executable(random_int LiMP/BB/random_int.c)
add_executable(prime_numbers LiMP/BB/prime_numbers.c)
add_executable(fib_numb LiMP/BB/fib_numb.c)
add_executable(factorial2 LiMP/BB/factorial.c)
add_executable(algoritm_evclid LiMP/BB/algoritm_evclid.c)