#pragma once

#include <vector>

//	INFO: все примеры генерируют прямоугольник размером width*height, заполненный цветом #888888
//	в центре которого расположен прямоугольник размером width/2*height/2, заполненный цветом #01DF01

//	INFO: создает тестовое изображение и возвращает его в виде невыравненного vector<unsigned char> 
std::vector<unsigned char> generateAsVectorChar(unsigned int width, unsigned int height);