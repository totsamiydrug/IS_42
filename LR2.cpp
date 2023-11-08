#include <iostream>
#include <cmath>
#include <vector>
#include <locale>

class Vector {
private:
    std::vector<double> data;
    int size;

public:
    // Конструктор
    Vector(int size) : size(size) {
        data.resize(size);
    }

    // Деструктор
    ~Vector() {}

    // Метод для заполнения вектора
    void fillVector() {
        for (int i = 0; i < size; i++) {
            std::cin >> data[i];
        }
    }

    // Метод для вывода вектора и его нормы
    void printVector() {
        for (int i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }
    }
    void printNorm() {
        double norm = calculateNorm();
        std::cout << "norma= " << norm << std::endl;
    }

    // Метод для вычисления евклидовой нормы
    double calculateNorm() const {
        double sum = 0.0;
        for (int i = 0; i < size; i++) {
            sum += data[i] * data[i];
        }
        return std::sqrt(sum);
    }

    // Метод для сложения двух векторов
    Vector add(const Vector& other) {
        Vector result(size);
        for (int i = 0; i < size; i++) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }

    // Метод для вычитания двух векторов
    Vector subtract(const Vector& other) {
        Vector result(size);
        for (int i = 0; i < size; i++) {
            result.data[i] = data[i] - other.data[i];
        }
        return result;
    }

    // Метод для скалярного произведения векторов
    double scalarProduct(const Vector& other) {
        double result = 0;
        for (int i = 0; i < size; i++) {
            result += data[i] * other.data[i];
        }
        return result;
    }

    // Метод для умножения вектора на скаляр
    Vector multiplyByScalar(double scalar) {
        Vector result(size);
        for (int i = 0; i < size; i++) {
            result.data[i] = data[i] * scalar;
        }
        return result;
    }

    // Метод для сравнения двух векторов по норме
    int compareByNorm(const Vector& other) {
        double norm1 = calculateNorm();
        double norm2 = other.calculateNorm();
        if (norm1 == norm2) return 0;
        else if (norm1 < norm2) return -1;
        else return 1;
    }
};

int main() {
    // Устанавливаем русскую локаль
    std::locale::global(std::locale(""));

    int size;
    std::cin >> size;

    Vector vector1(size);
    Vector vector2(size);

    vector1.fillVector();
    vector2.fillVector();

    double scalar;
    std::cin >> scalar;

    // Вывод результатов
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
