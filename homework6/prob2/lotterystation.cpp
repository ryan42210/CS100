#include "lotterystation.h"

LotteryStation::LotteryStation() {
    m_round = 0;
}
LotteryStation::~LotteryStation() {}


LotteryTicket* LotteryStation::buy(CustomSet<int> numbers, int tickettype) {
    if (tickettype == LOTTO7 && numbers.size() >= 7 && numbers.getMax() < 31) {
        LotteryTicket* newTicket = new Lotto7Ticket(numbers, m_round);
        cout << "Bought a Lotto 7 ticket for " << newTicket->getCost() <<" Yuan at round "<< m_round << ".\n";
        return newTicket;
    } else if (tickettype == LOTTO6 && numbers.size() >= 6 && numbers.getMax() < 44) {
        LotteryTicket* newTicket = new Lotto6Ticket(numbers, m_round);
        cout << "Bought a Lotto 6 ticket for " << newTicket->getCost() <<" Yuan at round "<< m_round << ".\n";
        return newTicket;
    } else {
        cout << "Failed.\n";
        return nullptr;
    }
}

void LotteryStation::claimPrize(LotteryTicket* ticket) {
    if (ticket == nullptr) {
        cout << "This ticket wins 0 Yuan.\n";
        return;
    }
    if (ticket->getTicketType() == LOTTO6) {
        int money = ticket->claimPrize(m_prizeNumberfor6, m_round);
        cout << "This ticket wins "<< money << " Yuan.\n";
    } else if (ticket->getTicketType() == LOTTO7) {
        int money = ticket->claimPrize(m_prizeNumberfor7, m_round);
        cout << "This ticket wins "<< money << " Yuan.\n";
    }
}

void LotteryStation::newRound() {
    m_round++;
    CustomSet<int> temp1;
    while(temp1.size() < 7) {
        temp1 += randInt(1, 30);
    }
    m_prizeNumberfor7 = temp1;
    CustomSet<int> temp2;
    while(temp2.size() < 6) {
        temp2 += randInt(1, 43);
    }
    m_prizeNumberfor6 = temp2;
}

bool LotteryStation::setPrizeNumbers(CustomSet<int> numbers, int tickettype) {
    if (numbers.size() != tickettype || numbers.getMax() > -13*tickettype + 121) {
        //cerr <<"fail!!\n";
        return false;
    }else if (tickettype == LOTTO6) {
        m_prizeNumberfor6 = numbers;
        //clog <<"set 6\n";
    } else if (tickettype == LOTTO7) {
        m_prizeNumberfor7 = numbers;
        //clog <<"set 7\n";
    }
    return true;
}

int randInt(int min, int max) {
    if (max < min)
	swap(max, min);
    return rand() % (max - min + 1) + min;
}