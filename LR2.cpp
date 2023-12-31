﻿#include <iostream>
#include <vector>
#include <cmath>

class Vector {
private:
    std::vector<double> data;
    int size;
public:
    Vector(int size1) :size(size1) {
        data.resize(size1);
    }
    ~Vector() {}
    void fillVector() {
        for (int i = 0; i < size1; i++) {
            std::cin >> data[i];
        }
    }
    void printVector() {
        for (int i = 0; i < size1; i++) {
            std::cout << data[i] << " ";
        }
    }
    void printNorm() {
        double norm = calculateNorm();
        std::cout << "norma= " << norm << std::endl;
    }
    double calculateNorm() const {
        double sum = 0.0;
        for (int i = 0; i < size1; i++) {
            sum += data[i] * data[i];
        }
        return std::sqrt(sum);
    }
    Vector add(const Vector& other) {
        Vector result(size1);
        for (int i = 0; i < size1; i++) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }
    Vector subtract(const Vector& other) {
        Vector result(size1);
        for (int i = 0; i < size1; i++) {
            result.data[i] = data[i] - other.data[i];
        }
        return result;
    }
    double scalarProduct(const Vector& other) {
        double result = 0;
        for (int i = 0; i < size1; i++) {
            result += data[i] * other.data[i];
        }
        return result;
    }
    Vector multiplyByScalar(double scalar) {
        Vector result(size1);
        for (int i = 0; i < size1; i++) {
            result.data[i] = data[i] * scalar;
        }
        return result;
    }
    int compareByNorm(const Vector& other) {
        double norm1 = calculateNorm();
        double norm2 = other.calculateNorm();
        if (norm1 == norm2) return 0;
        else if (norm1 < norm2) return -1;
        else return 1;
    }
};

int main() {
    setlocale(LC_ALL, "Eng");
    int size1;
    std::cin >> size1;
    Vector vector1(size1);
    Vector vector2(size1);
    vector1.fillVector();
    vector2.fillVector();
    double scalar;
    std::cin >> scalar;
    std::cout << "vector1= ";
    vector1.printVector();
    vector1.printNorm();
    std::cout << "vector2= ";
    vector2.printVector();
    vector2.printNorm();
    Vector sum = vector1.add(vector2);
    std::cout << "summa= ";
    sum.printVector();
    std::cout << std::endl;
    Vector difference = vector1.subtract(vector2);
    std::cout << "raznost= ";
    difference.printVector();
    std::cout << std::endl;
    double dotProduct = vector1.scalarProduct(vector2);
    std::cout << "scalar= " << dotProduct << std::endl;
    Vector scaledVector1 = vector1.multiplyByScalar(scalar);
    std::cout << "mult chislo * Vector1= ";
    scaledVector1.printVector();
    std::cout << std::endl;
    Vector scaledVector2 = vector2.multiplyByScalar(scalar);
    std::cout << "mult chislo * Vector2= ";
    scaledVector2.printVector();
    std::cout << std::endl;
    int comparison = vector1.compareByNorm(vector2);
    if (comparison == 0) {
        std::cout << "norma(Vector1) = norma(Vector2)" << std::endl;
    }
    else if (comparison < 0) {
        std::cout << "norma(Vector1) < norma(Vector2)" << std::endl;
    }
    else {
        std::cout << "norma(Vector1) > norma(Vector2)" << std::endl;
    }
    return 0;
}
