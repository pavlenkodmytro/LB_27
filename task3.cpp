#include <iostream>
#include <string>
#include <stdexcept> // Для std::invalid_argument, якщо б ми хотіли кидати більш конкретний тип

using namespace std;

const int DivideByZeroErrorCode = 111; // Можна також використовувати std::string або власний клас

// Функція internaldiv може бути спрощена, якщо div робить перевірку,
// або залишена для інших потенційних викликів.
// У цьому прикладі, якщо div_v2 робить перевірку,
// то internaldiv не обов'язково має повторювати її,
// але для узгодження з завданням, де internaldiv кидає виняток, залишимо її.
float internaldiv(float arg1, float arg2) {
    // В цьому сценарії, якщо div_v2 вже перевірила на нуль,
    // ця перевірка в internaldiv_for_v2 може здатися надлишковою.
    // Однак, це робить internaldiv_for_v2 безпечною для самостійного використання.
    if (arg2 == 0.0f) {
        // Теоретично, сюди не маємо потрапити, якщо div_v2 працює правильно
        throw DivideByZeroErrorCode;
    }
    return arg1 / arg2;
}


// Версія 2: функція div сама перевіряє дільник
// і кидає виняток перед тим, як намагатися ділити.
float div(float arg1, float arg2) {
    return internaldiv_for_v2(arg1, arg2);
}

int main() {
    float r, a, b;

    cout << "Введіть два числа для ділення (або нечисловий ввід для виходу):" << endl;

    while (cin >> a >> b) {
        try {
            r = div(a, b);
            cout << "Результат: " << r << endl;
        } catch (int errorCode) { // Ловимо той самий тип винятку
            if (errorCode == DivideByZeroErrorCode) {
                cout << "Помилка: Спроба ділення на нуль! Введіть інший дільник." << endl;
            } else {
                cout << "Невідома помилка з кодом: " << errorCode << endl;
            }
        }
        cout << "\nВведіть наступну пару чисел (або нечисловий ввід для виходу):" << endl;
    }

    cout << "Завершення програми." << endl;
    return 0;
}
