#include <iostream>
#include <vector>
#include <iomanip>
#include <numeric>
#include <algorithm>

void disp(const std::vector<double>& arr) {

  for (double x : arr) {
    std::cout << std::fixed << std::setprecision(3) << x << " ";
  }
  std::cout << std::endl;

}

void add_element(std::vector<double>& arr, double &sum, double &avg) {

  sum1 = accumulate(arr.begin(), arr.end(), 0.0);
  avg = sum1 / arr.size();
  arr.push_back(sum1);
  arr.push_back(avg);

}

void rabotaSVektorom(std::vector<double>& arr, int n, double& avg) {

  int flag = 0;
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] > 0) {
      flag++;
      if (flag == 3) {
        arr[i] = avg;
        flag = 0;
      }
    }
  }

}

int menu(std::vector<double>& arr, int n, double &sum1, double &avg) {

  int choice;
  while (true) {
      std::cin >> choice;
    switch (choice) {
    case 0:
      return 0;
    case 1:
      double elem;
      std::cin >> elem;
      arr.push_back(elem);
      std::cout << "+: " << arr.size() << std::endl;
      disp(arr);
      add_element(arr, sum1, avg);
      disp(arr);
      rabotaSVektorom(arr, n, avg);
      disp(arr);
      break;
    case 2:
      if (!arr.empty()) {
        arr.pop_back();
        std::cout << "-: " << arr.size() << std::endl;
        disp(arr);
        add_element(arr, sum1, avg);
        disp(arr);
        rabotaSVektorom(arr, n, avg);
        disp(arr);  
      }
      else {
          std::cout << "Массив пуст, удаление невозможно." << std::endl;
      }
      break;
    default:
        std::cout << "Неверный выбор действия. Попробуйте еще раз." << std::endl;
    }
  }

}

int main() {

  setlocale(LC_ALL, "Russian");
  double  sum1 = 0;
  double avg = 0;
  int n;
  std::cin >> n;
  std::vector<double> arr(n);
  for (int i = 0; i < n; i++) {
      std::cin >> arr[i];
  }

  std::cout << std::endl << n << std::endl;

  disp(arr);
  add_element(arr, sum1, avg);
  disp(arr);
  rabotaSVektorom(arr, n, avg);
  disp(arr);
  menu(arr, n, sum1, avg);
  return 0;

}
