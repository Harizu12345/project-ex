#include <iostream> //  это директива препроцессора в C++ для включения ввода и ввывода 
#define start_for_game "Здравствуйте, выберите то, что вы хотите сделать" 
#define rules_for_gamee cout << "Игроки по очереди ставят на свободные клетки поля 3x3 знаки (один всегда крестики, другой всегда нолики). " << endl;
#include <windows.h> // для латиницы
using namespace std;



struct gamee
{
    string choice_play;
};


void printBoard(char board[3][3]) { // функция которая выводит настоящее поле в настоящее время. Она проходит по каждой клетке поля и показывает, что находится в этой клетке 
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkWin(char board[3][3], char symbol) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) // Проверка горизонтальных и вертикальных линий. Если символ присутствует во всех трех клетках, функция возвращает true, обозначая выигрыш.
            return true;
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) // тоже самое 
            return true;
    }
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) //  проверяет главную диагональ от верхнего левого угла до нижнего правого угла поля.
        return true;
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) // проверяет побочную диагональ от верхнего правого угла до нижнего левого угла поля.
        return true;

    return false;
}

bool isBoardFull(char board[3][3]) { // проверяет каждую клетку и если видит | то говорит что туда можно ходить, еше сделана для ничьй
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == '|')
                return false;
        }
    }
    return true;
}

int main() {
    SetConsoleOutputCP(1251); // для латиницы
    SetConsoleCP(1251); // для латиницы
    int choice;
    int choice_playGamee;

    cout << start_for_game << "\n" << endl; // тут используем define 


    gamee info = { "Вы готовы ? \n 1 = Да \n 2 = Нет " }; // структура 

    while (true) {
        cout << "Меню:" << endl;
        cout << "1. Посмотреть правила" << endl;
        cout << "2. Начать игру" << endl;
        cout << "3. Выйти из игры" << endl;
        cout << "Выберите опцию: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\n";
            cout << "Правила: " << endl;
            rules_for_gamee;
            cout << "\n";
            break;
        case 2:
            cout << info.choice_play << "\n";
            cin >> choice_playGamee;
            if (choice_playGamee == 1) {
                cout << "Игра начата" << "\n";

                char board[3][3] = { {'|', '|', '|'}, {'|', '|', '|'}, {'|', '|', '|'} }; //  создаёт игровое поле размером 3x3

                printBoard(board);

                bool player1Turn = true; // определяет кто ходит 
                char currentPlayerSymbol = 'X'; // указывает символ

                while (true) {
                    int row, col;
                    cout << "Игрок " << (player1Turn ? "1 (X)" : "2 (O)") << ", введите строку и столбец (например, 1 2): ";
                    cin >> row >> col;

                    if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != '|') { // проверяет правильность хода, конец проверяет свободна ли клетка
                        cout << "Неверный ход" << endl;
                        continue;
                    }

                    board[row - 1][col - 1] = currentPlayerSymbol; // устанавливает символ текущего игрока 
                    printBoard(board); // выводит обновленное состояние игрового поля на экран

                    if (checkWin(board, currentPlayerSymbol)) { // проверяет, выиграл ли текущий игрок после совершения хода
                        cout << "Игрок " << (player1Turn ? "1 (X)" : "2 (O)") << " выиграл!" << endl;
                        break;
                    }
                    else if (isBoardFull(board)) {
                        cout << "Ничья" << endl;
                        break; // поле заполнено и никто не выиграл 
                    }

                    player1Turn = !player1Turn; // переключает очередность хода между игроками
                    currentPlayerSymbol = (player1Turn) ? 'X' : 'O'; // обновляет символ текущего игрока. Если player1Turn равно true, то currentPlayerSymbol станет 'X', в инно случае 'O'
                }

                return 0;
            }
            if (choice_playGamee >= 2) {
                break;
            }

            break;
        case 3:
            cout << "\n";
            cout << "Выход из игры" << endl;
            return 0;
        default:
            cout << "Неверный выбор" << endl;
            cout << "\n" << endl;
            break;
        }
    }

    return 0;
}

