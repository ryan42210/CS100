#include <iostream>
#include <string>
#include <random>
#include <utility>
#include <time.h>
#include <functional>

using namespace std;

#define MAX_ROWS 3
#define MAX_COLS 10
#define MAX_STUDENTS 30

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

#define NOTHING 0
#define APPLEPIE 1
#define BEEF 2
#define CURRY 3


typedef int MEALTYPE;

class Fmart;

// ------------------------------Helper functions--------------------------------------//
int randInt(int min, int max){
    if (max < min)
		swap(max, min);
    return rand() % (max - min + 1) + min;
}
// -----------------------------Class Declarations-------------------------------------//
class Player{
public:
    //constructor
    Player(Fmart* fp);
    //destructor
    ~Player();
    //accessors
    int row() const;
    int col() const;
    int lives() const;
    int score() const;
    MEALTYPE mealInHand() const;

    //mutators
    void pickup(MEALTYPE meal);
    void move(int dir);

    void deliver();
    void decLife();

private:
    int m_row;
    int m_col;
    int m_lives;
    int m_score;
    MEALTYPE m_mealInHand;
    Fmart* m_fp;
};

class Student{
public:
    //constructor
    Student(Fmart* fp, int row, int col);
    //destructor
    ~Student();
    //accessors
    int row() const;
    int col() const;
    MEALTYPE typeWanted() const;

    //mutators
    void moveForward();

private:
    MEALTYPE m_typewanted;
    int m_stu_row;
    int m_stu_col;
    Fmart* ptr_to_its_fmart;
};

class Fmart{
public:
    //constructor
    Fmart();

    //destructor
    ~Fmart();

    //accessors
    Student* getStudent(int i) ;
    Player* getPlayer() const;
    int numberOfStudents() const;
    bool studentAt(int row, int col) const;
    int studentIndex(int row, int col);

    //mutators
    bool addStudent();
    bool deleteStudent(int row, int col);
    void display();
    void play();

private:
    Player* m_player;
    Student* m_students[MAX_STUDENTS];
    int m_numStudents;
};

//---------------------------Implementions of Fmart-------------------------------------//

Fmart::Fmart() {
    for (int i = 0; i < MAX_STUDENTS; i++){
        m_students[i] = nullptr;
    }
    m_numStudents = 0;
    m_player = new Player(this);
}

Fmart::~Fmart() {
    delete m_player;
    for (int i = 0; i < m_numStudents; i++){
        delete m_students[i];
        m_students[i] = NULL;
    }
    m_numStudents = 0;
}

Student* Fmart::getStudent(int i) {
    return m_students[i];
}

Player* Fmart::getPlayer() const {
    return m_player;
}

int Fmart::numberOfStudents() const {
    return m_numStudents;
}

bool Fmart::studentAt(int row, int col) const {
    for (int i = 0; i < m_numStudents; i++) {
        if (m_students[i]->col() == col && m_students[i]->row() == row) {
            return true;
        }
    }
    return false;
}

int Fmart::studentIndex(int row, int col) {
    for (int i = 0; i < m_numStudents; i++) {
        if (m_students[i]->col() == col && m_students[i]->row() == row) {
            return i;
        }
    }
    return MAX_STUDENTS;
}

bool Fmart::addStudent() {
    if (MAX_STUDENTS <= numberOfStudents()) {
        return false;
    }else {
        int row = randInt(1, MAX_ROWS);
        m_students[m_numStudents] = new Student(this, row, MAX_COLS);
        m_numStudents++;
        return true;
    }
}

bool Fmart::deleteStudent(int row, int col) {
    int index = studentIndex(row, col);
    if (index == MAX_STUDENTS) {
        return false;
    }
    delete m_students[index];
    for (int i = 0; i < m_numStudents - index - 1; i++) {
        m_students[index + i] = m_students[index + i + 1];
    }
    m_numStudents--;
    m_students[m_numStudents] = NULL;
    return true;
}

void Fmart::display()
{
    char** disp = new char* [3];
    for (int i = 0; i < 3; i++) {
        disp[i] = new char[10];
        for (int j = 0; j < 10; j++)
            disp[i][j] ='.';
    }

    for (int i = 0; i < m_numStudents; i++) {
        if (m_player->mealInHand() == m_students[i]->typeWanted()) {
            disp[m_students[i]->row() - 1][m_students[i]->col() - 1] = '@';
        } else {
            disp[m_students[i]->row() - 1][m_students[i]->col() - 1] = 'S';
        }
    }

    if (m_player->mealInHand() == APPLEPIE) {
        disp[m_player->row() - 1][m_player->col() - 1] = 'A';
    }
    else if (m_player->mealInHand() == BEEF) {
        disp[m_player->row() - 1][m_player->col() - 1] = 'B';
    }
    else if (m_player->mealInHand() == CURRY) {
        disp[m_player->row() - 1][m_player->col() - 1] = 'C';
    }
    else if (m_player->mealInHand() == NOTHING) {
        disp[m_player->row() - 1][m_player->col() - 1] = 'P';
    }

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 10; j++)
            cout << disp[i][j];
        cout << endl;
    }

    for (int i = 0; i < 3; i++)
        delete[] disp[i];
    delete[] disp;
}

void Fmart::play()
{
    addStudent();
    while (m_player->lives() > 0) {
        display();
        cout << "You have " <<m_player->lives() <<" lives, and your score is " <<m_player->score()<<"."<<endl;
        cout << "make a move (a, b, c, u, d, g): " << endl;
        string input;
		getline(cin, input);
        cout << endl << endl << endl;

        char option = input[0]; //Here, option is 'a', 'b', 'c', 'u', 'd', or 'g'.

        if (option == 'a') {
            m_player->pickup(APPLEPIE);
        }
        else if (option == 'b'){
            m_player->pickup(BEEF);
        }
        else if (option == 'c'){
            m_player->pickup(CURRY);
        }
        else if (option == 'u'){
            m_player->move(UP);
        }
        else if (option == 'd'){
            m_player->move(DOWN);
        }
        else if (option == 'g'){
            m_player->deliver();
        }
        else continue;
        // Moves all students forward
        for (int i = 0; i < m_numStudents; i++){
            int detector = m_numStudents;
            m_students[i]->moveForward();
            if(m_numStudents != detector)
                i--;
        }
        // A 30% chance for adding a new student
        if(randInt(1,10) <= 3)
            addStudent();
    }
    cout << "You lose. Your score is " << m_player->score() <<". Press any key to quit." << endl;
    getchar();
}

//---------------------------Implementions of Student -------------------------------------//
Student::Student(Fmart* fp, int row, int col) {
    m_typewanted = randInt(APPLEPIE,CURRY);
    m_stu_col = col;
    m_stu_row = row;
    ptr_to_its_fmart = fp;
}

Student::~Student() {
}

int Student::row() const {
    return m_stu_row;
}

int Student::col() const {
    return m_stu_col;
}

MEALTYPE Student::typeWanted() const{
    return m_typewanted;
}

void Student::moveForward() {
    m_stu_col--;
    if (m_stu_col <2 && m_stu_col > 0) {
        ptr_to_its_fmart->getPlayer()->decLife();
        ptr_to_its_fmart->deleteStudent(m_stu_row, m_stu_col);
    }
    return;
}

//---------------------------Implementions of Player -------------------------------------//

Player::Player(Fmart* fp) {
    m_row = 2;
    m_col = 1;
    m_lives = 3;
    m_score = 0;
    m_mealInHand = NOTHING;
    m_fp = fp;
}


Player::~Player() {
}

int Player::row() const {
    return m_row;
}
int Player::col() const {
    return m_col;
}

int Player::lives() const {
    return m_lives;
}

int Player::score() const {
    return m_score;
}

MEALTYPE Player::mealInHand() const {
    return m_mealInHand;
}

void Player::pickup(MEALTYPE meal) {
    m_mealInHand = meal;
    return;
}

void Player::move(int dir) {
    if (dir == UP) {
        if (row() <= MAX_ROWS && row() > 1) {
            m_row--;
        }
    }
    else if (dir == DOWN) {
        if (row() < MAX_ROWS && row() >= 1) {
            m_row++;
        }
    }
    return;
}

void Player::deliver() {
    for (int i = 0; i < MAX_COLS; i++) {
        if (m_fp->studentAt(m_row, i + 1)) {
            if (m_fp->getStudent(m_fp->studentIndex(m_row,i + 1))->typeWanted() == m_mealInHand && m_mealInHand != NOTHING) {
                m_fp->deleteStudent(m_row, i + 1);
                m_score = m_score + 10;
                pickup(NOTHING);
            }
            break;
        }
    }
    return;
}

void Player::decLife() {
    m_lives--;
    return;
}


// ------------------------------Main function--------------------------------------//
int main()
{
    //srand(time(NULL));
    Fmart f;
    f.play();
}