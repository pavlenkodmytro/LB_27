#include <iostream>   // Підключення бібліотеки для введення/виведення (cout, cin, cerr)
#include <stdexcept>  // Підключення для стандартних винятків (якщо б ми хотіли їх використовувати замість int)

// Використання стандартного простору імен
using namespace std;

// Константа, що представляє код помилки ділення на нуль [cite: 20]
const int DivideByZero = 111;

// Функція, яка виконує ділення і генерує виняток, якщо дільник нуль [cite: 21]
float internaldiv(float arg1, float arg2) {
    if (arg2 == 0.0f) { // Перевірка, чи другий аргумент (дільник) дорівнює 0.0 [cite: 21]
        throw DivideByZero; // Якщо дільник нуль, генеруємо виняток з кодом DivideByZero [cite: 21]
    }
    return arg1 / arg2; // Повертаємо результат ділення [cite: 21]
}

// Модифікована функція div, яка тепер повертає результат ділення (float)
// і використовує internaldiv, яка може згенерувати виняток.
// Ця версія відповідає "one that catches the division by zero exception" [cite: 19]
// в тому сенсі, що виняток генерується внутрішньою функцією.
float div_v1(float arg1, float arg2) {
    // Просто викликаємо internaldiv, яка обробляє перевірку на нуль і генерує виняток
    return internaldiv(arg1, arg2); // Повертаємо результат з internaldiv
}

// Головна функція програми [cite: 23]
int main(void) {
    float r;     // Змінна для зберігання результату ділення
    float a, b;  // Змінні для зберігання введених користувачем чисел (ділене та дільник)

    cout << "--- Version 1 (using internaldiv's throw) ---" << endl;
    cout << "Enter two numbers (a and b for a/b). Enter non-numeric input to quit." << endl;

    // Цикл продовжується, доки користувач вводить коректні числа [cite: 23]
    while (cin >> a) { // Зчитуємо перше число (ділене)
        if (!(cin >> b)) { // Намагаємося зчитати друге число (дільник)
            cout << "Invalid input for b. Exiting." << endl; // Якщо введення для 'b' невдале
            break; // Виходимо з циклу
        }

        try { // Початок блоку try для відстеження винятків з функції div_v1 [cite: 17]
            r = div_v1(a, b); // Викликаємо функцію div_v1, яка може згенерувати виняток
            cout << "Result (v1): " << r << endl; // Виводимо результат, якщо винятку не було [cite: 23]
        }
        catch (int errorCode) { // Перехоплюємо виняток типу int (наш DivideByZero) [cite: 17]
            if (errorCode == DivideByZero) { // Перевіряємо, чи це саме наш код помилки
                // Виводимо повідомлення згідно зі сценарієм [cite: 18, 27]
                cerr << "Error (v1): Your input is not valid. You can't divide by zero." << endl;
            } else {
                // Обробка інших можливих цілочисельних винятків (якщо такі є)
                cerr << "Error (v1): An unexpected integer exception occurred: " << errorCode << endl;
            }
        }
        cout << "Enter next pair of numbers (or non-numeric to quit):" << endl;
    }
    cin.clear(); // Очищуємо прапорці помилок потоку cin
    // Поглинаємо залишки невірного вводу з буфера, щоб наступні операції вводу (якщо є) працювали коректно
    string dummy;
    getline(cin, dummy);


    // --- Версія 2 ---
    // Код для Версії 2 буде представлений нижче

    return 0; // Успішне завершення програми [cite: 24]
}
