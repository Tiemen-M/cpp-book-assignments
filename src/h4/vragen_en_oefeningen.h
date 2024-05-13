// Created by Tiemen Molenaar in 2023
#pragma once
double discriminant(double a = 1.0, double b = 1.0, double c = 1.);

char alpha_shift(char in);
// pre: in is een karater in ['a','z']
// post: functie levert een karater in ['a','z'] op.

double macht(double grondgetal, unsigned int exponent);
// pre: grondgetal en exponent
// post: retourneert grondgetal^exponent