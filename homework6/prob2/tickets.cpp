#include "tickets.h"

//implementations of LotteryTicket
LotteryTicket::LotteryTicket() {}
LotteryTicket::LotteryTicket(const CustomSet<int>& numbers, int round) {
    m_round = round;
    m_numbers = numbers;
    m_claimed = false;
}
LotteryTicket::~LotteryTicket() {}
int LotteryTicket::getRound() {
    return m_round;
}
int LotteryTicket::getCost() {
    return m_cost;
}
void LotteryTicket::setCost(const int& cost) {
    m_cost = cost;
}
CustomSet<int> LotteryTicket::getNumbers() const {
    CustomSet<int> temp = m_numbers;
    return temp;
}
int LotteryTicket::calCombiNum(int a, int b) {
    if (a > b) return 0;
    if (a == 0) return 1;
    int result = 0;
    int up, down, upCopy, downCopy;
    up = b;
    upCopy = b - 1;
    down = a;
    downCopy = a - 1;
    for (int counter = a; counter > 1; counter--) {
        up = up*upCopy;
        upCopy--;
    }

    for (int counter = a; counter > 1; counter--) {
        down = down*downCopy;
        downCopy--;
    }
    result = up/down;
    return result;
}

/*void LotteryTicket::calPrizeWin(int type, int bought, int right){
    if (right > type - 4) {
        int free = bought - right;
        int prizeNumber = calCombiNum(type - right, free);
        if(right > type - 3) calPrizeWin(type, bought - 1, right - 1);
        prizeList.push_back(prizeNumber);
    }
}*/
void LotteryTicket::calPrizeWin(int type, int bought, int right, int cnt){
    if (right > type - 4) {
        int rightfix = right - cnt;
        int rightComb = calCombiNum(rightfix, right);
        int freeComb = calCombiNum(type - rightfix, bought - right);
        int winPrize = freeComb*rightComb;
        if(rightfix > type - 3) calPrizeWin(type, bought, right, cnt + 1);
        prizeList.push_back(winPrize);
    }
}

//implementations of Lotto7Ticket
Lotto7Ticket::Lotto7Ticket(const CustomSet<int>& number, int round):LotteryTicket::LotteryTicket(number, round) {
    int bought = number.size();
    int cost = 0;
    if (bought < 31) m_bought = bought;
    if (round == getRound() && bought < 31) {
        if(bought == 7) cost = 2;
        else if (bought < 7) cost = 0;
        else if (bought > 7) {
            cost = 2*calCombiNum(7, bought);
        }
        setCost(cost);
    }
}
Lotto7Ticket::~Lotto7Ticket() {}
int Lotto7Ticket::getTicketType() {
    return LOTTO7;
}
int Lotto7Ticket::claimPrize(const CustomSet<int>& prizeNumbers, int round) {
    if (round != getRound() || m_claimed == true) return 0;
    CustomSet<int> rightNumber(getNumbers().intersection(prizeNumbers));
    int right = rightNumber.size();
    if (right < 4) {
        m_claimed = true;
        return 0;
    }
    if (getCost() == 2){
        m_claimed = true;
        if(right == 4) return 5;
        if(right == 5) return 75;
        if(right == 6) return 4500;
        if(right == 7) return 2000000;
    } else if (getCost() > 2) {
        calPrizeWin(7, m_bought, right, 0);
        int totalMoney = 0;
        for (int i = 0; i < prizeList.size(); i++) {
            int money = 0;
            if (i == 0) money = 5;
            if (i == 1) money = 75;
            if (i == 2) money = 4500;
            if (i == 3) money = 2000000;
            totalMoney += money*prizeList[i];
        }
        m_claimed = true;
        return totalMoney;
    }
}

//implementations of Lotto6Ticket
Lotto6Ticket::Lotto6Ticket(const CustomSet<int>& number, int round):LotteryTicket::LotteryTicket(number, round) {
    int bought = number.size();
    int cost = 0;
    if (bought < 44) m_bought = bought;
    if (round == getRound() && bought < 44) {
        if(bought == 6) cost = 2;
        else if (bought < 6) cost = 0;
        else if (bought > 6) {
            cost = 2*calCombiNum(6, bought);
        }
        setCost(cost);
    }
}
Lotto6Ticket::~Lotto6Ticket() {}
int Lotto6Ticket::getTicketType() {
    return LOTTO6;
}
int Lotto6Ticket::claimPrize(const CustomSet<int>& prizeNumbers, int round) {
    if (round != getRound() || m_claimed == true) return 0;
    CustomSet<int> rightNumber(getNumbers().intersection(prizeNumbers));
    int right = rightNumber.size();
    if (right < 3) {
        m_claimed = true;
        return 0;
    }
    if (getCost() == 2){
        m_claimed = true;
        if(right == 3) return 5;
        if(right == 4) return 75;
        if(right == 5) return 4500;
        if(right == 6) return 2000000;
    } else if (getCost() > 2) {
        calPrizeWin(6, m_bought, right, 0);
        int totalMoney = 0;
        int money = 0;
        for (int i = 0; i < prizeList.size(); i++) {
            if (i == 0) money = 5;
            if (i == 1) money = 75;
            if (i == 2) money = 4500;
            if (i == 3) money = 2000000;
            totalMoney += money*prizeList[i];
        }
        m_claimed = true;
        return totalMoney;
    }
}